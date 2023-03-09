#pragma once

#include <vector>
#include "MixerChannelSubModel.h"
#include "SubModel.h"
#include "../View/Observable.h"

class SubModels;

class MixerSubModel : public SubModel, public Observable
{
  public:
    static const int NR_OF_MIXER_CHANNELS = 24;

	 enum class EPaneSelection
    {
    	  Drawbars,
    	  Channels1To8,
    	  Channels9To16,
    	  Channels17To23,
    };

    MixerSubModel(SubModels& subModels);
    ~MixerSubModel();

    void Init() override;

	 //TODO: Check if this method should be made protected or remove methods below that interact with individual mixer channel models
	 std::vector<MixerChannelSubModel *> GetMixerChannelSubModels();

	 EPaneSelection GetPaneSelection();
    void SetPaneSelection(EPaneSelection paneSelection);

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


	 bool GetChannelGateLeft(int channelIndex);
    void SetChannelGateLeft(int channelIndex, bool newGate);

	 bool GetChannelGateRight(int channelIndex);
    void SetChannelGateRight(int channelIndex, bool newGate);

    bool GetMasterGateLeft();
    void SetMasterGateLeft(bool newGate);

    bool GetMasterGateRight();
    void SetMasterGateRight(bool newGate);


	 const std::string &GetChannelName(int channelIndex);
    void SetChannelName(int channelIndex, const std::string &channelName);

	 MixerChannelSubModel::ESource GetChannelSource(int channelIndex);
    std::string GetChannelSourceName(int channelIndex);
    void SelectNextChannelSource(int channelIndex);
   
	 bool GetVolumeOverride(int channelIndex);
    void SwapVolumeOverride(int channelIndex);

  private:
    EPaneSelection _paneSelection;
    double _masterVolume;
    double _masterLevelLeft;
    double _masterLevelRight;
	 bool _masterGateLeft;
    bool _masterGateRight;

	 std::vector<MixerChannelSubModel *> _mixerChannelSubModels;
};
