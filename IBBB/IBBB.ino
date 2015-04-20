#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

int motorPin = 13; 

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(motorPin , OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    if(results.value == 0xB24D48B7){
      Serial.println("true - run gogogogo"); 
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    digitalWrite(motorPin , HIGH);    
  }
  else if(results.value == 0xB24D00FF){
      digitalWrite(motorPin , LOW);
      Serial.println("stop- is - stop - byuser");
      irrecv.resume();
    }
  else{
    Serial.println("false-not-avaliable signal");
    Serial.println(results.value, HEX);  
    irrecv.resume(); // Receive the next value
    digitalWrite(motorPin , LOW);
  }
  Serial.println(results.value, HEX);
  delay(1000);
 }
}
