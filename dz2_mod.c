/*Sastaviti program na programskom jeziku C koji vrši odredenu obradu nad jednom ili više
dinamicki alociranih matrica.Program treba da repetitivno ucitava sve potrebne ulazne podatke,
ispisuje ih po ucitavanju, izvršava zahtevanu obradu, ispisuje sve dobijene rezultate i ponavlja
navedene korake, sve dok korisnik za neki od podataka ne unese karakteristicnu vrednost.
5. ispituje da li je kvadratna matrica dijagonalna, a zatim izracunava broj dijagonala kod kojih je
suma elemenata pozitivna; matrica je dijagonalna ukoliko ima podjednak broj popunjenih
(nenultih) dijagonala iznad i ispod glavne dijagonale;

Pri zadavanju matrice, program treba prvo da ucita dimenzije, alocira potreban prostor i ucita
njene elemente sa standardnog ulaza.Kod ispisivanja matrice, program treba da ispiše jednu vrstu
po liniji ispisanog teksta.Za smeštanje matrice koristiti dinamicku memoriju i jedan(i samo jedan!)
staticki pokazivac odgovarajuceg tipa.U toku rada, prilikom svake alokacije dinamicke memorije,
proveravati uspešnost poziva funkcije.U slucaju neuspešne dodele dinamicke memorije, ispisati
poruku o grešci i prekinuti izvršavanje programa.Nakon svakog ciklusa programa(unos, obrada,
	ispis) dealocirati svu korišcenu dinamicku memoriju.Tip elemenata matrice odabrati prema
	potrebama zadatka, odnosno koristiti proizvoljni tip tamo gde to nije suštinski bitno za sam
	algoritam.Osmisliti i napisati na papiru nekoliko primera ulaznih podataka, kao i
	ocekivani izlaz za te primere.Kandidati koji na odbrani nemaju spremna makar tri suštinski
	razlicita test primera ne mogu dobiti maksimalan broj poena.
	Po rešavanju osnovnog zadatka, modifikovati rešenje, tako da nakon učitavanja
dimenzija matrice, program popuni matricu pseudoslučajnim brojevima čiji opseg treba
da učita sa standardnog ulaza, a zatim nastavi inicijalnu obradu. Obratiti pažnju na
ispravnu inicijalizaciju generatora pseudoslučajnih brojeva.*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
	while (1) {
		int **pok;
		int n, i, j,gornja_granica,donja_granica;
		printf("Unesite dimenziju matrice:\n");
		scanf("%d", &n);
		if (n <= 1)break;
		int **provera;
		provera = malloc(n * sizeof(int *));
		if (!provera) { printf("Neuspesna alokacija\n"); system("pause"); return 666; }
		pok = provera;
		for (i = 0; i < n; i++) {
			int *temp = malloc(n * sizeof(int));
			if (!temp) { printf("Neuspesna alokacija\n"); system("pause"); return 666; }
			*(pok + i) = malloc(n * sizeof(int));
		}
		do{
			printf("Unesite donju granicu intervala:\n");
			scanf("%d", &donja_granica);
			printf("Unesite gornju granicu intervala\n");
			scanf("%d", &gornja_granica);
			printf("\n");
		} while (gornja_granica < donja_granica);
		srand(time(NULL));
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
				pok[i][j] = (rand() / (double)RAND_MAX)*(gornja_granica - donja_granica) + donja_granica;
		}
		printf("\n");
		printf("Vasa matrica je:\n");
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++)
				printf("%d ", pok[i][j]);
			printf("\n");
		}
		printf("\n");
		int iznad_gdg = 0, ispod_gdg = 0;
		int p = 1;
		while (p < n)
		{
			i = 0; j = p;
			while (i < n - 1 && j < n)
			{
				if (pok[i][j] != 0) { iznad_gdg++; break; }
				i++; j++;
			}
			p++;
		}
		printf("Nenultih iznad gdg je : %d\n", iznad_gdg);
		p = 1;
		while (p < n)
		{
			i = p; j = 0;
			while (i < n  && j < n - 1)
			{
				if (pok[i][j] != 0) { ispod_gdg++; break; }
				i++; j++;
			}
			p++;
		}
		printf("Nenultih ispod gdg je : %d\n", ispod_gdg);
		if (iznad_gdg == ispod_gdg)
			printf("MATRICA JE DIJAGONALNA\n");
		else
			printf("MATRICA NIJE DIJAGONALNA\n");
		for (i = 0; i < n; i++)free(*(pok + i));
		free(pok);
		printf("---------------");
		printf("\n");
	}
	system("pause");
	return 0;
}
