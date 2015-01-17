#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Unarni_izraz::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
    cerr << "Unarni_izraz" << endl;
	povratni_tip xy;
	
	//produkcija 1
	if(produkcija.nodes.size() == 1
    && produkcija.nodes[0].znak == "<postfiks_izraz>")
       xy = Unarni_izraz::produkcija1(produkcija, tablica, ntip);
    //produkcija 2
    else if(produkcija.nodes.size() == 2
         && produkcija.nodes[0].znak.substr(0, produkcija.nodes[0].znak.find(" ")) == "OP_INC"
         && produkcija.nodes[1].znak == "<unarni_izraz>") 
       xy = Unarni_izraz::produkcija2(produkcija, tablica, ntip);
    //produkcija 3
    else if(produkcija.nodes.size() == 2
         && produkcija.nodes[0].znak.substr(0, produkcija.nodes[0].znak.find(" ")) == "OP_DEC"
         && produkcija.nodes[1].znak == "<unarni_izraz>")
       xy = Unarni_izraz::produkcija3(produkcija, tablica, ntip);
    //produkcija 4
    else if(produkcija.nodes.size() == 2
         && produkcija.nodes[0].znak == "<unarni_operator>"
         && produkcija.nodes[1].znak == "<cast_izraz>")
       xy = Unarni_izraz::produkcija4(produkcija, tablica, ntip);

	return xy; //nasumièna varijabla xy je tu samo radi toènosti kompaliranja (zamjeni je s potrebnim vrijednostima)
}

povratni_tip Unarni_izraz::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;
	Postfiks_izraz postfiks_izraz;
	
	//1
	xy = postfiks_izraz.produkcija(produkcija.nodes[0], tablica, ntip);
	
	return xy;
}

povratni_tip Unarni_izraz::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;
	
	//1
	xy = Unarni_izraz::produkcija(produkcija.nodes[1], tablica, ntip);
    //2
    xy.tip = "int";
    xy.l_izraz = false;
	
	return xy;
}

povratni_tip Unarni_izraz::produkcija3(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;
	
	//1
	xy = Unarni_izraz::produkcija(produkcija.nodes[1], tablica, ntip);
    //2
    xy.tip = "int";
    xy.l_izraz = false;
    
	return xy;
}

povratni_tip Unarni_izraz::produkcija4(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;
	Cast_izraz cast_izraz;
	
    //1
	xy = cast_izraz.produkcija(produkcija.nodes[1], tablica, ntip);
    //2
    xy.tip = "int";
    xy.l_izraz = false;
	
	return xy;
}
