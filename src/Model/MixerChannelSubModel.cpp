#include "MixerChannelSubModel.h"
#include "../Utilities/Debug.h"
#include "SubModels.h"
#include <string>

static std::string SUB_MODEL_NAME = "MixerChannel";

MixerChannelSubModel::MixerChannelSubModel(SubModels subModels, int channelIndex)
    : SubModel(subModels), _channelIndex(channelIndex), _volume(0.0), _name(""), _source(ESource::PrimaryKeyboard),
      _volumeIsOverridden(false)
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
        Notify((ChangedProperties::EChangedProperty)((int)ChangedProperties::EChangedProperty::MixerChannel1Volume +
                                                     _channelIndex));
    }
}

const std::string &MixerChannelSubModel::GetName()
{
    return _name;
}

void MixerChannelSubModel::SetName(const std::string &name)
{
    if (IsForcedMode() || (_name != name))
    {
        _name = name;
        Debug::Log("# " + SUB_MODEL_NAME + ": channel index = " + std::to_string(_channelIndex) + ", name = " + name);
        Notify((ChangedProperties::EChangedProperty)((int)ChangedProperties::EChangedProperty::Channel1Name +
                                                     _channelIndex));
    }
}

MixerChannelSubModel::ESource MixerChannelSubModel::GetSource()
{
    return _source;
}

void MixerChannelSubModel::SetSource(ESource source)
{
    if (IsForcedMode() || (_source != source))
    {
        Debug::Log("# " + SUB_MODEL_NAME + ": channel index = " + std::to_string(_channelIndex) +
                   ", source = " + GetSourceAsName());
        Notify((ChangedProperties::EChangedProperty)((int)ChangedProperties::EChangedProperty::Channel1Source +
                                                     _channelIndex));
    }
}

std::string MixerChannelSubModel::GetSourceAsName()
{
    std::string name;
    switch (_source)
    {
    case ESource::PrimaryKeyboard:
        name = "U";
        break;

    case ESource::PrimaryKeyboardPads:
        name = "P";
        break;

    case ESource::SecondaryKeyboard:
        name = "L";
        break;

    default:
        Debug::Error(__FUNCTION__, "Illegal source");
    }

    return name;
}

bool MixerChannelSubModel::IsVolumeOverridden()
{
    return _volumeIsOverridden;
}

void MixerChannelSubModel::SetSource(bool volumeIsOverriden)
{
    if (IsForcedMode() || (_volumeIsOverridden != volumeIsOverriden))
    {
        Debug::Log("# " + SUB_MODEL_NAME + ": channel index = " + std::to_string(_channelIndex) +
                   ", volume override = " + ( IsVolumeOverridden() ? "YES" : "No"));
        Notify((ChangedProperties::EChangedProperty)((int)ChangedProperties::EChangedProperty::Channel1VolumeOverride +
                                                     _channelIndex));
    }
}
