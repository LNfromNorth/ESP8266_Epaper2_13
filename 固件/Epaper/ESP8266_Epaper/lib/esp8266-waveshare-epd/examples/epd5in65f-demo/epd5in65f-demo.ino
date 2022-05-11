#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include "imagedata.h"
#include <stdlib.h>

void setup()
{
	DEV_Module_Init();
	printf("EPD_5in65F_test Demo\r\n");
	printf("e-Paper Init and Clear...\r\n");
	EPD_5IN65F_Init();
	EPD_5IN65F_Clear(EPD_5IN65F_WHITE);
	
#if 1 //Show array data
	printf("Show array image...\r\n");
	EPD_5IN65F_Display_part(gImage_5in65f, 204, 153, 192, 143);
	DEV_Delay_ms(2000);
#endif

	printf("e-Paper Clear...\r\n");
	EPD_5IN65F_Clear(EPD_5IN65F_WHITE);

	printf("Sleep...\r\n");
	EPD_5IN65F_Sleep();
 
}

/* The main loop -------------------------------------------------------------*/
void loop()
{
  //
}
