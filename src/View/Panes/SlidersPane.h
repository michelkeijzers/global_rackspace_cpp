#pragma once

#include "Pane.h"
#include <string>

class Model;
class MixerChannelSubModel;
class MixerSubModel;
class OrganSubModel;
class View;
class ValueWidget;

class SlidersPane : public Pane
{
  public:
    static const int NR_OF_SLIDERS = 9;
    static const int NR_OF_CHANNEL_SLIDERS = NR_OF_SLIDERS - 1;

    SlidersPane(View &view, Model &model, MixerSubModel &mixerSubModel, OrganSubModel &organSubModel);

    void Fill() override;

    void Update(ChangedProperties::EChangedProperty changedProperty) override;

  private:
    void UpdateTab();

    void UpdatePropertyMasterLastTimeGate();
    void UpdateWidgetForGateFading(long long ms, ValueWidget &valueWidget);

    bool IsChannelIndexActive(int channelIndex);

    void UpdateChannelVolume(int channelIndex);
    void UpdateChannelLevelLeft(int channelIndex);
    void UpdateChannelLevelRight(int channelIndex);
    void UpdateChannelGate(int channelIndex);

    void UpdateChannelName(int channelIndex);
    void UpdateChannelSource(int channelIndex);

    void CheckGatesFading();

    Model &_model;
    MixerSubModel &_mixerSubModel;
    OrganSubModel &_organSubModel;

    std::vector<MixerChannelSubModel *> _mixerChannelSubModels;
};
