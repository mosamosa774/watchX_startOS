#include "DataSet.h"

void printMenu(){
    if(checkTurningOnFlag(flag,0x08)){
        flag=0;
        if(tmp == 1){tmp=0;turnOnFlag(&flag,0x0200);}
        else if(tmp == 2){
            tmp=0;
            prepareSleep();
        }
        return;
    }
    else if(checkTurningOnFlag(flag,0x10)){tmp--;}
    else if(checkTurningOnFlag(flag,0x20)){tmp++;}

    if(tmp >= MenuLength){tmp = 0;}
    else if(tmp < 0){tmp = MenuLength-1;}
    
    delay(50);
    String str;
    for(int i=0;i < MenuLength;i++){
        if(i == tmp){str = ">";}
        else {str = " ";}
        str += menu_item[i];
        print(0, 8*i+1*(i!=0), str.c_str());
    }
    delay(50);
}