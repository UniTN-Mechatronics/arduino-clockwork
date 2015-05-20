#include <clockwork.h>

Clockwork cw(1000);

void setup() {
  Serial.begin(9600);
}

void loop() {
  cw.start();
  delay(400);
  Serial.print("tet=");
  Serial.print(cw.tet());
  Serial.print(" delay=");
  Serial.print(cw.last_delay()); 
  Serial.print(" total=");
  Serial.println(cw.tet() + cw.last_delay());
  cw.stop();
}