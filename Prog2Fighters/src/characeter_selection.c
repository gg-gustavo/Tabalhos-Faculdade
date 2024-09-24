#include "character_selection.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <stdio.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

ALLEGRO_BITMAP *bg_selecao;
int player1_selection = CHUNLI;
int player2_selection = CHUNLI;

void draw_character_selection(ALLEGRO_FONT *font) {
    al_draw_scaled_bitmap(bg_selecao, 0, 0, 
                          al_get_bitmap_width(bg_selecao), 
                          al_get_bitmap_height(bg_selecao),
                          0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    const char *characters[CHARACTER_COUNT] = {"Chunly", "Ryu", "Ken", "Blanka"};
    
    for (int i = 0; i < CHARACTER_COUNT; ++i) {
        ALLEGRO_COLOR color1 = (i == player1_selection) ? al_map_rgb(255, 0, 80) : al_map_rgb(244, 182, 30);
        ALLEGRO_COLOR color2 = (i == player2_selection) ? al_map_rgb(80, 0, 255) : al_map_rgb(244, 182, 30);
        al_draw_text(font, color1, SCREEN_WIDTH / 4 - 125, SCREEN_HEIGHT / 4 + 300 + i * 100, ALLEGRO_ALIGN_CENTRE, characters[i]);
        al_draw_text(font, color2, 3 * SCREEN_WIDTH / 4 + 125, SCREEN_HEIGHT / 4 + 300 + i * 100, ALLEGRO_ALIGN_CENTRE, characters[i]);
    }
    al_flip_display();
}

CharacterSelectionResult character_selection(ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_FONT *font, int *player1_character, int *player2_character, sons_t *som) {
    bg_selecao = al_load_bitmap("assets/backgrounds/bg_selecao.png");
    if (!bg_selecao) {
        fprintf(stderr, "Failed to load bg_selecao.\n");
        return CHAR_EXIT;
    }

    bool done = false, redraw = true;
    ALLEGRO_EVENT event;

    while (!done) {
        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_TIMER) {
            redraw = true;
        } else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            return CHAR_EXIT;
        } else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_W:
                    player1_selection = (player1_selection - 1 + CHARACTER_COUNT) % CHARACTER_COUNT;
                    break;
                case ALLEGRO_KEY_S:
                    player1_selection = (player1_selection + 1) % CHARACTER_COUNT;
                    break;
                case ALLEGRO_KEY_UP:
                    player2_selection = (player2_selection - 1 + CHARACTER_COUNT) % CHARACTER_COUNT;
                    break;
                case ALLEGRO_KEY_DOWN:
                    player2_selection = (player2_selection + 1) % CHARACTER_COUNT;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_play_sample(som->seleciona, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                    done = true;
                    break;
                case ALLEGRO_KEY_ESCAPE:
                    return CHAR_BACK;
            }
        }

        if (redraw && al_is_event_queue_empty(event_queue)) {
            redraw = false;
            draw_character_selection(font);
        }
    }

    *player1_character = player1_selection;
    *player2_character = player2_selection;

    al_destroy_bitmap(bg_selecao);
    return CHAR_SELECTED;
}
