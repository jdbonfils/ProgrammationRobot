/*
 * mainTP2.c
 *
 * Created: 21/02/2019 10:37:38
 *  Author: jdbonfils
 */ 
#include "libTPIUT.h"
#include "robot.h"

#define PORT_BP1 PortB
#define LIGNE_BP1 25
#define PORT_BP2 PortC
#define LIGNE_BP2 26
void tournerMoteur (int Moteur, Peripherique Port , int Ligne ,float angle) ;

int main (void)
{
	initCarte();
	configureConsole();
	initRobot() ;
	allumerPeriph(PORT_BP1);
	programmerLigne(PORT_BP1,LIGNE_BP1, ENTREE);
	allumerPeriph(PORT_BP2);
	programmerLigne(PORT_BP2,LIGNE_BP2, ENTREE);
	activerFiltrageLigne(PORT_BP1,LIGNE_BP1,20);
	activerFiltrageLigne(PORT_BP2,LIGNE_BP2,20);
	allumerPeriph(Timer1) ;
	timerModeDelai(Timer1,HDIV2,1680000UL,REPETITIF,INC);
	lancerTimer(Timer1) ;
	while(true)
	{
		
			tournerMoteur(BASE , PORT_BP1, LIGNE_BP1, 30) ;




	
		
	}
	
}

int indice = 1 ;

void tournerMoteur (int Moteur, Peripherique Port , int Ligne , float angle)
{
	while(lireLigne(Port,Ligne)==0){}
	while(lireLigne(Port,Ligne)==1){}

	if(indice == 1)
	{
		for(int i = 1 ; i <= angle ; i++)
		{
			//tourner de 0 à 30
			
			positionnerMoteur(Moteur,i) ;
			
			while (!testerEtatTimer(Timer1,LIMITE))
			{
			}
			
		}
		indice = 2 ;
	}
	else if(indice == 2)
	{
		
		for(int i = angle ; i >= 1 ; i--)
		{
			//tourne de 30 à 0
			positionnerMoteur(Moteur,i) ;
			
			while (!testerEtatTimer(Timer1,LIMITE))
			{
			}
			
		}
		indice = 3 ;
		
	}
	else if (indice == 3)
	{
		for(int i = 1 ; i >= -angle ; i--)
		{
			//tourne de 0 à -30
			positionnerMoteur(Moteur,i) ;
			
			while (!testerEtatTimer(Timer1,LIMITE))
			{
			}
		}
		indice = 4 ;
		
	}
	else if (indice == 4)
	{
		for(int i = -angle ; i <= 1 ; i++)
		{
			//tourne de -30 à 0
			positionnerMoteur(Moteur,i) ;
			
			while (!testerEtatTimer(Timer1,LIMITE))
			{
			}
		}
		indice = 1 ;
	}
	
	
	

}