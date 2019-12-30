/*

    For Ronin's Robotic "KAI" board.
             created 2019
     by Abdullah YILDIRIM @dyrylmz
	 by Mehmet Murat YILMAZ @mehmetmurat.yilmaz
        www.roninsrobotics.com


*/
#include "KAIpro.h"

#define pro_sh 4
#define pro_ds 6
#define pro_st 5
#define buzzer_pin_pro 13
#define l_e_f_t_m_1 11
#define l_e_f_t_m_2 3
#define r_i_g_h_t_m_1 10
#define r_i_g_h_t_m_2 9


int buzzer_delay_pro = 0, intro_delay = 80;
unsigned long millis1_tim_pro = 0, millis2_tim_pro = 0, millist_tim_pro = 0;
boolean buzzer_State_pro = 0, pro_short_brake = 1;


KAIpro::KAIpro() {

  pinMode(pro_sh , OUTPUT);
  pinMode(pro_ds , OUTPUT);
  pinMode(pro_st , OUTPUT);
  pinMode(l_e_f_t_m_1 , OUTPUT);
  pinMode(l_e_f_t_m_2 , OUTPUT);
  pinMode(r_i_g_h_t_m_1 , OUTPUT);
  pinMode(r_i_g_h_t_m_2 , OUTPUT);
  pinMode(buzzer_pin_pro, OUTPUT);  
     
}

KAIpro::~KAIpro() {
}



void KAIpro :: brake(boolean brake_mod_pro ) {
	if(brake_mod_pro == 0){
		pro_short_brake = 0 ;
	}else{
		pro_short_brake = 1 ;
	}
}


void KAIpro :: driveDC(float left_m_pwm , float right_m_pwm) {

  if (pro_short_brake == 1 & left_m_pwm == 0) {
    analogWrite(l_e_f_t_m_1 , 255);
    analogWrite(l_e_f_t_m_2 , 255);
  } else if (left_m_pwm < 0) {
    left_m_pwm = -1 * left_m_pwm ;
    analogWrite(l_e_f_t_m_1 , 0);
    analogWrite(l_e_f_t_m_2 , left_m_pwm);
  } else if (left_m_pwm > 0) {
    analogWrite(l_e_f_t_m_1 , left_m_pwm);
    analogWrite(l_e_f_t_m_2 , 0);
  } else if (pro_short_brake == 0 & left_m_pwm == 0) {
    analogWrite(l_e_f_t_m_1 , left_m_pwm);
    analogWrite(l_e_f_t_m_2 , left_m_pwm);
  }
  
  if (pro_short_brake == 1 & right_m_pwm == 0) {
    analogWrite(r_i_g_h_t_m_1 , 255);
    analogWrite(r_i_g_h_t_m_2 , 255);
  } else if (right_m_pwm < 0) {
    right_m_pwm = -1 * right_m_pwm ;
    analogWrite(r_i_g_h_t_m_1 , 0);
    analogWrite(r_i_g_h_t_m_2 , right_m_pwm);
  } else if (right_m_pwm > 0) {
    analogWrite(r_i_g_h_t_m_1 , right_m_pwm);
    analogWrite(r_i_g_h_t_m_2 , 0);
  } else if (pro_short_brake == 0 & right_m_pwm == 0) {
    analogWrite(r_i_g_h_t_m_1 , right_m_pwm);
    analogWrite(r_i_g_h_t_m_2 , right_m_pwm);
  }
  
}
void KAIpro :: driveDiff(int ch_speed , int ch_turn ){
   int Left_m_Power = ch_speed - ch_turn;
   int Right_m_Power = ch_speed + ch_turn;
   int MAX_M_PWM = 250;
   
  if (Left_m_Power < -MAX_M_PWM) {
    Left_m_Power=-MAX_M_PWM;
  }
  else if (Left_m_Power > MAX_M_PWM) { 
    Left_m_Power=MAX_M_PWM;
  }
  if (Right_m_Power > MAX_M_PWM) {
    Right_m_Power=MAX_M_PWM;
  }
  else if (Right_m_Power < -MAX_M_PWM) {
    Right_m_Power=-MAX_M_PWM;
  }
  
	 if(Left_m_Power<=0) {
      Left_m_Power=Left_m_Power*(-1);
      digitalWrite(l_e_f_t_m_2, LOW);
      analogWrite(l_e_f_t_m_1 , Left_m_Power);
    }else {
      digitalWrite(l_e_f_t_m_1 , LOW);
      analogWrite(l_e_f_t_m_2, Left_m_Power);
       }
	   
	     if(Right_m_Power<=0) {
     Right_m_Power=Right_m_Power*(-1);
     
     digitalWrite(r_i_g_h_t_m_1, LOW );
     analogWrite(r_i_g_h_t_m_2, Right_m_Power);
     
    }else {
    digitalWrite(r_i_g_h_t_m_2, LOW);
    analogWrite(r_i_g_h_t_m_1, Right_m_Power);
    }		  
			
						
}

