#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define FLOOR_Y 750
#define PLAYER_WIDTH 300
#define BAR_WIDTH 780
#define BAR_HEIGHT 60
#define BAR_PADDING 20

sons_t* init_sounds(){
    sons_t *sons;
    if (!(sons = (sons_t *)malloc(sizeof(sons_t))))
        return NULL;

    sons->ambiente = al_load_sample("assets/sounds/interface/ambiente.ogg");
    sons->lutem = al_load_sample("assets/sounds/interface/lutem.ogg");
    sons->seleciona = al_load_sample("assets/sounds/interface/selecao.ogg");
    sons->venceu = al_load_sample("assets/sounds/interface/venceu_jogo.ogg");
    sons->round = al_load_sample("assets/sounds/interface/venceu_round.ogg");

    sons->chute = al_load_sample("assets/sounds/combate/chute.ogg");
    sons->soco = al_load_sample("assets/sounds/combate/soco.ogg");
    sons->defesa = al_load_sample("assets/sounds/combate/defende.ogg");
    sons->no_hit = al_load_sample("assets/sounds/combate/sem_hit.ogg");

    sons->praia_theme = al_load_sample("assets/sounds/arenas/praia_theme.ogg");
    sons->artico_theme = al_load_sample("assets/sounds/arenas/artico_theme.ogg");
    sons->campus_theme = al_load_sample("assets/sounds/arenas/campus_theme.ogg");
    sons->grecia_theme = al_load_sample("assets/sounds/arenas/grecia_theme.ogg");
    sons->western_theme = al_load_sample("assets/sounds/arenas/western_theme.ogg");

    if(!sons->ambiente || !sons->lutem || !sons->seleciona || !sons->venceu || !sons->round || !sons->chute || !sons->soco ||
    !sons->defesa || !sons->no_hit || !sons->praia_theme || !sons->artico_theme || !sons->grecia_theme || !sons->western_theme || !sons->campus_theme){
        fprintf(stderr, "Falha ao carregar sons!");
        destroy_sons(sons);
        return NULL;
    }
    return sons;
}

void destroy_sons(sons_t *sons){
    if(!sons)
        return;

    if(sons->ambiente)
        al_destroy_sample(sons->ambiente);
    if(sons->lutem)
        al_destroy_sample(sons->lutem);
    if(sons->seleciona)
        al_destroy_sample(sons->seleciona);
    if(sons->venceu)
        al_destroy_sample(sons->venceu);
    if(sons->round)
        al_destroy_sample(sons->round);
    if(sons->chute)
        al_destroy_sample(sons->chute);
    if(sons->soco)
        al_destroy_sample(sons->soco);
    if(sons->defesa)
        al_destroy_sample(sons->defesa);
    if(sons->no_hit)
        al_destroy_sample(sons->no_hit);
    if(sons->praia_theme)
        al_destroy_sample(sons->praia_theme);
    if(sons->campus_theme)
        al_destroy_sample(sons->campus_theme);
    if(sons->artico_theme)
        al_destroy_sample(sons->artico_theme);
    if(sons->western_theme)
        al_destroy_sample(sons->western_theme);
    if(sons->grecia_theme)
        al_destroy_sample(sons->grecia_theme);
}

void init_animation(Animation *anim, int frame_count, float frame_duration) {
    anim->frames = (ALLEGRO_BITMAP **)malloc(frame_count * sizeof(ALLEGRO_BITMAP *));
    if (!anim->frames) {
        fprintf(stderr, "Failed to allocate memory for animation frames.\n");
        exit(1);
    }
    anim->frame_count = frame_count;
    anim->frame_duration = frame_duration;
    anim->current_frame = 0;
    anim->elapsed_time = 0;
}

void load_animations(Player *player, const char *base_path, const char *state_name, Animation *anim, int frame_count) {
    player->vida = 100;
    char path[100];
    for (int i = 0; i < frame_count; i++) {
        sprintf(path, "%s/%s/%s_%d.png", base_path, state_name, state_name, i + 1);
        anim->frames[i] = al_load_bitmap(path);
        if (!anim->frames[i]) {
            fprintf(stderr, "Failed to load frame %d for %s\n", i + 1, state_name);
            exit(1);
        }
    }
}

