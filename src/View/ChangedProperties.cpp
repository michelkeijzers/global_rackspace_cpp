#include "ChangedProperties.h"
#include "../Model/MixerSubModel.h"
#include "../Model/OrganSubModel.h"
#include "../Utilities/Debug.h"

/* static */ ChangedProperties::EChangedProperty ChangedProperties::GetOrganDrawbarProperty(int organDrawbarIndex)
{
   Debug::Assert(organDrawbarIndex >= 0, __FUNCTION__, "organDrawbarIndex too low");
   Debug::Assert(organDrawbarIndex <= OrganSubModel::NR_OF_DRAWBARS, __FUNCTION__, "organDrawbarIndexx too high");
   return static_cast<EChangedProperty>(static_cast<int>(EChangedProperty::OrganDrawbar1) + organDrawbarIndex);
}

/* static */ int ChangedProperties::GetIndexOfOrganDrawbarProperty(EChangedProperty changedProperty)
{
   return static_cast<int>(changedProperty) - static_cast<int>(ChangedProperties::EChangedProperty::OrganDrawbar1);
}

/* static */ ChangedProperties::EChangedProperty ChangedProperties::GetMixerChannelVolumeProperty(int channelIndex)
{
   Debug::Assert(channelIndex >= 0, __FUNCTION__, "channelIndex too low");
   Debug::Assert(channelIndex <= MixerSubModel::NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex too high");
   return static_cast<EChangedProperty>(static_cast<int>(EChangedProperty::MixerChannel1Volume) + channelIndex);
}

/* static */ int ChangedProperties::GetIndexOfMixerChannelVolumeProperty(EChangedProperty changedProperty)
{
   return static_cast<int>(changedProperty) -
          static_cast<int>(ChangedProperties::EChangedProperty::MixerChannel1Volume);
}

/* static */ ChangedProperties::EChangedProperty ChangedProperties::GetMixerChannelLevelLeftProperty(int channelIndex)
{
   Debug::Assert(channelIndex >= 0, __FUNCTION__, "channelIndex too low");
   Debug::Assert(channelIndex <= MixerSubModel::NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex too high");
   return static_cast<EChangedProperty>(static_cast<int>(EChangedProperty::MixerChannel1LevelLeft) + channelIndex);
}

/* static */ int ChangedProperties::GetIndexOfMixerChannelLevelLeftProperty(EChangedProperty changedProperty)
{
   return static_cast<int>(changedProperty) -
          static_cast<int>(ChangedProperties::EChangedProperty::MixerChannel1LevelLeft);
}

/* static */ ChangedProperties::EChangedProperty ChangedProperties::GetMixerChannelLevelRightProperty(int channelIndex)
{
   Debug::Assert(channelIndex >= 0, __FUNCTION__, "channelIndex too low");
   Debug::Assert(channelIndex <= MixerSubModel::NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex too high");
   return static_cast<EChangedProperty>(static_cast<int>(EChangedProperty::MixerChannel1LevelRight) + channelIndex);
}

/* static */ int ChangedProperties::GetIndexOfMixerChannelLevelRightProperty(EChangedProperty changedProperty)
{
   return static_cast<int>(changedProperty) -
          static_cast<int>(ChangedProperties::EChangedProperty::MixerChannel1LevelRight);
}

/* static */ ChangedProperties::EChangedProperty ChangedProperties::GetMixerChannel1LastTimeGateLeftActiveProperty(
 int channelIndex)
{
   Debug::Assert(channelIndex >= 0, __FUNCTION__, "channelIndex too low");
   Debug::Assert(channelIndex <= MixerSubModel::NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex too high");
   return static_cast<EChangedProperty>(
    static_cast<int>(EChangedProperty::MixerChannel1LastTimeGateLeftActive) + channelIndex);
}

/* static */ int ChangedProperties::GetIndexOfChannelLastTimeGateLeftActiveProperty(EChangedProperty changedProperty)
{
   return static_cast<int>(changedProperty) -
          static_cast<int>(ChangedProperties::EChangedProperty::MixerChannel1LastTimeGateLeftActive);
}

/* static */ ChangedProperties::EChangedProperty ChangedProperties::GetMixerChannel1LastTimeGateRightActiveProperty(
 int channelIndex)
{
   Debug::Assert(channelIndex >= 0, __FUNCTION__, "channelIndex too low");
   Debug::Assert(channelIndex <= MixerSubModel::NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex too high");
   return static_cast<EChangedProperty>(
    static_cast<int>(EChangedProperty::MixerChannel1LastTimeGateRightActive) + channelIndex);
}

/* static */ int ChangedProperties::GetIndexOfChannelLastTimeGateRightActiveProperty(EChangedProperty changedProperty)
{
   return static_cast<int>(changedProperty) -
          static_cast<int>(ChangedProperties::EChangedProperty::MixerChannel1LastTimeGateRightActive);
}

/* static */ ChangedProperties::EChangedProperty ChangedProperties::GetChannelNameProperty(int channelIndex)
{
   Debug::Assert(channelIndex >= 0, __FUNCTION__, "channelIndex too low");
   Debug::Assert(channelIndex <= MixerSubModel::NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex too high");
   return static_cast<EChangedProperty>(static_cast<int>(EChangedProperty::Channel1Name) + channelIndex);
}

/* static */ int ChangedProperties::GetIndexOfChannelNameProperty(EChangedProperty changedProperty)
{
   return static_cast<int>(changedProperty) - static_cast<int>(ChangedProperties::EChangedProperty::Channel1Name);
}

/* static */ ChangedProperties::EChangedProperty ChangedProperties::GetChannelTitleProperty(int channelIndex)
{
   Debug::Assert(channelIndex >= 0, __FUNCTION__, "channelIndex too low");
   Debug::Assert(channelIndex <= MixerSubModel::NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex too high");
   return static_cast<EChangedProperty>(static_cast<int>(EChangedProperty::Channel1Title) + channelIndex);
}

/* static */ int ChangedProperties::GetIndexOfChannelTitleProperty(EChangedProperty changedProperty)
{
   return static_cast<int>(changedProperty) - static_cast<int>(ChangedProperties::EChangedProperty::Channel1Title);
}

/* static */ ChangedProperties::EChangedProperty ChangedProperties::GetChannelSourceProperty(int channelIndex)
{
   Debug::Assert(channelIndex >= 0, __FUNCTION__, "channelIndex too low");
   Debug::Assert(channelIndex <= MixerSubModel::NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex too high");
   return static_cast<EChangedProperty>(static_cast<int>(EChangedProperty::Channel1Source) + channelIndex);
}

/* static */ int ChangedProperties::GetIndexOfChannelSourceProperty(EChangedProperty changedProperty)
{
   return static_cast<int>(changedProperty) - static_cast<int>(ChangedProperties::EChangedProperty::Channel1Source);
}

/* static */ ChangedProperties::EChangedProperty ChangedProperties::GetChannelVolumeOverrideProperty(int channelIndex)
{
   Debug::Assert(channelIndex >= 0, __FUNCTION__, "channelIndex too low");
   Debug::Assert(channelIndex <= MixerSubModel::NR_OF_MIXER_CHANNELS, __FUNCTION__, "channelIndex too high");
   return static_cast<EChangedProperty>(static_cast<int>(EChangedProperty::Channel1VolumeOverride) + channelIndex);
}

/* static */ int ChangedProperties::GetIndexOfChannelVolumeOverrideProperty(EChangedProperty changedProperty)
{
   return static_cast<int>(changedProperty) -
          static_cast<int>(ChangedProperties::EChangedProperty::Channel1VolumeOverride);
}
