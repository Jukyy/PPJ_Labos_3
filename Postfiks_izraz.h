#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Postfiks_izraz::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
    cerr << "Postfix_izraz" << endl;
	if (produkcija.nodes.size() == 1) 
		return produkcija1(produkcija, tablica);
	else if(produkcija.nodes.size() == 2) 
		return produkcija5(produkcija, tablica);
	else if(produkcija.nodes.size() == 3) 
		return produkcija3(produkcija, tablica);
	else if(produkcija.nodes.size() == 4) {
         if(produkcija.nodes[2].znak[2] == 'U') 
			 return produkcija2(produkcija, tablica);
         else 
			 return produkcija4(produkcija, tablica);
    }
}

povratni_tip Postfiks_izraz::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	Node node = produkcija.nodes[0];
	
	Primarni_izraz izraz;
	izvedbena_vrijednost = izraz.produkcija(node, tablica);
	
	return izvedbena_vrijednost;
}

povratni_tip Postfiks_izraz::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	Node node1 = produkcija.nodes[0];
	Node node2 = produkcija.nodes[2];
	
	Postfiks_izraz izraz1;
	povratni_tip vrijednost1 = izraz1.produkcija(node1, tablica);
	izvedbena_vrijednost.tip = skini(izvedbena_vrijednost.tip, "niz");
	//izvedbena_vrijednost.tip = vrijednost1.tip.substr(4, vrijednost1.tip.length()-1);
	izvedbena_vrijednost.l_izraz = (vrijednost1.constant == false);
	Izraz izraz2; 
	povratni_tip vrijednost2 = izraz2.produkcija(node2, tablica);
	
	//LABOS 4 prosljedjivanje imena_varijable
	//OVO TREBA POPRAVITI
	izvedbena_vrijednost.ime_varijable = vrijednost1.ime_varijable;
	
	return izvedbena_vrijednost;
}

povratni_tip Postfiks_izraz::produkcija3(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	
	Node node = produkcija.nodes[0];
    Postfiks_izraz izraz;
    povratni_tip vrijednost = izraz.produkcija(node, tablica);
    
    std::string pov;
    std::string tip = vrijednost.tip;
    
    pov = tip.substr(15);
	pov = pov.substr(0, pov.find(")"));
	
    izvedbena_vrijednost.tip = pov;
    izvedbena_vrijednost.l_izraz = false;
    
	//LABOS 4 prosljedjivanje imena_varijable
	izvedbena_vrijednost.ime_varijable = vrijednost.ime_varijable.substr(2);
	FRISC::CALL(Vrati_labelu("F_" + izvedbena_vrijednost.ime_varijable));
	FRISC::STORE("R6", "TEMP", tablica.lok_var);
	izvedbena_vrijednost.ime_varijable = "TEMP";
    
	return izvedbena_vrijednost;
}

povratni_tip Postfiks_izraz::produkcija4(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
    
    Node node1 = produkcija.nodes[0];
    Node node2 = produkcija.nodes[2];
    Postfiks_izraz izraz;
    povratni_tip vrijednost_izraz = izraz.produkcija(node1, tablica);
    Lista_argumenata list_args;
    povratni_tip vrijednost_args = list_args.produkcija(node2, tablica);
    
    //LABOS 4 prosljedjivanje varijable
    //globalno ili konst
    string imena = vrijednost_args.ime_varijable + ",";
    string jedno_ime;
    
    while(imena.find(",") != string::npos)
    {
        jedno_ime = imena.substr(0, imena.find(","));
        imena = imena.substr(imena.find(",") + 1);
		
		//ako je varijabla globalna
		if(jedno_ime[0] != 'V')
        {
           FRISC::LOAD("R3", jedno_ime, tablica.lok_var);
           FRISC::PUSH("R3");
        }
        else
        {
           //WAT DO?
        }
	}
	FRISC::CALL(Vrati_labelu("F_" + vrijednost_izraz.ime_varijable.substr(2)));
	FRISC::STORE("R6", "TEMP", tablica.lok_var);
	//POPANJE STOGA KAO
	imena = vrijednost_args.ime_varijable + ",";
    while(imena.find(",") != string::npos)
    {
        imena = imena.substr(imena.find(",") + 1);
		FRISC::ADD("R7", "4", "R7");
	}
	
	izvedbena_vrijednost.ime_varijable = "TEMP";
	
    
    std::string tip = vrijednost_izraz.tip;
    std::string pov, args, params;
    vector <std::string> arg, param;
    params = vrijednost_args.tip;

	args = tip.substr(tip.find('(')+1);
	args = args.substr(0, args.find("->"));

	pov = tip.substr(tip.find('>')+1);
	pov = pov.substr(0, pov.find(")"));

    izvedbena_vrijednost.tip = pov;
    izvedbena_vrijednost.l_izraz = false;
    
	while (args.find(",") != string::npos) {
		arg.push_back(args.substr(0, args.find(",")));
		args = args.substr(args.find(",")+1);
	}
	arg.push_back(args);

	while (params.find(",") != string::npos) {
		param.push_back(params.substr(0, params.find(",")));
		params = params.substr(params.find(",") + 1);
	}
	param.push_back(params);

	/*for (unsigned last = 0, i = 0; i < args.size(); ++i) {
        if(param[i] == ',' ) {
            arg.push_back(args.substr(last, i));
            last = i + 1;
        }
        if(i + 1 == args.size()) arg.push_back(args.substr(last, i + 1));
    }
    
	for (unsigned last = 0, i = 0; i < params.size(); ++i) {
        if(params[i] == ',' ) {
            param.push_back(params.substr(last, i));
            last = i + 1;
        }
        if(i + 1 == params.size()) param.push_back(params.substr(last, i + 1));
    }*/
    
	return izvedbena_vrijednost;
}

povratni_tip Postfiks_izraz::produkcija5(Node produkcija, Tablica_djelokruga &tablica, std::string ntip){
	povratni_tip izvedbena_vrijednost;
	izvedbena_vrijednost.tip = "int";
	izvedbena_vrijednost.l_izraz = false;
    Node node = produkcija.nodes[0];
	
	Postfiks_izraz izraz;
	povratni_tip vrijednost = izraz.produkcija(node, tablica);
	
	//LABOS 4 prosljedjivanje imena_varijable
	izvedbena_vrijednost.ime_varijable = vrijednost.ime_varijable;
	
	return izvedbena_vrijednost;
}

