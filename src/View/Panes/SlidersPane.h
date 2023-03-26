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
   void Relayout() override;

   void Update(ChangedProperties::EChangedProperty changedProperty) override;

 private:
   void UpdateTab();

   void UpdateTabShowOrganWidgets(bool drawbarsSelected);
   void UpdateTabShowSliders(bool drawbarsSelected);
   void UpdateTabUpdateValues(bool drawbarsSelected);

   void UpdateDrawbar(int drawbarIndex);
   void UpdateOrganDrive();
   void UpdateOrganReverbAmount();

   void UpdateMasterVolume();
   void UpdateMasterLevelLeft();
   void UpdateMasterLevelRight();

	void CheckUpdateChannelLastTimeGateRightActive(int &index, ChangedProperties::EChangedProperty changedProperty);
   void CheckUpdateChannelLastTimeGateLeftActive(int &index, ChangedProperties::EChangedProperty changedProperty);
   void UpdatePropertyMasterLastTimeGate();
   void UpdateWidgetForGateFading(long long ms, ValueWidget &valueWidget);

   bool IsChannelIndexActive(int channelIndex);

   void CheckUpdateMixerChannelVolume(int &index, ChangedProperties::EChangedProperty changedProperty);
   void UpdateMixerChannelVolume(int channelIndex);
   void CheckUpdateMixerChannelLevelLeft(int &index, ChangedProperties::EChangedProperty changedProperty);
   void UpdateMixerChannelLevelLeft(int channelIndex);
   void CheckUpdateMixerChannelLevelRight(int &index, ChangedProperties::EChangedProperty changedProperty);
   void UpdateMixerChannelLevelRight(int channelIndex);
   void UpdateChannelGate(int channelIndex);

   void CheckUpdateChannelName(int &index, ChangedProperties::EChangedProperty changedProperty);
   void UpdateChannelName(int channelIndex);
   void CheckUpdateChannelSource(int &index, ChangedProperties::EChangedProperty changedProperty);
   void UpdateChannelSource(int channelIndex);

   void CheckGatesFading();

   Model &_model;
   MixerSubModel &_mixerSubModel;
   OrganSubModel &_organSubModel;

   std::vector<MixerChannelSubModel *> _mixerChannelSubModels;
};
