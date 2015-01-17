//Klase za deklaracije i definicije

//*Ako mislite da je gadno raditi na ovakav naèin
//*onda morate biti svjesni da se na ovakav naèin osigurava da svaka klasa može
//*koristiti svaku drugu klasu (rekurzivne produkcije itd.)
#pragma once

class Definicija_funkcije{//2
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string, std::string);
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string, std::string);
};

class Lista_parametara{//2
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Deklaracija_parametra{//2
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Lista_deklaracija{//2
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Deklaracija{//1
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Lista_init_deklaratora{//2
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Init_deklarator{//2
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Izravni_deklarator{//4
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija3(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija4(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Inicijalizator{//2
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Lista_izraza_pridruzivanja{//2
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};
