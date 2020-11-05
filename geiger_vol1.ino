#include <Servo.h>

Servo camservo1;
Servo camservo2;
Servo camservo3;

const int ch1 = 0; 
const int ch2 = 0;
const int aux1 = 0;
const int aux2 = 0;
const int aux3 = 0;
const int aux4 = 0;
const int aux5 = 0;
const int aux6 = 0;

const int md1 = 0; // motor1 PWM
const int md2 = 0; // motor2 PWM
const int md3 = 0; // motor3 PWM
const int md4 = 0; // motor4 PWM

int pulseNum1 = 0;
int pulseNum2 = 0;
int pulseNum3 = 0;
int pulseNum4 = 0;
int pulseNum5 = 0;
int pulseNum6 = 0;
int pulseNum7 = 0;
int pulseNum8 = 0;

const int campin1 = 9;
const int campin2 = 10;
const int campin3 = 11;

const int switcher = A0;
const int a2 = A2;

int val = 0;

int ang = 0;

int cam, e1, e2, e3;

int max = 90;
int min = 0;

void setup() {
  pinMode(switcher, INPUT);
  pinMode(a2, INPUT);
  pinMode(campin1, OUTPUT);
  pinMode(campin2, OUTPUT);
  pinMode(campin3, OUTPUT);
  camservo1.attach(3);
  camservo2.attach(5);
  camservo3.attach(6);
  Serial.begin(115200);
}

void loop() {
  pulseNum1 = pulseIn(ch1, HIGH);
  pulseNum2 = pulseIn(ch2, HIGH);
  pulseNum3 = pulseIn(aux1, HIGH);
  pulseNum4 = pulseIn(aux2, HIGH);
  pulseNum5 = pulseIn(aux3, HIGH);
  pulseNum6 = pulseIn(aux4, HIGH);
  pulseNum7 = pulseIn(aux5, HIGH);
  pulseNum8 = pulseIn(aux6, HIGH);
  val = constrain(val, 1000, 2000);
  ang = constrain(ang, 1000, 2000);

    Serial.print(cam);
    Serial.print("  ");
    Serial.print(val);
    Serial.print("  ");

    Serial.print(e1);
    Serial.print("  ");
    Serial.print(e2);
    Serial.print("  ");
    Serial.print(e3);
    Serial.print("  ");
    Serial.println(ang);
}
void MR_switching() {
  
}
void md_ctrl() {
  
}
void cam_ctrl() {
  if (val != 0) {
    if (val < 1200) {
      cam = 1;
    } else if (val < 1600) {
      cam = 2;
    } else if (val < 2100) {
      cam = 3;
    }




    switch (cam) {
      case 1:
        digitalWrite(campin1, HIGH);
        digitalWrite(campin2, LOW);
        digitalWrite(campin3, LOW);

        if (ang > 1700 && e1 < 90) {
          e1++;
        }

        else if (ang < 1300 && e1 > 0) {
          e1--;
        }

        camservo3.write(e1);

        break;

      case 2:
        digitalWrite(campin1, LOW);
        digitalWrite(campin2, HIGH);
        digitalWrite(campin3, LOW);

        if (ang > 1700 && e2 < 90) {
          e2++;
        }

        else if (ang < 1300 && e2 > 0) {
          e2--;
        }

        camservo1.write(e2);


        break;

      case 3:
        digitalWrite(campin1, LOW);
        digitalWrite(campin2, LOW);
        digitalWrite(campin3, HIGH);

        if (ang > 1700 && e3 < 90) {
          e3++;
        }

        else if (ang < 1300 && e3 > 0) {
          e3--;
        }

        camservo2.write(e3);


        break;
    }
}
}