void init_blanka(Player *player, int x, int y) {
    player->x = x;
    player->y = y;
    player->vida = 100;
    player->vitorias = 0;
    player->animacao_atual = IDLE;
    player->is_jumping = false;
    player->jump_velocity = 0;
    player->is_crouching = false;
    player->moving_left = false;
    player->moving_right = false;

    const char *base_path = "assets/sprites/Blanka";
    init_animation(&player->animations[IDLE], 4, 0.2f);
    init_animation(&player->animations[WALK], 5, 0.1f);
    init_animation(&player->animations[PUNCH], 3, 0.2f);
    init_animation(&player->animations[CROUCH_PUNCH], 3, 0.1f);
    init_animation(&player->animations[KICK], 3, 0.2f);
    init_animation(&player->animations[CROUCH_KICK], 3, 0.2f);
    init_animation(&player->animations[DEFEND], 1, 0.1f);
    init_animation(&player->animations[CROUCH_DEFEND], 1, 0.2f);
    init_animation(&player->animations[JUMP], 5, 0.2f);
    init_animation(&player->animations[CROUCH], 2, 0.2f);

    load_animations(player, base_path, "Idle", &player->animations[IDLE], 4);
    load_animations(player, base_path, "Andando", &player->animations[WALK], 5);
    load_animations(player, base_path, "Soco_pe", &player->animations[PUNCH], 3);
    load_animations(player, base_path, "Soco_agachado", &player->animations[CROUCH_PUNCH], 3);
    load_animations(player, base_path, "Chute_pe", &player->animations[KICK], 3);
    load_animations(player, base_path, "Chute_agachado", &player->animations[CROUCH_KICK], 3);
    load_animations(player, base_path, "Defende_pe", &player->animations[DEFEND], 1);
    load_animations(player, base_path, "Defende_agachado", &player->animations[CROUCH_DEFEND], 1);
    load_animations(player, base_path, "Pulando", &player->animations[JUMP], 5);
    load_animations(player, base_path, "Agachado", &player->animations[CROUCH], 2);
}

void init_chunly(Player *player, int x, int y) {
    player->x = x;
    player->y = y;
    player->vida = 100;
    player->vitorias = 0;
    player->animacao_atual = IDLE;
    player->is_jumping = false;
    player->jump_velocity = 0;
    player->is_crouching = false;
    player->moving_left = false;
    player->moving_right = false;

    const char *base_path = "assets/sprites/Chunly";
    init_animation(&player->animations[IDLE], 4, 0.2f);
    init_animation(&player->animations[WALK], 5, 0.1f);
    init_animation(&player->animations[PUNCH], 3, 0.2f);
    init_animation(&player->animations[CROUCH_PUNCH], 3, 0.2f);
    init_animation(&player->animations[KICK], 3, 0.2f);
    init_animation(&player->animations[CROUCH_KICK], 3, 0.2f);
    init_animation(&player->animations[DEFEND], 1, 0.1f);
    init_animation(&player->animations[CROUCH_DEFEND], 1, 0.2f);
    init_animation(&player->animations[JUMP], 5, 0.2f);
    init_animation(&player->animations[CROUCH], 2, 0.2f);

    load_animations(player, base_path, "Idle", &player->animations[IDLE], 4);
    load_animations(player, base_path, "Andando", &player->animations[WALK], 5);
    load_animations(player, base_path, "Soco_pe", &player->animations[PUNCH], 3);
    load_animations(player, base_path, "Soco_agachado", &player->animations[CROUCH_PUNCH], 3);
    load_animations(player, base_path, "Chute_pe", &player->animations[KICK], 3);
    load_animations(player, base_path, "Chute_agachado", &player->animations[CROUCH_KICK], 3);
    load_animations(player, base_path, "Defende_pe", &player->animations[DEFEND], 1);
    load_animations(player, base_path, "Defende_agachado", &player->animations[CROUCH_DEFEND], 1);
    load_animations(player, base_path, "Pulando", &player->animations[JUMP], 5);
    load_animations(player, base_path, "Agachado", &player->animations[CROUCH], 2);
}

