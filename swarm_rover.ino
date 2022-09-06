#include "SoftwareSerial.h"
SoftwareSerial mySerial(0, 1); // RX | TX

char t;
int buzzer = 2;
int trigPin = A0;   
int echoPin = A1;    

long duration, distance;

// Motor A

int enA = 8;
int in1 = 7;
int in2 = 6;

// Motor B

int enB = 3;
int in3 = 5;
int in4 = 4;

void setup() 
{
  Serial.begin(9600);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT); 
  pinMode(in3, OUTPUT); 
  pinMode(in4, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}


void loop() 
{
Serial.println("Driving Forward for 3 Seconds");
analogWrite(enA, 200);
analogWrite(enB, 200);
  
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,HIGH); 
delay(3000);

Serial.println("Driving Backwards for 3 Seconds");
analogWrite(enA, 200);
analogWrite(enB, 200);

digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);
digitalWrite(in3,HIGH);
digitalWrite(in4,LOW);
delay(3000);

Serial.println("Stopping");
analogWrite(enA, 0);
analogWrite(enB, 0);

digitalWrite(in1,LOW);
digitalWrite(in2,LOW);
digitalWrite(in3,LOW);
digitalWrite(in4,LOW);
delay(1000);
exit(0);
}
