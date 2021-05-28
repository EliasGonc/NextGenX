#include <stdio.h>
#include "consolecursor.h"
#include "auxfuncs.h"
#include "prints.h"

void printWithLeftPadding(char string[], short int padding) {
	for(short int i = 0; i < padding; i++) {
		printf(" ");
	}
	printf("%s", string);
}

void printBlankLines(short int lines) {
	for(short int i = 0; i < lines; i++) {
		changeLocaleToC();
		printf("%c", 186);
		printWithLeftPadding("\xBA\n", 77);
	}
}

void printHorizontalLine(short int blankLinesAfter
						, short int upConnectorPosition) {
	changeLocaleToC();
	printf("%c", 204);
	if(upConnectorPosition == 0) {
		for(short int i = 0; i < 77; i++) {
			printf("%c", 205);
		}
	} else {
		for(short int i = 0; i < upConnectorPosition; i++) {
			printf("%c", 205);
		}
		printf("%c", 202);
		for(short int i = upConnectorPosition + 1; i < 77; i++) {
			printf("%c", 205);
		}
	}
	printf("%c\n", 185);
	printBlankLines(blankLinesAfter);
}

void printBottomLine() {
	changeLocaleToC();
	printf("%c", 200);
	for(short int i = 0; i < 77; i++) {
		printf("%c", 205);
	}
	printf("%c\n", 188);
}

void printLine(char string[], short int blankLinesAfter, short int isScanfLine){
	short int lineCount = 1, i, charLimit = 75;
	int stringLength = strlen(string);
	while (stringLength > (lineCount-1)*charLimit) {
		changeLocaleToC();
		printf("%c ", 186);
		changeLocaleToPortuguese();
		for(i = (lineCount-1) * charLimit; i < lineCount*charLimit; i++) {
			printf("%c", string[i]);
			if(i == stringLength - 1) {
				if(isScanfLine) {
					consoleCursorPosition = getConsoleCursorPosition();
				}
				break;
			}
		}
		changeLocaleToC();
		printWithLeftPadding(" \xBA\n", charLimit - i
										+ (lineCount-1)*charLimit - 1);
		lineCount++;
	}
	printBlankLines(blankLinesAfter);
}

void printPausedMessage(char message[], float pauseTime
						, short int hasBottomLine) {
	printLine(message, 0, 0);
	if(pauseTime == 0) {
		printBlankLines(1);
		printLine("Aperte qualquer tecla para continuar.", 0, 0);
		if(hasBottomLine) {
			printBottomLine();
		}
		system("pause>nul");
	} else {
		if(hasBottomLine) {
			printBottomLine();
		}
		Sleep(pauseTime);
	}
}

void printResult(double result, char resultType) {
	short int decimalsLength = getNumberOfDecimals(result);
	short int resultLength = getNumberOfDigits(result);
	printHorizontalLine(1, 0);
	changeLocaleToC();
	switch(resultType) {
		case 'f':
			printf("%c %c(x) = %.*lf", 186, 159, decimalsLength, result);
			printWithLeftPadding("\xBA\n", 69 - resultLength);
			break;
		case 'd':
			printf("%c %c'(x) = %.*lf", 186, 159, decimalsLength, result);
			printWithLeftPadding("\xBA\n", 68 - resultLength);
			break;
		case 'i':
			printLine(" b", 0, 0);
			changeLocaleToC();
			printf("%c %c", 186, 244);
			printWithLeftPadding("\xBA\n", 75);
			printf("%c %c f(x) dx = %.*lf", 186, 245, decimalsLength, result);
			printWithLeftPadding("\xBA\n", 64 - resultLength);
			printLine("a", 0, 0);
			break;
	}
	printPausedMessage("", 0, 1);
}

void printOptionBox(char string[], short int extraSpaces) {
	short int stringLentgh = strlen(string), charLimit = 75;
	consoleCursorPosition = getConsoleCursorPosition();
	consoleCursorPosition.X = stringLentgh + 2;
	consoleCursorPosition.Y++;
	changeLocaleToC();
	//Print box top border
	printf("%c", 204);
	for(short int i = 0; i < 1 + stringLentgh + extraSpaces; i++) {
		printf("%c", 205);
	}
	printf("%c", 187);
	printWithLeftPadding("\xBA\n", charLimit - stringLentgh - extraSpaces);
	//Print box middle section
	printf("%c ", 186);
	changeLocaleToPortuguese();
	printf("%s", string);
	for(short int i = 0; i < extraSpaces; i++) {
		printf(" ");
	}
	changeLocaleToC();
	printf("%c", 186);
	printWithLeftPadding("\xBA\n", 75 - stringLentgh - extraSpaces);
	printf("%c", 200);
	// Print botton line
	for(short int i = 0; i < stringLentgh + extraSpaces + 1; i++) {
		printf("%c", 205);
	}
	printf("%c", 202);
	for(short int i = 0; i < charLimit - stringLentgh - extraSpaces; i++) {
		printf("%c", 205);
	}
	printf("%c", 188);
	mySetConsoleCursorPosition();
}

