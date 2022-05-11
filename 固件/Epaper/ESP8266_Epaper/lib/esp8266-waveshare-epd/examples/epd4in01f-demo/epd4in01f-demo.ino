#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include "imagedata.h"
#include <stdlib.h>

void setup()
{
  DEV_Module_Init();
  printf("EPD_4in01F_test Demo\r\n");
	printf("e-Paper Init and Clear...\r\n");
	EPD_4IN01F_Init();
	EPD_4IN01F_Clear(EPD_4IN01F_WHITE);
	
#if 1 //Show array data
  EPD_4IN01F_Display_part(gImage_4in01f, 0, 0, 192, 143);
  DEV_Delay_ms(2000);
#endif

	printf("e-Paper Clear...\r\n");
	EPD_4IN01F_Clear(EPD_4IN01F_WHITE);

	printf("Sleep...\r\n");
	EPD_4IN01F_Sleep();
 
}

/* The main loop -------------------------------------------------------------*/
void loop()
{
  //
}
