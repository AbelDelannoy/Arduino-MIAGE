#include <ArduinoRobot.h>
#include <Wire.h>
#include <SPI.h>

// DECLARATION DES VALEURS POUR LES CAPTEURS

int value0;
int value1;
int value2;
int value3;
int value4;


void setup()
{
  Robot.begin();
  Robot.beginTFT();
  Serial.begin(9600);
  
// DEFINITIONS DES FONCTIONS POUR QUE LE ROBOT CHANGE DE POSITION
 
// STOP
  void arrete_toi() 
  { 
    Robot.motorStop(); 
    delay(1000); 
  } 
  
// AVANCE
  void avance() 
  { 
    Robot.motorsWrite(255,255); 
    delay(2000); 
  }  

// TOURNE À DROITE
  void tournedroite() 
  { 
    Robot.motorsWrite(255,-255); 
    delay(2000); 
  }  
  
// TOURNE À GAUCHE
  void tournegauche() 
  { 
    Robot.motorsWrite(-255,255); 
    delay(2000); 
  } 
 
 // AFFICHAGE QU'UNE SEULE FOIS DE LA VALEUR DES CAPTEURS SANS ETRE OBLIGES DE LES RAFRAICHIR
 
   Robot.stroke(25, 40, 0);
   Robot.textSize(2);
   Robot.text("IR0: ", 0, 0); // Robot.text(le texte, valeur x, valeur y);
   
   Robot.stroke(25, 40, 0);
   Robot.textSize(2);
   Robot.text("IR1: ", 0, 30);
   
   Robot.stroke(25, 40, 0);
   Robot.textSize(2);
   Robot.text("IR2: ", 0, 60);
   
   Robot.stroke(25, 40, 0);
   Robot.textSize(2);
   Robot.text("IR3: ", 0, 90);
   
   Robot.stroke(25, 40, 0);
   Robot.textSize(2);
   Robot.text("IR4: ", 0, 120);
   
}

void loop(){

   Robot.updateIR(); // MISE A JOUR DE IR ARRAY
   
   //**************************************
   //*     Capteur 0                      *
   //**************************************
   
   value0=Robot.IRarray[0];
   Robot.stroke(0, 255, 0);
   Robot.textSize(2);
   Robot.text(value0, 80,0 );  
 
  //**************************************
  //*              Capteur 1             *
  //**************************************
  
   value1=Robot.IRarray[1];
   Robot.stroke(0, 255, 0);
   Robot.textSize(2);
   Robot.text(value1, 80,30 );  
   
  //**************************************
  //*              Capteur 2             *
  //**************************************
  
   value2=Robot.IRarray[2];
   Robot.stroke(0, 255, 0);
   Robot.textSize(2);
   Robot.text(value2, 80,60 ); 
  
  //**************************************
  //*              Capteur 3             *
  //**************************************
   
   value3=Robot.IRarray[3];
   Robot.stroke(0, 255, 0);
   Robot.textSize(2);
   Robot.text(value3, 80,90 );  

  
  //**************************************
  //*              Capteur 4             *
  //**************************************
   
   value4=Robot.IRarray[4];
   Robot.stroke(0, 255, 0);
   Robot.textSize(2);
   Robot.text(value4, 80,120 );  
   
// POUR METTRE À JOUR LA VALEUR DES CAPTEURS INFRA-ROUGE
 
  delay(1000);
   
  Robot.stroke(255, 255, 255);
  Robot.textSize(2);
  Robot.text(value0, 80,0 );

  Robot.stroke(255, 255, 255);
  Robot.textSize(2);
  Robot.text(value1, 80,30 );
  
  Robot.stroke(255, 255, 255);
  Robot.textSize(2);
  Robot.text(value2, 80,60 ); 
  
  Robot.stroke(255, 255, 255);
  Robot.textSize(2);
  Robot.text(value3, 80,90 );
 
  Robot.stroke(255, 255, 255);
  Robot.textSize(2);
  Robot.text(value4, 80,120 );
  
  
 // LES FONCTIONS : 
  
 // FONCTION AVANCE TOUT DROIT
 
   void avance_tout_droit(int valeur0,int valeur1, int valeur2, int valeur3,int valeur4)  
  { 
   if ((valeur0>500 && valeur4>500) && ((valeur1 < 400 && valeur2 <400 && valeur3 < 400) || 
      (valeur1 < 400 && valeur2 <400) || (valeur2 <400 && valeur3 <400))) 
    { 
      avance(); 
    } 
   
   else
    { 
      arrete_toi(); 
    } 
  } 
  
  // FONCTION TOURNE À GAUCHE
   
  void tourne_a_gauche(int valeur0,int valeur1, int valeur2, int valeur3,int valeur4)
 {  
  if ((valeur4>500) && ((valeur1 && valeur2 & valeur3<500)||(valeur0 && valeur1 & valeur2<500) || (valeur0 && valeur1 && valeur3<500)))
    {    
      tournegauche();     
    } 
   
  else
    {  
      arrete_toi();     
    }  
  }  


// FONCTION TOURNE À DROITE

  void tourne_a_droite(int valeur0,int valeur1, int valeur2, int valeur3,int valeur4)
 {  
    if ((valeur0>500) && ( (valeur1 && valeur2 & valeur3<500)||(valeur4 && valeur1 & valeur2<500) || (valeur4 && valeur1 && valeur3<500)))
    {    
      tournedroite();   
    }  
    else
    {  
      arrete_toi(); 
    }  
  }  
  
}
