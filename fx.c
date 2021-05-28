#include <stdio.h>
#include <math.h>
#include "consolecursor.h"
#include "prints.h"
#include "auxfuncs.h"
#include "fx.h"

void constantFunc(double k, double x) {
	printResult(k, 'f');
}

void powerFunc(double k, double x) {
	printResult(pow(x, k), 'f');
}

void exponentialFunc(double k, double x) {
	printResult(pow(k, x), 'f');
}

void naturalLogFunc(double k, double x) {
	if(x <= 0) {
		printBlankLines(1);
		printPausedMessage("ERRO: O valor de x deve ser maior que zero.", 0, 1);
	} else {
		printResult(log(x), 'f');
	}
}

void rationalFunc(double k, double x) {
	if(x == 0) {
		printBlankLines(1);
		printPausedMessage("ERRO: O valor de x deve ser diferente de zero.",0,1);
	} else {
		printResult(1/x, 'f');
	}
}

void sinFunc(double k, double x) {
	printResult(sin(degreeToRadian(x)), 'f');
}

void cosFunc(double k, double x) {
	printResult(cos(degreeToRadian(x)), 'f');
}

void tanFunc(double k, double x) {
	int intX = (int) x;
	if((intX % 90 == 0) && (intX % 180 != 0)) {
		printBlankLines(1);
		printLine("ERRO: A função não está definida para valores de x múltiplos"
				  "de 180 + 90*m,", 0, 0);
		printPausedMessage("onde m pertence aos inteiros.", 0, 1);
	} else {
		printResult(tan(degreeToRadian(x)), 'f');
	}
}

void functionHandler(short int mainMenuOption, double k) {
	double x;
	consoleCursorPosition.X = 0;
	consoleCursorPosition.Y += 2;
	mySetConsoleCursorPosition(consoleCursorPosition);
	getVariableValue(&x, "x", mainMenuOption, 0);
	func[mainMenuOption-1](k, x);
}

f func[8] = {&constantFunc, &powerFunc, &exponentialFunc, &naturalLogFunc
			, &rationalFunc, &sinFunc, &cosFunc, &tanFunc};
