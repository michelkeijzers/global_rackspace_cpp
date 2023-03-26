#pragma once

#include "MidiInBlock.h"

class Controller;

class FootBoardMidiInBlock : public MidiInBlock
{
 public:
   FootBoardMidiInBlock(Controller &controller);

 private:
   enum class ECCs
   {
      Switch1 = 0x10, // TODO: Check correct values
      Switch2 = 0x11,
      Switch3 = 0x12,
      Switch4 = 0x13,
      Switch5 = 0x14,
      Switch6 = 0x15,
      Switch7 = 0x16,
      Switch8 = 0x17,
      Switch9 = 0x18,
      Switch0 = 0x19,
      LeftPedal = 94,
      RightPedal = 95,
      Last
   };

   static const int VALUE_BUTTON_PRESSED = 127;
   bool HandleCcMessage(uint8_t ccNumber, uint8_t value);
};
