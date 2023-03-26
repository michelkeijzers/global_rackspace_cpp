#pragma once

#include <map>
#include <string>
#include <vector>

class WidgetIds
{
 public:
   enum class EWidgetId
   {
      // Slider pane
      OrganDrawbar1,
      OrganDrawbar2,
      OrganDrawbar3,
      OrganDrawbar4,
      OrganDrawbar5,
      OrganDrawbar6,
      OrganDrawbar7,
      OrganDrawbar8,
      OrganDrawbar9,

      PrimaryKeyboardSliderBox1,
      PrimaryKeyboardSliderBox2,
      PrimaryKeyboardSliderBox3,
      PrimaryKeyboardSliderBox4,
      PrimaryKeyboardSliderBox5,
      PrimaryKeyboardSliderBox6,
      PrimaryKeyboardSliderBox7,
      PrimaryKeyboardSliderBox8,
      PrimaryKeyboardSliderBox9,

      PrimaryKeyboardSlider1,
      PrimaryKeyboardSlider2,
      PrimaryKeyboardSlider3,
      PrimaryKeyboardSlider4,
      PrimaryKeyboardSlider5,
      PrimaryKeyboardSlider6,
      PrimaryKeyboardSlider7,
      PrimaryKeyboardSlider8,
      PrimaryKeyboardSlider9,

      PrimaryKeyboardSlider1LevelLeft,
      PrimaryKeyboardSlider2LevelLeft,
      PrimaryKeyboardSlider3LevelLeft,
      PrimaryKeyboardSlider4LevelLeft,
      PrimaryKeyboardSlider5LevelLeft,
      PrimaryKeyboardSlider6LevelLeft,
      PrimaryKeyboardSlider7LevelLeft,
      PrimaryKeyboardSlider8LevelLeft,
      PrimaryKeyboardSlider9LevelLeft,

      PrimaryKeyboardSlider1LevelRight,
      PrimaryKeyboardSlider2LevelRight,
      PrimaryKeyboardSlider3LevelRight,
      PrimaryKeyboardSlider4LevelRight,
      PrimaryKeyboardSlider5LevelRight,
      PrimaryKeyboardSlider6LevelRight,
      PrimaryKeyboardSlider7LevelRight,
      PrimaryKeyboardSlider8LevelRight,
      PrimaryKeyboardSlider9LevelRight,

      PrimaryKeyboardSlider1Name,
      PrimaryKeyboardSlider2Name,
      PrimaryKeyboardSlider3Name,
      PrimaryKeyboardSlider4Name,
      PrimaryKeyboardSlider5Name,
      PrimaryKeyboardSlider6Name,
      PrimaryKeyboardSlider7Name,
      PrimaryKeyboardSlider8Name,
      PrimaryKeyboardSlider9Name,

      PrimaryKeyboardSlider1SourceName,
      PrimaryKeyboardSlider2SourceName,
      PrimaryKeyboardSlider3SourceName,
      PrimaryKeyboardSlider4SourceName,
      PrimaryKeyboardSlider5SourceName,
      PrimaryKeyboardSlider6SourceName,
      PrimaryKeyboardSlider7SourceName,
      PrimaryKeyboardSlider8SourceName,
      PrimaryKeyboardSlider9SourceName,

      // Organ pane
      OrganPaneBox,
		OrganPaneTitleTextLabel,
      OrganRotatorSpeedTextLabel,
      OrganDriveTextLabel,
      OrganReverbAmountTextLabel,

      // Primary Keyboard Buttons pane
      PrimaryKeyboardButton1,
      PrimaryKeyboardButton2,
      PrimaryKeyboardButton3,
      PrimaryKeyboardButton4,
      PrimaryKeyboardButton5,
      PrimaryKeyboardButton6,
      PrimaryKeyboardButton7,
      PrimaryKeyboardButton8,
      PrimaryKeyboardButton9,
      PrimaryKeyboardButton10,
      PrimaryKeyboardButton11,
      PrimaryKeyboardButton12,
      PrimaryKeyboardButton13,

