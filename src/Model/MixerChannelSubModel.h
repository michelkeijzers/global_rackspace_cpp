#pragma once

#include "MixerChannelSubModel.h"

class MixerChannelSubModel
{
  public:
    MixerChannelSubModel();

    double GetVolume();
    void SetVolume(double volume);

  private:
    double _volume;
};