void KAIpro :: numberWrite(int dis ) {
  if (dis == 0) {
    ledWrite(0, 0, 1, 1, 1, 1, 1, 1);
    //1, 1, 1, 1, 1, 1, 0, 0
  } else if (dis == 1) {
    ledWrite(0, 0, 0, 0, 0, 1, 1, 0);
    //0, 1, 1, 0, 0, 0, 0, 0
  } else if (dis == 2) {
    ledWrite(0, 1, 0, 1, 1, 0, 1, 1);
    //1, 1, 0, 1, 1, 0, 1, 0
  } else if (dis == 3) {
    ledWrite(0, 1, 0, 0, 1, 1, 1, 1);
    //1, 1, 1, 1, 0, 0, 1, 0
  } else if (dis == 4) {
    ledWrite(0, 1, 1, 0, 0, 1, 1, 0);
    //0, 1, 1, 0, 0, 1, 1, 0
  } else if (dis == 5) {
    ledWrite(0, 1, 1, 0, 1, 1, 0, 1);
    //1, 0, 1, 1, 0, 1, 1, 0
  } else if (dis == 6) {
    ledWrite(0, 1, 1, 1, 1, 1, 0, 1);
    //1, 0, 1, 1, 1, 1, 1, 0
  } else if (dis == 7) {
    ledWrite(0, 0, 0, 0, 0, 1, 1, 1);
    //1, 1, 1, 0, 0, 0, 0, 0
  } else if (dis == 8) {
    ledWrite(0, 1, 1, 1, 1, 1, 1, 1);
    //1, 1, 1, 1, 1, 1, 1, 0
  } else if (dis == 9) {
    ledWrite(0, 1, 1, 0, 1, 1, 1, 1);
    //1, 1, 1, 1, 0, 1, 1, 0
  } else if (dis == 10) {
    ledWrite(1, 0, 1, 1, 1, 1, 1, 1);
    //1, 1, 1, 1, 1, 1, 0, 0
  } else if (dis == 11) {
    ledWrite(1, 0, 0, 0, 0, 1, 1, 0);
    //0, 1, 1, 0, 0, 0, 0, 0
  } else if (dis == 12) {
    ledWrite(1, 1, 0, 1, 1, 0, 1, 1);
    //1, 1, 0, 1, 1, 0, 1, 0
  } else if (dis == 13) {
    ledWrite(1, 1, 0, 0, 1, 1, 1, 1);
    //1, 1, 1, 1, 0, 0, 1, 0
  } else if (dis == 14) {
    ledWrite(1, 1, 1, 0, 0, 1, 1, 0);
    //0, 1, 1, 0, 0, 1, 1, 0
  } else if (dis == 15) {
    ledWrite(1, 1, 1, 0, 1, 1, 0, 1);
    //1, 0, 1, 1, 0, 1, 1, 0
  } else if (dis == 16) {
    ledWrite(1, 1, 1, 1, 1, 1, 0, 1);
    //1, 0, 1, 1, 1, 1, 1, 0
  } else if (dis == 17) {
    ledWrite(1, 0, 0, 0, 0, 1, 1, 1);
    //1, 1, 1, 0, 0, 0, 0, 0
  } else if (dis == 18) {
    ledWrite(1, 1, 1, 1, 1, 1, 1, 1); 
    //1, 1, 1, 1, 1, 1, 1, 0
  } else if (dis == 19) {
    ledWrite(1, 1, 1, 0, 1, 1, 1, 1);
    //1, 1, 1, 1, 0, 1, 1, 0
  }
}

