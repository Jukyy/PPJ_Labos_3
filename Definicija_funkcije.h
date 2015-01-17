#pragma once
#include "Tipovi_podataka.h"
#include "class_definitions_Izrazi.h"
#include "class_definitions_Naredbena_struktura.h"
#include "class_definitions_Deklaracije_i_definicije.h"
#include "produkcije.h"

povratni_tip Definicija_funkcije::produkcija(Node produkcija, Tablica_djelokruga &tablica, std::string ntip)
{
    cerr << "Definicija_funkcije" << endl;
	povratni_tip xy;
	
	//produkcija1
	if(produkcija.nodes.size() == 6
	&& produkcija.nodes[0].znak == "<ime_tipa>"
	&& produkcija.nodes[2].znak.substr(0, produkcija.nodes[2].znak.find(" ")) == "L_ZAGRADA"
	&& produkcija.nodes[3].znak.substr(0, produkcija.nodes[3].znak.find(" ")) == "KR_VOID"
	&& produkcija.nodes[4].znak.substr(0, produkcija.nodes[4].znak.find(" ")) == "D_ZAGRADA"
	&& produkcija.nodes[5].znak == "<slozena_naredba>")
	   xy = Definicija_funkcije::produkcija1(produkcija, tablica, ntip, produkcija.nodes[1].znak);
    //produkcija2
    else if(produkcija.nodes.size() == 6
         && produkcija.nodes[0].znak == "<ime_tipa>"
         && produkcija.nodes[2].znak.substr(0, produkcija.nodes[2].znak.find(" ")) == "L_ZAGRADA"
         && produkcija.nodes[3].znak == "<lista_parametara>"
         && produkcija.nodes[4].znak.substr(0, produkcija.nodes[4].znak.find(" ")) == "D_ZAGRADA"
         && produkcija.nodes[5].znak == "<slozena_naredba>")
       xy = Definicija_funkcije::produkcija2(produkcija, tablica, ntip, produkcija.nodes[1].znak);
    
	return xy; //nasumièna varijabla xy je tu samo radi toènosti kompaliranja (zamjeni je s potrebnim vrijednostima)
}

povratni_tip Definicija_funkcije::produkcija1(Node produkcija, Tablica_djelokruga &tablica, std::string ntip, std::string IDN)
{
	povratni_tip xy;
	Ime_tipa ime_tipa;
	//Slozena_naredba slozena_naredba;
	
	//1
	xy = ime_tipa.produkcija(produkcija.nodes[0], tablica, ntip);
	//2  T = int ili char
	//3
	std::string IDNime = IDN.substr(IDN.find(" ")+1);
	IDNime = IDNime.substr(IDNime.find(" ")+1);
	//4
	std::string IDNtip = "funkcija(void->" + xy.tip + ")";
	bool zastavica = false;
	for(int brojac = 0; brojac != tablica.lokalne_variable.size(); brojac++)
	{
        if(tablica.lokalne_variable[brojac].ime == IDNime)
        {
           zastavica = true;
           break;
        }
    }
    //5
    //deklaracija ako vec nije deklarirana
    if(!zastavica)
    {
       Znakovi znak;
       znak.l_izraz = false;
       znak.ime = IDNime;
       znak.tip = IDNtip;
       tablica.lokalne_variable.push_back(znak);
    }
    //definicija
    definicije.push_back(IDNime);
    
	//za juru
	ime_trenutne_funkcije = IDNime;
	
    //6 pravim novu tablicu za slozenu naredbu (blok)
	vector<Znakovi> lokalne_variable;
	xy = Slozena_naredba::produkcija(produkcija.nodes[5], tablica, lokalne_variable);
	
	return xy;
}

povratni_tip Definicija_funkcije::produkcija2(Node produkcija, Tablica_djelokruga &tablica, std::string ntip, std::string IDN)
{
	povratni_tip xy;
	povratni_tip xy2;
	Ime_tipa ime_tipa;
	Lista_parametara lista_parametara;
	//Slozena_naredba slozena_naredba;
	
	//1
	xy = ime_tipa.produkcija(produkcija.nodes[0], tablica, ntip);
	//2  T = int ili char
	//3
	std::string IDNime = IDN.substr(IDN.find(" ")+1);
	IDNime = IDNime.substr(IDNime.find(" ")+1);
    //4
    xy2 = lista_parametara.produkcija(produkcija.nodes[3], tablica, ntip);
    //5
    std::string IDNtip = "funkcija(" + xy2.tip + "->" + xy.tip + ")";
	bool zastavica = false;
	for(int brojac = 0; brojac != tablica.lokalne_variable.size(); brojac++)
	{
        if(tablica.lokalne_variable[brojac].ime == IDNime)
        {
           zastavica = true;
           break;
        }
    }
    //6
    //deklaracija ako vec nije deklarirana
    if(!zastavica)
    {
       Znakovi znak;
       znak.l_izraz = false;
       znak.ime = IDNime;
       znak.tip = IDNtip;
       tablica.lokalne_variable.push_back(znak);
    }
    //definicija
    definicije.push_back(IDNime);
    
    //za juru
	ime_trenutne_funkcije = IDNime;
	
	//7 pravim novu tablicu za slozenu naredbu (blok) i trpam varijable u nju one
    
	
	vector<Znakovi> lokalne_variable;
    
    std::string temp = xy2.ime + ",";
	std::string rijec = "a";
	Znakovi znak;
	while(temp != "")
	{
       rijec = temp.substr(0, temp.find(","));
       temp = temp.substr(temp.find(",")+1);
       znak.ime = rijec;
       lokalne_variable.push_back(znak);
    }
    
    temp = xy2.tip + ",";
    rijec = "a";
    int brojac = 0;
    while(temp != "")
	{
       rijec = temp.substr(0, temp.find(","));
       temp = temp.substr(temp.find(",")+1);
       lokalne_variable[brojac].tip = rijec;
       if(rijec.substr(0,5) == "const") lokalne_variable[brojac].l_izraz = false;
       else lokalne_variable[brojac].l_izraz = true;
	   brojac++;
    }
    
	xy = Slozena_naredba::produkcija(produkcija.nodes[5], tablica, lokalne_variable);
	
	return xy;
}
