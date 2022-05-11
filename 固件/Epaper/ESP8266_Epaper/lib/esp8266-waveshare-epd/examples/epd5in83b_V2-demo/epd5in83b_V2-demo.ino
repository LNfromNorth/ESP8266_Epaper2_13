/* Includes ------------------------------------------------------------------*/
#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include "imagedata.h"
#include <stdlib.h>

//esp8266 cannot have too long delay, it is easy to trigger software watchdog
/* Entry point ----------------------------------------------------------------*/
void setup()
{
  printf("EPD_5IN83BC_test Demo\r\n");
  DEV_Module_Init();

  printf("e-Paper Init and Clear...\r\n");
  EPD_5IN83B_V2_Init();
  EPD_5IN83B_V2_Clear();

#if 1   // Not enough memory, not recommended
  printf("show image for array\r\n");
  EPD_5IN83B_V2_Display(gImage_5in83b_V2_b, gImage_5in83b_V2_r);
  DEV_Delay_ms(2000);
#endif

#if 1   // Drawing on the image 648*480
  //Create a new image cache named IMAGE_BW and fill it with white
  UBYTE *BlackImage, *RYImage;
  UWORD Imagesize = ((EPD_5IN83B_V2_WIDTH % 8 == 0) ? (EPD_5IN83B_V2_WIDTH / 8 ) : (EPD_5IN83B_V2_WIDTH / 8 + 1)) * EPD_5IN83B_V2_HEIGHT;
  if ((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
    printf("Failed to apply for black memory...\r\n");
    while (1);
  }

  printf("NewImage:BlackImage and RYImage\r\n");
  Paint_NewImage(BlackImage, EPD_5IN83B_V2_WIDTH, EPD_5IN83B_V2_HEIGHT, 0, WHITE);

  //Select Image
  Paint_SelectImage(BlackImage);
  Paint_Clear(WHITE);

  /*Horizontal screen*/
  //1.Draw black image
  Paint_SelectImage(BlackImage);
  Paint_Clear(WHITE);
  Paint_DrawPoint(580, 50, BLACK, DOT_PIXEL_1X1, DOT_STYLE_DFT);
  Paint_DrawPoint(580, 60, BLACK, DOT_PIXEL_2X2, DOT_STYLE_DFT);
  Paint_DrawPoint(580, 70, BLACK, DOT_PIXEL_3X3, DOT_STYLE_DFT);
  Paint_DrawPoint(580, 80, BLACK, DOT_PIXEL_3X3, DOT_STYLE_DFT);
  Paint_DrawLine(300, 20, 360, 80, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
  Paint_DrawLine(360, 20, 300, 80, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
  Paint_DrawRectangle(300, 20, 360, 80, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
  Paint_DrawRectangle(400, 20, 460, 80, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
  Paint_DrawString_EN(10, 20, "waveshare", &Font16, BLACK, WHITE);
  Paint_DrawString_CN(130, 40, "微雪电子", &Font24CN, WHITE, BLACK);
  Paint_DrawNum(10, 70, 987654321, &Font16, WHITE, BLACK);
  EPD_5IN83B_V2_SendHalfHalfScreen(0, BlackImage);
  
  //2.Draw red image
  Paint_SelectImage(BlackImage);
  Paint_Clear(WHITE);
  Paint_DrawCircle(530, 50, 30, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
  Paint_DrawCircle(530, 50, 20, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
  Paint_DrawLine(330, 20, 330, 80, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
  Paint_DrawLine(300, 50, 360, 50, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
  Paint_DrawString_CN(130, 20, "你好abc", &Font12CN, BLACK, WHITE);
  Paint_DrawString_EN(10, 43, "hello world", &Font12, WHITE, BLACK);
  Paint_DrawNum(10, 55, 123456789, &Font12, BLACK, WHITE);
  printf("EPD_Display\r\n");
  EPD_5IN83B_V2_SendHalfHalfScreen(1, BlackImage);
  
  free(BlackImage);
  BlackImage = NULL;
#endif

  printf("Clear...\r\n");
  EPD_5IN83B_V2_Clear();

  printf("Goto Sleep...\r\n");
  EPD_5IN83B_V2_Sleep();
}

/* The main loop -------------------------------------------------------------*/
void loop()
{

}
