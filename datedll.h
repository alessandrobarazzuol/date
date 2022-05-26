/*
===============================================================================================
LIBRERIA dinamica (DLL ) DATE: calcola la differenza in giorni tra due date 
autore: classe 2G 2021-2022
Dev-C++ version 5.5.2 
Compilatore: MINGW64 
===============================================================================================
*/


#ifndef _DATEDLL_H_
#define _DATEDLL_H_

using namespace std;

extern "C"
{
__declspec(dllexport) int  giorni(int g1,int m1,int a1, int g2, int m2, int a2);	//calcola la differenza tra date
__declspec(dllexport) bool dv(int g, int m, int a);									//controlla se una data è valida in base al Calendario Gregoriano
__declspec(dllexport) int  g_mese(int a, int m);									// ritona il numero di giorni di quel mese di quell'anno
__declspec(dllexport) bool bisestile(int a);										//controlla se un anno è bisestile
__declspec(dllexport) int  confronto(int g1, int m1, int a1, int g2, int m2, int a2);//confronta due date
__declspec(dllexport) void data_succ(int &g, int &m, int &a);						//calcola la data successiva ad una data

};

#endif
