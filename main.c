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

<<<<<<< HEAD



=======
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a
const float FPS = 60;
const int SCREEN_W = 720;
const int SCREEN_H = 720;

<<<<<<< HEAD

=======
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a
int main(int argc, char **argv)
{
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(1);

    ALLEGRO_DISPLAY *display                = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue        = NULL;
    ALLEGRO_TIMER *timer                    = NULL;
    ALLEGRO_FONT *font                      = al_load_ttf_font("fonts/American Captain.ttf", 100, 0);
    ALLEGRO_FONT *font2                     = al_load_ttf_font("fonts/American Captain.ttf", 110, 0);
    ALLEGRO_FONT *font3                     = al_load_ttf_font("fonts/American Captain.ttf", 60, 0);
    ALLEGRO_FONT *font4                     = al_load_ttf_font("fonts/American Captain.ttf", 120, 0);
    ALLEGRO_AUDIO_STREAM *musica            = al_load_audio_stream("audios/musica.ogg", 4, 2048);
    ALLEGRO_SAMPLE *selectingmenu_sample    = al_load_sample("audios/selectingaudio.ogg");
    ALLEGRO_SAMPLE_INSTANCE *selectingmenu  = al_create_sample_instance(selectingmenu_sample);


    al_attach_sample_instance_to_mixer(selectingmenu, al_get_default_mixer());

<<<<<<< HEAD
    al_init();

    al_init_font_addon();

    al_init_ttf_addon();

    al_init_image_addon();

    al_install_audio();

    al_init_acodec_addon();

    al_reserve_samples(1);

    ALLEGRO_FONT *font               = al_load_ttf_font("fonts/American Captain.ttf", 100, 0);
    ALLEGRO_FONT *font2              = al_load_ttf_font("fonts/American Captain.ttf", 110, 0);
    ALLEGRO_FONT *font3              = al_load_ttf_font("fonts/American Captain.ttf", 60, 0);
    ALLEGRO_FONT *font4              = al_load_ttf_font("fonts/American Captain.ttf", 40, 0 );

    ALLEGRO_AUDIO_STREAM *musica     = al_load_audio_stream("audios/musica.ogg", 4, 2048);
    ALLEGRO_SAMPLE *colisao = al_load_sample("audios/steve.wav");
    ALLEGRO_SAMPLE *selectingmenu_sample    = al_load_sample("audios/selectingaudio.ogg");
    ALLEGRO_SAMPLE_INSTANCE *selectingmenu  = al_create_sample_instance(selectingmenu_sample);

    al_attach_sample_instance_to_mixer(selectingmenu, al_get_default_mixer());

=======
    if (!selectingmenu) {
        printf("Erro ao carregar musica!\n");
        return -1;
    }
    if (!selectingmenu_sample) {
        fprintf(stderr, "Erro ao criar instância do sample\n");
        return -1;
    }
    if (!musica) {
        printf("Erro ao carregar musica!\n");
        return -1;
    }
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a

    if(!al_init())
    {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    if (!font)
    {
        printf("falha ao carregar fonte!\n");
        return -1;
    }

    if (!musica)
    {
        printf("Erro ao carregar musica!\n");
        return -1;
    }

    if (!colisao)
    {
        printf ("Erro ao carregar som de colisao!\n");
        return -1;
    }

    if (!font)
    {
        printf("falha ao carregar fonte!\n");
        return -1;
    }

    if (!selectingmenu)
    {
        printf("Erro ao carregar musica!\n");
        return -1;
    }
    if (!selectingmenu_sample)
    {
        fprintf(stderr, "Erro ao criar instância do sample\n");
        return -1;
    }

    ///definição do timer
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
        al_destroy_timer(timer); // serve para desalocar o ponteiro relacionado ao timer
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

<<<<<<< HEAD
    /* DECLARAÇÃO DOS BITMAPS */
    ALLEGRO_BITMAP *bloco = NULL;

    ALLEGRO_BITMAP *obstaculo = NULL;

    ALLEGRO_BITMAP *moeda = NULL;

    ALLEGRO_BITMAP *background_1 = NULL;

    ALLEGRO_BITMAP *background_2 = NULL;

    ALLEGRO_BITMAP *background_3 = NULL;
=======
    /* DECLARACAO DOS BITMAPS */
    ALLEGRO_BITMAP *bloco           = NULL;
    ALLEGRO_BITMAP *obstaculo       = NULL;
    ALLEGRO_BITMAP *moeda           = NULL;
    ALLEGRO_BITMAP *background_menu = NULL;
    ALLEGRO_BITMAP *background_1    = NULL;
    ALLEGRO_BITMAP *background_2    = NULL;
    ALLEGRO_BITMAP *background_3    = NULL;
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a

    ALLEGRO_BITMAP *background_menu = NULL;

    /* DECLARACAO E DEFINICAO DOS SPAWNPOINTS DE CADA FASE */
<<<<<<< HEAD
    int spawnpoint_x[3], spawnpoint_y[3], i, j;
    spawnpoint_x[0] = 80 - 28/2;
=======
    int spawnpoint_x[3], spawnpoint_y[3], i;
    spawnpoint_x[0] = 80  - 28/2;
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a
    spawnpoint_y[0] = 360 - 28/2;
    spawnpoint_x[1] = 360 - 28/2;
    spawnpoint_y[1] = 380 - 28/2;
    spawnpoint_x[2] = 180 - 28/2;
    spawnpoint_y[2] = 220 - 28/2;

<<<<<<< HEAD

    float bloco_pos_x = spawnpoint_x[0];

    float bloco_pos_y = spawnpoint_y[0];

    float bloco_vx = 0;

    float bloco_vy = 0;

    bool origem_abaixo, origem_acima, ainda_abaixo, ainda_acima, contra_bug, contra_bug_2, can_move;


    float volume = 0.5; /* DECLARAÇÃO DO VOLUME DO SOM */

    bool playingsound = true;

    float alpha = 0; /* DECLARAÇÃO DO GRAU DE TRANSPARÊNCIA DO OBJETO */

    int deaths = 0; /* DECLARAÇÃO DA VARIAVEL QUE GUARDARÁ O VALOR DO NÚMERO DE MORTES */

    int fase = 1; /* DECLARAÇÃO DA VARIAVEL QUE CONTROLARÁ AS FASES QUE APARECEM NA TELA */

    int qtd_moeda = 0; /* DECLARAÇÃO DA QUANTIDADE DE MOEDAS COLETADAS PELO JOGADOR NA FASE 2 */

    bool moeda_fora[4]; /* DECLARACÃO DA VARIAVEL QUE CONTERA A INFORMAÇÃO SE UMA MOEDA DA FASE 3 FOI PEGA OU NÃO */

    char cont_mortes[50]; /* DECLARAÇÃO DO ARRAY QUE VAI MOSTRAR O NÚMERO DE MORTES */


    /* CARREGAMENTO DOS BITMAPS QUE VÃO SER USADOS NO JOGO*/
    bloco             = al_load_bitmap("imagens/bloco_28.png");
    obstaculo         = al_load_bitmap("imagens/obstaculo_20.png");
    moeda             = al_load_bitmap("imagens/moeda_20.png");
    background_menu   = al_load_bitmap("imagens/bground.jpg");
=======
    float volume         = 0.5;
    float bloco_pos_x    = spawnpoint_x[0];
    float bloco_pos_y    = spawnpoint_y[0];
    float bloco_vx       = 0;
    float bloco_vy       = 0;
    bool playingsound    = true;
    bool origem_abaixo, origem_acima, ainda_abaixo, ainda_acima, apertou_em_cima, contra_bug, contra_bug_2, can_move, key_down_before;
    float alpha          = 0; /*DECLARAï¿½ï¿½O DO GRAU DE TRANSPARï¿½NCIA DO OBJETO */
    int deaths           = 0; /*DECLARAï¿½ï¿½O DA VARIAVEL QUE GUARDARï¿½ O VALOR DO Nï¿½MERO DE MORTES */
    int fase             = 1; /* DECLARAï¿½ï¿½O DA VARIAVEL QUE CONTROLARï¿½ AS FASES QUE APARECEM NA TELA */
    int qtd_moeda        = 0; /* DECLARAï¿½ï¿½O DA QUANTIDADE DE MOEDAS COLETADAS PELO JOGADOR */
    char cont_mortes[50];


    /* CARREGAMENTO DOS BITMAPS QUE Vï¿½O SER USADOS NO JOGO*/
    bloco             = al_load_bitmap("imagens/bloco_28.png");
    obstaculo         = al_load_bitmap("imagens/obstaculo_20.png");
    moeda             = al_load_bitmap("imagens/moeda_20.png");
    background_menu  = al_load_bitmap("imagens/bground.jpg");
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a
    background_1      = al_load_bitmap("imagens/background_1.png");
    background_2      = al_load_bitmap("imagens/background_2.png");
    background_3      = al_load_bitmap ("imagens/background_3.png");


        if(!background_menu)
    {
<<<<<<< HEAD

        fprintf(stderr, "falhou ao criar o bloco bitmap!\n");

        return -1;

    }

    if (!obstaculo)
    {

        fprintf(stderr, "falhou ao criar o obstaculo bitmap!\n");

        return -1;

    }

    if (!moeda)
    {

        fprintf(stderr, "falhou ao criar a moeda bitmap!\n");

=======
        fprintf(stderr, "falhou ao criar a backgrouund bitmap!\n");
        return -1;
    }
    if(!bloco)
    {
        fprintf(stderr, "falhou ao criar a bloco bitmap!\n");
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a
        return -1;
    }

    if(!background_1)
    {
<<<<<<< HEAD

        fprintf(stderr, "falhou ao criar o background_1 bitmap!\n");

=======
        fprintf(stderr, "falhou ao criar o background bitmap!\n");
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a
        return -1;
    }

<<<<<<< HEAD
    if(!background_1)

    {

        fprintf(stderr, "falhou ao criar o background_2 bitmap!\n");

        return -1;

    }

    if(!background_3)

    {

        fprintf(stderr, "falhou ao criar o background_3 bitmap!\n");

        return -1;

    }

    if(!background_menu)

    {

        fprintf(stderr, "falhou ao criar o background_menu bitmap!\n");

        return -1;

    }






=======
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a
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

<<<<<<< HEAD
    /* DECLARAÇÃO DAS POSICÕES DAS MOEDAS DAS FASES DO JOGO */
    int moeda_pos_x[4], moeda_pos_y[4];
=======
    /* DECLARAï¿½ï¿½O DAS POSICï¿½ES DAS MOEDAS DAS FASES DO JOGO */
    int moeda_pos_x[5], moeda_pos_y[5];
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a

    /*DECLARACAO DAS POSICOES DOS OBSTACULOS NAS FASES DO JOGO */
    int obs_pos_x [11], obs_pos_y [11];

<<<<<<< HEAD
    /* POSIÇÕES INICIAIS DOS OBSTACULOS NA FASE 1 */
=======
    /* POSIï¿½ï¿½ES INICIAIS DOS OBSTACULOS NA FASE 1 */
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a
    for (i = 0; i < 5; i++)
    {
        obs_pos_x[i]= 360 - 20/2;
        obs_pos_y[i] = 440 - 20/2;

        if (i >= 1)
        {
            obs_pos_y[i] = obs_pos_y [i-1] - 40;
        }
    }

<<<<<<< HEAD
    /* DECLARAÇÃO DAS VELOCIDADES DOS OBSTACULOS DE CADA FASE */
    int obs_vx_1, obs_vx_2[11], obs_vy_2[11], obs_vx_3[7], obs_vy_3[7];
=======
    /* DECLARAï¿½ï¿½O DAS VELOCIDADES DOS OBSTACULOS DE CADA FASE */
    int obs_vx_1, obs_vy_1, obs_vx_2[11], obs_vy_2[11];
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a

    /* VELOCIDADE DOS OBSTACULOS DA FASE 1 */
    obs_vx_1 = 6;

<<<<<<< HEAD
    /* Declaração do GameState */
    typedef enum
        {MENU, TRANSITION, GAME} GameState;

    GameState current_state = MENU;

=======
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a
    al_flip_display();
    al_start_timer(timer);

<<<<<<< HEAD
    /************************** LOOP DO MENU ***********************/
    while(current_state == MENU)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {

        }
        else if (ev.type == ALLEGRO_EVENT_TIMER)
        {
            redraw = true;
        }
        else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {

            int mx = ev.mouse.x;
            int my = ev.mouse.y;

                    //PLAYBUTTON
            int largura_play = al_get_text_width(font, "PLAY");
            int altura_play = al_get_font_line_height(font);
            float play_pos_x = (SCREEN_W - largura_play) / 2.0;
            float play_pos_Y = (SCREEN_H / 2) - 30;

                    //-VOLUME
            int largura_volmenos = al_get_text_width(font, "-");
            int altura_volmenos  = al_get_font_line_height(font);
            float menos_pos_x    = (SCREEN_W/2 - 160);
            float menos_pos_Y    = SCREEN_H / 2 + 90;

                    //+VOLUME
            int largura_volmais = al_get_text_width(font, "-");
            int altura_volmais  = al_get_font_line_height(font);
            float mais_pos_x    = (SCREEN_W/2 + 135);
            float mais_pos_Y    = SCREEN_H / 2 + 60;

            //CLICKS
                    //CLICK PLAY
            if ((mx >= play_pos_x) && (mx <= play_pos_x + largura_play) &&
            (my >= play_pos_Y) && (my <= play_pos_Y + altura_play))
            {
                playingsound = true;

                if (playingsound)
                {
                        al_stop_sample_instance(selectingmenu);
                        al_play_sample_instance(selectingmenu);
                }
                else if (!playingsound)
                {
                        al_play_sample_instance(selectingmenu);
                }

                current_state = GAME;

                break;

                al_destroy_bitmap(background_menu);
            }
                    //CLICK -VOLUME
            else if ((mx >= menos_pos_x) && (mx <= menos_pos_x + largura_volmenos) &&
            (my >= menos_pos_Y) && (my <= menos_pos_Y + altura_volmenos))
            {
                playingsound = true;

                if (volume >= 0)
                {

                    volume = volume - 0.1;
                    al_set_audio_stream_gain(musica, volume);
                    al_set_sample_instance_gain(selectingmenu, volume);



                    if (playingsound){
                        al_stop_sample_instance(selectingmenu);
                        al_play_sample_instance(selectingmenu);
                    }
                    else if (!playingsound){
                        al_play_sample_instance(selectingmenu);
                    }
                }
            }
                    //CLICK +VOLUME
            else if ((mx >= mais_pos_x) && (mx <= mais_pos_x + largura_volmais) &&
            (my >= mais_pos_Y) && (my <= mais_pos_Y + altura_volmais))
            {
                playingsound = true;

                if (volume <= 1)
                {

                    volume = volume + 0.1;
                    al_set_audio_stream_gain(musica, volume);
                    al_set_sample_instance_gain(selectingmenu, volume);


                    if (playingsound){
                        al_stop_sample_instance(selectingmenu);
                        al_play_sample_instance(selectingmenu);
                    }
                    else if (!playingsound){
                        al_play_sample_instance(selectingmenu);
                    }
                }
            }
            else
            {
                playingsound = false;
            }
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(ev.keyboard.keycode)
            {
                case ALLEGRO_KEY_ESCAPE:
                    return -1;
                    break;
            }
        }

        if (redraw && al_is_event_queue_empty(event_queue))
        {
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

                    //-VOLUME
            int largura_volmenos = al_get_text_width(font, "-");
            int altura_volmenos  = al_get_font_line_height(font);
            float menos_pos_x    = (SCREEN_W/2 - 160);
            float menos_pos_Y    = SCREEN_H / 2 + 90;

                    //+VOLUME
            int largura_volmais = al_get_text_width(font, "-");
            int altura_volmais  = al_get_font_line_height(font);
            float mais_pos_x    = (SCREEN_W/2 + 135);
            float mais_pos_Y    = SCREEN_H / 2 + 60;

                    //"VOLUME"
            al_draw_text(font3, al_map_rgb(139,0,0), SCREEN_W/2 + 4, SCREEN_H/2 + 104, ALLEGRO_ALIGN_CENTRE, "Volume");
            al_draw_text(font3, al_map_rgb(255,255,255), SCREEN_W/2, SCREEN_H/2 + 100, ALLEGRO_ALIGN_CENTRE, "Volume");

                    //TITULO
            al_draw_text(font3, al_map_rgb(255,0,0), SCREEN_W/2 + 5, SCREEN_H/2 -265, ALLEGRO_ALIGN_CENTRE, "Worlds Hardest");
            al_draw_text(font3, al_map_rgb(255,0,0), SCREEN_W/2 + 5, SCREEN_H/2 -155, ALLEGRO_ALIGN_CENTRE, "Game");
            al_draw_text(font3, al_map_rgb(255,255,255), SCREEN_W/2, SCREEN_H/2 -270, ALLEGRO_ALIGN_CENTRE, "Worlds Hardest");
            al_draw_text(font3, al_map_rgb(255,255,255), SCREEN_W/2, SCREEN_H/2 -160, ALLEGRO_ALIGN_CENTRE, "Game");

            char strVol[6];
            sprintf(strVol, "%.1f", volume);

                    //NUMEROS VOLUME
            if (volume > 0)
            {
                al_draw_text(font3, al_map_rgb(139,0,0), SCREEN_W/2 + 4, SCREEN_H/2 + 154, ALLEGRO_ALIGN_CENTRE, strVol);
                al_draw_text(font3, al_map_rgb(255,255,255), SCREEN_W/2, SCREEN_H/2 + 150, ALLEGRO_ALIGN_CENTRE, strVol);
            }
            else if(volume < 0)
            {
                al_draw_text(font3, al_map_rgb(139,0,0), SCREEN_W/2 + 4, SCREEN_H/2 + 154, ALLEGRO_ALIGN_CENTRE, "0.0");
                al_draw_text(font3, al_map_rgb(255,255,255), SCREEN_W/2, SCREEN_H/2 + 150, ALLEGRO_ALIGN_CENTRE, "0.0");
            }

            int mx = mouse_state.x;
            int my = mouse_state.y;



            // AUMENTAR BOTOES
                    //AUMENTAR PLAY
            if ((mx >= play_pos_x) && (mx <= play_pos_x + largura_play) &&
            (my >= play_pos_Y) && (my <= play_pos_Y + altura_play))
            {
                al_draw_text(font2, al_map_rgb(139,0,0), SCREEN_W/2 + 4,   SCREEN_H/2 - 6,  ALLEGRO_ALIGN_CENTRE, "PLAY");  //sombra
                al_draw_text(font3, al_map_rgb(139,0,0), SCREEN_W/2 - 147, SCREEN_H/2 + 103, ALLEGRO_ALIGN_CENTRE, "-");    //sombra
                al_draw_text(font3, al_map_rgb(139,0,0), SCREEN_W/2 + 153, SCREEN_H/2 + 103, ALLEGRO_ALIGN_CENTRE, "+");    //sombra
                al_draw_text(font2, al_map_rgb(255,255,255), SCREEN_W/2,       SCREEN_H/2 - 10,  ALLEGRO_ALIGN_CENTRE, "PLAY");
                al_draw_text(font3, al_map_rgb(255,255,255), SCREEN_W/2 - 150, SCREEN_H/2 + 100, ALLEGRO_ALIGN_CENTRE, "-");
                al_draw_text(font3, al_map_rgb(255,255,255), SCREEN_W/2 + 150, SCREEN_H/2 + 100, ALLEGRO_ALIGN_CENTRE, "+");
            }
                    //AUMENTAR -VOLUME
            else if ((mx >= menos_pos_x) && (mx <= menos_pos_x + largura_volmenos) &&
            (my >= menos_pos_Y) && (my <= menos_pos_Y + altura_volmenos))
            {
                al_draw_text(font,  al_map_rgb(139,0,0), SCREEN_W/2 + 4,   SCREEN_H/2 + 4,  ALLEGRO_ALIGN_CENTRE, "PLAY");  //sombra
                al_draw_text(font2, al_map_rgb(139,0,0), SCREEN_W/2 - 146, SCREEN_H/2 + 79,  ALLEGRO_ALIGN_CENTRE, "-");    //sombra
                al_draw_text(font3, al_map_rgb(139,0,0), SCREEN_W/2 + 153, SCREEN_H/2 + 103, ALLEGRO_ALIGN_CENTRE, "+");    //sombra
                al_draw_text(font,  al_map_rgb(255,255,255), SCREEN_W/2,       SCREEN_H/2,  ALLEGRO_ALIGN_CENTRE, "PLAY");
                al_draw_text(font2, al_map_rgb(255,255,255), SCREEN_W/2 - 150, SCREEN_H/2 + 75,  ALLEGRO_ALIGN_CENTRE, "-");
                al_draw_text(font3, al_map_rgb(255,255,255), SCREEN_W/2 + 150, SCREEN_H/2 + 100, ALLEGRO_ALIGN_CENTRE, "+");
            }
                    //AUMENTAR +VOLUME
            else if ((mx >= mais_pos_x) && (mx <= mais_pos_x + largura_volmais) &&
            (my >= mais_pos_Y) && (my <= mais_pos_Y + altura_volmais))
            {
                al_draw_text(font, al_map_rgb(139,0,0),  SCREEN_W/2 + 4,   SCREEN_H/2 + 4,  ALLEGRO_ALIGN_CENTRE, "PLAY");  //sombra
                al_draw_text(font3, al_map_rgb(139,0,0), SCREEN_W/2 - 147, SCREEN_H/2 + 103, ALLEGRO_ALIGN_CENTRE, "-");    //sombra
                al_draw_text(font2, al_map_rgb(139,0,0), SCREEN_W/2 + 154, SCREEN_H/2 + 79,  ALLEGRO_ALIGN_CENTRE, "+");    //sombra
                al_draw_text(font, al_map_rgb(255,255,255),  SCREEN_W/2,       SCREEN_H/2,  ALLEGRO_ALIGN_CENTRE, "PLAY");
                al_draw_text(font3, al_map_rgb(255,255,255), SCREEN_W/2 - 150, SCREEN_H/2 + 100, ALLEGRO_ALIGN_CENTRE, "-");
                al_draw_text(font2, al_map_rgb(255,255,255), SCREEN_W/2 + 150, SCREEN_H/2 + 75,  ALLEGRO_ALIGN_CENTRE, "+");
            }
                    //RESTO
            else
            {
                al_draw_text(font, al_map_rgb(139,0,0),  SCREEN_W/2 + 4,   SCREEN_H/2 + 4,  ALLEGRO_ALIGN_CENTRE, "PLAY");  //sombra
                al_draw_text(font3, al_map_rgb(139,0,0), SCREEN_W/2 - 147, SCREEN_H/2 + 103, ALLEGRO_ALIGN_CENTRE, "-");    //sombra
                al_draw_text(font3, al_map_rgb(139,0,0), SCREEN_W/2 + 153, SCREEN_H/2 + 103, ALLEGRO_ALIGN_CENTRE, "+");    //sombra
                al_draw_text(font, al_map_rgb(255,255,255),  SCREEN_W/2,       SCREEN_H/2,  ALLEGRO_ALIGN_CENTRE, "PLAY");
                al_draw_text(font3, al_map_rgb(255,255,255), SCREEN_W/2 - 150, SCREEN_H/2 + 100, ALLEGRO_ALIGN_CENTRE, "-");
                al_draw_text(font3, al_map_rgb(255,255,255), SCREEN_W/2 + 150, SCREEN_H/2 + 100, ALLEGRO_ALIGN_CENTRE, "+");
            }

            al_flip_display();
        }
    }
    /*************************** LOOP DO JOGO ************************/
    while(current_state == GAME)
    {
        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
        al_set_audio_stream_playmode(musica, ALLEGRO_PLAYMODE_LOOP);
=======
    typedef enum
        {MENU, TRANSITION, GAME} GameState;

    GameState current_state = MENU;

    //MENU
    while(current_state == MENU){
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a

        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        }
        else if (ev.type == ALLEGRO_EVENT_TIMER) {
            redraw = true;
        }
        else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {

            int mx = ev.mouse.x;
            int my = ev.mouse.y;

                    //PLAYBUTTON
            int largura_play = al_get_text_width(font, "PLAY");
            int altura_play = al_get_font_line_height(font);
            float play_pos_x = (SCREEN_W - largura_play) / 2.0;
            float play_pos_Y = (SCREEN_H / 2) - 30;

                    //-VOLUME
            int largura_volmenos = al_get_text_width(font, "-");
            int altura_volmenos  = al_get_font_line_height(font);
            float menos_pos_x    = (SCREEN_W/2 - 160);
            float menos_pos_Y    = SCREEN_H / 2 + 90;

                    //+VOLUME
            int largura_volmais = al_get_text_width(font, "-");
            int altura_volmais  = al_get_font_line_height(font);
            float mais_pos_x    = (SCREEN_W/2 + 135);
            float mais_pos_Y    = SCREEN_H / 2 + 60;

            //CLICKS
                    //CLICK PLAY
            if (
                mx >= (play_pos_x) && mx <= (play_pos_x + largura_play) &&
                my >= (play_pos_Y) && my <= (play_pos_Y + altura_play)) {
                if (playingsound){
                        al_stop_sample_instance(selectingmenu);
                        al_play_sample_instance(selectingmenu);
                }
                else if (!playingsound){
                        al_play_sample_instance(selectingmenu);
                }

                current_state = GAME;

                break;

                al_destroy_bitmap(background_menu);
            }
                    //CLICK -VOLUME
            if (
                mx >= (menos_pos_x) && mx <= (menos_pos_x + largura_volmenos) &&
                my >= (menos_pos_Y) && my <= (menos_pos_Y + altura_volmenos)) {

                if (volume >= 0)
                {

                    volume = volume - 0.1;
                    al_set_audio_stream_gain(musica, volume);
                    al_set_sample_instance_gain(selectingmenu, volume);
                    if (playingsound){
                        al_stop_sample_instance(selectingmenu);
                        al_play_sample_instance(selectingmenu);
                    }
                    else if (!playingsound){
                        al_play_sample_instance(selectingmenu);
                    }
                }
            }
                    //CLICK +VOLUME
            if (
                mx >= (mais_pos_x) && mx <= (mais_pos_x + largura_volmais) &&
                my >= (mais_pos_Y) && my <= (mais_pos_Y + altura_volmais)) {

                if (volume <= 1)
                {

                    volume = volume + 0.1;
                    al_set_audio_stream_gain(musica, volume);
                    al_set_sample_instance_gain(selectingmenu, volume);
                    if (playingsound){
                        al_stop_sample_instance(selectingmenu);
                        al_play_sample_instance(selectingmenu);
                    }
                    else if (!playingsound){
                        al_play_sample_instance(selectingmenu);
                    }
                }
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

                    //-VOLUME
            int largura_volmenos = al_get_text_width(font, "-");
            int altura_volmenos  = al_get_font_line_height(font);
            float menos_pos_x    = (SCREEN_W/2 - 160);
            float menos_pos_Y    = SCREEN_H / 2 + 90;

                    //+VOLUME
            int largura_volmais = al_get_text_width(font, "-");
            int altura_volmais  = al_get_font_line_height(font);
            float mais_pos_x    = (SCREEN_W/2 + 135);
            float mais_pos_Y    = SCREEN_H / 2 + 60;

                    //"VOLUME"
            al_draw_text(font3, al_map_rgb(139,0,0), SCREEN_W/2 + 4, SCREEN_H/2 + 104, ALLEGRO_ALIGN_CENTRE, "Volume");
            al_draw_text(font3, al_map_rgb(255,255,255), SCREEN_W/2, SCREEN_H/2 + 100, ALLEGRO_ALIGN_CENTRE, "Volume");

                    //TITULO
            al_draw_text(font4, al_map_rgb(255,0,0), SCREEN_W/2 + 5, SCREEN_H/2 -265, ALLEGRO_ALIGN_CENTRE, "Worlds Hardest");
            al_draw_text(font4, al_map_rgb(255,0,0), SCREEN_W/2 + 5, SCREEN_H/2 -155, ALLEGRO_ALIGN_CENTRE, "Game");
            al_draw_text(font4, al_map_rgb(255,255,255), SCREEN_W/2, SCREEN_H/2 -270, ALLEGRO_ALIGN_CENTRE, "Worlds Hardest");
            al_draw_text(font4, al_map_rgb(255,255,255), SCREEN_W/2, SCREEN_H/2 -160, ALLEGRO_ALIGN_CENTRE, "Game");

            char strVol[6];
            sprintf(strVol, "%.1f", volume);

                    //NUMEROS VOLUME
            if (volume > 0){
                al_draw_text(font3, al_map_rgb(139,0,0), SCREEN_W/2 + 4, SCREEN_H/2 + 154, ALLEGRO_ALIGN_CENTRE, strVol);
                al_draw_text(font3, al_map_rgb(255,255,255), SCREEN_W/2, SCREEN_H/2 + 150, ALLEGRO_ALIGN_CENTRE, strVol);
            }
            else if(volume < 0){
                al_draw_text(font3, al_map_rgb(139,0,0), SCREEN_W/2 + 4, SCREEN_H/2 + 154, ALLEGRO_ALIGN_CENTRE, "0.0");
                al_draw_text(font3, al_map_rgb(255,255,255), SCREEN_W/2, SCREEN_H/2 + 150, ALLEGRO_ALIGN_CENTRE, "0.0");
            }

            int mx = mouse_state.x;
            int my = mouse_state.y;


<<<<<<< HEAD
=======

            // AUMENTAR BOTOES
                    //AUMENTAR PLAY
            if (
                mx >= (play_pos_x) && mx <= (play_pos_x + largura_play) &&
                my >= (play_pos_Y) && my <= (play_pos_Y + altura_play)) {
                al_draw_text(font2, al_map_rgb(139,0,0), SCREEN_W/2 + 4,   SCREEN_H/2 - 6,  ALLEGRO_ALIGN_CENTRE, "PLAY");  //sombra
                al_draw_text(font3, al_map_rgb(139,0,0), SCREEN_W/2 - 147, SCREEN_H/2 + 103, ALLEGRO_ALIGN_CENTRE, "-");    //sombra
                al_draw_text(font3, al_map_rgb(139,0,0), SCREEN_W/2 + 153, SCREEN_H/2 + 103, ALLEGRO_ALIGN_CENTRE, "+");    //sombra
                al_draw_text(font2, al_map_rgb(255,255,255), SCREEN_W/2,       SCREEN_H/2 - 10,  ALLEGRO_ALIGN_CENTRE, "PLAY");
                al_draw_text(font3, al_map_rgb(255,255,255), SCREEN_W/2 - 150, SCREEN_H/2 + 100, ALLEGRO_ALIGN_CENTRE, "-");
                al_draw_text(font3, al_map_rgb(255,255,255), SCREEN_W/2 + 150, SCREEN_H/2 + 100, ALLEGRO_ALIGN_CENTRE, "+");
                }
                    //AUMENTAR -VOLUME
            else if (
                mx >= (menos_pos_x) && mx <= (menos_pos_x + largura_volmenos) &&
                my >= (menos_pos_Y) && my <= (menos_pos_Y + altura_volmenos)) {
                al_draw_text(font,  al_map_rgb(139,0,0), SCREEN_W/2 + 4,   SCREEN_H/2 + 4,  ALLEGRO_ALIGN_CENTRE, "PLAY");  //sombra
                al_draw_text(font2, al_map_rgb(139,0,0), SCREEN_W/2 - 146, SCREEN_H/2 + 79,  ALLEGRO_ALIGN_CENTRE, "-");    //sombra
                al_draw_text(font3, al_map_rgb(139,0,0), SCREEN_W/2 + 153, SCREEN_H/2 + 103, ALLEGRO_ALIGN_CENTRE, "+");    //sombra
                al_draw_text(font,  al_map_rgb(255,255,255), SCREEN_W/2,       SCREEN_H/2,  ALLEGRO_ALIGN_CENTRE, "PLAY");
                al_draw_text(font2, al_map_rgb(255,255,255), SCREEN_W/2 - 150, SCREEN_H/2 + 75,  ALLEGRO_ALIGN_CENTRE, "-");
                al_draw_text(font3, al_map_rgb(255,255,255), SCREEN_W/2 + 150, SCREEN_H/2 + 100, ALLEGRO_ALIGN_CENTRE, "+");
            }
                    //AUMENTAR +VOLUME
            else if (
                mx >= (mais_pos_x) && mx <= (mais_pos_x + largura_volmais) &&
                my >= (mais_pos_Y) && my <= (mais_pos_Y + altura_volmais)) {
                al_draw_text(font, al_map_rgb(139,0,0),  SCREEN_W/2 + 4,   SCREEN_H/2 + 4,  ALLEGRO_ALIGN_CENTRE, "PLAY");  //sombra
                al_draw_text(font3, al_map_rgb(139,0,0), SCREEN_W/2 - 147, SCREEN_H/2 + 103, ALLEGRO_ALIGN_CENTRE, "-");    //sombra
                al_draw_text(font2, al_map_rgb(139,0,0), SCREEN_W/2 + 154, SCREEN_H/2 + 79,  ALLEGRO_ALIGN_CENTRE, "+");    //sombra
                al_draw_text(font, al_map_rgb(255,255,255),  SCREEN_W/2,       SCREEN_H/2,  ALLEGRO_ALIGN_CENTRE, "PLAY");
                al_draw_text(font3, al_map_rgb(255,255,255), SCREEN_W/2 - 150, SCREEN_H/2 + 100, ALLEGRO_ALIGN_CENTRE, "-");
                al_draw_text(font2, al_map_rgb(255,255,255), SCREEN_W/2 + 150, SCREEN_H/2 + 75,  ALLEGRO_ALIGN_CENTRE, "+");
            }
                    //RESTO
            else {
                al_draw_text(font, al_map_rgb(139,0,0),  SCREEN_W/2 + 4,   SCREEN_H/2 + 4,  ALLEGRO_ALIGN_CENTRE, "PLAY");  //sombra
                al_draw_text(font3, al_map_rgb(139,0,0), SCREEN_W/2 - 147, SCREEN_H/2 + 103, ALLEGRO_ALIGN_CENTRE, "-");    //sombra
                al_draw_text(font3, al_map_rgb(139,0,0), SCREEN_W/2 + 153, SCREEN_H/2 + 103, ALLEGRO_ALIGN_CENTRE, "+");    //sombra
                al_draw_text(font, al_map_rgb(255,255,255),  SCREEN_W/2,       SCREEN_H/2,  ALLEGRO_ALIGN_CENTRE, "PLAY");
                al_draw_text(font3, al_map_rgb(255,255,255), SCREEN_W/2 - 150, SCREEN_H/2 + 100, ALLEGRO_ALIGN_CENTRE, "-");
                al_draw_text(font3, al_map_rgb(255,255,255), SCREEN_W/2 + 150, SCREEN_H/2 + 100, ALLEGRO_ALIGN_CENTRE, "+");
            }

            al_flip_display();
        }
    }

    //TRANSICAO
    while(current_state == TRANSITION){
        printf("Transicao");
    }

    //GAME
    while(current_state == GAME){

        al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
        al_set_audio_stream_playmode(musica, ALLEGRO_PLAYMODE_LOOP);

        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a
        if(ev.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
        }
        else if(ev.type == ALLEGRO_EVENT_TIMER)
        {
            /* MOVIMENTAÇÃO DO BLOCO */
            bloco_pos_x += bloco_vx;
            bloco_pos_y += bloco_vy;

            /* AJUSTES DAS VARIÁVEIS alpha e can_move */
            if(alpha > 1.0)
            {
                alpha = 1.0;
            }
                //SE alpha != 1, O JOGADOR NÃO PODE MOVIMENTAR O BLOCO//
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


<<<<<<< HEAD
                /* CHEGAGEM DAS COLISÕES COM OS OBSTACULOS DA FASE 1*/
=======
                /* CHEGAGEM DAS COLISï¿½ES COM OS OBSTACULOS DA FASE 1*/
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a
                for (i = 0; i < 5; i++)
                {
                    if ((bloco_pos_x >= obs_pos_x[i]+4-28)&(bloco_pos_x <= obs_pos_x[i] + 16)&
                    (bloco_pos_y >= obs_pos_y[i]+4-28)&(bloco_pos_y <= obs_pos_y[i] + 16))
                    {
                        /*BARULHO DO STEVE */
                        al_play_sample(colisao, volume + 0.3, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);

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
<<<<<<< HEAD
                    //Tela de termino da fase 1
                    //Limpa a tela
                    al_clear_to_color(al_map_rgb(174, 183 , 254));

                    // Escreve a mensagem no meio da tela
                    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_W/2, SCREEN_H/2 - 70, ALLEGRO_ALIGN_CENTRE, "It was just");
                    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_W/2, SCREEN_H/2 + 20, ALLEGRO_ALIGN_CENTRE, "for warm up");
                    al_flip_display();

                    // Espera 2 segundos
                    al_rest(2.0);

                    fase = 2;
=======
                    //Tela de termino da 1ï¿½fase
                    //Limpa a tela
                    al_clear_to_color(al_map_rgb(174, 183 , 254));
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a

                    // Escreve a mensagem no meio da tela
                    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_W/2, SCREEN_H/2 - 70, ALLEGRO_ALIGN_CENTRE, "Era apenas");
                    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_W/2, SCREEN_H/2 + 20, ALLEGRO_ALIGN_CENTRE, "pra aquecer");
                    al_flip_display();
                    // Espera 2 segundos
                    al_rest(2.0);
                    fase = 2;
                    bloco_pos_x = spawnpoint_x[1];
                    bloco_pos_y = spawnpoint_y[1];
                    bloco_vx = 0;
                    bloco_vy = 0;
                    alpha = 0;

<<<<<<< HEAD
                    /* DEFINIÇÃO DAS POSIÇÕES DE ONDE COMEÇARÃO OS OBSTACULOS DA FASE 2 */
=======
                    /* DEFINIï¿½ï¿½O DAS POSIï¿½ï¿½ES DE ONDE COMEï¿½ARï¿½O OS OBSTACULOS DA FASE 2 */
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a
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

<<<<<<< HEAD
                    /* DEFINIÇÃO DA VELOCIDADE INICIAL DOS OBSTACULOS DA FASE 2 */
=======
                    /* DEFINIï¿½ï¿½O DA VELOCIDADE INICIAL DOS OBSTACULOS DA FASE 2 */
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a
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

                /* DEFINIÇÃO DE COMO A POSIÇÃO DOS OBSTACULOS VARIAM NA FASE 2*/
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
<<<<<<< HEAD
=======
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

                    /* CHECAGEM DOS MOMENTOS NOS QUAIS O SENTIDO DAS VELOCIDADES DOS OBSTACULOS DA FASE 2 MUDARï¿½O */
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

                    /* CHEGAGEM DAS COLISï¿½ES COM OS OBSTACULOS DA FASE 2*/
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
                        //Tela de termino da 2ï¿½fase
                    //Limpa a tela
                    al_clear_to_color(al_map_rgb(174, 183 , 254));

                    // Escreve a mensagem no meio da tela
                    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_W/2, SCREEN_H/2 - 70, ALLEGRO_ALIGN_CENTRE, "Nem perde");
                    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_W/2, SCREEN_H/2 + 20, ALLEGRO_ALIGN_CENTRE, "o tempo tentando");
                    al_flip_display();
                    // Espera 2 segundos
                    al_rest(2.0);
                        fase = 3;
                        bloco_pos_x = spawnpoint_x[2];
                        bloco_pos_y = spawnpoint_y[2];
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a
                        bloco_vx = 0;
                        bloco_vy = 0;
                        alpha = 0;

                        bloco_pos_x = spawnpoint_x[1];
                        bloco_pos_y = spawnpoint_y[1];

                        deaths = deaths + 1;

                        /* BARULHO DO STEVE */
                        al_play_sample(colisao, volume + 0.3, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
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

                        /* BARULHO DO STEVE */
                        al_play_sample(colisao, volume + 0.3, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                    }
                }

                /* CHECAGEM PARA VER SE O JOGADOR COLETOU A MOEDA DA FASE 2 */
                if ((bloco_pos_x >= moeda_pos_x[0]+4-28)&(bloco_pos_x <= moeda_pos_x[0] + 16)&
                (bloco_pos_y >= moeda_pos_y[0]+4-28)&(bloco_pos_y <= moeda_pos_y[0] + 16))
                {
                    qtd_moeda = 1;
                }

                /* CHECAGEM PARA VER SE O JOGADOR TERMINOU A FASE 2 */
                if ((bloco_pos_x >= 320 - 28)&(bloco_pos_x <= 400)&(bloco_pos_y >= 340 - 28)&
                (bloco_pos_y <= 420)&(qtd_moeda == 1))
                {
                    //Tela de termino da 2�fase
                    //Limpa a tela
                    al_clear_to_color(al_map_rgb(174, 183 , 254));

                    // Escreve a mensagem no meio da tela
                    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_W/2, SCREEN_H/2 - 70, ALLEGRO_ALIGN_CENTRE, "Don't even");
                    al_draw_text(font, al_map_rgb(0, 0, 0), SCREEN_W/2, SCREEN_H/2 + 20, ALLEGRO_ALIGN_CENTRE, "waste your time");
                    al_flip_display();

                    // Espera 2 segundos
                    al_rest(2.0);

                    fase = 3;

                    bloco_pos_x = spawnpoint_x[2];
                    bloco_pos_y = spawnpoint_y[2];

                    bloco_vx = 0;
                    bloco_vy = 0;

                    alpha = 0;


                    /* DEFINIÇÃO DA POSIÇÃO INICIAL DOS OBSTACULOS DA FASE 3 */
                    obs_pos_x[0] = 140 - 20/2;
                    obs_pos_y[0] = 180 - 20/2;

                    for (i = 1; i<7; i++)
                    {
                        if (i!= 3)
                        {
                            if ((i==1)||(i==2))
                            {
                                obs_pos_x[i] = obs_pos_x[i-1];
                                obs_pos_y[i] = obs_pos_y[i-1] + 120;
                            }
                            else if ((i>=4)&(i<=6))
                            {
                                obs_pos_x[i] = obs_pos_x[0]+360;
                                obs_pos_y[i] = obs_pos_y[i-4];
                            }
                        }
                        else
                        {
                            obs_pos_x[i] = 260 - 20/2;
                            obs_pos_y[i] = 220 - 20/2;
                        }

                    }

                    /* DEFINIÇÃO DA VELOCIDADE INICIAL DOS OBSTACULOS DA FASE 3 */

                    obs_vx_3[0] = 3;
                    obs_vy_3[0] = 0;

                    obs_vx_3[3] = 3;
                    obs_vy_3[3] = 0;

                    /* DEFINIÇÃO DA POSIÇÃO DAS MOEDAS DA FASE 3 */
                    moeda_pos_x[0] = 140 - 20/2;
                    moeda_pos_y[0] = 180 - 20/2;

                    moeda_pos_x[1] = moeda_pos_x[0];
                    moeda_pos_y[1] = 540 - 20/2;

                    moeda_pos_x[2] = 500 - 20/2;
                    moeda_pos_y[2] = moeda_pos_y[0];

                    moeda_pos_x[3] = moeda_pos_x[2];
                    moeda_pos_y[3] = moeda_pos_y[1];


                    /* NENHUMA MOEDA DA FASE 3 FOI COLETADA AINDA */

                    for (i=0; i<4; i++)
                    {
                            moeda_fora[i] = false;
                    }

                }
            }
            else if(fase == 3)
            {

                /* LIMITES DAS PAREDES MAIS EXTERNAS DA FASE 3 */
                /// PAREDES VERTICAIS
                if (bloco_pos_x<=120)
                {
                    bloco_pos_x = 120;
                }



                /// PAREDES HORIZONTAIS
                if (bloco_pos_y<=160)
                {
                    bloco_pos_y = 160;
                }
                else if(bloco_pos_y>=560-28)
                {
                    bloco_pos_y = 560-28;
                }

                /* LIMITES DAS OUTRAS PAREDES DA FASE 3, COM O MAPA DIVIDIDO EM REGIOES */
                ///região do spawnpoint
                if ((bloco_pos_x > 160-28)&(bloco_pos_x<=200-28+5)&(bloco_pos_y>200-28)&(bloco_pos_y<=240-28+5))
                {
                    if (bloco_pos_x >= 200-28)
                    {
                        bloco_pos_x = 200-28;
                    }

                    if (bloco_pos_y >= 240 - 28)
                    {
                        bloco_pos_y  = 240-28;
                    }
                }
                ///região entre_paredes_horizontais 1
                else if ((bloco_pos_x>200-28)&(bloco_pos_x<240)&(bloco_pos_y>=160)&(bloco_pos_y<=200-28+5))
                {
                    if (bloco_pos_y >= 200 - 28)
                    {
                        bloco_pos_y = 200 - 28;
                    }
                }
                ///região entre_paredes_horizontais 2
                else if ((bloco_pos_x > 160-28)&(bloco_pos_x <240)&(bloco_pos_y>=280-5)&(bloco_pos_y<=320-28+5))
                {
                    if (bloco_pos_y <= 280)
                    {
                        bloco_pos_y = 280;
                    }
                    else if (bloco_pos_y >= 320 - 28)
                    {
                        bloco_pos_y = 320 - 28;
                    }
                }
                /// região entre_parede_horizontais 3
                else if ((bloco_pos_x > 160-28)&(bloco_pos_x <240)&(bloco_pos_y>=400-5)&(bloco_pos_y<=440-28+5))
                {
                    if (bloco_pos_y <= 400)
                    {
                        bloco_pos_y = 400;
                    }
                    else if (bloco_pos_y >= 440 - 28)
                    {
                        bloco_pos_y = 440 - 28;
                    }
                }
                /// região entre_paredes_horizontais 4
                else if ((bloco_pos_x > 160-28)&(bloco_pos_x <240)&(bloco_pos_y>=520-5)&(bloco_pos_y<=560-28+5))
                {
                    if (bloco_pos_y <= 520)
                    {
                        bloco_pos_y = 520;
                    }
                    else if (bloco_pos_y >= 560 - 28)
                    {
                        bloco_pos_y = 560 - 28;
                    }
                }
                /// região entre_parede_horizontais 5
                else if ((bloco_pos_x > 280 - 28)&(bloco_pos_x<360)&(bloco_pos_y>=200-5)&(bloco_pos_y<=240-28+5))
                {
                    if (bloco_pos_y <= 200)
                    {
                        bloco_pos_y = 200;
                    }
                    else if (bloco_pos_y >= 240 - 28)
                    {
                        bloco_pos_y = 240 - 28;
                    }
                }
                ///região entre_parede_horizontais 6
                else if ((bloco_pos_x > 280 - 28)&(bloco_pos_x<360)&(bloco_pos_y>=480-5)&(bloco_pos_y<=520-28+5))
                {
                    if (bloco_pos_y <= 480)
                    {
                        bloco_pos_y = 480;
                    }
                    else if (bloco_pos_y >= 520 - 28)
                    {
                        bloco_pos_y = 520 - 28;
                    }
                }
                ///região entre_paredes_horizontais 7
                else if ((bloco_pos_x>400-28)&(bloco_pos_x<480)&(bloco_pos_y>=160)&(bloco_pos_y<=200-28+5))
                {
                    if (bloco_pos_y >= 200 - 28)
                    {
                        bloco_pos_y = 200 - 28;
                    }
                }
                ///região entre_paredes_horizontais 8
                else if ((bloco_pos_x > 400-28)&(bloco_pos_x <480)&(bloco_pos_y>=280-5)&(bloco_pos_y<=320-28+5))
                {
                    if (bloco_pos_y <= 280)
                    {
                        bloco_pos_y = 280;
                    }
                    else if (bloco_pos_y >= 320 - 28)
                    {
                        bloco_pos_y = 320 - 28;
                    }
                }
                ///região entre_paredes_horizontais 9
                else if ((bloco_pos_x > 400-28)&(bloco_pos_x <480)&(bloco_pos_y>=400-5)&(bloco_pos_y<=440-28+5))
                {
                    if (bloco_pos_y <= 400)
                    {
                        bloco_pos_y = 400;
                    }
                    else if (bloco_pos_y >= 440 - 28)
                    {
                        bloco_pos_y = 440 - 28;
                    }
                }
                ///região entre_paredes_horizontais 10
                else if ((bloco_pos_x > 400-28)&(bloco_pos_x <480)&(bloco_pos_y>=520-5)&(bloco_pos_y<=560-28+5))
                {
                    if (bloco_pos_y <= 520)
                    {
                        bloco_pos_y = 520;
                    }
                    else if (bloco_pos_y >= 560 - 28)
                    {
                        bloco_pos_y = 560 - 28;
                    }
                }
                /// região entre_paredes_verticais 1
                else if ((bloco_pos_x>= 120)&(bloco_pos_x<=160-28+5)&(bloco_pos_y>440-28)&(bloco_pos_y<520))
                {
                    if (bloco_pos_x >= 160 - 28)
                    {
                        bloco_pos_x = 160 - 28;
                    }
                }
                ///região entre_paredes_verticais 2
                else if ((bloco_pos_x>= 240 - 5)&(bloco_pos_x<=280-28)&(bloco_pos_y>440-28)&(bloco_pos_y<520))
                {
                    if (bloco_pos_x <= 240)
                    {
                        bloco_pos_x = 240;
                    }
                }
                ///região entre_paredes_verticais 3
                else if ((bloco_pos_x>= 360)&(bloco_pos_x<=400-28+5)&(bloco_pos_y>440-28)&(bloco_pos_y<520))
                {
                    if (bloco_pos_x >= 400-28)
                    {
                        bloco_pos_x = 400-28;
                    }
                }
                ///região entre_paredes_verticais 4
                else if ((bloco_pos_x>= 480-5)&(bloco_pos_x<=520-28)&(bloco_pos_y>440-28)&(bloco_pos_y<520))
                {
                    if (bloco_pos_x <= 480)
                    {
                        bloco_pos_x = 480;
                    }
                }
                ///região entre_paredes_verticais 5
                else if ((bloco_pos_x>= 120)&(bloco_pos_x<=160-28+5)&(bloco_pos_y>320-28)&(bloco_pos_y<400))
                {
                    if (bloco_pos_x >= 160 - 28)
                    {
                        bloco_pos_x = 160 - 28;
                    }
                }
                ///região entre_paredes_verticais 6
                else if ((bloco_pos_x>= 240 - 5)&(bloco_pos_x<=280-28)&(bloco_pos_y>320-28)&(bloco_pos_y<400))
                {
                    if (bloco_pos_x <= 240)
                    {
                        bloco_pos_x = 240;
                    }
                }
                ///região entre_paredes_verticais 7
                else if ((bloco_pos_x>= 360)&(bloco_pos_x<=400-28+5)&(bloco_pos_y>320-28)&(bloco_pos_y<400))
                {
                    if (bloco_pos_x >= 400-28)
                    {
                        bloco_pos_x = 400-28;
                    }
                }
                ///região entre_paredes_verticais 8
                else if ((bloco_pos_x>= 480-5)&(bloco_pos_x<=520-28)&(bloco_pos_y>320-28)&(bloco_pos_y<400))
                {
                    if (bloco_pos_x <= 480)
                    {
                        bloco_pos_x = 480;
                    }
                }
                ///região entre_paredes_verticais 9
                else if ((bloco_pos_x>= 120)&(bloco_pos_x<=160-28+5)&(bloco_pos_y>240-28)&(bloco_pos_y<280))
                {
                    if (bloco_pos_x >= 160 - 28)
                    {
                        bloco_pos_x = 160 - 28;
                    }
                }
                ///região entre_paredes_verticais 10
                else if ((bloco_pos_x>= 240 - 5)&(bloco_pos_x<=280-28)&(bloco_pos_y>200-28)&(bloco_pos_y<280))
                {
                    if (bloco_pos_x <= 240)
                    {
                        bloco_pos_x = 240;
                    }
                }
                ///região entre_paredes_verticais 11
                else if ((bloco_pos_x>= 360)&(bloco_pos_x<=400-28+5)&(bloco_pos_y>200-28)&(bloco_pos_y<280))
                {
                    if (bloco_pos_x >= 400-28)
                    {
                        bloco_pos_x = 400-28;
                    }
                }
                ///região entre_paredes_verticais 12
                else if ((bloco_pos_x >= 480-5)&(bloco_pos_x<=520-28)&(bloco_pos_y>200-28)&(bloco_pos_y<280))
                {
                    if (bloco_pos_x <= 480)
                    {
                        bloco_pos_x = 480;
                    }
                }
                ///região canto_1
                else if ((bloco_pos_x >= 240)&(bloco_pos_x <= 280-28+5)&(bloco_pos_y >= 160)& (bloco_pos_y< 200))
                {
                    if (bloco_pos_x >= 280-28)
                    {
                        bloco_pos_x = 280-28;
                    }
                }
                ///região canto_2
                else if ((bloco_pos_x >= 240)&(bloco_pos_x <= 280-28+5)&(bloco_pos_y > 520-28)& (bloco_pos_y<= 560))
                {
                    if (bloco_pos_x >= 280-28)
                    {
                        bloco_pos_x = 280-28;
                    }
                }
                ///região canto_3
                else if ((bloco_pos_x >= 360-5)&(bloco_pos_x <= 400)&(bloco_pos_y >= 160)& (bloco_pos_y< 200))
                {
                    if (bloco_pos_x <= 360)
                    {
                        bloco_pos_x = 360;
                    }
                }
                ///região canto_4
                else if ((bloco_pos_x >= 360-5)&(bloco_pos_x <= 400)&(bloco_pos_y > 520-28)& (bloco_pos_y<= 560))
                {
                    if (bloco_pos_x <= 360)
                    {
                        bloco_pos_x = 360;
                    }
                }
                ///região parede_vertical_central 1
                else if ((bloco_pos_x >=240)&&(bloco_pos_x<=280-28+5)&&(bloco_pos_y>240-28)&&(bloco_pos_y<480))
                {
                    if ((bloco_pos_x >= 280 - 28)&&(bloco_pos_x<=360-28)&&(bloco_pos_y>240-28)&&(bloco_pos_y<480)&&
                    (bloco_vx > 0))
                    {
                        bloco_pos_x = 280 - 28;
                    }
                }
                ///região parede_vertical_central 2
                else if((bloco_pos_x >= 360 - 5)&&(bloco_pos_x<=400-28)&&(bloco_pos_y>240-28)&&(bloco_pos_y<480))
                {
                    if ((bloco_pos_x <= 360)&&(bloco_pos_x>=280)&&(bloco_pos_y>240-28)&&(bloco_pos_y<480)&&
                    (bloco_vx < 0))
                    {
                        bloco_pos_x = 360;
                    }
                }
                ///região destino_final
                else if ((bloco_pos_x > 520 - 28)&&(bloco_pos_x<=600-28+5)&&(bloco_pos_y>=320-5)&&(bloco_pos_y<=400-28+5))
                {
                    if(bloco_pos_y<= 320)
                    {
                        bloco_pos_y = 320;
                    }
                    else if (bloco_pos_y >= 400-28)
                    {
                        bloco_pos_y = 400-28;
                    }

                    if (bloco_pos_x >= 600-28)
                    {
                        bloco_pos_x = 600-28;
                    }
                }
                ///região paredes_verticais_fim
                else if ((bloco_pos_x>=480)&&(bloco_pos_x<=520-28+5)&&( ((bloco_pos_y>=160)&&(bloco_pos_y < 320))||
                ((bloco_pos_y>400-28)&&(bloco_pos_y<=560-28)) ))
                {
                    if (bloco_pos_x>=520-28)
                    {
                        bloco_pos_x = 520 - 28;
                    }
                }


                /* MOVIMENTAÇÃO DOS OBSTACULOS */
                for (i=0; i<7; i++)
                {
                    if ((i>=0)&&(i<=2))
                    {
                        obs_pos_x[i] += obs_vx_3[0];
                        obs_pos_y[i] += obs_vy_3[0];
                    }
                    else if (i==3)
                    {
                        obs_pos_x[i] += obs_vx_3[i];
                        obs_pos_y[i] += obs_vy_3[i];
                    }
                    else
                    {
                        obs_pos_x[i] -= obs_vx_3[0];
                        obs_pos_y[i] += obs_vy_3[0];
                    }
                }

                /* MOMENTOS NOS QUAIS O SENTIDO DA VELOCIDADE DOS OBSTACULOS LATERAIS DA FASE 3 VAI MUDAR */
                if ((obs_pos_x[0] >= 260 - 20/2)&&(obs_pos_y[0]==180-20/2))
                {
                    obs_vx_3[0] = 0;
                    obs_vy_3[0] = 3;
                }
                else if ((obs_pos_x[0] == 260 - 20/2)&&(obs_pos_y[0] >= 300 - 20/2))
                {
                    obs_vx_3[0] = -3;
                    obs_vy_3[0] = 0;
                }
                else if ((obs_pos_x[0] <= 140 - 20/2)&&(obs_pos_y[0] == 300 - 20/2))
                {
                    obs_vx_3[0] = 0;
                    obs_vy_3[0] = -3;
                }
                else if ((obs_pos_x[0] == 140 - 20/2)&&(obs_pos_y[0] <= 180 - 20/2))
                {
                    obs_vx_3[0] = 3;
                    obs_vy_3[0] = 0;
                }

                /* MOMENTO QUE O SENTIDO DA VELOCIDADE DO OBSTACULO CENTRAL DA FASE 3 VAI MUDAR */
                if ((obs_pos_x[3] >= 380 - 20/2)&&(obs_pos_y[3] == 220 - 20/2))
                {
                    obs_pos_x[3] = 380 - 20/2;

                    obs_vx_3[3] = 0;
                    obs_vy_3[3] = 3;
                }
                else if ((obs_pos_x[3] == 380 - 20/2)&&(obs_pos_y[3] >= 500 - 20/2))
                {
                    obs_pos_y[3] = 500 - 20/2;

                    obs_vx_3[3] = -3;
                    obs_vy_3[3] = 0;
                }
                else if ((obs_pos_x[3] <= 260 - 20/2)&&(obs_pos_y[3] == 500 - 20/2))
                {
                    obs_pos_x[3] = 260 - 20/2;

                    obs_vx_3[3] = 0;
                    obs_vy_3[3] = -3;
                }
                else if ((obs_pos_x[3] == 260 - 20/2)&&(obs_pos_y[3] <= 220 - 20/2))
                {
                    obs_pos_y[3] = 220 - 20/2;

                    obs_vx_3[3] = 3;
                    obs_vy_3[3] = 0;
                }

                /* CHECAGEM DE COLISÃO COM OS OBSTACULOS */
                for (i = 0; i < 7; i++)
                {
                    if ((bloco_pos_x >= obs_pos_x[i]+4-28)&&(bloco_pos_x <= obs_pos_x[i] + 16)&&
                    (bloco_pos_y >= obs_pos_y[i]+4-28)&&(bloco_pos_y <= obs_pos_y[i] + 16))
                    {
                        bloco_vx = 0;
                        bloco_vy = 0;

                        alpha = 0;

                        bloco_pos_x = spawnpoint_x[2];
                        bloco_pos_y = spawnpoint_y[2];

                        deaths = deaths + 1;

                        /* BARULHO DO STEVE */
                        al_play_sample(colisao, volume + 0.3, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);

                        /* TODAS AS MOEDAS DA FASE 3 APARECEM OUTRA VEZ */
                        for (j=0; j <4; j++)
                        {
                            if (moeda_fora[j])
                            {
                                moeda_fora[j] = false;
                            }
                        }

                    }

                }

                /* CHECAGEM PARA VER SE O JOGADOR PEGOU ALGUMA MOEDA */
                for (i=0; i<4; i++)
                {
                    if ((bloco_pos_x >= moeda_pos_x[i]+4-28)&&(bloco_pos_x <= moeda_pos_x[i] + 16)&&
                    (bloco_pos_y >= moeda_pos_y[i]+4-28)&&(bloco_pos_y <= moeda_pos_y[i] + 16))
                    {
                        moeda_fora[i] = true;
                    }
                }

                /*CHECAGEM PARA VER SE O JOGADOR TERMINOU A FASE 3 */
                if ((bloco_pos_x > 520 - 27)&&(bloco_pos_y >= 320)&&(bloco_pos_y<=400-28)&&
                (moeda_fora[0])&&(moeda_fora[1])&&(moeda_fora[2])&&(moeda_fora[3]))
                {
                    fase = 4;

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

                    /* VELOCIDADE DOS OBSTACULOS DA FASE 1 */
                    obs_vx_1 = 6;

                }










            }

            redraw = true;
        }

        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(ev.keyboard.keycode)
            {
<<<<<<< HEAD
                case (ALLEGRO_KEY_UP):
=======
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a
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

                case (ALLEGRO_KEY_DOWN):
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



                    if (can_move)
                    {
                        bloco_vy = 2.75;
                    }
                    else
                    {
                        bloco_vy = 0;
                    }


                    break;

                case (ALLEGRO_KEY_RIGHT):
                case (ALLEGRO_KEY_D):

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

                case ALLEGRO_KEY_LEFT:
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
<<<<<<< HEAD

                case ALLEGRO_KEY_ENTER:

                    if (fase == 4)
                    {
                        fase = 1;
                        deaths = 0;
                        qtd_moeda = 0;

                        for (i = 0; i<4; i++)
                        {
                            moeda_fora[i] = false;
                        }

                        bloco_vx = 0;
                        bloco_vy = 0;

                        alpha = 0;

                        bloco_pos_x = spawnpoint_x[0];
                        bloco_pos_y = spawnpoint_y[0];
                    }

                    break;




=======
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a
            }
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch(ev.keyboard.keycode)
            {
<<<<<<< HEAD

            case ALLEGRO_KEY_RIGHT:
=======
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a
            case ALLEGRO_KEY_D:
                if (bloco_vx > 0)
                {
                    bloco_vx = 0;
                }

                break;

            case ALLEGRO_KEY_LEFT:
            case ALLEGRO_KEY_A:
                if (bloco_vx < 0)
                {
                    bloco_vx = 0;
                }

                break;

            case ALLEGRO_KEY_UP:
            case ALLEGRO_KEY_W:
                if (bloco_vy < 0)
                {
                    bloco_vy = 0;
                }

                break;

            case ALLEGRO_KEY_DOWN:
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
<<<<<<< HEAD

                /*CONTADOR DE MORTES */
                al_draw_text(font3, al_map_rgb(0, 0, 0), 10, 10, 0, cont_mortes);
                sprintf(cont_mortes, "deaths: %d", deaths);
=======
                al_draw_text(font3, al_map_rgb(0, 0, 0), 10, 10, 0, cont_mortes);
                sprintf(cont_mortes, "mortes: %d", deaths);
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a
            }
            else if (fase == 2)
            {
                al_draw_bitmap(background_2, 0, 0, 0);
<<<<<<< HEAD

                /*CONTADOR DE MORTES */
                al_draw_text(font3, al_map_rgb(0, 0, 0), 10, 10, 0, cont_mortes);
                sprintf(cont_mortes, "deaths: %d", deaths);
=======
                al_draw_text(font3, al_map_rgb(0, 0, 0), 10, 10, 0, cont_mortes);
                sprintf(cont_mortes, "mortes: %d", deaths);
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a
            }
            else if (fase == 3)
            {
                al_draw_bitmap(background_3, 0, 0, 0);
<<<<<<< HEAD

                /*CONTADOR DE deaths */
                al_draw_text(font3, al_map_rgb(0, 0, 0), 10, 10, 0, cont_mortes);
                sprintf(cont_mortes, "deaths: %d", deaths);
            }
            else if (fase == 4)
            {
                al_clear_to_color(al_map_rgb(174, 183 , 254));

                // Escreve a mensagem no meio da tela
                al_draw_text(font3, al_map_rgb(0, 0, 0), SCREEN_W/2, SCREEN_H/2 - 90, ALLEGRO_ALIGN_CENTRE, "OMG, I can't believe it!");
                al_draw_text(font3, al_map_rgb(0, 0, 0), SCREEN_W/2, SCREEN_H/2 - 40, ALLEGRO_ALIGN_CENTRE, "You  did it!");

                /* CONTADOR DE deaths */
                al_draw_text(font4, al_map_rgb(0, 0, 0), SCREEN_W/2, 382, ALLEGRO_ALIGN_CENTRE, cont_mortes);
                sprintf(cont_mortes, "deaths: %d", deaths);

                al_draw_text(font4, al_map_rgb(0, 0, 0), SCREEN_W/2, 520, ALLEGRO_ALIGN_CENTRE, "Esc to leave");
                al_draw_text(font4, al_map_rgb(0, 0, 0), SCREEN_W/2, 570, ALLEGRO_ALIGN_CENTRE, "Enter to try again");

=======
                al_draw_text(font3, al_map_rgb(0, 0, 0), 10, 10, 0, cont_mortes);
                sprintf(cont_mortes, "mortes: %d", deaths);
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a
            }



            /* DESENHO DO BLOCO */
            if ((fase >=1)&&(fase<=3))
            {
                al_draw_tinted_bitmap(bloco, al_map_rgba_f(1, 1, 1, alpha), bloco_pos_x, bloco_pos_y, 0);
            }


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
            else if(fase == 3)
            {
                for (i=0; i<4; i++)
                {
                    if (!moeda_fora[i])
                    {
                        al_draw_bitmap(moeda, moeda_pos_x[i], moeda_pos_y[i], 0);
                    }
                }

<<<<<<< HEAD
                for (i=0 ; i<7; i++)
                {
                    al_draw_bitmap(obstaculo, obs_pos_x[i], obs_pos_y[i], 0);
                }
            }


=======
>>>>>>> 76a10ac9b1031bb8b1876fa584c8872257c52e4a
            al_flip_display();

        }

    }


    al_destroy_font(font);
    al_destroy_font(font2);
    al_destroy_font(font3);
    al_destroy_font(font4);
    al_destroy_sample_instance(selectingmenu);
    al_destroy_sample(selectingmenu_sample);
    al_destroy_audio_stream(musica);
    al_destroy_bitmap(bloco);
    al_destroy_bitmap(obstaculo);
    al_destroy_bitmap(moeda);
    al_destroy_bitmap(background_1);
    al_destroy_bitmap(background_2);
    al_destroy_bitmap(background_3);
    al_destroy_bitmap(background_menu);
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;

}

