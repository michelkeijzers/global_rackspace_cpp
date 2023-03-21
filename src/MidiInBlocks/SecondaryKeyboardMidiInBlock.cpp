#include "SecondaryKeyboardMidiInBlock.h"
#include "../Controller/Controller.h"
#include "../Midi/MidiMessage.h"
#include "../Model/Model.h"
#include "../Utilities/Debug.h"
#include <iostream>

SecondaryKeyboardMidiInBlock::SecondaryKeyboardMidiInBlock(Controller &controller)
    : MidiInBlock(controller, "SecondaryKeyboardMidiIn")
{
}

bool SecondaryKeyboardMidiInBlock::HandleCcMessage(uint8_t ccNumber, uint8_t value)
{
    bool handleMessage = true;
    switch ((ECCs)ccNumber)
    {
    case ECCs::Sustain: 
        break;
    }

	 return handleMessage;
}
