#include <IRremote.h>
#include "pins_arduino.h"
int RECV_PIN = 11;//Pin should be PWM

IRrecv irrecv(RECV_PIN);

decode_results results;


const int pinENB = 5;
const int pinIN3 = 7;
const int pinIN4 = 6;

const int pinENA = 8;
const int pinIN1 = 9;
const int pinIN2 = 10;
int speed = 255;      //velocidad de giro 80% (200/255)
 
  
  void setup()
{
    irrecv.enableIRIn(); // Start the receiver
    
   pinMode(pinIN3, OUTPUT);
   pinMode(pinIN4, OUTPUT);
   pinMode(pinENB, OUTPUT);
                           
   pinMode(pinIN1, OUTPUT);
   pinMode(pinIN2, OUTPUT);
   pinMode(pinENA, OUTPUT);
}
void loop() {
  if (irrecv.decode(&results)) {
      switch(results.value)
      {        
        case 0x1BC0157B: 
        speed = 255;
        //Serial.println("Forward"); // Button 8
                           digitalWrite(pinIN3, HIGH);
                           digitalWrite(pinIN4, LOW);
                           analogWrite(pinENB, speed);
   
                          digitalWrite(pinIN1, HIGH);
                             digitalWrite(pinIN2, LOW);
                                analogWrite(pinENA, speed);
                                   //delay(500);
                         break;       
        case 0x132C6FDF7:  //Serial.println("Left"); // Button 7
                         digitalWrite(pinIN3, HIGH);
                           digitalWrite(pinIN4, LOW);
                           analogWrite(pinENB, speed);
                         break; 
        case 0x1EE886D7F:  //Serial.println("Stop"); // Button 8
        speed = 0;
                       digitalWrite(pinIN3, HIGH);
                           digitalWrite(pinIN4, LOW);
                           analogWrite(pinENB, speed);
   
                          digitalWrite(pinIN1, HIGH);
                             digitalWrite(pinIN2, LOW);
                                analogWrite(pinENA, speed);
                                   //delay(500);
                         break; 
        case 0x13EC3FC1B:  //Serial.println("r"); // Button 9
                         digitalWrite(pinIN1, HIGH);
                             digitalWrite(pinIN2, LOW);
                                analogWrite(pinENA, speed);
                         break;         
    
      }  
    irrecv.resume(); // Receive the next value
  }
}
