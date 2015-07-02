/**
*    Aluna: Bárbara Coelho.
*    IFSC - Câmpus Florianópolis
*    Engenharia Eletrônica
*    Programação de Computadores II - 2015/1
*
*                          Projeto Final - CAD
*                            ( Parte final )
*
*     Nessa etapa os botões estão funcionando e os valores  são pegos
*     pelo mouse.
*/

#include "func_CAD.h"

int main(void)
{
    /**< Atributos da tela */
    const int LARGURA_TELA = 640;
    const int ALTURA_TELA = 480;

    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_FONT *fonte = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_BITMAP *botao_sair = NULL;
    ALLEGRO_BITMAP *Quadrado = NULL;
    ALLEGRO_BITMAP *Circulo = NULL;
    ALLEGRO_BITMAP *Retangulo = NULL;
    ALLEGRO_BITMAP *Elipse = NULL;
    ALLEGRO_BITMAP *Triangulo = NULL;
    ALLEGRO_BITMAP *limpa_janela = NULL;
    ALLEGRO_BITMAP *preenchido = NULL;


    /**< Flag que condiciona o looping */
    int sair = 0;
    /**< Flag que indica se o objeto vai ou não ser preenchido */
    int preencher = 0;
    /**< Flag utilizada para desenhar um quandrado quando 1 */
    int desenha_quadrado = 0;
    /**< Flag utilizada para desenhar um circulo quando 1 */
    int desenha_circulo = 0;
    /**< Flag utilizada para desenhar um retangulo quando 1 */
    int desenha_retangulo = 0;
    /**< Flag utilizada para desenhar um elipse quando 1 */
    int desenha_elipse = 0;
    /**< Flag utilizada para desenhar um elipse quando 1 */
    int desenha_triangulo = 0;
    /**< Flag utilizada para janela tela quando 1 */
    int limpa_j = 0;


    /**< Inicialização da biblioteca Allegro */
    if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
        return -1;
    }

    /**< Inicialização do add-on para uso de fontes */
    al_init_font_addon();
    if (!al_init_ttf_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
        return -1;
    }

    /**< Inicializa as funções primitivas */
    if (!al_init_primitives_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on de primitivas.\n");
        return false;
    }

    /**< Criação da janela */
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
        return -1;
    }

    /**< Carregando o arquivo de fonte */
    fonte = al_load_font("arial.TTF", 27, 0);
    if (!fonte)
    {
        al_destroy_display(janela);
        fprintf(stderr, "Falha ao carregar fonte.\n");
        return -1;
    }

    /**< Configura o título da janela */
    al_set_window_title(janela, "Barbara Coelho - Projeto CAD");

    /**< Torna apto o uso de mouse na aplicação */
    if (!al_install_mouse())
    {
        fprintf(stderr, "Falha ao inicializar o mouse.\n");
        al_destroy_display(janela);
        return -1;
    }

    /**< Atribui o cursor padrão do sistema para ser usado */
    if (!al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT))
    {
        fprintf(stderr, "Falha ao atribuir ponteiro do mouse.\n");
        al_destroy_display(janela);
        return -1;
    }

    /**< É criado um mapa de bit para o Quadrado */
    Quadrado = al_create_bitmap(135, 50);
    falha_bitmap(janela, Quadrado);

    /**< É criado um mapa de bit para o Circulo */
    Circulo = al_create_bitmap(105, 50);
    falha_bitmap(janela, Circulo);

    /**< É criado um mapa de bit para o Retangulo */
    Retangulo = al_create_bitmap(140, 50);
    falha_bitmap(janela, Retangulo);

    /**< É criado um mapa de bit para a Elipse */
    Elipse = al_create_bitmap(90, 50);
    falha_bitmap(janela, Elipse);

    /**< É criado um mapa de bit para o Triangulo */
    Triangulo = al_create_bitmap(170, 50);
    falha_bitmap(janela, Triangulo);

    /**< É criado um mapa de bit para o limpa_janela */
    limpa_janela = al_create_bitmap(180, 50);
    falha_bitmap(janela, limpa_janela);

    /**< É criado um mapa de bit para o preenchido */
    preenchido = al_create_bitmap(160, 50);
    falha_bitmap(janela, preenchido);

    /**< É alocado o botão para fechar a janela */
    botao_sair = al_create_bitmap(100, 50);
    if (!botao_sair)
    {
        fprintf(stderr, "Falha ao criar botão de saída.\n");
        al_destroy_bitmap(Quadrado);
        al_destroy_bitmap(Circulo);
        al_destroy_bitmap(Retangulo);
        al_destroy_bitmap(Elipse);
        al_destroy_bitmap(Triangulo);
        al_destroy_bitmap(limpa_janela);
        al_destroy_bitmap(preenchido);
        al_destroy_font(fonte);
        al_destroy_display(janela);
        return -1;
    }

    /**< Inicicaliza a fila de eventos */
    fila_eventos = al_create_event_queue();
    if (!fila_eventos)
    {
        fprintf(stderr, "Falha ao inicializar o fila de eventos.\n");
        al_destroy_display(janela);
        return -1;
    }

    /**< Trata os eventos vindos do mouse */
    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    /**< Flags indicando se o mouse está sobre o retangulo do Quadrado */
    int no_quadrado = 0;
    /**< Flags indicando se o mouse está sobre o retangulo do Circulo */
    int no_circulo = 0;
    /**< Flags indicando se o mouse está sobre o retangulo do Retangulo */
    int no_retangulo = 0;
    /**< Flags indicando se o mouse está sobre o retangulo do Elipse */
    int no_elipse = 0;
    /**< Flags indicando se o mouse está sobre o retangulo do Triangulo */
    int no_triangulo = 0;
    /**< Flags indicando se o mouse está sobre o retangulo do botao_sair */
    int no_botao_sair = 0;
    /**< Flags indicando se o mouse está sobre o retangulo do limpa_janela */
    int no_limpa_janela = 0;
    /**< Flags indicando se o mouse está sobre o retangulo do preenchido */
    int no_preenchido = 0;
    /**< Flag salvar cada posição clicada */
    int aux = 0;
    /**< Flag usada para armazenar as posições do mouse */
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1, x3 = -1, y3 = -1;

    /**< Sai do while se quando o mouse é clicado dentro do botão de sair "vermelho" */
    while (!sair)
    {
        /**< Verificamos se há eventos na fila */
        while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            /**< Se o evento foi de movimentação do mouse */
            if (evento.type == ALLEGRO_EVENT_MOUSE_AXES)
            {
                /**< Verificamos se ele está sobre a região do retângulo de Quadrado */
                if (evento.mouse.x >= 0  && evento.mouse.x <= 135 && evento.mouse.y >= 0 && evento.mouse.y <= 50)
                {
                    no_quadrado = 1;
                }
                /**< Verificamos se ele está sobre a região do retângulo de Circulo */
                else if (evento.mouse.x >= 145 && evento.mouse.x <= 250 && evento.mouse.y >= 0 && evento.mouse.y <= 50)
                {
                    no_circulo = 1;
                }
                /**< Verificamos se ele está sobre a região do retângulo de Retamgulo */
                else if (evento.mouse.x >= 260  && evento.mouse.x <= 400 && evento.mouse.y >= 0 && evento.mouse.y <= 50)
                {
                    no_retangulo = 1;
                }
                /**< Verificamos se ele está sobre a região do retângulo de Elipse */
                else if (evento.mouse.x >= 410  && evento.mouse.x <= 500 && evento.mouse.y >= 0 && evento.mouse.y <= 50)
                {
                    no_elipse = 1;
                }
                /**< Verificamos se ele está sobre a região do retângulo de Triangulo */
                else if (evento.mouse.x >= 510  && evento.mouse.x <= 640 && evento.mouse.y >= 0 && evento.mouse.y <= 50)
                {
                    no_triangulo = 1;
                }
                /**< Verificamos se ele está sobre a região do retângulo do botao_sair */
                else if (evento.mouse.x >= 530  && evento.mouse.x <= 630 && evento.mouse.y >= 420 && evento.mouse.y <= 470)
                {
                    no_botao_sair = 1;
                }
                /**< Verificamos se ele está sobre a região do retângulo do limpa_janela */
                else if (evento.mouse.x >= 10  && evento.mouse.x <= 190 && evento.mouse.y >= 420 && evento.mouse.y <= 470)
                {
                    no_limpa_janela = 1;
                }
                /**< Verificamos se ele está sobre a região do retângulo do preenchido */
                else if (evento.mouse.x >= 240  && evento.mouse.x <= 400 && evento.mouse.y >= 420 && evento.mouse.y <= 470)
                {
                    no_preenchido = 1;
                }
                else
                {
                    no_quadrado = 0;
                    no_circulo = 0;
                    no_retangulo = 0;
                    no_elipse = 0;
                    no_triangulo = 0;
                    no_botao_sair = 0;
                    no_limpa_janela = 0;
                    no_preenchido = 0;
                }
            }
            /**< Verifica se o evento foi um clique do mouse */
            else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
            {
                /**< Leitura do botao sair */
                if( evento.mouse.x >= 530 && evento.mouse.x <= 630 && evento.mouse.y <= 470 && evento.mouse.y >= 420)
                {
                    sair = 1;
                }
                /**< Leitura do botao quadrado */
                else if( evento.mouse.x >= 0 && evento.mouse.x <= 135 && evento.mouse.y <= 50 && evento.mouse.y >= 0)
                {
                    desenha_quadrado = 1;
                    desenha_circulo = 0;
                    desenha_retangulo = 0;
                    desenha_elipse = 0;
                    desenha_triangulo = 0;
                    aux = 0;
                }
                /**< Leitura do botao circulo */
                else if( evento.mouse.x >= 145 && evento.mouse.x <= 250 && evento.mouse.y <= 50 && evento.mouse.y >= 0)
                {
                    desenha_quadrado = 0;
                    desenha_circulo = 1;
                    desenha_retangulo = 0;
                    desenha_elipse = 0;
                    desenha_triangulo = 0;
                    aux = 0;
                }
                /**< Leitura do botao retangulo */
                else if( evento.mouse.x >= 260 && evento.mouse.x <= 400 && evento.mouse.y <= 50 && evento.mouse.y >= 0)
                {
                    desenha_quadrado = 0;
                    desenha_circulo = 0;
                    desenha_retangulo = 1;
                    desenha_elipse = 0;
                    desenha_triangulo = 0;
                    aux = 0;
                }
                /**< Leitura do botao elipse */
                else if( evento.mouse.x >= 410 && evento.mouse.x <= 500 && evento.mouse.y <= 50 && evento.mouse.y >= 0)
                {
                    desenha_quadrado = 0;
                    desenha_circulo = 0;
                    desenha_retangulo = 0;
                    desenha_elipse = 1;
                    desenha_triangulo = 0;
                    aux = 0;
                }
                /**< Leitura do botao triangulo */
                else if( evento.mouse.x >= 510 && evento.mouse.x <= 640 && evento.mouse.y <= 50 && evento.mouse.y >= 0)
                {
                    desenha_quadrado = 0;
                    desenha_circulo = 0;
                    desenha_retangulo = 0;
                    desenha_elipse = 0;
                    desenha_triangulo = 1;
                    aux = 0;
                }
                 /**< Leitura do botao limpa janela */
                else if( evento.mouse.x >= 10 && evento.mouse.x <= 190 && evento.mouse.y <= 470 && evento.mouse.y >= 420)
                {
                    limpa_j = 1;
                }
                 /**< Leitura do botao preenchido */
                else if( evento.mouse.x >= 240 && evento.mouse.x <= 400 && evento.mouse.y <= 470 && evento.mouse.y >= 420)
                {
                    preencher = 1;
                }
                else if(aux == 0)
                {
                    x1 = evento.mouse.x;
                    y1 = evento.mouse.y;
                    aux = 1;
                }
                else if(aux == 1)
                {
                    x2= evento.mouse.x;
                    y2 = evento.mouse.y;
                    aux = 2;
                }
                else if(aux == 2 && (desenha_triangulo == 1 || desenha_elipse == 1))
                {
                    x3= evento.mouse.x;
                    y3 = evento.mouse.y;
                }

                printf("x1 = %d  y1 = %d\nx2 = %d  y2 = %d\nx3 = %d  y3 = %d\n\n", x1, y1, x2, y2, x3, y3);
            }
        }
        /**< Limpa a tela */
        al_clear_to_color(al_map_rgb(0, 0, 0));

        /**< Condição que preenche os elemento geométrico caso seja igual a 1 */
        if (!preencher)
        {
            /**< Desenha o elemento geométrico no respectivo do botão */
            Des_Quadrado( desenha_quadrado, fonte, x1, y2);
            Des_Circulo( desenha_circulo, fonte, x1, y1, x2, y2);
            Des_Retangulo( desenha_retangulo, fonte, x1, y1, x2, y2);
            Des_Elipse( desenha_elipse, fonte, x1, y1, x2, y2, x3, y3);
            Des_Triangulo ( desenha_triangulo, fonte, x1, y1, x2, y2, x3, y3);
        }
        else
        {
            /**< Desenha o elemento geométrico preenchido no respectivo do botão */
            Des_Quadrado_preenchido( desenha_quadrado, fonte, x1, y2);
            Des_Circulo_preenchido( desenha_circulo, fonte, x1, y1, x2, y2);
            Des_Retangulo_preenchido( desenha_retangulo, fonte, x1, y1, x2, y2);
            Des_Elipse_preenchido( desenha_elipse, fonte, fila_eventos, x1, y1, x2, y2, x3, y3);
            Des_Triangulo_preenchido ( desenha_triangulo, fonte, x1, y1, x2, y2, x3, y3);
        }

        /**< Condição de limpar a janela */
        if( limpa_j == 1)
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            desenha_quadrado = 0;
            desenha_circulo = 0;
            desenha_retangulo = 0;
            desenha_elipse = 0;
            desenha_triangulo = 0;
            limpa_j = 0;
            preencher = 0;
            aux = 0;
            x1 = -1;
            y1 = -1;
            x2 = -1;
            y2 = -1;
            x3 = -1;
            y3 = -1;
        }

        /**< É colorido o bitmap correspondente ao retângulo do Quadrado */
        al_set_target_bitmap( Quadrado);
        muda_cor_botao( no_quadrado);

        /**< É colorido o bitmap correspondente ao retângulo do Circulo */
        al_set_target_bitmap( Circulo);
        muda_cor_botao( no_circulo);

        /**< É colorido o bitmap correspondente ao retângulo do Retangulo */
        al_set_target_bitmap (Retangulo);
        muda_cor_botao( no_retangulo);

        /**< É colorido o bitmap correspondente ao retângulo do Elipse */
        al_set_target_bitmap( Elipse);
        muda_cor_botao( no_elipse);

        /**< É colorido o bitmap correspondente ao retângulo do Triangulo */
        al_set_target_bitmap( Triangulo);
        muda_cor_botao( no_triangulo);

        /**< É colorido o bitmap correspondente ao retângulo do botao_sair */
        al_set_target_bitmap( botao_sair);
        muda_cor_botao( no_botao_sair);

        /**< É colorido o bitmap correspondente ao retângulo do limpa_janela */
        al_set_target_bitmap( limpa_janela);
        muda_cor_botao( no_limpa_janela);

        /**< É colorido o bitmap correspondente ao retângulo do preenchido */
        al_set_target_bitmap(preenchido);
        muda_cor_botao(no_preenchido);

        /**< Desenha os retângulos na tela */
        al_set_target_bitmap(al_get_backbuffer(janela));
        /**< Desenha o retângulo do Quadrado */
        al_draw_bitmap(Quadrado, 0 , 0, 0);
        /**< Desenha o retângulo do Circulo */
        al_draw_bitmap(Circulo, 145, 0, 0);
        /**< Desenha o retângulo do Retangulo */
        al_draw_bitmap(Retangulo, 260, 0, 0);
        /**< Desenha o retângulo da Elipse */
        al_draw_bitmap(Elipse, 410, 0, 0);
        /**< Desenha o retângulo do Triangulo */
        al_draw_bitmap(Triangulo, 510, 0, 0);
        /**< Desenha o retângulo do limpa_janela */
        al_draw_bitmap(limpa_janela, 10, 420, 0);
        /**< Desenha o retângulo do preenchido */
        al_draw_bitmap(preenchido, 240, 420, 0);
        /**< Desenha o retângulo do botão de saida */
        al_draw_bitmap(botao_sair, 530, 420, 0);

        escrita_janela(fonte,LARGURA_TELA);

        /**< Atualiza a tela */
        al_flip_display();
    }

    /**< Desaloca os recursos utilizados na aplicação */
    al_destroy_bitmap(botao_sair);
    al_destroy_bitmap(Quadrado);
    al_destroy_bitmap(Circulo);
    al_destroy_bitmap(Retangulo);
    al_destroy_bitmap(Elipse);
    al_destroy_bitmap(Triangulo);
    al_destroy_bitmap(limpa_janela);
    al_destroy_bitmap(preenchido);
    al_destroy_font(fonte);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);

    return 0;
}
