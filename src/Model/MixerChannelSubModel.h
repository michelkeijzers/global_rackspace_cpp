#pragma once

#include "../View/Observable.h"
#include "MixerChannelSubModel.h"
#include "SubModel.h"
#include <juce_core/juce_core.h>
#include <juce_core/time/juce_Time.h>
#include <string>

class SubModels;

class MixerChannelSubModel : public SubModel, public Observable
{
  public:
    enum class ESource
    {
        Off,
        PrimaryKeyboard,
        PrimaryKeyboardPads,
        SecondaryKeyboard,

        Last
    };

    MixerChannelSubModel(SubModels subModels, int channelIndex);

    std::string Serialize() override;
    void Deserialize(std::string data) override;

    double GetVolume();
    void SetVolume(double volume);

    double GetLevelLeft();
    void SetLevelLeft(double level);

    double GetLevelRight();
    void SetLevelRight(double level);

    juce::Time GetLastTimeGateLeftActive();
    void SetGateLeft(bool level);

    juce::Time GetLastTimeGateRightActive();
    void SetGateRight(bool level);

    const std::string GetName();
    void SetName(const std::string &name);

    ESource GetSource();
    std::string GetSourceName();
    void SelectNextSource();

    bool IsVolumeOverridden();
    void SwapVolumeOverride();

    enum class EParameters
    {
        ChannelIndex,
        Volume,
		  Source,
		  IsVolumeOverridden,
		  Last
    };

  private:
    int _channelIndex;
    double _volume;
    double _levelLeft;
    double _levelRight;
    juce::Time _lastTimeGateLeftActive;
    juce::Time _lastTimeGateRightActive;

    std::string _name;
    ESource _source;
    bool _isVolumeOverridden;
};
