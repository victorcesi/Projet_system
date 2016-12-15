#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <sys/wait.h>

//recupération des touches clavier.
    char fin()
{
    char buf=0; 
    struct termios old={0}; //cree la structure old
    // fflush(stdout);
    if(tcgetattr(0, &old)<0)
    /*recupere les parametres du terminal 
    et l'enregistre dans old (structure de
    termios).*/
        perror("tcsetattr()");
        // affiche une erreur systeme ou un succes.

    old.c_lflag&=~ICANON;
    /*Sortie de mode canonique.*/
    old.c_lflag&=~ECHO;

    if(tcsetattr(0, TCSANOW, &old)<0)
    /*fixe les parametres du terminal en lisant 
    le contenu de old (avec modification immediate).*/
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
    //lit une valeur entré dans le terminal.
        perror("read()");

    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
    /*fixe les parametres du terminal en lisant 
    le contenu de old (restoration des parametres de base.*/
        perror ("tcsetattr ~ICANON");
    system("clear");
    return buf;
}

int statique(char *image)
{
	int longueur;
	int largeur;
	char ligne[255];
	char temp[255];
	FILE* fichier=NULL;
	
	int f;

	fichier = fopen(image,"r+");
	f=fork();
	if(f!=0){
		wait(NULL);
	}
	else
	{

		for (int i = 0; i < 3; ++i)
		{
			fgets(ligne,255,fichier);  	//aller a la 3eme ligne
		}
		strcpy(temp,strtok(ligne," "));		//recupere le premier mot de la chaine de caractere
		longueur=atoi(temp);				//convertir la chaine de caractere en entier
		strcpy(temp,strtok(NULL," "));		//recupere le mot suivant
		largeur=atoi(temp);					//convertir la chaine de caractere en entier

		system("clear");					

		for (int i = 0; i < ((24-largeur)/2); ++i)		//centre l'image sur la hauteur de l'ecran 
		{
			printf("\n");
		}
		for (int i = 0; i < largeur; ++i)				// pour chaque ligne
		{

			fgets(ligne,255,fichier);						//recupere le contenu du fichier et l'enregistre dans ligne
			strcpy(temp,strtok(ligne," "));


			for (int x = 0; x < ((80-longueur)/2); ++x)		//centre l'image sur la longueur de l'ecran
			{
				printf(" ");
			}



			if (strcmp(temp,"0")==0)		//compare 2 chaines de caractere temp et 0
			{
				printf(" ");		// si elles correspondent, on rempplace le 0 par un espace 
			}
			else if(strcmp(temp,"1")==0)		//compare 2 chaines de caractere temp et 1
			{
				printf("\u2588");		// si elles correspondent, on affiche un caractere ascii a la place du 1
			}
			for (int j = 1; j < longueur; ++j)
			{	
				strcpy(temp,strtok(NULL," "));		//
				if (strcmp(temp,"0")==0)			//
				{									//
					printf(" ");					//
				}									//on repete l'operation precedente pour completer la ligne
				else if(strncmp(temp,"1",1)==0)		//
				{									//
					printf("\u2588");				//
				}									//
			}
			printf("\n");
		}
		fclose(fichier);
		for (int i = 0; i < ((24-largeur)/2); ++i)		//centre l'image sur la hauteur de l'ecran 
		{
			printf("\n");
		}
		fin();
	}
}