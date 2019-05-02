const int PIN_LED_GREEN = 11;
const int PIN_LED_YELLOW = 12;
const int PIN_LED_RED = 10;

const int PIN_CABLE_FIRST = 2;
const int PIN_CABLE_SECOND = 3;
const int PIN_BTN_HOME = 4;

void disable_leds(){
  digitalWrite(PIN_LED_GREEN,   LOW);
  digitalWrite(PIN_LED_RED,     LOW);
  digitalWrite(PIN_LED_YELLOW,  LOW);
  }

void test_leds() {
  digitalWrite(PIN_LED_GREEN, HIGH);
  delay(200);
  digitalWrite(PIN_LED_YELLOW, HIGH);
  delay(200);
  digitalWrite(PIN_LED_RED, HIGH);
  delay(200);
  disable_leds();
  delay(400);
}

void disable_all_leds(){
      digitalWrite(PIN_LED_GREEN,   LOW);
      digitalWrite(PIN_LED_RED,     LOW);
      digitalWrite(PIN_LED_YELLOW,  LOW);
  }

void handle_cables(){
   disable_all_leds();
   if (!digitalRead(PIN_CABLE_FIRST) && !digitalRead(PIN_CABLE_SECOND)){
      digitalWrite(PIN_LED_GREEN, HIGH);
    } else if (!digitalRead(PIN_CABLE_FIRST) || !digitalRead(PIN_CABLE_SECOND)){
      digitalWrite(PIN_LED_YELLOW, HIGH);     
    } else {
      digitalWrite(PIN_LED_RED, HIGH);       
    }
}

bool are_both_cables_connected(){
  return (!digitalRead(PIN_CABLE_FIRST)) && (!digitalRead(PIN_CABLE_SECOND));
  }


void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED_GREEN,  OUTPUT);
  pinMode(PIN_LED_RED,    OUTPUT);
  pinMode(PIN_LED_YELLOW, OUTPUT);
  
  pinMode(PIN_CABLE_FIRST, INPUT);
  digitalWrite(PIN_CABLE_FIRST, HIGH);

  pinMode(PIN_CABLE_SECOND, INPUT);
  digitalWrite(PIN_CABLE_SECOND, HIGH);

  pinMode(PIN_BTN_HOME, INPUT);
  digitalWrite(PIN_BTN_HOME, HIGH);
 
  Serial.begin(9600);

}


void loop() {
  // put your main code here, to run repeatedly:
  handle_cables();
  if (are_both_cables_connected()){
    if (!digitalRead(PIN_BTN_HOME)) {
        test_leds();
        Serial.write("play\n");
    }
  } else {
    handle_cables();
    }
  delay(100);
}
