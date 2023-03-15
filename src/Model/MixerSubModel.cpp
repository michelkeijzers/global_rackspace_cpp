#include <string>
#include "MixerSubModel.h"
#include "MixerChannelSubModel.h"
#include "SubModels.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"

static const std::string SUB_MODEL_NAME = "Mixer";

MixerSubModel::MixerSubModel(SubModels &subModels)
    : SubModel(subModels), _masterVolume(0.0), _masterLevelLeft(0.0), _masterLevelRight(0.0), _masterLastTimeGateLeftActive(0),
      _masterLastTimeGateRightActive(0), _paneSelection(MixerSubModel::EPaneSelection::Drawbars)
{
    for (int channelIndex = 0; channelIndex < NR_OF_MIXER_CHANNELS; channelIndex++)
    {
        _mixerChannelSubModels.push_back(new MixerChannelSubModel(subModels, channelIndex));
    }
}

MixerSubModel::~MixerSubModel()
{
    _mixerChannelSubModels.clear();
}

void MixerSubModel::Init() /* override */
{
    for (auto mixerChannelSubModel : _mixerChannelSubModels)
    {
        mixerChannelSubModel->Init();
    }
}

std::vector<MixerChannelSubModel *> MixerSubModel::GetMixerChannelSubModels()
{
    return _mixerChannelSubModels;
}

MixerSubModel::EPaneSelection MixerSubModel::GetPaneSelection()
{
    return _paneSelection;
}

void MixerSubModel::SetPaneSelection(EPaneSelection paneSelection)
{
    if (IsForcedMode() || (_paneSelection != paneSelection))
    {
        _paneSelection = paneSelection;
        Debug::Log("# " + SUB_MODEL_NAME + ": Pane Selection = " + std::to_string((int)_paneSelection));
        Notify(ChangedProperties::EChangedProperty::SlidersPaneSelection);
    }
}

int MixerSubModel::GetChannelOffset()
{
    int channelOffset = -1;
    switch (_paneSelection)
    {
    case MixerSubModel::EPaneSelection::Drawbars:
        // Do nothing
        break;

    case MixerSubModel::EPaneSelection::Channels1To8:
        channelOffset = 0;
        break;

    case MixerSubModel::EPaneSelection::Channels9To16:
        channelOffset = 8;
        break;

    case MixerSubModel::EPaneSelection::Channels17To23:
        channelOffset = 16;
        break;

	 default:
        Debug::Error(__FUNCTION__, "Illegal pane selection");
    }

	 return channelOffset;
}

double MixerSubModel::GetChannelVolume(int channelIndex)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    return _mixerChannelSubModels[channelIndex]->GetVolume();
}

void MixerSubModel::SetChannelVolume(int channelIndex, double newVolume)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    _mixerChannelSubModels[channelIndex]->SetVolume(newVolume);
}

double MixerSubModel::GetMasterVolume()
{
    return _masterVolume;
}

void MixerSubModel::SetMasterVolume(double newVolume)
{
    if (IsForcedMode() || !DoubleUtilities::AreEqual(_masterVolume, newVolume))
    {
        _masterVolume = newVolume;
        Debug::Log("# " + SUB_MODEL_NAME + ": Master Volume = " + std::to_string((int)_masterVolume));
        Notify(ChangedProperties::EChangedProperty::MasterVolume);
    }
}

double MixerSubModel::GetChannelLevelLeft(int channelIndex)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    return _mixerChannelSubModels[channelIndex]->GetLevelLeft();
}

void MixerSubModel::SetChannelLevelLeft(int channelIndex, double newLevel)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    _mixerChannelSubModels[channelIndex]->SetLevelLeft(newLevel);
}

double MixerSubModel::GetChannelLevelRight(int channelIndex)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    return _mixerChannelSubModels[channelIndex]->GetLevelRight();
}

void MixerSubModel::SetChannelLevelRight(int channelIndex, double newLevel)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    _mixerChannelSubModels[channelIndex]->SetLevelRight(newLevel);
}

double MixerSubModel::GetMasterLevelLeft()
{
    return _masterLevelLeft;
}

double MixerSubModel::GetMasterLevelRight()
{
    return _masterLevelRight;
}

void MixerSubModel::SetMasterLevelLeft(double newLevel)
{
    if (IsForcedMode() || !DoubleUtilities::AreEqual(_masterVolume, newLevel))
    {
        _masterLevelLeft = newLevel;
        Debug::Log("# " + SUB_MODEL_NAME + ": Master Level Left = " + std::to_string((int)_masterVolume));
        Notify(ChangedProperties::EChangedProperty::MasterLevelLeft);
    }
}

