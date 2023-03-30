#include "OrganMidiInBlock.h"
#include "../Framework/MvcFramework.h"
#include "../Model/OrganSubModel.h"
#include "../Utilities/BoolUtilities.h"
#include "../Utilities/Debug.h"
#include "../Utilities/MidiUtilities.h"
#include "../View/ChangedProperties.h"
#include <iostream>
#include <juce_audio_basics/midi/juce_MidiMessage.h>
#ifdef TESTER
#include "../../../JuceTester2/NewProject/Builds/VisualStudio2022/Source/GP_API/GigPerformerAPI.h"
#else
#include <gigperformer/sdk/GigPerformerAPI.h>
#endif

OrganMidiInBlock::OrganMidiInBlock(View &view, OrganSubModel &organSubModel, const std::string &name)
    : _name(name), _view(view), _organSubModel(organSubModel)
{
   _organSubModel.Subscribe(*this);
}

void OrganMidiInBlock::Init()
{
}

const std::string OrganMidiInBlock::GetName()
{
   return _name;
}

View &OrganMidiInBlock::GetView()
{
   return _view;
}

void OrganMidiInBlock::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
   switch (changedProperty)
   {
   case ChangedProperties::EChangedProperty::PrimaryKeyboardOrganNotesOff: // Fall through
   case ChangedProperties::EChangedProperty::SecondaryKeyboardOrganNotesOff: {
      HandleNoteOnOff(false);
   }
   break;
   case ChangedProperties::EChangedProperty::PrimaryKeyboardOrganNotesOn: // Fall through
   case ChangedProperties::EChangedProperty::SecondaryKeyboardOrganNotesOn: {
      HandleNoteOnOff(true);
   }
   break;

   default:
      // Ignore
      break;
   }
}

void OrganMidiInBlock::HandleNoteOff()
{
   HandleNoteOnOff(false);
}

void OrganMidiInBlock::HandleNoteOn()
{
   HandleNoteOnOff(true);
}

void OrganMidiInBlock::HandleNoteOnOff(bool noteOn)
{
   std::pair<uint8_t, uint8_t> values = _organSubModel.PopNoteOff();
   uint8_t midiMessage[MIDI_MESSAGE_NOTE_ON_OFF_LENGTH];
   uint8_t noteNumber = values.first;
   uint8_t velocity = values.second;
   if (noteOn)
   {
      MidiUtilities::FillNoteOnMessage(midiMessage, noteNumber, velocity);
   }
	else
	{
      MidiUtilities::FillNoteOffMessage(midiMessage, noteNumber, velocity);
	}
   MvcFramework::GetGigPerformerApi().injectMidiMessageToMidiInputDevice(
    GetName(), midiMessage, MIDI_MESSAGE_NOTE_ON_OFF_LENGTH);
   Debug::Log("$ " + GetName() + ": note " + (noteOn ? "on" : "off") +
              ", note number = " + juce::MidiMessage::getMidiNoteName(noteNumber, true, true, 4).toStdString() +
              ", velocity = " + std::to_string(velocity));
}
