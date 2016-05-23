#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <Servo.h>

class Vehicle {
public:
    // Creates a new vehicle instance.
    Vehicle(int right_pin, int left_pin);
  
    // Drives the car backward (-100 to -1), forward (1 to 100), or stop (0).
    void move(int speed);
  
    // Stops and turns car right (0 to 100).
    void turn_right(unsigned speed);
  
    // Stops and turns car left (0 to 100).
    void turn_left(unsigned speed);
  
    // Spins car in place, turning left (-100 to -1), right (1 to 100), or stop (0).
    void spin_in_circle(int speed);

private:
    // Activate the servo pins RIGHT_PIN and LEFT_PIN.
    void attach_servos();

    // Transforms a speed value from [-100, 100] to [0, 180].
    unsigned convert_speed(int speed);

    int RIGHT_PIN;
    int LEFT_PIN;

    Servo right;
    Servo left;
};

#endif // VEHICLE_HPP
