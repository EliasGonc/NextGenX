#include <stdio.h>
#include <math.h>
#include "consolecursor.h"
#include "auxfuncs.h"
#include "prints.h"
#include "derivx.h"

void constantDeriv(double k, double x) {
	printResult(0, 'd');
}

void powerDeriv(double k, double x) {
	printResult(k * pow(x, (k-1)), 'd');
}

void exponentialDeriv(double k, double x) {
	if(k == 0) {
		printBlankLines(1);
		printPausedMessage("ERRO: O valor de k deve ser diferente de zero. ",0,1);
	} else {
		printResult(pow(k, x) * log(fabs(k)), 'd');
	}
}

void naturalLogDeriv(double k, double x) {
	if(x == 0) {
		printBlankLines(1);
		printPausedMessage("ERRO: O valor de x deve ser diferente de zero.",0,1);
	} else {
		printResult(1/x, 'd');
	}
}

void rationalDeriv(double k, double x) {
	if(x == 0) {
		printBlankLines(1);
		printPausedMessage("ERRO: O valor de x deve ser diferente de zero.",0,1);
	} else {
		printResult(-1/pow(x, 2), 'd');
	}
}

void sinDeriv(double k, double x) {
	printResult(cos(x), 'd');
}

void cosDeriv(double k, double x) {
	printResult(-1 * sin(x), 'd');
}

void tanDeriv(double k, double x) {
	double result = pow(1/cos(x), 2);
	if(result > 1000000) {
		printBlankLines(1);
		changeLocaleToC();
		printf("%c ", 186);
		changeLocaleToPortuguese();
		printf("ERRO: \x83'(x) não está definida para valores de x múltiplos ");
		changeLocaleToC();
		printf("de m*%c + %c/2,     %c\n", 227, 227, 186);
		printPausedMessage("onde m pertence aos inteiros.", 0, 1);
	} else {
		printResult(result, 'd');
	}
}

void derivativeHandler(short int mainMenuOption, double k) {
	double x;
	consoleCursorPosition.X = 0;
	consoleCursorPosition.Y += 2;
	mySetConsoleCursorPosition(consoleCursorPosition);
	printBlankLines(1);
	printChosenDerivative(mainMenuOption);
	printBlankLines(1);
	getVariableValue(&x, "x", mainMenuOption, 1);
	deriv[mainMenuOption-1](k, x);
}

df deriv[8] = {&constantDeriv, &powerDeriv, &exponentialDeriv, &naturalLogDeriv
			, &rationalDeriv, &sinDeriv, &cosDeriv, &tanDeriv};
