#pragma once

#include "AP_Baro.h"
#include "AP_Baro_Backend.h"
#include "AP_Baro_Params.h"

class AP_Baro_Analog : public AP_Baro_Backend
{
public:
    // constructor
    AP_Baro_Analog(Baro::Baro_State &_state, AP_Baro_Params &_params);

    // static detection function
    static bool detect(AP_Baro_Params &_params);

    // update state
    void update(void) override;

protected:

    MAV_DISTANCE_SENSOR _get_mav_distance_sensor_type() const override {
        return MAV_DISTANCE_SENSOR_UNKNOWN;
    }

private:
    // update raw voltage
    void update_voltage(void);

    AP_HAL::AnalogSource *source;
};
