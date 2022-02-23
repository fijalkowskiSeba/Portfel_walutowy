#pragma once

#include<iostream>
#include<string>

template<class portfel>
class menu {
public:
	static void wyplata(portfel& moj_portfel, const std::string& nazwa_waluty);
	static void wplata(portfel& moj_portfel, const std::string& nazwa_waluty);
	static void menu_wymiana(portfel& moj_portfel);
	static void menu_wplata(portfel& moj_portfel);
	static void menu_wyplata(portfel& moj_portfel);
	static void menu_stan_konta(portfel& moj_portfel);
	static void menu_historia(portfel& moj_portfel);
	static void MENU(portfel& moj_portfel);
};

template<class portfel>
inline void menu<portfel>::wyplata(portfel& moj_portfel, const std::string& nazwa_waluty)
{
	system("CLS");
	std::cout << "Wyplata " << nazwa_waluty << "\n";
	std::cout << "Stan konta " << nazwa_waluty << ": " << moj_portfel.wskazniki[nazwa_waluty]->aktualny_stan_srodkow() << "\n";
	std::cout << "Ile chcesz wyplacic?\n";
	float kwota;
	std::cin >> kwota;
	while (kwota > moj_portfel.wskazniki[nazwa_waluty]->aktualny_stan_srodkow() || (kwota < 0)) {
		std::cout << "Podana kwota jest nieprawidlowa, prosze wpisac ponownie:\n";
		std::cin >> kwota;
	}
	moj_portfel.wskazniki[nazwa_waluty]->wyplac_srodki(kwota);
	moj_portfel.dodaj_wydarzenie(nazwa_waluty, "wyplata", kwota, "");
}

template<class portfel>
inline void menu<portfel>::wplata(portfel& moj_portfel, const std::string& nazwa_waluty)
{
	system("CLS");
	std::cout << "Wplata " << nazwa_waluty << "\n";
	std::cout << "Ile chcesz wplacic?\n";
	float kwota;
	std::cin >> kwota;
	while ((kwota < 0)) {
		std::cout << "Podana kwota jest nieprawidlowa, prosze wpisac ponownie:\n";
		std::cin >> kwota;
	}
	moj_portfel.wskazniki[nazwa_waluty]->dodaj_nowe_srodki(kwota);
	moj_portfel.dodaj_wydarzenie(nazwa_waluty, "wplata", kwota, "");
}

template<class portfel>
inline void menu<portfel>::menu_wymiana(portfel& moj_portfel)
{
	system("CLS");
	std::cout << "Wymiana waluty\n";
	std::cout << "Jaka walute bedziesz wymieniac?\n";
	std::cout << "1. PLN\n2. USD\n3. CHF\n4. GPB\n5. EUR\n";
	char wybor;
	std::cin >> wybor;
	std::string wybrana_waluta1;
	if (wybor == '1') wybrana_waluta1 = "PLN";
	else if (wybor == '2') wybrana_waluta1 = "USD";
	else if (wybor == '3') wybrana_waluta1 = "CHF";
	else if (wybor == '4') wybrana_waluta1 = "GPB";
	else if (wybor == '5') wybrana_waluta1 = "EUR";
	else return;
	std::cout << "Na jaka walute chcesz wymienic?\n";
	std::cout << "1. PLN\n2. USD\n3. CHF\n4. GPB\n5. EUR\n";
	std::cin >> wybor;
	std::string wybrana_waluta2;
	if (wybor == '1') wybrana_waluta2 = "PLN";
	else if (wybor == '2') wybrana_waluta2 = "USD";
	else if (wybor == '3') wybrana_waluta2 = "CHF";
	else if (wybor == '4') wybrana_waluta2 = "GPB";
	else if (wybor == '5') wybrana_waluta2 = "EUR";
	else return;
	if (wybrana_waluta1 == wybrana_waluta2) {
		std::cout << "Nie mozna wymienic " << wybrana_waluta1 << " na " << wybrana_waluta2 << " !!!\n";
		system("pause");
		return;
	}
	system("cls");
	std::cout << "Wymiana " << wybrana_waluta1 << " na " << wybrana_waluta2 << "\n";
	std::cout << "Stan konta " << wybrana_waluta1 << "\t" << moj_portfel.wskazniki[wybrana_waluta1]->aktualny_stan_srodkow() << "\n";
	std::cout << "Jaka kwote chesz wymienic?\n";
	float kwota;
	std::cin >> kwota;
	while (kwota<0 || kwota>moj_portfel.wskazniki[wybrana_waluta1]->aktualny_stan_srodkow()) {
		std::cout << "Wybrana kwota jest nieprawidlowa, prosze wprowadzic poprawna kwote\n";
		std::cin >> kwota;
	}
	moj_portfel.wskazniki[wybrana_waluta1]->zamien(kwota, *moj_portfel.wskazniki[wybrana_waluta2]);
	moj_portfel.dodaj_wydarzenie(wybrana_waluta1, "wymiana", kwota, wybrana_waluta2);
}

