#include<iostream>
#include<string>
#include<vector>
using namespace std;
	
class Pozycja {
public:
	virtual string opis() = 0;
	virtual ~Pozycja(){}
};
class audiobook :public Pozycja {
	//int id;
	string tytul;
public:
	string opis() { return "Audiobook '" + tytul+"'"; }
	audiobook(string tytul) : tytul(tytul){}
};
class ksiazka :public Pozycja {
	//int id;
	string autor;
	string tytul;
public:
	string opis() { return "Ksiazka '" + tytul + "', autor " + autor; }
	ksiazka(string autor, string tytul) :autor(autor),tytul(tytul) {}
};
class film :public Pozycja {
//	int id;
	string rezyser;
	string tytul;
public:
	string opis() { return "Film '" + tytul + "', rezyser: " +rezyser; }
	film(string rezyser, string tytul):rezyser(rezyser),tytul(tytul) {}
};
class Uzytkownik {
	vector<Pozycja*> historia_zamowien;
	int id;
	string imie;
	string nazwisko;	
public:
	Uzytkownik(int id, string imie, string nazwisko):id(id), imie(imie),nazwisko(nazwisko){}
	string dane() { return imie +" " + nazwisko; }
	void dodaj_zamowienie(Pozycja* pozycja) {
		historia_zamowien.push_back(pozycja);
	}
	void pokaz_historie_zamowien() {
		int lp = 1;
		for (auto p : historia_zamowien) {
			cout << lp++<< ". " << p->opis();
		}
	}
	
};
class Uzytkownicy {
	vector<Uzytkownik*> uzytkownicy; 
public:

	void dodaj(Uzytkownik* user) {
		uzytkownicy.push_back(user);
	}
	void dane() {
		for (auto p : uzytkownicy) {
			p->dane();
		}
	}
	Uzytkownik* wsk_user(int lp) {
		return uzytkownicy.at(lp-1);
	}
	void pokaz_uzytkownikow() {
		int lp = 1;
		for (auto p : uzytkownicy) {
			cout << lp++ << ". " << p->dane() << endl;
		}
		cout << endl;
	}

};
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
	vector<Zasob> zasoby;
	vector<pair<Pozycja*, Uzytkownik*>> aktualne_wypozyczenia;
public:
	void dodaj(Zasob* zasob) {
		zasoby.push_back(*zasob);
	}
	void pokaz_zasoby() {
		int id = 1;
		for (auto p : zasoby) {
			cout << id++ << ". " << p.pozycja_wsk->opis() << ", wszystkich: " << p.ilosc << " sztuk" << ", dostepne: " << p.dostepne << endl;
		}
		cout << endl;
	}
	void wypozyczenie(int poz, Uzytkownik* user) {
		if (poz <= zasoby.size()) {
			poz--;
			for (auto  p : zasoby) {
				if (p.pozycja_wsk == zasoby.at(poz).pozycja_wsk) {
					if (p.dostepne > 0) {
						zasoby.at(poz).wypozyczenie();
						user->dodaj_zamowienie(zasoby.at(poz).pozycja_wsk);
						aktualne_wypozyczenia.push_back(make_pair(p.pozycja_wsk, user));
					}
					else
					{
						cout << "Pozycja niedostepna." << endl;
					}
				}
			}
		}
		else {
			cout << "Brak pozycji." << endl;
		}
	}
	void zwrot(int poz) {
		if (poz <= aktualne_wypozyczenia.size()) {
			poz--;
			for (auto p : aktualne_wypozyczenia) {
zasoby.at(poz).zwrot();
//aktualne_wypozyczenia.erase()
			}
			
		}
		else {
			cout << "Brak pozycji do zwrotu" << endl;
		}
	}

	void pokaz_aktualne_wypozyczenia() {
		if (aktualne_wypozyczenia.size() > 0) {
			int lp = 1;
			for (auto p : aktualne_wypozyczenia) {
				cout << lp++ << ". " << p.first->opis() << endl;
				cout<<	", wypozyczone dla " << p.second->dane() << endl;
			}
		}
	}



};

int main() {
		Biblioteka publiczna;
		Uzytkownicy lista_uzytkownikow;

		lista_uzytkownikow.dodaj(new Uzytkownik(1, "Jan", "Kowalski"));
		lista_uzytkownikow.dodaj(new Uzytkownik(2, "Tomasz", "Nowak"));
		lista_uzytkownikow.dodaj(new Uzytkownik(3, "Karol", "Nowak"));
		//Zasob pozycja_w_bibliotece(new audiobook("kjdskjda"), 7, 7);
	//	publiczna.dodaj(pozycja_w_bibliotece);
		publiczna.dodaj(new Zasob(new audiobook("Zly"), 5, 5));
		publiczna.dodaj(new Zasob(new audiobook("bajki"), 5,5));
		publiczna.dodaj(new Zasob (new ksiazka("Huxley", "DP"), 5,5));
		publiczna.dodaj(new Zasob(new film("Tarantino", "PRwH"), 5,5));

		publiczna.pokaz_zasoby();

		//dodanie zamówienia
		lista_uzytkownikow.pokaz_uzytkownikow();
		Uzytkownik* tmp_user = lista_uzytkownikow.wsk_user(1);
		publiczna.wypozyczenie(4,tmp_user);
		
		publiczna.pokaz_zasoby();
		publiczna.pokaz_aktualne_wypozyczenia();
		tmp_user->pokaz_historie_zamowien();





		return 0;
	}

//usuniecie pozycji z aktualnych wypozyczeñ
