#include "AP_Baro_Params.h"
#include "AP_Baro.h"

// table of user settable parameters
const AP_Param::GroupInfo AP_Baro_Params::var_info[] = {
    // @Param: TYPE
    // @DisplayName: Baro type
    // @Description: Whether an analog Baro device is connected
    // @Values: 0:None,1:Analog
    // @User: Standard
    AP_GROUPINFO("TYPE",    1, AP_Baro_Params, type, 0),

    // @Param: PIN
    // @DisplayName: Analog Baro pin
    // @Description: Analog pin that baro is connected to. Set to 11 on PX4 for the analog 'airspeed' port. Set to 15 on the Pixhawk for the analog 'airspeed' port.
    // @Values: -1:Not Used, 11:PX4-airspeed port, 15:Pixhawk-airspeed port
    // @User: Standard
    AP_GROUPINFO("PIN",     2, AP_Baro_Params, pin, -1),

    // @Param: SCALING
    // @DisplayName: Barometer scaling
    // @Description: Scaling factor between barometer reading and depth. For the linear and inverted functions this is in meters per volt. For the hyperbolic function the units are meterVolts.
    // @Units: m/V
    // @Increment: 0.001
    // @User: Standard
    AP_GROUPINFO("SCALING", 3, AP_Baro_Params, scaling, 3.0f),

    // @Param: OFFSET
    // @DisplayName: analog barometer offset
    // @Description: Offset in volts for zero distance for analog barometer. Offset added to distance in centimeters for PWM and I2C Lidars
    // @Units: V
    // @Increment: 0.001
    // @User: Standard
    AP_GROUPINFO("OFFSET",  4, AP_Baro_Params, offset, 0.0f),

    // @Param: FUNCTION
    // @DisplayName: Barometer function
    // @Description: Control over what function is used to calculate distance. For a linear function, the distance is (voltage-offset)*scaling. For a inverted function the distance is (offset-voltage)*scaling. For a hyperbolic function the distance is scaling/(voltage-offset). The functions return the distance in meters.
    // @Values: 0:Linear,1:Inverted,2:Hyperbolic
    // @User: Standard
    AP_GROUPINFO("FUNCTION", 5, AP_Baro_Params, function, 0),

    // @Param: MIN_CM
    // @DisplayName: Baro minimum distance
    // @Description: Minimum distance in centimeters that the barometer can reliably read
    // @Units: cm
    // @Increment: 1
    // @User: Standard
    AP_GROUPINFO("MIN_CM",  6, AP_Baro_Params, min_depth_cm, 20),

    // @Param: MAX_CM
    // @DisplayName: Baro maximum distance
    // @Description: Maximum distance in centimeters that Baro can reliably read
    // @Units: cm
    // @Increment: 1
    // @User: Standard
    AP_GROUPINFO("MAX_CM",  7, AP_Baro_Params, max_depth_cm, 7000),

    // @Param: STOP_PIN
    // @DisplayName: Baro stop pin
    // @Description: Digital pin that enables/disables baro measurement for the pwm Baro. A value of -1 means no pin. If this is set, then the pin is set to 1 to enable the Baro and set to 0 to disable it. This is used to enable powersaving when out of range.
    // @Values: -1:Not Used,50:Pixhawk AUXOUT1,51:Pixhawk AUXOUT2,52:Pixhawk AUXOUT3,53:Pixhawk AUXOUT4,54:Pixhawk AUXOUT5,55:Pixhawk AUXOUT6,111:PX4 FMU Relay1,112:PX4 FMU Relay2,113:PX4IO Relay1,114:PX4IO Relay2,115:PX4IO ACC1,116:PX4IO ACC2
    // @User: Standard
    AP_GROUPINFO("STOP_PIN", 8, AP_Baro_Params, stop_pin, -1),

    // 9 was SETTLE

    // @Param: RMETRIC
    // @DisplayName: Ratiometric
    // @Description: This parameter sets whether an analog barometer is ratiometric. Most analog Baros are ratiometric, meaning that their output voltage is influenced by the supply voltage. Some analog Baros (such as the SF/02) have their own internal voltage regulators so they are not ratiometric.
    // @Values: 0:No,1:Yes
    // @User: Standard
    AP_GROUPINFO("RMETRIC", 10, AP_Baro_Params, ratiometric, 1),

    // @Param: PWRRNG
    // @DisplayName: Powersave range
    // @Description: This parameter sets the estimated terrain distance in meters above which the sensor will be put into a power saving mode (if available). A value of zero means power saving is not enabled
    // @Units: m
    // @Range: 0 32767
    // @User: Standard
    AP_GROUPINFO("PWRRNG", 11, AP_Baro_Params, powersave_range, 0),

    // @Param: GNDCLEAR
    // @DisplayName: Distance (in cm) from the range finder to the ground
    // @Description: This parameter sets the expected range measurement(in cm) that the range finder should return when the vehicle is on the ground.
    // @Units: cm
    // @Range: 5 127
    // @Increment: 1
    // @User: Standard
    AP_GROUPINFO("GNDCLEAR", 12, AP_Baro_Params, ground_clearance_cm, BARO_GROUND_CLEARANCE_CM_DEFAULT),

    // @Param: ADDR
    // @DisplayName: Bus address of sensor
    // @Description: This sets the bus address of the sensor, where applicable. Used for the I2C and UAVCAN sensors to allow for multiple sensors on different addresses. A value of 0 disables the sensor.
    // @Range: 0 127
    // @Increment: 1
    // @User: Standard
    AP_GROUPINFO("ADDR", 23, AP_Baro_Params, address, 0),

    // @Param: POS_X
    // @DisplayName:  X position offset
    // @Description: X position of the first Baro in body frame. Positive X is forward of the origin. Use the zero range datum point if supplied.
    // @Units: m
    // @User: Advanced

    // @Param: POS_Y
    // @DisplayName: Y position offset
    // @Description: Y position of the first Baro in body frame. Positive Y is to the right of the origin. Use the zero range datum point if supplied.
    // @Units: m
    // @User: Advanced

    // @Param: POS_Z
    // @DisplayName: Z position offset
    // @Description: Z position of the first Baro in body frame. Positive Z is down from the origin. Use the zero range datum point if supplied.
    // @Units: m
    // @User: Advanced
    AP_GROUPINFO("POS", 49, AP_Baro_Params, pos_offset, 0.0f),

    AP_GROUPEND
};

AP_Baro_Params::AP_Baro_Params(void) {
    AP_Param::setup_object_defaults(this, var_info);
}
