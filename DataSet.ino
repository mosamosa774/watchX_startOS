#include "DataSet.h"
RTC_DS3231 rtc;
byte bPin = A11; // maybe require static
byte battEn = 4; // maybe require static
int interruptCount=0;
int count=0;
DateTime now;
char* menu_item[] = {"Clock","Memo","Sleep"};
char daysOfTheWeek[7][3] = { 
    {'S','u','n'},
    {'M','o','n'},
    {'T','u','e'},
    {'W','e','d'},
    {'T','h','u'},
    {'F','r','i'},
    {'S','a','t'}
};
int tmp=0;//index
int tmp2=0;
float R1 = 10000;
float R2 = 10000;
int flag=0;
int window_flag=0;
char keys[40] = {
    '1','2','3','4','5','6','7','8','9','0',
    'q','w','e','r','t','y','u','i','o','p',
    'a','s','d','f','g','h','j','k','l','B',
    'z','x','c','v','b','n','m',' ',':','E'
};
String memo[4] = {"","","",""};

void print(int x, int y, String str){
    char buf[40];
    int len=str.length();
    str.toCharArray(buf,len+1); 
    drawString(x, y, buf,smallFont);
}
void print2X(int x, int y, String str){
    char buf[40];
    int len=str.length();
    str.toCharArray(buf,len+1); 
    drawString_P(x, y, buf,smallFont);
}