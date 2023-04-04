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
      SlidersPaneTabChannels17To24,

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

      PrimaryKeyboardSlLevelLeft1,
      PrimaryKeyboardSlLevelLeft2,
      PrimaryKeyboardSlLevelLeft3,
      PrimaryKeyboardSlLevelLeft4,
      PrimaryKeyboardSlLevelLeft5,
      PrimaryKeyboardSlLevelLeft6,
      PrimaryKeyboardSlLevelLeft7,
      PrimaryKeyboardSlLevelLeft8,
      PrimaryKeyboardSlLevelLeft9,
							
      PrimaryKeyboardSlLevelRight1,
      PrimaryKeyboardSlLevelRight2,
      PrimaryKeyboardSlLevelRight3,
      PrimaryKeyboardSlLevelRight4,
      PrimaryKeyboardSlLevelRight5,
      PrimaryKeyboardSlLevelRight6,
      PrimaryKeyboardSlLevelRight7,
      PrimaryKeyboardSlLevelRight8,
      PrimaryKeyboardSlLevelRight9,

      PrimaryKeyboardSliderTitle1,
      PrimaryKeyboardSliderTitle2,
      PrimaryKeyboardSliderTitle3,
      PrimaryKeyboardSliderTitle4,
      PrimaryKeyboardSliderTitle5,
      PrimaryKeyboardSliderTitle6,
      PrimaryKeyboardSliderTitle7,
      PrimaryKeyboardSliderTitle8,
      PrimaryKeyboardSliderTitle9,

      PrimaryKeyboardSlSourceName1,
      PrimaryKeyboardSlSourceName2,
      PrimaryKeyboardSlSourceName3,
      PrimaryKeyboardSlSourceName4,
      PrimaryKeyboardSlSourceName5,
      PrimaryKeyboardSlSourceName6,
      PrimaryKeyboardSlSourceName7,
      PrimaryKeyboardSlSourceName8,
      PrimaryKeyboardSlSourceName9,

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
      ChannelNumberTextLabel,
      NextSourceTextLabel,
      VolumeOverrideTextLabel,

      ChannelsSetupTitle1,
      ChannelsSetupTitle2,
      ChannelsSetupTitle3,
      ChannelsSetupTitle4,
      ChannelsSetupTitle5,
      ChannelsSetupTitle6,
      ChannelsSetupTitle7,
      ChannelsSetupTitle8,
      ChannelsSetupTitle9,
      ChannelsSetupTitle10,
      ChannelsSetupTitle11,
      ChannelsSetupTitle12,
      ChannelsSetupTitle13,
      ChannelsSetupTitle14,
      ChannelsSetupTitle15,
      ChannelsSetupTitle16,
      ChannelsSetupTitle17,
      ChannelsSetupTitle18,
      ChannelsSetupTitle19,
      ChannelsSetupTitle20,
      ChannelsSetupTitle21,
      ChannelsSetupTitle22,
      ChannelsSetupTitle23,
      ChannelsSetupTitle24,

      ChannelsSetupNumber1,
      ChannelsSetupNumber2,
      ChannelsSetupNumber3,
      ChannelsSetupNumber4,
      ChannelsSetupNumber5,
      ChannelsSetupNumber6,
      ChannelsSetupNumber7,
      ChannelsSetupNumber8,
      ChannelsSetupNumber9,
      ChannelsSetupNumber10,
      ChannelsSetupNumber11,
      ChannelsSetupNumber12,
      ChannelsSetupNumber13,
      ChannelsSetupNumber14,
      ChannelsSetupNumber15,
      ChannelsSetupNumber16,
      ChannelsSetupNumber17,
      ChannelsSetupNumber18,
      ChannelsSetupNumber19,
      ChannelsSetupNumber20,
      ChannelsSetupNumber21,
      ChannelsSetupNumber22,
      ChannelsSetupNumber23,
      ChannelsSetupNumber24,

      ChannelsSetupSourceName1,
      ChannelsSetupSourceName2,
      ChannelsSetupSourceName3,
      ChannelsSetupSourceName4,
      ChannelsSetupSourceName5,
      ChannelsSetupSourceName6,
      ChannelsSetupSourceName7,
      ChannelsSetupSourceName8,
      ChannelsSetupSourceName9,
      ChannelsSetupSourceName10,
      ChannelsSetupSourceName11,
      ChannelsSetupSourceName12,
      ChannelsSetupSourceName13,
      ChannelsSetupSourceName14,
      ChannelsSetupSourceName15,
      ChannelsSetupSourceName16,
      ChannelsSetupSourceName17,
      ChannelsSetupSourceName18,
      ChannelsSetupSourceName19,
      ChannelsSetupSourceName20,
      ChannelsSetupSourceName21,
      ChannelsSetupSourceName22,
      ChannelsSetupSourceName23,
      ChannelsSetupSourceName24,

      ChannelsSetupNextSourceBut1,
      ChannelsSetupNextSourceBut2,
      ChannelsSetupNextSourceBut3,
      ChannelsSetupNextSourceBut4,
      ChannelsSetupNextSourceBut5,
      ChannelsSetupNextSourceBut6,
      ChannelsSetupNextSourceBut7,
      ChannelsSetupNextSourceBut8,
      ChannelsSetupNextSourceBut9,
      ChannelsSetupNextSourceBut10,
      ChannelsSetupNextSourceBut11,
      ChannelsSetupNextSourceBut12,
      ChannelsSetupNextSourceBut13,
      ChannelsSetupNextSourceBut14,
      ChannelsSetupNextSourceBut15,
      ChannelsSetupNextSourceBut16,
      ChannelsSetupNextSourceBut17,
      ChannelsSetupNextSourceBut18,
      ChannelsSetupNextSourceBut19,
      ChannelsSetupNextSourceBut20,
      ChannelsSetupNextSourceBut21,
      ChannelsSetupNextSourceBut22,
      ChannelsSetupNextSourceBut23,
      ChannelsSetupNextSourceBut24,

      ChannelsSetupVolOverrideBut1,
      ChannelsSetupVolOverrideBut2,
      ChannelsSetupVolOverrideBut3,
      ChannelsSetupVolOverrideBut4,
      ChannelsSetupVolOverrideBut5,
      ChannelsSetupVolOverrideBut6,
      ChannelsSetupVolOverrideBut7,
      ChannelsSetupVolOverrideBut8,
      ChannelsSetupVolOverrideBut9,
      ChannelsSetupVolOverrideBut10,
      ChannelsSetupVolOverrideBut11,
      ChannelsSetupVolOverrideBut12,
      ChannelsSetupVolOverrideBut13,
      ChannelsSetupVolOverrideBut14,
      ChannelsSetupVolOverrideBut15,
      ChannelsSetupVolOverrideBut16,
      ChannelsSetupVolOverrideBut17,
      ChannelsSetupVolOverrideBut18,
      ChannelsSetupVolOverrideBut19,
      ChannelsSetupVolOverrideBut20,
      ChannelsSetupVolOverrideBut21,
      ChannelsSetupVolOverrideBut22,
      ChannelsSetupVolOverrideBut23,
      ChannelsSetupVolOverrideBut24,

      // Plugin Setup pane
      OrganSetupPaneBox,
      OrganSetupPaneTitleTextLabel,
      OrganSetupPrimaryKbdActBut,
      OrganSetupSecondaryKbdActBut,
      OrganSetupLowestNoteSlider,
      OrganSetupHighestNoteSlider,
      OrganSetupLowestNoteTextLabel,
      OrganSetupHighestNoteTextLabel,
      OrganSetupSustainPedalActBut,

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

   static EWidgetId GetPrimaryKeyboardSliderTitle(int sliderIndex);
   static int GetIndexOfPrimaryKeyboardSliderTitle(EWidgetId slider);

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
