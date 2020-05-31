 #include <REG51V.H> 
#include "LCD.H"
#include "SECDELAY.H"
#include "ADC.H"
#include "CONVERT_ADC.H"

void main()
	{  			 
		LCD_INIT();
		LCDSTR(0x80,"       ADC      "); 
		LCDSTR(0xC0,"  VALUE =       ");	
		while (1)
			{
				AEN   = 0;			    //enable ADC
				WRITE = 0;				//Write=0
				WRITE = 1;				//WR=1 L-TO-H TO START CONVERSION
				while (INTR == 1) ;	    //WAIT FOR END OF CONVERSION
				READ  = 0;				//CONVERSION FINISHED,ENABLE RD
				ADC = 3.65*(MYDATA - 48);											
				LCDCMD(0xCA);
    			CONVERT_ADC(ADC);
			   	READ  = 1;				//MAKE RD=1 FOR NEXT ROUND
				_1SECDELAY(10);
			}
	}
	