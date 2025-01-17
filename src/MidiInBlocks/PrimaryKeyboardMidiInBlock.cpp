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

bool PrimaryKeyboardMidiInBlock::HandleNoteOffMessage(uint8_t noteNumber, uint8_t velocity) // override
{
   OrganSubController &organSubController =
    (OrganSubController &)(GetController().GetSubController(SubControllers::ESubControllerId::Organ));
   organSubController.NoteOff(true, noteNumber, velocity);
   return true;
}

bool PrimaryKeyboardMidiInBlock::HandleNoteOnMessage(uint8_t noteNumber, uint8_t velocity) // override
{
   OrganSubController &organSubController =
    (OrganSubController &)(GetController().GetSubController(SubControllers::ESubControllerId::Organ));
   organSubController.NoteOn(true, noteNumber, velocity);
   return true;
}

bool PrimaryKeyboardMidiInBlock::HandleCcMessage(uint8_t ccNumber, uint8_t value) // override
{
   bool handleMessage = true;
   switch (static_cast<ECCs>(ccNumber))
   {
   case ECCs::Knob1: {
      OrganSubController &organSubController =
       static_cast<OrganSubController &>(GetController().GetSubController(SubControllers::ESubControllerId::Organ));
      organSubController.SetDrive(MidiUtilities::MidiToParam(value));
      handleMessage = false;
   }
   break;
   case ECCs::Knob2: {
      OrganSubController &organSubController =
       static_cast<OrganSubController &>(GetController().GetSubController(SubControllers::ESubControllerId::Organ));
      organSubController.SetReverbAmount(MidiUtilities::MidiToParam(value));
      handleMessage = false;
   }
   break;
   case ECCs::ButtonLeft: 
		if (value == VALUE_BUTTON_PRESSED)
      {
         GetController().OnPreviousSong();
         handleMessage = false;
      }
      break;
   case ECCs::ButtonRight: 
		if (value == VALUE_BUTTON_PRESSED)
      {
         GetController().OnNextSong();
         handleMessage = false;
      }
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
          static_cast<OrganSubController &>(GetController().GetSubController(SubControllers::ESubControllerId::Organ));
         organSubController.SwapRotatorSpeed();
         handleMessage = false;
      }
      break;
   case ECCs::Button12:
      if (value == VALUE_BUTTON_PRESSED)
      {
         WindowSubController &windowSubController =
          static_cast<WindowSubController &>(GetController().GetSubController(SubControllers::ESubControllerId::Window));
         windowSubController.SetNextSlidersPane();
         handleMessage = false;
      }
      break;
   }
   return handleMessage;
}
