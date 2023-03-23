#pragma once

#include "../View/Observable.h"
#include "MixerChannelSubModel.h"
#include "SubModel.h"
#include <vector>

class SubModels;

class MixerSubModel : public SubModel, public Observable
{
  public:
    static const int NR_OF_MIXER_CHANNELS = 24;

    enum class ETabSelection
    {
        Drawbars,
        Channels1To8,
        Channels9To16,
        Channels17To24,
        Last
    };

    MixerSubModel(SubModels &subModels);
    ~MixerSubModel();
    void Init() override;
    const std::string& GetName() override;

    std::string Serialize() override;
    void Deserialize(std::string data) override;

    // TODO: Check if this method should be made protected or remove methods below that interact with individual mixer
    // channel models
    std::vector<MixerChannelSubModel *> GetMixerChannelSubModels();

    ETabSelection GetTabSelection();
    void SetTabSelection(ETabSelection tabSelection);
    void SetNextTab();

    /// <summary>
    /// Returns -1 if not in a channel mode
    /// </summary>
    /// <returns></returns>
    int GetChannelOffset();

    double GetChannelVolume(int channelIndex);
    void SetChannelVolume(int channelIndex, double newVolume);

    double GetMasterVolume();
    void SetMasterVolume(double newVolume);

    double GetChannelLevelLeft(int channelIndex);
    void SetChannelLevelLeft(int channelIndex, double newLevel);

    double GetChannelLevelRight(int channelIndex);
    void SetChannelLevelRight(int channelIndex, double newLevel);

    double GetMasterLevelLeft();
    void SetMasterLevelLeft(double newVolume);

    double GetMasterLevelRight();
    void SetMasterLevelRight(double newVolume);

    juce::Time GetChannelLastTimeGateLeftActive(int channelIndex);
    void SetChannelGateLeft(int channelIndex, bool newGate);

    juce::Time GetChannelLastTimeGateRightActive(int channelIndex);
    void SetChannelGateRight(int channelIndex, bool newGate);

    juce::Time GetMasterLastTimeGateLeftActive();
    void SetMasterGateLeft(bool newGate);

    juce::Time GetMasterLastTimeGateRightActive();
    void SetMasterGateRight(bool newGate);

    const std::string &GetChannelName(int channelIndex);
    void SetChannelName(int channelIndex, const std::string &channelName);

    MixerChannelSubModel::ESource GetChannelSource(int channelIndex);
    std::string GetChannelSourceName(int channelIndex);
    void SelectNextChannelSource(int channelIndex);

    bool GetVolumeOverride(int channelIndex);
    void SwapVolumeOverride(int channelIndex);

    enum class EParameters
    {
        TabSelection,
        // TODO: Serialization
		  Last
    };

  private:
    ETabSelection _tabSelection;
    double _masterVolume;
    double _masterLevelLeft;
    double _masterLevelRight;
    juce::Time _masterLastTimeGateLeftActive;
    juce::Time _masterLastTimeGateRightActive;

    std::vector<MixerChannelSubModel *> _mixerChannelSubModels;
};
