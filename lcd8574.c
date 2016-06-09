#include <stdio.h>                                                            //include standard input output head file                                                            
#include <wiringPi.h>                                                         //include wiringpi                                                     
#include <pcf8574.h>
#include <lcd.h>                                                              //include LCD control head file                                                   
int main()
{
	int display,i,count;                                                 
	wiringPiSetup();                                                      //init wiringPi                                                    
	pcf8574Setup (100, 0x27);                                            //init mcp23017 chip I2C address: 0x20,the first pin number: 100                                          
	printf ("Raspberry Pi - PCF8574 Test\n");                            //print information
	for(i=0;i<16;i++)                            
	pinMode(100+i,OUTPUT);                                                //set pin 100 - 115 as output                          
	digitalWrite(103,1);                                                  //set pin 101 low voltage                              
	display=lcdInit(2,16,4,100,102,104,105,106,107,0,0,0,0);              //lcd init 2*16,4 bit control,use 100,101,102,103,104 pin as control pin         
	lcdHome(display);                                                     //reset cursor  
	lcdClear(display);                                                    //clear screen   
	lcdPosition(display,0,0);                                             //set display location (0,0)   
	lcdPuts(display,"PCF8574/HD44780");                                       //print string "Hello World"
while(1)                                                                      //always display
{       
 	lcdPosition(display,0,1); 
 	lcdPuts(display,"-RED------------");
	delay(1000);
        lcdPosition(display,0,1);
        lcdPuts(display,"-----GREEN------");
        delay(1000);
        lcdPosition(display,0,1);
        lcdPuts(display,"-----------BLUE-");
        delay(1000);
        digitalWrite (103,0);
        lcdPosition(display,0,1);
	lcdPuts(display,"----------------");
	delay(1000);
        digitalWrite (103,1);
   }
}
