#include "libTPIUT.h"
#include "robot.h"

#define PORT_BP1 PortB
#define LIGNE_BP1 25
#define PORT_BP2 PortC
#define LIGNE_BP2 26
void tournerMoteur (int Moteur, Peripherique Port , int Ligne , float angle) ;
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
	bool btn2 = false ;
	while(true) {

				while(true)
					{
						if(lireLigne(PORT_BP2,LIGNE_BP2)==1)
							{
								if(btn2 == false)
								{
									btn2 = true ;
								 }
								else
								{
									btn2 = false ;
								}
							}
						if(lireLigne(PORT_BP1,LIGNE_BP1)==1){ break ;}
				
					}
				if(btn2==true)
					{
						tournerMoteur(COUDE , PORT_BP1, LIGNE_BP1 , 10) ;
					}
				else
					{
						tournerMoteur(BASE , PORT_BP1, LIGNE_BP1 , 10) ;		
					}

			while(true)
			{
				if(lireLigne(PORT_BP2,LIGNE_BP2)==1)
				{
					if(btn2 == false)
					{
						btn2 = true ;
					}
					else
					{
						btn2 = false ;
					}
				}
				if(lireLigne(PORT_BP1,LIGNE_BP1)==1){ break ;}
	
			}
			if(btn2==true)
				{
					tournerMoteur(COUDE , PORT_BP1, LIGNE_BP1 , 0) ;
				}
			else
				{
					tournerMoteur(BASE , PORT_BP1, LIGNE_BP1 , 0) ;
				}

			while(true)
			{
				if(lireLigne(PORT_BP2,LIGNE_BP2)==1)
				{
					if(btn2 == false)
						{
							btn2 = true ;
						}
					else
						{
							btn2 = false ;
						}
				}
				if(lireLigne(PORT_BP1,LIGNE_BP1)==1){ break ;}
	
			}
			if(btn2==true)
			{
				tournerMoteur(COUDE , PORT_BP1, LIGNE_BP1 , -10) ;
			}
			else
			{
				tournerMoteur(BASE , PORT_BP1, LIGNE_BP1 , -10) ;
			}

			while(true)
			{
				if(lireLigne(PORT_BP2,LIGNE_BP2)==1)
				{
					if(btn2 == false)
					{
						btn2 = true ;
					}
					else
					{
						btn2 = false ;
					}
				}
				if(lireLigne(PORT_BP1,LIGNE_BP1)==1){ break ;}
		
			}
			if(btn2==true)
			{
				tournerMoteur(COUDE , PORT_BP1, LIGNE_BP1 , 0) ;
			}
			else
			{
				tournerMoteur(BASE , PORT_BP1, LIGNE_BP1 , 0) ;
			}


	}
}
void tournerMoteur (int Moteur, Peripherique Port , int Ligne , float angle)
{
		while(lireLigne(Port,Ligne)==0){}
		while(lireLigne(Port,Ligne)==1){}
		positionnerMoteur(Moteur,angle) ;

}

