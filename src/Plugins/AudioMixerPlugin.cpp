#include "AudioMixerplugin.h"
#include "../Controller/Controller.h"
#include "../Framework/MvcFramework.h"
#include "../Utilities/BoolUtilities.h"
#include "../Utilities/Debug.h"
#include <iostream>

#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif

const int NR_OF_STEREO_CHANNELS = 16;
const int NR_OF_PARAMETERS_PER_CHANNEL = 7;
const int VOLUME_PARAMETER = 0;

AudioMixerPlugin::AudioMixerPlugin(View &view, MixerSubModel &mixerSubModel, bool lowerChannels,
                                   const std::string &name)
    : Plugin(name, view), _mixerSubModel(mixerSubModel), _lowerChannels(lowerChannels)
{
    _mixerSubModel.Subscribe(*this);
}

void AudioMixerPlugin::Init() /* override */
{
}

void AudioMixerPlugin::SetChannelVolume(int channelIndex)
{
    if (IsChannelIndexForThisAudioMixer(channelIndex))
    {
        double newVolume = _mixerSubModel.GetChannelVolume(channelIndex);
        MvcFramework::GetGigPerformerApi().setPluginParameter(GetName(), GetVolumeOfChannelParameter(channelIndex),
                                                              newVolume, true);
        Debug::Log("$ " + GetName() + ": channel volume, channel index = " + std::to_string(channelIndex) +
                   ", new volume = " + std::to_string(newVolume));
    }
}

void AudioMixerPlugin::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
    if (changedProperty == ChangedProperties::EChangedProperty::MixerChannel1Volume)
    {
        SetChannelVolume(0); // TODO: channels 1..24
    }
}

bool AudioMixerPlugin::IsChannelIndexForThisAudioMixer(int channelIndex)
{
    return ((_lowerChannels && (channelIndex < NR_OF_STEREO_CHANNELS)) ||
            (!_lowerChannels && (channelIndex >= NR_OF_STEREO_CHANNELS)));
}

int AudioMixerPlugin::GetVolumeOfChannelParameter(int channelIndex)
{
    return channelIndex * NR_OF_PARAMETERS_PER_CHANNEL + VOLUME_PARAMETER;
}
