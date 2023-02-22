#include "Mixer.h"
#include "../Utilities/Debug.h"
#include "MixerChannel.h"

Mixer::Mixer()
{
    for (int channelIndex = 0; channelIndex < NR_OF_MIXER_CHANNELS; channelIndex++)
    {
        _mixerChannels.push_back(std::make_shared<MixerChannel>());
	 }
}

double Mixer::GetChannelVolume(int channelIndex)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    return _mixerChannels[channelIndex]->GetVolume();
}

void Mixer::SetChannelVolume(int channelIndex, double volume)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    _mixerChannels[channelIndex]->SetVolume(volume);
}
