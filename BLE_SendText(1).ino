#include <BluetoothSerial.h>
BluetoothSerial BT;
int LED = 12;
char LEDstatus;

void setup()
{
 Serial.begin(115200);
 BT.begin("rrrr"); // 設定和 HC-06 通訊的速度 (預設 9600)
 pinMode(LED, OUTPUT);  
}
void loop()
{
 //讀取藍芽模組訊息，並傳送到電腦
 if (BT.available()){
    LEDstatus=BT.read();
    Serial.println(LEDstatus);  
 }
 //判斷LED開關條件
 switch (LEDstatus){ 
  case 'a':
  digitalWrite(LED,HIGH);
  break;
  case 'b':
  digitalWrite(LED,LOW);
  break;
  }
}
