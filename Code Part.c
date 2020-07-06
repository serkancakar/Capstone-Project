#include <LiquidCrystal.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

//THIS PULSE VALUES OBTAINED FROM USING THE FIRST CODE

#define SERVOMIN  110 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMID  310 // This is the 'middle'  pulse length count (out of 4096)
#define SERVOMAX  510 // this is the 'maximum' pulse length count (out of 4096)


const int rs = 13, en = 12, d4 = A5 , d5 = A4, d6 = A3, d7 = A2;
LiquidCrystal lcd (13,12,A5,A4,A3,A2);
 

const int sensorPin0 = 0;
const int sensorPin1 = 1;
const int sensorPin2 = 2;
const int sensorPin3 = 3;
const int sensorPin4 = 4;
const int sensorPin5 = 5;
const int sensorPin6 = 6;
const int sensorPin7 = 7;
const int sensorPin8 = 8;

int sensorState0 = 0;
int sensorState1 = 0;
int sensorState2 = 0;
int sensorState3 = 0;
int sensorState4 = 0;
int sensorState5 = 0;
int sensorState6 = 0;
int sensorState7 = 0;
int sensorState8 = 0;

int I2C_condition = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("pca9685_TurnoutTest!");
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  Wire.begin(0x8);      // Join I2C bus with address 8
  Wire.onReceive(receiveEvent);
  lcd.begin(16,2);
  delay(50);


// WE DEFINE SERVO NUMBERS AND INITIAL POSITIONS OF THEM

  pwm.setPWM(0, 0, SERVOMID); // We define servoPin0
  pwm.setPWM(1, 0, SERVOMID); // We define servoPin1
  pwm.setPWM(2, 0, SERVOMID); // We define servoPin2
  pwm.setPWM(3, 0, SERVOMID); // We define servoPin3
  pwm.setPWM(4, 0, SERVOMID); // We define servoPin4  
  pwm.setPWM(5, 0, SERVOMID); // We define servoPin5
  pwm.setPWM(6, 0, SERVOMID); // We define servoPin6
  pwm.setPWM(7, 0, SERVOMID); // We define servoPin7  
  pwm.setPWM(8, 0, SERVOMID); // We define servoPin8
}



void loop() {

lcd.print("Hamle yapın:");

sensorState0 = digitalRead(sensorPin0); // Reading the sensorPin0's value.
  if (sensorState0 == HIGH) {           // Is sensorPin0's value is HIGH?
    pwm.setPWM(0, 0, SERVOMIN);         // If it is HIGH turn the servo motor to angle of 0.
  }
  else if(I2C_condition == 1){          // Checking if there is a signal from Raspberry Pi.
    lcd.print("Bekleyiniz");
    pwm.setPWM(0, 0, SERVOMAX);         // Turning servo motor to angle of 180.
    
  }

sensorState1 = digitalRead(sensorPin1); // Reading the sensorPin1's value.
  if(sensorState1 == HIGH) {            // Is sensorPin1's value is HIGH?
    pwm.setPWM(1, 0, SERVOMIN);         // If it is HIGH turn the servo motor to angle of 180.
  }
  else if(I2C_condition == 1){          // Checking if there is a signal from Raspberry Pi.
    lcd.print("Bekleyiniz");
    pwm.setPWM(1, 0, SERVOMAX);         // Turning servo motor to angle of 180.  
    
  }

sensorState2 = digitalRead(sensorPin2);
  if(sensorState2 == HIGH) {
    pwm.setPWM(2, 0, SERVOMIN);
  }
  else if(I2C_condition == 1){
    lcd.print("Bekleyiniz");
    pwm.setPWM(2, 0, SERVOMAX);  
    
  }


 sensorState3= digitalRead(sensorPin3);
  if(sensorState3 == HIGH) {
    pwm.setPWM(3, 0, SERVOMIN);
  }
  else if(I2C_condition == 1){
    lcd.print("Bekleyiniz");
    pwm.setPWM(3, 0, SERVOMAX);  
    
  }

sensorState4 = digitalRead(sensorPin4);
  if(sensorState4 == HIGH) {
    pwm.setPWM(4, 0, SERVOMIN);
  }
  else if(I2C_condition == 1){
    lcd.print("Bekleyiniz");
    pwm.setPWM(4, 0, SERVOMAX);  
    
  }

sensorState5 = digitalRead(sensorPin5);
  if(sensorState5 == HIGH) {
    pwm.setPWM(5, 0, SERVOMIN);
  }
  else if(I2C_condition == 1){
    lcd.print("Bekleyiniz");
    pwm.setPWM(5, 0, SERVOMAX);  
    
  }

 sensorState6 = digitalRead(sensorPin6);
  if(sensorState6 == HIGH) {
    pwm.setPWM(6, 0, SERVOMIN);
  }
 else if(I2C_condition == 1){
    lcd.print("Bekleyiniz");
    pwm.setPWM(6, 0, SERVOMAX);  
    
  }

 sensorState7 = digitalRead(sensorPin7);
  if(sensorState7 == HIGH) {
    pwm.setPWM(7, 0, SERVOMIN);
  }

  else if(I2C_condition == 1){
    lcd.print("Bekleyiniz");
    pwm.setPWM(7, 0, SERVOMAX);  
    
  }

 sensorState8 = digitalRead(sensorPin8);
  if(sensorState8 == HIGH) {
    pwm.setPWM(8, 0, SERVOMIN);     
            
   }

   else if(I2C_condition == 1){
    lcd.print("Bekleyiniz");
    pwm.setPWM(8, 0, SERVOMAX);  
    
  }

lcd.print("Oyun bitti.");

}

void receiveEvent(int howMany){   // This is the Arduino - Rasp. Pi connection. (If it was used.)
  while(Wire.available()){
    char I2C_condition = Wire.read();
    }
  }
