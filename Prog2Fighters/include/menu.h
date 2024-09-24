#ifndef MENU_H
#define MENU_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "player.h"

typedef enum {
    MENU_PLAY,
    MENU_EXIT
} MenuResult;

void show_intro();
MenuResult main_menu(ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_FONT *font, sons_t *som);
void show_credits(ALLEGRO_EVENT_QUEUE *event_queue);
void destroy_menu_resources();
void draw_background(ALLEGRO_BITMAP *background);

#endif // MENU_H
