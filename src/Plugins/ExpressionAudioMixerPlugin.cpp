#include "ExpressionAudioMixerPlugin.h"
#include "../Controller/Controller.h"
#include "../Framework/MvcFramework.h"
#include "../Model/KeyboardSubModel.h"
#include "../Model/MixerSubModel.h"
#include "../Utilities/BoolUtilities.h"
#include "../Utilities/Debug.h"
#include "../Utilities/MidiUtilities.h"
#include <iostream>

#ifdef TESTER
#include "../../../JuceTester2/NewProject/Builds/VisualStudio2022/Source/GP_API/GigPerformerAPI.h"
#else
#include <gigperformer/sdk/GigPerformerAPI.h>
#endif

// TODO: Duplicate code
const int NR_OF_STEREO_CHANNELS = 16;
const int NR_OF_PARAMETERS_PER_CHANNEL = 7;
const int VOLUME_PARAMETER = 0;

ExpressionAudioMixerPlugin::ExpressionAudioMixerPlugin(View &view, KeyboardSubModel &primaryKeyboardSubModel,
 KeyboardSubModel &secondaryKeyboardSubModel, MixerSubModel &mixerSubModel, bool lowerChannels, const std::string &name)
    : Plugin(name, view), _primaryKeyboardSubModel(primaryKeyboardSubModel),
      _secondaryKeyboardSubModel(secondaryKeyboardSubModel), _mixerSubModel(mixerSubModel),
      _lowerChannels(lowerChannels), _startChannelIndex(lowerChannels ? 0 : NR_OF_STEREO_CHANNELS),
      _endChannelIndex(lowerChannels ? NR_OF_STEREO_CHANNELS : MixerSubModel::NR_OF_MIXER_CHANNELS)
{
   _primaryKeyboardSubModel.Subscribe(*this);
   _secondaryKeyboardSubModel.Subscribe(*this);
   for (int channelIndex = _startChannelIndex; channelIndex < _endChannelIndex; channelIndex++)
   {
      MixerChannelSubModel &mixerChannelSubModel = *_mixerSubModel.GetMixerChannelSubModels()[channelIndex];
      _mixerChannelSubModels.push_back(&mixerChannelSubModel);
      mixerChannelSubModel.Subscribe(*this);
   }
}

void ExpressionAudioMixerPlugin::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
   if (changedProperty == ChangedProperties::EChangedProperty::PrimaryKeyboardExpressionVolume)
   {
      UpdateVolume(true);
   }
   else if (changedProperty == ChangedProperties::EChangedProperty::SecondaryKeyboardExpressionVolume)
   {
      UpdateVolume(false);
   }
   else
   {
      ChangedProperties::EChangedProperty nameStartProperty =
       (_lowerChannels ? ChangedProperties::EChangedProperty::Channel1Name
                       : ChangedProperties::EChangedProperty::Channel17Name);
      int nrOfUsedChannels = GetNrOfUsedChannels();
      int index = ChangedProperties::GetIndexOfChannelNameProperty(changedProperty);
      if ((changedProperty >= nameStartProperty) && (index < nrOfUsedChannels))
      {
         UpdateChannelName(index % NR_OF_STEREO_CHANNELS);
      }
   }
}

void ExpressionAudioMixerPlugin::UpdateVolume(bool primaryKeyboard)
{
   KeyboardSubModel &keyboardSubModel = primaryKeyboard ? _primaryKeyboardSubModel : _secondaryKeyboardSubModel;
   double newVolume = keyboardSubModel.GetExpressionVolume();
   int startChannel = _lowerChannels ? 0 : NR_OF_STEREO_CHANNELS;
   int endChannel = startChannel + GetNrOfUsedChannels();
   for (int channelIndex = startChannel; channelIndex < endChannel; channelIndex++)
   {
      MixerChannelSubModel::ESource source = _mixerSubModel.GetChannelSource(channelIndex);
      if ((primaryKeyboard && ((source == MixerChannelSubModel::ESource::PrimaryKeyboard) ||
                               (source == MixerChannelSubModel::ESource::PrimaryKeyboardPads))) ||
          (!primaryKeyboard && (source == MixerChannelSubModel::ESource::SecondaryKeyboard)))
      {
         MvcFramework::GetGigPerformerApi().setPluginParameter(
          GetName(), GetChannelVolumeParameter(channelIndex % NR_OF_STEREO_CHANNELS), newVolume, true);
      }
   }
}

// TODO: Duplicated code (make common base class with AudioMixerPlugin)
int ExpressionAudioMixerPlugin::GetChannelVolumeParameter(int channelIndex)
{
   return channelIndex * NR_OF_PARAMETERS_PER_CHANNEL + VOLUME_PARAMETER;
}

void ExpressionAudioMixerPlugin::UpdateChannelName(int channelIndex)
{
   const std::string &newName = _mixerChannelSubModels[channelIndex]->GetName();
   // Not implemented by GP
   // MvcFramework::GetGigPerformerApi().setPluginParameter(GetName(), GetChannelVolumeParameter(channelIndex),
   // channelName,
   //                                                      true);
   Debug::Log(
    "$ " + GetName() + ": channel name, channel index = " + std::to_string(channelIndex) + ", new name = " + newName);
}

int ExpressionAudioMixerPlugin::GetNrOfUsedChannels()
{
   return _lowerChannels ? NR_OF_STEREO_CHANNELS : MixerSubModel::NR_OF_MIXER_CHANNELS - NR_OF_STEREO_CHANNELS;
}