void init_ken(Player *player, int x, int y) {
    player->x = x;
    player->y = y;
    player->vida = 100;
    player->vitorias = 0;
    player->animacao_atual = IDLE;
    player->is_jumping = false;
    player->jump_velocity = 0;
    player->is_crouching = false;
    player->moving_left = false;
    player->moving_right = false;

    const char *base_path = "assets/sprites/Ken";
    init_animation(&player->animations[IDLE], 4, 0.2f);
    init_animation(&player->animations[WALK], 5, 0.1f);
    init_animation(&player->animations[PUNCH], 3, 0.2f);
    init_animation(&player->animations[CROUCH_PUNCH], 3, 0.2f);
    init_animation(&player->animations[KICK], 3, 0.2f);
    init_animation(&player->animations[CROUCH_KICK], 3, 0.2f);
    init_animation(&player->animations[DEFEND], 1, 0.1f);
    init_animation(&player->animations[CROUCH_DEFEND], 1, 0.1f);
    init_animation(&player->animations[JUMP], 5, 0.2f);
    init_animation(&player->animations[CROUCH], 2, 0.2f);

    load_animations(player, base_path, "Idle", &player->animations[IDLE], 4);
    load_animations(player, base_path, "Andando", &player->animations[WALK], 5);
    load_animations(player, base_path, "Soco_pe", &player->animations[PUNCH], 3);
    load_animations(player, base_path, "Soco_agachado", &player->animations[CROUCH_PUNCH], 3);
    load_animations(player, base_path, "Chute_pe", &player->animations[KICK], 3);
    load_animations(player, base_path, "Chute_agachado", &player->animations[CROUCH_KICK], 3);
    load_animations(player, base_path, "Defende_pe", &player->animations[DEFEND], 1);
    load_animations(player, base_path, "Defende_agachado", &player->animations[CROUCH_DEFEND], 1);
    load_animations(player, base_path, "Pulando", &player->animations[JUMP], 5);
    load_animations(player, base_path, "Agachado", &player->animations[CROUCH], 2);
}

void init_ryu(Player *player, int x, int y) {
    player->x = x;
    player->y = y;
    player->vida = 100;
    player->vitorias = 0;
    player->animacao_atual = IDLE;
    player->is_jumping = false;
    player->jump_velocity = 0;
    player->is_crouching = false;
    player->moving_left = false;
    player->moving_right = false;

    const char *base_path = "assets/sprites/Ryu";
    init_animation(&player->animations[IDLE], 4, 0.2f);
    init_animation(&player->animations[WALK], 5, 0.1f);
    init_animation(&player->animations[PUNCH], 3, 0.2f);
    init_animation(&player->animations[CROUCH_PUNCH], 3, 0.2f);
    init_animation(&player->animations[KICK], 3, 0.2f);
    init_animation(&player->animations[CROUCH_KICK], 3, 0.2f);
    init_animation(&player->animations[DEFEND], 1, 0.1f);
    init_animation(&player->animations[CROUCH_DEFEND], 1, 0.1f);
    init_animation(&player->animations[JUMP], 5, 0.2f);
    init_animation(&player->animations[CROUCH], 2, 0.2f);

    load_animations(player, base_path, "Idle", &player->animations[IDLE], 4);
    load_animations(player, base_path, "Andando", &player->animations[WALK], 5);
    load_animations(player, base_path, "Soco_pe", &player->animations[PUNCH], 3);
    load_animations(player, base_path, "Soco_agachado", &player->animations[CROUCH_PUNCH], 3);
    load_animations(player, base_path, "Chute_pe", &player->animations[KICK], 3);
    load_animations(player, base_path, "Chute_agachado", &player->animations[CROUCH_KICK], 3);
    load_animations(player, base_path, "Defende_pe", &player->animations[DEFEND], 1);
    load_animations(player, base_path, "Defende_agachado", &player->animations[CROUCH_DEFEND], 1);
    load_animations(player, base_path, "Pulando", &player->animations[JUMP], 5);
    load_animations(player, base_path, "Agachado", &player->animations[CROUCH], 2);
}

