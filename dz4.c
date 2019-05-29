#include<stdio.h>
#include<stdlib.h>
typedef struct k {
	unsigned int ID, kg, klasa, UN;
	struct k* sledeci;
}kontejner;
void ispisi(kontejner*glava)
{
	int i = 1;
	for (kontejner*tmp = glava; tmp != NULL; tmp = tmp->sledeci)
		printf("Kontejner %d : ID=%d, kg=%d, klasa=%d, UN=%d\n", i++, tmp->ID, tmp->kg, tmp->klasa, tmp->UN);
}
kontejner* ucitaj_listu()
{
	kontejner*glava = NULL, *rep = NULL; unsigned int ID=0, kg, klasa, UN, n = 0;
	printf("Unesite podatke (kod prekida unosa je '-1 -1 -1 -1'):ID, kg, klasa, UN\n");
	while (1)
	{
		scanf("%d%d%d%d", &ID, &kg, &klasa, &UN);
		if (ID == -1 && kg == -1 && klasa == -1 && UN == -1 )break;
		kontejner*novi = malloc(sizeof(kontejner));
		novi->ID = ID; novi->kg = kg; novi->klasa = klasa; novi->UN = UN;
		novi->sledeci = NULL;
		if (glava == NULL) { glava = novi; rep = novi; }
		else { rep->sledeci = novi; rep = novi; }n++;
	}
	return glava;
}
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
	kontejner* stari; unsigned int ID;
	printf("Unesi ID elementa koji zelite da izbacite : ");
	scanf("%d", &ID); kontejner* tmp = glava;
	if (tmp->ID == ID) { glava = glava->sledeci; free(tmp); return glava; }
	while ((tmp->sledeci)->ID != ID)
		  tmp = tmp->sledeci;
	stari = tmp->sledeci; tmp->sledeci = stari->sledeci;
	free(stari);
	printf("\n");
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
		for (j = i->sledeci;j; j = j->sledeci)
			if (i->ID > j->ID)
				zameni(i, j);
}
int main() {
	kontejner*glava=ucitaj_listu(); 
	ispisi(glava);
	kontejner*rep = rep_liste(glava);
	//printf("rep liste je %d %d %d %d\n", rep->ID, rep->kg, rep->klasa, rep->UN);
	kontejner*novi = malloc(sizeof(kontejner));
	glava=ubaci_na_poc(glava);
	rep = ubaci_na_kraj(rep);
	ispisi(glava);
	printf("\n duzina liste je %d\n", duzina_liste(glava));
	glava = izostavi(glava);
	ispisi(glava);
	printf("\n duzina liste je %d\n", duzina_liste(glava));
	rep = rep_liste(glava);
	sortiraj(glava);
	printf("\nsortirana lista je\n");
	ispisi(glava);
	izbrisi_listu(glava);
	system("pause");
	return 0;
}