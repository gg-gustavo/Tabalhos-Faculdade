#ifndef CHARACTER_SELECTION_H
#define CHARACTER_SELECTION_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "player.h"


typedef enum {
    CHUNLI,
    RYU,
    KEN,
    BLANKA,
    CHARACTER_COUNT
} Character;

typedef enum {
    CHAR_SELECTED,
    CHAR_BACK,
    CHAR_EXIT
} CharacterSelectionResult;

CharacterSelectionResult character_selection(ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_FONT *font, int *player1_character, int *player2_character, sons_t *som);

#endif // CHARACTER_SELECTION_H
