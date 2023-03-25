#include "MixerChannelSubModel.h"
#include "../Framework/MvcFramework.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"
#include "../Utilities/SerializationUtilities.h"
#include "Model.h"
#include "SubModels.h"
#include <string>

static std::string SUB_MODEL_NAME = "MixerChannel";

static std::pair<MixerChannelSubModel::EParameters, std::string> SerializationParametersData[] = {
    std::make_pair(MixerChannelSubModel::EParameters::ChannelIndex, "ChannelIndex"),
    std::make_pair(MixerChannelSubModel::EParameters::Volume, "Volume"),
    std::make_pair(MixerChannelSubModel::EParameters::Source, "Source"),
    std::make_pair(MixerChannelSubModel::EParameters::IsVolumeOverridden, "IsVolumeOverridden")};

static std::map<MixerChannelSubModel::EParameters, std::string> SerializationParameters(
    SerializationParametersData,
    SerializationParametersData + sizeof SerializationParametersData / sizeof SerializationParametersData[0]);

MixerChannelSubModel::MixerChannelSubModel(SubModels subModels, int channelIndex)
    : SubModel(subModels), _channelIndex(channelIndex), _volume(0.0),
      _name(SUB_MODEL_NAME + " " + std::to_string(channelIndex)), _source(ESource::PrimaryKeyboard), _levelLeft(0.0),
      _levelRight(0.0), _lastTimeGateLeftActive(0), _lastTimeGateRightActive(0), _isVolumeOverridden(false)
{
    Debug::Assert(SerializationParameters.size() == static_cast<int>(EParameters::Last), __FUNCTION__,
                  "Serialization parameter names incorrect");
}

std::string MixerChannelSubModel::Serialize() // override
{
    std::string data;
    data +=
        SerializationUtilities::CreateIntParameter(SerializationParameters[EParameters::ChannelIndex], _channelIndex);
    data += SerializationUtilities::CreateDoubleParameter(SerializationParameters[EParameters::Volume], _volume);
    data += SerializationUtilities::CreateIntParameter(SerializationParameters[EParameters::Source],
                                                       static_cast<int>(_source));
    data += SerializationUtilities::CreateBooleanParameter(SerializationParameters[EParameters::Source],
                                                           _isVolumeOverridden);
    return data;
}

int MixerChannelSubModel::Deserialize(std::vector<std::string> lines, int currentLineIndex) // override
{
    // TODO Serialization
    return 0;
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
        Debug::Log("# " + GetName() + ", volume = " + std::to_string(_volume));
        Notify(ChangedProperties::GetMixerChannelVolumeProperty(_channelIndex));
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
        Debug::Log("# " + GetName() + ", Level Left = " + std::to_string(_levelLeft));
        Notify(ChangedProperties::GetMixerChannelLevelLeftProperty(_channelIndex));
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
        Debug::Log("# " + GetName() + ", level right = " + std::to_string(_levelRight));
        Notify(ChangedProperties::GetMixerChannelLevelRightProperty(_channelIndex));
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
        Debug::Log("# " + GetName() + ", gate left = " + std::to_string(_lastTimeGateLeftActive.toMilliseconds()));
        Notify(ChangedProperties::GetMixerChannel1LastTimeGateLeftActiveProperty(_channelIndex));
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
        Debug::Log("# " + GetName() + ", gate left = " + std::to_string(_lastTimeGateRightActive.toMilliseconds()));
        Notify(ChangedProperties::GetMixerChannel1LastTimeGateRightActiveProperty(_channelIndex));
    }
}

const std::string MixerChannelSubModel::GetName()
{
    return _name;
}

void MixerChannelSubModel::SetName(const std::string &name)
{
    if (IsForcedMode() || (_name != name))
    {
        _name = name;
        Debug::Log("# " + GetName() + ", Name = " + name);
        Notify(ChangedProperties::GetChannelNameProperty(_channelIndex));
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
    _source = static_cast<ESource>((static_cast<int>(_source) + 1) % static_cast<int>(ESource::Last));
    Debug::Log("# " + GetName() + ", source = " + GetSourceName());
    Notify(ChangedProperties::GetChannelSourceProperty(_channelIndex));
}

bool MixerChannelSubModel::IsVolumeOverridden()
{
    return _isVolumeOverridden;
}

void MixerChannelSubModel::SwapVolumeOverride()
{
    _isVolumeOverridden = !_isVolumeOverridden;
    Debug::Log("# " + GetName() + ", volume override = " + (IsVolumeOverridden() ? "YES" : "No"));
    Notify(ChangedProperties::GetChannelVolumeOverrideProperty(_channelIndex));
}
