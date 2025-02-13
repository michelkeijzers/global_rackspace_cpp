#pragma once

#include "../Model/MixerSubModel.h"
#include "SubController.h"
#include <string>
#include <vector>

class Controller;
class AudioMixerPlugin;
class MixerSubModel;

class MixerSubController : public SubController
{
 public:
   MixerSubController(Controller &controller);

   void SetSliderValue(int sliderIndex, double value);
   void SelectNextSource(int channelIndex);
   void SwapVolumeOverride(int channelIndex);

   void SetChannelLevelLeft(bool master, int channelIndex, double value);
   void SetChannelLevelRight(bool master, int channelIndex, double value);
   void SetChannelGateLeft(bool master, int channelIndex, bool value);
   void SetChannelGateRight(bool master, int channelIndex, bool value);

   void SetChannelTitles(std::vector<std::string>);

 private:
   static const int CHANNELS_IN_MIXER;

   MixerSubModel &_mixerSubModel;
};
