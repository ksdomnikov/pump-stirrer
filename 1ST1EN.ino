#include <AccelStepper.h>
AccelStepper StepperS(1, 3, 4);




#include <EncButton.h>
EncButton2<EB_TICK, 5, 6, 7> enc2;  // энкодер с кнопкой <A, B, KEY>
int value = 0;
int speedS =0;


 

int checkWay_1 = -1; //используется для смены направления 


 
void setup() {
  Serial.begin(9600);
}

void loop() {    
  enc2.tick();
  if (enc2.right()) value -= 5;      // если был поворот направо, увеличиваем на 5
  if (enc2.left()) value += 5;       // если был поворот налево, уменьшаем на 5
  if (enc2.rightH()) value -= 50;    // если был быстрый поворот направо, увеличиваем на 20
  if (enc2.leftH()) value += 50;     // если был быстрый поворот налево, уменьшаем на 20
                                     // если был совершён поворот (индикатор поворота в любую сторону)
  if (enc2.hasClicks(1)){
    speedS=value;
    Serial.println(value);
    Serial.println(speedS);
    }
  

  if (enc2.hasClicks(2)) {
      speedS = -speedS;
      value=-value;
    }
    
  if (enc2.held()) {
    speedS=0;
    value =0;
  }
  StepperS.setMaxSpeed(speedS); //устанавливаем максимальную скорость вращения ротора двигателя (шагов/секунду)
  StepperS.setSpeed(speedS);
  StepperS.setAcceleration(10); //устанавливаем ускорение (шагов/секунду^2)
  StepperS.move(checkWay_1);
  StepperS.runSpeed(); 
}
