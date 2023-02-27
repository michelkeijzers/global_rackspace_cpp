#pragma once

#include <memory>
#include <vector>
#include "MixerChannelSubModel.h"
#include "SubModel.h"

class MixerSubModel : SubModel
{
  public:
    static const int NR_OF_MIXER_CHANNELS = 24;

    MixerSubModel();
    void Init() override;

	 double GetChannelVolume(int channelIndex);
    void SetChannelVolume(int channelIndex, double volume);

  private:
    std::vector<std::shared_ptr<MixerChannelSubModel>> _mixerChannelSubModels;
};