// фамилия, инициалы, количество вещей, общий вес вещей,
//пункт назначения, время вылета, наличие пересадок, сведения о детях.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "passengers.h"
int main(int argc, char *argv[])
{
	if(argc!=3)
	{
		printf("Error, please enter programm inputFile outputFile\n");
		return 1;
	}
	passengers list;
	FILE *fi, *fo;
	fi=(fi=fopen(argv[1],"r"));
	fo=(fo=fopen(argv[2],"wb"));

	if(!fi)
	{
		printf("Error can't open file\n");
		return 2;
	}
	while(!feof(fi))
	{
		fscanf(fi,"%s %s %d %d %s %s %s %s\n",
		list.surname, list.initials,
		&list.countOfThing, &list.weight, list.destination, list.timeOfDeparture, list.transfer,
		list.children);
		fwrite(&list,sizeof(list),1,fo);
	}
	return 0;
}