      LeftFootPedal,
      RightFootPedal,

      // Channels Setup pane
      SyncLabelsToMixerButton,
      ChannelIndexTextLabel,
      NextSourceTextLabel,
      VolumeOverrideTextLabel,

      SetupChannel1Name,
      SetupChannel2Name,
      SetupChannel3Name,
      SetupChannel4Name,
      SetupChannel5Name,
      SetupChannel6Name,
      SetupChannel7Name,
      SetupChannel8Name,
      SetupChannel9Name,
      SetupChannel10Name,
      SetupChannel11Name,
      SetupChannel12Name,
      SetupChannel13Name,
      SetupChannel14Name,
      SetupChannel15Name,
      SetupChannel16Name,
      SetupChannel17Name,
      SetupChannel18Name,
      SetupChannel19Name,
      SetupChannel20Name,
      SetupChannel21Name,
      SetupChannel22Name,
      SetupChannel23Name,
      SetupChannel24Name,

      SetupChannel1Number,
      SetupChannel2Number,
      SetupChannel3Number,
      SetupChannel4Number,
      SetupChannel5Number,
      SetupChannel6Number,
      SetupChannel7Number,
      SetupChannel8Number,
      SetupChannel9Number,
      SetupChannel10Number,
      SetupChannel11Number,
      SetupChannel12Number,
      SetupChannel13Number,
      SetupChannel14Number,
      SetupChannel15Number,
      SetupChannel16Number,
      SetupChannel17Number,
      SetupChannel18Number,
      SetupChannel19Number,
      SetupChannel20Number,
      SetupChannel21Number,
      SetupChannel22Number,
      SetupChannel23Number,
      SetupChannel24Number,

      SetupChannel1SourceName,
      SetupChannel2SourceName,
      SetupChannel3SourceName,
      SetupChannel4SourceName,
      SetupChannel5SourceName,
      SetupChannel6SourceName,
      SetupChannel7SourceName,
      SetupChannel8SourceName,
      SetupChannel9SourceName,
      SetupChannel10SourceName,
      SetupChannel11SourceName,
      SetupChannel12SourceName,
      SetupChannel13SourceName,
      SetupChannel14SourceName,
      SetupChannel15SourceName,
      SetupChannel16SourceName,
      SetupChannel17SourceName,
      SetupChannel18SourceName,
      SetupChannel19SourceName,
      SetupChannel20SourceName,
      SetupChannel21SourceName,
      SetupChannel22SourceName,
      SetupChannel23SourceName,
      SetupChannel24SourceName,

      SetupChannel1NextSourceButton,
      SetupChannel2NextSourceButton,
      SetupChannel3NextSourceButton,
      SetupChannel4NextSourceButton,
      SetupChannel5NextSourceButton,
      SetupChannel6NextSourceButton,
      SetupChannel7NextSourceButton,
      SetupChannel8NextSourceButton,
      SetupChannel9NextSourceButton,
      SetupChannel10NextSourceButton,
      SetupChannel11NextSourceButton,
      SetupChannel12NextSourceButton,
      SetupChannel13NextSourceButton,
      SetupChannel14NextSourceButton,
      SetupChannel15NextSourceButton,
      SetupChannel16NextSourceButton,
      SetupChannel17NextSourceButton,
      SetupChannel18NextSourceButton,
      SetupChannel19NextSourceButton,
      SetupChannel20NextSourceButton,
      SetupChannel21NextSourceButton,
      SetupChannel22NextSourceButton,
      SetupChannel23NextSourceButton,
      SetupChannel24NextSourceButton,

