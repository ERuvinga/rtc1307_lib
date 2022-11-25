#ifndef rtc
#define rtc

//structure stockant toute la date
struct dateTime_t{

   byte sec;
   byte mins;
   byte hours;
   byte dow;   //dayOfWeek(1-7)
   byte dom;  //dayOfMonth(1-30/31)
   byte month;
   byte year;
   
}DateTime;


void Clock(bool);//controle du compteur du module 

// fonction pour le decodage du jour de la semaine et celui du moi 
String decode_dow(byte);
String decode_month(byte);

//fonction de mise ajour du temp
void update_time(byte, byte, byte, byte, byte, byte, byte);
void download_time(dateTime_t *);

//convertisseur des donnees
byte decimal_hexa(byte);
byte hexa_decimal(byte);

// fonction pour le decodage du jour de la semaine et celui du moi 
String decode_dow(byte);
String decode_month(byte);

#endif //rtc
