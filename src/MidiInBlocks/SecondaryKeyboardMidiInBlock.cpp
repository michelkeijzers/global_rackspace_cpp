#include "SecondaryKeyboardMidiInBlock.h"
#include "../Controller/Controller.h"
#include "../Model/Model.h"
#include "../Utilities/Debug.h"
#include "../Utilities/MidiUtilities.h"
#include <iostream>

SecondaryKeyboardMidiInBlock::SecondaryKeyboardMidiInBlock(Controller &controller)
    : MidiInBlock(controller, "SecondaryKeyboardMidiIn")
{
}

bool SecondaryKeyboardMidiInBlock::HandleNoteOffMessage(uint8_t noteNumber, uint8_t velocity) // override
{
   OrganSubController &organSubController =
    (OrganSubController &)(GetController().GetSubController(SubControllers::ESubControllerId::Organ));
   organSubController.NoteOn(true, noteNumber, velocity);
   return true;
}

bool SecondaryKeyboardMidiInBlock::HandleNoteOnMessage(uint8_t noteNumber, uint8_t velocity) // override
{
   OrganSubController &organSubController =
    (OrganSubController &)(GetController().GetSubController(SubControllers::ESubControllerId::Organ));
   organSubController.NoteOff(true, noteNumber, velocity);
   return true;
}

#pragma warning(disable : 4100)
bool SecondaryKeyboardMidiInBlock::HandleCcMessage(uint8_t ccNumber, uint8_t value) // override
#pragma warning(default : 4100)
{
   bool handleMessage = true;
   return handleMessage;
}
