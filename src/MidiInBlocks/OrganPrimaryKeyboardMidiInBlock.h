#pragma once

#include "MidiInBlock.h"

class Controller;

class OrganPrimaryKeyboardMidiInBlock : public MidiInBlock
{
 public:
   OrganPrimaryKeyboardMidiInBlock(Controller &controller);

 private:
   bool HandleCcMessage(uint8_t ccNumber, uint8_t value);
};
