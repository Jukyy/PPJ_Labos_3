#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Lista_deklaracija::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
    cerr << "Lista_deklaracija" << endl;
	povratni_tip xy;
	
	//produkcija1
	if(produkcija.nodes.size() == 1
    && produkcija.nodes[0].znak == "<deklaracija>")
	   xy = Lista_deklaracija::produkcija1(produkcija, tablica, ntip);
    //produkcija2
	else if(produkcija.nodes.size() == 2
         && produkcija.nodes[0].znak == "<lista_deklaracija>"
         && produkcija.nodes[1].znak == "<deklaracija>")
	   xy = Lista_deklaracija::produkcija2(produkcija, tablica, ntip);
	
	return xy; //nasumièna varijabla xy je tu samo radi toènosti kompaliranja (zamjeni je s potrebnim vrijednostima)
}

povratni_tip Lista_deklaracija::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;
	Deklaracija deklaracija;
	
	//1
	xy = deklaracija.produkcija(produkcija.nodes[0], tablica, ntip);
	
	return xy;
}

povratni_tip Lista_deklaracija::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;
	povratni_tip xy2;
	Deklaracija deklaracija;
	Lista_deklaracija lista_deklaracija;
	
	//1
	xy = lista_deklaracija.produkcija(produkcija.nodes[0], tablica, ntip);
	//2
	xy2 = deklaracija.produkcija(produkcija.nodes[1], tablica, ntip);
	
	//vracam staa?
	return xy;
}
