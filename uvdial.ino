#include <MicroView.h>

MicroViewWidget *widget;

void setup() {
  Serial.begin(57600);
  uView.begin();
  uView.clear(PAGE);
  uView.setCursor(0, 0);
  uView.print("CPU");
  widget = new MicroViewGauge(40, 24, 0, 100, WIDGETSTYLE1);
  // widget = new MicroViewGauge(32, 24, 0, 240, WIDGETSTYLE1 + WIDGETNOVALUE);
  widget->setValue(0);
  uView.display();
}

void loop() {
  if (Serial.available()) {
    int i = Serial.parseInt();
    widget->setValue(i);
    uView.display();
  }
}


