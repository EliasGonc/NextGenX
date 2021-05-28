#ifndef FX_H_INCLUDED
#define FX_H_INCLUDED

typedef void (*f)(double, double);

/**
 * Imprime o resultado da função f(x)=k
 *
 * @param k a constante k
 * @param x a variável x (não utilizado)
 */
void constantFunc(double k, double x);

/**
 * Imprime o resultado da função f(x)=x^k
 *
 * @param k a constante k
 * @param x a variável x
 */
void powerFunc(double k, double x);

/**
 * Imprime o resultado da função f(x)=k^x
 *
 * @param k a constante k
 * @param x a variável x
 */
void exponentialFunc(double k, double x);

/**
 * Imprime o resultado da função f(x)=ln(x)
 *
 * @param k a constante k (não utilizado)
 * @param x a variável x
 */
void naturalLogFunc(double k, double x);

/**
 * Imprime o resultado da função f(x)=1/x
 *
 * @param k a constante k (não utilizado)
 * @param x a variável x
 */
void rationalFunc(double k, double x);

/**
 * Imprime o resultado da função f(x)=sen(x)
 *
 * @param k a constante k (não utilizado)
 * @param x a variável x (em graus)
 */
void sinFunc(double k, double x);

/**
 * Imprime o resultado da função f(x)=cos(x)
 *
 * @param k a constante k (não utilizado)
 * @param x a variável x (em graus)
 */
void cosFunc(double k, double x);

/**
 * Imprime o resultado da função f(x)=tan(x)
 *
 * @param k a constante k (não utilizado)
 * @param x a variável x (em graus)
 */
void tanFunc(double k, double x);

/**
 * Solicita do usuário o valor da variável x e chama a respectiva função f(x)
 *
 * @param mainMenuOption a função f(x) escolhida no menu principal
 * @param k a constante k
 */
void functionHandler(short int mainMenuOption, double k);

extern f func[8];

#endif // FX_H_INCLUDED
