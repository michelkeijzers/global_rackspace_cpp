#pragma once

#include "MidiInBlock.h"

class Controller;

class PrimaryKeyboardMidiInBlock : public MidiInBlock
{
 public:
   PrimaryKeyboardMidiInBlock(Controller &controller);

 private:
   enum class ECCs
   {
      ButtonLeft = 0x10, // TODO: Check numbers
      ButtonRight = 0x11,

      Button1 = 0x62,
      Button2 = 0x63,
      Button3 = 0x64,
      Button4 = 0x65,
      Button5 = 0x66,
      Button6 = 0x67,
      Button7 = 0x68,
      Button8 = 0x69,
      Button9 = 0x6A,
      Button10 = 0x99, // TODO: Check numbers
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
   bool HandleNoteOffMessage(uint8_t noteNumber, uint8_t velocity) override;
   bool HandleNoteOnMessage(uint8_t noteNumber, uint8_t velocity) override;
   bool HandleCcMessage(uint8_t ccNumber, uint8_t value) override;
};
