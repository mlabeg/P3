#include<iostream>
#include<string>
#include<vector>
using namespace std;

//stworzyć kontener vector przechowujący zamówienia 

class Pozycja {
public:
	virtual string opis() = 0;
	virtual ~Pozycja(){}
};
class audiobook :public Pozycja {
	int id;
	string tytul;
public:
	string opis() { return "Audiobook '" + tytul+"'"; }
	audiobook(int id, string tytul) :id(id), tytul(tytul){}
};
class ksiazka :public Pozycja {
	int id;
	string autor;
	string tytul;
public:
	string opis() { return "Ksiazka '" + tytul + "', autor " + autor; }
	ksiazka(int id, string autor, string tytul) :id(id), autor(autor),tytul(tytul) {}
};
class film :public Pozycja {
	int id;
	string rezyser;
	string tytul;
public:
	string opis() { return "Film '" + tytul + "', rezyser: " +rezyser; }
	film(int id, string rezyser, string tytul):id(id),rezyser(rezyser),tytul(tytul) {}
};
class Uzytkownik {
	int id;
	string imie;
	string nazwisko;
public:
	string dane() { return "Imie: " + imie + " nazwisko: " + nazwisko; }
	Uzytkownik(int id, string imie, string nazwisko):id(id), imie(imie),nazwisko(nazwisko){}
};
class Uzytkownicy {
	vector<Uzytkownik*> uzytkownicy;
public:
	void dodaj(Uzytkownik* user) {
		uzytkownicy.push_back(user);
	}
};
class Wypozyczenie {
	vector<Pozycja*> wypozyczenie;
	Uzytkownik* wypozyczajacy=nullptr;
public:
	void dodaj(Pozycja* pozycja) {
		wypozyczenie.push_back(pozycja);
	}
	void kto_wypozycza(Uzytkownik USER) {
		wypozyczajacy = &USER;
	}
};
class Wypozyczenia {
	vector < pair<Wypozyczenie*, Uzytkownik*>> historia_zamwowien;
	void dodaj(Wypozyczenie* wypozyczneie, Uzytkownik* uzytkownik) {
		historia_zamwowien.push_back(make_pair(wypozyczneie, uzytkownik));
	}
};
class Biblioteka {
	vector<pair<Pozycja*, int>> zasoby;
public:
	Pozycja* dodaj(Pozycja* pozycja) {
		zasoby.push_back(pozycja); 
	}
	void pokaz_zasoby() {
		int id = 1;
		for (auto &p:zasoby) {
			cout << id << p;
		}
	}
};

int main() {
	Biblioteka publiczna;
	publiczna.dodaj(new audiobook(2, "opowiadania"));
	publiczna.dodaj(new ksiazka(3, "Huxley", "DP"));
	publiczna.dodaj(new film(4, "Tarantino", "PRwH"));
	audiobook adbk(1, "basnie");
	adbk.opis();

	publiczna.pokaz_zasoby();
	//publiczna.wypozyczenie(publiczna.);

	return 0;
} 