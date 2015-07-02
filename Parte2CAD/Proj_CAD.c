/**************************************************************************

    Aluna: Bárbara Coelho.
    IFSC - Câmpus Florianópolis
    Engenharia Eletrônica
    Programação de Computadores II - 2015/1

                          Projeto Final - CAD
                             ( Parte 2 )

    * Nessa etapa os botões estão funcionando, no entanto, os valores
      são fixos, na próxima etapa será usado valores pegos pelo mouse.

**************************************************************************/

#include "Proj_CAD.h"

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
void Des_Quadrado(int desenha_quadrado)
{
    if (desenha_quadrado == 1 )
    {
        al_draw_rectangle(100, 100, 200, 200, al_map_rgb(255, 255,255), 10); // funciona no linux
    }
}

/**< Função Desenha um quadrado preenchido na Janela */
void Des_Quadrado_preenchido( int desenha_quadrado)
{
    if (desenha_quadrado == 1)
    {
        al_draw_filled_rectangle(100, 100, 200, 200, al_map_rgb(255, 255,255));
    }
}

/**< Função Desenha um circulo na Janela */
void Des_Circulo(int desenha_circulo)
{
    if (desenha_circulo == 1)
    {
        al_draw_circle(200, 300, 70, al_map_rgb(128, 0, 0), 2.0);
    }
}

/**< Função Desenha um circulo preenchido na Janela */
void Des_Circulo_preenchido(int desenha_circulo)
{
    if (desenha_circulo == 1)
    {
        al_draw_filled_circle(200, 300, 70, al_map_rgb(255, 255,255));
    }
}

/**< Função Desenha um retangulo na Janela */
void Des_Retangulo(int desenha_retangulo)
{
    if (desenha_retangulo == 1)
    {
        al_draw_rectangle(100, 100, 300, 200, al_map_rgb(255, 255,255), 10); // funciona no linux
    }
}

/**< Função Desenha um retangulo preenchido na Janela */
void Des_Retangulo_preenchido(int desenha_retangulo)
{
    if (desenha_retangulo == 1)
    {
        al_draw_filled_rectangle(100, 100, 300, 200, al_map_rgb(255, 255,255));
    }
}

/**< Função Desenha uma elipse na Janela */
void Des_Elipse( int desenha_elipse)
{
    if (desenha_elipse == 1)
    {
         al_draw_ellipse(70.0, 90.0, 20.0, 55.0, al_map_rgb(255, 255, 255), 5.0);
    }
}

/**< Função Desenha uma elipse preenchido na Janela */
void Des_Elipse_preenchido( int desenha_elipse)
{
    if (desenha_elipse == 1)
    {
        al_draw_filled_ellipse(70.0, 90.0, 20.0, 55.0, al_map_rgb(255, 255, 255));
    }
}

/**< Função Desenha um triangulo na Janela */
void Des_Triangulo( int desenha_triangulo)
{
    if (desenha_triangulo == 1)
    {
       al_draw_triangle(100.0, 80.0, 50.0, 50.0, 110.0, 250.0, al_map_rgb(255, 255, 255), 5.0);
    }
}

/**< Função Desenha um triangulo preenchido na Janela */
void Des_Triangulo_preenchido( int desenha_triangulo)
{
    if (desenha_triangulo == 1)
    {
        al_draw_filled_triangle(200.0, 200.0, 300.0, 100.0, 110.0, 250.0, al_map_rgb(255, 255, 255));
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
