#include <avr/io.h>
#include <util/delay.h> 
#include "uart.h"

// define some macros
#define BAUD 9600                         // define baud rate
int main(void){
  init();
  uart_transmit('K');  
  char val;

  while (1)
  {
    char Button1[]="Button Pressed ";
    int i;
    
    char button= (PINB&0b00010000);     // read pin 4 of port B
    
    if ((button == 0))                 // when the button is pressed pin 4 will be connected to ground
    {

     for (i = 0; i < 15; ++i)
     {
       uart_transmit (Button1[i]);
     }
     while (!(PINB&0b00010000));      // stay here as long as the button is pressed (debouncing)
    } 
//----------------------------------------------------
    if (uart_recieve_ready ());
    {
      val = UDR0;
        
      if(val == 'N')
      {
        SET_BIT(PORTB,0);
      }
      else if (val == 'F')
      {
        CLR_BIT(PORTB,0);
      }                             
    }    
  }
  return 0; 
}



void init(){
  uart_init (BAUD); 
  SET_BIT(PORTB,4);
  CLR_BIT(PORTB,0);
  DDRB= 0b00000001;  // bit 0 is R/W while all other bits are R
}

