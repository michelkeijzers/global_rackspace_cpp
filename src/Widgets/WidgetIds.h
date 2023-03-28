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
      SlidersPaneBox,
      SlidersPaneTitleTextLabel,
		SlidersPaneTabOrgan,
		SlidersPaneTabChannels1To8,
		SlidersPaneTabChannels9To16,
		SlidersPaneTabChannels16To24,

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
				
      PrimaryKeyboardSliderNumber1,
      PrimaryKeyboardSliderNumber2,
      PrimaryKeyboardSliderNumber3,
      PrimaryKeyboardSliderNumber4,
      PrimaryKeyboardSliderNumber5,
      PrimaryKeyboardSliderNumber6,
      PrimaryKeyboardSliderNumber7,
      PrimaryKeyboardSliderNumber8,
      PrimaryKeyboardSliderNumber9,

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
      PrimaryKeyboardButtonsPaneBox,
      PrimaryKeyboardButtonsPaneTitleTextLabel,
      PrimaryKeyboardButton1,
      PrimaryKeyboardButton2,
      PrimaryKeyboardButton3,
      PrimaryKeyboardButton4,
      PrimaryKeyboardButton5,
      PrimaryKeyboardButton6,
      PrimaryKeyboardButton7,
      PrimaryKeyboardButton8,
      PrimaryKeyboardButton9,
      PrimaryKeyboardKnob1,
      PrimaryKeyboardKnob2,
      PrimaryKeyboardKnob3,
      PrimaryKeyboardKnob4,
      PrimaryKeyboardKnob5,
      PrimaryKeyboardKnob6,
      PrimaryKeyboardKnob7,
      PrimaryKeyboardKnob8,

		// Foot Board Pane
		FootBoardPaneBox,
		FootBoardPaneTitleTextLabel,
      LeftFootPedal,
      RightFootPedal,

      // Channels Setup pane
      ChannelsSetupPaneBox,
      ChannelsSetupPaneTitleTextLabel,
      SyncLabelsToMixerButton,
      ChannelIndexTextLabel,
      NextSourceTextLabel,
      VolumeOverrideTextLabel,

      ChannelsSetup1Name,
      ChannelsSetup2Name,
      ChannelsSetup3Name,
      ChannelsSetup4Name,
      ChannelsSetup5Name,
      ChannelsSetup6Name,
      ChannelsSetup7Name,
      ChannelsSetup8Name,
      ChannelsSetup9Name,
      ChannelsSetup10Name,
      ChannelsSetup11Name,
      ChannelsSetup12Name,
      ChannelsSetup13Name,
      ChannelsSetup14Name,
      ChannelsSetup15Name,
      ChannelsSetup16Name,
      ChannelsSetup17Name,
      ChannelsSetup18Name,
      ChannelsSetup19Name,
      ChannelsSetup20Name,
      ChannelsSetup21Name,
      ChannelsSetup22Name,
      ChannelsSetup23Name,
      ChannelsSetup24Name,

      ChannelsSetup1Number,
      ChannelsSetup2Number,
      ChannelsSetup3Number,
      ChannelsSetup4Number,
      ChannelsSetup5Number,
      ChannelsSetup6Number,
      ChannelsSetup7Number,
      ChannelsSetup8Number,
      ChannelsSetup9Number,
      ChannelsSetup10Number,
      ChannelsSetup11Number,
      ChannelsSetup12Number,
      ChannelsSetup13Number,
      ChannelsSetup14Number,
      ChannelsSetup15Number,
      ChannelsSetup16Number,
      ChannelsSetup17Number,
      ChannelsSetup18Number,
      ChannelsSetup19Number,
      ChannelsSetup20Number,
      ChannelsSetup21Number,
      ChannelsSetup22Number,
      ChannelsSetup23Number,
      ChannelsSetup24Number,

      ChannelsSetup1SourceName,
      ChannelsSetup2SourceName,
      ChannelsSetup3SourceName,
      ChannelsSetup4SourceName,
      ChannelsSetup5SourceName,
      ChannelsSetup6SourceName,
      ChannelsSetup7SourceName,
      ChannelsSetup8SourceName,
      ChannelsSetup9SourceName,
      ChannelsSetup10SourceName,
      ChannelsSetup11SourceName,
      ChannelsSetup12SourceName,
      ChannelsSetup13SourceName,
      ChannelsSetup14SourceName,
      ChannelsSetup15SourceName,
      ChannelsSetup16SourceName,
      ChannelsSetup17SourceName,
      ChannelsSetup18SourceName,
      ChannelsSetup19SourceName,
      ChannelsSetup20SourceName,
      ChannelsSetup21SourceName,
      ChannelsSetup22SourceName,
      ChannelsSetup23SourceName,
      ChannelsSetup24SourceName,

      ChannelsSetup1NextSourceButton,
      ChannelsSetup2NextSourceButton,
      ChannelsSetup3NextSourceButton,
      ChannelsSetup4NextSourceButton,
      ChannelsSetup5NextSourceButton,
      ChannelsSetup6NextSourceButton,
      ChannelsSetup7NextSourceButton,
      ChannelsSetup8NextSourceButton,
      ChannelsSetup9NextSourceButton,
      ChannelsSetup10NextSourceButton,
      ChannelsSetup11NextSourceButton,
      ChannelsSetup12NextSourceButton,
      ChannelsSetup13NextSourceButton,
      ChannelsSetup14NextSourceButton,
      ChannelsSetup15NextSourceButton,
      ChannelsSetup16NextSourceButton,
      ChannelsSetup17NextSourceButton,
      ChannelsSetup18NextSourceButton,
      ChannelsSetup19NextSourceButton,
      ChannelsSetup20NextSourceButton,
      ChannelsSetup21NextSourceButton,
      ChannelsSetup22NextSourceButton,
      ChannelsSetup23NextSourceButton,
      ChannelsSetup24NextSourceButton,

      ChannelsSetup1VolumeOverrideButton,
      ChannelsSetup2VolumeOverrideButton,
      ChannelsSetup3VolumeOverrideButton,
      ChannelsSetup4VolumeOverrideButton,
      ChannelsSetup5VolumeOverrideButton,
      ChannelsSetup6VolumeOverrideButton,
      ChannelsSetup7VolumeOverrideButton,
      ChannelsSetup8VolumeOverrideButton,
      ChannelsSetup9VolumeOverrideButton,
      ChannelsSetup10VolumeOverrideButton,
      ChannelsSetup11VolumeOverrideButton,
      ChannelsSetup12VolumeOverrideButton,
      ChannelsSetup13VolumeOverrideButton,
      ChannelsSetup14VolumeOverrideButton,
      ChannelsSetup15VolumeOverrideButton,
      ChannelsSetup16VolumeOverrideButton,
      ChannelsSetup17VolumeOverrideButton,
      ChannelsSetup18VolumeOverrideButton,
      ChannelsSetup19VolumeOverrideButton,
      ChannelsSetup20VolumeOverrideButton,
      ChannelsSetup21VolumeOverrideButton,
      ChannelsSetup22VolumeOverrideButton,
      ChannelsSetup23VolumeOverrideButton,
      ChannelsSetup24VolumeOverrideButton,

		// Plugin Setup pane
      OrganSetupPaneBox,
      OrganSetupPaneTitleTextLabel,
      OrganSetupPrimaryKeyboardActiveButton,
      OrganSetupSecondaryKeyboardActiveButton,
      OrganSetupLowestNoteSlider,
      OrganSetupHighestNoteSlider,
      OrganSetupLowestNoteTextLabel,
      OrganSetupHighestNoteTextLabel,
      OrganSetupSustainPedalActiveButton,

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

   static EWidgetId GetPrimaryKeyboardSliderNumber(int boxIndex);
   static int GetIndexOfPrimaryKeyboardSliderNumber(EWidgetId box);

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

   static EWidgetId GetPrimaryKeyboardKnob(int knobIndex);
   static int GetIndexOfPrimaryKeyboardKnob(EWidgetId knob);

   static EWidgetId GetChannelsSetupName(int channelIndex);
   static int GetIndexOfChannelsSetupName(EWidgetId channelName);

   static EWidgetId GetChannelsSetupNumber(int channelIndex);
   static int GetIndexOfChannelsSetupNumber(EWidgetId channelNumber);

   static EWidgetId GetChannelsSetupSourceName(int channelIndex);
   static int GetIndexOfChannelsSetupSourceName(EWidgetId channelSourceName);

   static EWidgetId GetChannelsSetupNextSourceButton(int channelIndex);
   static int GetIndexOfChannelsSetupNextSourceButton(EWidgetId channelIndex);

   static EWidgetId GetChannelsSetupVolumeOverrideButton(int channelIndex);
   static int GetIndexOfChannelsSetupVolumeOverrideButton(EWidgetId channelIndex);

 private:
   void FillSlidersPane();
   void FillOrganPane();
   void FillPrimaryKeyboardButtonsPane();
   void FillFootBoardPane();
   void FillChannelsSetupPane();
   void FillOrganSetupPane();

   std::vector<std::string> _idToNames;
   std::map<std::string, EWidgetId> _nameToIds;
};
