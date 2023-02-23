#include "MixerController.h"
#include "../Model/Mixer.h"
#include "../Model/Model.h"
#include "../Plugins/AudioMixerPlugin.h"
#include "../View/View.h"
#include "../Widgets/Widgets.h"
#include "Controller.h"

/* static */ const int MixerController::CHANNELS_IN_MIXER = 16;

MixerController::MixerController(Controller *controller, std::shared_ptr<AudioMixerPlugin> audioMixerChannel1To16Plugin,
                                 std::shared_ptr<AudioMixerPlugin> audioMixerChannel17To23Plugin)
    : _controller(controller), _audioMixerChannel1To16Plugin(audioMixerChannel1To16Plugin),
      _audioMixerChannel17To23Plugin(audioMixerChannel17To23Plugin), _paneSelection(EPaneSelection::Channels1To8)
{
}

void MixerController::Init()
{
}

void MixerController::SetChannelVolume(int channelIndex, double volume, bool forced /* = false */)
{
    Mixer *mixer = _controller->GetModel()->GetMixer();

    if (forced || (fabs(volume - mixer->GetChannelVolume(channelIndex)) > 0.01))  // TODO: make const (also used in other controllers
    {
        mixer->SetChannelVolume(channelIndex, volume);
        GetPluginForChannel(channelIndex)->SetChannelVolume(channelIndex % CHANNELS_IN_MIXER, volume);
        if (GetPaneSelection() == EPaneSelection::Channels1To8)
        {
            _controller->GetView()->GetWidgets()->SetWidgetValue(Widgets::EWidgetId::Slider1, volume);
        }
    }
}

std::shared_ptr<AudioMixerPlugin> MixerController::GetPluginForChannel(int channelIndex)
{
    return (channelIndex < CHANNELS_IN_MIXER) ? _audioMixerChannel1To16Plugin : _audioMixerChannel17To23Plugin;
}

MixerController::EPaneSelection MixerController::GetPaneSelection()
{

    return _paneSelection;
}