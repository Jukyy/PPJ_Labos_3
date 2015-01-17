#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Odnosni_izraz::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
    //cout << "Odnosni_izraz" << endl;
	povratni_tip xy;
	
	//produkcija 1
	if(produkcija.nodes.size() == 1
    && produkcija.nodes[0].znak == "<aditivni_izraz>")
	   xy = Odnosni_izraz::produkcija1(produkcija, tablica, ntip);
	//produkcija 2
    else if(produkcija.nodes.size() == 3
         && produkcija.nodes[0].znak == "<odnosni_izraz>"
         && produkcija.nodes[1].znak.substr(0, produkcija.nodes[1].znak.find(" ")) == "OP_LT"
         && produkcija.nodes[2].znak == "<aditivni_izraz>") 
	   xy = Odnosni_izraz::produkcija2(produkcija, tablica, ntip);
	//produkcija 3
    else if(produkcija.nodes.size() == 3
         && produkcija.nodes[0].znak == "<odnosni_izraz>"
         && produkcija.nodes[1].znak.substr(0, produkcija.nodes[1].znak.find(" ")) == "OP_GT"
         && produkcija.nodes[2].znak == "<aditivni_izraz>") 
	   xy = Odnosni_izraz::produkcija3(produkcija, tablica, ntip);
	//produkcija 4
    else if(produkcija.nodes.size() == 3
         && produkcija.nodes[0].znak == "<odnosni_izraz>"
         && produkcija.nodes[1].znak.substr(0, produkcija.nodes[1].znak.find(" ")) == "OP_LTE"
         && produkcija.nodes[2].znak == "<aditivni_izraz>") 
	   xy = Odnosni_izraz::produkcija4(produkcija, tablica, ntip);
	//produkcija 5
    else if(produkcija.nodes.size() == 3
         && produkcija.nodes[0].znak == "<odnosni_izraz>"
         && produkcija.nodes[1].znak.substr(0, produkcija.nodes[1].znak.find(" ")) == "OP_GTE"
         && produkcija.nodes[2].znak == "<aditivni_izraz>") 
	   xy = Odnosni_izraz::produkcija5(produkcija, tablica, ntip);
	else throw form_error(produkcija);
	
	return xy; //nasumièna varijabla xy je tu samo radi toènosti kompaliranja (zamjeni je s potrebnim vrijednostima)
}

povratni_tip Odnosni_izraz::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;
	Aditivni_izraz aditivni_izraz;
	
	//1
	xy = aditivni_izraz.produkcija(produkcija.nodes[0], tablica, ntip);
	
	return xy;
}

povratni_tip Odnosni_izraz::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;
	povratni_tip xy2;
	Aditivni_izraz aditivni_izraz;
	
	//1
	xy = Odnosni_izraz::produkcija(produkcija.nodes[0], tablica, ntip);
	//2
    if(!(xy.tip == "int" || xy.tip == "bool" || xy.tip == "char")) throw form_error(produkcija);
	//3
    xy2 = aditivni_izraz.produkcija(produkcija.nodes[2], tablica, ntip);
	//4
    if(!(xy2.tip == "int" || xy2.tip == "bool" || xy2.tip == "char")) throw form_error(produkcija);
	
	xy.l_izraz = false;
	xy.tip = "int";
	return xy;
}

povratni_tip Odnosni_izraz::produkcija3(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;
	povratni_tip xy2;
	Aditivni_izraz aditivni_izraz;
	
	//1
	xy = Odnosni_izraz::produkcija(produkcija.nodes[0], tablica, ntip);
	//2
    if(!(xy.tip == "int" || xy.tip == "bool" || xy.tip == "char")) throw form_error(produkcija);
	//3
    xy2 = aditivni_izraz.produkcija(produkcija.nodes[2], tablica, ntip);
	//4
    if(!(xy2.tip == "int" || xy2.tip == "bool" || xy2.tip == "char")) throw form_error(produkcija);
	
	xy.l_izraz = false;
	xy.tip = "int";
	return xy;
}

povratni_tip Odnosni_izraz::produkcija4(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;
	povratni_tip xy2;
	Aditivni_izraz aditivni_izraz;
	
	//1
	xy = Odnosni_izraz::produkcija(produkcija.nodes[0], tablica, ntip);
	//2
    if(!(xy.tip == "int" || xy.tip == "bool" || xy.tip == "char")) throw form_error(produkcija);
	//3
    xy2 = aditivni_izraz.produkcija(produkcija.nodes[2], tablica, ntip);
	//4
    if(!(xy2.tip == "int" || xy2.tip == "bool" || xy2.tip == "char")) throw form_error(produkcija);
	
	xy.l_izraz = false;
	xy.tip = "int";
	return xy;
}

povratni_tip Odnosni_izraz::produkcija5(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
	povratni_tip xy;
	povratni_tip xy2;
	Aditivni_izraz aditivni_izraz;
	
	//1
	xy = Odnosni_izraz::produkcija(produkcija.nodes[0], tablica, ntip);
	//2
    if(!(xy.tip == "int" || xy.tip == "bool" || xy.tip == "char")) throw form_error(produkcija);
	//3
    xy2 = aditivni_izraz.produkcija(produkcija.nodes[2], tablica, ntip);
	//4
    if(!(xy2.tip == "int" || xy2.tip == "bool" || xy2.tip == "char")) throw form_error(produkcija);
	
	xy.l_izraz = false;
	xy.tip = "int";
	return xy;
}
