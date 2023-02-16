#include <iostream>
#include "PrimaryKeyboardMidiInBlock.h"
#include "../Midi/MidiMessage.h"
#include "../Utilities/Debug.h"
#include "../Model/Model.h"
#include "../Model/Organ.h"
#include "../Controller/Controller.h"
#include "../Controller/OrganController.h"

PrimaryKeyboardMidiInBlock::PrimaryKeyboardMidiInBlock(Controller* controller)
	: MidiInBlock(controller)
{
}

bool PrimaryKeyboardMidiInBlock::OnMidiIn(const uint8_t *data, int length)
{
    std::cout << "PrimaryKeyboardMidiInBlock::OnMidiIn\n";

    bool handleMessage = true;

    if (MidiMessage::IsCcMessage(data, length))
    {
        if (MidiMessage::IsChannel1(data, length))
        {
            Debug::Assert(length == 3, __FUNCTION__, "Illegal length for MIDI CC message");

            HandleCcMessage(data[1], data[2]);
        }

        handleMessage = false;
    }

    return handleMessage;
}

bool PrimaryKeyboardMidiInBlock::HandleCcMessage(uint8_t ccNumber, uint8_t value)
{
    bool handleMessage = true;

    switch (ccNumber)
    {
    case 90:              // TODO button 9
        if (value == 127) // Pressed
        {
            GetController()->GetOrganController()->SwapRotatorSpeed();
        }
        break;
    }
    return handleMessage;
}