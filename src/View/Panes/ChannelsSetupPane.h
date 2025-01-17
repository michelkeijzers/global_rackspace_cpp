#pragma once

#include "../ChangedProperties.h"
#include "Pane.h"
#include <string>

class MixerSubModel;
class View;

class ChannelsSetupPane : public Pane
{
 public:
   ChannelsSetupPane(View &view, MixerSubModel &mixerSubModel, double leftPercentage,
    double topPercentage, double widthPercentage, double heightPercentage);

   void Fill() override;
   void Relayout() override;

   void Update(ChangedProperties::EChangedProperty changedProperty) override;

   void SetChannelTitle(int channelIndex);
   void SetChannelSource(int channelIndex);
   void SetChannelVolumeOverride(int channelIndex);

 private:
   MixerSubModel &_mixerSubModel;
};
