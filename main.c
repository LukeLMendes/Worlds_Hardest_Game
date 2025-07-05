/* Copyright (C) 2016 Marcelo Serrano Zanetti - All Rights Reserved

 * Licensed under the GNU GPL V3.0 license. All conditions apply.

 * Powered by Allegro: http://liballeg.org/license.html

 */



#include <stdio.h>

#include <allegro5/allegro.h>

#include <allegro5/allegro_image.h>

#include <allegro5/allegro_audio.h>

#include <allegro5/allegro_acodec.h>



const float FPS = 60;

const int SCREEN_W = 720;

const int SCREEN_H = 720;

const int SNAKE_TAMANHO = 46;

const int APPLE_TAMANHO = 46;

const int REBATEDOR_LARGURA = 257;

const int REBATEDOR_ALTURA = 506;



int main(int argc, char **argv)

{

    ALLEGRO_DISPLAY *display = NULL;

    ALLEGRO_EVENT_QUEUE *event_queue = NULL;

    ALLEGRO_TIMER *timer = NULL;


    if(!al_init())

    {

        fprintf(stderr, "failed to initialize allegro!\n");

        return -1; /* return -1 indica que o programa vai encerrar */

    }

    timer = al_create_timer(1.0 / FPS);

    if(!timer)

    {

        fprintf(stderr, "failed to create timer!\n");

        return -1;

    }

    bool redraw = true;

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
    ALLEGRO_BITMAP *bloco = NULL;

    ALLEGRO_BITMAP *obstaculo = NULL;

    ALLEGRO_BITMAP *moeda = NULL;

    //ALLEGRO_BITMAP *snake_body = NULL;

    //ALLEGRO_BITMAP *bola = NULL;

    //ALLEGRO_BITMAP *rebatedorEsquerda = NULL;

    //ALLEGRO_BITMAP *rebatedorDireita = NULL;

    ALLEGRO_BITMAP *background_1 = NULL;

    ALLEGRO_BITMAP *background_2 = NULL;

    ALLEGRO_BITMAP *background_3 = NULL;

    /* DECLARACAO E DEFINICAO DOS SPAWNPOINTS DE CADA FASE */
    int spawnpoint_x[3], spawnpoint_y[3], i;
    spawnpoint_x[0] = 80 - 28/2;
    spawnpoint_y[0] = 360 - 28/2;
    spawnpoint_x[1] = 360 - 28/2;
    spawnpoint_y[1] = 380 - 28/2;


    float bloco_pos_x = spawnpoint_x[0];

    float bloco_pos_y = spawnpoint_y[0];

    float bloco_vx = 0;

    float bloco_vy = 0;

    bool origem_abaixo, origem_acima, ainda_abaixo, ainda_acima;

    int deaths = 0; /*DECLARAÇÃO DA VARIAVEL QUE GUARDARÁ O VALOR DO NÚMERO DE MORTES */

    int fase = 1; /* DECLARAÇÃO DA VARIAVEL QUE CONTROLARÁ AS FASES QUE APARECEM NA TELA */


    /* CARREGAMENTO DOS BITMAPS QUE VÃO SER USADOS NO JOGO*/
    bloco             = al_load_bitmap("imagens/bloco_28.png");

    obstaculo         = al_load_bitmap("imagens/obstaculo_20.png");

    moeda             = al_load_bitmap("imagens/moeda_20.png");

    background_1  = al_load_bitmap("imagens/background_1.png");

    background_2 = al_load_bitmap("imagens/background_2.png");

    background_3 = al_load_bitmap ("imagens/background_3.png");



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


    /*DECLARACAO DAS POSICOES DOS OBSTACULOS NAS FASES DO JOGO */
    int obs_pos_x [5], obs_pos_y [5];

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
    int obs_vx[3], obs_vy [3];

    /* VELOCIDADE DOS OBSTACULOS DE CADA FASE */
    obs_vx[0] = 5;
    obs_vy[0] = 0;



    al_flip_display();

    al_start_timer(timer);

    while(1)

    {

        ALLEGRO_EVENT ev;

        al_wait_for_event(event_queue, &ev);



         if(ev.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)

        {

        }

        else if(ev.type == ALLEGRO_EVENT_TIMER)

        {
            bloco_pos_x += bloco_vx;
            bloco_pos_y += bloco_vy;

            if (fase == 1)
            {
            /* LIMITES DAS PAREDES VERTICAIS DA FASE 1*/
            if (bloco_pos_x <= 40)
            {
                bloco_pos_x = 40;
            }
            else if ((bloco_pos_x >= 120-28)&(bloco_pos_x <= 160 - 28)&(bloco_pos_y < 460)&(!origem_abaixo)&(bloco_vx > 0))
            {
                bloco_pos_x = 120 - 28;
            }
            else if ((bloco_pos_x <= 160)&(bloco_pos_x >= 120) &(bloco_pos_y < 460)&(!origem_abaixo)&(bloco_vx < 0))
            {
                bloco_pos_x = 160;
            }
            else if ((bloco_pos_x >= 200 - 28) & (bloco_pos_y >= 460 - 28) & (bloco_pos_y <= 500 - 23)&((origem_abaixo)||(ainda_abaixo)))
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
            else if ((bloco_pos_y >= 460 - 28) & (bloco_pos_x > 200 - 23) & (bloco_pos_x <= 560 - 23))
            {
                bloco_pos_y = 460 - 28;
            }
            else if ((bloco_pos_y <= 460) & (bloco_pos_x >= 120 - 28) & (bloco_pos_x <= 160) & (origem_abaixo))
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
            obs_pos_x[0] += obs_vx[0];
            obs_pos_x[2] = obs_pos_x[0];
            obs_pos_x[4] = obs_pos_x[0];

            obs_pos_x[1] -= obs_vx[0];
            obs_pos_x[3] = obs_pos_x[1];


            /* CONDICOES PARA O SENTIDO DA VELODIDADE DOS OBSTACULOS DA FASE 1 MUDAREM */
            if (obs_pos_x[0] >= 560 - 20)
            {
                obs_vx[0] = -5;
            }
            else if (obs_pos_x[0] <= 160)
            {
                obs_vx[0] = 5;
            }


            /* CHEGAGEM DAS COLISÕES COM OS OBSTACULOS DA FASE 1*/
            for (i = 0; i < 5; i++)
            {
                if ((bloco_pos_x >= obs_pos_x[i]+4-28)&(bloco_pos_x <= obs_pos_x[i] + 16)&
                (bloco_pos_y >= obs_pos_y[i]+4-28)&(bloco_pos_y <= obs_pos_y[i] + 16))
                {
                    bloco_pos_x = spawnpoint_x[0];
                    bloco_pos_y = spawnpoint_y[0];

                    deaths = deaths + 1;
                }
            }


            /* CHECAGEM SE O JOGADOR TERMINOU A FASE 1 */
            if (bloco_pos_x >= 600 - 28)
            {
                bloco_pos_x = spawnpoint_x[1];
                bloco_pos_y = spawnpoint_y[1];

                fase = 2;
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

                    bloco_vy = -2.75;


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
                    }

                    bloco_vy = 2.75;

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
                    }

                    bloco_vx = 2.75;

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

                    bloco_vx = -2.75;

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
            al_draw_bitmap(bloco,bloco_pos_x, bloco_pos_y, 0);

            /* DESENHO DOS OBSTACULOS */
            if (fase == 1)
            {
                al_draw_bitmap (obstaculo, obs_pos_x[0], obs_pos_y[0], 0);

                al_draw_bitmap(obstaculo, obs_pos_x[2], obs_pos_y[2], 0);

                al_draw_bitmap(obstaculo, obs_pos_x[4], obs_pos_y[4], 0);

                al_draw_bitmap(obstaculo, obs_pos_x[1], obs_pos_y[1], 0);

                al_draw_bitmap(obstaculo, obs_pos_x[3], obs_pos_y[3], 0);
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

