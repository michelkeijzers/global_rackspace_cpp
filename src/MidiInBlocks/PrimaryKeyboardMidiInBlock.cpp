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
            OrganSubController &organSubController =
                (OrganSubController &)(GetController().GetSubControllerById(SubControllers::ESubControllerId::Organ));

            organSubController.SwapRotatorSpeed();
        }
        break;
    }
    return handleMessage;
}
