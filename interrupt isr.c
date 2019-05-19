#include "config.h"
#include "interrupt isr.h"
#include "paddle_left.h"
#include "byteLcd.h"
#include "move_ball.h"

void interrupt isr(void)
{
    static uchar row, col;
    
    row = 4;
    col = 1;
    if ( INTCONbits.TMR0IF = 1)
    {
        //GREEN_LED = ~GREEN_LED;
         paddle_left();      // put this in a 1ms interrupt routine
         TMR0 = 0x00; 
         INTCONbits.TMR0IF = 0; 
    }
    if (PIR1bits.TMR1IF == 1 )       // TMR1 is 1 sec gravity timer interrupt
    {
        move_ball();
        GREEN_LED = ~GREEN_LED;
        TMR1H = 0x00;               // preload TMR1 to generate a 125ms interrupt
        TMR1L = 0x00;
        z = 1;
        PIR1bits.TMR1IF = 0;
    }
}
