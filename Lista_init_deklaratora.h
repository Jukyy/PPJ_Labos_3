#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Lista_init_deklaratora::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
    //cout << "Lista_init_deklaratora" << endl;
	povratni_tip xy;
	
	//produkcija 1
	if(produkcija.nodes.size() == 1
    && produkcija.nodes[0].znak == "<init_deklarator>")
	   xy = Lista_init_deklaratora::produkcija1(produkcija, tablica, ntip);
    //produkcija 2
    else if(produkcija.nodes.size() == 3
         && produkcija.nodes[0].znak == "<lista_init_deklaratora>"
         && produkcija.nodes[1].znak.substr(0, produkcija.nodes[1].znak.find(" ")) == "ZAREZ"
         && produkcija.nodes[2].znak == "<init_deklarator>")
       xy = Lista_init_deklaratora::produkcija2(produkcija, tablica, ntip);
    else throw form_error(produkcija);
	
	return xy; //nasumièna varijabla xy je tu samo radi toènosti kompaliranja (zamjeni je s potrebnim vrijednostima)
}

povratni_tip Lista_init_deklaratora::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;
	Init_deklarator init_deklarator;
	
	//1
	xy = init_deklarator.produkcija(produkcija.nodes[0], tablica, ntip);
	
	return xy;
}

povratni_tip Lista_init_deklaratora::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;
	povratni_tip xy2;
	Init_deklarator init_deklarator;
	
	//1
	xy = Lista_init_deklaratora::produkcija(produkcija.nodes[0], tablica, ntip);
	//2
	xy2 = init_deklarator.produkcija(produkcija.nodes[2], tablica, ntip);
	
	//sta vracam opet xd
	return xy;
}
