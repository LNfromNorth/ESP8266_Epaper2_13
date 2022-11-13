/* Includes ------------------------------------------------------------------*/
#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include "imagedata.h"
#include <stdlib.h>

UBYTE *BlackImage;

void Epaper_init(){
  printf("EPD_2IN13_test Demo\r\n");
  DEV_Module_Init();

  printf("e-Paper Init and Clear...\r\n");
  EPD_2IN13_Init(EPD_2IN13_FULL);
  EPD_2IN13_Clear();
  DEV_Delay_ms(500);

  //Create a new image cache
  /* you have to edit the startup_stm32fxxx.s file and set a big enough heap size */
  UWORD Imagesize = ((EPD_2IN13_WIDTH % 8 == 0) ? (EPD_2IN13_WIDTH / 8 ) : (EPD_2IN13_WIDTH / 8 + 1)) * EPD_2IN13_HEIGHT;
  if ((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
    printf("Failed to apply for black memory...\r\n");
    while (1);
  }
  printf("Paint_NewImage\r\n");
  Paint_NewImage(BlackImage, EPD_2IN13_WIDTH, EPD_2IN13_HEIGHT, 270, WHITE);
}

/* Entry point ----------------------------------------------------------------*/
void setup()
{
  Serial.begin(115200);
  Epaper_init();

#if 1   //show image for array    
  printf("show image for array\r\n");
  Paint_SelectImage(BlackImage);
  Paint_Clear(WHITE);
  Paint_DrawBitMap(gImage_2in13);

  EPD_2IN13_Display(BlackImage);
  DEV_Delay_ms(2000);
#endif
  EPD_2IN13_Sleep();
  free(BlackImage);
  BlackImage = NULL;
}



void parse(){

}
/* The main loop -------------------------------------------------------------*/
void loop()
{
  char *buf;
  Serial.readBytes(buf, 400);
  Serial.write(buf, 400);
}
