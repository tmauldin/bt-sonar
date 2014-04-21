#include "Maxbotix.h"

Maxbotix rangeSensorPW(10, Maxbotix::PW, Maxbotix::LV, Maxbotix::MEDIAN);

//left vibe
int leftVibe = 6;

//right vibe
int rightVibe = 16;

int writeVal = 0;

void setup()  { 
  // for debugging
  Serial.begin(9600);
  
  pinMode(leftVibe, OUTPUT);
  pinMode(rightVibe, OUTPUT);
  digitalWrite(leftVibe, LOW); 
  digitalWrite(rightVibe, LOW);
}

void loop()  { 
  
  // get distance
  float readingCm = rangeSensorPW.getRange();
  
  writeVal = get_write_val(readingCm);
  analogWrite(leftVibe, writeVal);
  analogWrite(rightVibe, writeVal);
  
  Serial.print(readingCm);
  Serial.print("cm\n");  
  
  delay(50);                            
}

int get_write_val(float range) {
  if (range > 60) 
    return 0;
  if (range > 50)
    return 100;
  if (range > 45)
    return 110;
  if (range > 40)
    return 130;
  if (range > 35)
    return 150;
  if (range > 30)
    return 200;
  return 255;
}









