#include "AudioMixerPlugin.h"
#include "../Controller/Controller.h"
#include "../Framework/MvcFramework.h"
#include "../Model/MixerSubModel.h"
#include "../Utilities/BoolUtilities.h"
#include "../Utilities/Debug.h"
#include <iostream>

#ifdef TESTER
	#include "../../../JuceTester2/NewProject/Source/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif

const int NR_OF_STEREO_CHANNELS = 16;
const int NR_OF_PARAMETERS_PER_CHANNEL = 7;
const int VOLUME_PARAMETER = 0;

AudioMixerPlugin::AudioMixerPlugin(View &view, MixerSubModel &mixerSubModel, bool lowerChannels,
                                   const std::string &name)
    : Plugin(name, view), _mixerSubModel(mixerSubModel)
{
    for (int channelIndex = lowerChannels ? 0 : NR_OF_STEREO_CHANNELS;
         channelIndex < (lowerChannels ? NR_OF_STEREO_CHANNELS : MixerSubModel::NR_OF_MIXER_CHANNELS); channelIndex++)
    {
        MixerChannelSubModel &mixerChannelSubModel = *_mixerSubModel.GetMixerChannelSubModels()[channelIndex];
        _mixerChannelSubModels.push_back(&mixerChannelSubModel);
        mixerChannelSubModel.Subscribe(*this);
    }

    _mixerSubModel.Subscribe(*this);
}

void AudioMixerPlugin::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
    if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::MixerChannel1Volume) &&
        ((int)changedProperty < (int)ChangedProperties::EChangedProperty::MixerChannel1Volume +
            _mixerChannelSubModels.size()))
    {
        int channelIndex = (int)changedProperty - (int)ChangedProperties::EChangedProperty::MixerChannel1Volume;
        SetChannelVolume(channelIndex % NR_OF_STEREO_CHANNELS);
    }

    else if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::Channel17Name) &&
        ((int)changedProperty <
              (int)ChangedProperties::EChangedProperty::Channel17Name + _mixerChannelSubModels.size()))
    {
        int channelIndex = (int)changedProperty - (int)ChangedProperties::EChangedProperty::Channel17Name;
        SetChannelName(channelIndex % NR_OF_STEREO_CHANNELS);
    }
}

void AudioMixerPlugin::SetChannelVolume(int channelIndex)
{
    double newVolume = _mixerChannelSubModels[channelIndex]->GetVolume();

    MvcFramework::GetGigPerformerApi().setPluginParameter(GetName(), GetChannelVolumeParameter(channelIndex), newVolume,
                                                          true);
    Debug::Log("$ " + GetName() + ": channel volume, channel index = " + std::to_string(channelIndex) +
               ", new volume = " + std::to_string(newVolume));
}

int AudioMixerPlugin::GetChannelVolumeParameter(int channelIndex)
{
    return channelIndex * NR_OF_PARAMETERS_PER_CHANNEL + VOLUME_PARAMETER;
}

void AudioMixerPlugin::SetChannelName(int channelIndex)
{
    const std::string &newName = _mixerChannelSubModels[channelIndex]->GetName();

	 //Not implemented by GP
   // MvcFramework::GetGigPerformerApi().setPluginParameter(GetName(), GetChannelVolumeParameter(channelIndex), newVolume,
    //                                                      true);
    Debug::Log("$ " + GetName() + ": channel name, channel index = " + std::to_string(channelIndex) +
               ", new name = " + newName);
}

