#ifndef DERIVX_H_INCLUDED
#define DERIVX_H_INCLUDED

typedef void (*df)(double, double);

/**
 * Imprime o resultado da derivada da função f(x)=k, isto é, f'(x)=0
 *
 * @param k a constante k (não utilizado)
 * @param x a variável x (não utilizado)
 */
void constantDeriv(double k, double x);

/**
 * Imprime o resultado da derivada da função f(x)=x^k, isto é, f'(x)=k * x^(k-1)
 *
 * @param k a constante k
 * @param x a variável x
 */
void powerDeriv(double k, double x);

/**
 * Imprime o resultado da derivada da função f(x)=k^x, isto é, f'(x)=k^x * ln(k)
 *
 * @param k a constante k
 * @param x a variável x
 */
void exponentialDeriv(double k, double x);

/**
 * Imprime o resultado da derivada da função f(x)=ln(x), isto é, f'(x)=1/x
 *
 * @param k a constante k (não utilizado)
 * @param x a variável x
 */
void naturalLogDeriv(double k, double x);

/**
 * Imprime o resultado da derivada da função f(x)=1/x, isto é, f'(x) = -1/(x^2)
 *
 * @param k a constante k (não utilizado)
 * @param x a variável x
 */
void rationalDeriv(double k, double x);

/**
 * Imprime o resultado da derivada da função f(x)=sen(x), isto é, f'(x)=cos(x)
 *
 * @param k a constante k (não utilizado)
 * @param x a variável x (em radianos)
 */
void sinDeriv(double k, double x);

/**
 * Imprime o resultado da derivada da função f(x)=cos(x), isto é, f'(x)=-sen(x)
 *
 * @param k a constante k (não utilizado)
 * @param x a variável x (em radianos)
 */
void cosDeriv(double k, double x);

/**
 * Imprime o resultado da derivada da função f(x)=tan(x), i.e., f'(x)=1/sec(x)^2
 *
 * @param k a constante k (não utilizado)
 * @param x a variável x (em radianos)
 */
void tanDeriv(double k, double x);

/**
 * Solicita do usuário o valor da variável x e chama a respectiva função f'(x)
 *
 * @param mainMenuOption a função f(x) escolhida no menu principal
 * @param k a constante k
 */
void derivativeHandler(short int mainMenuOption, double k);

extern df deriv[8];

#endif // DERIVX_H_INCLUDED