void printTitle() {
	changeLocaleToC();
	system("cls");
	printf("%c", 201);
	for(short int i = 0; i < 77; i++) {
		printf("%c", 205);
	}
	printf("%c\n%c", 187, 186);
	printWithLeftPadding("N E X T   G E N   X", 29);
	printWithLeftPadding("\xBA\n", 29);
	printHorizontalLine(1, 0);
}

void printMainMenu() {
	printTitle();
	printLine("Para operar com um das funções abaixo, digite seu respectivo "
			  "número.", 2, 0);
	printLine("1.  \x83(x) = k", 1, 0);
	printLine("            k", 0, 0);
	printLine("2.  \x83(x) = x", 1, 0);
	printLine("            x", 0, 0);
	printLine("3.  \x83(x) = k", 1, 0);
	printLine("4.  \x83(x) = ln(x)", 1, 0);
	printLine("            1", 0, 0);
	changeLocaleToC();
	printf("%c 5.  %c(x) = %c%c%c", 186, 159, 196, 196, 196);
	printWithLeftPadding("\xBA\n", 62);
	changeLocaleToPortuguese();
	printLine("            x", 1, 0);
	printLine("6.  \x83(x) = sen(x)", 1, 0);
	printLine("7.  \x83(x) = cos(x)", 1, 0);
	printLine("8.  \x83(x) = tg(x)", 1, 0);
	printLine("9.  Alterar precisão máxima", 1, 0);
	printLine("10. Sair", 1, 0);
	printOptionBox("Opção: ", 6);
}

void printChosenFunction(short int mainMenuOption) {
	switch(mainMenuOption) {
		case 1:
			printLine("\x83(x) = k", 1, 0);
			break;
		case 2:
			printLine("        k", 0, 0);
			printLine("\x83(x) = x", 1, 0);
			break;
		case 3:
			printLine("        x", 0, 0);
			printLine("\x83(x) = k", 1, 0);
			break;
		case 4:
			printLine("\x83(x) = ln(x)", 1, 0);
			break;
		case 5:
			printLine("        1", 0, 0);
			changeLocaleToC();
			printf("%c %c(x) = %c%c%c", 186, 159, 196, 196, 196);
			printWithLeftPadding("\xBA\n", 66);
			printLine("        x", 1, 0);
			break;
		case 6:
			printLine("\x83(x) = sen(x)", 1, 0);
			break;
		case 7:
			printLine("\x83(x) = cos(x)", 1, 0);
			break;
		case 8:
			printLine("\x83(x) = tg(x)", 1, 0);
			break;
	}
}

void printChosenDerivative(short int mainMenuOption) {
	switch(mainMenuOption) {
		case 1:
			printLine("\x83'(x) = 0", 1, 0);
			break;
		case 2:
			printLine("          k-1", 0, 0);
			printLine("\x83'(x) = kx", 1, 0);
			break;
		case 3:
			printLine("         x", 0, 0);
			printLine("\x83'(x) = k ln(x)", 1, 0);
			break;
		case 4:
			printLine("         1", 0, 0);
			changeLocaleToC();
			printf("%c %c'(x) = %c%c%c", 186, 159, 196, 196, 196);
			printWithLeftPadding("\xBA\n", 65);
			printLine("         x", 1, 0);
			break;
		case 5:
			printLine("           1", 0, 0);
			changeLocaleToC();
			printf("%c %c'(x) = - %c%c%c", 186, 159, 196, 196, 196);
			printWithLeftPadding("\xBA\n", 63);
			printLine("           x\xB2", 1, 0);
			break;
		case 6:
			printLine("\x83'(x) = cos(x)", 1, 0);
			break;
		case 7:
			printLine("\x83'(x) = -sen(x)", 1, 0);
			break;
		case 8:
			printLine("\x83'(x) = sec\xB2(x)", 1, 0);
			break;
	}
}

