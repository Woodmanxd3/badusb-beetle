#include <Keyboard.h>
#include <KeyboardLayout.h>
#include <Keyboard_da_DK.h>
#include <Keyboard_de_DE.h>
#include <Keyboard_es_ES.h>
#include <Keyboard_fr_FR.h>
#include <Keyboard_hu_HU.h>
#include <Keyboard_it_IT.h>
#include <Keyboard_pt_PT.h>
#include <Keyboard_sv_SE.h>

void setup() {
  // put your setup code here, to run once:
delay(3000);
Keyboard.begin();
//Press the windows key
Keyboard.press(KEY_LEFT_GUI);
Keyboard.releaseAll();
delay(1000);
Keyboard.print("n");
delay(300);
Keyboard.print("o");
delay(100);
Keyboard.print("t");
delay(100);
Keyboard.print("e");
delay(300);
Keyboard.press(KEY_RETURN);
Keyboard.releaseAll();
delay(1000);
Keyboard.print("Pay");
delay(50);
Keyboard.print("load ");
delay(100);
Keyboard.print("Succ");
delay(50);
Keyboard.print("eeded!");
//Stop emulating the keyboard
Keyboard.releaseAll();
Keyboard.end();
}

void loop() {
  // put your main code here, to run repeatedly:

}
