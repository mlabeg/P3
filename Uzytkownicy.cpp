#include<iostream>
#include<vector>
#include<string>
#pragma once

#include"Pozycja.cpp"


class Uzytkownik {


public:
	//friend std::istream& operator>>(std::istream& in, Uzytkownik& u);
//	friend std::ostream& operator<<(std::ostream& out, Uzytkownik& u);
	std::vector<Pozycja*> historia_zamowien;
	std::string imie;
	std::string nazwisko;
	static int id;


	Uzytkownik(std::string imie, std::string nazwisko) {
		
		this->imie=imie;
		this->nazwisko=nazwisko;
		this->id=id++;
	}

	std::string dane() { 
		return std::to_string(id) + ". " +imie + " " + nazwisko;
		//return imie + " " + nazwisko;

	}
	void dodaj_zamowienie(Pozycja* pozycja) {
		historia_zamowien.push_back(pozycja);
	}
	void pokaz_historie_zamowien() {
		int lp = 1;
		std::cout << "Historia zamowien  dla " + this->imie + " " + this->nazwisko + ": " << std::endl;
		for (auto p : historia_zamowien) {
			std::cout << lp++ << ". " << p->opis();
		}
	}
	int daj_ID() {
		return id;
	}
	std::string daj_imie() {
		return imie;
	}
	std::string daj_nazwisko() {
		return nazwisko;
	}
};
class Uzytkownicy {
public:
	std::vector<Uzytkownik*> uzytkownicy;

	void dodaj(Uzytkownik* user) {
		uzytkownicy.push_back(user);
	}
	void dane() {
		for (auto p : uzytkownicy) {
			p->dane();
		}
	}
	Uzytkownik* wsk_user(int lp) {
		return uzytkownicy.at(lp - 1);
	}
	void pokaz_uzytkownikow() {
		int lp = 1;
		for (auto p : uzytkownicy) {
			std::cout << lp++ << ". " << p->dane() << std::endl;
		}
		std::cout << std::endl;
	}
	int last_lp() {
		if (uzytkownicy.size() == 0) {
			return 0;
		}
		else
			return uzytkownicy.back()->daj_ID();
	}

};

//w metodzie dodaj u¿yj konstruktora "new" 

/*std::istream& operator>>(std::istream& in, Uzytkownik& u) {
	in >> u.imie >> u.nazwisko;
	return in;
}
std::ostream& operator>>(std::ostream& out, Uzytkownik& u) {
	out << u.daj_ID() << " " << u.daj_imie() << " " << u.daj_nazwisko();
	return out;
}*/