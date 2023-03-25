#pragma once

class ChangedProperties
{
  public:
    enum class EChangedProperty
    {
        PrimaryKeyboardSustainEnabled,
        SecondaryKeyboardSustainEnabled,
        PrimaryKeyboardExpressionVolume,
        SecondaryKeyboardExpressionVolume,

        OrganIsEnabled,
        OrganDrawbar1,
        OrganDrawbar2,
        OrganDrawbar3,
        OrganDrawbar4,
        OrganDrawbar5,
        OrganDrawbar6,
        OrganDrawbar7,
        OrganDrawbar8,
        OrganDrawbar9,
        OrganRotatorSpeed,
        OrganDrive,
        OrganReverbAmount,

        // Setup
        OrganPrimaryKeyboardActive,
        OrganSecondaryKeyboardActive,
        OrganLowestNote,
        OrganHighestNote,
        OrganSustainPedalActive,

        SlidersTabSelection,

        MixerChannel1Volume,
        MixerChannel2Volume,
        MixerChannel3Volume,
        MixerChannel4Volume,
        MixerChannel5Volume,
        MixerChannel6Volume,
        MixerChannel7Volume,
        MixerChannel8Volume,
        MixerChannel9Volume,
        MixerChannel10Volume,
        MixerChannel11Volume,
        MixerChannel12Volume,
        MixerChannel13Volume,
        MixerChannel14Volume,
        MixerChannel15Volume,
        MixerChannel16Volume,
        MixerChannel17Volume,
        MixerChannel18Volume,
        MixerChannel19Volume,
        MixerChannel20Volume,
        MixerChannel21Volume,
        MixerChannel22Volume,
        MixerChannel23Volume,
        MixerChannel24Volume,

        MasterVolume,

        MixerChannel1LevelLeft,
        MixerChannel2LevelLeft,
        MixerChannel3LevelLeft,
        MixerChannel4LevelLeft,
        MixerChannel5LevelLeft,
        MixerChannel6LevelLeft,
        MixerChannel7LevelLeft,
        MixerChannel8LevelLeft,
        MixerChannel9LevelLeft,
        MixerChannel10LevelLeft,
        MixerChannel11LevelLeft,
        MixerChannel12LevelLeft,
        MixerChannel13LevelLeft,
        MixerChannel14LevelLeft,
        MixerChannel15LevelLeft,
        MixerChannel16LevelLeft,
        MixerChannel17LevelLeft,
        MixerChannel18LevelLeft,
        MixerChannel19LevelLeft,
        MixerChannel20LevelLeft,
        MixerChannel21LevelLeft,
        MixerChannel22LevelLeft,
        MixerChannel23LevelLeft,
        MixerChannel24LevelLeft,

        MixerChannel1LevelRight,
        MixerChannel2LevelRight,
        MixerChannel3LevelRight,
        MixerChannel4LevelRight,
        MixerChannel5LevelRight,
        MixerChannel6LevelRight,
        MixerChannel7LevelRight,
        MixerChannel8LevelRight,
        MixerChannel9LevelRight,
        MixerChannel10LevelRight,
        MixerChannel11LevelRight,
        MixerChannel12LevelRight,
        MixerChannel13LevelRight,
        MixerChannel14LevelRight,
        MixerChannel15LevelRight,
        MixerChannel16LevelRight,
        MixerChannel17LevelRight,
        MixerChannel18LevelRight,
        MixerChannel19LevelRight,
        MixerChannel20LevelRight,
        MixerChannel21LevelRight,
        MixerChannel22LevelRight,
        MixerChannel23LevelRight,
        MixerChannel24LevelRight,

        MasterLevelLeft,
        MasterLevelRight,

        MixerChannel1LastTimeGateLeftActive,
        MixerChannel1LastTimeGateRightActive,
        MixerChannel2LastTimeGateLeftActive,
        MixerChannel2LastTimeGateRightActive,
        MixerChannel3LastTimeGateLeftActive,
        MixerChannel3LastTimeGateRightActive,
        MixerChannel4LastTimeGateLeftActive,
        MixerChannel4LastTimeGateRightActive,
        MixerChannel5LastTimeGateLeftActive,
        MixerChannel5LastTimeGateRightActive,
        MixerChannel6LastTimeGateLeftActive,
        MixerChannel6LastTimeGateRightActive,
        MixerChannel7LastTimeGateLeftActive,
        MixerChannel7LastTimeGateRightActive,
        MixerChannel8LastTimeGateLeftActive,
        MixerChannel8LastTimeGateRightActive,
        MixerChannel9LastTimeGateLeftActive,
        MixerChannel9LastTimeGateRightActive,
        MixerChannel10LastTimeGateLeftActive,
        MixerChannel10LastTimeGateRightActive,
        MixerChannel11LastTimeGateLeftActive,
        MixerChannel11LastTimeGateRightActive,
        MixerChannel12LastTimeGateLeftActive,
        MixerChannel12LastTimeGateRightActive,
        MixerChannel13LastTimeGateLeftActive,
        MixerChannel13LastTimeGateRightActive,
        MixerChannel14LastTimeGateLeftActive,
        MixerChannel14LastTimeGateRightActive,
        MixerChannel15LastTimeGateLeftActive,
        MixerChannel15LastTimeGateRightActive,
        MixerChannel16LastTimeGateLeftActive,
        MixerChannel16LastTimeGateRightActive,
        MixerChannel17LastTimeGateLeftActive,
        MixerChannel17LastTimeGateRightActive,
        MixerChannel18LastTimeGateLeftActive,
        MixerChannel18LastTimeGateRightActive,
        MixerChannel19LastTimeGateLeftActive,
        MixerChannel19LastTimeGateRightActive,
        MixerChannel20LastTimeGateLeftActive,
        MixerChannel20LastTimeGateRightActive,
        MixerChannel21LastTimeGateLeftActive,
        MixerChannel21LastTimeGateRightActive,
        MixerChannel22LastTimeGateLeftActive,
        MixerChannel22LastTimeGateRightActive,
        MixerChannel23LastTimeGateLeftActive,
        MixerChannel23LastTimeGateRightActive,
        MixerChannel24LastTimeGateLeftActive,
        MixerChannel24LastTimeGateRightActive,

