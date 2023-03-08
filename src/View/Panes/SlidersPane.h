#pragma once

#include "Pane.h"
#include <string>

class MixerChannelSubModel;
class MixerSubModel;
class OrganSubModel;
class View;

class SlidersPane : public Pane
{
  public:
    static const int NR_OF_SLIDERS = 9;
    static const int NR_OF_CHANNEL_SLIDERS = NR_OF_SLIDERS - 1;

    SlidersPane(View &view, MixerSubModel &mixerSubModel, OrganSubModel &organSubModel);

    void Fill() override;

    void Update(ChangedProperties::EChangedProperty changedProperty) override;


  private:
    bool IsChannelIndexActive(int channelIndex);

	 void SetChannelVolume(int channelIndex);
    void SetChannelName(int channelIndex);
    void SetChannelSource(int channelIndex);

    MixerSubModel &_mixerSubModel;
    OrganSubModel &_organSubModel;

    std::vector<MixerChannelSubModel *> _mixerChannelSubModels;
};