void update_player(Player *player, float delta_time) {
    Animation *anim = &player->animations[player->animacao_atual];
    anim->elapsed_time += delta_time;

    // Atualiza a animação
    if (anim->elapsed_time >= anim->frame_duration) {
        anim->elapsed_time -= anim->frame_duration;
        anim->current_frame = (anim->current_frame + 1) % anim->frame_count;
    }

    // Atualiza a posição do jogador se estiver pulando
    if (player->is_jumping) {
        player->y -= player->jump_velocity * delta_time;

        // Aplica a gravidade
        if (player->is_crouching) {
            player->jump_velocity -= GRAVITY_FAST * delta_time; // Gravidade dobrada
        } else {
            player->jump_velocity -= GRAVITY_NORMAL * delta_time; // Gravidade normal
        }

        // Verifica se o jogador atingiu o chão
        if (player->y >= FLOOR_Y) {
            player->y = FLOOR_Y;
            player->is_jumping = false;
            player->jump_velocity = 0;
            player->animacao_atual = IDLE;
        } else if (player->jump_velocity > 150) {
            anim->current_frame = 1; // Subindo
        } else if (player->jump_velocity > 0) {
            anim->current_frame = 2; // Ponto máximo
        } else if (player->jump_velocity < 0 && player->y > 0) {
            anim->current_frame = 3; // Descendo
        }

        // Permitir movimento horizontal enquanto está no ar
        if (player->moving_left) {
            player->x -= MOVE_SPEED * delta_time; // Velocidade de movimento para a esquerda
        } else if (player->moving_right) {
            player->x += MOVE_SPEED * delta_time; // Velocidade de movimento para a direita
        }
    } else if (player->is_crouching) {
        if (anim->current_frame == 0 && anim->elapsed_time >= anim->frame_duration) {
            anim->current_frame = 1; // Estático agachado
        }
    } else if (player->moving_left) {
        player->x -= MOVE_SPEED * delta_time; // Velocidade de movimento para a esquerda
        player->animacao_atual = WALK;
    } else if (player->moving_right) {
        player->x += MOVE_SPEED * delta_time; // Velocidade de movimento para a direita
        player->animacao_atual = WALK;
    } else if (player->is_attacking) {
        if (anim->elapsed_time >= anim->frame_duration * anim->frame_count) {
            player->is_attacking = false;
            player->animacao_atual = IDLE;
        }
    } else if (player->is_defending) {
        // Não voltar para idle enquanto estiver defendendo
    } else {
        player->animacao_atual = IDLE;
    }

    // Limitar a posição dos jogadores dentro da tela
    if (player->x < 0) {
        player->x = 0;
    } else if (player->x > SCREEN_WIDTH - PLAYER_WIDTH) {
        player->x = SCREEN_WIDTH - PLAYER_WIDTH;
    }
}

void reset_player_position(Player *player, int x, int y) {
    player->x = x;
    player->y = y;
    player->vida = 100;
    player->is_jumping = false;
    player->jump_velocity = 0;
    player->is_crouching = false;
    player->moving_left = false;
    player->moving_right = false;
    player->is_attacking = false;
    player->is_defending = false;
    player->animacao_atual = IDLE;
}

void draw_player(Player *player, bool flipped) {
    Animation *anim = &player->animations[player->animacao_atual];
    ALLEGRO_BITMAP *current_frame = anim->frames[anim->current_frame];

    if (current_frame) {
        if (flipped) {
            al_draw_scaled_bitmap(current_frame, 0, 0,
                al_get_bitmap_width(current_frame),
                al_get_bitmap_height(current_frame),
                player->x, player->y,
                al_get_bitmap_width(current_frame),
                al_get_bitmap_height(current_frame), ALLEGRO_FLIP_HORIZONTAL);
        } else {
            al_draw_scaled_bitmap(current_frame, 0, 0,
                al_get_bitmap_width(current_frame),
                al_get_bitmap_height(current_frame),
                player->x, player->y,
                al_get_bitmap_width(current_frame),
                al_get_bitmap_height(current_frame), 0);
        }
    }
}

