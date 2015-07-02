/**************************************************************************

    Aluna: B�rbara Coelho.
    IFSC - C�mpus Florian�polis
    Engenharia Eletr�nica
    Programa��o de Computadores II - 2015/1

                          Projeto Final - CAD
                             ( Parte 2 )

    * Nessa etapa os bot�es est�o funcionando, no entanto, os valores
      s�o fixos, na pr�xima etapa ser� usado valores pegos pelo mouse.

**************************************************************************/

#ifndef PROJ_CAD_H_INCLUDED
#define PROJ_CAD_H_INCLUDED

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

/**< Fun��o Escreve na Janela */
void escrita_janela( ALLEGRO_FONT *fonte, int LARGURA_TELA);
/**< Fun��o Desenha um quadrado na Janela */
void Des_Quadrado( int desenha_quadrado);
/**< Fun��o Desenha um quadrado preenchido na Janela */
void Des_Quadrado_preenchido( int desenha_quadrado);
/**< Fun��o Desenha um circulo na Janela */
void Des_Circulo( int desenha_circulo);
/**< Fun��o Desenha um circulo preenchido na Janela */
void Des_Circulo_preenchido(int desenha_circulo);
/**< Fun��o Desenha um retangulo na Janela */
void Des_Retangulo( int desenha_retangulo);
/**< Fun��o Desenha um retangulo preenchido na Janela */
void Des_Retangulo_preenchido(int desenha_retangulo);
/**< Fun��o Desenha uma elipse na Janela */
void Des_Elipse( int desenha_elipse);
/**< Fun��o Desenha uma elipse preenchido na Janela */
void Des_Elipse_preenchido( int desenha_elipse);
/**< Fun��o Desenha um triangulo na Janela */
void Des_Triangulo ( int desenha_triangulo);
/**< Fun��o Desenha um triangulo preenchido na Janela */
void Des_Triangulo_preenchido( int desenha_triangulo);
/**< Fun��o que muda a cor do bot�o quando o mouse estiver sobre ele */
void muda_cor_botao( int nomeBotao);

#endif // PROJ_CAD_H_INCLUDED