      SetupChannel1VolumeOverrideButton,
      SetupChannel2VolumeOverrideButton,
      SetupChannel3VolumeOverrideButton,
      SetupChannel4VolumeOverrideButton,
      SetupChannel5VolumeOverrideButton,
      SetupChannel6VolumeOverrideButton,
      SetupChannel7VolumeOverrideButton,
      SetupChannel8VolumeOverrideButton,
      SetupChannel9VolumeOverrideButton,
      SetupChannel10VolumeOverrideButton,
      SetupChannel11VolumeOverrideButton,
      SetupChannel12VolumeOverrideButton,
      SetupChannel13VolumeOverrideButton,
      SetupChannel14VolumeOverrideButton,
      SetupChannel15VolumeOverrideButton,
      SetupChannel16VolumeOverrideButton,
      SetupChannel17VolumeOverrideButton,
      SetupChannel18VolumeOverrideButton,
      SetupChannel19VolumeOverrideButton,
      SetupChannel20VolumeOverrideButton,
      SetupChannel21VolumeOverrideButton,
      SetupChannel22VolumeOverrideButton,
      SetupChannel23VolumeOverrideButton,
      SetupChannel24VolumeOverrideButton,

      SetupOrganPaneBox,
      SetupOrganTitleTextLabel,
      SetupOrganPrimaryKeyboardActiveButton,
      SetupOrganSecondaryKeyboardActiveButton,
      SetupOrganLowestNoteSlider,
      SetupOrganHighestNoteSlider,
      SetupOrganLowestNoteTextLabel,
      SetupOrganHighestNoteTextLabel,
      SetupOrganSustainPedalActiveButton,

      Last
   };

   WidgetIds();

   void Fill();

   EWidgetId GetId(const std::string &name);
   std::string GetName(EWidgetId id);

   static EWidgetId GetOrganDrawbar(int sliderIndex);
   static int GetIndexOfOrganDrawbar(EWidgetId slider);

   static EWidgetId GetPrimaryKeyboardSliderBox(int boxIndex);
   static int GetIndexOfPrimaryKeyboardSliderBox(EWidgetId box);

   static EWidgetId GetPrimaryKeyboardSlider(int sliderIndex);
   static int GetIndexOfPrimaryKeyboardSlider(EWidgetId slider);

   static EWidgetId GetPrimaryKeyboardSliderLevelLeft(int sliderIndex);
   static int GetIndexOfPrimaryKeyboardSliderLevelLeft(EWidgetId slider);

   static EWidgetId GetPrimaryKeyboardSliderLevelRight(int sliderIndex);
   static int GetIndexOfPrimaryKeyboardSliderLevelRight(EWidgetId slider);

   static EWidgetId GetPrimaryKeyboardSliderName(int sliderIndex);
   static int GetIndexOfPrimaryKeyboardSliderName(EWidgetId slider);

   static EWidgetId GetPrimaryKeyboardSliderSourceName(int sliderIndex);
   static int GetIndexOfPrimaryKeyboardSliderSourceName(EWidgetId slider);

   static EWidgetId GetPrimaryKeyboardButton(int buttonIndex);
   static int GetIndexOfPrimaryKeyboardButton(EWidgetId button);

   static EWidgetId GetSetupChannelName(int channelIndex);
   static int GetIndexOfSetupChannelName(EWidgetId channelName);

   static EWidgetId GetSetupChannelNumber(int channelIndex);
   static int GetIndexOfSetupChannelNumber(EWidgetId channelNumber);

   static EWidgetId GetSetupChannelSourceName(int channelIndex);
   static int GetIndexOfSetupChannelSourceName(EWidgetId channelSourceName);

   static EWidgetId GetSetupChannelNextSourceButton(int channelIndex);
   static int GetIndexOfSetupChannelNextSourceButton(EWidgetId channelIndex);

   static EWidgetId GetSetupChannelVolumeOverrideButton(int channelIndex);
   static int GetIndexOfSetupChannelVolumeOverrideButton(EWidgetId channelIndex);

 private:
   void FillSlidersPane();
   void FillOrganPane();
   void FillFootPedalPane();
   void FillSetupChannelsPane();
   void FillSetupChannelWidget(const std::string &setupChannelPrefix, int channelIndex);
   void FillSetupOrganPane();

   std::vector<std::string> _idToNames;
   std::map<std::string, EWidgetId> _nameToIds;
};
