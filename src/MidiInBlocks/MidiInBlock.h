#pragma once

#include "../Controller/Controller.h"
#include <string>

class MidiInBlock
{
  public:
    MidiInBlock(Controller *controller);
    MidiInBlock(std::string name);

    virtual bool OnMidiIn(const uint8_t *data, int length) = 0;

    std::string GetName();

    Controller *GetController();

  private:
    std::string _name;

    Controller *_controller;
};
