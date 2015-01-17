#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "FRISC_instrukcije.h"

using namespace std;

#define LOOP 1
#define NOT_LOOP 0
#define UNDEFINED_LOOP 99

typedef struct _Uniformni_znak{
	std::string type;
	int line;
	std::string value;
} Uniformni_znak; //trenutno ga ne koristim

typedef struct _Node{
	std::string znak;
	bool zavrsni;
	vector<_Node> nodes;
} Node;

typedef struct _Znakovi{
	std::string ime;
	std::string tip;
	bool l_izraz;
} Znakovi;

typedef struct _Tablica_djelokruga{
	_Tablica_djelokruga *ugnijezdena_tablica;
	vector<_Tablica_djelokruga> lokalne_tablice;
	bool is_global;
	bool is_loop;
	bool from_function;
	vector<Znakovi> lokalne_variable;
} Tablica_djelokruga;

typedef struct _povratni_tip{
	std::string ime;
	std::string ime_varijable;
	std::string tip;
	bool l_izraz;
	int broj;
	bool constant;
	//Ovdje nadodajte dodatne potrebne izvedbene vrijednosti
	//Dodavanje novih elemenata neèe poremetiti kompatabilnost:)
}povratni_tip;

int loop_status = NOT_LOOP;

vector<std::string> definicije;
std::string ime_trenutne_funkcije;

