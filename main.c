/* Copyright (C) 2016 Marcelo Serrano Zanetti - All Rights Reserved

 * Licensed under the GNU GPL V3.0 license. All conditions apply.

 * Powered by Allegro: http://liballeg.org/license.html

 */


#include <stdio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

const float FPS = 60;
const int SCREEN_W = 720;
const int SCREEN_H = 720;

int main(int argc, char **argv)
{
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_FONT *font = al_load_ttf_font("fonts/regular.ttf", 100, 0);
    ALLEGRO_FONT *font2 = al_load_ttf_font("fonts/regular.ttf", 110, 0);

    if(!al_init())
    {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1; /* return -1 indica que o programa vai encerrar */
    }


    if (!font)
    {
        printf("falha ao carregar fonte!\n");
        return -1;
    }

    timer = al_create_timer(1.0 / FPS);
    if(!timer)
    {
        fprintf(stderr, "failed to create timer!\n");
        return -1;
    }

    bool redraw = true;
    bool running = true;

    al_set_new_display_option(ALLEGRO_VSYNC, 1, ALLEGRO_REQUIRE);
    al_set_new_display_flags(ALLEGRO_OPENGL | ALLEGRO_WINDOWED);

    display = al_create_display(SCREEN_W, SCREEN_H);
    if(!display)
    {
        fprintf(stderr, "failed to create display!\n");
        al_destroy_timer(timer); /* serve para desalocar o ponteiro relacionado ao timer */
        return -1;
    }

    if(!al_install_keyboard())
    {
        fprintf(stderr, "failed to initialize the keyboard!\n");
        return -1;
    }

    if(!al_install_mouse())
    {
        fprintf(stderr, "failed to initialize the mouse!\n");
        return -1;
    }

    if(!al_init_image_addon())
    {
        fprintf(stderr, "failed to initialize the image addon!\n");
        return -1;

    }

    /* DECLARAÇÃO DOS BITMAPS */
    ALLEGRO_BITMAP *bloco           = NULL;
    ALLEGRO_BITMAP *obstaculo       = NULL;
    ALLEGRO_BITMAP *moeda           = NULL;
    ALLEGRO_BITMAP *background_menu = NULL;
    ALLEGRO_BITMAP *background_1    = NULL;
    ALLEGRO_BITMAP *background_2    = NULL;
    ALLEGRO_BITMAP *background_3    = NULL;


    /* DECLARACAO E DEFINICAO DOS SPAWNPOINTS DE CADA FASE */
    int spawnpoint_x[3], spawnpoint_y[3], i;
    spawnpoint_x[0] = 80 - 28/2;
    spawnpoint_y[0] = 360 - 28/2;
    spawnpoint_x[1] = 360 - 28/2;
    spawnpoint_y[1] = 380 - 28/2;
    spawnpoint_x[2] = 180 - 28/2;
    spawnpoint_y[2] = 220 - 28/2;

    float bloco_pos_x = spawnpoint_x[0];
    float bloco_pos_y = spawnpoint_y[0];
    float bloco_vx = 0;
    float bloco_vy = 0;
    bool origem_abaixo, origem_acima, ainda_abaixo, ainda_acima, apertou_em_cima, contra_bug, contra_bug_2, can_move, key_down_before;
    float alpha = 0; /*DECLARAÇÃO DO GRAU DE TRANSPARÊNCIA DO OBJETO */
    int deaths = 0; /*DECLARAÇÃO DA VARIAVEL QUE GUARDARÁ O VALOR DO NÚMERO DE MORTES */
    int fase = 1; /* DECLARAÇÃO DA VARIAVEL QUE CONTROLARÁ AS FASES QUE APARECEM NA TELA */
    int qtd_moeda = 0; /* DECLARAÇÃO DA QUANTIDADE DE MOEDAS COLETADAS PELO JOGADOR */

    /* CARREGAMENTO DOS BITMAPS QUE VÃO SER USADOS NO JOGO*/
    bloco             = al_load_bitmap("imagens/bloco_28.png");
    obstaculo         = al_load_bitmap("imagens/obstaculo_20.png");
    moeda             = al_load_bitmap("imagens/moeda_20.png");
    background_menu  = al_load_bitmap("imagens/backgroundmenu.jpg");
    background_1      = al_load_bitmap("imagens/background_1.png");
    background_2      = al_load_bitmap("imagens/background_2.png");
    background_3      = al_load_bitmap ("imagens/background_3.png");


    if(!bloco)
    {
        fprintf(stderr, "falhou ao criar a snake bitmap!\n");
        return -1;
    }

    if(!background_1)
    {
        fprintf(stderr, "falhou ao criar o background bitmap!\n");
        return -1;
    }

    al_set_target_bitmap(al_get_backbuffer(display));
    event_queue = al_create_event_queue();

    if(!event_queue)
    {
        fprintf(stderr, "failed to create event_queue!\n");
        return -1;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_clear_to_color(al_map_rgb(0,0,0));

    /* DECLARAÇÃO DAS POSICÕES DAS MOEDAS DAS FASES DO JOGO */
    int moeda_pos_x[5], moeda_pos_y[5];

    /*DECLARACAO DAS POSICOES DOS OBSTACULOS NAS FASES DO JOGO */
    int obs_pos_x [11], obs_pos_y [11];

    /* POSIÇÕES INICIAIS DOS OBSTACULOS NA FASE 1 */
    for (i = 0; i < 5; i++)
    {
        obs_pos_x[i]= 360 - 20/2;
        obs_pos_y[i] = 440 - 20/2;

        if (i >= 1)
        {
            obs_pos_y[i] = obs_pos_y [i-1] - 40;
        }
    }

    /* DECLARAÇÃO DAS VELOCIDADES DOS OBSTACULOS DE CADA FASE */
    int obs_vx_1, obs_vy_1, obs_vx_2[11], obs_vy_2[11];

    /* VELOCIDADE DOS OBSTACULOS DA FASE 1 */
    obs_vx_1 = 6;
    obs_vy_1 = 0;

    al_flip_display();
    al_start_timer(timer);

    bool menu = true;

    while(menu){

        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        } else if (ev.type == ALLEGRO_EVENT_TIMER) {
            redraw = true;
        } else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {

            int mx = ev.mouse.x;
            int my = ev.mouse.y;

                    //PLAYBUTTON
            int largura_play = al_get_text_width(font, "PLAY");
            int altura_play = al_get_font_line_height(font);
            float play_pos_x = (SCREEN_W - largura_play) / 2.0;
            float play_pos_Y = SCREEN_H / 2 - 30;

                    //CONFIGBUTTON
            int largura_config = al_get_text_width(font, "CONFIG");
            int altura_config = al_get_font_line_height(font);
            float config_pos_x = (SCREEN_W - largura_config) / 2.0;
            float config_pos_Y = SCREEN_H / 2 + 60;

                    //CLICK PLAY
            if (mx >= play_pos_x && mx <= play_pos_x + largura_play &&
                my >= play_pos_Y && my <= play_pos_Y + altura_play) {

                menu = false;

                break;

                al_clear_to_color(al_map_rgb(0,0,0));

            }
                    //CLICK COONFIG
            if (mx >= config_pos_x && mx <= config_pos_x + largura_config &&
                my >= config_pos_Y + 31 && my <= config_pos_Y + altura_config + 30) {
                printf("Config!\n");

            }
        }

        if (redraw && al_is_event_queue_empty(event_queue)) {
            redraw = false;

            //LOAD IMAGES
            al_draw_bitmap(background_menu, 0, 0, 0);

            // COORD MOUSE
            ALLEGRO_MOUSE_STATE mouse_state;
            al_get_mouse_state(&mouse_state);

            // DECLARAR TAMANHOS E POSICOES

                    //PLAYBUTTON
            int largura_play = al_get_text_width(font, "PLAY");
            int altura_play = al_get_font_line_height(font);
            float play_pos_x = (SCREEN_W - largura_play) / 2.0;
            float play_pos_Y = SCREEN_H / 2 - 30;

                    //CONFIGBUTTON
            int largura_config = al_get_text_width(font, "CONFIG");
            int altura_config = al_get_font_line_height(font);
            float config_pos_x = (SCREEN_W - largura_config) / 2.0;
            float config_pos_Y = SCREEN_H / 2 + 60;

            int mx = mouse_state.x;
            int my = mouse_state.y;

            // AUMENTAR BOTOES
            if (
                mx >= play_pos_x && mx <= play_pos_x + largura_play &&
                my >= play_pos_Y && my <= play_pos_Y + altura_play) {
                al_draw_text(font2, al_map_rgb(255,0,0), SCREEN_W/2, SCREEN_H/2 - 30, ALLEGRO_ALIGN_CENTRE, "PLAY");
                al_draw_text(font, al_map_rgb(255,0,0), SCREEN_W/2, SCREEN_H/2 + 80, ALLEGRO_ALIGN_CENTRE, "CONFIG");
            }

            else if (
                mx >= (config_pos_x) && mx <= (config_pos_x + largura_config) &&
                my >= (config_pos_Y) && my <= (config_pos_Y + altura_config)) {
                al_draw_text(font, al_map_rgb(255,0,0), SCREEN_W/2, SCREEN_H/2 - 30, ALLEGRO_ALIGN_CENTRE, "PLAY");
                al_draw_text(font2, al_map_rgb(255,0,0), SCREEN_W/2, SCREEN_H/2 + 80, ALLEGRO_ALIGN_CENTRE, "CONFIG");

            } else {
                al_draw_text(font, al_map_rgb(255,0,0), SCREEN_W/2, SCREEN_H/2 - 30, ALLEGRO_ALIGN_CENTRE, "PLAY");
                al_draw_text(font, al_map_rgb(255,0,0), SCREEN_W/2, SCREEN_H/2 + 80, ALLEGRO_ALIGN_CENTRE, "CONFIG");
            }

            al_flip_display();
        }
    }

    while(!menu){

        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
        }

        else if(ev.type == ALLEGRO_EVENT_TIMER)
        {
            bloco_pos_x += bloco_vx;
            bloco_pos_y += bloco_vy;

            if(alpha > 1.0)
            {
                alpha = 1.0;
            }

            if (alpha != 1.0)
            {
                alpha += 0.05;
                can_move = false;
            }

            else if (alpha == 1.0)
            {
                can_move = true;
            }

            if (fase == 1)
            {
                /* LIMITES DAS PAREDES VERTICAIS DA FASE 1*/
                if (bloco_pos_x <= 40)
                {
                    bloco_pos_x = 40;
                }
                else if ((bloco_pos_x >= 120-28)&(bloco_pos_x <= 160 - 28)&(bloco_pos_y < 460-5)&((!origem_abaixo)||(contra_bug))&(bloco_vx > 0))
                {
                    bloco_pos_x = 120 - 28;
                }
                else if ((bloco_pos_x <= 160)&(bloco_pos_x >= 120) &(bloco_pos_y < 460-5)&(!origem_abaixo)&(bloco_vx < 0))
                {
                    bloco_pos_x = 160;
                }
                else if ((bloco_pos_x >= 200 - 28) & (bloco_pos_y > 460 - 23) & (bloco_pos_y <= 500 - 23)&((origem_abaixo)||(ainda_abaixo)||(contra_bug_2)))
                {
                    bloco_pos_x = 200 - 28;
                }
                else if ((bloco_pos_x <= 520) & (bloco_pos_y >= 220-5) & (bloco_pos_y <= 260) & ((origem_acima)||(ainda_acima)))
                {
                    bloco_pos_x = 520;
                }
                else if ((bloco_pos_x >= 560 - 28) & (bloco_pos_y > 260 - 28) & (bloco_pos_y <= 460 - 23)&(!origem_acima))
                {
                    bloco_pos_x = 560 - 28;
                }

                /* LIMITES DAS PAREDES HORIZONTAIS DA FASE 1*/
                if (bloco_pos_y >= 500 - 28)
                {
                    bloco_pos_y = 500 - 28;
                }
                else if ((bloco_pos_y >= 460 - 28) & (bloco_pos_x > 200 - 23) & (bloco_pos_x <= 560 - 23) & (!origem_abaixo))
                {
                    bloco_pos_y = 460 - 28;
                }
                else if ((bloco_pos_y <= 460)&(bloco_pos_x > 120 - 28)&(bloco_pos_x < 160)&((origem_abaixo)||(contra_bug)))
                {
                    bloco_pos_y = 460;
                }
                else if (bloco_pos_y <= 220)
                {
                    bloco_pos_y = 220;
                }
                else if ((bloco_pos_y <= 260)&(bloco_pos_x >= 40)&(bloco_pos_x <= 120 - 25))
                {
                    bloco_pos_y = 260;
                }
                else if ((bloco_pos_y <= 260)&(bloco_pos_x >=155)&(bloco_pos_x < 520)&(!origem_acima)&(!ainda_acima))
                {
                    bloco_pos_y = 260;
                }
                else if ((bloco_pos_y >= 260 - 28)&(bloco_pos_x>= 560 - 28)&(bloco_pos_x <= 600 + 28)&(origem_acima))
                {
                    bloco_pos_y = 260 - 28;
                }

                /* DEFINICAO DE COMO AS POSICOES DOS OBSTACULOS DA FASE 1 VARIAM */
                obs_pos_x[0] += obs_vx_1;
                obs_pos_x[2] = obs_pos_x[0];
                obs_pos_x[4] = obs_pos_x[0];
                obs_pos_x[1] -= obs_vx_1;
                obs_pos_x[3] = obs_pos_x[1];


                /* CONDICOES PARA O SENTIDO DA VELODIDADE DOS OBSTACULOS DA FASE 1 MUDAREM */
                if (obs_pos_x[0] >= 560 - 20)
                {
                    obs_vx_1 = -6;
                }
                else if (obs_pos_x[0] <= 160)
                {
                    obs_vx_1 = 6;
                }


                /* CHEGAGEM DAS COLISÕES COM OS OBSTACULOS DA FASE 1*/
                for (i = 0; i < 5; i++)
                {
                    if ((bloco_pos_x >= obs_pos_x[i]+4-28)&(bloco_pos_x <= obs_pos_x[i] + 16)&
                    (bloco_pos_y >= obs_pos_y[i]+4-28)&(bloco_pos_y <= obs_pos_y[i] + 16))
                    {
                        bloco_vx = 0;
                        bloco_vy = 0;

                        alpha = 0;

                        bloco_pos_x = spawnpoint_x[0];
                        bloco_pos_y = spawnpoint_y[0];

                        deaths = deaths + 1;

                        if (origem_abaixo)
                        {
                            contra_bug = true;
                            contra_bug_2 = false;
                        }
                        else
                        {
                            contra_bug = false;
                            contra_bug_2 = true;
                        }
                    }
                }


                /* CHECAGEM PARA VER SE O JOGADOR TERMINOU A FASE 1 */
                if (bloco_pos_x >= 600 - 28)
                {
                    fase = 2;
                    bloco_pos_x = spawnpoint_x[1];
                    bloco_pos_y = spawnpoint_y[1];
                    bloco_vx = 0;
                    bloco_vy = 0;
                    alpha = 0;

                    /* DEFINIÇÃO DAS POSIÇÕES DE ONDE COMEÇARÃO OS OBSTACULOS DA FASE 2 */
                    obs_pos_x[0] = 300 - 20/2;
                    obs_pos_y[0] = 320 - 20/2;

                    for (i=1; i<11; i++)
                    {
                        if ((i>=1)&(i<=3))
                        {
                            obs_pos_y[i] = obs_pos_y[i-1];
                            obs_pos_x[i] = obs_pos_x[i-1] + 40;
                        }
                        else if((i>=4)&(i<=6))
                        {
                            obs_pos_x[i] = obs_pos_x [i-1];
                            obs_pos_y[i] = obs_pos_y[i-1] + 40;
                        }
                        else if (i == 7)
                        {
                            obs_pos_y[i]=obs_pos_y[i-1];
                            obs_pos_x[i]=obs_pos_x[i-1]-40;
                        }
                        else if((i >= 8)&(i<=10))
                        {
                            obs_pos_x[i]=obs_pos_x[0];
                            obs_pos_y[i]=obs_pos_y[0]+40*(11-i);
                        }
                    }

                    /* DEFINIÇÃO DA VELOCIDADE INICIAL DOS OBSTACULOS DA FASE 2 */
                    obs_vx_2[0] = 0;
                    obs_vy_2[0] = -3;

                    for (i=1; i<11; i++)
                    {
                        if ((i>=1)&(i<=3))
                        {
                            obs_vx_2[i] = 3;
                            obs_vy_2[i]= 0;
                        }
                        else if((i>=4)&(i<=6))
                        {
                            obs_vx_2[i] = 0;
                            obs_vy_2[i] = 3;
                        }
                        else if(i==7)
                        {
                            obs_vx_2[i] = -3;
                            obs_vy_2[i] = 0;
                        }
                        else if((i>=8)&(i<=10))
                        {
                            obs_vx_2[i] = 0;
                            obs_vy_2[i] = -3;
                        }
                    }

                    /* DEFINICAO DA POSICAO DA MOEDA DA FASE 2 */
                    moeda_pos_x[0] = 300 - 20/2;
                    moeda_pos_y[0] = 280 - 20/2;
                }
            }
            else if (fase == 2)
            {
                    /* LIMITES DAS PAREDES VERTICAIS DA FASE 2 */
                    if (bloco_pos_x <= 280)
                    {
                        bloco_pos_x = 280;
                    }
                    else if (bloco_pos_x >= 440 - 28)
                    {
                        bloco_pos_x = 440 - 28;
                    }
                    else if((bloco_pos_x >= 320 - 28)&(bloco_pos_y>= 255)&(bloco_pos_y<=300)&((!origem_abaixo)||(ainda_acima)))
                    {
                        bloco_pos_x = 320 - 28;
                    }

                    /* LIMITES DAS PAREDES HORIZONTAIS DA FASE 2 */

                    if (bloco_pos_y <= 260)
                    {
                        bloco_pos_y = 260;
                    }
                    else if ((bloco_pos_y <= 300)&(bloco_pos_x>320-28)&(bloco_pos_x <= 440 - 28)&(origem_abaixo))
                    {
                        bloco_pos_y = 300;
                    }
                    else if(bloco_pos_y >= 460 - 28)
                    {
                        bloco_pos_y = 460 - 28;
                    }

                    for (i=0; i<11; i++)
                    {
                        obs_pos_y[i] += obs_vy_2[i];
                        obs_pos_x[i] += obs_vx_2[i];
                    }

                    /* CHECAGEM DOS MOMENTOS NOS QUAIS O SENTIDO DAS VELOCIDADES DOS OBSTACULOS DA FASE 2 MUDARÃO */
                    for (i = 0; i < 11; i++)
                    {
                        if ((obs_pos_x[i] + 10 == 300)&(obs_pos_y[i]+10 <= 320))
                        {
                            obs_pos_x[i] = 300 - 10;
                            obs_pos_y[i] = 320 - 10;

                            obs_vx_2[i] = 3;
                            obs_vy_2[i] = 0;
                        }
                        else if ((obs_pos_x[i] + 10 >= 420)&(obs_pos_y[i]+10 == 320))
                        {
                            obs_pos_x[i] = 420 - 10;
                            obs_pos_y[i] = 320 - 10;

                            obs_vx_2[i] = 0;
                            obs_vy_2[i] = 3;
                        }
                        else if((obs_pos_x[i]+10 == 420)&(obs_pos_y[i]+10 >= 440))
                        {
                            obs_pos_x[i] = 420 - 10;
                            obs_pos_y[i] = 440 - 10;

                            obs_vx_2[i] = -3;
                            obs_vy_2[i] = 0;
                        }
                        else if((obs_pos_x[i]+10 <= 300)&(obs_pos_y[i]+10 == 440))
                        {
                            obs_pos_x[i] = 300 - 10;
                            obs_pos_y[i] = 440 - 10;

                            obs_vx_2[i] = 0;
                            obs_vy_2[i] = -3;
                        }
                    }

                    /* CHEGAGEM DAS COLISÕES COM OS OBSTACULOS DA FASE 2*/
                    for (i = 0; i < 11; i++)
                    {
                        if ((bloco_pos_x >= obs_pos_x[i]+4-28)&(bloco_pos_x <= obs_pos_x[i] + 16)&
                        (bloco_pos_y >= obs_pos_y[i]+4-28)&(bloco_pos_y <= obs_pos_y[i] + 16)&(qtd_moeda==0))
                        {
                            bloco_vx = 0;
                            bloco_vy = 0;
                            alpha = 0;
                            bloco_pos_x = spawnpoint_x[1];
                            bloco_pos_y = spawnpoint_y[1];

                            deaths = deaths + 1;
                        }
                        else if ((bloco_pos_x >= obs_pos_x[i]+5-28)&(bloco_pos_x <= obs_pos_x[i] + 15)&
                        (bloco_pos_y >= obs_pos_y[i]+5-28)&(bloco_pos_y <= obs_pos_y[i] + 15)&(qtd_moeda==1))
                        {
                            bloco_vx = 0;
                            bloco_vy = 0;
                            alpha = 0;
                            bloco_pos_x = spawnpoint_x[1];
                            bloco_pos_y = spawnpoint_y[1];
                            deaths = deaths + 1;
                            qtd_moeda = 0;
                        }
                    }

                    /* CHECAGEM PARA VER SE O JOGADOR COLETOU A MOEDA DA FASE 2 */
                    if ((bloco_pos_x >= moeda_pos_x[0]+4-28)&(bloco_pos_x <= moeda_pos_x[0] + 16)&
                    (bloco_pos_y >= moeda_pos_y[0]+4-28)&(bloco_pos_y <= moeda_pos_y[0] + 16))
                    {
                        qtd_moeda = 1;
                    }

                    /* CHECAGEM PARA VER SE O JOGADOR TERMINOU A FASE 1 */
                    if ((bloco_pos_x >= 320 - 28)&(bloco_pos_x <= 400)&(bloco_pos_y >= 340 - 28)&
                    (bloco_pos_y <= 420)&(qtd_moeda == 1))
                    {
                        fase = 3;
                        bloco_pos_x = spawnpoint_x[2];
                        bloco_pos_y = spawnpoint_y[2];
                        bloco_vx = 0;
                        bloco_vy = 0;
                        alpha = 0;
                    }
            }

            redraw = true;
        }

        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(ev.keyboard.keycode)
            {
                case (ALLEGRO_KEY_W):
                    if (fase == 1)
                    {
                        /* REGULAGEM DO FATOR origem_acima */
                        if (bloco_pos_y <= 260-28)
                        {
                            origem_acima = true;
                        }
                        else
                        {
                            origem_acima = false;
                        }

                        /* REGULAGEM DO FATOR origem_abaixo */
                        if (bloco_pos_y >= 460)
                        {
                            origem_abaixo = true;
                        }
                        else
                        {
                            origem_abaixo = false;
                        }

                        /* REGULAGEM DO FATOR origem_abaixo */
                        if ((bloco_pos_x <= 200 - 28)&(bloco_pos_y >= 460 - 28))
                        {
                            ainda_abaixo = true;
                        }
                        else
                        {
                            ainda_abaixo = false;
                        }

                        /* REGULAGEM DO FATOR ainda_acima */
                        if ((bloco_pos_x >= 520)&(bloco_pos_y <= 260 + 28))
                        {
                            ainda_acima = true;
                        }
                        else
                        {
                            ainda_acima = false;
                        }
                    }
                    else if (fase == 2)
                    {

                        /* REGULAGEM DO FATOR origem_abaixo */
                        if (bloco_pos_y >= 300 - 5)
                        {
                            origem_abaixo = true;
                        }
                        else
                        {
                            origem_abaixo = false;
                        }

                        if((bloco_pos_x <= 320 - 28)&(bloco_pos_y >= 260)&(bloco_pos_y <= 300))
                        {
                            ainda_acima = true;
                        }
                        else
                        {
                            ainda_acima = false;
                        }
                    }

                    if (can_move)
                    {
                        bloco_vy = -2.75;
                    }
                    else
                    {
                        bloco_vy = 0;
                    }

                    break;

                case (ALLEGRO_KEY_S):

                    if (fase == 1)
                    {
                        /* REGULAGEM DO FATOR origem_acima */
                        if (bloco_pos_y <= 260 - 28)
                        {
                            origem_acima = true;
                        }
                        else
                        {
                            origem_acima = false;
                        }

                        /* REGULAGEM DO FATOR origem_abaixo */
                        if (bloco_pos_y >= 460)
                        {
                            origem_abaixo = true;
                        }
                        else
                        {
                            origem_abaixo = false;
                        }

                        /* REGULAGEM DO FATOR ainda_abaixo */
                        if ((bloco_pos_x <= 200 - 28)&(bloco_pos_y >= 460 - 28))
                        {
                            ainda_abaixo = true;
                        }
                        else
                        {
                            ainda_abaixo = false;
                        }

                        /* REGULAGEM DO FATOR ainda_acima */
                        if ((bloco_pos_x >= 520-5)&(bloco_pos_y <= 260 + 28))
                        {
                            ainda_acima = true;
                        }
                        else
                        {
                            ainda_acima = false;
                        }

                        /* REGULAGEM DO FATOR ainda_acima */
                        if ((bloco_pos_x >= 520)&(bloco_pos_y <= 260 + 28))
                        {
                            ainda_acima = true;
                        }
                        else
                        {
                            ainda_acima = false;
                        }

                        /* REGULAGEM DO FATOR apertou_em_cima */
                        if ((bloco_pos_x <= 120-28)&(bloco_pos_y >= 260)&(bloco_pos_y <= 500 - 28))
                        {
                            apertou_em_cima = true;
                        }
                        else
                        {
                            apertou_em_cima = false;
                        }
                    }

                    if (can_move)
                    {
                        bloco_vy = 2.75;
                    }
                    else
                    {
                        bloco_vy = 0;
                    }


                    break;

                case ALLEGRO_KEY_D:

                    if (fase == 1)
                    {
                        /* REGULAGEM DO FATOR origem_abaixo */
                        if (bloco_pos_y >= 455)
                        {
                            origem_abaixo = true;
                        }
                        else
                        {
                            origem_abaixo = false;
                        }

                        /* REGULAGEM DO FATOR origem_acima */
                        if (bloco_pos_y <= 260 - 23)
                        {
                            origem_acima = true;
                        }
                        else
                        {
                            origem_acima = false;
                        }

                        /* REGULAGEM DO FATOR ainda_abaixo */
                        if ((bloco_pos_x <= 200 - 28)&(bloco_pos_y >= 460 - 28))
                        {
                            ainda_abaixo = true;
                        }
                        else
                        {
                            ainda_abaixo = false;
                        }

                        /* REGULAGEM DO FATOR apertou_em_cima */
                        if ((bloco_pos_x <= 120-28)&(bloco_pos_y >= 260)&(bloco_pos_y <= 500 - 28))
                        {
                            apertou_em_cima = true;
                        }
                        else
                        {
                            apertou_em_cima = false;
                        }
                    }
                    else if (fase == 2)
                    {
                        /* REGULAGEM DO FATOR origem_abaixo */
                        if (bloco_pos_y >= 300 - 5)
                        {
                            origem_abaixo = true;
                        }
                        else
                        {
                            origem_abaixo = false;
                        }
                    }

                    if (can_move)
                    {
                        bloco_vx = 2.75;
                    }
                    else
                    {
                        bloco_vx = 0;
                    }


                    break;

                case ALLEGRO_KEY_A:

                    if (fase == 1)
                    {
                        /* REGULAGEM DO FATOR origem_acima */
                        if (bloco_pos_y <= 260 - 23)
                        {
                            origem_acima = true;
                        }
                        else
                        {
                            origem_acima = false;
                        }

                        /* REGULAGEM DO FATOR origem_abaixo */
                        if (bloco_pos_y >= 455)
                        {
                            origem_abaixo = true;
                        }
                        else
                        {
                            origem_abaixo = false;
                        }

                        /* REGULAGEM DO FATOR ainda_abaixo */
                        if ((bloco_pos_x <= 200 - 28)&(bloco_pos_y >= 460 - 28))
                        {
                            ainda_abaixo = true;
                        }
                        else
                        {
                            ainda_abaixo = false;
                        }

                        /* REGULAGEM DO FATOR ainda_acima */
                        if ((bloco_pos_x >= 520-5)&(bloco_pos_y <= 260 + 28))
                        {
                            ainda_acima = true;
                        }
                        else
                        {
                            ainda_acima = false;
                        }
                    }
                    else if (fase == 2)
                    {
                        /* REGULAGEM DO FATOR origem_abaixo */
                        if (bloco_pos_y >= 300 - 5)
                        {
                            origem_abaixo = true;
                        }
                        else
                        {
                            origem_abaixo = false;
                        }
                    }

                    if (can_move)
                    {
                        bloco_vx = -2.75;
                    }
                    else
                    {
                        bloco_vx = 0;
                    }


                    break;

                case ALLEGRO_KEY_ESCAPE:

                    return 0;

                    break;
            }
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_D:
                if (bloco_vx > 0)
                {
                    bloco_vx = 0;
                }

                break;

            case ALLEGRO_KEY_A:
                if (bloco_vx < 0)
                {
                    bloco_vx = 0;
                }

                break;

            case ALLEGRO_KEY_W:
                if (bloco_vy < 0)
                {
                    bloco_vy = 0;
                }

                break;

            case ALLEGRO_KEY_S:
                if (bloco_vy > 0)
                {
                    bloco_vy = 0;
                }

                break;

            }
        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            break;
        }

        if(redraw && al_is_event_queue_empty(event_queue))
        {

            redraw = false;

            al_clear_to_color(al_map_rgb(0,100,0));

            /* DESENHO DOS BACKGROUNDS/FASES */
            if (fase == 1)
            {
                al_draw_bitmap(background_1, 0, 0, 0);
            }
            else if (fase == 2)
            {
                al_draw_bitmap(background_2, 0, 0, 0);
            }
            else if (fase == 3)
            {
                al_draw_bitmap(background_3, 0, 0, 0);
            }

            /* DESENHO DO BLOCO */
            al_draw_tinted_bitmap(bloco, al_map_rgba_f(1, 1, 1, alpha), bloco_pos_x, bloco_pos_y, 0);

            /* DESENHO DOS OBSTACULOS */
            if (fase == 1)
            {
                al_draw_bitmap (obstaculo, obs_pos_x[0], obs_pos_y[0], 0);
                al_draw_bitmap(obstaculo, obs_pos_x[2], obs_pos_y[2], 0);
                al_draw_bitmap(obstaculo, obs_pos_x[4], obs_pos_y[4], 0);
                al_draw_bitmap(obstaculo, obs_pos_x[1], obs_pos_y[1], 0);
                al_draw_bitmap(obstaculo, obs_pos_x[3], obs_pos_y[3], 0);
            }
            else if (fase == 2)
            {
                for (i = 0; i<11; i++)
                {
                    al_draw_bitmap(obstaculo, obs_pos_x[i], obs_pos_y[i], 0);
                }

                if (qtd_moeda == 0)
                {
                    al_draw_bitmap(moeda, moeda_pos_x[0], moeda_pos_y[0], 0);
                }
            }

            al_flip_display();

        }

    }


    al_destroy_bitmap(bloco);
    al_destroy_bitmap(obstaculo);
    al_destroy_bitmap(moeda);
    al_destroy_bitmap(background_1);
    al_destroy_bitmap(background_2);
    al_destroy_bitmap(background_3);
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;

}

