#pragma once
#include<unordered_map>
#include<string>
class konto {
public:
	virtual void dodaj_nowe_srodki(float ile_dodac) = 0;
	virtual void wyplac_srodki(float ile_wyplacic) = 0;
	virtual float aktualny_stan_srodkow() = 0;
	virtual std::string get_nazwa_waluty() = 0;
	std::unordered_map<std::string, float> kurs;
};