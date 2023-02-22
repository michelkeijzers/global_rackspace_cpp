#pragma once

#include <memory>
#include "../Model/Mixer.h"

class Controller;
class AudioMixerPlugin;

class MixerController
{
  public:
	  enum class EPaneSelection
    {
		  Drawbars, //TODO: Rename this controller as it also controls drawbars
		  Channels1To8,
		  Channels9To16,
		  Channels17To23,
    };

    MixerController(Controller *controller, std::shared_ptr<AudioMixerPlugin> audioMixerChannel1To16Plugin, 
		 std::shared_ptr<AudioMixerPlugin> audioMixerChannel17To23Plugin);

    void Init();

    void SetChannelVolume(int channelIndex, double volume, bool forced = false);

	 EPaneSelection GetPaneSelection();

	 protected:
		std::shared_ptr<AudioMixerPlugin> GetPluginForChannel(int channelIndex);

  private:
        static const int CHANNELS_IN_MIXER;

    Controller *_controller;
    std::shared_ptr<AudioMixerPlugin> _audioMixerChannel1To16Plugin;
    std::shared_ptr<AudioMixerPlugin> _audioMixerChannel17To23Plugin;

	 EPaneSelection _paneSelection;
};
