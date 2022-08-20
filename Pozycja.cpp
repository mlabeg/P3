#include<iostream>

class Pozycja {
public:
	virtual std::string opis() = 0;
	virtual ~Pozycja() {}
};
class audiobook :public Pozycja {
	std::string autor;
	std::string tytul;
public:
	std::string opis() { return "Audiobook '" + tytul + "'"; }
	audiobook(std::string tytul) : tytul(tytul) {}
};
class ksiazka :public Pozycja {
	std::string autor;
	std::string tytul;
public:
	std::string opis() { return "Ksiazka '" + tytul + "', autor " + autor; }
	ksiazka(std::string autor, std::string tytul) :autor(autor), tytul(tytul) {}
};
class film :public Pozycja {
	std::string rezyser;
	std::string tytul;
public:
	std::string opis() { return "Film '" + tytul + "', rezyser: " + rezyser; }
	film(std::string rezyser, std::string tytul) :rezyser(rezyser), tytul(tytul) {}
};