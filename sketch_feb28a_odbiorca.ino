#include <SPI.h>
#define SS_PIN 10
#define LED_PIN 13

void setup (void)
{
  Serial.begin(115200);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
  pinMode(SS_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(SS_PIN, HIGH);
}

void loop (void)
{
  digitalWrite(SS_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
  SPI.transfer(0xF);
  delay(1000);
  SPI.transfer(0);
  digitalWrite(SS_PIN,HIGH);
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
}