void draw_health_bars(Player *player1, Player *player2, ALLEGRO_FONT *font) {
    // Desenhar barra de vida do jogador 1
    al_draw_filled_rectangle(BAR_PADDING, BAR_PADDING, BAR_PADDING + BAR_WIDTH, BAR_PADDING + BAR_HEIGHT, al_map_rgb(255, 0, 0));
    al_draw_filled_rectangle(BAR_PADDING, BAR_PADDING, BAR_PADDING + (BAR_WIDTH * (player1->vida / 100.0f)), BAR_PADDING + BAR_HEIGHT, al_map_rgb(0, 255, 0));

    // Desenhar barra de vida do jogador 2
    al_draw_filled_rectangle(SCREEN_WIDTH - BAR_PADDING - BAR_WIDTH, BAR_PADDING, SCREEN_WIDTH - BAR_PADDING, BAR_PADDING + BAR_HEIGHT, al_map_rgb(255, 0, 0));
    al_draw_filled_rectangle(SCREEN_WIDTH - BAR_PADDING - BAR_WIDTH, BAR_PADDING, SCREEN_WIDTH - BAR_PADDING - (BAR_WIDTH * (1 - player2->vida / 100.0f)), BAR_PADDING + BAR_HEIGHT, al_map_rgb(0, 255, 0));

    // Desenhar "VS" no meio
    al_draw_text(font, al_map_rgb(244, 182, 30), SCREEN_WIDTH / 2, BAR_PADDING, ALLEGRO_ALIGN_CENTRE, "VS");
    al_draw_text(font, al_map_rgb(255, 0, 0), SCREEN_WIDTH / 2 + 4, BAR_PADDING + 4, ALLEGRO_ALIGN_CENTRE, "VS"); //sombra


    // Desenhar rounds ganhos
    char buffer[20];
    sprintf(buffer, "Rounds: %d", player1->vitorias);
    al_draw_text(font, al_map_rgb(244, 182, 30), BAR_PADDING, BAR_PADDING + BAR_HEIGHT + 8, ALLEGRO_ALIGN_LEFT, buffer);
    al_draw_text(font, al_map_rgb(255, 0, 0), BAR_PADDING + 2, BAR_PADDING + BAR_HEIGHT + 14, ALLEGRO_ALIGN_LEFT, buffer);


    sprintf(buffer, "Rounds: %d", player2->vitorias);
    al_draw_text(font, al_map_rgb(244, 182, 30), SCREEN_WIDTH - BAR_PADDING, BAR_PADDING + BAR_HEIGHT + 8, ALLEGRO_ALIGN_RIGHT, buffer);
    al_draw_text(font, al_map_rgb(255, 0, 0), SCREEN_WIDTH - BAR_PADDING -4, BAR_PADDING + BAR_HEIGHT + 14, ALLEGRO_ALIGN_RIGHT, buffer);
}

