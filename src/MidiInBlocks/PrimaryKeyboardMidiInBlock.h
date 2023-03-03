#pragma once

#include "MidiInBlock.h"

class Controller;

class PrimaryKeyboardMidiInBlock : public MidiInBlock
{
  public:
    PrimaryKeyboardMidiInBlock(Controller& controller);

	 void Init() override;

    bool OnMidiIn(const uint8_t *data, int length) override;

  private:
    bool HandleCcMessage(uint8_t ccNumber, uint8_t value);
};
