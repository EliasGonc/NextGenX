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
 * Verifica se a função f(x) selecionada possui uma constante k
 *
 * @param mainMenuOption a função f(x) escolhida no menu principal
 *
 * @return retorna 1 se a funçao f(x) possui uma constante k ou 0 caso contrário
 */
short int funcUsesK(short int mainMenuOption);

/**
 * Verifica a quantidade de dígitos de um número inteiro. Se o número for nega-
 * tivo, é adicionado 1 ao resultado.
 *
 * @param number o número inteiro passado pelo usuário
 *
 * @return o número do dígitos do número inteiro passado pelo usuário
 */
int getNumberOfDigits(double number);

/**
 * Verifica a quantidade de dígitos depois da vírgula de um número real.
 *
 * @param number o número inteiro passado pelo usuário
 *
 * @return o número do dígitos do número inteiro passado pelo usuário
 */
int getNumberOfDecimals(double number);

/**
 * Converte um ângulo em graus para radianos
 *
 * @param degreeValue o valor do ângulo em graus
 *
 * @return o valor do ângulo em radianos
 */
double degreeToRadian(double degreeValue);

/**
 * Converte um ângulo em radianos para graus
 *
 * @param radianValue o valor do ângulo em radianos
 *
 * @return o valor do ângulo em graus
 */
double radianToDegree(double radianValue);

/**
 * Solicita do usuário o valor da constante k
 *
 * @param[out] k a constante k
 * @param[in] mainMenuOption a função f(x) escolhida no menu principal
 * @param[in] isNewValue se não zero, representa que o usuário está alterando o
 *     valor de k, alterando o texto apresentado
 */
void getConstantValue(double *k, short int mainMenuOption, short int isNewValue);

/**
 * Solicita do usuário o valor de uma variável (x, a, b etc.)
 * @param[out] x a variável em questão
 * @param[in] mainMenuOption a função f(x) escolhida no menu principal
 **/
void getVariableValue(double *x, char *varName, short int mainMenuOption
					, short int isInRadians);

/**
 * Faz o controle das opções do submenu principal
 *
 * @param[in] mainMenuOption a função f(x) escolhida no menu principal
 * @param[out] k a constante k
 */
void subMenuHandler(short int mainMenuOption, double *k);

void setPrecision();

extern short int AUX_PRECISION;

#endif // AUXFUNCS_H_INCLUDED
