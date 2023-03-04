#include <string>
#include "SubModels.h"
#include "MixerChannelSubModel.h"
#include "../Utilities/Debug.h"

static std::string SUB_MODEL_NAME = "MixerChannel";

MixerChannelSubModel::MixerChannelSubModel(SubModels subModels, int channelIndex)
    : SubModel(subModels),  _channelIndex(channelIndex), _volume(0.0)
{
}

void MixerChannelSubModel::Init() /* override */
{
}

double MixerChannelSubModel::GetVolume()
{
    return _volume;
}

void MixerChannelSubModel::SetVolume(double volume)
{
    if (IsForcedMode() || (_volume != volume))
    {
        _volume = volume;
        Debug::Log("# " + SUB_MODEL_NAME + ": channel index = " + std::to_string(_channelIndex) +
                   ", volume = " + std::to_string(_volume));
        Notify((ChangedProperties::EChangedProperty) 
			  ((int)ChangedProperties::EChangedProperty::MixerChannel1Volume + _channelIndex));
    }
}
