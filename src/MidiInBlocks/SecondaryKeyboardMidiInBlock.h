#pragma once

#include "MidiInBlock.h"

class Controller;

class SecondaryKeyboardMidiInBlock : public MidiInBlock
{
  public:
    SecondaryKeyboardMidiInBlock(Controller &controller);

  private:
    enum class ECCs
    {
        Sustain,

        Last
    };

    bool HandleCcMessage(uint8_t ccNumber, uint8_t value);
};
