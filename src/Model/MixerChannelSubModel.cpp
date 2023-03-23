#include <string>
#include "MixerChannelSubModel.h"
#include "SubModels.h"
#include "Model.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"
#include "../Framework/MvcFramework.h"

static std::string SUB_MODEL_NAME = "MixerChannel";

static std::pair<MixerChannelSubModel::EParameters, std::string> SerializationParametersData[] = {
    std::make_pair(MixerChannelSubModel::EParameters::ChannelIndex, "ChannelIndex")
    // TODO: Serialization
};

static std::map<MixerChannelSubModel::EParameters, std::string> SerializationParameters(
    SerializationParametersData,
    SerializationParametersData + sizeof SerializationParametersData / sizeof SerializationParametersData[0]);

MixerChannelSubModel::MixerChannelSubModel(SubModels subModels, int channelIndex)
    : SubModel(subModels), _channelIndex(channelIndex), _volume(0.0), _name(""), _source(ESource::PrimaryKeyboard),
      _levelLeft(0.0), _levelRight(0.0), _lastTimeGateLeftActive(0), _lastTimeGateRightActive(0),
      _isVolumeOverridden(false)
{
    Debug::Assert(SerializationParameters.size() == (int) EParameters::Last, __FUNCTION__,
                  "Serialization parameter names incorrect");
}

const std::string MixerChannelSubModel::GetDebugName() /* override */
{
    return SUB_MODEL_NAME + " " + std::to_string(_channelIndex);
}

std::string MixerChannelSubModel::Serialize() // override
{
    std::string data;
    // TODO Serialization
    return data;
}

void MixerChannelSubModel::Deserialize(std::string data) // override
{
    // TODO Serialization
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
        Debug::Log("# " + GetDebugName() + ", volume = " + std::to_string(_volume));
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
        Debug::Log("# " + GetDebugName() + ", Level Left = " + std::to_string(_levelLeft));
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
        Debug::Log("# " + GetDebugName() + ", level right = " + std::to_string(_levelRight));
        Notify((ChangedProperties::EChangedProperty)((int)ChangedProperties::EChangedProperty::MixerChannel1LevelRight +
                                                     _channelIndex));
    }
}


juce::Time MixerChannelSubModel::GetLastTimeGateLeftActive()
{
    return _lastTimeGateLeftActive;
}

void MixerChannelSubModel::SetGateLeft(bool gateActive)
{
    long long ms = _lastTimeGateLeftActive.toMilliseconds();
    if (IsForcedMode() || ((ms == 0LL) && gateActive) || ((ms != 0LL) && !gateActive))
    {
        if (gateActive)
        {
            _lastTimeGateLeftActive = juce::Time::getCurrentTime();
        }
		  else
		  {
            _lastTimeGateLeftActive = juce::Time(0);
		  }
          Debug::Log("# " + GetDebugName() + ", gate left = " + std::to_string(_lastTimeGateLeftActive.toMilliseconds()));
        Notify((ChangedProperties::EChangedProperty)((int)ChangedProperties::EChangedProperty::MixerChannel1LastTimeGateLeftActive +
                                                     _channelIndex));
    }
}

juce::Time MixerChannelSubModel::GetLastTimeGateRightActive()
{
    return _lastTimeGateRightActive;
}

void MixerChannelSubModel::SetGateRight(bool gateActive)
{
    long long ms = _lastTimeGateRightActive.toMilliseconds();
    if (IsForcedMode() || ((ms == 0LL) && gateActive) || ((ms != 0LL) && !gateActive))
    {
        if (gateActive)
        {
            _lastTimeGateRightActive = juce::Time::getCurrentTime();
        }
        else
        {
            _lastTimeGateRightActive = juce::Time(0);
        }
        Debug::Log("# " + GetDebugName() + ", gate left = " + std::to_string(_lastTimeGateRightActive.toMilliseconds()));
        Notify((ChangedProperties::EChangedProperty)(
            (int)ChangedProperties::EChangedProperty::MixerChannel1LastTimeGateRightActive + _channelIndex));
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
        Debug::Log("# " + GetDebugName() + ", Name = " + name);
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
    case ESource::Off:
        name = "";
        break;

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
    Debug::Log("# " + GetDebugName() + ", source = " + GetSourceName());
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
    Debug::Log("# " + GetDebugName() + ", volume override = " + (IsVolumeOverridden() ? "YES" : "No"));
      Notify((ChangedProperties::EChangedProperty)((int)ChangedProperties::EChangedProperty::Channel1VolumeOverride +
                                                   _channelIndex));
}
