#include "FootBoardMidiInBlock.h"
#include "../Controller/Controller.h"
#include "../Controller/KeyboardSubController.h"
#include "../Controller/OrganSubController.h"
#include "../Controller/WindowSubController.h"
#include "../Model/Model.h"
#include "../Model/OrganSubModel.h"
#include "../Utilities/Debug.h"
#include "../Utilities/MidiUtilities.h"
#include <iostream>

FootBoardMidiInBlock::FootBoardMidiInBlock(Controller &controller) : MidiInBlock(controller, "FootBoardMidiIn")
{
}

bool FootBoardMidiInBlock::HandleCcMessage(uint8_t ccNumber, uint8_t value)
{
    bool handleMessage = true;
    switch (static_cast<ECCs>(ccNumber))
    {
    case ECCs::Switch1: {
        // TODO: Modulation wheel upper keyboard
        handleMessage = false;
    }
    break;
    case ECCs::Switch2: {
        // TODO: Modulation wheel lower keyboard
        handleMessage = false;
    }
    break;
    case ECCs::Switch3:
        if (value == VALUE_BUTTON_PRESSED)
        {
            OrganSubController &organSubController = static_cast<OrganSubController &>(
                GetController().GetSubController(SubControllers::ESubControllerId::Organ));
            organSubController.SwapRotatorSpeed();
            handleMessage = false;
        }
        break;
    case ECCs::Switch4: {
        KeyboardSubController &keyboardSubController = static_cast<KeyboardSubController &>(
            GetController().GetSubController(SubControllers::ESubControllerId::PrimaryKeyboard));
        keyboardSubController.EnableSustain(MidiUtilities::MidiToBool(value));
        handleMessage = false;
    }
    break;
    case ECCs::Switch5: {
        KeyboardSubController &keyboardSubController = static_cast<KeyboardSubController &>(
            GetController().GetSubController(SubControllers::ESubControllerId::SecondaryKeyboard));
        keyboardSubController.EnableSustain(MidiUtilities::MidiToBool(value));
        handleMessage = false;
    }
    break;
    case ECCs::LeftPedal: {
        KeyboardSubController &keyboardSubController = static_cast<KeyboardSubController &>(
            GetController().GetSubController(SubControllers::ESubControllerId::PrimaryKeyboard));
        keyboardSubController.SetExpressionVolume(MidiUtilities::MidiToParam(value));
        handleMessage = false;
    }
    break;
    case ECCs::RightPedal: {
        KeyboardSubController &keyboardSubController = static_cast<KeyboardSubController &>(
            GetController().GetSubController(SubControllers::ESubControllerId::SecondaryKeyboard));
        keyboardSubController.SetExpressionVolume(MidiUtilities::MidiToParam(value));
        handleMessage = false;
    }
    break;
    }
    return handleMessage;
}
