#ifndef CONSOLECURSOR_H_INCLUDED
#define CONSOLECURSOR_H_INCLUDED
#include <windows.h>

extern COORD consoleCursorPosition;

/**
 * Pega a coordenada atual do cursor da janela de console,
 *
 * @return uma estrutura COORD que cont�m 2 inteiros shorts: X para o n�mero da
 *     linha e Y para o n�mero da coluna
 */
COORD getConsoleCursorPosition();

/**
 * Altera a posi��o atual do cursor da janela de console utilizando as coordena-
 * das salvas na vari�vel global consoleCursorPosition
 */
void mySetConsoleCursorPosition();

#endif // CONSOLECURSOR_H_INCLUDED
