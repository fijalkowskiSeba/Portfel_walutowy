#include"portfel.h"

portfel::portfel(float pln, float eur, float chf, float gpb, float usd) :
	PLN("PLN", pln),
	EUR("EUR", eur),
	CHF("CHF", chf),
	GPB("GPB", gpb),
	USD("USD", usd),
	numer_zdarzenia(0)
{
	wskazniki.emplace(PLN.get_nazwa_waluty(), &PLN);
	wskazniki.emplace(EUR.get_nazwa_waluty(), &EUR);
	wskazniki.emplace(CHF.get_nazwa_waluty(), &CHF);
	wskazniki.emplace(GPB.get_nazwa_waluty(), &GPB);
	wskazniki.emplace(USD.get_nazwa_waluty(), &USD);

}

void portfel::dodaj_wydarzenie(std::string waluta, std::string typ_operacji, float kwota, std::string druga_waluta)
{
	numer_zdarzenia++;
	wydarzenie nowe_wydarzenie(numer_zdarzenia, waluta, typ_operacji, kwota, druga_waluta);
	historia.push_back(nowe_wydarzenie);
}

void portfel::wyswietl_historie()
{
	for (auto element : historia) {
		std::cout << element.numer_zdarzenia << "\t" << element.waluta << "\t" << element.typ_operacji << "\t" << element.kwota << "\t" << element.druga_waluta << "\n";
	}
}

void portfel::sortuj_historie_kolejnosc()
{
	historia.sort([](const wydarzenie& wydarzenie1, const wydarzenie& wydarzenie2)
		{
			if (wydarzenie1.numer_zdarzenia < wydarzenie2.numer_zdarzenia) return true;
			return false;
		});
}

void portfel::sortuj_historie_waluty()
{
	historia.sort([](const wydarzenie& wydarzenie1, const wydarzenie& wydarzenie2)
		{
			if (wydarzenie1.waluta < wydarzenie2.waluta) return true;
			return false;
		});
}
