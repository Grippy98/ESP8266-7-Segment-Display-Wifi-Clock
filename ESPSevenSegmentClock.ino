// Arduino Uno compatible pin assignments
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
int dPnt = 12;  //         D       O dPnt
// decimal point is not used in this example code, but is included just because
int dig1 = 0;
int dig2 = 0;
int dig3 = 0;
int dig4 = 0;

int DTime = 1; //Delaytime for itterations, 16ms default, 4 ms now

#include <ESP8266WiFi.h>
#include <time.h>

const char* ssid = "Grippy-Hawk";
const char* password = "grippen98";
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
  configTime(timezone * 3600, dst * 0, "pool.ntp.org", "time.nist.gov");
  /*while (!time(nullptr)) {
      delay(1000);
      digitalWrite( GND4, LOW);    //digit 4
      pickNumber(0);
  }*/
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
  //Serial.println(timeinfo->tm_hour);
  //delay(1000);

  dig1 = timeinfo->tm_hour/10;
  dig2 = timeinfo->tm_hour%10;
  dig3 = timeinfo->tm_min/10;
  dig4 = timeinfo->tm_min%10;

/*  //counter
while (i <10000)
{
  if (millis() > timer) { // increment counter
    i++;
    if (i > 9999) {
      i = 0;
    }
    dig1 = i / 1000;
    dig2 = (i - (dig1 * 1000)) / 100;
    dig3 = (i - (dig1 * 1000 + dig2 * 100)) / 10;
    dig4 = i % 10;
    timer = millis() + 500;
  }
*/
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
  digitalWrite(dPnt, HIGH); //Middle decimal point
  delay(DTime);
  digitalWrite( GND2, HIGH);
  digitalWrite(dPnt, LOW);
 
  digitalWrite( GND1, LOW);   //digit 1
  pickNumber(dig1);
  delay(DTime);
  digitalWrite( GND1, HIGH);
} // end loop
 
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
  digitalWrite(  2, LOW); // A
  digitalWrite(  3, LOW); // B
  digitalWrite(  4, LOW); // C
  digitalWrite(  5, LOW); // D
  digitalWrite(  6, LOW); // E
  digitalWrite(  7, LOW); // F
  digitalWrite(  8, LOW); // G
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
