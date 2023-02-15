#pragma once

#include <string>

#include "gigperformer/sdk/types.h"

class MidiInBlock
{
  public:
    MidiInBlock();
    MidiInBlock(std::string name);

    virtual bool OnMidiIn(const uint8_t *data, int length) = 0;

    std::string GetName();

  private:
    std::string _name;
};
