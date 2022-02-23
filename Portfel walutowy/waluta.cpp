#include"waluta.h"

waluta::waluta(std::string nazwa, float stan_konta) :
	nazwa_waluty(nazwa),
	stan_srodkow(stan_konta) {
	std::ifstream input("kurs.txt");
	if (!input) std::exit(0);
	std::string text;
	float number;
	while (input >> text && input >> number) {
		kurs.emplace(text, number);
	}
}

void waluta::zamien(float ile_zamieniasz, waluta& na_co_zamieniasz)
{
	stan_srodkow -= ile_zamieniasz;
	float zamieniona_kasa_PLN = ile_zamieniasz * kurs[nazwa_waluty];
	float zamieniona_kasa_inna_waluta = zamieniona_kasa_PLN / kurs[na_co_zamieniasz.get_nazwa_waluty()];
	na_co_zamieniasz.dodaj_nowe_srodki(zamieniona_kasa_inna_waluta);
}
