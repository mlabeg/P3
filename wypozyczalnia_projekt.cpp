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
	string opis() { return "Film '" + tytul + "' rezyser: "; }
	film(int id, string rezyser, string tytul) {}
};
class Biblioteka {
	vector<Pozycja*> zasoby;
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
/*	Magazyn magazyn;
	magazyn.dodaj(new Dysk(100, 256), 25);
	magazyn.dodaj(new Dysk(100, 512), 30);
	magazyn.dodaj(new Monitor(200, 22), 15);
	magazyn.dodaj(new pamiec_RAM(300, 4), 4);
	magazyn.pokaz();
	Zamowienie zamowienie;
	cout << endl << endl << "Tworzenie zamowienia\nWybierz produkt i jego ilosc (lub wpisz z, aby zakonczyc): ";
	int id, ile;
	float wartoscCalegoZamowienia = 0;
	while (cin >> id >> ile) {
		Produkt*pobrany_produkt = nullptr;
		pobrany_produkt = magazyn.pobierz(id, ile);
		if (pobrany_produkt) {
			cout << "Pobrany produkt: " << pobrany_produkt->opis()<<", ilosc: "<<ile<<endl; //wywolanie polimorficzne
			cout << "Wartoc pobranej pozycji: " << to_string(ile * pobrany_produkt->podaj_cene()) << " zl";
			wartoscCalegoZamowienia += ile * pobrany_produkt->podaj_cene();
			zamowienie.dodaj(pobrany_produkt, ile);
		}
		else cout << " - nie mozna dodac do zamowienia";

		cout << endl << "Wybierz nastepny produkt i jego ilosc (lub wpisz z, aby zakonczyc): ";
	}
	
	zamowienie.drukuj();
	cout << endl << "Wartosc calego zamowienia: " << to_string(wartoscCalegoZamowienia);
	magazyn.pokaz();
	*/
	return 0;
}
