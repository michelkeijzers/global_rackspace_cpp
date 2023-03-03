#include "MixerSubController.h"
#include "../Model/MixerSubModel.h"
#include "../Model/Model.h"
#include "../Plugins/AudioMixerPlugin.h"
#include "../View/View.h"
#include "../Widgets/Widgets.h"
#include "Controller.h"

/* static */ const int MixerSubController::CHANNELS_IN_MIXER = 16;

MixerSubController::MixerSubController(Controller &controller)
    : SubController(controller), // _paneSelection(EPaneSelection::Channels1To8)
      _mixerSubModel((MixerSubModel&) (GetController().GetModel().GetSubModelById(SubModels::ESubModelId::Mixer)))
{
    SubModel& x = GetController().GetModel().GetSubModelById(SubModels::ESubModelId::Mixer);
}

void MixerSubController::Init()
{
}

void MixerSubController::SetChannelVolume(int channelIndex, double volume, bool forced /* = false */)
{
    if (forced || (fabs(volume - _mixerSubModel.GetChannelVolume(channelIndex)) >
                   0.01)) // TODO: make const (also used in other controllers
    {
        _mixerSubModel.SetChannelVolume(channelIndex, volume);
        // GetPluginForChannel(channelIndex)->SetChannelVolume(channelIndex % CHANNELS_IN_MIXER, volume);
        // if (GetPaneSelection() == EPaneSelection::Channels1To8)
        //{
        //    _controller->GetView()->GetWidgets()->SetWidgetValue(Widgets::EWidgetId::Slider1, volume);
        //}
    }
}

// std::shared_ptr<AudioMixerPlugin> MixerSubController::GetPluginForChannel(int channelIndex)
//{
//    return (channelIndex < CHANNELS_IN_MIXER) ? _audioMixerChannel1To16Plugin : _audioMixerChannel17To23Plugin;
//}

// MixerSubController::EPaneSelection MixerSubController::GetPaneSelection()
//{
//    return _paneSelection;
//}
