# Segway - Robot that balances on 2 wheels

## Problem statement
The main goal of this project is to create a simple robot that balances only on two wheels. The robot will have a longitudinal profile and two wheels whose axes is along the same line. The robot must try its best to remain balanced.

## Solution
The problem can basically be decomposed into two main parts (1) Identifying the current angle of inclination. Which ideally must be 0 degrees or perpendicular to the floor to be considered as a balanced robot. (2) A method to correct this error in inclination, so as to force the robot to be in balance.

For the first problem of estimating the current inclination, an inertial sensor is used. The sensor chosen is MPU6050. The sensor will output the gravity along the three axes and using this one can estimate the inclination of the robot. This sensor will be firmly fixed to the body of the robot, hence reflecting the inclination of the robot.

The second problem of correcting the inclination could be achieved by appropriate acceleration to the centre of gravity of the robot. This needed acceleration can be provided through the wheels present.

## Challenges

Since this is a hardware project some assembly was required. The sensor, MPU6050 must be read as fast as possible in order to estimate changes in its inclination and act as soon as possible. Along with this sensor reading, the robot will have to perform other functions e.g. actuating the wheels appropriately to maintain balance. Hence, accurate time keeping is necessary to keep all the functions going on smoothly.

The other challenge is to know when to actuate the motors. A crude algorithm that only takes the proportion or the sign of error will lead the system into instability. Hence a proportional derivative integral controller (PID) was to designed and used in the system. Estimating the constants of the PID controller is also a challenge as it is experimental.

## Implementation

The sensor MPU6050 was connected to an Arduino (atmega328) microcontroller. Two DC motors housed in 360 degree servo package were driving the wheels, which were also connected to the microcontroller. The system was powered by an USB power package. 

Two different kinds of software were written with the same functionality. One is a linear code and another uses freeRTOS on arduino which allows multitasking with RTOS standards.

## Results

The robot did not perform very well, but was able to keep the balance for some time. Here are two short videos showing the same.

[![Prototype 0.1](http://img.youtube.com/vi/7iJMFH5HTnM/0.jpg)](http://www.youtube.com/watch?v=7iJMFH5HTnM)

[![Prototype 0.1](http://img.youtube.com/vi/4HVC-rO0Jf8/0.jpg)](http://www.youtube.com/watch?v=4HVC-rO0Jf8)

Both linear software aswell as the RTOS version performed similarly as currently there are no other tasks running. Where as, when extra tasks e.g. transmit data through WiFi, store data to SD card, etc. are introduced, the RTOS version is able to cope up with the scheduling tasks.

## Shortcomings

One of the main reasons why the robot is not able to maintain balance for a long time is because the motors being used support only a single speed. For a control system to work well, the feedback loop should have some sort of variability, else there will be such instabilities.

## References

* Code: https://github.com/7andahalf/
* https://www.invensense.com/products/motion-tracking/6-axis/mpu-6050/
* https://playground.arduino.cc/Code/PIDLibrary/
* https://create.arduino.cc/projecthub/feilipu/using-freertos-multi-tasking-in-arduino-ebc3cc