void handle_input(Player *player, ALLEGRO_EVENT *event, bool is_player2) {
    float current_time = al_get_time();
    
    if (event->type == ALLEGRO_EVENT_KEY_DOWN) {
        switch (event->keyboard.keycode) {
            // Controles para o Jogador 1
            case ALLEGRO_KEY_A:
                if (!is_player2) {
                    player->moving_left = true;
                }
                break;
            case ALLEGRO_KEY_D:
                if (!is_player2) {
                    player->moving_right = true;
                }
                break;
            case ALLEGRO_KEY_W:
                if (!is_player2 && !player->is_jumping) {
                    player->is_jumping = true;
                    player->jump_velocity = 300;
                    player->animacao_atual = JUMP;
                }
                break;
            case ALLEGRO_KEY_S:
                if (!is_player2) {
                    player->is_crouching = true;
                    if (!player->is_jumping) {
                        player->animacao_atual = CROUCH;
                    }
                }
                break;
            case ALLEGRO_KEY_Y:
                if (!is_player2 && !player->is_jumping && current_time - player->last_punch_time > 1.0f) {
                    player->is_attacking = true;
                    player->last_punch_time = current_time;
                    if (player->is_crouching) {
                        player->animacao_atual = CROUCH_PUNCH;
                    } else {
                        player->animacao_atual = PUNCH;
                    }
                }
                break;
            case ALLEGRO_KEY_U:
                if (!is_player2 && !player->is_jumping && current_time - player->last_kick_time > 2.0f) {
                    player->is_attacking = true;
                    player->last_kick_time = current_time;
                    if (player->is_crouching) {
                        player->animacao_atual = CROUCH_KICK;
                    } else {
                        player->animacao_atual = KICK;
                    }
                }
                break;
            case ALLEGRO_KEY_I:
                if (!is_player2 && !player->is_jumping) {
                    player->is_defending = true;
                    if (player->is_crouching) {
                        player->animacao_atual = CROUCH_DEFEND;
                    } else {
                        player->animacao_atual = DEFEND;
                    }
                }
                break;

            // Controles para o Jogador 2
            case ALLEGRO_KEY_LEFT:
                if (is_player2) {
                    player->moving_left = true;
                }
                break;
            case ALLEGRO_KEY_RIGHT:
                if (is_player2) {
                    player->moving_right = true;
                }
                break;
            case ALLEGRO_KEY_UP:
                if (is_player2 && !player->is_jumping) {
                    player->is_jumping = true;
                    player->jump_velocity = 300;
                    player->animacao_atual = JUMP;
                }
                break;
            case ALLEGRO_KEY_DOWN:
                if (is_player2) {
                    player->is_crouching = true;
                    if (!player->is_jumping) {
                        player->animacao_atual = CROUCH;
                    }
                }
                break;
            case ALLEGRO_KEY_B:
                if (is_player2 && !player->is_jumping && current_time - player->last_punch_time > 1.0f) {
                    player->is_attacking = true;
                    player->last_punch_time = current_time;
                    if (player->is_crouching) {
                        player->animacao_atual = CROUCH_PUNCH;
                    } else {
                        player->animacao_atual = PUNCH;
                    }
                }
                break;
            case ALLEGRO_KEY_N:
                if (is_player2 && !player->is_jumping && current_time - player->last_kick_time > 2.0f) {
                    player->is_attacking = true;
                    player->last_kick_time = current_time;
                    if (player->is_crouching) {
                        player->animacao_atual = CROUCH_KICK;
                    } else {
                        player->animacao_atual = KICK;
                    }
                }
                break;
            case ALLEGRO_KEY_M:
                if (is_player2 && !player->is_jumping) {
                    player->is_defending = true;
                    if (player->is_crouching) {
                        player->animacao_atual = CROUCH_DEFEND;
                    } else {
                        player->animacao_atual = DEFEND;
                    }
                }
                break;
            default:
                break;
        }
    } else if (event->type == ALLEGRO_EVENT_KEY_UP) {
        switch (event->keyboard.keycode) {
            // Controles para o Jogador 1
            case ALLEGRO_KEY_A:
                if (!is_player2) {
                    player->moving_left = false;
                    if(!player->is_jumping)
                        player->animacao_atual = IDLE;
                }
                break;
            case ALLEGRO_KEY_D:
                if (!is_player2) {
                    player->moving_right = false;
                    if(!player->is_jumping)
                        player->animacao_atual = IDLE;
                }   
                break;
            case ALLEGRO_KEY_S:
                if (!is_player2) {
                    player->is_crouching = false;
                    if (!player->is_jumping) {
                        player->animacao_atual = IDLE;
                    }
                }
                break;
            case ALLEGRO_KEY_Y:
                if (!is_player2) {
                    player->is_attacking = false;
                    if (!player->is_jumping && player->animacao_atual == PUNCH) {
                        player->animacao_atual = IDLE;
                    }
                }
                break;
            case ALLEGRO_KEY_U:
                if (!is_player2) {
                    player->is_attacking = false;
                    if (!player->is_jumping && player->animacao_atual == KICK) {
                        player->animacao_atual = IDLE;
                    }
                }
                break;
            case ALLEGRO_KEY_I:
                if (!is_player2) {
                    player->is_defending = false;
                    if (!player->is_jumping && (player->animacao_atual == DEFEND || player->animacao_atual == CROUCH_DEFEND)) {
                        player->animacao_atual = IDLE;
                    }
                }
                break;

            // Controles para o Jogador 2
            case ALLEGRO_KEY_LEFT:
                if (is_player2) {
                    player->moving_left = false;
                        if(!player->is_jumping)
                        player->animacao_atual = IDLE;

                }
                break;
            case ALLEGRO_KEY_RIGHT:
                if (is_player2) {
                    player->moving_right = false;
                    if(!player->is_jumping)
                        player->animacao_atual = IDLE;

                }
                break;
            case ALLEGRO_KEY_DOWN:
                if (is_player2) {
                    player->is_crouching = false;
                    if (!player->is_jumping) {
                        player->animacao_atual = IDLE;
                    }
                }
                break;
            case ALLEGRO_KEY_B:
                if (is_player2) {
                    player->is_attacking = false;
                    if (!player->is_jumping && player->animacao_atual == PUNCH) {
                        player->animacao_atual = IDLE;
                    }
                }
                break;
            case ALLEGRO_KEY_N:
                if (is_player2) {
                    player->is_attacking = false;
                    if (!player->is_jumping && player->animacao_atual == KICK) {
                        player->animacao_atual = IDLE;
                    }
                }
                break;
            case ALLEGRO_KEY_M:
                if (is_player2) {
                    player->is_defending = false;
                    if (!player->is_jumping && (player->animacao_atual == DEFEND || player->animacao_atual == CROUCH_DEFEND)) {
                        player->animacao_atual = IDLE;
                    }
                }
                break;
            default:
                break;
        }
    }
}

