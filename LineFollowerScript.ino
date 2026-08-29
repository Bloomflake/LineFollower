// Line_follower_V2
// Author(s): Y. Panigrahi
// Made with <3 in Arduino IDE

#define MTR_IN1 4
#define MTR_IN2 5
#define MTR_IN3 6
#define MTR_IN4 7

#define IR1 8
#define IR2 9
#define IR3 10
#define IR4 11
#define IR5 12

#define DRIVE_THRESH_ACCURACY 20

void mtr(int x, unsigned long dur_ms) { // Motor Driver Function
  if (x == 0) { // Brake
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    digitalWrite(7, 0);
    delay(dur_ms);
    return;
  } if (x == 1) { // Left
      digitalWrite(4, 0);
      digitalWrite(5, 1);
      digitalWrite(6, 1);
      digitalWrite(7, 0);
      delay(dur_ms);
      mtr(0, 50);
  } if (x == 2) { // Right
    digitalWrite(4, 1);
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    digitalWrite(7, 1);
    delay(dur_ms);
    mtr(0, 50);
  } if (x == 3) { // Forward
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    digitalWrite(6, 1);
    digitalWrite(7, 1);
    delay(dur_ms);
    mtr(0, 50);
  } else {
    return;
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(MTR_IN1, OUTPUT);
  pinMode(MTR_IN2, OUTPUT);
  pinMode(MTR_IN3, OUTPUT);
  pinMode(MTR_IN4, OUTPUT);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);
}

bool ir1, ir2, ir3, ir4, ir5;

void loop() {
  // put your main code here, to run repeatedly:
  ir1 = digitalRead(IR1);
  ir2 = digitalRead(IR2);
  ir3 = digitalRead(IR3);
  ir4 = digitalRead(IR4);
  ir5 = digitalRead(IR5);

  while (!(ir1 && ir5) && (ir2 || ir4) || (ir3 && ir4)) {
    mtr(3, DRIVE_THRESH_ACCURACY);
  } while (ir1 && ir2 && !(ir4 && ir5)) {
    mtr(1, DRIVE_THRESH_ACCURACY);
  } while (ir4 && ir5 && (!ir1 || !ir2)) {
    mtr(2, DRIVE_THRESH_ACCURACY);
  }
}
