#include "SmartHome.h"
#include <iostream>

SmartHome::SmartHome() : switches_state(0), color_temperature(5000), lights_inside(false), lights_outside(false) {}

void SmartHome::processTemperature(int temperature_inside, int temperature_outside) {
    if (temperature_outside < 0) {
        switches_state |= WATER_PIPE_HEATING;
        std::cout << "Heaters ON!" << std::endl;
    } else if (temperature_outside > 5) {
        switches_state &= ~WATER_PIPE_HEATING;
        std::cout << "Heaters OFF!" << std::endl;
    }

    if (temperature_inside < 22) {
        switches_state |= HEATERS;
        std::cout << "Heaters ON!" << std::endl;
    } else if (temperature_inside >= 25) {
        switches_state &= ~HEATERS;
        std::cout << "Heaters OFF!" << std::endl;
    }

    if (temperature_inside >= 30) {
        switches_state |= CONDITIONER;
        std::cout << "Conditioner ON!" << std::endl;
    } else if (temperature_inside <= 25) {
        switches_state &= ~CONDITIONER;
        std::cout << "Conditioner OFF!" << std::endl;
    }
}

void SmartHome::processMovement(bool has_movement, int hours) {
    if ((hours >= 16 || hours < 5) && has_movement) {
        lights_outside = true;
        std::cout << "Outside Lights ON!" << std::endl;
    } else if ((hours >= 16 || hours < 5) && !has_movement) {
        lights_outside = false;
        std::cout << "Outside Lights OFF!" << std::endl;
    } else if (!has_movement) {
        lights_outside = false;
        std::cout << "Outside Lights OFF!" << std::endl;
    }
}

void SmartHome::processLights(std::string lights) {
    if (lights == "on") {
        lights_inside = true;
        std::cout << "Inside Lights ON!" << std::endl;
        std::cout << "Inside Lights Color temperature: " << color_temperature << "K" << std::endl;
    } else if (lights == "off") {
        lights_inside = false;
        std::cout << "Inside Lights OFF!" << std::endl;
    }
}

void SmartHome::simulateTwoDays() {
    for (int day = 1; day <= 2; day++) {
        for (int hours = 0; hours < 24; hours++) {
            int temperature_inside, temperature_outside;
            std::string movement, lights;

            std::cout << "Temperature inside, temperature outside, movement, lights: ";
            std::cin >> temperature_inside >> temperature_outside >> movement >> lights;
            bool has_movement = (movement == "yes");

            processTemperature(temperature_inside, temperature_outside);
            processMovement(has_movement, hours);
            processLights(lights);
        }
    }
}
