#include<stdlib.h>
#include<stdio.h>
#include"dz4.h"
kontejner* ucitaj_listu()
{
	kontejner*glava = NULL, *rep = NULL; unsigned int ID = 0, kg, klasa, UN, n = 0;
	printf("Unesite podatke (kod prekida unosa je '-1 -1 -1 -1'):ID, kg, klasa, UN\n");
	while (1)
	{
		scanf("%d%d%d%d", &ID, &kg, &klasa, &UN);
		if (ID == -1 && kg == -1 && klasa == -1 && UN == -1)break;
		kontejner*novi = malloc(sizeof(kontejner));//formiranje elementa i provera opsega klase
		if (klasa > 9 || klasa < 1 )exit(13);
		novi->ID = ID; novi->kg = kg; novi->klasa = klasa; novi->UN = UN;
		novi->sledeci = NULL;
		if (glava == NULL) { glava = novi; rep = novi; }//dodavanje uz ocuvanje poretka
		else { rep->sledeci = novi; rep = novi; }n++;
	}
	return glava;
}