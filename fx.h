#ifndef FX_H_INCLUDED
#define FX_H_INCLUDED

typedef void (*f)(double, double);

/**
 * Imprime o resultado da fun��o f(x)=k
 *
 * @param k a constante k
 * @param x a vari�vel x (n�o utilizado)
 */
void constantFunc(double k, double x);

/**
 * Imprime o resultado da fun��o f(x)=x^k
 *
 * @param k a constante k
 * @param x a vari�vel x
 */
void powerFunc(double k, double x);

/**
 * Imprime o resultado da fun��o f(x)=k^x
 *
 * @param k a constante k
 * @param x a vari�vel x
 */
void exponentialFunc(double k, double x);

/**
 * Imprime o resultado da fun��o f(x)=ln(x)
 *
 * @param k a constante k (n�o utilizado)
 * @param x a vari�vel x
 */
void naturalLogFunc(double k, double x);

/**
 * Imprime o resultado da fun��o f(x)=1/x
 *
 * @param k a constante k (n�o utilizado)
 * @param x a vari�vel x
 */
void rationalFunc(double k, double x);

/**
 * Imprime o resultado da fun��o f(x)=sen(x)
 *
 * @param k a constante k (n�o utilizado)
 * @param x a vari�vel x (em graus)
 */
void sinFunc(double k, double x);

/**
 * Imprime o resultado da fun��o f(x)=cos(x)
 *
 * @param k a constante k (n�o utilizado)
 * @param x a vari�vel x (em graus)
 */
void cosFunc(double k, double x);

/**
 * Imprime o resultado da fun��o f(x)=tan(x)
 *
 * @param k a constante k (n�o utilizado)
 * @param x a vari�vel x (em graus)
 */
void tanFunc(double k, double x);

/**
 * Solicita do usu�rio o valor da vari�vel x e chama a respectiva fun��o f(x)
 *
 * @param mainMenuOption a fun��o f(x) escolhida no menu principal
 * @param k a constante k
 */
void functionHandler(short int mainMenuOption, double k);

extern f func[8];

#endif // FX_H_INCLUDED
