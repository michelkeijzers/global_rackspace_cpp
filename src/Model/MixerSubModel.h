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

	 std::vector<MixerChannelSubModel *> GetMixerChannelSubModels();

	 EPaneSelection GetPaneSelection();
    void SetPaneSelection(EPaneSelection paneSelection);

	 double GetChannelVolume(int channelIndex);
    void SetChannelVolume(int channelIndex, double volume);
     
  private:
    EPaneSelection _paneSelection;
    std::vector<MixerChannelSubModel *> _mixerChannelSubModels;
};
