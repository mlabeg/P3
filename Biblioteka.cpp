#include<iostream>
#include<vector>


//#include "Pozycja.cpp"
#include "Uzytkownicy.cpp"

#pragma once

class Zasob {
public:
	Pozycja* pozycja_wsk;
	int ilosc;
	int dostepne;
	Zasob(Pozycja* pozycja_wsk, int ilosc, int dostepne) :pozycja_wsk(pozycja_wsk), ilosc(ilosc), dostepne(dostepne) {}

	void wypozyczenie() {
		dostepne--;
	}
	void zwrot() {
		dostepne++;
	}
};
class Biblioteka {
	std::vector<Zasob> zasoby;
	std::vector<std::pair<Pozycja*, Uzytkownik*>> aktualne_wypozyczenia;
public:
	void dodaj(Zasob* zasob) {
		zasoby.push_back(*zasob);
	}
	void pokaz_zasoby() {
		int id = 1;
		for (auto p : zasoby) {
			std::cout << id++ << ". " << p.pozycja_wsk->opis() << ", wszystkich: " << p.ilosc << " sztuk" << ", dostepne: " << p.dostepne << std::endl;
		}
		std::cout << std::endl;
	}
	void wypozyczenie(int poz, Uzytkownik* user) {
		if (poz <= zasoby.size()) {
			poz--;
			for (auto p : zasoby) {
				if (p.pozycja_wsk == zasoby.at(poz).pozycja_wsk) {
					if (p.dostepne > 0) {
						zasoby.at(poz).wypozyczenie();		//to samo co w 131 - odwo³ujê siê do zasobów nie przez "p."
						user->dodaj_zamowienie(zasoby.at(poz).pozycja_wsk);
						aktualne_wypozyczenia.push_back(std::make_pair(p.pozycja_wsk, user));
					}
					else
					{
						std::cout << "Pozycja niedostepna." << std::endl;
					}
				}
			}
		}
		else {
			std::cout << "Brak pozycji." << std::endl;
		}
	}
	void zwrot(int poz) {
		if (poz <= aktualne_wypozyczenia.size()) {
			poz--;
			int n = 0;
			for (auto p : zasoby) {
				if (aktualne_wypozyczenia.at(poz).first == p.pozycja_wsk) {
					//p.zwrot();		- wywo³ywanie funkcji przez wska¿nik p nie pozwala na zmianê wartoœci wewn¹trz innej klasy - to samo co w 110
					zasoby.at(n).zwrot();
				}
				n++;
			}
			aktualne_wypozyczenia.erase(aktualne_wypozyczenia.begin() + poz);
		}
		else {
			std::cout << "Brak pozycji do zwrotu" << std::endl;
		}
	}

	void pokaz_aktualne_wypozyczenia() {
		if (aktualne_wypozyczenia.size() > 0) {
			int lp = 1;
			for (auto p : aktualne_wypozyczenia) {
				std::cout << lp++ << ". " << p.first->opis() << std::endl;
				std::cout << ", wypozyczone dla " << p.second->dane() << std::endl;
			}
			std::cout << std::endl;
		}
		else {
			std::cout << "Brak aktualnych wypozyczen." << std::endl;
		}
	}
};