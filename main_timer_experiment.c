//
// Main Timer Experiment
// =====================
//
// An app written to show the use of the inPulse API's
// pulse_get_millis and main_app_loop functions
// in tandem.

#include <stdint.h>

#include <pulse_os.h>
#include <pulse_types.h>


#define INTERVAL_LENGTH_MS 5000
uint32_t start_interval_ms;
uint32_t now_ms;


// inPulse Event Handlers
// ======================

void main_app_init()
{
    start_interval_ms = pulse_get_millis();
    printf("Starting app!\n");
    printf("Timer: %d\n", start_interval_ms);
}

void main_app_handle_button_down()
{

}

void main_app_handle_button_up()
{

}

void main_app_loop()
{
    now_ms = pulse_get_millis();
    if (now_ms - start_interval_ms > INTERVAL_LENGTH_MS) {
        pulse_blank_canvas();
        printf("5 seconds have\npassed!\n");
        printf("Timer: %d\n", now_ms);
        printf("Actual interval:%d\n", now_ms - start_interval_ms);
        start_interval_ms = pulse_get_millis();
    }
}

void main_app_handle_doz()
{

}

void main_app_handle_hardware_update(enum PulseHardwareEvent event)
{

}