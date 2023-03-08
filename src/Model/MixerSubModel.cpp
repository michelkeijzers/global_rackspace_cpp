#include <string>
#include "MixerSubModel.h"
#include "MixerChannelSubModel.h"
#include "SubModels.h"
#include "../Utilities/Debug.h"
#include "../Utilities/DoubleUtilities.h"


static const std::string SUB_MODEL_NAME = "Mixer";

MixerSubModel::MixerSubModel(SubModels &subModels)
    : SubModel(subModels), _masterVolume(0.0), _paneSelection(MixerSubModel::EPaneSelection::Drawbars)
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

double MixerSubModel::GetChannelVolume(int channelIndex)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    return _mixerChannelSubModels[channelIndex]->GetVolume();
}

void MixerSubModel::SetChannelVolume(int channelIndex, double newVolume)
{
    Debug::Assert(channelIndex < NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex out of range");

    if (IsForcedMode() || !DoubleUtilities::AreEqual(_mixerChannelSubModels[channelIndex]->GetVolume(), newVolume))
    {
        _mixerChannelSubModels[channelIndex]->SetVolume(newVolume);
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

    if (IsForcedMode() || (_mixerChannelSubModels[channelIndex]->GetName() != channelName))
    {
        _mixerChannelSubModels[channelIndex]->SetName(channelName);
    }
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

void MixerSubModel::SetVolumeOverride(int channelIndex, bool volumeOverride)
{
    // Always (independent of current source, and thus also independent of forced modee)

	_mixerChannelSubModels[channelIndex]->SetVolumeOverride(volumeOverride);
}
