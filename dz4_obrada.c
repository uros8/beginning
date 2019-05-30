#include<stdlib.h>
#include<stdio.h>
#include"dz4.h"
kontejner *ubaci_na_poc(kontejner *glava) {
	printf("Unesite podatke elementa koji dodajemo na pocetak: ID, kg, klasa, UN\n");
	unsigned int ID, kg, klasa, UN;
	scanf("%d%d%d%d", &ID, &kg, &klasa, &UN);
	kontejner*novi = malloc(sizeof(kontejner));
	novi->ID = ID; novi->kg = kg; novi->klasa = klasa; novi->UN = UN;
	novi->sledeci = glava;
	glava = novi;
	return glava;
}
kontejner *ubaci_na_kraj(kontejner *rep) {
	printf("Unesite podatke elementa koji dodajemo na kraj: ID, kg, klasa, UN\n");
	unsigned int ID, kg, klasa, UN;
	scanf("%d%d%d%d", &ID, &kg, &klasa, &UN);
	kontejner*novi = malloc(sizeof(kontejner));
	novi->ID = ID; novi->kg = kg; novi->klasa = klasa; novi->UN = UN;
	novi->sledeci = NULL; rep->sledeci = novi; rep = novi;
	return rep;
}
kontejner*rep_liste(kontejner*glava) {
	kontejner* tmp;
	for (tmp = glava; tmp->sledeci != NULL; tmp = tmp->sledeci);
	return tmp;
}
int duzina_liste(kontejner*glava) {
	int n = 0;
	for (kontejner*tmp = glava; tmp != NULL; tmp = tmp->sledeci)
		n++;
	return n;
}
void izbrisi_listu(kontejner *glava)
{
	while (glava)
	{
		kontejner* stari = glava;
		glava = glava->sledeci;
		free(stari);
	}
}
kontejner* izostavi(kontejner *glava)
{
	unsigned int ID, kg, klasa, UN;
	printf("Unesite podatke elementa koji izostavljamo ID,kg,klasa,UN : \n");
	scanf("%d%d%d%d", &ID, &kg, &klasa, &UN);
	kontejner* prosli = glava, *t = glava;
	while (t)
	{
		if (t == glava && ((ID == t->ID) && (t->kg == kg) && (t->klasa == klasa) && (t->UN == UN)))
		{
			glava = glava->sledeci, free(t); break;//ako je prvi element trazeni
		}
		else
			if ((ID == t->ID) && (t->kg == kg) && (t->klasa == klasa) && (t->UN == UN))
			{
				prosli->sledeci = t->sledeci; free(t); break;//ukoliko smo nasli element prespojimo pokazivace uredno
			}
			else prosli = t, t = t->sledeci;//prolazak ako ponudjeni element nije trazeni

	}
	return glava;
}
void zameni(kontejner*i, kontejner*j)
{
	int p = i->ID; i->ID = j->ID; j->ID = p;
	p = i->kg; i->kg = j->kg; j->kg = p;
	p = i->klasa; i->klasa = j->klasa; j->klasa = p;
	p = i->UN; i->UN = j->UN; j->UN = p;
}
void sortiraj(kontejner* glava) {
	kontejner *i, *j;
	for (i = glava; i; i = i->sledeci)
		for (j = i->sledeci; j; j = j->sledeci)
			if (i->kg > j->kg)
				zameni(i, j);
}
kontejner* prepisi(kontejner*tmp,kontejner*k)
{
	kontejner*novi = malloc(sizeof(kontejner));//prepisivanje elementa u podlistu
	novi->ID = tmp->ID; novi->kg = tmp->kg; novi->klasa = tmp->klasa; novi->UN = tmp->UN; novi->sledeci = NULL;
	novi->sledeci = k;
	k = novi;
	return k;
}
void sortiraj_poUN(kontejner*glava)
{
		kontejner *i, *j;//klasican selection sort
		for (i = glava; i; i = i->sledeci)
			for (j = i->sledeci; j!=NULL; j = j->sledeci)
				if (i->UN > j->UN)
					zameni(i, j);
}
int najvise_UN(kontejner*k)
{
	sortiraj_poUN(k);
	kontejner*p = k, *t = k->sledeci; int UN = 0, max = 0, br = 1;//odredjivanje UNmax po klasi
	while (p) {
		if (t == NULL)//zbog slucaja kada je samo jedan element u podlisti
		{
			if (br > max)
				max = br, UN = p->UN;
			break;
		}
		if ((t->UN != p->UN))//po potrebi objasniti na papiru
		{
			if (br > max)
				max = br, UN = p->UN;
			br = 1;//uvek azuriramo na jedan kada krece brojanje dela podliste
			p = t; t = t->sledeci;
		}
		else {
			p = t; t = t->sledeci; br++;//nastavljamo dok se ne razlikuju prosli i trenutni po UN
		}
	}
	sortiraj(k);
	return UN;
}
void klasiraj(kontejner* glava)
{
	//kontejner *k1 = NULL, *k2 = NULL, *k3 = NULL, *k4 = NULL, *k5 = NULL, *k6 = NULL, *k7 = NULL, *k8 = NULL, *k9 = NULL;
	kontejner*k[9]; for (int i = 0; i < 9; i++)k[i] = NULL;
	for (kontejner*tmp = glava; tmp; tmp = tmp->sledeci) {
		k[(tmp->klasa) - 1] = prepisi(tmp, k[(tmp->klasa) - 1]);
	}
	//for (int i = 0; i < 9; i++)if(k[i]!=NULL)sortiraj(k[i]);
	for (int i = 0; i < 9; i++)
		if (k[i] != NULL) {
			sortiraj(k[i]);
		}
	while (1) {
		printf("Izaberite nad kojom klasom vrsite manipulaciju:\n");int unos; scanf("%d", &unos); kontejner *rep = rep_liste(k[unos - 1]);
		while (1) {
			printf("izaberite opciju:1.ispisi 2.dodaj na poc 3.dodaj na kraj 4.izostavi 5.izbrisi listu 6.izadji iz obrade 7.izlazak iz programa\n");
			int unos1; scanf("%d", &unos1); 
			if (unos1 == 6)break;
			if (unos1 == 7)exit(56);
			if (unos1 == 5) {
				izbrisi_listu(k[unos - 1]); break;
			}
			switch (unos1)
			{
			case 1: ispisi(k[unos - 1]); printf("Najvise UN: %d\n", najvise_UN(k[unos - 1])); break;//klasicne funkcije koje smo vec obradili
			case 2: k[unos - 1] = ubaci_na_poc(k[unos - 1]); ispisi(k[unos - 1]); break;
			case 3: rep = ubaci_na_kraj(rep); ispisi(k[unos - 1]); break;
			case 4: k[unos - 1] = izostavi(k[unos - 1]); ispisi(k[unos - 1]); break;
			case 7: izbrisi_listu(glava); exit(3);//da li je treba izbrisati??
			}
		}
	}
}