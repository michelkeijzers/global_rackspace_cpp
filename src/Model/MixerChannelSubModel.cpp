#include "MixerChannelSubModel.h"
#include "../Utilities/Debug.h"
#include "SubModels.h"
#include <string>

static std::string SUB_MODEL_NAME = "MixerChannel";

MixerChannelSubModel::MixerChannelSubModel(SubModels subModels, int channelIndex)
    : SubModel(subModels), _channelIndex(channelIndex), _volume(0.0), _name(""), _source(ESource::PrimaryKeyboard),
      _levelLeft(0.0), _levelRight(0.0), _isVolumeOverridden(false)
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

double MixerChannelSubModel::GetLevelLeft()
{
    return _levelLeft;
}

void MixerChannelSubModel::SetLevelLeft(double level)
{
    if (IsForcedMode() || (_levelLeft != level))
    {
        _levelLeft = level;
        Debug::Log("# " + SUB_MODEL_NAME + ": channel index = " + std::to_string(_channelIndex) +
                   ", level left = " + std::to_string(_levelLeft));
        Notify((ChangedProperties::EChangedProperty)((int)ChangedProperties::EChangedProperty::MixerChannel1LevelLeft +
                                                     _channelIndex));
    }
}

double MixerChannelSubModel::GetLevelRight()
{
    return _levelRight;
}

void MixerChannelSubModel::SetLevelRight(double level)
{
    if (IsForcedMode() || (_levelRight != level))
    {
        _levelRight = level;
        Debug::Log("# " + SUB_MODEL_NAME + ": channel index = " + std::to_string(_channelIndex) +
                   ", level right = " + std::to_string(_levelRight));
        Notify((ChangedProperties::EChangedProperty)((int)ChangedProperties::EChangedProperty::MixerChannel1LevelRight +
                                                     _channelIndex));
    }
}


bool MixerChannelSubModel::GetGateLeft()
{
    return _gateLeft;
}

void MixerChannelSubModel::SetGateLeft(bool gate)
{
    if (IsForcedMode() || (_gateLeft != gate))
    {
        _gateLeft = gate;
        Debug::Log("# " + SUB_MODEL_NAME + ": channel index = " + std::to_string(_channelIndex) +
                   ", gate left = " + std::to_string(_gateLeft));
        Notify((ChangedProperties::EChangedProperty)((int)ChangedProperties::EChangedProperty::MixerChannel1GateLeft +
                                                     _channelIndex));
    }
}

bool MixerChannelSubModel::GetGateRight()
{
    return _gateRight;
}

void MixerChannelSubModel::SetGateRight(bool gate)
{
    if (IsForcedMode() || (_gateRight != gate))
    {
        _gateRight = gate;
        Debug::Log("# " + SUB_MODEL_NAME + ": channel index = " + std::to_string(_channelIndex) +
                   ", gate right = " + std::to_string(_gateRight));
        Notify((ChangedProperties::EChangedProperty)((int)ChangedProperties::EChangedProperty::MixerChannel1GateRight +
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


std::string MixerChannelSubModel::GetSourceName()
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

void MixerChannelSubModel::SelectNextSource()
{
    _source = (ESource)(((int)_source + 1) % (int)ESource::Last);
    Debug::Log("# " + SUB_MODEL_NAME + ": channel index = " + std::to_string(_channelIndex) +
               ", source = " + GetSourceName());
    Notify((ChangedProperties::EChangedProperty)((int)ChangedProperties::EChangedProperty::Channel1Source +
                                                 _channelIndex));
}

bool MixerChannelSubModel::IsVolumeOverridden()
{
    return _isVolumeOverridden;
}

void MixerChannelSubModel::SwapVolumeOverride()
{
      _isVolumeOverridden = !_isVolumeOverridden;
      Debug::Log("# " + SUB_MODEL_NAME + ": channel index = " + std::to_string(_channelIndex) +
                  ", volume override = " + (IsVolumeOverridden() ? "YES" : "No"));
      Notify((ChangedProperties::EChangedProperty)((int)ChangedProperties::EChangedProperty::Channel1VolumeOverride +
                                                   _channelIndex));
}
