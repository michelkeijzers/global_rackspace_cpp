#pragma once

#include "Plugin.h"

class View;

class AudioMixerPlugin : public Plugin
{
  public:
    AudioMixerPlugin(View& view, bool lowerChannels);

	 void Init() override;

	 void SetChannelVolume(int channelIndex, double volume);

	 private:
     
     int GetVolumeOfChannelParameter(int channelIndex);
};
