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
void initialiserRobot() ;
int main (void)
{
	initCarte();
	configureConsole();
	initialiserRobot() ;
	allumerPeriph(ConvAN) ;
	
	initConvAN(10,RES10BITS) ;
	declenchementConvAN(PROG_CONTINU) ;
	
	
	//allumerPeriph(PORT_BP1);
	//programmerLigne(PORT_BP1,LIGNE_BP1, ENTREE);
	//allumerPeriph(PORT_BP2);
	//programmerLigne(PORT_BP2,LIGNE_BP2, ENTREE);
	//activerFiltrageLigne(PORT_BP1,LIGNE_BP1,20);
	//activerFiltrageLigne(PORT_BP2,LIGNE_BP2,20);
	allumerPeriph(Timer1) ;
	timerModeDelai(Timer1,HDIV2,1543000UL,REPETITIF,INC);
	lancerTimer(Timer1) ;
	float valTension = 0 ;
	float valDegres =0 ;
	float valTensionPince = 0 ;
	float valDegresPince = 0 ;
	float valTensionPoignet = 0 ; 
	float valDegresPoignet = 0 ;
	float valTensionBase = 0 ;
	float valDegresBase = 0 ;
	//tournerMoteur(BASE , PORT_BP1, LIGNE_BP1, 0) ;
	while(true)
	{
			
			if(testerEtatTimer(Timer1,LIMITE)){
			choisirEntreeConvAN(6) ;
			while(!testerEtatConvAN(FIN_CONV6))
			{
			}
			//positionnerMoteur(PINCE,85) ;
			valTensionPince = lireTensionConvAN(6);
			//printf("Valeur de la tension pince%f\n ",valTensionPince) ;
			valDegresPince = (valTensionPince*51.51)-85 ;
			positionnerMoteur(PINCE,valDegresPince) ;}
			
			
			
			choisirEntreeConvAN(5) ;
			while(!testerEtatConvAN(FIN_CONV5))
					{
					}
							//positionnerMoteur(PINCE,85) ;
			valTension = lireTensionConvAN(5);
			printf("Valeur de la tension dans le du coude %f \n ",valTension) ;
			if (valTension<1.55|| valTension>1.80){
				
				if(testerEtatTimer(Timer1,LIMITE)){
			valDegres = ((valTension-1.85)*0.825)+valDegres ;
			positionnerMoteur(COUDE,valDegres) ;}}
			
			
			
		
				choisirEntreeConvAN(2) ;
				while(!testerEtatConvAN(FIN_CONV2))
				{
				}
				valTensionPoignet = lireTensionConvAN(2);
				//printf("Valeur de la tension dans le if %f \n ",valTensionPoignet) ;
				if (valTensionPoignet<1.55 || valTensionPoignet>1.80){
					if(testerEtatTimer(Timer1,LIMITE)){
					valDegresPoignet = ((valTensionPoignet-1.85)*0.825)+valDegresPoignet ;
				positionnerMoteur(POIGNET,valDegresPoignet) ;}}
				
				
				
				choisirEntreeConvAN(4) ;
				while(!testerEtatConvAN(FIN_CONV4))
				{
				}
				valTensionBase = lireTensionConvAN(4);
				//printf("Valeur de la tension dans le if %f \n ",valTensionBase) ;
				if (valTensionBase<1.55 || valTensionBase>1.80){
					if(testerEtatTimer(Timer1,LIMITE)){
						valDegresBase = ((valTensionBase-1.85)*0.825)+valDegresBase ;
					positionnerMoteur(BASE,valDegresBase) ;}}
			

	


	
		
	}
	
}
void initialiserRobot()
{
	initRobot() ;
}


/*
int indice = 1 ;

void tournerMoteur (int Moteur, Peripherique Port , int Ligne , float angle)
{
	while(lireLigne(Port,Ligne)==0){}
	while(lireLigne(Port,Ligne)==1){}
		positionnerMoteur(Moteur,angle) ;


}*/