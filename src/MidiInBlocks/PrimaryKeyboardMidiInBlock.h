#pragma once

#include <memory>
#include "MidiInBlock.h"

class Controller;

class PrimaryKeyboardMidiInBlock : public MidiInBlock
{
  public:
    PrimaryKeyboardMidiInBlock(Controller* controller);

    /* override */ bool OnMidiIn(const uint8_t *data, int length);

  private:
    bool HandleCcMessage(uint8_t ccNumber, uint8_t value);
};
