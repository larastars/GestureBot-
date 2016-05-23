#include "Vehicle.hpp"

Vehicle *car;

void setup()
{
    // Initialize car's servo motors.
    car = new Vehicle(2, 3);
  
    // Open a serial connection through USB.
    Serial.begin(19200);
    while (!Serial);
  
    // Print help text.
    Serial.println("Known commands:");
    Serial.println("  move <number>     Drive at speed 0-100 (pos == forward, neg == backward)");
    Serial.println("  left <number>     Stop and turn left at speed 0-100");
    Serial.println("  right <number>    Stop and turn right at speed 0-100");
    Serial.println("  circle <number>   Spin in place at speed 0-100 (pos == left, neg == right)\n");
}

void loop()
{
  // Process commands entered from serial connection.
  while (Serial.available() > 0) {
      String action = Serial.readStringUntil(' ');
      String value = Serial.readStringUntil('\n');
  
      if (action == "move") {
          car->move(value.toInt());
      } else if (action == "left") {
          car->turn_left(value.toInt());
      } else if (action == "right") {
          car->turn_right(value.toInt());
      } else if (action == "circle") {
          car->spin_in_circle(value.toInt());
      } else {
          break;
      }
  
      Serial.println("Recognized command \"" + action + " " + value + "\".");
  }

  // If serial connection broken, stop the car and wait.
  if (!Serial) {
      //car->move(0);
      Serial.begin(19200);
      while (!Serial);
  }
}
