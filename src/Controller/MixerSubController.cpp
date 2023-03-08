#include "MixerSubController.h"
#include "../Model/MixerSubModel.h"
#include "../Model/Model.h"
#include "../Plugins/AudioMixerPlugin.h"
#include "../Utilities/Debug.h"
#include "../View/View.h"
#include "../Widgets/Widgets.h"
#include "Controller.h"
#include "../View/Panes/SlidersPane.h"


/* static */ const int MixerSubController::CHANNELS_IN_MIXER = 16;

MixerSubController::MixerSubController(Controller &controller)
    : SubController(controller), // _paneSelection(EPaneSelection::Channels1To8)
      _mixerSubModel((MixerSubModel &)(GetController().GetModel().GetSubModel(SubModels::ESubModelId::Mixer)))
{
    SubModel &x = GetController().GetModel().GetSubModel(SubModels::ESubModelId::Mixer);
}

void MixerSubController::SetSliderValue(int sliderIndex, double newValue)
{
    if (sliderIndex < SlidersPane::NR_OF_CHANNEL_SLIDERS)
    {
        switch (_mixerSubModel.GetPaneSelection())
        {
        case MixerSubModel::EPaneSelection::Drawbars:
            // Not possible, invisible
            Debug::Error(__FUNCTION__, "Drawbar pane active, slider selected");
            break;

        case MixerSubModel::EPaneSelection::Channels1To8:
            _mixerSubModel.SetChannelVolume(sliderIndex, newValue);
            break;

        case MixerSubModel::EPaneSelection::Channels9To16:
            _mixerSubModel.SetChannelVolume(SlidersPane::NR_OF_SLIDERS - 1 + sliderIndex, newValue);
            break;

        case MixerSubModel::EPaneSelection::Channels17To23:
            _mixerSubModel.SetChannelVolume(2 * (SlidersPane::NR_OF_SLIDERS - 1) + sliderIndex, newValue);
            break;

        default:
            Debug::Error(__FUNCTION__, "Illegal pane selection");
        }
    }
    else
    {
        _mixerSubModel.SetMasterVolume(newValue);
	 }
}

void MixerSubController::SelectNextSource(int channelIndex)
{
    _mixerSubModel.SelectNextChannelSource(channelIndex);
}

void MixerSubController::SwapVolumeOverride(int channelIndex)
{
    _mixerSubModel.SwapVolumeOverride(channelIndex);
}
