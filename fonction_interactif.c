#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>

int getch(void)
{
	int ch;
	struct termios oldt, newt;

	tcgetattr(0, &oldt); //recupere les parametres du terminal
	newt = oldt; //et l'enregistre dans old.
	newt.c_lflag &= ~(ICANON|ECHO); //sortie du mode ECHO et canonique
	tcsetattr(0, TCSANOW, &newt); //fixe les parametres du terminal en lisant newt
	ch = getchar();
	tcsetattr(0, TCSANOW, &oldt); //retablie les parametres par defaults
	return ch;
}