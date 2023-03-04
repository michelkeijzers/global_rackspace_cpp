#pragma once

#include "../View/Observable.h"
#include "MixerChannelSubModel.h"
#include "SubModel.h"

class SubModels;

class MixerChannelSubModel : public SubModel, public Observable
{
  public:
    MixerChannelSubModel(SubModels subModels, int channelIndex);

    void Init() override;

    double GetVolume();
    void SetVolume(double volume);

  private:
    int _channelIndex;
    double _volume;
};
