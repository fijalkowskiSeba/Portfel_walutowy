#pragma once
#include"konto.h"
#include<fstream>
class waluta :public konto {
	std::string nazwa_waluty;
	float stan_srodkow;
public:
	waluta(std::string nazwa, float stan_konta);

	void zamien(float ile_zamieniasz, waluta& na_co_zamieniasz);
	void dodaj_nowe_srodki(float ile_dodac) override { stan_srodkow += ile_dodac; }
	void wyplac_srodki(float ile_wyplacic) override { stan_srodkow -= ile_wyplacic; }
	float aktualny_stan_srodkow() override { return stan_srodkow; };
	std::string get_nazwa_waluty() { return nazwa_waluty; }

};