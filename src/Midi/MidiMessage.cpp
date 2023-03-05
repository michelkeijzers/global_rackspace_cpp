// See https://www.midi.org/specifications-old/item/table-1-summary-of-midi-message

#include "MidiMessage.h"

/* static */ bool MidiMessage::IsChannel1(const uint8_t *data, int length)
{
    return ((length >= 1) && ((data[0] & 0x0F) == 0x00));
}

/* static */ bool MidiMessage::IsCcMessage(const uint8_t *data, int length)
{
    return ((length == 3) && ((data[0] & 0xF0) == 0xB0));
}

 /* static */ double MidiMessage::MidiToParam(uint8_t value)
{
    return (value / 128.0);
}

/* static */ uint8_t MidiMessage::ParamToMidi(double value)
{
    return (uint8_t) (value * 128 + 0.5);
}
