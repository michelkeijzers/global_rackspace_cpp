#pragma once

#include <vector>
#include "MixerChannelSubModel.h"
#include "SubModel.h"

class MixerSubModel : SubModel
{
  public:
    static const int NR_OF_MIXER_CHANNELS = 24;

    MixerSubModel();
    ~MixerSubModel();

    void Init() override;

	 double GetChannelVolume(int channelIndex);
    void SetChannelVolume(int channelIndex, double volume);

  private:
    std::vector<MixerChannelSubModel *> _mixerChannelSubModels;
};
