/*

    For Ronin's Robotic "KAI" board.
             created 2019
     by Abdullah YILDIRIM @dyrylmz
	 by Mehmet Murat YILMAZ @mehmetmurat.yilmaz
        www.roninsrobotic.com


*/
#ifndef KAIpro_H
#define KAIpro_H

#include <Arduino.h>
class KAIpro{ 
public:
 KAIpro();
 ~KAIpro();
 void buzzerDelay(int buzzer_delay_mod );
 void brake(boolean brake_mod_pro );
 void numberWrite(int dis);
 void intro();
 void ledWrite(boolean data_7 , boolean data_6 , boolean data_3 , boolean data_2 , boolean data_1 , boolean data_5 , boolean data_4 , boolean data_0 );
 void driveDC(float left_m_pwm , float right_m_pwm );
 void driveDiff(int ch_speed , int ch_turn );
 void buzzer(unsigned long b_freq_pro );
 void buzzer(unsigned long b_freq_pro , int b_freq_time_pro );
};

#endif
