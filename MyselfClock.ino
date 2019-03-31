#include "DataSet.h"

//脱！既存の表示用ライブラリ！（重いんじゃあ～～～）
//懸念:表示速度は1loopの速さに耐えられるのでしょうか？
//例のページのプログラムコードを参照しましょう。多分がっつり、フラッシュメモリーの30%程は削れると見たね！私は

//後、aruduinoにおける、データのセーブ方法もちょっと調べてみましょう、メモ消えるのめんどい

//android側はまず、平凡なサンプル（コピペ、もしくは模倣の意をさす）でbluetooth通信試すよ！
//その後ぉ、flutterを試してみましょー

void interruptFunction() {
    turnOffFlag(&flag,0x40);
    ssd1306_sendCommand(SSD1306_DISPLAYON);
}
void setup() {
    rtc.begin();
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    pinMode(BUTTON1, INPUT_PULLUP);
    pinMode(BUTTON2, INPUT_PULLUP);
    pinMode(BUTTON3, INPUT_PULLUP);
    SPI.begin();
    ssd1306_configure();
    // turn off accelerometer
    //mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G);
    //mpu.setSleepEnabled(true);
}
bool IsUSBConnected(){
    return(UDADDR & _BV(ADDEN));
}
void sleepNow(){
    clearAll();
    ssd1306_sendCommand(SSD1306_DISPLAYOFF);
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    enableInterrupt(BUTTON3, interruptFunction, CHANGE);
    sleep_mode();
    sleep_disable();
    disableInterrupt(BUTTON3);
}
void prepareSleep(){
    delay(500);
    count = 0;
    flag = 0;
    turnOnFlag(&flag,0x40);
    sleepNow();
}
void loop(){
    buttonCheck();
    window();
    if(!IsUSBConnected() && count >= 900) {
        prepareSleep();
    }
    resetButton();
    count++;
    count = count % 1000;
    ssd1306_drawBuffer(0, 0, s_displayWidth,s_displayHeight, mbuf);
}