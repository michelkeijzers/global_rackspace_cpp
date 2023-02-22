#pragma once

#include <memory>
#include <vector>

class MixerChannel;

class Mixer
{
  public:
    static const int NR_OF_MIXER_CHANNELS = 24;

    Mixer();

	 double GetChannelVolume(int channelIndex);
    void SetChannelVolume(int channelIndex, double volume);

  private:
    std::vector<std::shared_ptr<MixerChannel>> _mixerChannels;
};