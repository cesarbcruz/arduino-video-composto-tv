#include <PS2Keyboard.h>
#include <TVout.h>
#include <fontALL.h>


const int ClockPin =  3; 
const int DataPin = 4; 
PS2Keyboard keyboard;

TVout TV;

void setup() {
  delay(1000);
  keyboard.begin(DataPin, ClockPin);
  delay(1000);
  TV.begin(_NTSC, 184, 72);
  TV.select_font(font6x8);
  delay(1000);
  TV.println("Unicamp Mecatronica");
  TV.println("-------------------");
}

void loop() {
  if (keyboard.available()) {
    char c = keyboard.read();
    if (c == PS2_ENTER) {
      TV.println();
    } else {
      TV.print(c);
    }  
  }  
}