void KAIpro :: intro() {
	ledWrite(0, 0, 0, 0, 0, 0, 0, 1);
	delay(intro_delay);
	ledWrite(0, 0, 0, 0, 0, 0, 1, 0);
	delay(intro_delay);
	ledWrite(0, 0, 0, 0, 0, 1, 0, 0);
	delay(intro_delay);
	ledWrite(0, 0, 0, 0, 1, 0, 0, 0);
	delay(intro_delay);
	ledWrite(0, 0, 0, 1, 0, 0, 0, 0);
	delay(intro_delay);
	ledWrite(0, 0, 1, 0, 0, 0, 0, 0);
	delay(intro_delay);
	ledWrite(0, 1, 0, 0, 0, 0, 0, 0);
	delay(intro_delay);
	ledWrite(1, 0, 0, 0, 0, 0, 0, 0);
	delay(intro_delay);
	ledWrite(0, 0, 0, 0, 0, 0, 0, 0);
	delay(intro_delay);
	ledWrite(1, 0, 0, 0, 0, 0, 0, 0);
	delay(intro_delay);
	ledWrite(1, 1, 0, 0, 0, 0, 0, 0);
	delay(intro_delay);
	ledWrite(1, 1, 1, 0, 0, 0, 0, 0);
	delay(intro_delay);
	ledWrite(1, 1, 1, 1, 0, 0, 0, 0);
	delay(intro_delay);
	ledWrite(1, 1, 1, 1, 1, 0, 0, 0);
	delay(intro_delay);
	ledWrite(1, 1, 1, 1, 1, 1, 0, 0);
	delay(intro_delay);
	ledWrite(1, 1, 1, 1, 1, 1, 1, 0);
	delay(intro_delay);
	ledWrite(1, 1, 1, 1, 1, 1, 1, 1);
	delay(intro_delay);
	ledWrite(0, 0, 0, 0, 0, 0, 0, 0);
	buzzer(500, 100);
	delay(intro_delay);
	ledWrite(1, 1, 1, 1, 1, 1, 1, 1);
	delay(intro_delay);
	ledWrite(0, 0, 0, 0, 0, 0, 0, 0);
	delay(intro_delay);
	ledWrite(1, 1, 1, 1, 1, 1, 1, 1);
	delay(intro_delay);
	ledWrite(1, 1, 1, 1, 1, 1, 1, 0);
	delay(intro_delay);
    ledWrite(1, 1, 1, 1, 1, 1, 0, 0);
	delay(intro_delay);
	ledWrite(1, 1, 1, 1, 1, 0, 0, 0);
	delay(intro_delay);
	ledWrite(1, 1, 1, 1, 0, 0, 0, 0);
	delay(intro_delay);
	ledWrite(1, 1, 1, 0, 0, 0, 0, 0);
	delay(intro_delay);
	ledWrite(1, 1, 0, 0, 0, 0, 0, 0);
	delay(intro_delay);
	ledWrite(1, 0, 0, 0, 0, 0, 0, 0);
	delay(intro_delay);
	ledWrite(0, 0, 0, 0, 0, 0, 0, 0);
}

