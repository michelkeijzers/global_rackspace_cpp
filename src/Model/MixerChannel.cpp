#include "MixerChannel.h"

MixerChannel::MixerChannel() : _volume(0.0)
{
}

double MixerChannel::GetVolume()
{
    return _volume;
}

void MixerChannel::SetVolume(double volume)
{
    _volume = volume;
}
