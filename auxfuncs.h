#ifndef AUXFUNCS_H_INCLUDED
#define AUXFUNCS_H_INCLUDED

/**
 * Altera o locale para Portuguese.Brazil.1252
 */
void changeLocaleToPortuguese();

/**
 * Altera o locale para C
 */
void changeLocaleToC();

/**
 * Verifica se a fun��o f(x) selecionada possui uma constante k
 *
 * @param mainMenuOption a fun��o f(x) escolhida no menu principal
 *
 * @return retorna 1 se a fun�ao f(x) possui uma constante k ou 0 caso contr�rio
 */
short int funcUsesK(short int mainMenuOption);

/**
 * Verifica a quantidade de d�gitos de um n�mero inteiro. Se o n�mero for nega-
 * tivo, � adicionado 1 ao resultado.
 *
 * @param number o n�mero inteiro passado pelo usu�rio
 *
 * @return o n�mero do d�gitos do n�mero inteiro passado pelo usu�rio
 */
int getNumberOfDigits(double number);

/**
 * Verifica a quantidade de d�gitos depois da v�rgula de um n�mero real.
 *
 * @param number o n�mero inteiro passado pelo usu�rio
 *
 * @return o n�mero do d�gitos do n�mero inteiro passado pelo usu�rio
 */
int getNumberOfDecimals(double number);

/**
 * Converte um �ngulo em graus para radianos
 *
 * @param degreeValue o valor do �ngulo em graus
 *
 * @return o valor do �ngulo em radianos
 */
double degreeToRadian(double degreeValue);

/**
 * Converte um �ngulo em radianos para graus
 *
 * @param radianValue o valor do �ngulo em radianos
 *
 * @return o valor do �ngulo em graus
 */
double radianToDegree(double radianValue);

/**
 * Solicita do usu�rio o valor da constante k
 *
 * @param[out] k a constante k
 * @param[in] mainMenuOption a fun��o f(x) escolhida no menu principal
 * @param[in] isNewValue se n�o zero, representa que o usu�rio est� alterando o
 *     valor de k, alterando o texto apresentado
 */
void getConstantValue(double *k, short int mainMenuOption, short int isNewValue);

/**
 * Solicita do usu�rio o valor de uma vari�vel (x, a, b etc.)
 * @param[out] x a vari�vel em quest�o
 * @param[in] mainMenuOption a fun��o f(x) escolhida no menu principal
 **/
void getVariableValue(double *x, char *varName, short int mainMenuOption
					, short int isInRadians);

/**
 * Faz o controle das op��es do submenu principal
 *
 * @param[in] mainMenuOption a fun��o f(x) escolhida no menu principal
 * @param[out] k a constante k
 */
void subMenuHandler(short int mainMenuOption, double *k);

void setPrecision();

extern short int AUX_PRECISION;

#endif // AUXFUNCS_H_INCLUDED
