#include <SPI.h>
#include <english.h>
#include <oled.h>
#include <resources.h>
#include <EnableInterrupt.h>
#include <avr/sleep.h>
#include "RTClib.h"

#define BUZZER 9
#define OLED_DC     A3
#define OLED_CS     A5
#define OLED_RESET  A4
#define BUTTON1 8 // PullUp
#define BUTTON2 11 // PullUp
#define BUTTON3 10 // PullUp
#define MenuLength 3
extern RTC_DS3231 rtc;
extern byte bPin;
extern byte battEn;
extern int count;//index
extern DateTime now;
extern char* menu_item[];
extern char daysOfTheWeek[7][3];
extern float R1;
extern float R2;
extern int flag;
extern int tmp;
extern int tmp2;
extern char keys[40];
extern String memo[4];

void print(int x, int y, String str);