#pragma once

#include "../View/Observable.h"
#include "MixerChannelSubModel.h"
#include "SubModel.h"
#include <juce_core/juce_core.h>
#include <juce_core/time/juce_Time.h>
#include <string>

class Model;

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

    MixerChannelSubModel(Model& model, int channelIndex);

    std::string Serialize() override;
    int Deserialize(std::vector<std::string> lines, int currentLineIndex) override;

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
    void SetSource(ESource source);
    void SelectNextSource();

    bool IsVolumeOverridden();
    void SetVolumeOverride(bool isVolumeOverridden);
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
