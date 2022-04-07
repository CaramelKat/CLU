/**
 * CLU - Codified Likeness Utility 1.04
 * Script to force the following actions
 * after imaging a machine
 * - Windows Updates fetch and download
 * - Group Policy updates
 * - Running all config manager actions
 * - Open Software Center
 */
#include "DigiKeyboard.h"
// Keys not included in library
#define KEY_TAB 0x2B
#define KEY_RIGHT 0x4F
#define KEY_DOWN 0x51
#define KEY_UP 0x52
// System variables
#define ACTION_DELAY 150
#define INPUT_DELAY 500
#define ACTIONS 11
#define POLICY_WAIT_TIME 30000
#define END_PROGRAM_NAME "Software Center"
void setup() {}
void printToPrompt(String input) {
 DigiKeyboard.delay(INPUT_DELAY);
 DigiKeyboard.print(input);
 DigiKeyboard.sendKeyStroke(KEY_ENTER);
 }
void loop() {
 // gpupdate
 DigiKeyboard.sendKeyStroke(0);
 DigiKeyboard.delay(INPUT_DELAY);
 DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
 DigiKeyboard.delay(INPUT_DELAY);
 DigiKeyboard.print("cmd");
 DigiKeyboard.sendKeyStroke(KEY_ENTER);
 // check updates
 printToPrompt("wuauclt /detectnow");
 // update now
 printToPrompt("wuauclt /updatenow");
 // group policy update 
 printToPrompt("gpupdate /force");
 // exit cmd
 printToPrompt("exit");
 // wait for group policy update
 DigiKeyboard.delay(POLICY_WAIT_TIME);
 // open configuration manager
 // go to desktop
 DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
 DigiKeyboard.delay(INPUT_DELAY);
 // run
 DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
 DigiKeyboard.delay(INPUT_DELAY * 2);
 DigiKeyboard.print("control smscfgrc");
 DigiKeyboard.sendKeyStroke(KEY_ENTER);
 DigiKeyboard.delay(INPUT_DELAY * 3);
 // move to action tab
 DigiKeyboard.sendKeyStroke(KEY_TAB, MOD_SHIFT_LEFT);
 DigiKeyboard.sendKeyStroke(KEY_RIGHT);
 DigiKeyboard.sendKeyStroke(KEY_RIGHT);
 DigiKeyboard.sendKeyStroke(KEY_TAB);
 DigiKeyboard.sendKeyStroke(KEY_DOWN);
 DigiKeyboard.delay(INPUT_DELAY);
 // execute action loop
 for(int i = 0; i < ACTIONS; i++) {
  DigiKeyboard.sendKeyStroke(KEY_TAB);
  DigiKeyboard.delay(ACTION_DELAY);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(ACTION_DELAY);
  DigiKeyboard.sendKeyStroke(KEY_ENTER); 
  DigiKeyboard.delay(ACTION_DELAY);
  DigiKeyboard.sendKeyStroke(KEY_TAB, MOD_SHIFT_LEFT);
  DigiKeyboard.delay(ACTION_DELAY);
  DigiKeyboard.sendKeyStroke(KEY_DOWN);
 }
 // close window
 DigiKeyboard.sendKeyStroke(KEY_TAB);
 DigiKeyboard.sendKeyStroke(KEY_TAB);
 DigiKeyboard.sendKeyStroke(KEY_ENTER);
// open software center!
 DigiKeyboard.delay(INPUT_DELAY * 2);
 DigiKeyboard.sendKeyStroke(KEY_S, MOD_GUI_LEFT);
 DigiKeyboard.delay(INPUT_DELAY);
 DigiKeyboard.print(END_PROGRAM_NAME);
 DigiKeyboard.delay(INPUT_DELAY * 2);
 DigiKeyboard.sendKeyStroke(KEY_ENTER);
// open windows update
 DigiKeyboard.sendKeyStroke(0);
 DigiKeyboard.delay(INPUT_DELAY);
 DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
 DigiKeyboard.delay(INPUT_DELAY);
 DigiKeyboard.print("control update");
 DigiKeyboard.sendKeyStroke(KEY_ENTER);
 DigiKeyboard.delay(4000);
 DigiKeyboard.sendKeyStroke(KEY_TAB);
 DigiKeyboard.sendKeyStroke(KEY_TAB);
 DigiKeyboard.sendKeyStroke(KEY_TAB);
 DigiKeyboard.sendKeyStroke(KEY_TAB);
 DigiKeyboard.sendKeyStroke(KEY_ENTER);
 for (;;) {/*empty*/}
}
