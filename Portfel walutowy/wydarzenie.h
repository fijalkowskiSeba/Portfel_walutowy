#pragma once
#include<string>
class wydarzenie {
public:
	int numer_zdarzenia;
	std::string waluta;
	std::string typ_operacji;
	float kwota;
	std::string druga_waluta;

	wydarzenie(int numer_zdarzenia, std::string waluta, std::string typ_operacji, float kwota, std::string druga_waluta) :
		numer_zdarzenia(numer_zdarzenia),
		waluta(waluta),
		typ_operacji(typ_operacji),
		kwota(kwota),
		druga_waluta(druga_waluta)
	{}


};