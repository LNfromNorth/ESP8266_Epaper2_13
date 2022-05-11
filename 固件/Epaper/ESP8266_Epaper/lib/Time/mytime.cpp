#include "mytime.h"

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ntp.aliyun.com"); //NTP地址

char Time[6];
int Hour;
int Minite;
static int Second = 0;
int Week;
int Year;
int Month;
int Day;

UBYTE *BlackImage;

void Time_init()
{
	timeClient.begin();
  	printf("EPD_2IN13_test Demo\r\n");
  	DEV_Module_Init();
  	printf("e-Paper Init and Clear...\r\n");
 	 EPD_2IN13_Init(EPD_2IN13_FULL);
  	EPD_2IN13_Clear();
 	DEV_Delay_ms(500);
  	UWORD Imagesize = ((EPD_2IN13_WIDTH % 8 == 0) ? (EPD_2IN13_WIDTH / 8 ) : (EPD_2IN13_WIDTH / 8 + 1)) * EPD_2IN13_HEIGHT;
  	if ((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
    	printf("Failed to apply for black memory...\r\n");
    	while (1);
  	}
  	Paint_NewImage(BlackImage, EPD_2IN13_WIDTH, EPD_2IN13_HEIGHT, 270, WHITE);
}

void DrawDate(){
  #if 1   // Drawing on the image
  printf("Drawing\r\n");
  //1.Select Image
  Paint_SelectImage(BlackImage);
  Paint_Clear(WHITE);
  // Time
  Paint_DrawString_EN(25, 15, Time, &FontTime, WHITE, BLACK);
  // Week
  Paint_DrawPic(10,90,Week,&FontWeek,WHITE,BLACK);
  // Date
  Paint_DrawPic(82 ,90,2,&FontDateN,WHITE,BLACK);
  Paint_DrawPic(96 ,90,0 ,&FontDateN,WHITE,BLACK);
  Paint_DrawPic(112,90,2,&FontDateN,WHITE,BLACK);
  Paint_DrawPic(128,90,2 ,&FontDateN,WHITE,BLACK);
  Paint_DrawPic(144,90,10,&FontDateN,WHITE,BLACK);
  Paint_DrawPic(160,90,(int)Month/10,&FontDateN,WHITE,BLACK);
  Paint_DrawPic(176,90,(int)Month%10,&FontDateN,WHITE,BLACK);
  Paint_DrawPic(192,90,10,&FontDateN,WHITE,BLACK);
  Paint_DrawPic(208,90,(int)Day/10,&FontDateN,WHITE,BLACK);
  Paint_DrawPic(224,90,(int)Day%10,&FontDateN,WHITE,BLACK);
  EPD_2IN13_Display(BlackImage);
  DEV_Delay_ms(2000);
#endif
}


int getdata()
{
  timeClient.update();
  unsigned long epochTime = timeClient.getEpochTime();
  time_t mytime = epochTime;
	struct tm* timeinfo;
  timeinfo = localtime(&mytime);
	timeinfo->tm_hour+=8;
	// timeinfo->tm_hour = timeinfo->tm_hour>=24?(timeinfo->tm_hour-24):timeinfo->tm_hour;
  if(timeinfo->tm_hour >= 24)
  {
    timeinfo->tm_hour = timeinfo->tm_hour - 24;
    timeinfo->tm_mday++;
    timeinfo->tm_wday = timeinfo->tm_wday==6?0:timeinfo->tm_wday++;
  }
  else
    Hour = timeinfo->tm_hour;

  strftime(Time,sizeof(Time),"%H:%M",timeinfo);
  Serial.printf("%s\n",Time);
  Second =  timeinfo->tm_sec;
  Serial.printf("%d",Second);
  Serial.printf("%d\n",Hour);
  Minite = timeinfo->tm_min;
  Serial.printf("%d\n",Minite);
  Week = timeinfo->tm_wday;
  Serial.printf("%d\n",Week);
  Day = timeinfo->tm_mday;
  Serial.printf("%d\n",Day);
  Month = timeinfo->tm_mon + 1;
  Serial.printf("%d\n",Month);
  Year = timeinfo->tm_year;
  Serial.printf("%d\n",Year);
  return Second;
}

int time_handler()
{
  getdata();
  // if(Minite%5==0)
  DrawDate();
  return Second;
}