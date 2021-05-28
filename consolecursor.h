#ifndef CONSOLECURSOR_H_INCLUDED
#define CONSOLECURSOR_H_INCLUDED
#include <windows.h>

extern COORD consoleCursorPosition;

/**
 * Pega a coordenada atual do cursor da janela de console,
 *
 * @return uma estrutura COORD que contém 2 inteiros shorts: X para o número da
 *     linha e Y para o número da coluna
 */
COORD getConsoleCursorPosition();

/**
 * Altera a posição atual do cursor da janela de console utilizando as coordena-
 * das salvas na variável global consoleCursorPosition
 */
void mySetConsoleCursorPosition();

#endif // CONSOLECURSOR_H_INCLUDED
