#include <stdlib.h>
#include "joystick.h"

joystick *joystick_create() {
    joystick *element = (joystick *)malloc(sizeof(joystick));
    if (!element)
        return NULL;
    element->right = 0;
    element->left = 0;
    element->jump = 0;
    element->crouch = 0;
    element->punch = 0;
    element->kick = 0;
    element->defend = 0;
    element->pause = 0;
    element->back = 0;
    element->select = 0;
    return element;
}

void joystick_destroy(joystick *element) {
    free(element);
}

void joystick_right(joystick *element) {
    element->right = element->right ^ 1;
}

void joystick_left(joystick *element) {
    element->left = element->left ^ 1;
}

void joystick_up(joystick *element) {
    element->jump = element->jump ^ 1;
}

void joystick_down(joystick *element) {
    element->crouch = element->crouch ^ 1;
}

void joystick_punch(joystick *element) {
    element->punch = element->punch ^ 1;
}

void joystick_kick(joystick *element) {
    element->kick = element->kick ^ 1;
}

void joystick_defend(joystick *element) {
    element->defend = element->defend ^ 1;
}

void joystick_player_1(joystick *controle, ALLEGRO_EVENT *event) {
    if (event->type == ALLEGRO_EVENT_KEY_DOWN) {
        switch (event->keyboard.keycode) {
            case ALLEGRO_KEY_D:
                joystick_right(controle);
                break;
            case ALLEGRO_KEY_A:
                joystick_left(controle);
                break;
            case ALLEGRO_KEY_W:
                joystick_up(controle);
                break;
            case ALLEGRO_KEY_S:
                joystick_down(controle);
                break;
            case ALLEGRO_KEY_Y:
                joystick_punch(controle);
                break;
            case ALLEGRO_KEY_U:
                joystick_kick(controle);
                break;
            case ALLEGRO_KEY_I:
                joystick_defend(controle);
                break;
        }
    }
}

void joystick_player_2(joystick *controle, ALLEGRO_EVENT *event) {
    if (event->type == ALLEGRO_EVENT_KEY_DOWN) {
        switch (event->keyboard.keycode) {
            case ALLEGRO_KEY_RIGHT:
                joystick_right(controle);
                break;
            case ALLEGRO_KEY_LEFT:
                joystick_left(controle);
                break;
            case ALLEGRO_KEY_UP:
                joystick_up(controle);
                break;
            case ALLEGRO_KEY_DOWN:
                joystick_down(controle);
                break;
            case ALLEGRO_KEY_B:
                joystick_punch(controle);
                break;
            case ALLEGRO_KEY_N:
                joystick_kick(controle);
                break;
            case ALLEGRO_KEY_M:
                joystick_defend(controle);
                break;
        }
    }
}
