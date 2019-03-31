#include "DataSet.h"
//#define row_count 16

/*void printScreenSaver(){
    float pi=atan(1)*4;
    int _count=1;
    int _tmp = tmp;
    tmp++;
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    while(row_count<_tmp){
        display.print(pi,row_count);
        _tmp-=row_count;
        display.setCursor(0,8*_count++);
        if(_count >= 9){break;}
    }
    display.println(pi,_tmp);
}*/

void window(){
    clearAll();
    if(checkTurningOnFlag(flag,0x08) && !checkTurningOnFlag(flag,0x0100) && !checkTurningOnFlag(flag,0x40)){
        turnOnFlag(&flag,0x0100);
        return;
    }
    if(checkTurningOnFlag(flag,0x0100)){
        printMenu();
    }
    else if(checkTurningOnFlag(flag,0x0200)){
        printMemo();
    }
    else{
        printClock();
    }
}