/**
*    Aluna: B�rbara Coelho.
*    IFSC - C�mpus Florian�polis
*    Engenharia Eletr�nica
*    Programa��o de Computadores II - 2015/1
*
*                          Projeto Final - CAD
*                            ( Parte final )
*
*     Nessa etapa os bot�es est�o funcionando e os valores  s�o pegos
*     pelo mouse.
*/

#ifndef FUNC_CAD_H_INCLUDED
#define FUNC_CAD_H_INCLUDED

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <math.h>

/**< Fun��o Escreve na Janela */
void escrita_janela( ALLEGRO_FONT *fonte, int LARGURA_TELA);
/**< Fun��o Desenha um quadrado na Janela */
void Des_Quadrado( int desenha_quadrado, ALLEGRO_FONT *fonte, int x1, int y2);
/**< Fun��o Desenha um quadrado preenchido na Janela */
void Des_Quadrado_preenchido( int desenha_quadrado, ALLEGRO_FONT *fonte, int x1, int y2);
/**< Fun��o Desenha um circulo na Janela */
void Des_Circulo( int desenha_circulo, ALLEGRO_FONT *fonte, int x1, int y1, int x2, int y2);
/**< Fun��o Desenha um circulo preenchido na Janela */
void Des_Circulo_preenchido(int desenha_circulo, ALLEGRO_FONT *fonte, int x1, int y1, int x2, int y2);
/**< Fun��o Desenha um retangulo na Janela */
void Des_Retangulo( int desenha_retangulo, ALLEGRO_FONT *fonte, int x1, int y1, int x2, int y2);
/**< Fun��o Desenha um retangulo preenchido na Janela */
void Des_Retangulo_preenchido(int desenha_retangulo, ALLEGRO_FONT *fonte, int x1, int y1, int x2, int y2);
/**< Fun��o Desenha uma elipse na Janela */
void Des_Elipse( int desenha_elipse, ALLEGRO_FONT *fonte, int x1, int y1, int x2, int y2, int x3, int y3);
/**< Fun��o Desenha uma elipse preenchido na Janela */
void Des_Elipse_preenchido( int desenha_elipse, ALLEGRO_FONT *fonte, ALLEGRO_EVENT_QUEUE *fila_eventos, int x1, int y1, int x2, int y2, int x3, int y3);
/**< Fun��o Desenha um triangulo na Janela */
void Des_Triangulo ( int desenha_triangulo, ALLEGRO_FONT *fonte, int x1, int y1, int x2, int y2, int x3, int y3);
/**< Fun��o Desenha um triangulo preenchido na Janela */
void Des_Triangulo_preenchido( int desenha_triangulo, ALLEGRO_FONT *fonte, int x1, int y1, int x2, int y2, int x3, int y3);
/**< Fun��o que muda a cor do bot�o quando o mouse estiver sobre ele */
void muda_cor_botao( int nomeBotao);
/**< Verifica se h� falha na cria��o do bitmap */
void falha_bitmap( ALLEGRO_DISPLAY *janela, ALLEGRO_BITMAP *Elemento);

#endif // FUNC_CAD_H_INCLUDED
