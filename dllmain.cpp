
#include "datedll.h"
#include <windows.h>
#include<iostream>
/*
.---------------------.
| Differenza tra date. |
'---------------------'
Autore: alessandro barazzuol
Data 14/02/2022
Strutture
MinGW64- GCC
*/

/*
Differenza in giorni tra due date
Prima verifico se le date sono valide
Partiamo dalla d1, andiamo avanti di un giorno fino che arriviamo alla d2 
e contiamo. Il conteggio ci ritorna il numero di giorni tra le due date
*/


int giorni(int g1,int m1,int a1, int g2, int m2, int a2) 
{
	       
	
	        if(!dv(g1,m1,a1) || !dv(g2,m2,a2))
	        	return 0;
	
		    if(confronto(g1,m1,a1,g2,m2,a2)==1)
		    {
		    	swap(g1,g2);
		    	swap(m1,m2);
		    	swap(a1,a2);
			}
		
		
		
		
		
			int conta=0;
			while(confronto(g1,m1,a1,g2,m2,a2)!=0)
			{
				data_succ(g1,m1,a1);
				conta++;
			}
			return conta;
		

}

void data_succ(int &g, int &m, int &a)
{
	if(g<g_mese(a,m))
	{
		g=g+1;
	}
	else
	{
	    g=1;
	    if(m<12)
	       m=m+1;
	    else
	    {
	       m=1;
	       a=a+1;
		}
	
	}
}

// ritorna -1 se d1<d2, 1 se d1>d2, 0 se d1==d2
int confronto(int g1, int m1, int a1, int g2, int m2, int a2)
{
	if(a1<a2)
		return -1;
	else if(a1>a2)
	{
		return 1;
	}
	else // stesso anno
	{
		if(m1<m2)
			return -1;
		else if(m1>m2)
			return 1;
		else  // stesso anno, stesso mese
		{
			if(g1<g2)
				return -1;
			else if(g1>g2)
				return 1;
			else // stesso anno, stesso mese, stesso giorno
			{
				return 0;
			}
		}
	}
}

bool bisestile(int a)
{
	if((a%100!=0 && a%4==0) || a%400==0)//da Wikipedia
		return true;
	else
		return false;
	
}

int g_mese(int a, int m)
{
	switch(m)
	{
		case 1:
			case 3:
				case 5:
				   case 7:
				   	  case 8:
				   	  	 case 10:
				   	  	 	case 12:
				   	  	 		return 31;
				   	  	 		//break;
		case 2:
			if(bisestile(a))
			return 29;
			else
			return 28;
			//break;
	    case 4:
		    case 6:
			    case 9:
				   case 11:
				      return 30;
					  //break;		
		
	}
}



bool dv(int g, int m, int a)
{
	if(a<1582)
		return false;
	if(m<1 || m>12)
		return false;
	if(g<1 || g>g_mese(a,m))
		return false;
	
	return true;
}




BOOL APIENTRY DllMain( HINSTANCE hModule,DWORD fdwReason,LPVOID lpvReserved)
{
	switch(fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
		
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			break;
		}
		case DLL_THREAD_ATTACH:
		{
			break;
		}
		case DLL_THREAD_DETACH:
		{
			break;
		}
	}
	
	/* Return TRUE on success, FALSE on failure */
	return TRUE;
}




