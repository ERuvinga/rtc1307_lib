#include <rtc1307.h> //inclusion de nos constatntes et prototypes

void download_time(dateTime_t *now){  //now est (une structure) variable de type dateTime_t stoquant l'heure et la date actuelle
  Wire.beginTransmission(ADRESS_RTC);
  Wire.write(0);         //on remet a zero le curseur
  Wire.endTransmission();
  Wire.requestFrom(ADRESS_RTC, 7);
  byte secondes =Wire.read();
  
  now->sec   = decimal_hexa(secondes);
  now->mins  = decimal_hexa(Wire.read());
  now->hours = decimal_hexa(Wire.read() & 63);
  now->dow   = decimal_hexa(Wire.read());
  now->dom   = decimal_hexa(Wire.read());
  now->month = decimal_hexa(Wire.read());
  now->year  = decimal_hexa(Wire.read());
  
  Clock(secondes & 128);// verification de l'horloge [CH]
}


void update_time(byte secondes, byte minutes, byte heures, byte dows, byte doms, byte moi, byte an){ //mise a jours de l'heure et de la date dans le registre du module

  Wire.beginTransmission(ADRESS_RTC);
  Wire.write(0);                      // remise a zero du curseur
  Wire.write( hexa_decimal(secondes) & 127); // CH=0
  Wire.write( hexa_decimal(minutes));
  Wire.write( hexa_decimal(heures) & 63);    //mode 24
  Wire.write( hexa_decimal(dows));
  Wire.write( hexa_decimal(doms));
  Wire.write( hexa_decimal(moi));
  Wire.write( hexa_decimal(an));
  Wire.endTransmission();
  
}



void Clock(bool data){  // fonction verifiant l'etat du compteur de l'horloge
 
  if(data){
    update_time(0, 30, 12, 1, 10, 10, 22);
    //(sec, mins, heur, dow, dom, moi, an) mise a jours de l'heure et de la date
    //Serial.println("clock en arret");
    }
/*
  else{
    Serial.println("clock active");
  }
  */
}

