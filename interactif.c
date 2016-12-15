#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include "fonction_interactif.h"

int main ()
{
	char temp[255];
	char caractere[255];
	char path[255];
	char aviong[255];
	char aviond[255];
	char avionh[255];
	char avionb[255];
	int x,y,i, nombre, coordX, coordY;
	int j=0;
	int tableau [25][80]; 
	FILE* fichier=NULL;
	srand(time(NULL));
	int randomsens,n;
	int savefrappe;
	int frappe;

	strcpy(path,getenv("EXIASAVER3_PBM"));  // on recupère la variable d'environnement

	strcpy(aviond,path);
	strcat(aviond,"avion_droite.pbm");
	strcpy(aviong,path);
	strcat(aviong,"avion_gauche.pbm");
	strcpy(avionh,path);
	strcat(avionh,"avion_haut.pbm");
	strcpy(avionb,path);
	strcat(avionb,"avion_bas.pbm");

	coordX=rand()%(80-0)+0; // on donne une coordonnées aléatoire à X pour afficher l'avion
	coordY=rand ()%(21-1)+1;

	for (y=0; y<25; y++)
	{
		for (x=0; x<80; x++)
		{
			tableau [y][x]=0; // on remplit la console avec des 0
		}
	}
	randomsens=rand()%(4-0)+0;	//on donne un sens aléatoire à la position de base de l'avion
	switch (randomsens){
		case 0:
		fichier = fopen(aviond, "r+");
		break;
		case 1:
		fichier = fopen(aviong, "r+");
		break;
		case 2:
		fichier = fopen(avionb, "r+");
		break;
		case 3:
		fichier = fopen(avionh, "r+");
		break;
	}

	for (i=0; i<3; i++) //va a la 3eme ligne du fichier
	{
		fgets(temp, 255 , fichier);
	}

	for (int i = 0; i < 6; ++i)		// lit le fichier de la 3eme ligne du fichier a la 6eme		
	{
		fgets(temp,255,fichier); // lit le contenu du fichier et le stocke dans la variable temp
		strcpy(caractere,strtok(temp," ")); //copie dans caractere le contenu du fichier jusqu'au premier espace
		nombre= atoi(caractere); //transforme le contenu de la variable caractere en un entier er le stocke dans nombre
		tableau[coordY+i][coordX]=nombre; //se positionne aux coordonnées aleatoires et stocke la variable nombre dedans
		for (j=1; j<6; j++)
		{						
			strcpy(caractere,strtok(NULL," ")); // copie le contenu apres l'espace dans la variable caractere
			nombre= atoi(caractere);
			tableau[coordY+i][coordX+j]=nombre;
		}
	}
	fclose(fichier); //ferme le fichier
	
	for (y=1; y<24; y++)
	{
		for (x=0; x<80; x++) //on lit la totalité de la commande
		{
			if(tableau[y][x]==0){
				printf(" "); // si il y a des 0, on les remplace par un caractere espace
			}
			else {
				printf("\u2588"); //sinon on affiche un carré blanc
			}

		}
		printf("\n"); //on passe à la ligne suivante
	}

	while(n!=1){
		frappe=getch(); // on met la fonction getch () dans la variable frappe
		switch(frappe)
		{
			case'z':			//si on apuie sur la touche z
			coordY--;			// on décrémente coordY de 1
			savefrappe=frappe;	// on enregistre la dernière touche
			fichier = fopen(avionh, "r+");	// on ouvre le fichier pour changer la position de l'avion
			break;

			case's':		//si on appuie sur la touche z
			coordY++;	//on incrémente coordY de 1
			savefrappe=frappe;
			fichier = fopen(avionb, "r+");
			break;

			case'q':			
			coordX--;
			savefrappe=frappe;
			fichier = fopen(aviong, "r+");
			break;

			case'd':
			coordX++;
			savefrappe=frappe;
			fichier = fopen(aviond, "r+");
			break;

			case'x':	//si on appuie sur x
			n=1;		// condition pour rester dans la boucle while 
			fichier=fopen(aviond, "r+");
			savefrappe=frappe;
			break;

			default:
			switch(savefrappe) //même opération avec la derniere touche enregistrée
			{
				case'z':

				coordY--;
				fichier = fopen(avionh, "r+");
				break;
				case's':

				coordY++;
				fichier = fopen(avionb, "r+");
				break;
				case'q':

				coordX--;
				fichier = fopen(aviong, "r+");

				break;
				case'd':

				coordX++;
				fichier = fopen(aviond, "r+");
				break;
				case'x':
				n=1;
				fichier=fopen(aviond, "r+");
				break;
			}
		}

		for (y=1; y<24; y++)									//
		{														//
			for (x=0; x<80; x++)								//
			{
				tableau [y][x]=0;								//
			}
		}

		for (i=0; i<3; i++)										//
		{
			fgets(temp, 255 , fichier);							//
		}

		for (int i = 0; i < 6; ++i)								//
		{
			fgets(temp,255,fichier);							//
			strcpy(caractere,strtok(temp," "));					//
			nombre= atoi(caractere);
			tableau[coordY+i][coordX]=nombre;					//
			for (j=1; j<6; j++)									//
			{						
				strcpy(caractere,strtok(NULL," "));				//
				nombre= atoi(caractere);						//
				tableau[coordY+i][coordX+j]=nombre;				//
			}
		}

		fclose(fichier);										//

		for (y=1; y<24; y++)									//
		{
			for (x=0; x<80; x++)								//
			{
				if(tableau[y][x]==0){							//
					printf(" ");								//
				}
				else {
					printf("\u2588");							//
				}
				if (tableau[25][x]==1 && savefrappe=='s')
				{
					if (coordY ==24)
					{
						coordY= coordY-24;
					}
				}
				if (tableau [0][x]==1)
				{
					if (coordY ==0)
					{
						coordY=coordY+24;
					}
				}
			}
			
			printf("\n");										// on lit le fichier à chaque fois qu'on appuie sur une touche
		}
	}
	system("clear");											
}