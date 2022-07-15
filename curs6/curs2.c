#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "passengers.h"
int main(int argc, char *argv[])
{
	int a,b;
	int p = 0;
		if(argc==4 && !strcmp(argv[1], "-f"))
		{
			a=2;
			b=3;
		}
		else if(argc==5 && !strcmp(argv[1], "-p"))
		{
			a=3;
			b=4;
			p=atoi(argv[2]);
		}
		else
		{
			printf("Error please enter programm [-key] inputFile outputFile\n");
			printf("Keys: \n");
			printf("-f output all data\n");
			printf("-p <parametr> output data about passegers with more than parametr stuff\n");
			return 1;
		}
	passengers list;
		FILE *fin=(fin=fopen(argv[a],"r"));
		if(!fin)
		{
			printf("Error, can't open file %s\n",argv[a]);
			return 2;
		}
		FILE *fout=(fout=fopen(argv[b],"wb"));
		if(!fout)
		{
			printf("Error, can't open file %s\n", argv[b]);
			return 2;
		}
		printf("┌───────────────┬────────┬─────┬──────┬───────────────┬─────┬────────┬────────┐\n");
		printf("│    Surname    │Initials│Items│Weight│  Destination  │Time │Transfer│Children│\n");
		if(!strcmp(argv[1],"-f"))
		{
		while(!feof(fin))
		{
			fread(&list, sizeof(list),1,fin);
			fprintf(fout,"surname= %s initials= %s countOfThing= %d weight= %d destination= %s timeOfDeparture= %s transfer= %s children= %s \n", list.surname,
			list.initials, list.countOfThing, list.weight,
			list.destination, list.timeOfDeparture, list.transfer, list.children);
			printf("│%15s│%8s│%5d│%6d│%15s│%5s│%8s│%8s│\n", list.surname,
			list.initials, list.countOfThing, list.weight,
			list.destination, list.timeOfDeparture, list.transfer, list.children);
		}
		}
		else if(!strcmp(argv[1],"-p"))
		{
			while(!feof(fin))
		{
			fread(&list, sizeof(list),1,fin);
			if(list.countOfThing>p){
				fprintf(fout,"surname= %s initials= %s countOfThing= %d weight= %d destination= %s timeOfDeparture= %s transfer= %s children= %s \n", list.surname,
				list.initials, list.countOfThing, list.weight,
				list.destination, list.timeOfDeparture, list.transfer, list.children);
				printf("│%15s│%8s│%5d│%6d│%15s│%5s│%8s│%8s│\n", list.surname,
				list.initials, list.countOfThing, list.weight,
				list.destination, list.timeOfDeparture, list.transfer, list.children);
		}
		}
		}
		printf("└───────────────┴────────┴─────┴──────┴───────────────┴─────┴────────┴────────┘\n");





}