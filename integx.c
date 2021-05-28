#include <stdio.h>
#include <math.h>
#include "integx.h"
#include "consolecursor.h"
#include "prints.h"
#include "auxfuncs.h"

void constantInteg(double k, double a, double b) {
	if(a == b) {
		printResult(0, 'i');
	} else {
		printResult(k * (b-a), 'i');
	}
}

void powerInteg(double k, double a, double b) {
	if(a == b) {
		printResult(0, 'i');
	} else if(k == -1) {
		rationalInteg(k, a, b);
	} else {
		printResult((pow(b, k+1) - pow(a, k+1)) / (k+1), 'i');
	}
}

void exponentialInteg(double k, double a, double b) {
	if(k <= 0) {
		printIntegralError(3, 1);
	} else if(a == b) {
		printResult(0, 'i');
	} else {
		printResult((pow(k, b) - pow(k, a)) / log(k), 'i');
	}
}

void naturalLogInteg(double k, double a, double b) {
	if((a <= 0 && b >= 0) || (a >= 0 && b <= 0)) {
		printIntegralError(4, 1);
		return;
	} else if(a == b) {
		printResult(0, 'i');
		return;
	}
	printResult(b*(log(b)-1) - a*(log(a)-1), 'i');
}

void rationalInteg(double k, double a, double b) {
	if(a == 0 || b == 0) {
		printIntegralError(5, 1);
	} else if((a < 0 && b > 0) || (a > 0 && b < 0)) {
		printIntegralError(5, 2);
	} else if(a == b) {
		printResult(0, 'i');
	} else {
		printResult(log(fabs(b)) - log(fabs(a)), 'i');
	}
}

void sinInteg(double k, double a, double b) {
	if(a == b) {
		printResult(0, 'i');
	} else {
		printResult(cos(a) - cos(b), 'i');
	}
}

void cosInteg(double k, double a, double b) {
	if(a == b) {
		printResult(0, 'i');
	} else {
		printResult(sin(b) - sin(a), 'i');
	}
}

void tanInteg(double k, double a, double b) {
	double cos_a = cos(a), cos_b = cos(b);
	if(fabs(cos_a) < 0.0001 || fabs(cos_b) < 0.0001) {
		printIntegralError(8, 1);
		return;
	} else if(fabs(a-b) > M_PI ||
			((cos_a < 0 && cos_b > 0) || (cos_a > 0 && cos_b < 0))) {
		printIntegralError(8, 2);
		return;
	} else if(a == b) {
		printResult(0, 'i');
		return;
	}
	printResult(log(fabs(cos_a)) - log(fabs(cos_b)), 'i');
}

void integralHandler(short int mainMenuOption, double k) {
	double a, b;
	consoleCursorPosition.X = 0;
	consoleCursorPosition.Y += 2;
	mySetConsoleCursorPosition(consoleCursorPosition);
	printBlankLines(1);
	printChosenIntegral(mainMenuOption, k);
	printBlankLines(1);
	getVariableValue(&a, "a", mainMenuOption, 1);
	getVariableValue(&b, "b", mainMenuOption, 1);
	integ[mainMenuOption-1](k, a, b);
}

integf integ[8] = {&constantInteg, &powerInteg, &exponentialInteg
			  , &naturalLogInteg, &rationalInteg, &sinInteg, &cosInteg
			  , &tanInteg};
