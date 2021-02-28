#include<Servo.h> //import the header file

 //created objects
Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;

//analog pins of ldr
const int pickupLdr = A0;
const int placeLdr1 = A1;
const int placeLdr2 = A2;
const int placeLdr3 = A3;
const int placeLdr4 = A4;

int pos=0; 

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  motor1.attach(9); //attached our pins here
  motor2.attach(10);
  motor3.attach(11);
  motor4.attach(6);

//To take the input from analog pins
  pinMode(pickupLdr, INPUT);
  pinMode(placeLdr1, INPUT);
  pinMode(placeLdr2, INPUT);
  pinMode(placeLdr3, INPUT);
  pinMode(placeLdr4, INPUT);

  Serial.println("Going to default");

  defaultsync(); //func

  Serial.println("At default");
}

void defaultsync() { //for the motor rotation
  for(pos=0; pos<180; pos++) {
    motor1.write(pos);
    delay(30); //delay is defined in milliseconds
  }
  for(pos=180; pos>0; pos--) {
    motor1.write(pos);
    delay(30);
  }
  for(pos=0; pos<110; pos++) {
    motor1.write(pos);
    delay(30);
  }
  delay(250);

  for(pos=100; pos<140; pos++) {
    motor2.write(pos);
    delay(30);
  }
  for(pos=140; pos>100; pos--) {
    motor2.write(pos); //to give degrees of the motor
    delay(30);
  }
  for(pos=100; pos<120; pos++) {
    motor2.write(pos);
    delay(30);
  }
  delay(250);

  for(pos=110; pos<150; pos++) {
    motor3.write(pos);
    delay(30);
  }
  for(pos=150; pos>110; pos--) {
    motor3.write(pos);
    delay(30);
  }
  for(pos=110; pos<120; pos++) {
    motor3.write(pos);
    delay(30);
  }
  delay(250);

  for(pos=52; pos<72; pos++) {
    motor4.write(pos);
    delay(30);
  }
  for(pos=72; pos>52; pos--) {
    motor4.write(pos);
    delay(30);
  }
  for(pos=52; pos<72; pos++) {
    motor4.write(pos);
    delay(30);
  }
  delay(250);
}

void movemotor1(int pos1) { //To move first motor in the given parameters as degree
  int m1pos = motor1.read();
  
  if(m1pos<pos1) {
    for(pos=m1pos; pos<=pos1; pos++) {
      motor1.write(pos);
      delay(30);
    }
  }
  else if(m1pos>pos1) {
    for(pos=m1pos; pos>=pos1; pos--) {
      motor1.write(pos);
      delay(30);
    }
  }
  delay(250);
}

void movemotor2(int pos2) {//To move second motor in the given parameters as degree
  int m2pos = motor2.read();

  if(m2pos<pos2) {
    for(pos=m2pos; pos<=pos2; pos++) {
      motor2.write(pos);
      delay(30);
    }
  }
  else if(m2pos>pos2) {
    for(pos=m2pos; pos>=pos2; pos--) {
      motor2.write(pos);
      delay(30);
    }
  }
  delay(250);
}
void movemotor3(int pos3) {//To move third motor in the given parameters as degree
  int m3pos = motor3.read();

  if(m3pos<pos3) {
    for(pos=m3pos; pos<=pos3; pos++) {
      motor3.write(pos);
      delay(30);
    }
  }
  else if(m3pos>pos3) {
    for(pos=m3pos; pos>=pos3; pos--) {
      motor3.write(pos);
      delay(30);
    }
  }
  delay(250);
}
void movemotor4(int pos4) {//To move fourth motor in the given parameters as degree
  int m4pos = motor4.read();

  if(m4pos<pos4) {
    for(pos=m4pos; pos<=pos4; pos++) {
      motor4.write(pos);
      delay(30);
    }
  }
  else if(m4pos>pos4) {
    for(pos=m4pos; pos>=pos4; pos--) {
      motor4.write(pos);
      delay(30);
    }
  }
  delay(250);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pickupStatus = analogRead(pickupLdr); //defined our analog pins
  int placeStatusA = analogRead(placeLdr1);
  int placeStatusB = analogRead(placeLdr2);
  int placeStatusC = analogRead(placeLdr3);
  int placeStatusD = analogRead(placeLdr4);

  if(pickupStatus<=300) {
//    Serial.println("Object found.");

    if(placeStatusC<=500) {
      Serial.println("You can place at C.");
      movemotor1(180);
      movemotor3(110);
      movemotor4(52);
      movemotor2(140);
      movemotor3(130);
      movemotor4(72);
      movemotor2(120);
      movemotor3(130);
      movemotor1(65);
      movemotor3(130);
      movemotor2(160);
      movemotor4(52);

      movemotor2(140);
      movemotor3(130);
      movemotor1(82);
      movemotor4(72);
    }
    
    else if(placeStatusB<=500) {
      Serial.println("You can place at B.");
      movemotor1(180);
      movemotor3(110);
      movemotor2(170);
      movemotor4(52);
      movemotor3(130);
      movemotor4(72);
      movemotor2(140);
      movemotor3(130);
      movemotor1(100);
      movemotor3(130);
      movemotor2(160);
      movemotor4(52);

      movemotor2(140);
      movemotor3(130);
      movemotor1(82);
      movemotor4(72);
    }

    else if(placeStatusA<=500) {
      Serial.println("You can place at A.");
      movemotor1(180);
      movemotor3(110);
      movemotor2(170);
      movemotor4(52);
      movemotor3(130);
      movemotor4(72);
      movemotor2(140);
      movemotor3(130);
      movemotor1(130);
      movemotor3(165);
      movemotor2(160);
      movemotor4(52);

      movemotor2(140);
      movemotor3(130);
      movemotor1(82);
      movemotor4(72);
    }

    else {
      Serial.println("All places full.");
    }
  }

  else {
    Serial.println("Object not found.");
  }
}