#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Specifikator_tipa::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
    //cout << "Specifikator tipa" << endl;
	povratni_tip xy;
	
	//produkcija 1
	if(produkcija.nodes.size() == 1
    && produkcija.nodes[0].znak.substr(0, produkcija.nodes[0].znak.find(" ")) == "KR_VOID")
	   xy = Specifikator_tipa::produkcija1(produkcija.nodes[0], tablica, ntip);
    //produkcija 2
    else if(produkcija.nodes.size() == 1
         && produkcija.nodes[0].znak.substr(0, produkcija.nodes[0].znak.find(" ")) == "KR_CHAR")
	   xy = Specifikator_tipa::produkcija2(produkcija.nodes[0], tablica, ntip);
    //produkcija 3
    else if(produkcija.nodes.size() == 1
         && produkcija.nodes[0].znak.substr(0, produkcija.nodes[0].znak.find(" ")) == "KR_INT")
	   xy = Specifikator_tipa::produkcija3(produkcija.nodes[0], tablica, ntip);
    else throw form_error(produkcija);

	return xy; //nasumièna varijabla xy je tu samo radi toènosti kompaliranja (zamjeni je s potrebnim vrijednostima)
}

povratni_tip Specifikator_tipa::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;
	
	xy.tip = "void";
	
	return xy;
}

povratni_tip Specifikator_tipa::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;
	
	xy.tip = "char";
	
	return xy;
}

povratni_tip Specifikator_tipa::produkcija3(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;
	
	xy.tip = "int";
	
	return xy;
}
