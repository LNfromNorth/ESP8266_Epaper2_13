/* Includes ------------------------------------------------------------------*/
#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include "imagedata.h"
#include <stdlib.h>

/* Entry point ----------------------------------------------------------------*/
void setup()
{
  printf("EPD_7IN5BC_test Demo\r\n");
  DEV_Module_Init();

  printf("e-Paper Init and Clear...\r\n");
  EPD_7IN5BC_Init();
  EPD_7IN5BC_Clear();
  //  DEV_Delay_ms(500);

#if 0   // Not enough memory, not recommended
  printf("show image for array\r\n");
  EPD_7IN5BC_Display(gImage_7in5bc_b, gImage_7in5bc_ry);
  DEV_Delay_ms(2000);
#endif

#if 1   // Drawing on the image
  //Create a new image cache named IMAGE_BW and fill it with white
  UBYTE *BlackImage, *RYImage;
  UWORD Imagesize = ((EPD_7IN5BC_WIDTH % 8 == 0) ? (EPD_7IN5BC_WIDTH / 8 ) : (EPD_7IN5BC_WIDTH / 8)) * EPD_7IN5BC_HEIGHT;
  if ((BlackImage = (UBYTE *)malloc(Imagesize / 4)) == NULL) {
    printf("Failed to apply for black memory...\r\n");
  }
  if ((RYImage = (UBYTE *)malloc(Imagesize / 4)) == NULL) {
    printf("Failed to apply for red memory...\r\n");
  }
  printf("NewImage:BlackImage and RYImage\r\n");
  Paint_NewImage(BlackImage, EPD_7IN5BC_WIDTH, EPD_7IN5BC_HEIGHT / 4, 0, WHITE);
  Paint_NewImage(RYImage, EPD_7IN5BC_WIDTH, EPD_7IN5BC_HEIGHT / 4, 0, WHITE);

  //Select Image
  Paint_SelectImage(BlackImage);
  Paint_Clear(WHITE);
  Paint_SelectImage(RYImage);
  Paint_Clear(WHITE);

  /*Horizontal screen*/
  //1.Draw black image
  Paint_SelectImage(BlackImage);
  Paint_Clear(WHITE);
  Paint_DrawString_EN(10, 0, "waveshare", &Font16, BLACK, WHITE);
  Paint_DrawString_CN(130, 20, "微雪电子", &Font24CN, WHITE, BLACK);
  Paint_DrawNum(10, 50, 987654321, &Font16, WHITE, BLACK);
  Paint_DrawPoint(620, 10, BLACK, DOT_PIXEL_1X1, DOT_STYLE_DFT);
  Paint_DrawPoint(620, 20, BLACK, DOT_PIXEL_2X2, DOT_STYLE_DFT);
  Paint_DrawPoint(620, 30, BLACK, DOT_PIXEL_3X3, DOT_STYLE_DFT);
  Paint_DrawPoint(620, 40, BLACK, DOT_PIXEL_3X3, DOT_STYLE_DFT);
  Paint_DrawLine(300, 20, 360, 80, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
  Paint_DrawLine(360, 20, 300, 80, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
  Paint_DrawRectangle(300, 20, 360, 80, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
  Paint_DrawRectangle(400, 20, 460, 80, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);

  //2.Draw red image
  Paint_SelectImage(RYImage);
  Paint_Clear(WHITE);
  Paint_DrawString_CN(130, 0, "你好abc", &Font12CN, BLACK, WHITE);
  Paint_DrawString_EN(10, 20, "hello world", &Font12, WHITE, BLACK);
  Paint_DrawNum(10, 33, 123456789, &Font12, BLACK, WHITE);
  Paint_DrawCircle(550, 50, 30, BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
  Paint_DrawCircle(550, 50, 20, BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
  Paint_DrawLine(430, 20, 430, 80, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
  Paint_DrawLine(400, 50, 460, 50, BLACK, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);

  printf("EPD_Display\r\n");
  EPD_7IN5BC_SendHalfHalfScreen(0, BlackImage, RYImage);
  EPD_7IN5BC_SendHalfHalfScreen(1, BlackImage, RYImage);
  EPD_7IN5BC_SendHalfHalfScreen(2, BlackImage, RYImage);
  EPD_7IN5BC_SendHalfHalfScreen(3, BlackImage, RYImage);
  EPD_7IN5BC_TurnOnDisplay();
  //DEV_Delay_ms(2000);

  free(BlackImage);
  free(RYImage);
  BlackImage = NULL;
  RYImage = NULL;
#endif

  printf("Clear...\r\n");
  EPD_7IN5BC_Clear();

  printf("Goto Sleep...\r\n");
  EPD_7IN5BC_Sleep();
}

/* The main loop -------------------------------------------------------------*/
void loop()
{
  //
}
