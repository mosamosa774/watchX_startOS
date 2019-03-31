#include "DataSet.h"
void buttonCheck(){
    if(!digitalRead(BUTTON1) && !checkTurningOnFlag(flag,0x01)){
        turnOnFlag(&flag,0x01);
        count = 0;
    }
    else if(digitalRead(BUTTON1) && checkTurningOnFlag(flag,0x01)){
        turnOffFlag(&flag,0x01);
        turnOnFlag(&flag,0x08);
        count = 0;
    }
    else if(!digitalRead(BUTTON2) && !checkTurningOnFlag(flag,0x02)){
        turnOnFlag(&flag,0x02);
        count = 0;
    }
    else if(digitalRead(BUTTON2) && checkTurningOnFlag(flag,0x02)){
        turnOffFlag(&flag,0x02);
        turnOnFlag(&flag,0x10);
        count = 0;
    }
    else if(!digitalRead(BUTTON3) && !checkTurningOnFlag(flag,0x04)){
        turnOnFlag(&flag,0x04);
        count = 0;
    }
    else if(digitalRead(BUTTON3) && checkTurningOnFlag(flag,0x04)){
        turnOffFlag(&flag,0x04);
        turnOnFlag(&flag,0x20);
        count = 0;
    }
}