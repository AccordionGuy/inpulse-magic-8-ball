//
// InPulse Magic 8-Ball
// ====================
//
// A "Magic 8-ball" app for the inPulse smartwatch.
// Normally, it displays the time in h:mm:ss format.
// When the user presses the button, it displays
// a "Magic 8-ball"-style answer for five seconds,
// and then returns to its normal mode of showing
// the time.

#include <stdint.h>
#include <stdlib.h>

#include <pulse_os.h>
#include <pulse_types.h>


enum DisplayMode_t { TIME_MODE, ANSWER_MODE } display_mode;

// Magic 8-ball answers
#define  NUM_8BALL_ANSWERS 15
typedef  char* string;
string   magic_8ball_quotes[NUM_8BALL_ANSWERS];

// Timing
#define  TIME_UPDATE_INTERVAL_LENGTH_MS 900
#define  ANSWER_INTERVAL_LENGTH_MS 5000 
struct   pulse_time_tm current_time;
uint32_t interval_start_time_ms;
uint32_t interval_length_ms;
uint32_t now_ms;


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

void set_time_mode()
{
    display_mode = TIME_MODE;
    interval_length_ms = TIME_UPDATE_INTERVAL_LENGTH_MS;
    interval_start_time_ms = pulse_get_millis();
}

void update_time_display()
{
    pulse_blank_canvas();
    pulse_get_time_date(&current_time);
    printf("The time is\n%d:%0.2d:%0.2d\n", 
           current_time.tm_hour,
           current_time.tm_min,
           current_time.tm_sec);
}

void display_prequote_message()
{
    pulse_blank_canvas();
    printf("Think of a yes-\nor-no question.\n");
}

void set_answer_mode()
{
    display_mode = ANSWER_MODE;
    interval_length_ms = ANSWER_INTERVAL_LENGTH_MS;
    interval_start_time_ms = pulse_get_millis();
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
    now_ms = pulse_get_millis();
    if (now_ms - interval_start_time_ms > interval_length_ms) {
        if (display_mode == ANSWER_MODE) {
            set_time_mode();
        }
        update_time_display();
    }
}

void main_app_handle_doz()
{

}

void main_app_handle_hardware_update(enum PulseHardwareEvent event)
{

}