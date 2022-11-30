#include <TinyGPS++.h>

//Testing definitions
String latitude;
String longitude;

TinyGPSPlus gps;
void setup(){
  Serial.begin(115200);
  //Serial2.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, 16,17); //RX,TX
  //Serial.println("Beginning...");
}

void read_gps(){
  delay(10000);
  while (Serial2.available() > 0){
    //delay(10000);
    //Serial.println("Primera lectura");
    gps.encode(Serial2.read());
    //delay(10000);
    if (gps.location.isUpdated()){
      //Serial.println("segunda lectura");
      latitude = String(gps.location.lat(),6);
      longitude = String(gps.location.lng(),6);
      //String.substring(,);
      Serial.print("Latitude= "); 
      Serial.println(latitude);
      Serial.print("Longitude= "); 
      Serial.println(longitude);
      Serial.print("Speed in Km/h: ");
      Serial.println(gps.speed.kmph());
    }
  }
}


void loop(){
  read_gps();
  //Serial.println("Hola");
  delay(10000);
}
