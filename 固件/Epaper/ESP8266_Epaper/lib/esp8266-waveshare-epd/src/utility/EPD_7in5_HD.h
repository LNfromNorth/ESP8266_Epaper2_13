#ifndef EPD7IN5_HD_H
#define EPD7IN5_HD_H

#include "DEV_Config.h"

// Display resolution
#define EPD_7IN5_HD_WIDTH       880
#define EPD_7IN5_HD_HEIGHT      528


void EPD_7IN5_HD_Init(void);
void EPD_7IN5_HD_Clear(void);
void EPD_7IN5_HD_Display(const UBYTE *blackimage);
void EPD_7IN5_HD_Display_half(const UBYTE *blackimage, UBYTE part);
void EPD_7IN5_HD_Sleep(void);
void EPD_7IN5_HD_Displaypart(const unsigned char* pbuffer, unsigned long xStart,         unsigned long yStart,\
                      unsigned long Picture_Width,  unsigned long Picture_Height);


#endif /* EPD7IN5_H */

