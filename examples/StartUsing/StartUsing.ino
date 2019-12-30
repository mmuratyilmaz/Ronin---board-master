#include <KAIpro.h>
KAIpro Control ;

#define button_1 8
#define button_2 7
#define button_3 13

int bt_1 , bt_2 , bt_3;
byte number = 0;
boolean value = 0;

void setup() {

  pinMode( button_1 , INPUT);
  pinMode( button_2 , INPUT);
  pinMode( button_3 , INPUT);

  Control.buzzerDelay(50);
  Control.buzzer(500, 100);
  Control.intro();
  Control.buzzer(440, 375);
  Control.buzzer(523, 125);
  Control.buzzer(659, 650);

}

void loop() {

  if (digitalRead(button_1) == LOW || digitalRead(button_2) == LOW || digitalRead(button_3) == LOW )
    Control.buzzer(500 + number * 50);
  else
    Control.buzzer(0);


  if (bt_1 != digitalRead(button_1)) { //for increase the number.
    if (bt_1 == HIGH) {                // sayıyı arttırmak için bir koşul.
      number = number + 1 ;
    }
    bt_1 =  digitalRead(button_1);
  }


  if (bt_2 != digitalRead(button_2)) { //for decrease the number
    if (bt_2 == HIGH) {                // sayıyı eksiltmek için bir koşul.
      number = number - 1 ;
    }
    bt_2 =  digitalRead(button_2);
  }


  if (bt_3 != digitalRead(button_3)) { // for change the motor direction.
    if (bt_3 == HIGH) {                // motor yönlerinin değiştirilmesi için bir koşul.
      if (value == 1) {
        value = 0;
      } else {
        value = 1;
      }
    }
    bt_3 =  digitalRead(button_3);
  }

  if (value == 1) {
    Control.driveDC(number * -13.42, number * -13.42 ); // You can enter values " -255 ~ 255 ". " control.moto(-210 , 210 );" as ...
  } else {                                           // minus values for backward motor direction ...
    Control.driveDC(number * 13.42, number * 13.42 );   // positive values for forward motor direction ...
  }                                                  // " -255 ~ 255 arası değer girebilirsiniz. " control.moto(-210 , 210 );" gibi...

  if (number > 19) { // We fix the screen number between 0~19.
    number = 0 ;     // Sayıyı 0~19 arası sabitlemek için bir koşul.
  }

  if (number < 0) {
    number = 19 ;
  }

  Control.numberWrite(number);

}
