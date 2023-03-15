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

    SlidersPane(View &view, Model& model, MixerSubModel &mixerSubModel, OrganSubModel &organSubModel);

    void Fill() override;

    void Update(ChangedProperties::EChangedProperty changedProperty) override;

    void UpdatePropertyMasterLastTimeGate();
    void UpdateWidgetForGateFading(long long ms, ValueWidget &valueWidget);

  private:
    bool IsChannelIndexActive(int channelIndex);

	 void SetChannelVolume(int channelIndex);
    void SetChannelLevelLeft(int channelIndex);
    void SetChannelLevelRight(int channelIndex);
    void SetChannelGate(int channelIndex);

    void SetChannelName(int channelIndex);
    void SetChannelSource(int channelIndex);

	 void CheckGatesFading();

	 Model &_model;
    MixerSubModel &_mixerSubModel;
    OrganSubModel &_organSubModel;

    std::vector<MixerChannelSubModel *> _mixerChannelSubModels;
};
