#include <clockwork.h>

void tet_warning(long t) {
  Serial.print(t);
  Serial.println(" TET warning!");
}

Clockwork cw(500, tet_warning);

void setup() {
  Serial.begin(9600);
}

void loop() {
  cw.start();
  delay(400 + random(0, 110));
  Serial.print("tet=");
  Serial.print(cw.tet());
  Serial.print(" delay=");
  Serial.print(cw.last_delay()); 
  Serial.print(" total=");
  Serial.println(cw.tet() + cw.last_delay());
  cw.stop();
}