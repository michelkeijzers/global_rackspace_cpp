#pragma once

#include "gigperformer/sdk/types.h"

/* static */ class MidiMessage
{
  public:
    static bool IsChannel1(const uint8_t *data, int length);
    static bool IsCcMessage(const uint8_t *data, int length);

  private:
    MidiMessage();
};