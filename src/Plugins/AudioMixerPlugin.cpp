#include "AudioMixerplugin.h"
#include "../Controller/Controller.h"
#include "../Utilities/BoolUtilities.h"
#include "../Utilities/Debug.h"
#include <iostream>
#include "../Framework/MvcFramework.h"

#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif

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

    MvcFramework::GetGigPerformerApi()->setPluginParameter(GetName(), GetVolumeOfChannelParameter(channelIndex),
                                                              volume, true);

    Debug::LogMethodExit(__FUNCTION__);
}

int AudioMixerPlugin::GetVolumeOfChannelParameter(int channelIndex)
{
    return channelIndex * NR_OF_PARAMETERS_PER_CHANNEL + VOLUME_PARAMETER;
}