#pragma once

#ifdef _CONSOLE
#include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/types.h"
#else
#include "gigperformer/sdk/types.h"
#endif

/* static */ class MidiMessage
{
  public:
    static bool IsChannel1(const uint8_t *data, int length);
    static bool IsCcMessage(const uint8_t *data, int length);

  private:
    MidiMessage();
};