#include "MixerChannelSubModel.h"

MixerChannelSubModel::MixerChannelSubModel() : _volume(0.0)
{
}

double MixerChannelSubModel::GetVolume()
{
    return _volume;
}

void MixerChannelSubModel::SetVolume(double volume)
{
    _volume = volume;
}
