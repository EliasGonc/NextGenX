#ifndef INTEGX_H_INCLUDED
#define INTEGX_H_INCLUDED

typedef void (*integf)(double, double, double);

/**
 * Imprime o resultado da integral da função f(x) = k definida no intervalo
 * [a, b], isto é, F(b)-F(a), onde F(x) = k*x
 *
 * @param k a constante k
 * @param a o limite inferior do intervalo
 * @param x o limite superior do intervalo
 */
void constantInteg(double k, double a, double b);

/**
 * Imprime o resultado da integral da função f(x) = x^k definida no intervalo
 * [a, b], isto é, F(b)-F(a), onde F(x) = (x^(k+1)) / (k+1)
 *
 * @param k a constante k
 * @param a o limite inferior do intervalo
 * @param x o limite superior do intervalo
 */
void powerInteg(double k, double a, double b);

/**
 * Imprime o resultado da integral da função f(x) = k^x definida no intervalo
 * [a, b], isto é, F(b)-F(a), onde F(x) = (k^x) / ln(k)
 *
 * @param k a constante k
 * @param a o limite inferior do intervalo
 * @param x o limite superior do intervalo
 */
void exponentialInteg(double k, double a, double b);

/**
 * Imprime o resultado da integral da função f(x) = ln(x) definida no intervalo
 * [a, b], isto é, F(b)-F(a), onde F(x) = x*(ln(x)-1)
 *
 * @param k a constante k (não utilizado)
 * @param a o limite inferior do intervalo
 * @param x o limite superior do intervalo
 */
void naturalLogInteg(double k, double a, double b);

/**
 * Imprime o resultado da integral da função f(x) = 1/x definida no intervalo
 * [a, b], isto é, F(b)-F(a), onde F(x) = ln(|x|)
 *
 * @param k a constante k (não utilizado)
 * @param a o limite inferior do intervalo
 * @param x o limite superior do intervalo
 */
void rationalInteg(double k, double a, double b);

/**
 * Imprime o resultado da integral da função f(x) = sen(x) definida no intervalo
 * [a, b], isto é, F(b)-F(a), onde F(x) = -cos(x)
 *
 * @param k a constante k (não utilizado)
 * @param a o limite inferior do intervalo
 * @param x o limite superior do intervalo
 */
void sinInteg(double k, double a, double b);

/**
 * Imprime o resultado da derivada da função f(x) = cos(x) definida no intervalo
 * [a, b], isto é, F(b)-F(a), onde F(x) = sen(x)
 *
 * @param k a constante k (não utilizado)
 * @param a o limite inferior do intervalo
 * @param x o limite superior do intervalo
 */
void cosInteg(double k, double a, double b);

/**
 * Imprime o resultado da integral da função f(x) = tan(x) definida no intervalo
 * [a, b], isto é, F(b)-F(a), onde F(x) = -ln(|cos(x)|)
 *
 * @param k a constante k (não utilizado)
 * @param x a variável x (em radianos)
 * @param a o limite inferior do intervalo
 * @param x o limite superior do intervalo
 */
void tanInteg(double k, double a, double b);

/**
 * Solicita do usuário o valor da variável x e chama a respectiva função I(x)
 *
 * @param mainMenuOption a função f(x) escolhida no menu principal
 * @param k a constante k
 */
void integralHandler(short int mainMenuOption, double k);

extern integf integ[8];

#endif // INTEGX_H_INCLUDED
