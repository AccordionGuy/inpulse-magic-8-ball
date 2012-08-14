//
// Mulitple Timer Demo
// ===================
//
// An app that demonstrates the inPulse API's
// pulse_register_timer function to create
// multiple timers. 

#include <stdint.h>

#include <pulse_os.h>
#include <pulse_types.h>


typedef char* string;


void display_message(string message)
{
    uint32_t interval = pulse_get_millis();
    pulse_blank_canvas();
    printf("%s\n", message);
    printf("Main timer:\n%d\n", interval);
}

// inPulse Event Handlers
// ======================

void main_app_init()
{
    printf("Starting the\ntimer.");
    pulse_register_timer(3000, &display_message, "3 seconds.");
    pulse_register_timer(5000, &display_message, "5 seconds.");
    pulse_register_timer(7000, &display_message, "7 seconds.");
}

void main_app_handle_button_down()
{

}

void main_app_handle_button_up()
{

}

void main_app_loop()
{

}

void main_app_handle_doz()
{

}

void main_app_handle_hardware_update(enum PulseHardwareEvent event)
{

}