template<class portfel>
inline void menu<portfel>::menu_wplata(portfel& moj_portfel)
{
	system("CLS");
	std::cout << "Wplata pieniedzy\n";
	std::cout << "Wybierz walute:\n";
	std::cout << "1. PLN\n2. USD\n3. CHF\n4. GPB\n5. EUR\n";
	char wybor;
	std::cin >> wybor;
	if (wybor == '1') { wplata(moj_portfel, "PLN"); }
	else if (wybor == '2') { wplata(moj_portfel, "USD"); }
	else if (wybor == '3') { wplata(moj_portfel, "CHF"); }
	else if (wybor == '4') { wplata(moj_portfel, "GPB"); }
	else if (wybor == '5') { wplata(moj_portfel, "EUR"); }
}

template<class portfel>
inline void menu<portfel>::menu_wyplata(portfel& moj_portfel)
{
	system("CLS");
	std::cout << "Wyplata pieniedzy\n";
	std::cout << "Wybierz walute:\n";
	std::cout << "1. PLN\n2. USD\n3. CHF\n4. GPB\n5. EUR\n";
	char wybor;
	std::cin >> wybor;
	if (wybor == '1') { wyplata(moj_portfel, "PLN"); }
	else if (wybor == '2') { wyplata(moj_portfel, "USD"); }
	else if (wybor == '3') { wyplata(moj_portfel, "CHF"); }
	else if (wybor == '4') { wyplata(moj_portfel, "GPB"); }
	else if (wybor == '5') { wyplata(moj_portfel, "EUR"); }
}

template<class portfel>
inline void menu<portfel>::menu_stan_konta(portfel& moj_portfel)
{

	system("CLS");
	std::cout << "Stan konta\n";
	std::cout << "PLN\t" << moj_portfel.wskazniki["PLN"]->aktualny_stan_srodkow() << "\n";
	std::cout << "USD\t" << moj_portfel.wskazniki["USD"]->aktualny_stan_srodkow() << "\n";
	std::cout << "CHF\t" << moj_portfel.wskazniki["CHF"]->aktualny_stan_srodkow() << "\n";
	std::cout << "GPB\t" << moj_portfel.wskazniki["GPB"]->aktualny_stan_srodkow() << "\n";
	std::cout << "EUR\t" << moj_portfel.wskazniki["EUR"]->aktualny_stan_srodkow() << "\n";
	system("pause");

}

template<class portfel>
inline void menu<portfel>::menu_historia(portfel& moj_portfel) {
	system("cls");
	std::cout << "Historia operacji:\n";
	std::cout << "Wybierz sortowanie:\n1. sortowanie wedlug kolejnosci\n2. Sortowanie walutami\n";
	char wybor;
	std::cin >> wybor;
	if (wybor == '1') moj_portfel.sortuj_historie_kolejnosc();
	else if (wybor == '2') moj_portfel.sortuj_historie_waluty();
	system("cls");
	std::cout << "Historia operacji:\n";
	moj_portfel.wyswietl_historie();
	system("pause");
}

template<class portfel>
inline void menu<portfel>::MENU(portfel& moj_portfel)
{
	while (1 == 1) {
		system("CLS");
		std::cout << "PORTFEL WALUTOWY\n";
		std::cout << "Co chcesz zrobic?\n";
		std::cout << "1. Wyplacic pieniadze\n";
		std::cout << "2. Wplacic pieniadze\n";
		std::cout << "3. Sprawdzic stan konta\n";
		std::cout << "4. Wymienic walute\n";
		std::cout << "5. Historia\n";
		std::cout << "6. Zakoncz\n";
		char wybor;
		std::cin >> wybor;
		if (wybor == '6') return;
		else if (wybor == '1') {
			menu_wyplata(moj_portfel);
		}
		else if (wybor == '2') {
			menu_wplata(moj_portfel);
		}
		else if (wybor == '3') {
			menu_stan_konta(moj_portfel);
		}
		else if (wybor == '4') {
			menu_wymiana(moj_portfel);
		}
		else if (wybor == '5') {
			menu_historia(moj_portfel);
		}
	}
}
