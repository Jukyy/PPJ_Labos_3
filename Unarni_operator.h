#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Unarni_operator::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
    //cout << "Unarni_operator" << endl;
	povratni_tip xy;
	
	//produkcija 1
	if(produkcija.nodes.size() == 1
    && produkcija.nodes[0].znak.substr(0, produkcija.nodes[0].znak.find(" ")) == "PLUS")
	   xy = Unarni_operator::produkcija1(produkcija.nodes[0], tablica, ntip);
    //produkcija 2
    else if(produkcija.nodes.size() == 1
         && produkcija.nodes[0].znak.substr(0, produkcija.nodes[0].znak.find(" ")) == "MINUS")
	   xy = Unarni_operator::produkcija2(produkcija.nodes[0], tablica, ntip);
    //produkcija 3
    else if(produkcija.nodes.size() == 1
        && produkcija.nodes[0].znak.substr(0, produkcija.nodes[0].znak.find(" ")) == "OP_")
	   xy = Unarni_operator::produkcija3(produkcija.nodes[0], tablica, ntip);
    //produkcija 4
    else if(produkcija.nodes.size() == 1
         && produkcija.nodes[0].znak.substr(0, produkcija.nodes[0].znak.find(" ")) == "KR_INT")
	   xy = Unarni_operator::produkcija4(produkcija.nodes[0], tablica, ntip);
    else throw form_error(produkcija);

	return xy; //nasumièna varijabla xy je tu samo radi toènosti kompaliranja (zamjeni je s potrebnim vrijednostima)
}

//ovdje se nist ne mora ali neka ih
povratni_tip Unarni_operator::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;

	return xy;
}

povratni_tip Unarni_operator::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;

	return xy;
}

povratni_tip Unarni_operator::produkcija3(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;

	return xy;
}

povratni_tip Unarni_operator::produkcija4(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;

	return xy;
}
