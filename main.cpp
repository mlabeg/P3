#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

#include "Biblioteka.cpp"


int main() {
		Biblioteka publiczna;
		Uzytkownicy lista_uzytkownikow;
		fstream user;
		user.open("lista_uzytkownikow.txt", ios::in | ios::out);
		if (user.good() == true) {
			cout << "Uzyskano dostep do pliku" << endl;
		}
		else{
			cout << "Nie uzyskano dostepu do pliku" << endl;
		}
		Uzytkownik* tmp_user = nullptr;
		int zw;
		string name;
		string surname;
		int loop = 1;
		char d;


		lista_uzytkownikow.dodaj(new Uzytkownik(1, "Jan", "Kowalski"));
		lista_uzytkownikow.dodaj(new Uzytkownik(2, "Tomasz", "Nowak"));
		lista_uzytkownikow.dodaj(new Uzytkownik(3, "Karol", "Nowak"));
		while (loop) {
			cout << "Podaj imie: ";
			cin >> name;
			cout << "Podaj nazwisko: ";
			cin >> surname;
			lista_uzytkownikow.dodaj(new Uzytkownik(lista_uzytkownikow.last_lp(), name, surname));
			cout << "Czy dodac nastpnego? ";
				cin >> d;
				if (d == 't' || d == 'T') {}
				else {
					loop = 0;
				}
		}

		publiczna.dodaj(new Zasob(new audiobook("Zly"), 5, 5));	
		publiczna.dodaj(new Zasob(new audiobook("bajki"), 5,5));
		publiczna.dodaj(new Zasob (new ksiazka("Huxley", "DP"), 5,5));
		publiczna.dodaj(new Zasob(new film("Tarantino", "PRwH"), 5,5));

		publiczna.pokaz_zasoby();

		//dodanie zamówienia
		lista_uzytkownikow.pokaz_uzytkownikow();
		tmp_user = lista_uzytkownikow.wsk_user(1);
		publiczna.wypozyczenie(4,tmp_user);
		tmp_user = lista_uzytkownikow.wsk_user(2);
		publiczna.wypozyczenie(4, tmp_user);
		
		publiczna.pokaz_zasoby();
		publiczna.pokaz_aktualne_wypozyczenia();
		//tmp_user->pokaz_historie_zamowien();

		//zwrot zamowienia
		cout << "Wybierz pozycje do zwrotu: ";
		cin >> zw;
		publiczna.zwrot(zw);
		publiczna.pokaz_zasoby();
		publiczna.pokaz_aktualne_wypozyczenia();


		return 0;
	}
