#ifndef ARENA_SELECTION_H
#define ARENA_SELECTION_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "player.h"

#define ARENA_COUNT 5

typedef enum {
    ARENA_PRAIA,
    ARENA_ARTICO,
    ARENA_CAMPUS,
    ARENA_GRECIA,
    ARENA_WESTERN
} Arena;

typedef enum {
    ARENA_SELECTED,
    ARENA_BACK,
    ARENA_EXIT
} ArenaSelectionResult;

ArenaSelectionResult arena_selection(ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_FONT *font, sons_t *som);
void load_arena_background(Arena arena);
void draw_arena_selection(ALLEGRO_FONT *font);
void draw_arena_background();

#endif // ARENA_SELECTION_H
