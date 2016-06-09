# LCDtest
LCD test tools

Experimenting with various 1602/2004 drivers on the Raspberry - these are the .c files I used to test them. 
Assumes wiringPi installed in /opt. Based on the demo code of 52pi.com.

Compile: gcc xxx.c -lwiringPi /opt/wiringPi/devLib/lcd.o -o xxx
