//Klase za izraze

//*Ako mislite da je gadno raditi na ovakav naèin
//*onda morate biti svjesni da se na ovakav naèin osigurava da svaka klasa može
//*koristiti svaku drugu klasu (rekurzivne produkcije itd.)
#pragma once

class Primarni_izraz{//5
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija3(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija4(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija5(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Postfiks_izraz{//6
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija3(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija4(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija5(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija6(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Lista_argumenata{//2
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Unarni_izraz{//4
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija3(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija4(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Unarni_operator{//4
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija3(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija4(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Cast_izraz{//2
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Ime_tipa{//2
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Specifikator_tipa{//3
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija3(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Multiplikativni_izraz{//4
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija3(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija4(Node, Tablica_djelokruga&, std::string ntip = "");

};

class Aditivni_izraz{//3
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija3(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Odnosni_izraz{//5
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija3(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija4(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija5(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Jednakosni_izraz{//3
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija3(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Bin_i_izraz{//2
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Bin_xili_izraz{//2
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Bin_ili_izraz{//2
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Log_i_izraz{//2
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Log_ili_izraz{//2
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Izraz_pridruzivanja{//2
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};

class Izraz{//2
public:
	povratni_tip produkcija(Node, Tablica_djelokruga&, std::string ntip = "");
private:
	povratni_tip produkcija1(Node, Tablica_djelokruga&, std::string ntip = "");
	povratni_tip produkcija2(Node, Tablica_djelokruga&, std::string ntip = "");
};
