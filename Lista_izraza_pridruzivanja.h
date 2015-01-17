#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Lista_izraza_pridruzivanja::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
    //cout << "Lista_izraza_pridruzivanja" << endl;
	povratni_tip xy;
	
	//produkcija 1
	if(produkcija.nodes.size() == 1
    && produkcija.nodes[0].znak == "<izraz_pridruzivanja>")
	   xy = Lista_izraza_pridruzivanja::produkcija1(produkcija, tablica, ntip);
	//produkcija 2
    else if(produkcija.nodes.size() == 3
         && produkcija.nodes[0].znak == "<lista_izraza_pridruzivanja>"
         && produkcija.nodes[1].znak.substr(0, produkcija.nodes[1].znak.find(" ")) == "ZAREZ"
         && produkcija.nodes[2].znak == "<izraz_pridruzivanja>")
	   xy = Lista_izraza_pridruzivanja::produkcija2(produkcija, tablica, ntip);
    else throw form_error(produkcija);
	
	return xy; //nasumièna varijabla xy je tu samo radi toènosti kompaliranja (zamjeni je s potrebnim vrijednostima)
}

povratni_tip Lista_izraza_pridruzivanja::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;
	Izraz_pridruzivanja izraz_pridruzivanja;
	
	//1 tipovi = taj 1 tip automatski
	xy = izraz_pridruzivanja.produkcija(produkcija.nodes[0], tablica, ntip);
	xy.broj = 1;
	
	return xy;
}

povratni_tip Lista_izraza_pridruzivanja::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;
	povratni_tip xy2;
	Izraz_pridruzivanja izraz_pridruzivanja;
	
	//1
	xy = Lista_izraza_pridruzivanja::produkcija(produkcija.nodes[0], tablica, ntip);
	//2
	xy2 = izraz_pridruzivanja.produkcija(produkcija.nodes[2], tablica, ntip);
	
	xy.tip = xy.tip + "," + xy2.tip;
	xy.broj++;
	
	return xy;
}
