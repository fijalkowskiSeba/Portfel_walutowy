#pragma once
#include"waluta.h"
#include"wydarzenie.h"
#include<iostream>
class portfel {
	waluta PLN;
	waluta EUR;
	waluta CHF;
	waluta GPB;
	waluta USD;
	std::list<wydarzenie> historia;
	int numer_zdarzenia;

public:
	std::unordered_map<std::string, waluta*> wskazniki;

	portfel(float pln, float eur, float chf, float gpb, float usd);

	void dodaj_wydarzenie(std::string waluta, std::string typ_operacji, float kwota, std::string druga_waluta);
	void wyswietl_historie();
	void sortuj_historie_kolejnosc();
	void sortuj_historie_waluty();
};