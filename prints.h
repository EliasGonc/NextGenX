#ifndef PRINTS_H_INCLUDED
#define PRINTS_H_INCLUDED

/**
 * Imprime um texto com uma quantidade caracteres de espaços antes deste texto
 *
 * @param string o texto que será impresso
 * @param padding a quantidade de caracteres de espaço impressos antes do texto
 */
void printWithLeftPadding(char string[], short int padding);

/**
 * Imprime linhas em branco com comprimento de 80 caracteres, onde o primeiro e
 * penúltimo caracteres são barras verticais duplas e o último é uma quebra de
 * linha
 *
 * @param lines o número de linhas que será impresso
 */
void printBlankLines(short int lines);

/**
 * Imprime uma linha horizontal com comprimento de 80 caracteres, onde o primei-
 * ro caracter é um cruzamento de barras duplas por cima, baixo e direita, o pe-
 * núltimo é um cruzamento de barras duplas por cima, baixo e esquerda, o último
 * caractere é uma quebra de linha e os caracteres intermediários são barras du-
 * plas horizontais
 *
 * @param blankLinesAfter número de linhas em branco impressas após a linha
 *     horizontal
 * @param upConnectorPosition se não zero, um dos caracteres do meio da linha é
 *     um cruzamento de barras duplas por cima, esquerda e direita, na posição
 *     do valor desta variável
 */
void printHorizontalLine(short int blankLinesAfter
						, short int upConnectorPosition);

/**
 * Imprime uma linha horizontal com comprimento de 80 caracteres, onde o primei-
 * ro caracter é um cruzamento de barras duplas por cima e direita, o penúltimo
 * é um cruzamento de barras duplas por cima e esquerda, o último é uma quebra
 * de linha e os caracteres intermediários são barras duplas horizontais
 */
void printBottomLine();

/**
 * Imprime um texto com comprimento de 80 caracteres, onde o primeiro e último
 * são barras duplas verticais, o segundo é um espaço, do terceiro em diante é o
 * texto passado para função e depois do último caractere deste texto até o pe-
 * núltimo caractere são espaços
 *
 * @param string o texto que será impresso
 * @param blankLinesAfter o número de linhas em branco que será impresso após
 *     esta linha de texto
 * @param isScanfLine se não zero, o cursor da janela de console será movido
 *     para a posição 2 caractere após a última letra do texto impresso
 */
void printLine(char string[], short int blankLinesAfter, short int isScanfLine);

/**
 * Imprime uma mensagem pausada
 *
 * @param message o texto que será impresso
 * @param pauseTime qual será o tempo de pausa, onde se este valor for zero o
 *     programa aguardará uma tecla ser pressionada pelo usuário
 * @param hasBottomLine se não zero, imprime a borda inferior da interface
 */
void printPausedMessage(char message[], float pauseTime
						, short int hasBottomLine);

/**
 * Imprime o resultado de uma função f(x)
 *
 * @param result o resultado da operação que foi realizada
 * @param type uma letra representando se é o resultado de uma função ('f'), uma
 *     derivada de uma função ('d') ou uma integral de uma função ('i')
 */
void printResult(double result, char type);

/**
 * Imprime um retângulo formado por caracteres de barras duplas na forma:
 * |-------.
 * | Texto |
 * |---------------------------------------------------------------------------|
 *
 * @param string o texto que será impresso dentro do retângulo
 */
void printOptionBox(char string[], short int extraSpaces);

/**
 * Imprime o título da calculadora
 */
void printTitle();

/**
 * Imprime o menu principal da calculadora
 */
void printMainMenu();

/**
 * Imprime a função f(x) escolhida
 *
 * @param mainMenuOption a função f(x) escolhida no menu principal
 * @param padding a quantidade caracteres de espaço que precederá o texto da
 *     função
 */
void printChosenFunction(short int mainMenuOption);

/**
 * Imprime a derivada da função f(x) escolhida
 *
 * @param mainMenuOption a função f(x) escolhida no menu principal
 * @param padding a quantidade caracteres de espaço que precederá o texto da
 *     função
 */
void printChosenDerivative(short int mainMenuOption);

/**
 * Imprime a integral indefinida da função f(x) escolhida
 *
 * @param mainMenuOption a função f(x) escolhida no menu principal
 * @param padding a quantidade caracteres de espaço que precederá o texto da
 *     função
 */
void printChosenIntegral(short int mainMenuOption, double k);

/**
 * Imprime o submenu principal da calculadora
 *
 * @param mainMenuOption a função f(x) escolhida no menu principal
 */
void printSubMenu(short int mainMenuOption, double k);

/**
 * Imprime mensagens de erros de funções de integrais
 *
 * @param mainMenuOption qual função f(x) foi selecionada no menu principal
 * @param errorType o tipo de erro, podendo ser 1 (valor inválido) ou 2 (o
 *     o intervalo contém um valor inválido)
 */
void printIntegralError(short int mainMenuOption, short int errorType);

/**
 * Imprime a tabela ASCII extendida
 */
void printAsciiTable();

#endif // PRINTS_H_INCLUDED
