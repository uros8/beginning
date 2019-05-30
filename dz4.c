#include<stdio.h>
#include<stdlib.h>
#include "dz4.h"
int main() {
		while (1) {
		printf("Izaberite: 1.ucitavanje liste 2.izlaz iz programa\n");
		int unos; scanf("%d", &unos);
			if (unos == 1) {
				kontejner*glava = ucitaj_listu(); kontejner*rep = rep_liste(glava);
				printf("---------\n");
				while (1) {
					printf("1.ispisi listu 2.dodaj element na pocetak 3.dodaj element na kraj 4.izostavi element 5.klasiraj 6.izlaz iz obrade 7.obrisi listu\n");
					int unos1; scanf("%d", &unos1); if (unos1 == 6)break;
					switch (unos1)
					{
					case 1: ispisi(glava); break;
					case 2: glava = ubaci_na_poc(glava); ispisi(glava); break;
					case 3: rep = ubaci_na_kraj(rep); ispisi(glava); break;
					case 4: glava = izostavi(glava); ispisi(glava); break;
					case 5: klasiraj(glava); break;
					case 7: izbrisi_listu(glava); exit(3);
					}
				}
			}
			else exit(23);
		}
	system("pause");
	return 0;
}