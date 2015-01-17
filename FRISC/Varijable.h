#pragma once
#include <string.h>
#include <map>
//<>

/*****     DIO ZA LOKALNE VARIJABLE    *****/
struct Lokalne_varijable
{
   map<string, int> varijable;
   Lokalne_varijable * nadtablica;
   Lokalne_varijable * podtablica;
};

//ubacivanje varijable u listu
void Registriraj_varijablu(Lokalne_varijable * tablica, string ime)
{
   map<string, int>::iterator it = tablica->varijable.begin();
   //povecaj sve offsete za 4
   while(it != tablica->varijable.end())
   {
      it->second += 4;
      it++;
   }
   //dodaj novu varijablu
   tablica->varijable[ime] = 0;
   
   return;
}

//funkcija koju treba pozvati kada se ulazi u blok
Lokalne_varijable * Stvori_novu_tablicu(Lokalne_varijable * nadtablica)
{
   Lokalne_varijable *nova_tablica = (Lokalne_varijable*)malloc(sizeof(Lokalne_varijable));
   
   nova_tablica->nadtablica = nadtablica;
   nova_tablica->podtablica = NULL;
   
   return nova_tablica;
}

//funkcija koja ce pronaci offset varijable
int Pronadji_offset_varijable(Lokalne_varijable * tablica, string ime)
{
   int offset = 0;
   
   while(1)
   {
      //ako je tablica u lokalnoj sve stima
      if(tablica->varijable.find(ime) != tablica->varijable.end())
      {
         offset += tablica->varijable[ime];
         break;
      }
      else //inace ako nije u tablici odi u vanjsku
      {
         //ako nema vanjsku tablicu onda treba pogledat u globalno
         if(tablica->nadtablica == NULL)
         {
            //vrati -1 da se zna da je globalno
            offset = -1;
            break;
         }
         else
         {
            //ako postoji nadtablica odi u nju i preskoci varijable trenutne tablice
            offset += tablica->varijable.size()*4;
            tablica = tablica->nadtablica;
         }
      }
   }
   
   return offset;
}

/*****     DIO ZA GLOBALNE VARIJABLE    *****/
