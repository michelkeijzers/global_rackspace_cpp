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

	 double GetMasterVolume();
    void SetMasterVolume(double newVolume);

    double GetChannelVolume(int channelIndex);
    void SetChannelVolume(int channelIndex, double newVolume);

	 const std::string& GetChannelName(int channelIndex);
    void SetChannelName(int channelIndex, const std::string &channelName);

	 MixerChannelSubModel::ESource GetChannelSource(int channelIndex);
    std::string GetChannelSourceName(int channelIndex);
    void SelectNextChannelSource(int channelIndex);
   
	 bool GetVolumeOverride(int channelIndex);
    void SwapVolumeOverride(int channelIndex);

  private:
    EPaneSelection _paneSelection;
    double _masterVolume;

	 std::vector<MixerChannelSubModel *> _mixerChannelSubModels;
};
