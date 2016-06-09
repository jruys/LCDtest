#include <stdio.h>                                                            //include standard input output head file                                                            
#include <wiringPi.h>                                                         //include wiringpi                                                     
#include <mcp23017.h>                                                         //include mcp23017 control head file                                         
#include <lcd.h>                                                              //include LCD control head file                                                   
int main()
{
	int display,i,count;                                                 
	wiringPiSetup();                                                      //init wiringPi                                                    
	mcp23017Setup (100, 0x20);                                            //init mcp23017 chip I2C address: 0x20,the first pin number: 100                                          
	printf ("Raspberry Pi - MCP23017 Test\n");                            //print information
	for(i=0;i<16;i++)                            
	pinMode(100+i,OUTPUT);                                                //set pin 100 - 115 as output                          
	digitalWrite(101,0);                                                  //set pin 101 low voltage                              
	display=lcdInit(2,16,4,100,102,103,104,105,106,0,0,0,0);              //lcd init 2*16,4 bit control,use 100,101,102,103,104 pin as control pin         
	lcdHome(display);                                                     //reset cursor  
	lcdClear(display);                                                    //clear screen   
	lcdPosition(display,0,0);                                             //set display location (0,0)   
	lcdPuts(display,"MCP23017/HD44780");                                       //print string "Hello World"
	pinMode(0, OUTPUT);                                                   //set Raspberry pi pin 0 as output   
	pinMode(2, OUTPUT);                                                   //set Raspberry Pi pin 2 as output  
	pinMode(3, OUTPUT);                                                   //set Raspberry Pi pin 3 as output
while(1)                                                                      //always display
{       
 	lcdPosition(display,0,1); 
 	lcdPuts(display,"-RED------------");
	digitalWrite (0,1);
 	digitalWrite (2,0);
 	digitalWrite (3,0);
	delay(1000);
        lcdPosition(display,0,1);
        lcdPuts(display,"-----GREEN------");
        digitalWrite (0,0);
        digitalWrite (2,1);
        digitalWrite (3,0);
        delay(1000);
        lcdPosition(display,0,1);
        lcdPuts(display,"-----------BLUE-");
        digitalWrite (0,0);
        digitalWrite (2,0);
        digitalWrite (3,1);
        delay(1000);
        lcdPosition(display,0,1);
        lcdPuts(display,"-RED-GREEN------");
        digitalWrite (0,1);
        digitalWrite (2,1);
        digitalWrite (3,0);
        delay(1000);
        lcdPosition(display,0,1);
        lcdPuts(display,"-RED-------BLUE-");
        digitalWrite (0,1);
        digitalWrite (2,0);
        digitalWrite (3,1);
        delay(1000);
        lcdPosition(display,0,1);
        lcdPuts(display,"-----GREEN-BLUE-");
        digitalWrite (0,0);
        digitalWrite (2,1);
        digitalWrite (3,1);
        delay(1000);
        lcdPosition(display,0,1);
        lcdPuts(display,"-RED-GREEN-BLUE-");
        digitalWrite (0,1);
        digitalWrite (2,1);
        digitalWrite (3,1);
        delay(1000);
        lcdPosition(display,0,1);
        lcdPuts(display,"----------------");
        digitalWrite (0,0);
        digitalWrite (2,0);
        digitalWrite (3,0);
        delay(1000);
   }
}
