/*Sastaviti program na programskom jeziku C koji vrsi odredjenu vrstu obrade nad ulaznim
nizom/nizovima. Program treba da:
a) ucita sve potrebne podatke (duzinu niza, elemente niza, itd.);
b) izvrsi zahtevanu obradu;
c) ispise sve dobijene rezultate;
d) ponavlja prethodna tri koraka dok za duzinu niza/nizova ne bude uneta negativna vrednost;
f) odredjuje broj elemenata koje je potrebno dodati u niz tako da u njemu budu prisutni svi
elementi koji se nalaze u zadatom opsegu [donji, gornji]; obezbediti da se svaki
element u nizu pojavljuje samo jednom;
e) modifikovana problem tako da pre
osnovne obrade izvrsi sortiranje pocetnog niza (nizova) po neopadajucem ili nerastucem
kriterijumu, ispise tako sortiran niz (nizove) i nastavi dalje osnovnu obradu. Kriterijum
sortiranja korisnik zadaje preko glavnog ulaza.*/
#include<stdio.h>
#define max_br_el 1000
int main() {
	int n, niz[max_br_el], i, j, gornja, donja, k;
	while (1) {
		printf("Unesite duzinu niza:\n");
		scanf("%d", &n);
		if (n < 0 || n>max_br_el)break;
	xxx:printf("Unesite elemente niza(broj se sme samo jednom pojavljivati):\n");
		for (i = 0; i < n; scanf("%d", niz + i++));
		for (i = 1; i < n; i++)
			for (j = 0; j < i; j++)
				if (niz[i] == niz[j])
				{
					printf("Nekorektan unos\n");
					goto xxx;
				}
		printf("Unesite donju granicu intervala:\n");
		scanf("%d", &donja);
		printf("Unesite gornju granicu intervala:\n");
		scanf("%d", &gornja);
		printf("Unesite zeljen poredak(1-neopadajuci ; 0-nerastuci\n"); 
		scanf("%d", &k);
		if (k)
		{
			for (i = 0; i < n-1; i++)
				for (j = i + 1; j < n;j++)
					if (niz[i] > niz[j])
					{
						niz[i] += niz[j];
						niz[j] = niz[i] - niz[j];
						niz[i] = niz[i] - niz[j];
					}
		}
		else 
		{
			for (i = 0; i < n - 1; i++)
				for (j = i + 1; j < n; j++)
					if (niz[i] < niz[j])
					{
						niz[i] += niz[j];
						niz[j] = niz[i] - niz[j];
						niz[i] = niz[i] - niz[j];
					}
		}
		for (i = 0; i < n; printf("%d ", niz [i++]));
		printf("\n");
		k = gornja - donja + 1;
		for (i = 0; i < n; i++)
			if (niz[i] >= donja & niz[i] <= gornja)k--;
		printf("Potrebno je dodati %d elem. niza da biste popunili interval\n\n", k);
	}
	system("pause");
	return 0;
}