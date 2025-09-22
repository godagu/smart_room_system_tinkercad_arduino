// Author: Goda Gutparakyte
// HW1 for Intro To Robotics class at Vilnius University
// Smart room system - smoke detector + buzzer and LEDs, temperature sensor + fan (dc motor)
// Last updated: 2025-09-22

#define INPUT_SMOKE A0
#define INPUT_TEMPERATURE A1
#define OUTPUT_PIEZO 4
#define OUTPUT_RED_LED 7
#define OUTPUT_GREEN_LED 2
#define OUTPUT_FAN 9

#define GAS_LIMIT 100
#define TEMP_LIMIT 150

#define TUNE 523
#define RING_TIME 1000

#define DELAY_BLINK 200
#define DELAY_LOOP 10

int smoke = 0;

void setup()
{
  pinMode(INPUT_SMOKE, INPUT);
  pinMode(INPUT_TEMPERATURE, INPUT);

  pinMode(OUTPUT_PIEZO, OUTPUT);
  pinMode(OUTPUT_RED_LED, OUTPUT);
  pinMode(OUTPUT_GREEN_LED, OUTPUT);
  pinMode(OUTPUT_FAN, OUTPUT);
}

void loop()
{
  smoke = analogRead(INPUT_SMOKE);
  float temp = analogRead(INPUT_TEMPERATURE);
  
  if(smoke > GAS_LIMIT){
    digitalWrite(OUTPUT_GREEN_LED, LOW);
    
  	tone(OUTPUT_PIEZO, TUNE, RING_TIME);
    
    digitalWrite(OUTPUT_RED_LED, HIGH);
    delay(DELAY_BLINK);
    digitalWrite(OUTPUT_RED_LED, LOW);
    delay(DELAY_BLINK);
  }
  else{
  	digitalWrite(OUTPUT_GREEN_LED, HIGH);
  }
  
  if(temp > TEMP_LIMIT)
  	analogWrite(OUTPUT_FAN, HIGH);
  else{
  	analogWrite(OUTPUT_FAN, LOW);
  }
  
  delay(DELAY_LOOP);
  
}
