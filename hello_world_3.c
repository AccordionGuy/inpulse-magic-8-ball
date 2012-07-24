//
// Hello, World!
// =============
//
// A simple tutorial app that demonstrates displaying the time
// and other text on the inPulse smartwatch screen,
// as well as responding to button events.
//
// Since this is a tutorial app, it's a little more heavily
// commented than your typical code.


#include <stdint.h>

// Headers we'll need to program inPulse apps.
// - pulse_os.h gives us access to the inPulse API functions,
//   from telling the time to drawing on the screen to controlling
//   vibration and so on.
// - pulse_types.h provides data types that we use when using
//   the inPulse API.
#include <pulse_os.h>
#include <pulse_types.h>


// inPulse Event Handlers
// ======================
// These routines are called in response to inPulse watch events,
// such as the watch booting up, the user pressing and releasing
// the button and so on.

// main_app_init is called once: after the watch has booted up, its
// OS has been loaded and when the app is starting up. 
// Use this to initialize your app.
void main_app_init()
{
    printf("Hello, world!\n");
}

// main_app_handle_button_down is called every time the user presses down
// on the watch button.
void main_app_handle_button_down()
{
    printf("Button goes down...\n");
}

// main_app_handle_button_up is called every time the user releases the
// watch button after having pressed it.
void main_app_handle_button_up()
{
    printf("...button goes up!\n");
}

// main_app_loop is a function that gets called regularly and frequently.
// Use this for operations that your app will perform on a regular basis.
// No blocking calls are allowed in this function; any call that blocks
// for over 5 seconds will cause the inPulse watchdog timer to start and
// reset the watch.
void main_app_loop()
{

}

// main_app_handle_doz is called whenever the processor is about to go into
// sleep mode to conserve power. Use this to do any "housekeeping" before the
// watch goes to sleep.
// The sleep functionality is scheduled with pulse_update_power_down_timer.
void main_app_handle_doz()
{

}

// main_app_handle_hardware_update is called whenever certain hardware events
// take place, such as Bluetooth connection/disconnetion and changes in the
// "battery charging" status.
void main_app_handle_hardware_update(enum PulseHardwareEvent event)
{

}