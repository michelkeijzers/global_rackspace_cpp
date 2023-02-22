#pragma once

#include "Plugin.h"

class Controller;

class AudioMixerPlugin : public Plugin
{
  public:
    AudioMixerPlugin(Controller *controller, bool lowerChannels);

	 void SetChannelVolume(int channelIndex, double volume);

	 private:
     
     int GetVolumeOfChannelParameter(int channelIndex);
};
