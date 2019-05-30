typedef struct k {
	unsigned int ID, kg, klasa, UN;
	struct k* sledeci;
}kontejner;
void ispisi(kontejner*glava);
kontejner* ucitaj_listu();
kontejner *ubaci_na_poc(kontejner *glava);
kontejner *ubaci_na_kraj(kontejner *rep);
kontejner*rep_liste(kontejner*glava);
int duzina_liste(kontejner*glava);
void izbrisi_listu(kontejner *glava);
kontejner* izostavi(kontejner *glava);
void zameni(kontejner*i, kontejner*j);
void sortiraj(kontejner* glava);
kontejner* prepisi(kontejner*tmp, kontejner*k);
int najvise_UN(kontejner*k);
void klasiraj(kontejner* glava);