#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>

char recupereHeure (char *horloge)
{
	
	float heure ;
	float minutes;
	float seconde;
	char ligne[255];
	time_t secondes;
	struct tm instant;


	time(&secondes);
	instant= *localtime(&secondes);

	heure= instant.tm_hour ; 
	minutes= instant.tm_min ;
	seconde= instant.tm_sec ;

	heure= heure/10; 		//aparition d'un separateur ex: 14 -> 1.4
	minutes= minutes/10;	//
	seconde=seconde/10;		//


	sprintf(ligne, "%.1f", heure);	//transforme le float tronqu頡 
									//la decimal en caract貥s
	strcpy(horloge,ligne);			//on met dans horloge le contenu de ligne
	strcat(horloge,".");			// on ajoute un point a la fin de horloge
	
	sprintf(ligne,"%.1f",minutes);
	strcat(horloge, ligne);
	strcat(horloge,".");
	
	sprintf(ligne,"%.1f", seconde);
	strcat(horloge, ligne);
	strcat(horloge,".");
	printf(horloge);
	printf("\n");
	return *horloge;
}

void afficherheure()
{

	char *horloge;
	char caractere[255];
	char chaine[255];
	char image;
	char temp[255];
	int i;
	int j;
	int f;
	FILE* fichier=NULL;
	char ligne[255];
	int longueur,largeur;
	int random;
	FILE* im1=NULL;				//fichier de l'image de la dizaine des heures
	FILE* im2=NULL;				//fichier de l'image de l'unit饠des heures
	FILE* im3=NULL;				//fichier de l'image des deux points
	FILE* im4=NULL;				//fichier de l'image de la dizaine des minutes
	FILE* im5=NULL;				//fichier de l'image de l'unit饠 des minutes
	FILE* im6=NULL;				//fichier de l'image des deux points
	FILE* im7=NULL;				//fichier de l'image de la dizaine des secondes
	FILE* im8=NULL;				//fichier de l'image de l'unit饠des secondes
	horloge=malloc(255);

	int chiffre1;				//entier qui contiens le chiffre de la dizaine des heures
	int chiffre2;				//entier qui contiens le chiffre de l'unit饠des heures
	int chiffre3;				//entier qui contiens le chiffre de la dizaine des minutes
	int chiffre4;				// entier qui contiens le chiffre de l'unit饠 des minutes
	int chiffre5;				//entier qui contiens le chiffre de la dizaine des secondes
	int chiffre6;				//entier qui contiens le chiffre de l'unit饠des secondes

	FILE* stat=NULL;




	recupereHeure(horloge);		//recupere l'heure et la stoque dans une chaine de caractere
	//printf(horloge);
	srand(time(NULL));				//
	random=(rand()%(2-1+1))+0;		//nomblre aleatoire qui determine la taille des images a utiliser
	//printf("\n%d\n",random );		//

	switch(random){
		case 0:									//la taille des images sera de 3 par 5 px
		fichier=fopen("./3x5/nb1.pbm","r+");		
		printf("fichier ouvert\n");
		break;
		case 1:									//la taille des image sera de 4 par 7 px
		fichier=fopen("./4x7/nb1.pbm","r+");
		printf("fichier ouvert\n");
		break;
	}
	for (int i = 0; i < 3; ++i)
	{
		fgets(ligne,255,fichier);		//va a la 3eme ligne du fichier pbm
	}
	strcpy(caractere,strtok(ligne," "));		//on recupere permier bloc de caractere de la ligne qui contient la longueur et la hauteur
	longueur=atoi(caractere);					// on convertis la longueur en entier et on le stoque dans la variable longueur
	strcpy(caractere,strtok(NULL," "));			//on recupere deuxieme bloc de caractere de la ligne qui contient la longueur et la hauteur
	largeur=atoi(caractere);					// on convertis la hauteur en entier et on le stoque dans la variable largeur
	fclose(fichier);
	//printf("%d\n",longueur);

	system("clear");
	for (int i = 0; i < (24-longueur)/2; ++i)		//on centre les images sur l'axe vertical
	{
		printf("\n");
	}
	


	strcpy(caractere,strtok(horloge,"."));		//on recupere chaque caractere et on les convertis en entier pour avoir chaque chiffre de l'heure en enier utilisable pour le switch suivant
	chiffre1=atoi(caractere);
	strcpy(caractere,strtok(NULL,"."));
	chiffre2=atoi(caractere);
	strcpy(caractere,strtok(NULL,"."));
	chiffre3=atoi(caractere);
	strcpy(caractere,strtok(NULL,"."));
	chiffre4=atoi(caractere);
	strcpy(caractere,strtok(NULL,"."));
	chiffre5=atoi(caractere);
	strcpy(caractere,strtok(NULL,"."));
	chiffre6=atoi(caractere);
	

	if(random ==0){							//cas ou on utilise des petite images(3x5)
		switch(chiffre1){							
			case 0:
			im1=fopen("./3x5/nb0.pbm","r+");		//chargement de la bonne image correspondant a l'entier 
			break;
			case 1:
			im1=fopen("./3x5/nb1.pbm","r+");		//chargement de la bonne image correspondant a l'entier 
			break;
			case 2:
			im1=fopen("./3x5/nb2.pbm","r+");		//chargement de la bonne image correspondant a l'entier 
			break;
			
		}
		switch(chiffre2){
			case 0:
			im2=fopen("./3x5/nb0.pbm","r+");
			break;
			case 1:
			im2=fopen("./3x5/nb1.pbm","r+");
			break;
			case 2:
			im2=fopen("./3x5/nb2.pbm","r+");
			break;
			case 3:
			im2=fopen("./3x5/nb3.pbm","r+");
			break;
			case 4:
			im2=fopen("./3x5/nb4.pbm","r+");		//chargement de la bonne image correspondant a l'entier 
			break;
			case 5:
			im2=fopen("./3x5/nb5.pbm","r+");
			break;
			case 6:
			im2=fopen("./3x5/nb6.pbm","r+");
			break;
			case 7:
			im2=fopen("./3x5/nb7.pbm","r+");
			break;
			case 8:
			im2=fopen("./3x5/nb8.pbm","r+");
			break;
			case 9:
			im2=fopen("./3x5/nb9.pbm","r+");
			break;
		}
		im3=fopen("./3x5/deuxpoints.pbm","r+");		//chargement de la bonne image correspondant au caractere deux points
		switch(chiffre3){
			case 0:
			im4=fopen("./3x5/nb0.pbm","r+");
			break;
			case 1:
			im4=fopen("./3x5/nb1.pbm","r+");
			break;
			case 2:
			im4=fopen("./3x5/nb2.pbm","r+");
			break;
			case 3:
			im4=fopen("./3x5/nb3.pbm","r+");
			break;
			case 4:
			im4=fopen("./3x5/nb4.pbm","r+");		//chargement de la bonne image correspondant a l'entier 
			break;
			case 5:
			im4=fopen("./3x5/nb5.pbm","r+");
			break;
			case 6:
			im4=fopen("./3x5/nb6.pbm","r+");
			break;
			case 7:
			im4=fopen("./3x5/nb7.pbm","r+");
			break;
			case 8:
			im4=fopen("./3x5/nb8.pbm","r+");
			break;
			case 9:
			im4=fopen("./3x5/nb9.pbm","r+");
			break;
		}
		switch(chiffre4){
			case 0:
			im5=fopen("./3x5/nb0.pbm","r+");
			break;
			case 1:
			im5=fopen("./3x5/nb1.pbm","r+");
			break;
			case 2:
			im5=fopen("./3x5/nb2.pbm","r+");
			break;
			case 3:
			im5=fopen("./3x5/nb3.pbm","r+");
			break;
			case 4:
			im5=fopen("./3x5/nb4.pbm","r+");		//chargement de la bonne image correspondant a l'entier 
			break;
			case 5:
			im5=fopen("./3x5/nb5.pbm","r+");
			break;
			case 6:
			im5=fopen("./3x5/nb6.pbm","r+");
			break;
			case 7:
			im5=fopen("./3x5/nb7.pbm","r+");
			break;
			case 8:
			im5=fopen("./3x5/nb8.pbm","r+");
			break;
			case 9:
			im5=fopen("./3x5/nb9.pbm","r+");
			break;
		}
		im6=fopen("./3x5/deuxpoints.pbm","r+");		//chargement de la bonne image correspondant au caractere deux points
		switch(chiffre5){
			case 0:
			im7=fopen("./3x5/nb0.pbm","r+");
			break;
			case 1:
			im7=fopen("./3x5/nb1.pbm","r+");
			break;
			case 2:
			im7=fopen("./3x5/nb2.pbm","r+");
			break;
			case 3:
			im7=fopen("./3x5/nb3.pbm","r+");
			break;
			case 4:
			im7=fopen("./3x5/nb4.pbm","r+");		//chargement de la bonne image correspondant a l'entier 
			break;
			case 5:
			im7=fopen("./3x5/nb5.pbm","r+");
			break;
			case 6:
			im7=fopen("./3x5/nb6.pbm","r+");
			break;
			case 7:
			im7=fopen("./3x5/nb7.pbm","r+");
			break;
			case 8:
			im7=fopen("./3x5/nb8.pbm","r+");
			break;
			case 9:
			im7=fopen("./3x5/nb9.pbm","r+");
			break;
		}
		switch(chiffre6){
			case 0:
			im8=fopen("./3x5/nb0.pbm","r+");
			break;
			case 1:
			im8=fopen("./3x5/nb1.pbm","r+");
			break;
			case 2:
			im8=fopen("./3x5/nb2.pbm","r+");
			break;
			case 3:
			im8=fopen("./3x5/nb3.pbm","r+");
			break;
			case 4:
			im8=fopen("./3x5/nb4.pbm","r+");		//chargement de la bonne image correspondant a l'entier 
			break;
			case 5:
			im8=fopen("./3x5/nb5.pbm","r+");
			break;
			case 6:
			im8=fopen("./3x5/nb6.pbm","r+");
			break;
			case 7:
			im8=fopen("./3x5/nb7.pbm","r+");
			break;
			case 8:
			im8=fopen("./3x5/nb8.pbm","r+");
			break;
			case 9:
			im8=fopen("./3x5/nb9.pbm","r+");
			break;
		}
	}
	else if(random ==1){					//cas ou on utilise des grandes image (4x7)
		switch(chiffre1){
			case 0:
			im1=fopen("./4x7/nb0.pbm","r+");
			break;
			case 1:
			im1=fopen("./4x7/nb1.pbm","r+");
			break;
			case 2:
			im1=fopen("./4x7/nb2.pbm","r+");
			break;
			case 3:
			im1=fopen("./4x7/nb3.pbm","r+");
			break;
			case 4:
			im1=fopen("./4x7/nb4.pbm","r+");		//chargement de la bonne image correspondant a l'entier 
			break;
			case 5:
			im1=fopen("./4x7/nb5.pbm","r+");
			break;
			case 6:
			im1=fopen("./4x7/nb6.pbm","r+");
			break;
			case 7:
			im1=fopen("./4x7/nb7.pbm","r+");
			break;
			case 8:
			im1=fopen("./4x7/nb8.pbm","r+");
			break;
			case 9:
			im1=fopen("./4x7/nb9.pbm","r+");
			break;
		}
		switch(chiffre2){
			case 0:
			im2=fopen("./4x7/nb0.pbm","r+");
			break;
			case 1:
			im2=fopen("./4x7/nb1.pbm","r+");
			break;
			case 2:
			im2=fopen("./4x7/nb2.pbm","r+");
			break;
			case 3:
			im2=fopen("./4x7/nb3.pbm","r+");
			break;
			case 4:
			im2=fopen("./4x7/nb4.pbm","r+");		//chargement de la bonne image correspondant a l'entier 
			break;
			case 5:
			im2=fopen("./4x7/nb5.pbm","r+");
			break;
			case 6:
			im2=fopen("./4x7/nb6.pbm","r+");
			break;
			case 7:
			im2=fopen("./4x7/nb7.pbm","r+");
			break;
			case 8:
			im2=fopen("./4x7/nb8.pbm","r+");
			break;
			case 9:
			im2=fopen("./4x7/nb9.pbm","r+");
			break;
		}
		im3=fopen("./4x7/deuxpoints.pbm","r+");				//chargement de la bonne image correspondant au caractere deux points
		switch(chiffre3){
			case 0:
			im4=fopen("./4x7/nb0.pbm","r+");
			break;
			case 1:
			im4=fopen("./4x7/nb1.pbm","r+");
			break;
			case 2:
			im4=fopen("./4x7/nb2.pbm","r+");
			break;
			case 3:
			im4=fopen("./4x7/nb3.pbm","r+");
			break;
			case 4:
			im4=fopen("./4x7/nb4.pbm","r+");
			break;
			case 5:
			im4=fopen("./4x7/nb5.pbm","r+");		//chargement de la bonne image correspondant a l'entier 
			break;
			case 6:
			im4=fopen("./4x7/nb6.pbm","r+");
			break;
			case 7:
			im4=fopen("./4x7/nb7.pbm","r+");
			break;
			case 8:
			im4=fopen("./4x7/nb8.pbm","r+");
			break;
			case 9:
			im4=fopen("./4x7/nb9.pbm","r+");
			break;
		}
		switch(chiffre4){
			case 0:
			im5=fopen("./4x7/nb0.pbm","r+");
			break;
			case 1:
			im5=fopen("./4x7/nb1.pbm","r+");
			break;
			case 2:
			im5=fopen("./4x7/nb2.pbm","r+");
			break;
			case 3:
			im5=fopen("./4x7/nb3.pbm","r+");
			break;
			case 4:
			im5=fopen("./4x7/nb4.pbm","r+");		//chargement de la bonne image correspondant a l'entier 
			break;
			case 5:
			im5=fopen("./4x7/nb5.pbm","r+");
			break;
			case 6:
			im5=fopen("./4x7/nb6.pbm","r+");
			break;
			case 7:
			im5=fopen("./4x7/nb7.pbm","r+");
			break;
			case 8:
			im5=fopen("./4x7/nb8.pbm","r+");
			break;
			case 9:
			im5=fopen("./4x7/nb9.pbm","r+");
			break;
		}
		im6=fopen("./4x7/deuxpoints.pbm","r+");				//chargement de la bonne image correspondant au caractere deux points
		switch(chiffre5){
			case 0:
			im7=fopen("./4x7/nb0.pbm","r+");
			break;
			case 1:
			im7=fopen("./4x7/nb1.pbm","r+");
			break;
			case 2:
			im7=fopen("./4x7/nb2.pbm","r+");
			break;
			case 3:
			im7=fopen("./4x7/nb3.pbm","r+");
			break;
			case 4:
			im7=fopen("./4x7/nb4.pbm","r+");		//chargement de la bonne image correspondant a l'entier 
			break;
			case 5:
			im7=fopen("./4x7/nb5.pbm","r+");
			break;
			case 6:
			im7=fopen("./4x7/nb6.pbm","r+");
			break;
			case 7:
			im7=fopen("./4x7/nb7.pbm","r+");
			break;
			case 8:
			im7=fopen("./4x7/nb8.pbm","r+");
			break;
			case 9:
			im7=fopen("./4x7/nb9.pbm","r+");
			break;
		}
		switch(chiffre6){
			case 0:
			im8=fopen("./4x7/nb0.pbm","r+");
			break;
			case 1:
			im8=fopen("./4x7/nb1.pbm","r+");
			break;
			case 2:
			im8=fopen("./4x7/nb2.pbm","r+");
			break;
			case 3:
			im8=fopen("./4x7/nb3.pbm","r+");
			break;
			case 4:
			im8=fopen("./4x7/nb4.pbm","r+");
			break;
			case 5:
			im8=fopen("./4x7/nb5.pbm","r+");		//chargement de la bonne image correspondant a l'entier 
			break;
			case 6:
			im8=fopen("./4x7/nb6.pbm","r+");
			break;
			case 7:
			im8=fopen("./4x7/nb7.pbm","r+");
			break;
			case 8:
			im8=fopen("./4x7/nb8.pbm","r+");
			break;
			case 9:
			im8=fopen("./4x7/nb9.pbm","r+");
			break;
		}
	}


	for (int i = 0; i < 3; ++i)		//on va a la 3eme ligne de chaque fichier
	{
		fgets(ligne,255,im1);
		fgets(ligne,255,im2);
		fgets(ligne,255,im3);
		fgets(ligne,255,im4);
		fgets(ligne,255,im5);
		fgets(ligne,255,im6);
		fgets(ligne,255,im7);
		fgets(ligne,255,im8);
	}


	for (int i = 0; i < (largeur); ++i)			//pour chaque ligne
	{
		
				for (int x = 0; x < ((80-(longueur*8+7))/2); ++x)		//centre l'image sur la longueur de l'ecran
				{	

					printf(" ");
				}

				fgets(ligne,255,im1);

				
				strcpy(caractere,strtok(ligne," "));

						if (strncmp(caractere,"0",1)==0)		//compare 2 chaines de caractere temp et 0
						{
							
							printf(" ");		// si elles correspondent, on rempplace le 0 par un espace 
						}
						else if(strncmp(caractere,"1",1)==0)		//compare 2 chaines de caractere temp et 1
						{
							printf("\u2588");		// si elles correspondent, on affiche un caractere ascii a la place du 1
							
						}
						else{
							printf("error");
							fflush(stdout);
						}
						for(int k=0;k<(longueur-1);++k)
						{
						strcpy(caractere,strtok(NULL," "));	//
						if (strncmp(caractere,"0",1)==0)	//
						{									//
							printf(" ");					//
						}									//on repete l'operation precedente pour completer la ligne
						else if(strncmp(caractere,"1",1)==0)//
						{									//
							printf("\u2588");				//
					 	}									//
					 }		

					 fgets(ligne,255,im2);

					 
					 strcpy(caractere,strtok(ligne," "));
					 printf(" ");
						if (strcmp(caractere,"0")==0)		//compare 2 chaines de caractere temp et 0
						{
							
							printf(" ");		// si elles correspondent, on rempplace le 0 par un espace 
						}
						else if(strcmp(caractere,"1")==0)		//compare 2 chaines de caractere temp et 1
						{
							printf("\u2588");		// si elles correspondent, on affiche un caractere ascii a la place du 1
							
						}
						else{
							printf("error");
							fflush(stdout);
						}
						for(int k=0;k<(longueur-1);++k)
						{
						strcpy(caractere,strtok(NULL," "));		//
						if (strncmp(caractere,"0",1)==0)			//
						{									//
							printf(" ");					//
						}									//on repete l'operation precedente pour completer la ligne
						else if(strncmp(caractere,"1",1)==0)//
						{									//
							printf("\u2588");				//
					 	}									//
					 }	
					 fgets(ligne,255,im3);

					 
					 strcpy(caractere,strtok(ligne," "));
					 printf(" ");
						if (strcmp(caractere,"0")==0)		//compare 2 chaines de caractere temp et 0
						{
							
							printf(" ");		// si elles correspondent, on rempplace le 0 par un espace 
						}
						else if(strcmp(caractere,"1")==0)		//compare 2 chaines de caractere temp et 1
						{
							printf("\u2588");		// si elles correspondent, on affiche un caractere ascii a la place du 1
							
						}
						else{
							printf("error");
							fflush(stdout);
						}
						for(int k=0;k<(longueur-1);++k)
						{

						strcpy(caractere,strtok(NULL," "));	//
						if (strncmp(caractere,"0",1)==0)	//
						{									//
							printf(" ");					//
						}									//on repete l'operation precedente pour completer la ligne
						else if(strncmp(caractere,"1",1)==0)//
						{									//
							printf("\u2588");				//
					 	}									//
					 }	
					 fgets(ligne,255,im4);

					 
					 strcpy(caractere,strtok(ligne," "));
					 printf(" ");
						if (strcmp(caractere,"0")==0)		//compare 2 chaines de caractere temp et 0
						{
							
							printf(" ");		// si elles correspondent, on rempplace le 0 par un espace 
						}
						else if(strcmp(caractere,"1")==0)		//compare 2 chaines de caractere temp et 1
						{
							printf("\u2588");		// si elles correspondent, on affiche un caractere ascii a la place du 1
							
						}
						else{
							printf("error");
							fflush(stdout);
						}
						for(int k=0;k<(longueur-1);++k)
						{
							

						strcpy(caractere,strtok(NULL," "));	//
						if (strncmp(caractere,"0",1)==0)	//
						{									//
							printf(" ");					//
						}									//on repete l'operation precedente pour completer la ligne
						else if(strncmp(caractere,"1",1)==0)//
						{									//
							printf("\u2588");				//
					 	}									//
					 }	
					 fgets(ligne,255,im5);

					 
					 strcpy(caractere,strtok(ligne," "));
					 printf(" ");

						if (strcmp(caractere,"0")==0)		//compare 2 chaines de caractere temp et 0
						{
							
							printf(" ");		// si elles correspondent, on rempplace le 0 par un espace 
						}
						else if(strcmp(caractere,"1")==0)		//compare 2 chaines de caractere temp et 1
						{
							printf("\u2588");		// si elles correspondent, on affiche un caractere ascii a la place du 1
							
						}
						else{
							printf("error");
							fflush(stdout);
						}
						for(int k=0;k<(longueur-1);++k)
						{
							

						strcpy(caractere,strtok(NULL," "));	//
						if (strncmp(caractere,"0",1)==0)	//
						{									//
							printf(" ");					//
						}									//on repete l'operation precedente pour completer la ligne
						else if(strncmp(caractere,"1",1)==0)//
						{									//
							printf("\u2588");				//
					 	}									//
					 }	
					 fgets(ligne,255,im6);

					 
					 strcpy(caractere,strtok(ligne," "));
					 printf(" ");
						if (strcmp(caractere,"0")==0)		//compare 2 chaines de caractere temp et 0
						{
							
							printf(" ");		// si elles correspondent, on rempplace le 0 par un espace 
						}
						else if(strcmp(caractere,"1")==0)		//compare 2 chaines de caractere temp et 1
						{
							printf("\u2588");		// si elles correspondent, on affiche un caractere ascii a la place du 1
							
						}
						else{
							printf("error");
							fflush(stdout);
						}
						for(int k=0;k<(longueur-1);++k)
						{
							

						strcpy(caractere,strtok(NULL," "));	//
						if (strncmp(caractere,"0",1)==0)	//
						{									//
							printf(" ");					//
						}									//on repete l'operation precedente pour completer la ligne
						else if(strncmp(caractere,"1",1)==0)//
						{									//
							printf("\u2588");				//
					 	}									//
					 }	
					 fgets(ligne,255,im7);

					 
					 strcpy(caractere,strtok(ligne," "));
					 printf(" ");
						if (strcmp(caractere,"0")==0)		//compare 2 chaines de caractere temp et 0
						{
							
							printf(" ");		// si elles correspondent, on rempplace le 0 par un espace 
						}
						else if(strcmp(caractere,"1")==0)		//compare 2 chaines de caractere temp et 1
						{
							printf("\u2588");		// si elles correspondent, on affiche un caractere ascii a la place du 1
							
						}
						else{
							printf("error");
							fflush(stdout);
						}
						for(int k=0;k<(longueur-1);++k)
						{
							

						strcpy(caractere,strtok(NULL," "));	//
						if (strncmp(caractere,"0",1)==0)	//
						{									//
							printf(" ");					//
						}									//on repete l'operation precedente pour completer la ligne
						else if(strncmp(caractere,"1",1)==0)//
						{									//
							printf("\u2588");				//
					 	}									//
					 }	
					 fgets(ligne,255,im8);

					 
					 strcpy(caractere,strtok(ligne," "));
					 printf(" ");
						if (strcmp(caractere,"0")==0)		//compare 2 chaines de caractere temp et 0
						{
							
							printf(" ");		// si elles correspondent, on rempplace le 0 par un espace 
						}
						else if(strcmp(caractere,"1")==0)		//compare 2 chaines de caractere temp et 1
						{
							printf("\u2588");		// si elles correspondent, on affiche un caractere ascii a la place du 1
							
						}
						for(int k=0;k<(longueur-1);++k)
						{

						strcpy(caractere,strtok(NULL," "));	//
						if (strncmp(caractere,"0",1)==0)	//
						{									//
							printf(" ");					//
						}									//on repete l'operation precedente pour completer la ligne
						else if(strncmp(caractere,"1",1)==0)//
						{									//
							printf("\u2588");				//
					 	}									//
					 }	

					 
					 printf("\n");

					}

					for (int i = 0; i < (24-longueur-2)/2; ++i) //on descend le curseur en bas de la console
					{
						printf("\n");
					}
				}

int compteur()
{

	int n=9;

	struct termios old={0};
	old.c_lflag|=IGNBRK;

	
		printf("Cet 飲an sera actualis頤ans quelques secondes ");

		for(int compteur=0; compteur <= n; compteur++)
		{
			printf(". ");
			fflush(stdout);
			sleep(1);
		}
		printf(".\n");
		system("clear");
}