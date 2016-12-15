#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

char fin() //appel à la fonction getch déja commenté dans les autres programmes
{
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    printf("%c\n",buf);
    system("clear");
    exit(0);
    return buf;
}

int main(int argc, char *argv[])
{
	int nombre;
	int i;
	int x=0;	//Coordonnées du tableau
	int y=0;	//
	int tri;
	char ligne[255];
	char tab[100][40]; //Tableau à double entrée
	char tmp[255];
	FILE* stat=NULL; //Fichier des statistiques

	stat=fopen("/root/Bureau/projetsysteme/stats","r+"); //ouvre le fichier

	printf("Modes de tri disponibles\n1.Date\n2.Mode\n\nTapez 1 ou 2 pour sélectionner un mode de tri\n"); //Permet a l'utilisateur de choisir son mode de tri
	scanf("%d", &nombre);


	while((nombre!=1)&&(nombre!=2))
	{
		printf("Entrez un nombre valide\n");	//Sécurise la saisie des caractères
		scanf("%d",&nombre);					//
	}

	if(nombre == 1)
	{
		system("clear");
		while(fgets(ligne,255,stat)!=NULL)	//
		{									//
			printf(ligne);					//Lit le fichier et l'écrit
		}									//
		fin();								//
	}
	else if(nombre == 2)
	{
		system("clear");
		printf("Fonctionnalité en cours de développement\n");
		fin();
		// while(fgets(ligne,255,stat)!=NULL)
		// {
		// 	strcpy(tmp,strtok(ligne," "));
		// 	for(i=0;i<2;i++)
		// 	{
		// 		strcpy(tmp,strtok(NULL," "));
		// 	}
		// 	strcpy(tab[x],tmp);
		// 	printf("%c\n",tab[x][0]);
		// 	x++;	
		// }

	}
	fclose(stat); //Ferme le fichier des statistiques
	return 0;
}