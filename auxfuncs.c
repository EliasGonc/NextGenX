#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "consolecursor.h"
#include "prints.h"
#include "auxfuncs.h"
#include "fx.h"
#include "derivx.h"
#include "integx.h"

void changeLocaleToPortuguese() {
	setlocale(LC_ALL, "Portuguese_Brazil.1252");
}

void changeLocaleToC() {
	setlocale(LC_ALL, "C");
}

short int funcUsesK(short int mainMenuOption) {
	if(mainMenuOption >= 1 && mainMenuOption <= 3) {
		return 1;
	}
	return 0;
}

int getNumberOfIntegerDigits(double number) {
	int digits = (number < 0) ? 2 : 1;
	while(number > 10) {
		number /= 10;
		digits++;
	}
	return digits;
}

int getNumberOfDecimals(double number) {
	short int digits = AUX_PRECISION;
	int decimals;
	if(AUX_PRECISION == 0) {
		return 0;
	}
	decimals = round(number * pow(10, AUX_PRECISION))
			 - floor(number) * pow(10, AUX_PRECISION);
	if(decimals == 0) return 0;
	while(decimals > 0) {
		if(decimals % 10 == 0) {
			digits--;
			decimals /= 10;
		} else {
			break;
		}
	}
	return digits;
}

int getNumberOfDigits(double number) {
	short int integerPartLength = getNumberOfIntegerDigits(number);
	short int decimalsLength = getNumberOfDecimals(number);
	return integerPartLength + decimalsLength + (decimalsLength > 0 ? 1 : 0);
}

double degreeToRadian(double degreeValue) {
	return M_PI * degreeValue / 180;
}

double radianToDegree(double radianValue) {
	return 180 * radianValue / M_PI;
}

void getConstantValue(double *k, short int mainMenuOption, short int isNewValue)  {
	printTitle();
	printChosenFunction(mainMenuOption);
	if(isNewValue) {
		printLine("A função escolhida necessita de elementos para sua "
				  "construção.", 1, 0);
		printLine("Insira o valor de k desejado: ", 0, 1);
	} else {
		printLine("Digite o novo valor de k desejado: ", 0, 1);
	}
	printBottomLine();
	mySetConsoleCursorPosition();
	scanf("%lf", k);
}

void getVariableValue(double *x, char *varName, short int mainMenuOption
					, short int isInRadians) {
	char text[36] = "Digite o valor de \0";
	strcat(text, varName);
	if(mainMenuOption >= 6 && mainMenuOption <= 8) {
		if(isInRadians) {
			strcat(text, " (em radianos)");
		} else {
			strcat(text, " (em graus)");
		}
	}
	strcat(text, ": \0");
	printLine(text, 0, 1);
	printBottomLine();
	mySetConsoleCursorPosition();
	scanf("%lf", x);
}

void subMenuHandler(short int mainMenuOption, double *k) {
	short int functionMenuOption;
	do {
		printSubMenu(mainMenuOption, *k);
		scanf("%hd", &functionMenuOption);
		printHorizontalLine(0, 1+strlen("Opção: ")+6);
		switch(functionMenuOption) {
			case 1:
				functionHandler(mainMenuOption, *k);
				break;
			case 2:
				derivativeHandler(mainMenuOption, *k);
				break;
			case 3:
				integralHandler(mainMenuOption, *k);
				break;
			case 4:
				if(funcUsesK(mainMenuOption)) {
					getConstantValue(k, mainMenuOption, 0);
					break;
				} else {
					printPausedMessage("Retornando ao menu principal...", 0, 1);
					return;
				}
			case 5:
				if(funcUsesK(mainMenuOption)) {
					printPausedMessage("Retornando ao menu principal...", 0, 1);
					return;
				} else  {
					printPausedMessage("Opção inválida.", 0, 1);
					break;
				}
			default:
				printPausedMessage("Opção inválida.", 0, 1);
		}
	} while(functionMenuOption != 4 + funcUsesK(mainMenuOption));
}

void setPrecision() {
	printTitle();
	changeLocaleToC();
	printf("%c ", 186);
	changeLocaleToPortuguese();
	printf("Precisão atual: %hd", AUX_PRECISION);
	changeLocaleToC();
	printWithLeftPadding("\xBA\n", 60-getNumberOfIntegerDigits(AUX_PRECISION));
	printBlankLines(1);
	printLine("Digite a nova precisão: ", 1, 1);
	printBottomLine();
	mySetConsoleCursorPosition();
	scanf("%hd", &AUX_PRECISION);
}

short int AUX_PRECISION = 6;
