#pragma once
#include <iostream>
#include <string>

using namespace std;

class FRISC{
public:
	static void pocetneInstrukcije(){
		cout << "\tMOVE 40000, R7" << endl;
		cout << "\tCALL F_MAIN" << endl;
		cout << "\tHALT" << endl;
	}

	static void spremiKontekst(){
		cout << "\tPUSH R0" << endl;
		cout << "\tPUSH R1" << endl;
		cout << "\tPUSH R2" << endl;
		cout << "\tPUSH R3" << endl;
		cout << "\tPUSH R4" << endl;
		cout << "\tPUSH R5" << endl;
	}

	static void vratiKontekst(){
		cout << "\tPOP R5" << endl;
		cout << "\tPOP R4" << endl;
		cout << "\tPOP R3" << endl;
		cout << "\tPOP R2" << endl;
		cout << "\tPOP R1" << endl;
		cout << "\tPOP R0" << endl;
	}

	static void funkcijaMnozi(){
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

	static void funkcijaDijeli(){
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

	static void funkcijaOstatak(){

	}

	static void label(std::string label){
		cout << label << endl;
	}

	static void ADD(std::string src1, std::string src2, std::string dest){
		cout << "\tADD " << src1 << ", " << src2 << ", " << dest << endl;
	}

	static void ADC(std::string src1, std::string src2, std::string C, std::string dest){
		cout << "\tADC " << src1 << ", " << src2 << " + " << C << ", " << dest << endl;
	}

	static void SUB(std::string src1, std::string src2, std::string dest){
		cout << "\tADD " << src1 << ", " << src2 << ", " << dest << endl;
	}

	static void SBC(std::string src1, std::string src2, std::string C, std::string dest){
		cout << "\tSBC " << src1 << ", " << src2 << " + " << C << ", " << dest << endl;
	}

	static void CMP(std::string src1, std::string src2){
		cout << "\tCMP " << src1 << ", " << src2 << endl;
	}

	static void AND(std::string src1, std::string src2, std::string dest){
		cout << "\tAND " << src1 << ", " << src2 << ", " << dest << endl;
	}

	static void OR(std::string src1, std::string src2, std::string dest){
		cout << "\tOR " << src1 << ", " << src2 << ", " << dest << endl;
	}

	static void XOR(std::string src1, std::string src2, std::string dest){
		cout << "\tXOR " << src1 << ", " << src2 << ", " << dest << endl;
	}

	static void SHL(std::string src1, std::string src2, std::string dest){
		cout << "\tSHL " << src1 << ", " << src2 << ", " << dest << endl;
	}

	static void SHR(std::string src1, std::string src2, std::string dest){
		cout << "\tSHR " << src1 << ", " << src2 << ", " << dest << endl;
	}

	static void ASHR(std::string src1, std::string src2, std::string dest){
		cout << "\tADD " << src1 << ", " << src2 << ", " << dest << endl;
	}

	static void ROTL(std::string src1, std::string src2, std::string dest){
		cout << "\tADD " << src1 << ", " << src2 << ", " << dest << endl;
	}

	static void ROTR(std::string src1, std::string src2, std::string dest){
		cout << "\tADD " << src1 << ", " << src2 << ", " << dest << endl;
	}

	static void spremiKonstantu(std::string label, int value){
		cout << label << endl;
		cout << "\tDW %D " << value << endl;
	}

	static void MOVE(std::string src, std::string dest){
		cout << "\tMOVE " << src << ", " << dest << endl;
	}

	static void LOAD(std::string dest, std::string src){
		cout << "\tLOAD " << dest << ", (" << src << ")" << endl;
	}

	static void STORE(std::string dest, std::string src){
		cout << "\tSTORE " << dest << ", (" << src << ")" << endl;
	}

	static void PUSH(std::string reg){
		cout << "\tPUSH " << reg << endl;
	}

	static void POP(std::string reg){
		cout << "\tPOP " << reg << endl;
	}

	static void JP(std::string condition, string adr){
		cout << "\tJP_" << condition << " " << adr << endl;
	}
	static void JP(string adr){
		cout << "\tJP " << adr << endl;
	}

	static void CALL(std::string fun){
		cout << "\tCALL " << fun << endl;
	}

	static void RET(){
		cout << "\tRET" << endl;
	}

	static void HALT(){
		cout << "\tHALT" << endl;
	}

};