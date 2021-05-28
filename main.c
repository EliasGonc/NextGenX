#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <math.h>
#include <string.h>

#include "consolecursor.h"
#include "auxfuncs.h"
#include "prints.h"
#include "fx.h"
#include "derivx.h"
#include "integx.h"

int main() {
	short int mainMenuOption;
	double k = 0;
	do {

		printMainMenu();
		scanf("%hd", &mainMenuOption);
		switch(mainMenuOption) {
			case 1:
			case 2:
			case 3:
				getConstantValue(&k, mainMenuOption, 1);
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
				subMenuHandler(mainMenuOption, &k);
				break;
			case 9:
				setPrecision();
				break;
			case 10:
				printHorizontalLine(0, 17);
				printLine("Encerrando...", 0, 0);
				printBottomLine();
				break;
			default:
				printHorizontalLine(0, 17);
				changeLocaleToPortuguese();
				printPausedMessage("Opção inválida.", 0, 1);
		}
	} while(mainMenuOption != 10);

    return 0;
}
