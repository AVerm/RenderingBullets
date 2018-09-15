const int PIN_trigger = 8;
const int PIN_jump =    9;
const int PIN_reload =  10;
const int PIN_special = 11;

bool trigger_PRESSED;
bool jump_PRESSED;
bool reload_PRESSED;
bool special_PRESSED;

void setup() {
  Serial.begin(9600);

  pinMode(PIN_trigger, INPUT);
  pinMode(PIN_jump, INPUT);
  pinMode(PIN_reload, INPUT);
  pinMode(PIN_special, INPUT);
  
  
}

void loop() {

 trigger_PRESSED = digitalRead(PIN_trigger) == HIGH;
 jump_PRESSED    = digitalRead(PIN_jump)    == HIGH;
 reload_PRESSED  = digitalRead(PIN_reload)  == HIGH;
 special_PRESSED = digitalRead(PIN_special) == HIGH;

 if (trigger_PRESSED) {
    Serial.print("trigger ");
 }
  
 if (jump_PRESSED) {//change to !jump_PRESSED
    Serial.print("jump ");
 }
 
 if (reload_PRESSED) {
    Serial.print("reload ");
 }

 if (special_PRESSED) {
    Serial.print("special ");
 }

  Serial.println();
 
 delay(1000);

}
