#ifndef _JOYSTICK_H
#define _JOYSTICK_H

#include <allegro5/allegro5.h>

typedef struct {
    unsigned char right;
    unsigned char left;
    unsigned char jump;
    unsigned char crouch;
    unsigned char punch;
    unsigned char kick;
    unsigned char defend;
    unsigned char pause;
    unsigned char back;
    unsigned char select;
} joystick;

joystick* joystick_create();
void joystick_destroy(joystick *element);
void joystick_right(joystick *element);
void joystick_left(joystick *element);
void joystick_up(joystick *element);
void joystick_down(joystick *element);
void joystick_punch(joystick *element);
void joystick_kick(joystick *element);
void joystick_defend(joystick *element);
void joystick_player_1(joystick *controle, ALLEGRO_EVENT *event);
void joystick_player_2(joystick *controle, ALLEGRO_EVENT *event);

#endif
