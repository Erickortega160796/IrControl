#include<IRremote.h >
#include <Servo.h>
int ReceptorIR = 2;
int Led1=8;
IRrecv irrecv (ReceptorIR);
decode_results Codigos;
Servo myServo;
int encender = 0;
int apagar = 0;
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(Led1,OUTPUT);
   myServo.attach(3); //servo pin
  myServo.write(0);
}
void loop() {
  if (irrecv.decode(&Codigos))
  {
    switch (Codigos.value)
    {
      case 0xFF38C7: /// 5
      encender ++;
      break;
      case  0xFF10EF: //// 4
     encender ++;
      break;
      
      case 0xFF30CF: /// 1
      apagar ++;
      break;
      case  0xFF18E7: //// 2
     apagar ++;
      break;
    }
    irrecv.resume();
    if (apagar == 2  ){
      digitalWrite(Led1,LOW);
      Serial.println("LED apagado......");
      myServo.write(0);
      delay(1000);
      apagar = 0;
    }
     if (encender==2)
    {
      digitalWrite(Led1,HIGH);
      Serial.println("LED encendido.....");
      myServo.write(180);
      delay(1000);
      encender = 0;
    }
 
   
  }
   
    
  
}

      
