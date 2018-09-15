//char forwardKey =  'W'; // Key that makes the player go forward
//char backwardKey = 'S'; // Key that makes the player go backward
//char leftKey =     'A'; // Key that makes the player go left
//char rightKey =    'D'; // Key that makes the player go right

const int PIN_joystickX = A0;
const int PIN_joystickY = A1;
const int PIN_trigger = 8;
const int PIN_reload =  9;
const int PIN_special = 10;
const int PIN_jump =    11;

int joystickX_REST;
int joystickY_REST;
int joystickX;
int joystickY;
int joystickX_DISPLACEMENT;
int joystickY_DISPLACEMENT;
bool trigger_PRESSED;
bool jump_PRESSED;
bool reload_PRESSED;
bool special_PRESSED;

void setup() {
  Serial.begin(9600);

  joystickX_REST = analogRead(PIN_joystickX);
  joystickY_REST = analogRead(PIN_joystickY);

  pinMode(PIN_trigger, INPUT);
  pinMode(PIN_jump, INPUT);
  pinMode(PIN_reload, INPUT);
  pinMode(PIN_special, INPUT);
}

void loop() {
  joystickX = analogRead(PIN_joystickX);
  joystickY = analogRead(PIN_joystickY);
  trigger_PRESSED = digitalRead(PIN_trigger) == HIGH;
  jump_PRESSED    = digitalRead(PIN_jump)    == HIGH;
  reload_PRESSED  = digitalRead(PIN_reload)  == HIGH;
  special_PRESSED = digitalRead(PIN_special) == HIGH;

  joystickX_DISPLACEMENT = joystickX - joystickX_REST; // How far joystickX is from the center
  joystickY_DISPLACEMENT = joystickY - joystickY_REST; // How far joystickY is from the center

  if (joystickX_DISPLACEMENT > 100) { // Arbitrary number. Scale goes from 0 to 1023, with a rest at about 511, so your displacement can only be between -511 and 512.
    Serial.print("w");
  }
  if (joystickX_DISPLACEMENT < -100) { // Arbitrary number. Scale goes from 0 to 1023, with a rest at about 511, so your displacement can only be between -511 and 512.
    Serial.print("s");
  }
  if (joystickY_DISPLACEMENT > 100) { // Arbitrary number. Scale goes from 0 to 1023, with a rest at about 511, so your displacement can only be between -511 and 512.
    Serial.print("d");
  }
  if (joystickY_DISPLACEMENT < -100) { // Arbitrary number. Scale goes from 0 to 1023, with a rest at about 511, so your displacement can only be between -511 and 512.
    Serial.print("a");
  }
 if (trigger_PRESSED) {
    Serial.print("t");
 }
  
 if (jump_PRESSED) {//change to !jump_PRESSED
    Serial.print("i"); // Space wasn't working
 }
 
 if (reload_PRESSED) {
    Serial.print("r");
 }

 if (special_PRESSED) {
    Serial.print("q");
 }

  //ENTER();
//  delay(20);
}
