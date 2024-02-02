#ifndef SMARTHOME_H
#define SMARTHOME_H

#include <string>

enum switches 
{ 
    LIGHTS_INSIDE = 1, 
    LIGHTS_OUTSIDE = 2, 
    HEATERS = 4, 
    WATER_PIPE_HEATING = 8, 
    CONDITIONER = 16 
};

class SmartHome {
public:
    SmartHome();
    void processTemperature(int temperature_inside, int temperature_outside);
    void processMovement(bool has_movement, int hours);
    void processLights(std::string lights);
    void simulateTwoDays();

private:
    int switches_state;
    int color_temperature;
    bool lights_inside;
    bool lights_outside;
};

#endif // SMARTHOME_H