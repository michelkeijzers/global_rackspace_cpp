#include "PrimaryKeyboardMidiInBlock.h"
#include "../Controller/Controller.h"
#include "../Controller/OrganSubController.h"
#include "../Midi/MidiMessage.h"
#include "../Model/Model.h"
#include "../Model/organSubModel.h"
#include "../Utilities/Debug.h"
#include <iostream>

PrimaryKeyboardMidiInBlock::PrimaryKeyboardMidiInBlock(Controller &controller)
    : MidiInBlock(controller, "PrimaryKeyboardMidiIn")
{
}

void PrimaryKeyboardMidiInBlock::Init() /* override */
{
}

bool PrimaryKeyboardMidiInBlock::OnMidiIn(const uint8_t *data, int length)
{
    Debug::LogMethodEntry(__FUNCTION__, "length = " + std::to_string(length));

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

	 Debug::LogMethodExit(__FUNCTION__);

    return handleMessage;
}

bool PrimaryKeyboardMidiInBlock::HandleCcMessage(uint8_t ccNumber, uint8_t value)
{
    bool handleMessage = true;

    switch (ccNumber)
    {
    case CC_BUTTON_9:
        if (value == VALUE_BUTTON_PRESSED)
        {
            OrganSubController &organSubController =
                (OrganSubController &)(GetController().GetSubController(SubControllers::ESubControllerId::Organ));

            organSubController.SwapRotatorSpeed();
        }
        break;
    }
    return handleMessage;
}
