#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include "fonction_dynamique.h"
			
int main(int argc,char *argv[])
{
	while(1)
	{
		afficherheure();
		compteur();
	}	
	return 0;
}