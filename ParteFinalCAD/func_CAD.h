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

#ifndef FUNC_CAD_H_INCLUDED
#define FUNC_CAD_H_INCLUDED

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <math.h>

/**< Função Escreve na Janela */
void escrita_janela( ALLEGRO_FONT *fonte, int LARGURA_TELA);
/**< Função Desenha um quadrado na Janela */
void Des_Quadrado( int desenha_quadrado, ALLEGRO_FONT *fonte, int x1, int y2);
/**< Função Desenha um quadrado preenchido na Janela */
void Des_Quadrado_preenchido( int desenha_quadrado, ALLEGRO_FONT *fonte, int x1, int y2);
/**< Função Desenha um circulo na Janela */
void Des_Circulo( int desenha_circulo, ALLEGRO_FONT *fonte, int x1, int y1, int x2, int y2);
/**< Função Desenha um circulo preenchido na Janela */
void Des_Circulo_preenchido(int desenha_circulo, ALLEGRO_FONT *fonte, int x1, int y1, int x2, int y2);
/**< Função Desenha um retangulo na Janela */
void Des_Retangulo( int desenha_retangulo, ALLEGRO_FONT *fonte, int x1, int y1, int x2, int y2);
/**< Função Desenha um retangulo preenchido na Janela */
void Des_Retangulo_preenchido(int desenha_retangulo, ALLEGRO_FONT *fonte, int x1, int y1, int x2, int y2);
/**< Função Desenha uma elipse na Janela */
void Des_Elipse( int desenha_elipse, ALLEGRO_FONT *fonte, int x1, int y1, int x2, int y2, int x3, int y3);
/**< Função Desenha uma elipse preenchido na Janela */
void Des_Elipse_preenchido( int desenha_elipse, ALLEGRO_FONT *fonte, ALLEGRO_EVENT_QUEUE *fila_eventos, int x1, int y1, int x2, int y2, int x3, int y3);
/**< Função Desenha um triangulo na Janela */
void Des_Triangulo ( int desenha_triangulo, ALLEGRO_FONT *fonte, int x1, int y1, int x2, int y2, int x3, int y3);
/**< Função Desenha um triangulo preenchido na Janela */
void Des_Triangulo_preenchido( int desenha_triangulo, ALLEGRO_FONT *fonte, int x1, int y1, int x2, int y2, int x3, int y3);
/**< Função que muda a cor do botão quando o mouse estiver sobre ele */
void muda_cor_botao( int nomeBotao);
/**< Verifica se há falha na criação do bitmap */
void falha_bitmap( ALLEGRO_DISPLAY *janela, ALLEGRO_BITMAP *Elemento);

#endif // FUNC_CAD_H_INCLUDED
