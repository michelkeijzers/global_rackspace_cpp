#pragma once

#include "MidiInBlock.h"

class PrimaryKeyboardMidiInBlock : public MidiInBlock
{
  public:
    PrimaryKeyboardMidiInBlock();

    /* override */ bool OnMidiIn(const uint8_t *data, int length);

  private:
    bool HandleCcMessage(uint8_t ccNumber, uint8_t value);
};
