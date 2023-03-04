#pragma once

#include "Plugin.h"

class MixerSubModel;
class View;

class AudioMixerPlugin : public Plugin
{
  public:
    AudioMixerPlugin(View& view, MixerSubModel& mixerSubModel, bool lowerChannels, const std::string& name);

	 void Init() override;

	 void Update(ChangedProperties::EChangedProperty changedProperty) override;

	 void SetChannelVolume(int channelIndex);

	 private:
     bool IsChannelIndexForThisAudioMixer(int channelIndex);
       
     int GetVolumeOfChannelParameter(int channelIndex);

     MixerSubModel &_mixerSubModel;
     bool _lowerChannels;
};
