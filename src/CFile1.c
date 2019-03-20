/*
 * CFile1.c
 *
 * Created: 07/03/2019 08:27:34
 *  Author: jdbonfils
 */ 
#include "libTPIUT.h"
#include "robot.h"

#define PORT_BP1 PortB
#define LIGNE_BP1 25
#define PORT_BP2 PortC
#define LIGNE_BP2 26
void tournerMoteur30deg (int Moteur, Peripherique Port , int Ligne ) ;

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
		while(true)
		{
			tournerMoteur30deg(BASE , PORT_BP1, LIGNE_BP1) ;
		}
		
}
	
	int indice = 1 ;
	
	void tournerMoteur30deg (int Moteur, Peripherique Port , int Ligne )
	{
		while(lireLigne(Port,Ligne)==0){}
		while(lireLigne(Port,Ligne)==1){}

				if(indice == 1)
				{
					for (int i = 1 ; i = 30 ; i++)
					{
					//tourne de 0 à 30
					positionnerMoteur(Moteur,i) ;
					}
					indice = 2 ;
				}
				else if(indice == 2)
				{
					
					for (int i = 30 ; i = 1 ; i--)
					{
						//tourne de 30 à 0
						positionnerMoteur(Moteur,i) ;
					}
					indice = 3 ;
					
				}
				else if (indice == 3)
				{
					for (int i = 1 ; i = -30 ; i--)
					{
						//tourne de 0 à -30
						positionnerMoteur(Moteur,i) ;
					}
					indice = 4 ;
					
				}
				else if (indice == 4)
				{
						for (int i = -30 ; i = 0 ; i++)
						{
							//tourne de -30 à 0
							positionnerMoteur(Moteur,i) ;
						}
						indice = 1 ;
				}
			
			
		

	}