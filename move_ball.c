#include "config.h"
#include "lcdWrite.h"
#include "byteLcd.h"
#include <stdio.h>
void move_ball(void)
{
    static uchar row = 4;
    static uchar col = 1;
    static uchar j,k,l = 0;
    
  const  bool upper_pos[17] = {0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xc0,0xe0,0xc0,0x80,0x00,0x00,0x00,0x00,0x00,0x00};    // up and down positions
  const  bool start_pos[19] ={0xe0,0xe0,0xe0,0x70,0x38,0x1c,0x0e,0x07,0x03,0x01,0x00,0x01,0x03,0x07,0x0e,0x1c,0x38,0x70,0xe0};
  uchar temp[4] ={0xe0,0xe0,0xe0};
     //                         0    1     2    3   4     5     6   7   8     9     10  11  12   13   14   15   16    
 //while(col <81)
 // {
  if(z == 0)                              // print out 0x00, 0xe0 for 3 spaces x
  {
    lcdWrite(SET_Y|row, LOW);
    lcdWrite(SET_X|col, LOW);
    for(j = 0;j <3;j++)
    {
        lcdWrite(start_pos[j], HIGH);       // initially draw ball at LHS of LCD
        printf("z = %d col = %d,\n",z, col);
    }
    
  }
  
   if(z==1)
  {
  col = col + 3;
  lcdWrite(SET_Y|row, LOW);
  lcdWrite(SET_X|col, LOW);
  for(j = 0;j <3;j++)
  {
    lcdWrite(start_pos[j], HIGH);       // draw ball 3 columns ahead of initial position
    printf("z = %d col = %d,\n",z, col);
  }
  
  
 
   
    lcdWrite(SET_Y|row, LOW);
    lcdWrite(SET_X|col, LOW);
    for(j = 0;j <3;j++)
    {
        lcdWrite(0x00, HIGH);       // erase ball behind current ball
        printf("z = %d col = %d,\n",z, col);
    }
    z = 0;
    printf("z = %d\n",z);
   }
  }

  

