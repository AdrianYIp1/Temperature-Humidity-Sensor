#include <DHT.h>
#include <LiquidCrystal.h>

#define Type DHT11

int sensePin = 2;
DHT mySensor(sensePin, Type);

LiquidCrystal lcd(12, 11, 5, 4, 3, 7);

float tempC;
float humidity;
int timeDelay = 5000;

void setup() {

Serial.begin(9600);
mySensor.begin();

lcd.begin(16, 2);
lcd.clear();

}

void loop() {

humidity = mySensor.readHumidity();
tempC = mySensor.readTemperature();

if (isnan(humidity) || isnan(tempC)) {
  Serial.println("Error measuring values from DHT sensor");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Error");
}
else {
  Serial.print("Temperature is: ");
  Serial.println(tempC);
  Serial.print("Humidity is: ");
  Serial.println(humidity);

  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print("Temperature: ");
  lcd.print(tempC, 1);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0, 1); 
  lcd.print("Humidity: ");
  lcd.print(humidity, 1);
  lcd.print("%");
}


delay(timeDelay);

}
  
