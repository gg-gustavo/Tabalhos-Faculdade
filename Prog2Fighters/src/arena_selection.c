#include "arena_selection.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <stdio.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

int selected_arena = ARENA_PRAIA;
ALLEGRO_BITMAP *bg_arena = NULL;
ALLEGRO_BITMAP *bg_arena_sl = NULL;

void load_arena_background(Arena arena) {
    const char *background_files[ARENA_COUNT] = {
        "assets/backgrounds/bg_praia.png",
        "assets/backgrounds/bg_artico.png",
        "assets/backgrounds/bg_campus.png",
        "assets/backgrounds/bg_grecia.png",
        "assets/backgrounds/bg_western.png"
    };
    
    bg_arena = al_load_bitmap(background_files[arena]);
    if (!bg_arena) {
        fprintf(stderr, "Failed to load arena background: %s\n", background_files[arena]);
    }
}

void draw_arena_background() {
    if (bg_arena) {
        al_draw_scaled_bitmap(bg_arena, 0, 0,
                              al_get_bitmap_width(bg_arena),
                              al_get_bitmap_height(bg_arena),
                              0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    }
}

void draw_arena_selection(ALLEGRO_FONT *font) {
    if (!bg_arena_sl)  bg_arena_sl = al_load_bitmap("assets/backgrounds/bg_arena.png");
        if (bg_arena_sl) {
        al_draw_scaled_bitmap(bg_arena_sl, 0, 0,
                              al_get_bitmap_width(bg_arena_sl),
                              al_get_bitmap_height(bg_arena_sl),
                              0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
                            
    }

    const char *arenas[ARENA_COUNT] = {"Praia", "Artico", "Campus", "Grecia", "Western"};

    for (int i = 0; i < ARENA_COUNT; ++i) {
        ALLEGRO_COLOR color = (i == selected_arena) ? al_map_rgb(255, 0, 80) : al_map_rgb(244, 182, 30);
        al_draw_text(font, color, SCREEN_WIDTH / 2 - 650 + i * 325, SCREEN_HEIGHT / 2 + 175, ALLEGRO_ALIGN_CENTRE, arenas[i]);
    }
    al_flip_display();
}

ArenaSelectionResult arena_selection(ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_FONT *font, sons_t *som) {
    bool done = false, redraw = true;
    ALLEGRO_EVENT event;

    while (!done) {
        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_TIMER) {
            redraw = true;
        } else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            return ARENA_EXIT;
        } else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_LEFT:
                    selected_arena = (selected_arena - 1 + ARENA_COUNT) % ARENA_COUNT;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    selected_arena = (selected_arena + 1) % ARENA_COUNT;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_play_sample(som->seleciona, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                    load_arena_background(selected_arena);
                    al_stop_samples();
                    ALLEGRO_SAMPLE *arena_themes[ARENA_COUNT] = {
                        som->praia_theme,
                        som->artico_theme,
                        som->campus_theme,
                        som->grecia_theme,
                        som->western_theme
                    };
                    al_play_sample(arena_themes[selected_arena], 0.2, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
                    return ARENA_SELECTED;
                case ALLEGRO_KEY_ESCAPE:
                    return ARENA_BACK;
            }
        }

        if (redraw && al_is_event_queue_empty(event_queue)) {
            redraw = false;
            draw_arena_selection(font);
        }
    }
    return ARENA_EXIT;
}