        MasterLastTimeGateLeftActive,
        MasterLastTimeGateRightActive,

        Channel1Name,
        Channel2Name,
        Channel3Name,
        Channel4Name,
        Channel5Name,
        Channel6Name,
        Channel7Name,
        Channel8Name,
        Channel9Name,
        Channel10Name,
        Channel11Name,
        Channel12Name,
        Channel13Name,
        Channel14Name,
        Channel15Name,
        Channel16Name,
        Channel17Name,
        Channel18Name,
        Channel19Name,
        Channel20Name,
        Channel21Name,
        Channel22Name,
        Channel23Name,
        Channel24Name,

        Channel1Source,
        Channel2Source,
        Channel3Source,
        Channel4Source,
        Channel5Source,
        Channel6Source,
        Channel7Source,
        Channel8Source,
        Channel9Source,
        Channel10Source,
        Channel11Source,
        Channel12Source,
        Channel13Source,
        Channel14Source,
        Channel15Source,
        Channel16Source,
        Channel17Source,
        Channel18Source,
        Channel19Source,
        Channel20Source,
        Channel21Source,
        Channel22Source,
        Channel23Source,
        Channel24Source,

        Channel1VolumeOverride,
        Channel2VolumeOverride,
        Channel3VolumeOverride,
        Channel4VolumeOverride,
        Channel5VolumeOverride,
        Channel6VolumeOverride,
        Channel7VolumeOverride,
        Channel8VolumeOverride,
        Channel9VolumeOverride,
        Channel10VolumeOverride,
        Channel11VolumeOverride,
        Channel12VolumeOverride,
        Channel13VolumeOverride,
        Channel14VolumeOverride,
        Channel15VolumeOverride,
        Channel16VolumeOverride,
        Channel17VolumeOverride,
        Channel18VolumeOverride,
        Channel19VolumeOverride,
        Channel20VolumeOverride,
        Channel21VolumeOverride,
        Channel22VolumeOverride,
        Channel23VolumeOverride,
        Channel24VolumeOverride,

        SecondElapsed,

        Last
    };

    static EChangedProperty GetOrganDrawbarProperty(int organDrawbarIndex);
    static int GetIndexOfOrganDrawbarProperty(EChangedProperty changedProperty);

    static EChangedProperty GetMixerChannelVolumeProperty(int channelIndex);
    static int GetIndexOfMixerChannelVolumeProperty(EChangedProperty changedProperty);

    static EChangedProperty GetMixerChannelLevelLeftProperty(int channelIndex);
    static int GetIndexOfMixerChannelLevelLeftProperty(EChangedProperty changedProperty);

    static EChangedProperty GetMixerChannelLevelRightProperty(int channelIndex);
    static int GetIndexOfMixerChannelLevelRightProperty(EChangedProperty changedProperty);

    static EChangedProperty GetMixerChannel1LastTimeGateLeftActiveProperty(int channelIndex);
    static int GetIndexOfChannelLastTimeGateLeftActiveProperty(EChangedProperty changedProperty);
    
	 static EChangedProperty GetMixerChannel1LastTimeGateRightActiveProperty(int channelIndex);
    static int GetIndexOfChannelLastTimeGateRightActiveProperty(EChangedProperty changedProperty);

    static EChangedProperty GetChannelNameProperty(int channelIndex);
    static int GetIndexOfChannelNameProperty(EChangedProperty changedProperty);

    static EChangedProperty GetChannelSourceProperty(int channelIndex);
    static int GetIndexOfChannelSourceProperty(EChangedProperty changedProperty);

    static EChangedProperty GetChannelVolumeOverrideProperty(int channelIndex);
    static int GetIndexOfChannelVolumeOverrideProperty(EChangedProperty changedProperty);

  private:
    ChangedProperties();
};
