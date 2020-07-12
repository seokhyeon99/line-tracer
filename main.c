//----MAIN function-----

#include "RoboCAR.h"


unsigned int psd_dist = 0;
unsigned char lineValue;

int main(void)
{ 
   unsigned char rcv_data;
   
   UART_Init();
   BUZZER_Init();
   LED_Init();
   Timer1_PWM_Init();
   Timer0_Init();
   MOTOR_Init();
   PSD_Init();
   LineSensor_Init();
 

   while(1)
   {
     UART_getch();
     rcv_data = RingBuff_Get(&ring);
    psd_dist = Get_dist_cm();
    lineValue = PINC;

    Front_LED_on();

     //Avoid obstacle and return to the line

   if(psd_dist<40)
   {
      Right_turn();
      _delay_ms(500);
      Forward();
      _delay_ms(1600);
      Left_turn();
      _delay_ms(750);
      Forward();
      _delay_ms(1530);
      Forward_right();
      _delay_ms(700);
   }
   else{

   
   switch(lineValue)
   {
      case 0b01111110:
         Forward_right();
         break;

      case 0b00111110:
         Forward_right();
         break;

     case 0b00000110:
         Forward_right();
         break;

      case 0b10011110:
         Speed_up();
         Forward();
       
         break;
     case 0b11001110:
         Speed_up();
         Forward();
         break;

      case 0b11000110:
         Speed_up();
         Forward();
         break;

     case 0b11000010:
         Speed_up();
         Forward();
         break;

     case 0b10000100:
         Speed_up();
         Forward();
         break;

     case 0b10000010:
         Speed_up();
         Forward();
         Speed_up();
         break;

      case 0b11100010:
         Speed_up();
         Forward();
         Speed_up();
         break;

     case 0b11100110:
         Speed_up();
         Forward();
         break;

     case 0b11110110:
         Speed_up();
         Forward();
         Speed_up();
         break;

      case 0b11111000:
         Forward_left();
         break;

      case 0b11111010:
         Forward_left();
         break;

      case 0b11111100:
         Forward_left();
         break;
     
     case 0b11110000:
         Forward_left();
         break;

     case 0b11100000:
         Forward_left();
         break;

      case 0b11110010:
         Speed_up();
         Forward();
         break;
       }
     }
   }
   return 0;
}