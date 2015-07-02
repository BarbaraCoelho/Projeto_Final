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

/**< Função Escreve na Janela */
void escrita_janela( ALLEGRO_FONT *fonte, int LARGURA_TELA)
{
    /**< Escreve Quadrado na janela */
    al_draw_text(fonte, al_map_rgb(255, 255, 255), 5, 8, ALLEGRO_ALIGN_LEFT, "Quadrado");
    /**< Escreve Circulo na janela */
    al_draw_text(fonte, al_map_rgb(255, 255, 255), (LARGURA_TELA / 2) - 125, 8, ALLEGRO_ALIGN_CENTRE, "Circulo");
    /**< Escreve Retangulo na janela */
    al_draw_text(fonte, al_map_rgb(255, 255, 255), (LARGURA_TELA / 2) + 10, 8, ALLEGRO_ALIGN_CENTRE, "Retangulo");
    /**< Escreve Elipse na janela */
    al_draw_text(fonte, al_map_rgb(255, 255, 255), (LARGURA_TELA / 2) + 135, 8, ALLEGRO_ALIGN_CENTRE, "Elipse");
    /**< Escreve Triangulo na janela */
    al_draw_text(fonte, al_map_rgb(255, 255, 255), LARGURA_TELA - 10, 8, ALLEGRO_ALIGN_RIGHT, "Triangulo");
    /**< Escreve Saida na janela */
    al_draw_text(fonte, al_map_rgb(255, 255, 255), LARGURA_TELA - 35, 430, ALLEGRO_ALIGN_RIGHT, "Sair");
    /**< Escreve Limpar tela */
    al_draw_text(fonte, al_map_rgb(255, 255, 255), 30 , 430, ALLEGRO_ALIGN_LEFT, "Limpar Tela");
    /**< Escreve preenchido */
    al_draw_text(fonte, al_map_rgb(255, 255, 255), (LARGURA_TELA/2), 430, ALLEGRO_ALIGN_CENTRE, "Preenchido");
}

/**< Função Desenha um quadrado na Janela */
void Des_Quadrado(int desenha_quadrado, ALLEGRO_FONT *fonte, int x1, int y2)
{
    if (desenha_quadrado == 1 )
    {
        al_draw_text(fonte, al_map_rgb(255, 255, 255), 320, 70, ALLEGRO_ALIGN_CENTRE, "Precione em 2 pontos:");
        al_draw_rectangle(x1, x1, y2, y2, al_map_rgb(255, 255,255), 2);
    }
}

/**< Função Desenha um quadrado preenchido na Janela */
void Des_Quadrado_preenchido( int desenha_quadrado, ALLEGRO_FONT *fonte, int x1, int y2)
{
    if (desenha_quadrado == 1)
    {
        al_draw_text(fonte, al_map_rgb(255, 255, 255), 320, 70, ALLEGRO_ALIGN_CENTRE, "Precione em 2 pontos:");
        al_draw_filled_rectangle(x1, x1, y2, y2, al_map_rgb(255, 255,255));
    }
}

/**< Função Desenha um circulo na Janela */
void Des_Circulo(int desenha_circulo, ALLEGRO_FONT *fonte, int x1, int y1, int x2, int y2)
{
    if (desenha_circulo == 1)
    {
        float r = sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
        al_draw_text(fonte, al_map_rgb(255, 255, 255), 320, 70, ALLEGRO_ALIGN_CENTRE, "Precione em 2 pontos:");
        al_draw_circle(x1, y1, r, al_map_rgb(255, 255, 255), 2);
    }
}

/**< Função Desenha um circulo preenchido na Janela */
void Des_Circulo_preenchido(int desenha_circulo, ALLEGRO_FONT *fonte, int x1, int y1, int x2, int y2)
{
    if (desenha_circulo == 1)
    {
        float r = sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
        al_draw_text(fonte, al_map_rgb(255, 255, 255), 320, 70, ALLEGRO_ALIGN_CENTRE, "Precione em 2 pontos:");
        al_draw_filled_circle( x1, y1, r, al_map_rgb(255, 255,255));
    }
}

