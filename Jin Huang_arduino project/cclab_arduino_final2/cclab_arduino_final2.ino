#include "pitches.h"
#include <Servo.h>
Servo myservo;

int trigPin = 6;
int echoPin = 7;
   
int redLED1 = 2;         
int button1 = 13; 
int greenLED = 3;         
int button2 = 12;
int redLED2 = 4;         
int button3 = 11;     

boolean led1GON = false;
boolean led2GON = false;
boolean led3GON = false;
boolean flagTurn = false;

  int countSound[] = {NOTE_C4,NOTE_C5,NOTE_C6};
  int countPitch[] = {8, 8, 8};

  int melody[] = {
  NOTE_C4, NOTE_F4, NOTE_E4, NOTE_E5, NOTE_E5
};

int noteDurations[] = {
  8, 8, 4, 8, 4 
};

void setup() {
  myservo.attach(9);
  myservo.write(0);

   Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
   
  pinMode(button1, INPUT);
  pinMode(redLED1, OUTPUT);
  pinMode(button2, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(button3, INPUT);
  pinMode(redLED2, OUTPUT);

  digitalWrite(redLED1,HIGH);
  digitalWrite(greenLED,HIGH);
  digitalWrite(redLED2,HIGH);
}

void loop() {
  int buttonState1 = digitalRead(button1);
  int buttonState2 = digitalRead(button2);
  int buttonState3 = digitalRead(button3);

  if(buttonState1 == HIGH){
    digitalWrite(redLED1,LOW);
    tone(8,countSound[0], 1000/countPitch[0]);
    led1GON = true;
    }
      
   if(buttonState2 == HIGH && led1GON == true){
    digitalWrite(greenLED,LOW);
    tone(8,countSound[1], 1000/countPitch[1]);
    led2GON = true;
    }

   if(buttonState3 == HIGH && led1GON == true && led2GON == true){
    digitalWrite(redLED2,LOW);
    tone(8,countSound[2], 1000/countPitch[2]);
    led3GON = true;
    }
    
 if(led1GON==true && led2GON==true && led3GON==true){
  myservo.write(90);
  flagTurn = true;
   }

 long duration, cm;
    // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);

  Serial.print(cm);
  Serial.println("cm");
  delay(100);
  
 if(flagTurn == true){
      if ( 15 < cm) {
    Serial.println("WIN!!!");
    for (int thisNote = 0; thisNote < 5; thisNote++) {

      tone(8, melody[thisNote], 1000 /noteDurations[thisNote]);

      int pauseBetweenNotes = 1000 /noteDurations[thisNote] * 1.50;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(8);
     }
    }
      
   }
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
