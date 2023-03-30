// See https://www.midi.org/specifications-old/item/table-1-summary-of-midi-message

#include "MidiUtilities.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"
#include <cmath>

static const double PARAM_ACCURACY = 0.001;

/* static */ void MidiUtilities::FillNoteOnOffMessage(
	uint8_t* data, bool noteOnMessage, uint8_t noteNumber, uint8_t velocity)
{
   Debug::Assert(data != nullptr, __FUNCTION__, "data not initialized");
   Debug::Assert(noteNumber < 128, __FUNCTION__, "noteNumber too big");
   Debug::Assert(velocity < 128, __FUNCTION__, "velocity too big");
   if (data != nullptr)
   {
      data[0] = noteOnMessage ? NOTE_ON_MESSAGE : NOTE_OFF_MESSAGE;
      data[1] = noteNumber;
      data[2] = velocity;
   }
}

/* static */ void MidiUtilities::FillCcMessage(uint8_t *data, uint8_t ccNumber, uint8_t ccValue)
{
   Debug::Assert(data != nullptr, __FUNCTION__, "data not initialized");
   Debug::Assert(ccNumber < 128, __FUNCTION__, "ccNumber too big");
   Debug::Assert(ccValue < 128, __FUNCTION__, "ccValue too big");
   if (data != nullptr)
   {
      data[0] = CC_MESSAGE;
      data[1] = ccNumber;
      data[2] = ccValue;
   }
}

/* static */ bool MidiUtilities::IsChannel1(const uint8_t *data, int length)
{
   Debug::Assert(length > 0, __FUNCTION__, "illegal length");
   return ((length >= 1) && ((data[0] & 0x0F) == 0x00));
}

/* static */ bool MidiUtilities::IsCcMessage(const uint8_t *data, int length)
{
   Debug::Assert(length > 0, __FUNCTION__, "illegal length");
   return ((length == 3) && ((data[0] & 0xF0) == 0xB0));
}

/* static */ bool MidiUtilities::IsNoteOffMessage(const uint8_t *data, int length)
{
   Debug::Assert(length > 0, __FUNCTION__, "illegal length");
   return ((length == 3) && ((data[0] & 0xF0) == 0x80));
}

/* static */ bool MidiUtilities::IsNoteOnMessage(const uint8_t *data, int length)
{
   Debug::Assert(length > 0, __FUNCTION__, "illegal length");
   return ((length == 3) && ((data[0] & 0xF0) == 0x90));
}

/* static */ double MidiUtilities::MidiToParam(uint8_t value)
{
   Debug::Assert(value >= 0, __FUNCTION__, "value too low");
   Debug::Assert(value <= 127, __FUNCTION__, "value too high");
   return static_cast<double>(value) / 127.0;
}

/* static */ bool MidiUtilities::MidiToBool(uint8_t value)
{
   Debug::Assert(value >= 0, __FUNCTION__, "value too low");
   Debug::Assert(value <= 127, __FUNCTION__, "value too high");
   return value >= 64;
}

/* static */ uint8_t MidiUtilities::BoolToMidi(bool value)
{
   return value ? 127 : 0;
}
/* static */ uint8_t MidiUtilities::ParamToMidi(double value)
{
   Debug::Assert(DoubleUtilities::AreEqual(value, 0.0) || (value >= 0.0), __FUNCTION__, "value too low");
   Debug::Assert(DoubleUtilities::AreEqual(value, 1.0) || (value <= 1.), __FUNCTION__, "value too high");
   return static_cast<uint8_t>(std::round(value * 127.0f));
}