/**< Função Desenha um retangulo na Janela */
void Des_Retangulo(int desenha_retangulo, ALLEGRO_FONT *fonte, int x1, int y1, int x2, int y2)
{
    if (desenha_retangulo == 1)
    {
        al_draw_text(fonte, al_map_rgb(255, 255, 255), 320, 70, ALLEGRO_ALIGN_CENTRE, "Precione em 2 pontos:");
        al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(255, 255,255), 2);
    }
}

/**< Função Desenha um retangulo preenchido na Janela */
void Des_Retangulo_preenchido(int desenha_retangulo, ALLEGRO_FONT *fonte, int x1, int y1, int x2, int y2)
{
    if (desenha_retangulo == 1)
    {
        al_draw_text(fonte, al_map_rgb(255, 255, 255), 320, 70, ALLEGRO_ALIGN_CENTRE, "Precione em 2 pontos:");
        al_draw_filled_rectangle( x1, y1, x2, y2, al_map_rgb(255, 255,255));
    }
}

/**< Função Desenha uma elipse na Janela */
void Des_Elipse( int desenha_elipse, ALLEGRO_FONT *fonte, int x1, int y1, int x2, int y2, int x3, int y3)
{
    if (desenha_elipse == 1)
    {
        float a = sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
        float b = sqrt(pow(x1 - x3,2) + pow(y1 - y3,2));
        al_draw_text(fonte, al_map_rgb(255, 255, 255), 320, 70, ALLEGRO_ALIGN_CENTRE, "Precione em 2 pontos:");
        al_draw_ellipse(x1, y1, b, a, al_map_rgb(255, 255, 255), 2);
    }
}

/**< Função Desenha uma elipse preenchido na Janela */
void Des_Elipse_preenchido( int desenha_elipse, ALLEGRO_FONT *fonte, ALLEGRO_EVENT_QUEUE *fila_eventos, int x1, int y1, int x2, int y2, int x3, int y3)
{
     if (desenha_elipse == 1)
    {
        float a = sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
        float b = sqrt(pow(x1 - x3,2) + pow(y1 - y3,2));
        al_draw_text(fonte, al_map_rgb(255, 255, 255), 320, 70, ALLEGRO_ALIGN_CENTRE, "Precione em 2 pontos:");
        al_draw_filled_ellipse(x1, y1, b, a, al_map_rgb(255, 255, 255));
    }
}

/**< Função Desenha um triangulo na Janela */
void Des_Triangulo( int desenha_triangulo, ALLEGRO_FONT *fonte, int x1, int y1, int x2, int y2, int x3, int y3)
{
    if (desenha_triangulo == 1)
    {
        al_draw_text(fonte, al_map_rgb(255, 255, 255), 320, 70, ALLEGRO_ALIGN_CENTRE, "Precione em 3 pontos:");
        al_draw_triangle( x1, y1, x2, y2, x3, y3, al_map_rgb(255, 255, 255), 2);
    }
}

/**< Função Desenha um triangulo preenchido na Janela */
void Des_Triangulo_preenchido( int desenha_triangulo, ALLEGRO_FONT *fonte, int x1, int y1, int x2, int y2, int x3, int y3)
{
    if (desenha_triangulo == 1)
    {
        al_draw_text(fonte, al_map_rgb(255, 255, 255), 320, 70, ALLEGRO_ALIGN_CENTRE, "Precione em 3 pontos:");
        al_draw_filled_triangle( x1, y1, x2, y2, x3, y3, al_map_rgb(255, 255, 255));
    }
}

/**< Função que muda a cor do botão quando o mouse estiver sobre ele */
void muda_cor_botao( int nomeBotao)
{
     if (!nomeBotao)
        {
            al_clear_to_color(al_map_rgb( 0, 255, 0));
        }
        else
        {
            al_clear_to_color(al_map_rgb( 0, 255, 255));
        }
}

/**< Verifica se há falha na criação do bitmap */
void falha_bitmap( ALLEGRO_DISPLAY *janela, ALLEGRO_BITMAP *Elemento)
{
    if (!Elemento)
    {
        fprintf(stderr, "Falha ao criar bitmap.\n");
        al_destroy_display(janela);
        exit (-1);
    }
}
