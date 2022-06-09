#include <AccelStepper.h>
AccelStepper StepperP1(1, 8, 9);
AccelStepper StepperP2(1, 10, 11);
AccelStepper StepperS1(1, 12, 13);


#include <EncButton.h>
EncButton<EB_TICK, 2, 4, 6> enc1;  // энкодер 1 с кнопкой <A, B, KEY>
EncButton<EB_TICK, 3, 5, 7> enc2;  // энкодер 2 с кнопкой <A, B, KEY>
int value1 = 0;
int value2 = 0;
int speedP1 = 0;
int speedP2 = 0;
int speedS1 = 0;
bool mot = true;
 

int checkWay_1 = -1; //используется для смены направления насосов
int checkWay_2 = -1; //для смены направления мешалки


 
void setup() {
  Serial.begin(9600);
}

void loop() {    

   // обязательная функция отработки. Должна постоянно опрашиваться
  enc1.tick();                       // изменение скорсти моторов
  if (enc1.right()) value1 -= 5;     // если был поворот направо, увеличиваем на 5
  if (enc1.left()) value1 += 5;      // если был поворот налево, уменьшаем на 5
  if (enc1.rightH()) value1 -= 50;   // если был быстрый поворот направо, увеличиваем на 20
  if (enc1.leftH()) value1 += 50;    // если был быстрый поворот налево, уменьшаем на 20
                 
  
  
  if (enc1.hasClicks(1)){
    if (mot){
    speedP1=value1;
    Serial.println(value1);
    Serial.println(speedP1);
    }
    else{
    speedP2=value1;
    Serial.println(value1);
    Serial.println(speedP2);
    }
  }

  if (enc1.hasClicks(2)) {
    if (mot){
      speedP1 = -speedP1;
      value1=-value1;
    }
    else{
      speedP2 = -speedP2;
      value1=-value1;
    }
  }
  if (enc1.hasClicks(3)) {
    
    if (mot){
      value1 = speedP2;
      mot = !mot;
    }
    else {
      value1 = speedP1;
      mot = !mot;
    }
    
  }

  if (enc1.held()) {
    speedP1=0;
    speedP2=0;

    value1 = 0;
  }

  
  enc2.tick();                       // изменение скорсти мешалки
  if (enc2.right()) value2 -= 5;      // если был поворот направо, увеличиваем на 5
  if (enc2.left()) value2 += 5;       // если был поворот налево, уменьшаем на 5
  if (enc2.rightH()) value2 -= 50;    // если был быстрый поворот направо, увеличиваем на 20
  if (enc2.leftH()) value2 += 50;     // если был быстрый поворот налево, уменьшаем на 20

  if (enc2.hasClicks(1)){
    speedS1=value2;
    Serial.println(value2);
    Serial.println(speedS1);
    }
  

  if (enc2.hasClicks(2)) {
      speedS1 = -speedS1;
      value2 = -value2;
    }
    
  if (enc2.held()) {
    speedS1 = 0;
    value2 = 0;
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
