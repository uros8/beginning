#include<stdlib.h>
#include<stdio.h>
#include"dz4.h"
void ispisi(kontejner*glava)
{
	int i = 1;
	for (kontejner*tmp = glava; tmp; tmp = tmp->sledeci)
		printf("Kontejner %d : ID=%d, kg=%d, klasa=%d, UN=%d\n", i++, tmp->ID, tmp->kg, tmp->klasa, tmp->UN);
	printf("\n");
}