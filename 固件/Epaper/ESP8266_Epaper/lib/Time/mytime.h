#ifndef __MYTIME_H
#define __MYTIME_H

// ----------------= include =-----------------
#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include <NTPclient.h>
#include <WiFiUdp.h>


void Time_init();
int time_handler();

#endif  /* __MYTIME_H */