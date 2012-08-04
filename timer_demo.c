//
// Timer Demo
// ==========
//
// An app that demonstrates the inPulse API's
// pulse_register_timer function. 

#include <stdint.h>

#include <pulse_os.h>
#include <pulse_types.h>


typedef char* string;


void display_message(string message)
{
    pulse_blank_canvas();
    printf("%s\n", message);
    printf("Main timer:\n%d\n", pulse_get_millis());
}

// inPulse Event Handlers
// ======================

void main_app_init()
{
    printf("Starting the\ntimer.");
    pulse_register_timer(5000, &display_message, "Hello there!");
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