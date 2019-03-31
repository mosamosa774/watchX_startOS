#include "DataSet.h"

void resetButton(){
    turnOffFlag(&flag,0x08);
    turnOffFlag(&flag,0x10);
    turnOffFlag(&flag,0x20);
}

int checkTurningOnFlag(int flag, int bit){return !((flag & bit) == 0);}
void turnOnFlag(int *flag, int bit){*flag = *flag | bit;}
void turnOffFlag(int *flag, int bit){*flag = *flag & ~bit;}
