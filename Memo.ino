#include "DataSet.h"

void keyBoard(int index){
    if(checkTurningOnFlag(flag,0x08)){
        if(tmp2 == 39){tmp2=0;turnOffFlag(&flag,0x80);return;}
        else if(tmp2 == 29){
            String swap = "";
            for(int i=0;i < memo[index].length()-1;i++){swap+=memo[index].charAt(i);}
            memo[index]=swap;
        }
        else {memo[index] += keys[tmp2];}
    }
    else if(checkTurningOnFlag(flag,0x10)){tmp2++;if(tmp2%10 == 0 && tmp2!=0){tmp2-=10;}}
    else if(checkTurningOnFlag(flag,0x20)){tmp2+=10;if(tmp2>39){tmp2=tmp2%10;}}

    print(0,0,memo[index]);
    delay(50);
    String str;
    for(int i=0;i<4;i++){
        str="";
        for(int j=0;j<10;j++){
            str += keys[i*10+j];
        }
        print(0,8+8*i+1,str);
    }
    drawLine(5*(tmp2%10)+1*((tmp2%10)!=0), 16+8*(int)(tmp2/10), 5+5*(tmp2%10)+1*((tmp2%10)!=0), 16+8*(int)(tmp2/10));
    delay(50);
}

void printMemo(){
    turnOnFlag(&flag,0x40);
    if(checkTurningOnFlag(flag,0x80)){
        if(tmp==4){turnOffFlag(&flag,0x40);turnOnFlag(&flag,0x0100);}
        else{keyBoard(tmp);return;}
    }
    if(checkTurningOnFlag(flag,0x10)){tmp--;}
    else if(checkTurningOnFlag(flag,0x20)){tmp++;}    
    else if(checkTurningOnFlag(flag,0x08)){
        if(memo[tmp].equals("")){turnOnFlag(&flag,0x80);return;}
        else{memo[tmp]="";}
    }
    if(tmp < 0){tmp = 4;}
    else if(tmp > 4){tmp = 0;}
    delay(50);
    String str;
    print(0,8*tmp,String(">"));  
    for(int i=0;i < 4;i++){
        str = " " + memo[i];
        print(0,8*i+1*(i!=0),str);        
    }
    str = " Return";
    print(0,8*4+1,str);
    delay(50);
}
