// будем искать слово hello
#include <AccelStepper.h>


AccelStepper StepperP1(1, 8, 9);
AccelStepper StepperP2(1, 10, 11);
AccelStepper StepperS1(1, 12, 13);
int speedP1 = 0;
int speedP2 = 0;
int speedS1 = 0;


void setup() {
  Serial.begin(9600);
  Serial.setTimeout(5);
}

void loop() {    

  if (Serial.available() > 1) {
    char key = Serial.read();
    int val = Serial.parseInt();
    switch (key) {
      case 't': Serial.println("Connected");
        break;
      case 'e': 
        speedP1 = 0;
        speedP2 = 0;
        speedS1 = 0;
        Serial.println("Stopped");
        break;
      case 'o':
        speedP1 = val;
        Serial.println("OK");
        break;
      case 'w':
        speedP2 = val;
        Serial.println("OK");
        break;
     case 's':
        speedS1 = val;
        Serial.println("OK");
        break;
        
    }
    

  }
  StepperP1.setMaxSpeed(speedP1); //устанавливаем максимальную скорость вращения ротора двигателя (шагов/секунду)
  StepperP1.setSpeed(speedP1);
  StepperP1.setAcceleration(10); //устанавливаем ускорение (шагов/секунду^2)
  StepperP1.move(checkWay_1);
  StepperP1.runSpeed();
  StepperP2.setMaxSpeed(speedP2); //устанавливаем максимальную скорость вращения ротора двигателя (шагов/секунду)
  StepperP2.setSpeed(speedP2);
  StepperP2.setAcceleration(10); //устанавливаем ускорение (шагов/секунду^2)
  StepperP2.move(checkWay_1);
  StepperP2.runSpeed();
  StepperS1.setMaxSpeed(speedS1); //устанавливаем максимальную скорость вращения ротора двигателя (шагов/секунду)
  StepperS1.setSpeed(speedS1);
  StepperS1.setAcceleration(10); //устанавливаем ускорение (шагов/секунду^2)
  StepperS1.move(checkWay_2);
  StepperS1.runSpeed(); 
}
