const int buzzer_pin = 0;
const int trig_pin = 1; //ultrasonic sensor
const int echo_pin = 2; //ultrasonic sensor
const int neopixel_pin = 3;
const int button_pin = 4;
const int pot_pin = A0;

int button_state = 0;
const int button_off = 0;
const int button_on = 1;

const int short_pause = 500;
const int medium_pause = 1500;
const int long_pause = 3000;

const int slow_speed = 70;
const int medium_speed = 135;
const int fast_speed = 200;
const int stop_speed = 0;

int motor_speed = 0;

void setup()
{
   Serial.begin(9600);
   
   pinMode(buzzer_pin, OUTPUT);
   pinMode(trig_pin, OUTPUT);
   pinMode(echo_pin, INPUT);
   pinMode(button_pin, INPUT);
   pinMode(pot_pin, INPUT);
}

int readButtonStatus()
{
  button_state = digitalRead(button_pin);
  if(button_state == LOW)
  {
     return button_off; 
  }
  else
  {
     return button_on; 
  }
}

int readMotorSpeed()
{
  int pot_val = analogRead(pot_pin);
  if(pot_val > 0 && pot_val <= 341)
  {
     motor_speed = slow_speed; 
  }
  else if(pot_val > 341 && pot_val <= 682)
  {
     motor_speed = medium_speed;
  }
  else if(pot_val > 682 && pot_val <= 1023)
  {
     motor_speed = fast_speed; 
  }
  else if(pot_val == 0)
  {
     motor_speed = stop_speed; 
  }
  return motor_speed;
}

void buzzerOn()
{
  tone(buzzer_pin, 4500);
}

void buzzerOff()
{
   noTone(buzzer_pin); 
}

void loop()
{
   Serial.println(readButtonStatus()); 
}
