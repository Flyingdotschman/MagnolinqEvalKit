/*
  Multiple Serial test

  Receives from the main serial port, sends to the others.
  Receives from serial port 1, sends to the main serial (Serial 0).

  This example works only with boards with more than one serial like Arduino Mega, Due, Zero etc.

  The circuit:
  - any serial device attached to Serial port 1
  - Serial Monitor open on Serial port 0

  created 30 Dec 2008
  modified 20 May 2012
  by Tom Igoe & Jed Roach
  modified 27 Nov 2015
  by Arturo Guadalupi

  This example code is in the public domain.
*/

int pinRelay1 = 7;
int pinRelay2 = 6;




void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
  Serial1.begin(57600);
  pinMode(pinRelay1,OUTPUT);
  pinMode(pinRelay2,OUTPUT);

  digitalWrite(pinRelay1,LOW);
   digitalWrite(pinRelay2,LOW);
  
}

void loop() {
  // read from port 1, send to port 0:
   
  if (Serial1.available()) {

     String inby = Serial1.readString();
     
    relayOpen(inby);
 
   
  }
 
}
void relayOpen(String i){
 int pos= i.indexOf(':');
  int ende = i.length();

 String msg = i.substring(pos+2,ende-1);
 String xxx = "-" + msg + "-";
    Serial.println(xxx);
  Serial.println(msg);
  if(msg.equals("left")){
      digitalWrite(pinRelay1,HIGH);
     delay(500);
     digitalWrite(pinRelay1,LOW);
    }
   if(msg.equals("right")){
      digitalWrite(pinRelay2,HIGH);
      Serial.println("Yo");
     delay(500);
     digitalWrite(pinRelay2,LOW);
    }
    }
