#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <stdio.h>

#include "menu.h"
#include "character_selection.h"
#include "arena_selection.h"
#include "player.h"
#include "joystick.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define FPS 30

ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *event_queue;
ALLEGRO_TIMER *timer;
ALLEGRO_FONT *font1;
ALLEGRO_FONT *font2;
ALLEGRO_BITMAP *bg_victory;

void draw_victory_screen(const char *winner, sons_t* sons) {
    bg_victory = al_load_bitmap("assets/backgrounds/bg_azul.png");
    if (!bg_victory) {
        fprintf(stderr, "Failed to load bg_victory.\n");
        return;
    }

    al_draw_scaled_bitmap(bg_victory, 0, 0,
        al_get_bitmap_width(bg_victory),
        al_get_bitmap_height(bg_victory),
        0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    al_draw_text(font1, al_map_rgb(244, 182, 30), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, ALLEGRO_ALIGN_CENTRE, winner);
    al_draw_text(font1, al_map_rgb(255, 0, 0), SCREEN_WIDTH / 2 + 4, SCREEN_HEIGHT / 2 + 4, ALLEGRO_ALIGN_CENTRE, winner);

    al_flip_display();
    al_stop_samples();
    al_play_sample(sons->venceu, 0.3, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
    al_rest(5.0);

    al_destroy_bitmap(bg_victory);
}

void check_winner(Player *player1, Player *player2, sons_t *som) {
    if (player1->vida <= 0) {
        player2->vitorias++;
        al_play_sample(som->round, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        reset_player_position(player1, 200, 750);
        reset_player_position(player2, 1400, 750);
    } else if (player2->vida <= 0) {
        player1->vitorias++;
        al_play_sample(som->round, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        reset_player_position(player1, 200, 750);
        reset_player_position(player2, 1400, 750);
    }
}

void game_loop(Player *player1, Player *player2, sons_t *som) {
    bool done = false;
    bool redraw = true;

    al_play_sample(som->lutem, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL); // Play lutem.ogg

    while (!done) {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_TIMER) {
            redraw = true;
        } else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            done = true;
        } else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                done = true;
            }
        }

        handle_input(player1, &event, false);
        handle_input(player2, &event, true);

        if (redraw && al_is_event_queue_empty(event_queue)) {
            redraw = false;
            draw_arena_background();
            update_player(player1, 1.0 / FPS);
            update_player(player2, 1.0 / FPS);
            check_collision(player1, player2, som);
            check_collision(player2, player1, som);
            draw_health_bars(player1, player2, font1);
            draw_player(player1, false);
            draw_player(player2, true);
            al_flip_display();

            check_winner(player1, player2, som);

            if (player1->vitorias == 2 || player2->vitorias == 2) {
                const char *winner = player1->vitorias == 2 ? "Player 1 Ganhou!" : "Player 2 Ganhou!";
                draw_victory_screen(winner, som);
                done = true;
            }
        }
    }

    al_stop_samples();
    al_play_sample(som->ambiente, 0.5, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL); // Play ambiente.ogg
}

int main() {
    if (!al_init()) {
        fprintf(stderr, "Failed to initialize Allegro.\n");
        return -1;
    }

    display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!display) {
        fprintf(stderr, "Failed to create display.\n");
        return -1;
    }

    al_install_keyboard();
    al_install_audio();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    al_init_acodec_addon();
    al_reserve_samples(14);
    sons_t *som = init_sounds();

    font1 = al_load_ttf_font("assets/fonts/street.ttf", 60, 0);
    font2 = al_load_ttf_font("assets/fonts/escrita.ttf", 35, 0);
    if (!font1 || !font2) {
        fprintf(stderr, "Failed to load fonts.\n");
        return -1;
    }

    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0 / FPS);

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_start_timer(timer);

    show_intro();

    while (1) {
        MenuResult result = main_menu(event_queue, font1, som);
        if (result == MENU_PLAY) {
            
            while (1) {
                int player1_character = 0, player2_character = 0;
                CharacterSelectionResult cs_result = character_selection(event_queue, font2, &player1_character, &player2_character, som);
                if (cs_result == CHAR_BACK) {
                    break;
                }

                Player player1, player2;
                if (player1_character == CHUNLI) init_chunly(&player1, 200, 750);
                if (player1_character == RYU) init_ryu(&player1, 200, 750);
                if (player1_character == KEN) init_ken(&player1, 200, 750);
                if (player1_character == BLANKA) init_blanka(&player1, 200, 750);
                
                if (player2_character == CHUNLI) init_chunly(&player2, 1400, 750);
                if (player2_character == RYU) init_ryu(&player2, 1400, 750);
                if (player2_character == KEN) init_ken(&player2, 1400, 750);
                if (player2_character == BLANKA) init_blanka(&player2, 1400, 750);

                if (arena_selection(event_queue, font2, som) == ARENA_BACK) {
                    continue;
                }

                player1.vitorias = 0;
                player2.vitorias = 0;

                game_loop(&player1, &player2, som);
                break;
            }
        } else if (result == MENU_EXIT) {
            break;
        }
    }

    al_destroy_font(font1);
    al_destroy_font(font2);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);

    return 0;
}