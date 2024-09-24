#include "menu.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <stdio.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define MENU_OPTION_COUNT 3

typedef enum {
    MENU_OPTION_PLAY,
    MENU_OPTION_CREDITS,
    MENU_OPTION_EXIT
} MenuOption;

ALLEGRO_BITMAP *bg_ufpr, *bg_azul, *bg_logo, *bg_menu, *bg_creditos;
int selected_option = MENU_OPTION_PLAY;

void show_background(ALLEGRO_BITMAP *background, float duration) {
    al_draw_scaled_bitmap(background, 0, 0, 
                          al_get_bitmap_width(background), 
                          al_get_bitmap_height(background),
                          0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    al_flip_display();
    al_rest(duration);
}

void draw_background(ALLEGRO_BITMAP *background) {
    al_draw_scaled_bitmap(background, 0, 0, 
                          al_get_bitmap_width(background), 
                          al_get_bitmap_height(background),
                          0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    al_flip_display();
}

void draw_menu(ALLEGRO_FONT *font) {
    al_draw_scaled_bitmap(bg_menu, 0, 0, 
                          al_get_bitmap_width(bg_menu), 
                          al_get_bitmap_height(bg_menu),
                          0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    
    const char *options[MENU_OPTION_COUNT] = {"Jogar", "Creditos", "Sair"};
    
    for (int i = 0; i < MENU_OPTION_COUNT; ++i) {
        if (i == selected_option) {
            al_draw_text(font, al_map_rgb(255, 0, 0), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 50 + i * 75, ALLEGRO_ALIGN_CENTRE, options[i]);
        } else {
            al_draw_text(font, al_map_rgb(244, 182, 30), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 50 + i * 75, ALLEGRO_ALIGN_CENTRE, options[i]);
        }
    }
    al_flip_display();
}

void show_intro() {
    bg_ufpr = al_load_bitmap("assets/backgrounds/bg_ufpr.png");
    bg_azul = al_load_bitmap("assets/backgrounds/bg_azul.png");
    bg_logo = al_load_bitmap("assets/backgrounds/bg_logo.png");
    bg_menu = al_load_bitmap("assets/backgrounds/bg_menu.png");
    bg_creditos = al_load_bitmap("assets/backgrounds/bg_creditos.png");

    if (!bg_ufpr || !bg_azul || !bg_logo || !bg_menu || !bg_creditos) {
        fprintf(stderr, "Failed to load backgrounds.\n");
        return;
    }

    show_background(bg_ufpr, 2.0);
    show_background(bg_azul, 1.0);
    show_background(bg_logo, 2.0);
}

void show_credits(ALLEGRO_EVENT_QUEUE *event_queue) {
    bool done = false;
    ALLEGRO_EVENT event;

    while (!done) {
        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            done = true;
        } else if (event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
            done = true;
        }

        al_draw_scaled_bitmap(bg_creditos, 0, 0, 
                              al_get_bitmap_width(bg_creditos), 
                              al_get_bitmap_height(bg_creditos),
                              0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
        al_flip_display();
    }
}

MenuResult main_menu(ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_FONT *font, sons_t *som) {
    bool done = false, redraw = true;
    ALLEGRO_EVENT event;

    // Tocar música ambiente durante o menu principal
    al_play_sample(som->ambiente, 0.5, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);

    while (!done) {
        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_TIMER) {
            redraw = true;
        } else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            done = true;
        } else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                    selected_option = (selected_option - 1 + MENU_OPTION_COUNT) % MENU_OPTION_COUNT;
                    break;
                case ALLEGRO_KEY_DOWN:
                    selected_option = (selected_option + 1) % MENU_OPTION_COUNT;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_play_sample(som->seleciona, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                    if (selected_option == MENU_OPTION_EXIT) {
                        return MENU_EXIT;
                    } else if (selected_option == MENU_OPTION_CREDITS) {
                        show_credits(event_queue);
                    } else if (selected_option == MENU_OPTION_PLAY) {
                        return MENU_PLAY;
                    }
                    break;
            }
        }

        if (redraw && al_is_event_queue_empty(event_queue)) {
            redraw = false;
            draw_menu(font);
        }
    }

    // Parar a música ambiente ao sair do menu principal
    al_stop_samples();
    return MENU_EXIT;
}

void destroy_menu_resources() {
    al_destroy_bitmap(bg_ufpr);
    al_destroy_bitmap(bg_azul);
    al_destroy_bitmap(bg_logo);
    al_destroy_bitmap(bg_menu);
    al_destroy_bitmap(bg_creditos);
}
