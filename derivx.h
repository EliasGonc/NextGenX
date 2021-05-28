#ifndef DERIVX_H_INCLUDED
#define DERIVX_H_INCLUDED

typedef void (*df)(double, double);

/**
 * Imprime o resultado da derivada da fun��o f(x)=k, isto �, f'(x)=0
 *
 * @param k a constante k (n�o utilizado)
 * @param x a vari�vel x (n�o utilizado)
 */
void constantDeriv(double k, double x);

/**
 * Imprime o resultado da derivada da fun��o f(x)=x^k, isto �, f'(x)=k * x^(k-1)
 *
 * @param k a constante k
 * @param x a vari�vel x
 */
void powerDeriv(double k, double x);

/**
 * Imprime o resultado da derivada da fun��o f(x)=k^x, isto �, f'(x)=k^x * ln(k)
 *
 * @param k a constante k
 * @param x a vari�vel x
 */
void exponentialDeriv(double k, double x);

/**
 * Imprime o resultado da derivada da fun��o f(x)=ln(x), isto �, f'(x)=1/x
 *
 * @param k a constante k (n�o utilizado)
 * @param x a vari�vel x
 */
void naturalLogDeriv(double k, double x);

/**
 * Imprime o resultado da derivada da fun��o f(x)=1/x, isto �, f'(x) = -1/(x^2)
 *
 * @param k a constante k (n�o utilizado)
 * @param x a vari�vel x
 */
void rationalDeriv(double k, double x);

/**
 * Imprime o resultado da derivada da fun��o f(x)=sen(x), isto �, f'(x)=cos(x)
 *
 * @param k a constante k (n�o utilizado)
 * @param x a vari�vel x (em radianos)
 */
void sinDeriv(double k, double x);

/**
 * Imprime o resultado da derivada da fun��o f(x)=cos(x), isto �, f'(x)=-sen(x)
 *
 * @param k a constante k (n�o utilizado)
 * @param x a vari�vel x (em radianos)
 */
void cosDeriv(double k, double x);

/**
 * Imprime o resultado da derivada da fun��o f(x)=tan(x), i.e., f'(x)=1/sec(x)^2
 *
 * @param k a constante k (n�o utilizado)
 * @param x a vari�vel x (em radianos)
 */
void tanDeriv(double k, double x);

/**
 * Solicita do usu�rio o valor da vari�vel x e chama a respectiva fun��o f'(x)
 *
 * @param mainMenuOption a fun��o f(x) escolhida no menu principal
 * @param k a constante k
 */
void derivativeHandler(short int mainMenuOption, double k);

extern df deriv[8];

#endif // DERIVX_H_INCLUDED
