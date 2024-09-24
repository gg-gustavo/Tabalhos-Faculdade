#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#define IDLE_FRAMES 4
#define WALK_FRAMES 5
#define PUNCH_FRAMES 3
#define CROUCH_PUNCH_FRAMES 3
#define KICK_FRAMES 3
#define CROUCH_KICK_FRAMES 3
#define DEFEND_FRAMES 1
#define JUMP_FRAMES 5
#define CROUCH_FRAMES 2
#define HITBOX_SIZE 220

#define GRAVITY_NORMAL 350 // Velocidade de descida normal
#define GRAVITY_FAST 1000   // Velocidade de descida rápida
#define JUMP_VELOCITY 300  // Velocidade inicial do pulo
#define MOVE_SPEED 350     // Velocidade de movimento horizontal

typedef enum {
    IDLE,
    WALK,
    PUNCH,
    CROUCH_PUNCH,
    KICK,
    CROUCH_KICK,
    DEFEND,
    CROUCH_DEFEND,
    JUMP,
    CROUCH,
    NUM_ANIMATIONS
} AnimationType;

typedef struct {
    ALLEGRO_BITMAP **frames;
    int frame_count;
    float frame_duration;
    int current_frame;
    float elapsed_time;
} Animation;

typedef struct {
    int x, y;
    int vida;
    int vitorias;
    Animation animations[NUM_ANIMATIONS];
    AnimationType animacao_atual;
    bool is_jumping;
    float jump_velocity;
    bool is_crouching;
    bool moving_left;
    bool moving_right;
    bool is_attacking;
    bool is_defending;
    float last_punch_time;
    float last_kick_time;
} Player;


typedef struct sons{
    ALLEGRO_SAMPLE *ambiente;
    ALLEGRO_SAMPLE *seleciona;
    ALLEGRO_SAMPLE *lutem;
    ALLEGRO_SAMPLE *round;
    ALLEGRO_SAMPLE *venceu;
    //combate
    ALLEGRO_SAMPLE *chute;
    ALLEGRO_SAMPLE *soco;
    ALLEGRO_SAMPLE *defesa;
    ALLEGRO_SAMPLE *no_hit;
    //arenas
    ALLEGRO_SAMPLE *artico_theme;
    ALLEGRO_SAMPLE *campus_theme;
    ALLEGRO_SAMPLE *grecia_theme;
    ALLEGRO_SAMPLE *praia_theme;
    ALLEGRO_SAMPLE *western_theme;
} sons_t;

void init_animation(Animation *anim, int frame_count, float frame_duration);
void load_animations(Player *player, const char *base_path, const char *state_name, Animation *anim, int frame_count);
void init_blanka(Player *player, int x, int y);
void init_chunly(Player *player, int x, int y);
void init_ken(Player *player, int x, int y);
void init_ryu(Player *player, int x, int y);
void update_player(Player *player, float delta_time);
void draw_player(Player *player, bool flipped);
void handle_input(Player *player, ALLEGRO_EVENT *event, bool is_player2);
void check_collision(Player *attacker, Player *defender, sons_t *som);
void reset_player_position(Player *player, int x, int y);
void draw_health_bars(Player *player1, Player *player2, ALLEGRO_FONT *font);
sons_t* init_sounds();
void destroy_sons(sons_t *sons);

#endif // PLAYER_H
