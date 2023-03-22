#pragma once

#include "Plugin.h"
#include <vector>

class KeyboardSubModel;
class MixerSubModel;
class MixerChannelSubModel;
class View;

class ExpressionAudioMixerPlugin : public Plugin
{
  public:
    ExpressionAudioMixerPlugin(View &view, KeyboardSubModel &primaryKeyboardSubModel,
                               KeyboardSubModel &secondaryKeyboardSubModel, MixerSubModel &mixerSubModel,
                               bool lowerChannels, const std::string &name);

    void Update(ChangedProperties::EChangedProperty changedProperty) override;

  private:
    int GetChannelVolumeParameter(int channelIndex);
    void UpdateVolume(bool primaryKeyboard);
    void UpdateChannelName(int channelIndex);
    int GetNrOfUsedChannels();

    KeyboardSubModel &_primaryKeyboardSubModel;
    KeyboardSubModel &_secondaryKeyboardSubModel;
    MixerSubModel &_mixerSubModel;
    std::vector<MixerChannelSubModel *> _mixerChannelSubModels;

    bool _lowerChannels;
    int _startChannelIndex;
    int _endChannelIndex;
};
