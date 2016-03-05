#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

#define LED 13   		    // LED pin on Arduino Uno

void setup()
{
    pinMode(LED, OUTPUT);
    MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop()
{
    if (MIDI.read())                // If we have received a message
    {
      MIDI.send(MIDI.getType(),
        MIDI.getData1(),
        MIDI.getData2(),
        MIDI.getChannel());
    }
}
