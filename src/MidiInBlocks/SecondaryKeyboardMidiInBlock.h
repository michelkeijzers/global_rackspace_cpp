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

   bool HandleNoteOffMessage(uint8_t noteNumber, uint8_t velocity) override;
   bool HandleNoteOnMessage(uint8_t noteNumber, uint8_t velocity) override;
   bool HandleCcMessage(uint8_t ccNumber, uint8_t value) override;
};
