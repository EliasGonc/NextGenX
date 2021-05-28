#ifndef PRINTS_H_INCLUDED
#define PRINTS_H_INCLUDED

/**
 * Imprime um texto com uma quantidade caracteres de espa�os antes deste texto
 *
 * @param string o texto que ser� impresso
 * @param padding a quantidade de caracteres de espa�o impressos antes do texto
 */
void printWithLeftPadding(char string[], short int padding);

/**
 * Imprime linhas em branco com comprimento de 80 caracteres, onde o primeiro e
 * pen�ltimo caracteres s�o barras verticais duplas e o �ltimo � uma quebra de
 * linha
 *
 * @param lines o n�mero de linhas que ser� impresso
 */
void printBlankLines(short int lines);

/**
 * Imprime uma linha horizontal com comprimento de 80 caracteres, onde o primei-
 * ro caracter � um cruzamento de barras duplas por cima, baixo e direita, o pe-
 * n�ltimo � um cruzamento de barras duplas por cima, baixo e esquerda, o �ltimo
 * caractere � uma quebra de linha e os caracteres intermedi�rios s�o barras du-
 * plas horizontais
 *
 * @param blankLinesAfter n�mero de linhas em branco impressas ap�s a linha
 *     horizontal
 * @param upConnectorPosition se n�o zero, um dos caracteres do meio da linha �
 *     um cruzamento de barras duplas por cima, esquerda e direita, na posi��o
 *     do valor desta vari�vel
 */
void printHorizontalLine(short int blankLinesAfter
						, short int upConnectorPosition);

/**
 * Imprime uma linha horizontal com comprimento de 80 caracteres, onde o primei-
 * ro caracter � um cruzamento de barras duplas por cima e direita, o pen�ltimo
 * � um cruzamento de barras duplas por cima e esquerda, o �ltimo � uma quebra
 * de linha e os caracteres intermedi�rios s�o barras duplas horizontais
 */
void printBottomLine();

/**
 * Imprime um texto com comprimento de 80 caracteres, onde o primeiro e �ltimo
 * s�o barras duplas verticais, o segundo � um espa�o, do terceiro em diante � o
 * texto passado para fun��o e depois do �ltimo caractere deste texto at� o pe-
 * n�ltimo caractere s�o espa�os
 *
 * @param string o texto que ser� impresso
 * @param blankLinesAfter o n�mero de linhas em branco que ser� impresso ap�s
 *     esta linha de texto
 * @param isScanfLine se n�o zero, o cursor da janela de console ser� movido
 *     para a posi��o 2 caractere ap�s a �ltima letra do texto impresso
 */
void printLine(char string[], short int blankLinesAfter, short int isScanfLine);

/**
 * Imprime uma mensagem pausada
 *
 * @param message o texto que ser� impresso
 * @param pauseTime qual ser� o tempo de pausa, onde se este valor for zero o
 *     programa aguardar� uma tecla ser pressionada pelo usu�rio
 * @param hasBottomLine se n�o zero, imprime a borda inferior da interface
 */
void printPausedMessage(char message[], float pauseTime
						, short int hasBottomLine);

/**
 * Imprime o resultado de uma fun��o f(x)
 *
 * @param result o resultado da opera��o que foi realizada
 * @param type uma letra representando se � o resultado de uma fun��o ('f'), uma
 *     derivada de uma fun��o ('d') ou uma integral de uma fun��o ('i')
 */
void printResult(double result, char type);

/**
 * Imprime um ret�ngulo formado por caracteres de barras duplas na forma:
 * |-------.
 * | Texto |
 * |---------------------------------------------------------------------------|
 *
 * @param string o texto que ser� impresso dentro do ret�ngulo
 */
void printOptionBox(char string[], short int extraSpaces);

/**
 * Imprime o t�tulo da calculadora
 */
void printTitle();

/**
 * Imprime o menu principal da calculadora
 */
void printMainMenu();

/**
 * Imprime a fun��o f(x) escolhida
 *
 * @param mainMenuOption a fun��o f(x) escolhida no menu principal
 * @param padding a quantidade caracteres de espa�o que preceder� o texto da
 *     fun��o
 */
void printChosenFunction(short int mainMenuOption);

/**
 * Imprime a derivada da fun��o f(x) escolhida
 *
 * @param mainMenuOption a fun��o f(x) escolhida no menu principal
 * @param padding a quantidade caracteres de espa�o que preceder� o texto da
 *     fun��o
 */
void printChosenDerivative(short int mainMenuOption);

/**
 * Imprime a integral indefinida da fun��o f(x) escolhida
 *
 * @param mainMenuOption a fun��o f(x) escolhida no menu principal
 * @param padding a quantidade caracteres de espa�o que preceder� o texto da
 *     fun��o
 */
void printChosenIntegral(short int mainMenuOption, double k);

/**
 * Imprime o submenu principal da calculadora
 *
 * @param mainMenuOption a fun��o f(x) escolhida no menu principal
 */
void printSubMenu(short int mainMenuOption, double k);

/**
 * Imprime mensagens de erros de fun��es de integrais
 *
 * @param mainMenuOption qual fun��o f(x) foi selecionada no menu principal
 * @param errorType o tipo de erro, podendo ser 1 (valor inv�lido) ou 2 (o
 *     o intervalo cont�m um valor inv�lido)
 */
void printIntegralError(short int mainMenuOption, short int errorType);

/**
 * Imprime a tabela ASCII extendida
 */
void printAsciiTable();

#endif // PRINTS_H_INCLUDED
