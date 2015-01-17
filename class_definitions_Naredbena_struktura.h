//Klase za naredbenu strukturu programa

//*Ako mislite da je gadno raditi na ovakav naèin
//*onda morate biti svjesni da se na ovakav naèin osigurava da svaka klasa može
//*koristiti svaku drugu klasu (rekurzivne produkcije itd.)
#pragma once

class Slozena_naredba{
public:
	static povratni_tip produkcija(Node, Tablica_djelokruga&, vector<Znakovi> init_znakovi = std::vector<Znakovi>());
private:
	static povratni_tip produkcija1(Node, Tablica_djelokruga&, vector<Znakovi> init_znakovi = std::vector<Znakovi>());
	static povratni_tip produkcija2(Node, Tablica_djelokruga&, vector<Znakovi> init_znakovi = std::vector<Znakovi>());
};

class Lista_naredbi{
public:
	static povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	static povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	static povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Naredba{
public:
	static povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	static povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	static povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
	static povratni_tip produkcija3(Node, Tablica_djelokruga&, std::string ntip = "");
	static povratni_tip produkcija4(Node, Tablica_djelokruga&, std::string ntip = "");
	static povratni_tip produkcija5(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Izraz_naredba{
public:
	static povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	static povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	static povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Naredba_grananja{
public:
	static povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	static povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	static povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Naredba_petlje{
public:
	static povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	static povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	static povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
	static povratni_tip produkcija3(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Naredba_skoka{
public:
	static povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	static povratni_tip produkcija1_2(Node, Tablica_djelokruga&, std::string ntip = "");
	static povratni_tip produkcija3(Node, Tablica_djelokruga&, std::string ntip = "");
	static povratni_tip produkcija4(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Prijevodna_jedinica{
public:
	static povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	static povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	static povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Vanjska_deklaracija{
public:
	static povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	static povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	static povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};
