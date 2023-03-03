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
    static const int CC_BUTTON_9 = 90;
    static const int VALUE_BUTTON_PRESSED = 127;

    bool HandleCcMessage(uint8_t ccNumber, uint8_t value);
};
