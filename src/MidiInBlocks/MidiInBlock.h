#pragma once

#include "../Controller/Controller.h"
#include <string>

class MidiInBlock
{
  public:
    MidiInBlock(Controller &controller, const std::string name);
    virtual void Init();

    virtual bool OnMidiIn(const uint8_t *data, int length);
    virtual bool HandleCcMessage(uint8_t ccNumber, uint8_t value) = 0;

    std::string GetName();
    Controller &GetController();

  private:
    std::string _name;
    Controller &_controller;
};
