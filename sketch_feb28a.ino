#include<SPI.h>                             //Library for SPI 

#define LED_RX 9
volatile uint8_t received;
volatile bool transmision = false;

void setup (void)
{

  Serial.begin(115200);
  pinMode(LED_RX,OUTPUT);
  pinMode(MISO, OUTPUT);
  pinMode(SS, INPUT);
  SPCR |= _BV(SPE);
  SPI.attachInterrupt();
}

ISR (SPI_STC_vect)
{
received = SPDR;
Serial.println("ISR");
}

void loop(void)
{
if(received>0)
{
  digitalWrite(LED_RX, HIGH);
}else{
  digitalWrite(LED_RX, LOW);}
}
