#include "AudioMixerplugin.h"
#include "../Controller/Controller.h"
#include "../Utilities/BoolUtilities.h"
#include "../Utilities/Debug.h"
#include <iostream>

const int NR_OF_PARAMETERS_PER_CHANNEL = 7;
const int VOLUME_PARAMETER = 0;

AudioMixerPlugin::AudioMixerPlugin(Controller *controller, bool lowerChannels) 
	: Plugin(lowerChannels ? "AudioMixerChannels1To16" : "AudioMixerChannels17To23", controller)
{
}

void AudioMixerPlugin::SetChannelVolume(int channelIndex, double volume)
{
    Debug::LogMethodEntry(__FUNCTION__,
                          "channelIndex: " + std::to_string(channelIndex) + ", volume = " + std::to_string(volume));

    GetController()->GetGigPerformerAPI()->setPluginParameter(GetName(), GetVolumeOfChannelParameter(channelIndex),
                                                              volume, true);

    Debug::LogMethodExit(__FUNCTION__);
}

int AudioMixerPlugin::GetVolumeOfChannelParameter(int channelIndex)
{
    return channelIndex * NR_OF_PARAMETERS_PER_CHANNEL + VOLUME_PARAMETER;
}