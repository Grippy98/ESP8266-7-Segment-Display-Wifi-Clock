//Andrei Aldea 2018, based on code by Mel Lester Jr. , adapted for Clock Functionality and use on the ESP8266
//Please note this Code uses the RX pin as one of the outputs, so you cannot use the Serial COM on the ESP8266 in the code

#include <ESP8266WiFi.h>
#include <time.h>

// ESP8266 Compatible Pin Assignment
int aPin = 14;  //         A
int bPin = 16;  //    ________
int cPin = 9;  //    |        |
int dPin = 13;  // F |        |  B
int ePin = 15;  //   |   G    |
int fPin = 0;  //    |________|
int gPin = 10;  //   |        |
int GND1 = 2; //     |        |
int GND2 = 4; //   E |        |   C
int GND3 = 5; //     |________|
int GND4 = 3; //       
int dPnt = 12;//         D       O dPnt

int dig1 = 0;
int dig2 = 0;
int dig3 = 0;
int dig4 = 0;

int DTime = 1; //Delaytime for itterations, 16ms default, 4 ms now

const char* ssid = ""; //Change the next 3 lines!
const char* password = "";
int timezone = -5; //EST is UTC-5
int dst = 0;


int i = 0;
long timer = millis() + 500;

void setup()
{
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT); 
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(GND1, OUTPUT);
  pinMode(GND2, OUTPUT);
  pinMode(GND3, OUTPUT);
  pinMode(GND4, OUTPUT);
  pinMode(dPnt, OUTPUT);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  configTime(timezone * 3600, dst * 0, "pool.ntp.org", "time.nist.gov"); //Time server
  while (!time(nullptr)) { //Wait for connection to get actual time
      delay(1000);
      digitalWrite( GND4, LOW);    //digit 4
      pickNumber(0);
  } 
}

void loop()
{
  
  // turn off all display digits
  digitalWrite( GND1, HIGH);
  digitalWrite( GND2, HIGH);
  digitalWrite( GND3, HIGH);
  digitalWrite( GND4, HIGH);

  time_t now;
  struct tm * timeinfo;
  time(&now);
  timeinfo = localtime(&now);  

  dig1 = timeinfo->tm_hour/10; //Abusing integer math a bit to get the digits
  dig2 = timeinfo->tm_hour%10;
  dig3 = timeinfo->tm_min/10;
  dig4 = timeinfo->tm_min%10;

  //The following code scans really fast throug the digits so it creates persistance of vision... aditional delays really screw with this.

  digitalWrite( GND4, LOW);    //digit 4
  pickNumber(dig4);
  delay(DTime);
  digitalWrite( GND4, HIGH);
  
  digitalWrite( GND3, LOW);    //digit 3
  pickNumber(dig3);
  delay(DTime);
  digitalWrite( GND3, HIGH);
 
  digitalWrite( GND2, LOW);   //digit 2
  pickNumber(dig2); 
  digitalWrite(dPnt, HIGH); //Middle decimal point always ON
  delay(DTime);
  digitalWrite( GND2, HIGH);
  digitalWrite(dPnt, LOW);
 
  digitalWrite( GND1, LOW);   //digit 1
  pickNumber(dig1);
  delay(DTime);
  digitalWrite( GND1, HIGH);
}
 
void pickNumber(int x){
   switch(x){
     case 1: one(); break;
     case 2: two(); break;
     case 3: three(); break;
     case 4: four(); break;
     case 5: five(); break;
     case 6: six(); break;
     case 7: seven(); break;
     case 8: eight(); break;
     case 9: nine(); break;
     case 10: a(); break;
     default: zero(); break;
   }
}

void clearLEDs()
{  
  digitalWrite(  aPin, LOW); // A
  digitalWrite(  bPin, LOW); // B
  digitalWrite(  cPin, LOW); // C
  digitalWrite(  dPin, LOW); // D
  digitalWrite(  ePin, LOW); // E
  digitalWrite(  fPin, LOW); // F
  digitalWrite(  gPin, LOW); // G
  digitalWrite(  dPnt, LOW); // DecimalPoint
}

void one()
{
  digitalWrite( aPin, LOW);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, LOW);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, LOW);
  digitalWrite( gPin, LOW);
}

void two()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, LOW);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, HIGH);
  digitalWrite( fPin, LOW);
  digitalWrite( gPin, HIGH);
}

void three()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, LOW);
  digitalWrite( gPin, HIGH);
}

void four()
{
  digitalWrite( aPin, LOW);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, LOW);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}

void five()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, LOW);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}

void six()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, LOW);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, HIGH);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}

void seven()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, LOW);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, LOW);
  digitalWrite( gPin, LOW);
}

void eight()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, HIGH);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}

void nine()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, LOW);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}

void zero()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, HIGH);
  digitalWrite( ePin, HIGH);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, LOW);
}

//The following isn't acutally used but you get an idea as to how you could implement a limited character set on these displays.

void a()
{
  digitalWrite( aPin, HIGH);
  digitalWrite( bPin, HIGH);
  digitalWrite( cPin, HIGH);
  digitalWrite( dPin, LOW);
  digitalWrite( ePin, HIGH);
  digitalWrite( fPin, HIGH);
  digitalWrite( gPin, HIGH);
}
