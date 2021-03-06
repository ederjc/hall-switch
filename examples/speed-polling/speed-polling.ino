#include <Arduino.h>
#include <stdint.h>
#include <hall-speed-ino.hpp>

/**
 * Plug & Play hw platform --> TLE4922 Speed Sensor 2GoKit Output Pin
 */

#define Q_OUTPUT_PIN    1   /**< TLE4922 2GoKit Output Pin  */
#define VDD_PIN         0   /**< TLE4922 2GoKit VDD Pin */

HallSpeedIno         hs(Q_OUTPUT_PIN, 1, HallSpeed::RPM, NULL, VDD_PIN);   /**< Hall Speed object */
double               speed = 0.0;                         

/**
 * @brief       Prints the sensor data in JSON format 
 * @param[in]   speed Speed value
 */
void JSONPrint(double speed)
{
  Serial.print("{ \"speed\" : ");
  Serial.print(speed);
  Serial.println(" }");
}

void setup()
{      
  int err = 0;

  delay(1000);

  Serial.begin(115200);
  Serial.println("Serial initialized");

  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("LED1 Initialized");

  err = hs.begin();
  if(0 > err ){ Serial.print("Hall Speed error");}

  Serial.println("Hall Speed started");

  JSONPrint(speed);
}

double curSpeed = speed;

void loop()
{ 
  curSpeed = hs.getSpeed();

  /** Only update LED and data when speed changes */
  if (curSpeed != speed)
  {
    speed = curSpeed;
  
    digitalWrite(LED_BUILTIN, HIGH);
  
    JSONPrint(speed); 
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }  
}

