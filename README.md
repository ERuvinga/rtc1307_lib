# rtc1307_lib
![pcb](https://www.electronics-lab.com/wp-content/uploads/2016/05/RTC-DS1307-MODULE-SMD-SCHEMATIC.jpg) image source [www.electronics-lab.com](https://www.electronics-lab.com/project/ds1307-rtc-module/rtc-ds1307-module-smd-schematic/)

cette Librairie permet le chargement des donnees sur la voies i2c du module Rtc1307 vers un microcontroleur Arduino ,

## Installation

l'integration de cette librairie est simple , apres une installation comme mentionner dans cette astuces [installation d'une bib...](https://www.robot-maker.com/ouvrages/tuto-arduino/bibliotheque-arduino/)

vous devez l'inclure dans votre programme grace a la ligne ci dessous:
``` C
#include <rtc1307.h>
```

## Keywords
   ### 1. structure
```C
  struct dateTime_t{

     byte sec;
     byte mins;
     byte hours;
     byte dow;   //dayOfWeek(1-7)
     byte dom;  //dayOfMonth(1-30/31)
     byte month;
     byte year;

  }DateTime;
  ``` 
  >Est une structure qui stocke la date(Jour, Moi , heures, minutes, secondes, ...)
  
  ### 2. functions
  
  ```C
  void update_time(byte, byte, byte, byte, byte, byte, byte);
  ```  
  >Cette fonction met a jour les datas du registre de notre module ``RTC``
  
  ```C
  void download_time(dateTime_t *);
  ```
  >Celle-ci met a jour les datas de notre structure `DateTime`, les donnees accessibles par notre carte arduino ;
  tout en verifiant si le compteur du module est a marche [CH = 0] sinon il le met a jour et relance le compteur 
  
  ### 3. Exemple 
  
  ```C
  ...
  void loop() {
  
    if(( millis() - duration) >= 500){  // apres chaque demi seconde on telecharge la date
           duration = millis();
           download_time(&DateTime); // mise a jour de la date 
           Serial.println(DateTime.sec); //affichage des secondes 
   }
}
```
>Merci pour vos ``Suggestions``
