#include "WidgetsListener.h"
#include "../Controller/Controller.h"
#include "../Controller/KeyboardSubController.h"
#include "../Controller/MixerSubController.h"
#include "../Controller/OrganSubController.h"
#include "../Controller/WindowSubController.h"
#include "../Framework/MvcFramework.h"
#include "../Model/Model.h"
#include "../Utilities/Debug.h"
#include "../Utilities/MidiUtilities.h"
#include "../View/Panes/OrganPane.h"
#include "../View/Panes/SlidersPane.h"
#include "../View/View.h"
#include "ButtonWidget.h"
#include "WidgetIds.h"
#ifdef TESTER
#include "../../../JuceTester2/NewProject/Builds/VisualStudio2022/Source/GP_API/GigPerformerAPI.h"
#else
#include <gigperformer/sdk/GigPerformerAPI.h>
#endif

#ifdef TESTER
const int BUTTON_DEBOUNCE_TIME = 0; // ms
#else
const int BUTTON_DEBOUNCE_TIME = 10; // ms
#endif

WidgetsListener::WidgetsListener(Controller &controller, WidgetIds &widgetIds)
    : _controller(controller), _widgetIds(widgetIds), _lastButtonPressTime(0)
{
}

void WidgetsListener::OnWidgetValueChanged(const std::string &widgetName, double newValue)
{
   bool processed = false;
   Debug::LogMethodEntry(__FUNCTION__, "widgetName = " + widgetName + ", newValue = " + std::to_string(newValue));
   WidgetIds::EWidgetId widgetId = _widgetIds.GetId(widgetName);
   Debug::Log("@-- On Widget " + widgetName + ": value = " + std::to_string(newValue));
   int index = WidgetIds::GetIndexOfOrganDrawbar(widgetId);
   if (widgetId == WidgetIds::EWidgetId::LeftFootPedal)
   {
      if (newValue > 0.0001) // TODO: Find out why  needed (crashes otherwise)
      {
         KeyboardSubController &keyboardSubController = static_cast<KeyboardSubController &>(
          _controller.GetSubController(SubControllers::ESubControllerId::PrimaryKeyboard));
         keyboardSubController.SetExpressionVolume(newValue);
      }
   }
   if (widgetId == WidgetIds::EWidgetId::RightFootPedal)
   {
      if (newValue > 0.0001) // TODO: Find out why  needed (crashes otherwise)
      {
         KeyboardSubController &keyboardSubController = static_cast<KeyboardSubController &>(
          _controller.GetSubController(SubControllers::ESubControllerId::SecondaryKeyboard));
         keyboardSubController.SetExpressionVolume(newValue);
      }
   }

	bugs: when opening GP, when changing source name, slider pane source name is not updated, when changing tab selection it works, solution: notify tab selection
	      when opening GP, organ visible, while not enabled (primary/secondary keyboard off)
			sync channel names clears all names

	
   if ((widgetId >= WidgetIds::EWidgetId::OrganDrawbar1) &&
       (index < OrganPane::NR_OF_DRAWBAR_SLIDERS))
   {
      OrganSubController &organSubController =
       static_cast<OrganSubController &>(_controller.GetSubController(SubControllers::ESubControllerId::Organ));
      organSubController.SetDrawbarValue(index, newValue);
      processed = true;
   }
   if (!processed && (widgetId == WidgetIds::EWidgetId::PrimaryKeyboardButton1))
   {
      if (IsPressed(newValue))
      {
         _controller.WriteSong();
      }
      processed = true;
   }
   // TODO: Next is temporary
   if (!processed && (widgetId == WidgetIds::EWidgetId::PrimaryKeyboardButton2))
   {
      if (IsPressed(newValue))
      {
         WindowSubController &windowSubController =
          static_cast<WindowSubController &>(_controller.GetSubController(SubControllers::ESubControllerId::Window));
         windowSubController.SetNextSlidersPane();
      }
      processed = true;
   }

   if (!processed && (widgetId == WidgetIds::EWidgetId::PrimaryKeyboardButton9))
   {
      if (IsPressed(newValue))
      {
         OrganSubController &organSubController =
          static_cast<OrganSubController &>(_controller.GetSubController(SubControllers::ESubControllerId::Organ));
         organSubController.SwapRotatorSpeed();
      }
      processed = true;
   }
   if (!processed && (widgetId == WidgetIds::EWidgetId::PrimaryKeyboardKnob1))
   {
      OrganSubController &organSubController =
       static_cast<OrganSubController &>(_controller.GetSubController(SubControllers::ESubControllerId::Organ));
      organSubController.SetDrive(newValue);
      processed = true;
   }
   if (!processed && (widgetId == WidgetIds::EWidgetId::PrimaryKeyboardKnob2))
   {
      OrganSubController &organSubController =
       static_cast<OrganSubController &>(_controller.GetSubController(SubControllers::ESubControllerId::Organ));
      organSubController.SetReverbAmount(newValue);
      processed = true;
   }
   if (!processed && (widgetId == WidgetIds::EWidgetId::PrimaryKeyboardKnob4))
   {
      KeyboardSubController &keyboardSubController = static_cast<KeyboardSubController &>(
       _controller.GetSubController(SubControllers::ESubControllerId::PrimaryKeyboard));
      keyboardSubController.SetExpressionVolume(newValue);
      processed = true;
   }
   if (!processed && (widgetId == WidgetIds::EWidgetId::PrimaryKeyboardKnob8))
   {
      KeyboardSubController &keyboardSubController = static_cast<KeyboardSubController &>(
       _controller.GetSubController(SubControllers::ESubControllerId::SecondaryKeyboard));
      keyboardSubController.SetExpressionVolume(newValue);
      processed = true;
   }
   if (!processed)
   {
      index = WidgetIds::GetIndexOfPrimaryKeyboardSlider(widgetId);
      if ((widgetId >= WidgetIds::EWidgetId::PrimaryKeyboardSlider1) && (index < SlidersPane::NR_OF_SLIDERS))
      {
         ProcessSlider(index, newValue);
         processed = true;
      }
   }
   if (!processed && (widgetId == WidgetIds::EWidgetId::SyncLabelsToMixerButton))
   {
      if (IsPressed(newValue))
      {
         MixerSubController &mixerSubController =
          static_cast<MixerSubController &>(_controller.GetSubController(SubControllers::ESubControllerId::Mixer));
         std::vector<std::string> channelTitles;
         for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
         {
            const std::string widgetNameChannelsSetup = "ChannelsSetupTitle" + std::to_string(channelIndex + 1);
            channelTitles.push_back(MvcFramework::GetGigPerformerApi().getWidgetTextValue(widgetNameChannelsSetup));
         }
         mixerSubController.SetChannelTitles(channelTitles);
      }
      processed = true;
   }
   if (!processed)
   {
      index = WidgetIds::GetIndexOfChannelsSetupNextSourceButton(widgetId);
      Debug::Log("TODO NS1");
      if ((widgetId >= WidgetIds::EWidgetId::ChannelsSetupNextSourceBut1) &&
          (index < MixerSubModel::NR_OF_MIXER_CHANNELS))
      {
         Debug::Log("TODO NS2");
         if (IsPressed(newValue))
         {
            Debug::Log("TODO NS3");
            MixerSubController &mixerSubController =
             static_cast<MixerSubController &>(_controller.GetSubController(SubControllers::ESubControllerId::Mixer));
            mixerSubController.SelectNextSource(index);
         }
         processed = true;
      }
   }
   if (!processed)
   {
      index = WidgetIds::GetIndexOfChannelsSetupVolumeOverrideButton(widgetId);
      if ((widgetId >= WidgetIds::EWidgetId::ChannelsSetupVolOverrideBut1) &&
          (index < MixerSubModel::NR_OF_MIXER_CHANNELS))
      {
         if (IsPressed(newValue))
         {
            MixerSubController &mixerSubController =
             static_cast<MixerSubController &>(_controller.GetSubController(SubControllers::ESubControllerId::Mixer));
            mixerSubController.SwapVolumeOverride(index);
         }
         processed = true;
      }
   }
   if (!processed)
   {
      if (widgetId == WidgetIds::EWidgetId::OrganSetupPrimaryKbdActBut)
      {
         OrganSubController &organSubController =
          static_cast<OrganSubController &>(_controller.GetSubController(SubControllers::ESubControllerId::Organ));
         organSubController.SetPrimaryKeyboardActive(IsPressed(newValue));
         processed = true;
      }
   }
   if (!processed)
   {
      if (widgetId == WidgetIds::EWidgetId::OrganSetupSecondaryKbdActBut)
      {
         OrganSubController &organSubController =
          static_cast<OrganSubController &>(_controller.GetSubController(SubControllers::ESubControllerId::Organ));
         organSubController.SetSecondaryKeyboardActive(IsPressed(newValue));
         processed = true;
      }
   }
   if (!processed)
   {
      if (widgetId == WidgetIds::EWidgetId::OrganSetupLowestNoteSlider)
      {
         OrganSubController &organSubController =
          static_cast<OrganSubController &>(_controller.GetSubController(SubControllers::ESubControllerId::Organ));
         organSubController.SetLowestNote(MidiUtilities::ParamToMidi(newValue));
         processed = true;
      }
   }
   if (!processed)
   {
      if (widgetId == WidgetIds::EWidgetId::OrganSetupHighestNoteSlider)
      {
         OrganSubController &organSubController =
          static_cast<OrganSubController &>(_controller.GetSubController(SubControllers::ESubControllerId::Organ));
         organSubController.SetHighestNote(MidiUtilities::ParamToMidi(newValue));
         processed = true;
      }
   }
   if (!processed)
   {
      if (widgetId == WidgetIds::EWidgetId::OrganSetupSustainPedalActBut)
      {
         OrganSubController &organSubController =
          static_cast<OrganSubController &>(_controller.GetSubController(SubControllers::ESubControllerId::Organ));
         organSubController.SetSustainPedalActive(MidiUtilities::ParamToMidi(newValue));
         processed = true;
      }
   }
   Debug::LogMethodExit(__FUNCTION__);
}

void WidgetsListener::ProcessSlider(int sliderIndex, double newValue)
{
   MixerSubController &mixerSubController =
    (MixerSubController &)_controller.GetSubController(SubControllers::ESubControllerId::Mixer);
   mixerSubController.SetSliderValue(sliderIndex, newValue);
}

bool WidgetsListener::IsPressed(double value)
{
   bool isPressed = false;
   juce::Time currentTime = juce::Time::getCurrentTime();

   if (currentTime - _lastButtonPressTime >= juce::RelativeTime::milliseconds(BUTTON_DEBOUNCE_TIME))
   {
      _lastButtonPressTime = currentTime;
      isPressed = value >= 0.5;
   }
   return isPressed;
}