void printChosenIntegral(short int mainMenuOption, double k) {
	printLine(" b", 0, 0);
	changeLocaleToC();
	printf("%c %c", 186, 244);
	printWithLeftPadding("\xBA\n", 75);
	printf("%c %c f(x) dx = F(b) - F(a), onde", 186, 245);
	printWithLeftPadding("\xBA\n", 47);
	printLine("a", 1, 0);
	switch(mainMenuOption) {
		case 1:
			printLine("F(x) = kx + C", 1, 0);
			break;
		case 2:
			if(k == -1) {
				printLine("F(x) = ln(|x|) + C", 1, 0);
			} else {
				printLine("         k+1", 0, 0);
				printLine("F(x) = _x___ + C", 1, 0);
				printLine("        k+1", 1, 0);
			}
			break;
		case 3:
			printLine("          x", 0, 0);
			printLine("F(x) = __k__ + C", 1, 0);
			printLine("       ln(k)", 1, 0);
			break;
		case 4:
			printLine("F(x) = ln(|x|) + C", 1, 0);
			break;
		case 5:
			printLine("F(x) = x\xB7[ln(x)-1] + C", 1, 0);
			break;
		case 6:
			printLine("F(x) = -cos(x) + C", 1, 0);
			break;
		case 7:
			printLine("F(x) = sen(x) + C", 1, 0);
			break;
		case 8:
			printLine("F(x) = -ln(|cos(x)|) + C", 1, 0);
			break;
	}
}

void printSubMenu(short int mainMenuOption, double k) {
	short int decimalsLength = getNumberOfDecimals(k);
	short int kLength = getNumberOfDigits(k);
	printTitle();
	printBlankLines(1);
	printChosenFunction(mainMenuOption);
	if(funcUsesK(mainMenuOption)) {
		printf("%c k = %.*lf", 186, decimalsLength, k);
		printWithLeftPadding("\xBA\n", 72 - kLength);
	}
	printBlankLines(1);
	printHorizontalLine(1, 0);
	printLine("1. Calcular a aplicação de um valor na função \x83(x)", 1, 0);
	printLine("2. Calcular a aplicação de um valor na derivada \x83'(x)", 1, 0);
	printLine("3. Calcular a integral definida da função \x83(x) no intervalo "
			  "[a, b]", 1, 0);
	if(funcUsesK(mainMenuOption)) {
		printf("%c 4. Alterar o valor de k (valor atual: %.*lf)", 186
				, decimalsLength, k);
		printWithLeftPadding("\xBA\n", 37 - kLength);
		printBlankLines(1);
		printLine("5. Voltar ao menu anterior", 1, 0);
	} else {
		printLine("4. Voltar ao menu anterior", 1, 0);
	}
	printOptionBox("Opção: ", 6);
}

void printIntegralError(short int mainMenuOption, short int errorType) {
	printBlankLines(1);
	switch(mainMenuOption) {
	case 3:
		printLine("ERRO: A integral desta função não está definida "
				  "para valores de 'k'", 0, 0);
		printPausedMessage("menores ou iguais a zero.", 0, 1);
		break;
	case 4:
		printLine("ERRO: A integral desta função não está definida em "
				  "intervalos que", 0, 0);
		printPausedMessage("incluem o valor zero.", 0, 1);
		/*
		printLine("ERRO: A integral desta função não está definida "
				  "para valores de 'a' e 'b'", 0, 0);
		printPausedMessage("menores ou iguais a zero.", 0, 1);
		*/
		break;
	case 5:
		if(errorType == 1) {
			printLine("ERRO: A integral desta função não está definida "
					  "para valores de 'a' e 'b'", 0, 0);
			printPausedMessage("iguais a zero.", 0, 1);
		} else if(errorType == 2) {
			printLine("ERRO: A integral desta função não está definida em "
					  "intervalos que", 0, 0);
			printPausedMessage("incluem o valor zero.", 0, 1);
		}
		break;
	case 8:
		changeLocaleToC();
		printf("%c ", 186);
		changeLocaleToPortuguese();
		printf("ERRO: A integral não está definida ");
		if(errorType == 1) {
			printf("para valores múltiplos de ");
			changeLocaleToC();
			printf("m*%c + %c/2,", 227, 227);
			printWithLeftPadding("\xBA\n", 5);
			printPausedMessage("onde m pertence aos inteiros.", 0, 1);
		} else if(errorType == 2) {
			changeLocaleToC();
			printf("em intervalos que incluem valores        %c\n%c ", 186, 186);
			changeLocaleToPortuguese();
			printf("múltiplos de ");
			changeLocaleToC();
			printf("m*%c + %c/2, onde m pertence aos inteiros", 227, 227);
			printWithLeftPadding("\xBA\n", 24);
			printBottomLine();
			system("pause>nul");
		}
		break;
	}
}

void printAsciiTable() {
	for(short int i = 0; i < 255; i++) {
		if(i == 10 || i == 13) {
			printf("  ");
		} else {
			printf("%c ", i);
		}
		if((i+1) % 16 == 0) {
			printf("\n");
		}
	}
}
