#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include "fonction_statique.h"

int main(int argc, char *argv[])
{
	char path[255];	//Variables indiquant le chemin des images grâce à la variable d'environnement ci-dessous
	char tmp[255];	//

	strcpy(path,getenv("EXIASAVER1_PBM"));	//Récupère la variable d'environnement pour avoir le chemin des images
	if(strcmp(argv[1],"ex1")==0)
	{
		strcpy(tmp,path);		//Stocke la variable d'environnement dans la chaine de caractère tmp
		strcat(tmp,"ex1.pbm");	//Indique quelle image ouvrir et la stocke dans la variable tmp
		statique(tmp);			//Execute la fonction qui va ouvrir l'image avec l'image en paramètre soit tmp
	}
	else if(strcmp(argv[1],"ex2")==0)
	{
		strcpy(tmp,path);
		strcat(tmp,"ex2.pbm");
		statique(tmp);
	}
	else if(strcmp(argv[1],"ex3")==0)
	{
		strcpy(tmp,path);
		strcat(tmp,"ex3.pbm");
		statique(tmp);
	}
	else if(strcmp(argv[1],"ex4")==0)
	{
		strcpy(tmp,path);
		strcat(tmp,"ex4.pbm");
		statique(tmp);
	}
	else if(strcmp(argv[1],"ex5")==0)
	{
		strcpy(tmp,path);
		strcat(tmp,"ex5.pbm");
		statique(tmp);
	}
	return 0;
}