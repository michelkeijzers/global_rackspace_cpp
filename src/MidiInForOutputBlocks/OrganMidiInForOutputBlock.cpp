#include "OrganMidiInForOutputBlock.h"
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

OrganMidiInForOutputBlock::OrganMidiInForOutputBlock(OrganSubModel &organSubModel, const std::string &name)
    : MidiInForOutputBlock(name), _organSubModel(organSubModel)
{
   _organSubModel.Subscribe(*this);
}

void OrganMidiInForOutputBlock::Init()
{
}

void OrganMidiInForOutputBlock::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
   switch (changedProperty)
   {
   case ChangedProperties::EChangedProperty::OrganNotesOff: HandleNoteOff(); break;
   case ChangedProperties::EChangedProperty::OrganNotesOn: HandleNoteOn(); break;
   case ChangedProperties::EChangedProperty::OrganSustained: HandleSustained(); break;
   default:
      // Ignore
      break;
   }
}

void OrganMidiInForOutputBlock::HandleNoteOff()
{
   HandleNoteOnOff(false);
}

void OrganMidiInForOutputBlock::HandleNoteOn()
{
   HandleNoteOnOff(true);
}

void OrganMidiInForOutputBlock::HandleNoteOnOff(bool noteOn)
{
   std::pair<uint8_t, uint8_t> values = _organSubModel.PopNote();
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
   Debug::Log("& " + GetName() + ": note " + (noteOn ? "on" : "off") +
              ", note number = " + juce::MidiMessage::getMidiNoteName(noteNumber, true, true, 4).toStdString() +
              ", velocity = " + std::to_string(velocity));
}

void OrganMidiInForOutputBlock::HandleSustained()
{
   bool sustained = _organSubModel.IsSustained();
   uint8_t midiMessage[MIDI_MESSAGE_CC_LENGTH];
   MidiUtilities::FillCcMessage(
    midiMessage, static_cast<uint8_t>(MidiUtilities::ECCs::Sustain), MidiUtilities::BoolToMidi(sustained));
   MvcFramework::GetGigPerformerApi().injectMidiMessageToMidiInputDevice(
    GetName(), midiMessage, MIDI_MESSAGE_NOTE_ON_OFF_LENGTH);
   Debug::Log(
    "& " + GetName() + ": sustain (" + std::to_string(midiMessage[1]) + ") = " + std::to_string(midiMessage[2]));
}
