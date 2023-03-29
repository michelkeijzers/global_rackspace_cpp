#include "MidiInBlock.h"
#include "../Framework/MvcFramework.h"
#include "../Utilities/Debug.h"
#include "../Utilities/MidiUtilities.h"

MidiInBlock::MidiInBlock(Controller &controller, const std::string name) : _controller(controller), _name(name)
{
   MvcFramework::GetGigPerformerApi().listenForMidi(name, true);
}

/* virtual */ void MidiInBlock::Init()
{
}

std::string MidiInBlock::GetName()
{
   return _name;
}

Controller &MidiInBlock::GetController()
{
   return _controller;
}

bool MidiInBlock::OnMidiIn(const uint8_t *data, int length)
{
   Debug::LogMethodEntry(__FUNCTION__, "length = " + std::to_string(length));
   bool handleMessage = true;
   if (MidiUtilities::IsNoteOffMessage(data, length))
   {
      if (MidiUtilities::IsChannel1(data, length))
      {
         Debug::Assert(length == 3, __FUNCTION__, "Illegal length for MIDI note message");
         HandleNoteOffMessage(data[1], data[2]);
      }
   }
   else if (MidiUtilities::IsNoteOnMessage(data, length))
   {
      if (MidiUtilities::IsChannel1(data, length))
      {
         Debug::Assert(length == 3, __FUNCTION__, "Illegal length for MIDI note message");
         HandleNoteOnMessage(data[1], data[2]);
      }
   }
   else if (MidiUtilities::IsCcMessage(data, length))
   {
      if (MidiUtilities::IsChannel1(data, length))
      {
         Debug::Assert(length == 3, __FUNCTION__, "Illegal length for MIDI CC message");
         HandleCcMessage(data[1], data[2]);
      }
   }
   Debug::LogMethodExit(__FUNCTION__);
   return handleMessage;
}

#pragma warning(disable : 4100)

/* virtual */ bool MidiInBlock::HandleNoteOffMessage(uint8_t noteNumber, uint8_t velocity)
{
   return true;
}

/* virtual */ bool MidiInBlock::HandleNoteOnMessage(uint8_t noteNumber, uint8_t velocity)
{
   return true;
}

#pragma warning(default : 4100)
