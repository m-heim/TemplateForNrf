#include <Arduino.h>
#include <stdint.h>
#include "config.hpp"
#include "RF24.h"


uint8_t payload[4] = {0};
uint8_t address[][5] = { "data" };

RF24 radio(CE_PIN, CSN_PIN);

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  if (!radio.begin()) {
    while (true) {
    }
  }
  radio.setPALevel(RF24_PA_LOW);
  radio.setPayloadSize(sizeof(payload));
  #ifdef SENDER
    radio.openReadingPipe(1, address[0]);
    radio.startListening();
  #endif

  #ifndef SENDER
    radio.openWritingPipe(address[0]);
    radio.stopListening();
  #endif
}

void loop() {
  // put your main code here, to run repeatedly:
}