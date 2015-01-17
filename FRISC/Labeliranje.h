
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <map>
#include <string.h>
//<>

map <string, int> labele;

//napravi novi tip labele
void Stvori_novu_labelu(string labela)
{
   //ako nije u listi labela
   if(labele.find(labela) == labele.end())
      labele[labela] = 1;
   else
      labele[labela]++;
   
   return;
}

//funkcija koja samo ispisuje zadnju napravljenu labelu tog tipa
//koristimo za petlje npr i kod ispisa globalnih varijabli na kraju
void Labeliraj(string labela)
{
   cout << labela << "_" << labele[labela] << endl;
   return;
}

//formatiraj zadnje dodanu labelu nekog tipa u string
string Vrati_labelu(string labela)
{
   char nesto[50];
   sprintf(nesto, "%d\0", labele[labela]);
   string ret(nesto);
   ret = labela + "_" + ret;
   
   return ret;
}
