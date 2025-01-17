#include "MixerSubController.h"
#include "../Model/MixerSubModel.h"
#include "../Model/Model.h"
#include "../Plugins/AudioMixerPlugin.h"
#include "../Utilities/Debug.h"
#include "../Utilities/MidiUtilities.h"
#include "../View/Panes/SlidersPane.h"
#include "../View/View.h"
#include "../Widgets/Widgets.h"
#include "Controller.h"

/* static */ const int MixerSubController::CHANNELS_IN_MIXER = 16;

MixerSubController::MixerSubController(Controller &controller)
    : SubController(controller),
      _mixerSubModel((MixerSubModel &)(GetController().GetModel().GetSubModel(SubModels::ESubModelId::Mixer)))
{
}

void MixerSubController::SetSliderValue(int sliderIndex, double newValue)
{
   if (sliderIndex < SlidersPane::NR_OF_CHANNEL_SLIDERS)
   {
      switch (_mixerSubModel.GetTabSelection())
      {
      case MixerSubModel::ETabSelection::Drawbars:
         // Not possible, invisible
         Debug::Error(__FUNCTION__, "Drawbar pane active, slider selected");
         break;
      case MixerSubModel::ETabSelection::Channels1To8: _mixerSubModel.SetChannelVolume(sliderIndex, newValue); break;
      case MixerSubModel::ETabSelection::Channels9To16:
         _mixerSubModel.SetChannelVolume(1 * (SlidersPane::NR_OF_SLIDERS - 1) + sliderIndex, newValue);
         break;
      case MixerSubModel::ETabSelection::Channels17To24:
         _mixerSubModel.SetChannelVolume(2 * (SlidersPane::NR_OF_SLIDERS - 1) + sliderIndex, newValue);
         break;
      default: Debug::Error(__FUNCTION__, "Illegal tab selection");
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

void MixerSubController::SetChannelLevelLeft(bool master, int channelIndex, double value)
{
   if (master)
   {
      _mixerSubModel.SetMasterLevelLeft(value);
   }
   else
   {
      _mixerSubModel.SetChannelLevelLeft(channelIndex, value);
   }
}

void MixerSubController::SetChannelLevelRight(bool master, int channelIndex, double value)
{
   if (master)
   {
      _mixerSubModel.SetMasterLevelRight(value);
   }
   else
   {
      _mixerSubModel.SetChannelLevelRight(channelIndex, value);
   }
}

void MixerSubController::SetChannelGateLeft(bool master, int channelIndex, bool value)
{
   if (master)
   {
      _mixerSubModel.SetMasterGateLeft(value);
   }
   else
   {
      _mixerSubModel.SetChannelGateLeft(channelIndex, value);
   }
}

void MixerSubController::SetChannelGateRight(bool master, int channelIndex, bool value)
{
   if (master)
   {
      _mixerSubModel.SetMasterGateRight(value);
   }
   else
   {
      _mixerSubModel.SetChannelGateRight(channelIndex, value);
   }
}

void MixerSubController::SetChannelTitles(std::vector<std::string> channelTitles)
{
   Debug::Assert(
    channelTitles.size() == MixerSubModel::NR_OF_MIXER_CHANNELS, __FUNCTION__, "Illegal number of channels names");
   for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
   {
      _mixerSubModel.SetChannelTitle(channelIndex, channelTitles[channelIndex]);
   }
}
