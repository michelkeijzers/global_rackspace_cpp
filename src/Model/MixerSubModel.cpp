#include "MixerSubModel.h"
#include "../Utilities/Debug.h"
#include "MixerChannelSubModel.h"

MixerSubModel::MixerSubModel()
{
    for (int channelIndex = 0; channelIndex < NR_OF_MIXER_CHANNELS; channelIndex++)
    {
        _mixerChannelSubModels.push_back(new MixerChannelSubModel());
	 }
}

MixerSubModel::~MixerSubModel()
{
    _mixerChannelSubModels.clear();
}

void MixerSubModel::Init() /* override */ 
{
}

double MixerSubModel::GetChannelVolume(int channelIndex)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    return _mixerChannelSubModels[channelIndex]->GetVolume();
}

void MixerSubModel::SetChannelVolume(int channelIndex, double volume)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    _mixerChannelSubModels[channelIndex]->SetVolume(volume);
}
