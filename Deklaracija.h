#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Deklaracija::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
    cerr << "Deklaracija" << endl;
	povratni_tip xy;
	
	//produkcija1
	if(produkcija.nodes.size() == 3
    && produkcija.nodes[0].znak == "<ime_tipa>"
    && produkcija.nodes[1].znak == "<lista_init_deklaratora>"
    && produkcija.nodes[2].znak.substr(0, produkcija.nodes[2].znak.find(" ")) == "TOCKAZAREZ")
	   xy = Deklaracija::produkcija1(produkcija, tablica, ntip);
	
	return xy; //nasumièna varijabla xy je tu samo radi toènosti kompaliranja (zamjeni je s potrebnim vrijednostima)
}

povratni_tip Deklaracija::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;
	povratni_tip xy2;
	Ime_tipa ime_tipa;
	Lista_init_deklaratora lista_init_deklaratora;
	
	//1
	xy = ime_tipa.produkcija(produkcija.nodes[0], tablica, ntip);
	//2
	xy2 = lista_init_deklaratora.produkcija(produkcija.nodes[1], tablica, xy.tip);
	
	//returnam staaa?
	return xy;
}
