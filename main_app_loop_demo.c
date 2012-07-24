//
// Main App Loop Demo
// ==================
//
// An app that demonstrates the inPulse API's
// main_app_loop event handler.

#include <stdint.h>

#include <pulse_os.h>
#include <pulse_types.h>


struct pulse_time_tm current_time;


// inPulse Event Handlers
// ======================

void main_app_init()
{

}

void main_app_handle_button_down()
{

}

void main_app_handle_button_up()
{

}

void main_app_loop()
{
    pulse_get_time_date(&current_time);
    printf("The time is\n%d:%0.2d:%0.2d\n", 
           current_time.tm_hour,
           current_time.tm_min,
           current_time.tm_sec);
}

void main_app_handle_doz()
{

}

void main_app_handle_hardware_update(enum PulseHardwareEvent event)
{

}