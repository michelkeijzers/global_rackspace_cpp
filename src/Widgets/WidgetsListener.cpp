#include "WidgetsListener.h"
#include "../Controller/Controller.h"
#include "../Controller/KeyboardSubController.h"
#include "../Controller/MixerSubController.h"
#include "../Controller/OrganSubController.h"
#include "../Framework/MvcFramework.h"
#include "../Model/Model.h"
#include "../Utilities/Debug.h"
#include "../Utilities/MidiUtilities.h"
#include "../View/Panes/OrganPane.h"
#include "../View/Panes/SlidersPane.h"
#include "../View/View.h"
#include "ButtonWidget.h"
#include "ValueWidget.h"
#include "WidgetIds.h"
#include "Widgets.h"
#ifdef TESTER
#include "../../../JuceTester2/NewProject/Builds/VisualStudio2022/Source/GP_API/GigPerformerAPI.h"
#else
#include <gigperformer/sdk/GigPerformerAPI.h>
#endif

WidgetsListener::WidgetsListener(Controller &controller, WidgetIds &widgetIds)
    : _controller(controller), _widgetIds(widgetIds)
{
}

void WidgetsListener::OnWidgetValueChanged(const std::string &widgetName, double newValue)
{
   bool processed = false;
   Debug::LogMethodEntry(__FUNCTION__, "widgetName = " + widgetName + ", newValue = " + std::to_string(newValue));
   WidgetIds::EWidgetId widgetId = _widgetIds.GetId(widgetName);
   Debug::Log("@--- On Widget " + widgetName + ": value = " + std::to_string(newValue));
   int index = WidgetIds::GetIndexOfOrganDrawbar(widgetId);
   if ((widgetId >= WidgetIds::EWidgetId::OrganDrawbar1) && (index < OrganPane::NR_OF_DRAWBAR_SLIDERS))
   {
      OrganSubController &organSubController =
       static_cast<OrganSubController &>(_controller.GetSubController(SubControllers::ESubControllerId::Organ));
      organSubController.SetDrawbarValue(index, newValue);
      processed = true;
   }
   if (!processed && (widgetId == WidgetIds::EWidgetId::PrimaryKeyboardButton9))
   {
      if (ButtonWidget::IsPressed(newValue))
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
   if (!processed)
   {
      if (widgetId == WidgetIds::EWidgetId::SyncLabelsToMixerButton)
      {
         if (ButtonWidget::IsPressed(newValue))
         {
            MixerSubController &mixerSubController =
             static_cast<MixerSubController &>(_controller.GetSubController(SubControllers::ESubControllerId::Mixer));
            std::vector<std::string> channelNames;
            for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
            {
               const std::string widgetNameChannelsSetup = "ChannelsSetup" + std::to_string(channelIndex + 1) + "Name";
               channelNames.push_back(MvcFramework::GetGigPerformerApi().getWidgetTextValue(widgetNameChannelsSetup));
            }
            mixerSubController.SetChannelNames(channelNames);
         }
      }
   }
   if (!processed)
   {
      index = WidgetIds::GetIndexOfChannelsSetupNextSourceButton(widgetId);
      if ((widgetId >= WidgetIds::EWidgetId::ChannelsSetup1NextSourceButton) &&
          (index < MixerSubModel::NR_OF_MIXER_CHANNELS))
      {
         if (ButtonWidget::IsPressed(newValue))
         {
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
      if ((widgetId >= WidgetIds::EWidgetId::ChannelsSetup1VolumeOverrideButton) &&
          (index < MixerSubModel::NR_OF_MIXER_CHANNELS))
      {
         if (ButtonWidget::IsPressed(newValue))
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
      if (widgetId == WidgetIds::EWidgetId::OrganSetupPrimaryKeyboardActiveButton)
      {
         OrganSubController &organSubController =
          static_cast<OrganSubController &>(_controller.GetSubController(SubControllers::ESubControllerId::Organ));
         organSubController.SetPrimaryKeyboardActive(ButtonWidget::IsPressed(newValue));
         processed = true;
      }
   }
   if (!processed)
   {
      if (widgetId == WidgetIds::EWidgetId::OrganSetupSecondaryKeyboardActiveButton)
      {
         OrganSubController &organSubController =
          static_cast<OrganSubController &>(_controller.GetSubController(SubControllers::ESubControllerId::Organ));
         organSubController.SetSecondaryKeyboardActive(ButtonWidget::IsPressed(newValue));
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
      if (widgetId == WidgetIds::EWidgetId::OrganSetupSustainPedalActiveButton)
      {
         OrganSubController &organSubController =
          static_cast<OrganSubController &>(_controller.GetSubController(SubControllers::ESubControllerId::Organ));
         organSubController.SetSustainPedalActive(MidiUtilities::ParamToMidi(newValue));
         processed = true;
      }
   }
   if (!processed)
   {
      Debug::Error(__FUNCTION__, "Illegal widgetId");
   }
   Debug::LogMethodExit(__FUNCTION__);
}

void WidgetsListener::ProcessSlider(int sliderIndex, double newValue)
{
   MixerSubController &mixerSubController =
    (MixerSubController &)_controller.GetSubController(SubControllers::ESubControllerId::Mixer);
   mixerSubController.SetSliderValue(sliderIndex, newValue);
}
