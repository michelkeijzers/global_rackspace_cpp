#include "PrimaryKeyboardMidiInBlock.h"
#include "../Controller/Controller.h"
#include "../Controller/OrganSubController.h"
#include "../Controller/WindowSubController.h"
#include "../Model/Model.h"
#include "../Model/OrganSubModel.h"
#include "../Utilities/Debug.h"
#include "../Utilities/MidiUtilities.h"
#include <iostream>

PrimaryKeyboardMidiInBlock::PrimaryKeyboardMidiInBlock(Controller &controller)
    : MidiInBlock(controller, "PrimaryKeyboardMidiIn")
{
}

bool PrimaryKeyboardMidiInBlock::HandleCcMessage(uint8_t ccNumber, uint8_t value)
{
    bool handleMessage = true;
    switch ((ECCs)ccNumber)
    {
    case ECCs::Knob1: {
        OrganSubController &organSubController =
            (OrganSubController &)(GetController().GetSubController(SubControllers::ESubControllerId::Organ));
        organSubController.SetDrive(MidiUtilities::MidiToParam(value));
        handleMessage = false;
    }
    break;

    case ECCs::Knob2: {
        OrganSubController &organSubController =
            (OrganSubController &)(GetController().GetSubController(SubControllers::ESubControllerId::Organ));
        organSubController.SetReverbAmount(MidiUtilities::MidiToParam(value));
        handleMessage = false;
    }
    break;

    case ECCs::ButtonLeft:
        GetController().OnPreviousSong();
        break;

    case ECCs::ButtonRight:
        GetController().OnNextSong();
        break;

	 case ECCs::Button1:
        if (value == VALUE_BUTTON_PRESSED)
        {
            GetController().WriteSong();
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
