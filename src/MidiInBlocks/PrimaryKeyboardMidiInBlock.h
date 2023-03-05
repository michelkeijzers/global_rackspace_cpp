#pragma once

#include "MidiInBlock.h"

class Controller;

class PrimaryKeyboardMidiInBlock : public MidiInBlock
{
  public:
    PrimaryKeyboardMidiInBlock(Controller &controller);

    void Init() override;

    bool OnMidiIn(const uint8_t *data, int length) override;

  private:
    enum class ECCs
    {
        Button1 = 0x90, // TODO: Check numbers
        Button2 = 0x91,
        Button3 = 0x92,
        Button4 = 0x93,
        Button5 = 0x94,
        Button6 = 0x95,
        Button7 = 0x96,
        Button8 = 0x97,
        Button9 = 0x98,
        Button10 = 0x99,
        Button11 = 0x9A,
        Button12 = 0x9B,
        Button13 = 0x9C,

        Knob1 = 0xA0,
        Knob2 = 0xA1,
        Knob3 = 0xA2,
        Knob4 = 0xA3,
        Knob5 = 0xA4,
        Knob6 = 0xA5,
        Knob7 = 0xA6,
        Knob8 = 0xA7,

        Last
    };

    static const int VALUE_BUTTON_PRESSED = 127;

    bool HandleCcMessage(uint8_t ccNumber, uint8_t value);
};
