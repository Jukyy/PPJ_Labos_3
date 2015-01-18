#pragma once
#include <map>
#include <string.h>
//<>
using namespace std;

map <string, int> labele;
vector <string> konstante;

//napravi novi tip labele
void Stvori_novu_labelu(string labela)
{
   //ako je labela funkcije onda se ponasaj na drugi nacin
   //samo jednom se moze deklarirat i nikad vise
   if(labela[0] == 'F')
   {
      if(labele.find(labela) == labele.end())
         labele[labela] = 1;
      return;
   }
   //ako nije u listi labela
   if(labele.find(labela) == labele.end())
      labele[labela] = 1;
   else
      labele[labela]++;
   
   return;
}
void Stvori_novu_labelu(string labela, string vrijednost)
{
   //ako pridodajemo globalnoj varijabli pocetnu vrijednost
   if(labela == "TEMP")
   {
      labele[labela] = atoi(vrijednost.c_str());
      return;
   }
   else if(labela[0] == 'G')
   {
      labele[labela] = atoi(vrijednost.c_str());
      return;
   }
   //ako nije u listi labela
   if(labele.find(labela) == labele.end())
      labele[labela] = 1;
   else
      labele[labela]++;
   //ako je labela == K_K zapamti vrijednost u vektoru konstanti
   if(labela == "K_K")
      konstante.push_back(vrijednost);
   
   return;
}

//mjenjanje pocente vrijednosti varijable
void Postavi_pocetnu_vrijednost(string labela, string vrijednost)
{
   labele[labela] = atoi(vrijednost.c_str());
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
