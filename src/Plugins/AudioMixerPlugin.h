#pragma once

#include "Plugin.h"
#include <vector>

class MixerChannelSubModel;
class MixerSubModel;
class View;

class AudioMixerPlugin : public Plugin
{
  public:
    AudioMixerPlugin(View &view, MixerSubModel &mixerSubModel, bool lowerChannels, const std::string &name);

    void Update(ChangedProperties::EChangedProperty changedProperty) override;

    void UpdateChannelVolume(int channelIndex);
    void UpdateChannelName(int channelIndex);

  private:
    int GetChannelVolumeParameter(int channelIndex);

    MixerSubModel &_mixerSubModel;
    std::vector<MixerChannelSubModel *> _mixerChannelSubModels;

    bool _lowerChannels;
    int _startChannelIndex;
    int _endChannelIndex;
};