void check_collision(Player *attacker, Player *defender, sons_t *som) {
    int attack_x = attacker->x + 95;  // Determina a posição X do ataque
    int attack_y;

    // Determina a posição Y do ataque
    if (attacker->animacao_atual == CROUCH_PUNCH || attacker->animacao_atual == CROUCH_KICK) {
        attack_y = 220;  // Posição do ataque em pé
    } else {
        attack_y = 110;  //  Posição do ataque agachado
    }

    int defend_x = defender->x + 95;  // Determina a posição X da defesa
    int defend_y;

    // Determina a posição Y da defesa
    if (defender->is_crouching) {
        defend_y = 220;  // Posição da defesa agachado
    } else {
        defend_y = 110;  // Posição da defesa em pé
    }

    if (attacker->is_attacking) {
        if (attack_x < defend_x + HITBOX_SIZE && attack_x + HITBOX_SIZE > defend_x &&
            attack_y < defend_y + HITBOX_SIZE && attack_y + HITBOX_SIZE > defend_y) {
            
            int damage = 0;
            bool is_upper_attack = false;
            bool is_lower_attack = false;

            // Determina o tipo de ataque
            if (attacker->animacao_atual == PUNCH || attacker->animacao_atual == KICK) {
                is_upper_attack = true;  // Ataque superior
            } else if (attacker->animacao_atual == CROUCH_PUNCH || attacker->animacao_atual == CROUCH_KICK) {
                is_lower_attack = true;  // Ataque inferior
            }

            // Calcular o dano
            if (is_upper_attack) {
                if (defender->is_crouching) {
                    damage = 0;  // Nenhum dano se o defensor estiver agachado
                } else {
                    if (defender->animacao_atual == DEFEND) {
                        damage = 1;  // Dano reduzido se estiver defendendo em pé
                    } else {
                        damage = 4;  // Dano total se não estiver defendendo
                    }
                }
            } else if (is_lower_attack) {
                if (defender->is_crouching) {
                    if (defender->animacao_atual == CROUCH_DEFEND) {
                        if (attacker->animacao_atual == CROUCH_PUNCH) {
                            damage = 1;  // Dano reduzido se estiver agachado e defendendo de soco agachado
                        } else {
                            damage = 2;  // Dano reduzido se estiver agachado e defendendo de chute agachado
                        }
                    } else {
                        if (attacker->animacao_atual == CROUCH_PUNCH) {
                            damage = 2;  // Dano total se não estiver defendendo de soco agachado
                        } else {
                            damage = 4;  // Dano total se não estiver defendendo de chute agachado
                        }
                    }
                } else {
                    if (defender->animacao_atual == DEFEND) {
                        damage = 2;  // Dano reduzido se estiver defendendo em pé contra ataque inferior
                    } else {
                        if (attacker->animacao_atual == CROUCH_PUNCH) {
                            damage = 2;  // Dano total se não estiver defendendo de soco agachado
                        } else {
                            damage = 4;  // Dano total se não estiver defendendo de chute agachado
                        }
                    }
                }
            }

            // Aplicar dano ao defensor
            defender->vida -= damage;

            // Reproduzir sons
            if (damage == 0) {
                al_play_sample(som->no_hit, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            } else if (is_upper_attack) {
                al_play_sample(som->soco, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            } else if (is_lower_attack) {
                al_play_sample(som->chute, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            }
        } else {
            al_play_sample(som->no_hit, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        }
    }
}
