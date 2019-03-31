#include "DataSet.h"


void printBattery(){
    digitalWrite(battEn, HIGH);
    delay(50);
    float voltage = analogRead(bPin);
    voltage = (voltage / 1024) * 3.35;
    voltage = voltage / ((R2 / (R1 + R2)));
    delay(50);
    digitalWrite(battEn, LOW);
    String str = "Battery Voltage: "+String(voltage);
    print(0,64-8,str);
}

void printTime(){
    now = rtc.now();
    String str = String(now.hour())+":"+String(now.minute())+"."+String(now.second());
    print(0,16,str);

    str = String(now.year()) + ". " + String(now.month()) + "/" + String(now.day()) + " ";
    for(int i=0;i < 3;i++){
        str += daysOfTheWeek[now.dayOfTheWeek()][i];
    }
    print(0,33,str);
}

void printCounter(){
    if(checkTurningOnFlag(flag,0x10)){
        if(checkTurningOnFlag(flag,0x80)){turnOffFlag(&flag,0x80);}
        else {turnOnFlag(&flag,0x80);tmp=0;}
    }
    if(checkTurningOnFlag(flag,0x80)){
        if(checkTurningOnFlag(flag,0x20)){tmp++;}
        String str = "Count: " + String(tmp);
        print(0,0,str);
    }
}

void printClock(){
    printBattery();
    printTime();
    printCounter();
}