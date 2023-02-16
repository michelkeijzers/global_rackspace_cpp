#pragma once

#include <string>

#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/types.h"
#else
    #include "gigperformer/sdk/types.h"
#endif

#include "../Controller/Controller.h"

class MidiInBlock
{
  public:
    MidiInBlock(Controller* controller);
    MidiInBlock(std::string name);

    virtual bool OnMidiIn(const uint8_t *data, int length) = 0;

    std::string GetName();

	 Controller* GetController();

  private:
    std::string _name;

	 Controller* _controller;
};