void MixerSubModel::SetMasterLevelRight(double newLevel)
{
    if (IsForcedMode() || !DoubleUtilities::AreEqual(_masterVolume, newLevel))
    {
        _masterLevelLeft = newLevel;
        Debug::Log("# " + SUB_MODEL_NAME + ": Master Level Right = " + std::to_string((int)_masterVolume));
        Notify(ChangedProperties::EChangedProperty::MasterLevelRight);
    }
}

juce::Time MixerSubModel::GetChannelLastTimeGateLeftActive(int channelIndex)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    return _mixerChannelSubModels[channelIndex]->GetLastTimeGateLeftActive();
}

void MixerSubModel::SetChannelGateLeft(int channelIndex, bool newGate)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    _mixerChannelSubModels[channelIndex]->SetGateLeft(newGate);
}

juce::Time MixerSubModel::GetChannelLastTimeGateRightActive(int channelIndex)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    return _mixerChannelSubModels[channelIndex]->GetLastTimeGateRightActive();
}

void MixerSubModel::SetChannelGateRight(int channelIndex, bool newGate)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    _mixerChannelSubModels[channelIndex]->SetGateRight(newGate);
}

juce::Time MixerSubModel::GetMasterLastTimeGateLeftActive()
{
    return _masterLastTimeGateLeftActive;
}

juce::Time MixerSubModel::GetMasterLastTimeGateRightActive()
{
    return _masterLastTimeGateRightActive;
}

void MixerSubModel::SetMasterGateLeft(bool gateActive)
{
    long long ms = _masterLastTimeGateLeftActive.toMilliseconds();
    if (IsForcedMode() || ((ms == 0) && gateActive) || ((ms != 0) && !gateActive))
    {
        if (gateActive)
        {
            _masterLastTimeGateLeftActive = juce::Time::getCurrentTime();
        }
        else
        {
            _masterLastTimeGateLeftActive = juce::Time(0);
        }
        Debug::Log("# " + SUB_MODEL_NAME + 
                   ", master gate left = " + std::to_string(_masterLastTimeGateLeftActive.toMilliseconds()));
        Notify((ChangedProperties::EChangedProperty)((int)ChangedProperties::EChangedProperty::MasterLastTimeGateLeftActive));
    }
}

void MixerSubModel::SetMasterGateRight(bool gateActive)
{
    long long ms = _masterLastTimeGateRightActive.toMilliseconds();
    if (IsForcedMode() || ((ms == 0) && gateActive) || ((ms != 0) && !gateActive))
    {
        if (gateActive)
        {
            _masterLastTimeGateRightActive = juce::Time::getCurrentTime();
        }
        else
        {
            _masterLastTimeGateRightActive = juce::Time(0);
        }
        Debug::Log("# " + SUB_MODEL_NAME +
                   ", master gate left = " + std::to_string(_masterLastTimeGateRightActive.toMilliseconds()));
        Notify((ChangedProperties::EChangedProperty)(
            (int)ChangedProperties::EChangedProperty::MasterLastTimeGateRightActive));
    }
}

const std::string &MixerSubModel::GetChannelName(int channelIndex)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    return _mixerChannelSubModels[channelIndex]->GetName();
}

void MixerSubModel::SetChannelName(int channelIndex, const std::string &channelName)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    _mixerChannelSubModels[channelIndex]->SetName(channelName);
}

MixerChannelSubModel::ESource MixerSubModel::GetChannelSource(int channelIndex)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    return _mixerChannelSubModels[channelIndex]->GetSource();
}

std::string MixerSubModel::GetChannelSourceName(int channelIndex)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    return _mixerChannelSubModels[channelIndex]->GetSourceName();
}

void MixerSubModel::SelectNextChannelSource(int channelIndex)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    // Always select next, not relevent if IsForcedMode.
    _mixerChannelSubModels[channelIndex]->SelectNextSource();
}

bool MixerSubModel::GetVolumeOverride(int channelIndex)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    return _mixerChannelSubModels[channelIndex]->IsVolumeOverridden();
}

void MixerSubModel::SwapVolumeOverride(int channelIndex)
{
    // Always (independent of current source, and thus also independent of forced modee)

    _mixerChannelSubModels[channelIndex]->SwapVolumeOverride();
}
