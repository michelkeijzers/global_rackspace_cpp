#include "MixerSubModel.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"
#include "MixerChannelSubModel.h"
#include "SubModels.h"
#include <string>

static const std::string SUB_MODEL_NAME = "Mixer";

MixerSubModel::MixerSubModel(SubModels &subModels)
    : SubModel(subModels), _masterVolume(0.0), _masterLevelLeft(0.0), _masterLevelRight(0.0), _masterGateLeft(false),
      _masterGateRight(false), _paneSelection(MixerSubModel::EPaneSelection::Drawbars)
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

bool MixerSubModel::GetChannelGateLeft(int channelIndex)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    return _mixerChannelSubModels[channelIndex]->GetGateLeft();
}

void MixerSubModel::SetChannelGateLeft(int channelIndex, bool newGate)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    _mixerChannelSubModels[channelIndex]->SetGateLeft(newGate);
}

bool MixerSubModel::GetChannelGateRight(int channelIndex)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    return _mixerChannelSubModels[channelIndex]->GetGateRight();
}

void MixerSubModel::SetChannelGateRight(int channelIndex, bool newGate)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    _mixerChannelSubModels[channelIndex]->SetGateRight(newGate);
}

bool MixerSubModel::GetMasterGateLeft()
{
    return _masterGateLeft;
}

bool MixerSubModel::GetMasterGateRight()
{
    return _masterGateRight;
}

void MixerSubModel::SetMasterGateLeft(bool newGate)
{
    if (IsForcedMode() || !DoubleUtilities::AreEqual(_masterVolume, newGate))
    {
        _masterGateLeft = newGate;
        Debug::Log("# " + SUB_MODEL_NAME + ": Master Gate Left = " + std::to_string(_masterGateLeft));
        Notify(ChangedProperties::EChangedProperty::MasterGateLeft);
    }
}

void MixerSubModel::SetMasterGateRight(bool newGate)
{
    if (IsForcedMode() || !DoubleUtilities::AreEqual(_masterVolume, newGate))
    {
        _masterGateLeft = newGate;
        Debug::Log("# " + SUB_MODEL_NAME + ": Master Gate Right = " + std::to_string(_masterGateRight));
        Notify(ChangedProperties::EChangedProperty::MasterGateRight);
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
