#include <Arduino.h>

#if USE_COUT
#include <ArduinoSTL.h>
#endif // USE_COUT

#if USE_DEBUGGER
#include <app_api.h> // only needed with flash breakpoints
#include <avr8-stub.h>
#endif // USE_DEBUGGER

#define PERIOD 1000

void setup() {
// put your setup code here, to run once:
#if USE_SERIAL
  Serial.begin(MONITOR_SPEED);
  Serial.println("setup() (Serial)");
#endif // USE_SERIAL

#if USE_COUT
  Serial.begin(MONITOR_SPEED);
  std::cout << "setup() (cout)" << std::endl;
#endif // USE_COUT

#if USE_DEBUGGER
  // initialize GDB stub
  debug_init();
#endif // USE_DEBUGGER

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
// put your main code here, to run repeatedly:
#if USE_SERIAL
  Serial.println("loop() (serial)");
#elif USE_COUT
  std::cout << "loop() (cout)" << std::endl;
#endif // USE_SERIAL

  digitalWrite(LED_BUILTIN,
               HIGH);             // turn the LED on (HIGH is the voltage level)
  delay(PERIOD);                  // wait for a second
  digitalWrite(LED_BUILTIN, LOW); // turn the LED off by making the voltage LOW
  delay(PERIOD);                  // wait for a second
}