void KAIpro :: ledWrite(boolean data_0 , boolean data_1 , boolean data_2 , boolean data_3 , boolean data_4 , boolean data_5 , boolean data_6 , boolean data_7 ) {
  digitalWrite(pro_st , LOW);
  digitalWrite(pro_sh , LOW);
  if (data_0 == 0) {
    digitalWrite(pro_ds , LOW);
  } else {
    digitalWrite(pro_ds , HIGH);
  }
  digitalWrite(pro_sh , HIGH);
  digitalWrite(pro_sh , LOW);
  if (data_1 == 0) {
    digitalWrite(pro_ds , LOW);
  } else {
    digitalWrite(pro_ds , HIGH);
  }
  digitalWrite(pro_sh , HIGH);
  digitalWrite(pro_sh , LOW);
  if (data_2 == 0) {
    digitalWrite(pro_ds , LOW);
  } else {
    digitalWrite(pro_ds , HIGH);
  }
  digitalWrite(pro_sh , HIGH);
  digitalWrite(pro_sh , LOW);
  if (data_3 == 0) {
    digitalWrite(pro_ds , LOW);
  } else {
    digitalWrite(pro_ds , HIGH);
  }
  digitalWrite(pro_sh , HIGH);
  digitalWrite(pro_sh , LOW);
  if (data_4 == 0) {
    digitalWrite(pro_ds , LOW);
  } else {
    digitalWrite(pro_ds , HIGH);
  }
  digitalWrite(pro_sh , HIGH);
  digitalWrite(pro_sh , LOW);
  if (data_5 == 0) {
    digitalWrite(pro_ds , LOW);
  } else {
    digitalWrite(pro_ds , HIGH);
  }
  digitalWrite(pro_sh , HIGH);
  digitalWrite(pro_sh , LOW);
  if (data_6 == 0) {
    digitalWrite(pro_ds , LOW);
  } else {
    digitalWrite(pro_ds , HIGH);
  }
  digitalWrite(pro_sh , HIGH);
  digitalWrite(pro_sh , LOW);
  if (data_7 == 0) {
    digitalWrite(pro_ds , LOW);
  } else {
    digitalWrite(pro_ds , HIGH);
  }
  digitalWrite(pro_sh , HIGH);
  digitalWrite(pro_sh , LOW);
  digitalWrite(pro_st , HIGH);
  digitalWrite(pro_st , LOW);
}

void KAIpro :: buzzerDelay(int buzzer_delay_mod ) {
buzzer_delay_pro = buzzer_delay_mod ;
}

void KAIpro ::  buzzer(unsigned long b_freq_pro ) {
  if (b_freq_pro > 0) {
    b_freq_pro = 1000000 / b_freq_pro  ;
    b_freq_pro = b_freq_pro / 2 ;
    millis2_tim_pro = micros();
    if ( millis2_tim_pro - millist_tim_pro >= b_freq_pro) {
      millist_tim_pro = millis2_tim_pro ;

      if (buzzer_State_pro == LOW) {
        buzzer_State_pro = HIGH;
      } else {
        buzzer_State_pro = LOW;
      }

    }
    digitalWrite(buzzer_pin_pro , buzzer_State_pro);
  } else {
    digitalWrite(buzzer_pin_pro , LOW);
  }
}

void KAIpro :: buzzer(unsigned long b_freq_pro , int b_freq_pro_time ) {
  b_freq_pro = 1000000 / b_freq_pro  ;
  b_freq_pro = b_freq_pro / 2 ;
  millis1_tim_pro = millis();
  while (b_freq_pro_time > 0 && millis() - millis1_tim_pro < b_freq_pro_time ) {
    digitalWrite(buzzer_pin_pro , HIGH);  
    delayMicroseconds(b_freq_pro);                       
    digitalWrite(buzzer_pin_pro , LOW);    
    delayMicroseconds(b_freq_pro);
  }
  delay(buzzer_delay_pro);
  b_freq_pro_time = 0 ;

}
