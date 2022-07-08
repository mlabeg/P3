#include<iostream>
#include<string>
#include<vector>
using namespace std;

//stworzyæ kontener vector przechowuj¹cy zamówienia 

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
	void dodaj() {
		uzytkownicy.push_back(new Uzytkownik(1, "Jan", "Nowak"));
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
class Biblioteka {
	vector<Pozycja*> zasoby;
public:
	void dodaj(Pozycja* pozycja) {
		zasoby.push_back(pozycja); 
	}
	void pokaz_zasoby() {
		int id = 1;
		for (auto p:zasoby) {
			cout << id++<<". " << p->opis() << endl;
		}
	}
	void wypozyczenie(Pozycja* pozycja) {
		Wypozyczenie wyp1;
		wyp1.dodaj(pozycja);

	}
};


//klasa USER
// 
// 
//class zasoby_biblioteki {
//	vector<pair<Pozycja*,int>> zasoby;
//public:
//	void dodaj(Pozycja* , int ilosc) {
//		int q = 1;
//		for (auto& p : zasoby) {
//			if (p.first->opis() == Pozycja->opis()) {
//				p.second += ilosc;
//				q = 0;
//			}
//		}
//		if (q)
//			zasoby.push_back(make_pair(pozycja, ilosc));
//	}
//	void pokaz() {
//		int id = 1;
//		cout << endl << endl << "Stan wypozyczalni: "<<endl;
//		for (auto &p : zasoby) {
//			cout << endl <<id++ <<": "<< p.first->opis() << ", sztuk " << p.second;
//
//		}
//	}
//	Pozycja* pobierz(int id) {
//		--id;
//		try {
//			if (zasoby.at(id).second>=1) {
//				zasoby.at(id).second -= 1;
//				return zasoby.at(id).first;
//			}
//			else {
//				cout << "Brak zasobów.";
//			}
//		}
//		catch (out_of_range & e) {
//			cout << "Nieprawidlowy numer produktu";
//		}
//		return nullptr;
//	}
//};
//class user {
//
//	int id;
//	string imie;
//	string nazwisko;
//public:
//	user(string imie, string nazwisko, int id) : imie(imie), nazwisko(nazwisko), id(id) {}
//	string daj_dane{ return "ID: "+to_string(id) +", imie: " + imie + ", nazwisko : " + nazwisko; }
//};
//class Wypozyczenie {
//	user* uzytkownik;
//	vector<Pozycja*> wypozyczenie;
//public:
//	Wypozyczenie(Pozycja* pozycja) :Pozycja(pozycja) {}
//	void dodaj(Pozycja* pozycja) {
//		wypozyczenie.push_back(new Pozycja);
//	}
//	void drukuj() {
//		int nr = 1;
//		cout << endl << endl << "Wypozyczenie";
//		for (auto&pz : wypozyczenie) {
//			cout << endl << pz + 1 << ": " << pz->opis();
//		}
//	}
//};

int main() {
	Biblioteka publiczna;
	publiczna.dodaj(new audiobook(2, "opowiadania"));
	publiczna.dodaj(new ksiazka(3, "Huxley", "DP"));
	publiczna.dodaj(new film(4, "Tarantino", "PRwH"));
	audiobook adbk(1, "basnie");
	adbk.opis();

	publiczna.pokaz_zasoby();
	publiczna.wypozyczenie(&film(4, "Tarantino", "PRwH"));

	return 0;
}
