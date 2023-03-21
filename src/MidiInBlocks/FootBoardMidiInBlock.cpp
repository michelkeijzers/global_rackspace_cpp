#include "FootBoardMidiInBlock.h"
#include "../Controller/Controller.h"
#include "../Controller/OrganSubController.h"
#include "../Controller/WindowSubController.h"
#include "../Midi/MidiMessage.h"
#include "../Model/Model.h"
#include "../Model/OrganSubModel.h"
#include "../Utilities/Debug.h"
#include <iostream>

FootBoardMidiInBlock::FootBoardMidiInBlock(Controller &controller) : MidiInBlock(controller, "FootBoardMidiIn")
{
}

bool FootBoardMidiInBlock::HandleCcMessage(uint8_t ccNumber, uint8_t value)
{
    bool handleMessage = true;
	 switch ((ECCs)ccNumber)
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
            OrganSubController &organSubController =
                static_cast<OrganSubController &>(GetController().GetSubController(SubControllers::ESubControllerId::Organ));
            organSubController.SwapRotatorSpeed();
            handleMessage = false;
        }
        break;

    case ECCs::Switch4:
        //PrimaryKeyboardController &primaryKeyboardController =  

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
