#pragma once

#include "../Controller/Controller.h"
#include <string>

class MidiInBlock
{
  public:
    MidiInBlock(Controller &controller, std::string name);

    virtual void Init() = 0;

    virtual bool OnMidiIn(const uint8_t *data, int length) = 0;

    std::string GetName();

    Controller &GetController();

  private:
    std::string _name;

    Controller &_controller;
};
