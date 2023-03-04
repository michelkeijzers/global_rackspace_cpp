#pragma once

#include "../Model/MixerSubModel.h"
#include "SubController.h"

class Controller;
class AudioMixerPlugin;
class MixerSubModel;

class MixerSubController : public SubController
{
  public:
    MixerSubController(Controller &controller);

    void Init() override;

    void SetSliderValue(int sliderIndex, double value);

    // protected:
    //	std::shared_ptr<AudioMixerPlugin> GetPluginForChannel(int channelIndex);

  private:
    static const int CHANNELS_IN_MIXER;

    MixerSubModel &_mixerSubModel;
};
