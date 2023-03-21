#include "PrimaryKeyboardMidiInBlock.h"
#include "../Controller/Controller.h"
#include "../Controller/OrganSubController.h"
#include "../Controller/WindowSubController.h"
#include "../Midi/MidiMessage.h"
#include "../Model/Model.h"
#include "../Model/OrganSubModel.h"
#include "../Utilities/Debug.h"
#include <iostream>

PrimaryKeyboardMidiInBlock::PrimaryKeyboardMidiInBlock(Controller &controller)
    : MidiInBlock(controller, "PrimaryKeyboardMidiIn")
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

            handleMessage = HandleCcMessage(data[1], data[2]);
        }
    }

    Debug::LogMethodExit(__FUNCTION__);

    return handleMessage;
}

bool PrimaryKeyboardMidiInBlock::HandleCcMessage(uint8_t ccNumber, uint8_t value)
{
    bool handleMessage = true;

    switch ((ECCs)ccNumber)
    {
    case ECCs::Knob1: {
        OrganSubController &organSubController =
            (OrganSubController &)(GetController().GetSubController(SubControllers::ESubControllerId::Organ));

        organSubController.SetDrive(MidiMessage::MidiToParam(value));
        handleMessage = false;
    }
    break;

    case ECCs::Knob2: {
        OrganSubController &organSubController =
            (OrganSubController &)(GetController().GetSubController(SubControllers::ESubControllerId::Organ));

        organSubController.SetReverbAmount(MidiMessage::MidiToParam(value));
        handleMessage = false;
    }
    break;

    case ECCs::Button9:
        if (value == VALUE_BUTTON_PRESSED)
        {
            OrganSubController &organSubController =
                (OrganSubController &)(GetController().GetSubController(SubControllers::ESubControllerId::Organ));

            organSubController.SwapRotatorSpeed();
            handleMessage = false;
        }
        break;

    case ECCs::Button12:
        if (value == VALUE_BUTTON_PRESSED)
        {
            WindowSubController &windowSubController =
                (WindowSubController &)(GetController().GetSubController(SubControllers::ESubControllerId::Window));

            windowSubController.SetNextSlidersPane();
            handleMessage = false;
        }
        break;
    }

    return handleMessage;
}
