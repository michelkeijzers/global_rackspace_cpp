#pragma once

#include "Pane.h"
#include <string>

class MixerChannelSubModel;
class MixerSubModel;
class View;

class SlidersPane : public Pane
{
  public:
    static const int NR_OF_SLIDERS = 9;
    static const int NR_OF_CHANNEL_SLIDERS = NR_OF_SLIDERS - 1;

    SlidersPane(View &view, MixerSubModel &mixerSubModel);

    void Init() override;
    void Fill() override;

    void Update(ChangedProperties::EChangedProperty changedProperty) override;

	 void SetChannelVolume(int channelIndex);

  private:
    MixerSubModel &_mixerSubModel;

	 std::vector<MixerChannelSubModel *> _mixerChannelSubModels;
};
