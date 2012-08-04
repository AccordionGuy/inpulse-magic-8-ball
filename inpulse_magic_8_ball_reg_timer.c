//
// InPulse Magic 8-Ball, Timer-Style!
// ==================================
//
// A "Magic 8-ball" app for the inPulse smartwatch.
// Normally, it displays the time in h:mm:ss format.
// When the user presses the button, it displays
// a "Magic 8-ball"-style answer for five seconds,
// and then returns to its normal mode of showing
// the time.
//
// To the user, this app is the same as the
// previous version. The difference is in the way
// timing is done -- this version uses inPulse's
// registered timer and the pulse_register_timer
// function instead of watching the main timer
// from inside the main app loop.

#include <stdint.h>
#include <stdlib.h>

#include <pulse_os.h>
#include <pulse_types.h>


// Magic 8-ball answers
#define  NUM_8BALL_ANSWERS 15
typedef  char* string;
string   magic_8ball_quotes[NUM_8BALL_ANSWERS];

// Timing
#define  TIME_UPDATE_INTERVAL_LENGTH_MS 900
#define  ANSWER_INTERVAL_LENGTH_MS 5000
#define  TIMER_CANCELLED -1
struct   pulse_time_tm current_time;
int32_t  timer_id = TIMER_CANCELLED;


void initialize_8ball_answers()
{
    magic_8ball_quotes[0]  = "I'd bet money on it";
    magic_8ball_quotes[1]  = "HELLZ YEAH!";
    magic_8ball_quotes[2]  = "Yes. Absolutely.";
    magic_8ball_quotes[3]  = "Signs point to yes.";
    magic_8ball_quotes[4]  = "Without a doubt.";
    magic_8ball_quotes[5]  = "Ask again later.";
    magic_8ball_quotes[6]  = "I'm not sure; try again.";
    magic_8ball_quotes[7]  = "Mmmmmmmmmaybe.";
    magic_8ball_quotes[8]  = "Think and ask again.";
    magic_8ball_quotes[9]  = "Can't predict now.";
    magic_8ball_quotes[10] = "Ummm...no.";
    magic_8ball_quotes[11] = "HELLZ NO!";
    magic_8ball_quotes[12] = "Absolutely not!";
    magic_8ball_quotes[13] = "I seriously doubt it.";
    magic_8ball_quotes[14] = "No. No. No. NO!";
}

string random_magic_8ball_quote()
{
    return magic_8ball_quotes[rand() % NUM_8BALL_ANSWERS];
}

void update_time_display();

void start_timer(uint32_t duration, PulseCallback callback)
{
    if (timer_id != TIMER_CANCELLED) {
      pulse_cancel_timer(&timer_id);
    }
    timer_id = pulse_register_timer(duration, callback, NULL);
}

void set_time_mode()
{
    start_timer(TIME_UPDATE_INTERVAL_LENGTH_MS,
                &update_time_display);
}

void update_time_display()
{
    pulse_blank_canvas();
    pulse_get_time_date(&current_time);
    printf("The time is\n%d:%0.2d:%0.2d\n", 
           current_time.tm_hour,
           current_time.tm_min,
           current_time.tm_sec);
    set_time_mode();
}

void display_prequote_message()
{
    pulse_blank_canvas();
    printf("Think of a yes-\nor-no question.\n");
}

void set_answer_mode()
{
    start_timer(ANSWER_INTERVAL_LENGTH_MS,
                &update_time_display);
}

void display_answer()
{
    pulse_blank_canvas();
    printf("The 8-ball says:\n\"%s\"\n", random_magic_8ball_quote());
}


// inPulse Event Handlers
// ======================

void main_app_init()
{
    initialize_8ball_answers();
    set_time_mode();
    update_time_display();
}

void main_app_handle_button_down()
{
    display_prequote_message();
}

void main_app_handle_button_up()
{
    set_answer_mode();
    display_answer();
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