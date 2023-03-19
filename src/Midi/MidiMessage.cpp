// See https://www.midi.org/specifications-old/item/table-1-summary-of-midi-message

#include <cmath>
#include "MidiMessage.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"

static const double PARAM_ACCURACY = 0.001;

/* static */ bool MidiMessage::IsChannel1(const uint8_t *data, int length)
{
    Debug::Assert(length > 0, __FUNCTION__, "illegal length");
    return ((length >= 1) && ((data[0] & 0x0F) == 0x00));
}

/* static */ bool MidiMessage::IsCcMessage(const uint8_t *data, int length)
{
    Debug::Assert(length > 0, __FUNCTION__, "illegal length");
    return ((length == 3) && ((data[0] & 0xF0) == 0xB0));
}

 /* static */ double MidiMessage::MidiToParam(uint8_t value)
{
    Debug::Assert(value >= 0, __FUNCTION__, "value too low");
    Debug::Assert(value <= 127, __FUNCTION__, "value too high");
    return static_cast<double>(value) / 127;
}

/* static */ uint8_t MidiMessage::ParamToMidi(double value)
{
    Debug::Assert(DoubleUtilities::AreEqual(value, 0.0) || (value >= 0.0), __FUNCTION__, "value too low");
    Debug::Assert(DoubleUtilities::AreEqual(value, 1.0) || (value <= 1.), __FUNCTION__, "value too high");
    return static_cast<uint8_t>(std::round(value * 127.0f));
}
