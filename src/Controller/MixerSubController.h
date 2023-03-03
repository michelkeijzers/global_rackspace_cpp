#pragma once

#include "../Model/MixerSubModel.h"
#include "SubController.h"

class Controller;
class AudioMixerPlugin;
class MixerSubModel;

class MixerSubController : public SubController
{
  public:
    //  enum class EPaneSelection
    //{
    //	  Drawbars, //TODO: Rename this controller as it also controls drawbars
    //	  Channels1To8,
    //	  Channels9To16,
    //	  Channels17To23,
    //};

    MixerSubController(Controller &controller);

    void Init();

    void SetChannelVolume(int channelIndex, double volume, bool forced = false);

    // EPaneSelection GetPaneSelection();

    // protected:
    //	std::shared_ptr<AudioMixerPlugin> GetPluginForChannel(int channelIndex);

  private:
    static const int CHANNELS_IN_MIXER;

    MixerSubModel &_mixerSubModel;
    // EPaneSelection _paneSelection;
};
