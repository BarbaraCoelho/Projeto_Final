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

#ifndef PROJ_CAD_H_INCLUDED
#define PROJ_CAD_H_INCLUDED

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

/**< Função Escreve na Janela */
void escrita_janela( ALLEGRO_FONT *fonte, int LARGURA_TELA);
/**< Função Desenha um quadrado na Janela */
void Des_Quadrado( int desenha_quadrado);
/**< Função Desenha um quadrado preenchido na Janela */
void Des_Quadrado_preenchido( int desenha_quadrado);
/**< Função Desenha um circulo na Janela */
void Des_Circulo( int desenha_circulo);
/**< Função Desenha um circulo preenchido na Janela */
void Des_Circulo_preenchido(int desenha_circulo);
/**< Função Desenha um retangulo na Janela */
void Des_Retangulo( int desenha_retangulo);
/**< Função Desenha um retangulo preenchido na Janela */
void Des_Retangulo_preenchido(int desenha_retangulo);
/**< Função Desenha uma elipse na Janela */
void Des_Elipse( int desenha_elipse);
/**< Função Desenha uma elipse preenchido na Janela */
void Des_Elipse_preenchido( int desenha_elipse);
/**< Função Desenha um triangulo na Janela */
void Des_Triangulo ( int desenha_triangulo);
/**< Função Desenha um triangulo preenchido na Janela */
void Des_Triangulo_preenchido( int desenha_triangulo);
/**< Função que muda a cor do botão quando o mouse estiver sobre ele */
void muda_cor_botao( int nomeBotao);

#endif // PROJ_CAD_H_INCLUDED
