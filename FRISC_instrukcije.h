#pragma once
#include <iostream>
#include "FRISC/Labeliranje.h"

using namespace std;

void pocetneInstrukcije(){
	cout << "\tMOVE 40000, R7" << endl;
	cout << "\tCALL ";
    Stvori_novu_labelu("F_main");
    cout << Vrati_labelu("F_main") << endl;
	cout << "\tHALT" << endl;
}

void spremiKontekst(){
	cout << "\tPUSH R0" << endl;
	cout << "\tPUSH R1" << endl;
	cout << "\tPUSH R2" << endl;
	cout << "\tPUSH R3" << endl;
	cout << "\tPUSH R4" << endl;
	cout << "\tPUSH R5" << endl;
}

void vratiKontekst(){
	cout << "\tPUSH R5" << endl;
	cout << "\tPUSH R4" << endl;
	cout << "\tPUSH R3" << endl;
	cout << "\tPUSH R2" << endl;
	cout << "\tPUSH R1" << endl;
	cout << "\tPUSH R0" << endl;
}

void funkcijaMnozi(){
	cout << "MULT" << endl;
	cout << "\tLOAD R0, (R7 + 8)" << endl;
	cout << "\tLOAD R1, (R7 + 4)" << endl;
	cout << "\tPUSH R2" << endl;
	cout << "\tPUSH R3" << endl;
	cout << "\tAND R3, 0, R3" << endl;
	cout << "\tAND R2, 0, R2" << endl;

	cout << "MULT_FIRST" << endl;
	cout << "\tADD R0, 0, R0" << endl;
	cout << "\tJP_P MULT_SECOND" << endl;
	cout << "\tADD R3, 1, R3" << endl;
	cout << "\tSUB R2, R0, R0" << endl;

	cout << "MULT_SECOND" << endl;
	cout << "\tADD R1, 0, R1" << endl;
	cout << "\tJP_P MULT_INIT" << endl;
	cout << "\tADD R3, 1, R3" << endl;
	cout << "\tSUB R2, R1, R1" << endl;

	cout << "MULT_INIT" << endl;
	cout << "\tMOVE R0, R2" << endl;
	cout << "\tAND R0, 0, R0" << endl;

	cout << "MLOOP" << endl;
	cout << "\tCMP R2, 0" << endl;
	cout << "\tJP_Z MEND_1" << endl;
	cout << "\tADD R0, R1, R0" << endl;
	cout << "\tSUB R2, 1, R2" << endl;
	cout << "\tJP MLOOP" << endl;

	cout << "MEND_1" << endl;
	cout << "\tCMP R3, 1" << endl;
	cout << "\tJP_NE MEND_2" << endl;
	cout << "\tSUB R2, R0, R0" << endl;

	cout << "MEND_2" << endl;
	cout << "\tMOVE R0, R6" << endl;
	cout << "\tPOP R3" << endl;
	cout << "\tPOP R2" << endl;
	cout << "\tRET" << endl;
}

void funkcijaDijeli(){
	cout << "DIV" << endl;
	cout << "\tLOAD R0, (R7 + 8)" << endl;
	cout << "\tLOAD R1, (R7 + 4)" << endl;
	cout << "\tPUSH R2" << endl;
	cout << "\tPUSH R3" << endl;
	cout << "\tAND R2, 0, R2" << endl;
	cout << "\tAND R3, 0, R3" << endl;

	cout << "DIV_FIRST" << endl;
	cout << "\tADD R0, 0, R0" << endl;
	cout << "\tJP_P DIV_SECOND" << endl;
	cout << "\tADD R3, 1, R3" << endl;
	cout << "\tSUB R2, R0, R0" << endl;

	cout << "DIV_SECOND" << endl;
	cout << "\tADD R1, 0, R1" << endl;
	cout << "\tJP_P DLOOP" << endl;
	cout << "\tADD R3, 1, R3" << endl;
	cout << "\tSUB R2, R1, R1" << endl;

	cout << "DLOOP" << endl;
	cout << "\tSUB R0, R1, R0" << endl;
	cout << "\tJP_ULT DEND_1" << endl;
	cout << "\tADD R2, 1, R2" << endl;
	cout << "\tJP DLOOP" << endl;
	cout << "DEND_1" << endl;
	cout << "\tCMP R3, 1" << endl;
	cout << "\tJP_NE DEND_2" << endl;
	cout << "\tAND R3, 0, R3" << endl;
	cout << "\tSUB R3, R2, R2" << endl;

	cout << "DEND_2" << endl;
	cout << "\tMOVE R2, R6" << endl;
	cout << "\tPOP R3" << endl;
	cout << "\tPOP R2" << endl;
	cout << "\tRET" << endl;
}
