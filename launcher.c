#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

char *date(char *horloge)
{
	time_t secondes;
	struct tm instant;
	int jour;
	int mois;
	int annee;
	int heure;
	int minute;
	int seconde;

	//structure de time.h
	time(&secondes);
	instant= *localtime(&secondes);

	//Utilise la bibliothèque time.h pour récupérer l'heure réelle
	jour = instant.tm_mday;
	mois = instant.tm_mon;
	annee = instant.tm_year;
	heure = instant.tm_hour;
	minute = instant.tm_min;
	seconde = instant.tm_sec;

	annee = (annee-100)+2000;
	//Ecrit dans la chaîne de caractère horloge pour retourner une seule valeur.
	sprintf(horloge,"%d/%d/%d %d:%d:%d",jour, mois, annee, heure, minute, seconde);

	return horloge;
}



int main(int argc,char *argv[])
{
	char path[255]; //chemin des variables d'environnement
	char argu[255];
	int f;		//Variables du fork

	if(argc >= 2 && strcmp(argv[0],"-stats")) //Vérfie si on entre l'argument -stats au lancement
	{
		f=fork();
		if(f!=0)
		{
			wait(NULL);
		}
		else
		{
			strcpy(path,getenv("EXIASAVER_HOME"));	//Utilise la variable d'environnement pour le menu des stats
			strcat(path,"menu");
			execv(path,NULL); //lance le menu
			exit(0);
		}
	}
	else
	{
		
		FILE* im1=NULL;
		FILE* stat=NULL;
		char *argv[3];									//
		argv[0]="/root/Bureau/projetsysteme/statique";	//Définition des arguments pour
		argv[2]=NULL;									//choisir l'image statique
		char path[255];
		char horloge[255];
		char env[255];

		srand(time(NULL));				//
		int random=(rand()%(3-1+1))+0;	//Module de random pour choix du mode

		date(horloge);

		switch(random)
		{
			case 0:
				f =fork();		//Duplication processus père créant un processus fils
				if(f!=0)		//
				{
					wait(NULL);	//Attend la fin de l'execution du processus fils
				}
				else
				{
					srand(time(NULL));						//
					int randomStatique=(rand()%(5-1+1))+0;	//Choix aléatoir d'une des 5 images

					stat=fopen("/root/Bureau/projetsysteme/stats","a"); //Ouvre l'historique de lancement

					switch(randomStatique)
					{
						case 0:
							argv[1]="ex1"; //Met la 1ere image en argument du programme de statique
							fprintf(stat,"%s  statique;ex1.pbm\n",horloge);
							break;
							case 1:
							argv[1]="ex2";
							fprintf(stat,"%s  statique;ex2.pbm\n",horloge);
							break;
							case 2:
							argv[1]="ex3";
							fprintf(stat,"%s  statique;ex3.pbm\n",horloge);
							break;
							case 3:
							argv[1]="ex4";
							fprintf(stat,"%s  statique;ex4.pbm\n",horloge);
							break;
							case 4:
							argv[1]="ex5";
							fprintf(stat,"%s  statique;ex5.pbm\n",horloge);
							break;
						}


						fclose(stat);
					strcpy(path,getenv("EXIASAVER_HOME"));	//Utilise la variable d'environnement pour récupérer le programme statique.
					strcat(path,"statique");
					execv(path,argv);//Execute statique avec image en argument
					exit(0);	//Quitte le processus fils sans erreur											
				}
				break;

			case 1:
				stat=fopen("/root/Bureau/projetsysteme/stats","a");
				fprintf(stat,"%s  dynamique\n", horloge);
				fclose(stat);
				f=fork();
				if(f!=0)
				{
					wait(NULL);
				}
				else
				{
				strcpy(path,getenv("EXIASAVER_HOME"));	//Utilise la variable d'environnement pour récupérer le programme dynamique.
				strcat(path,"horloge");
				execv(path,NULL);
				exit(0);
				}
			break;
			
			case 2:
				stat=fopen("/root/Bureau/projetsysteme/stats","a");
				fprintf(stat,"%s  intéractif\n", horloge);
				fclose(stat);
				f=fork();
				if(f!=0)
				{
					wait(NULL);
				}
				else
				{
					strcpy(path,getenv("EXIASAVER_HOME"));	//Utilise la variable d'environnement pour récupérer le programme intéractif.
					strcat(path,"interactif");
					execv(path,NULL);
					exit(0);
				}
				break;
			}
		}
		return 0;
	}