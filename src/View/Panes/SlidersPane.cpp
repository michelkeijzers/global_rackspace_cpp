#include "SlidersPane.h"
#include "../../Framework/MvcFramework.h"
#include "../../Model/MixerSubModel.h"
#include "../../Model/Model.h"
#include "../../Model/OrganSubModel.h"
#include "../../Utilities/Debug.h"
#include "../../Utilities/DoubleUtilities.h"
#include "../../Widgets/ValueWidget.h"
#include "../../Widgets/WidgetIds.h"
#include "../View.h"
#include <juce_core/juce_core.h>
#include <juce_core/time/juce_Time.h>

constexpr double GATE_FADE_TIME = 30.0; // seconds
constexpr int GATE_FADE_BOX_OUTLINE_THICKNESS = 5;

SlidersPane::SlidersPane(View &view, Model &model, MixerSubModel &mixerSubModel, OrganSubModel &organSubModel,
 double leftPercentage, double topPercentage, double widthPercentage, double heightPercentage)
    : Pane(view, leftPercentage, topPercentage, widthPercentage, heightPercentage), _model(model),
      _mixerSubModel(mixerSubModel), _organSubModel(organSubModel)
{
   for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
   {
      MixerChannelSubModel &mixerChannelSubModel = *_mixerSubModel.GetMixerChannelSubModels()[channelIndex];
      _mixerChannelSubModels.push_back(&mixerChannelSubModel);
      mixerChannelSubModel.Subscribe(*this);
   }
   _model.Subscribe(*this);
   _mixerSubModel.Subscribe(*this);
   _organSubModel.Subscribe(*this);
}

void SlidersPane::Fill() // override
{
   WidgetIds::EWidgetId widgetId;

   // Add sliders, and names for channels and master volume.
   for (int sliderIndex = 0; sliderIndex < NR_OF_SLIDERS; sliderIndex++)
   {
      widgetId = WidgetIds::GetPrimaryKeyboardSliderBox(sliderIndex);
      GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, false));
      widgetId = WidgetIds::GetPrimaryKeyboardSlider(sliderIndex);
      GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));
      widgetId = WidgetIds::GetPrimaryKeyboardSliderLevelLeft(sliderIndex);
      GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, false));
      widgetId = WidgetIds::GetPrimaryKeyboardSliderLevelRight(sliderIndex);
      GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, false));
      widgetId = WidgetIds::GetPrimaryKeyboardSliderName(sliderIndex);
      GetWidgets().AddWidget(widgetId, new UpdateOrganRotatorSpeed(GetView().GetWidgetIds(), widgetId, false));
      widgetId = WidgetIds::GetPrimaryKeyboardSliderSourceName(sliderIndex);
      GetWidgets().AddWidget(widgetId, new UpdateOrganRotatorSpeed(GetView().GetWidgetIds(), widgetId, false));
   }

   // Add organ drawbars.
   for (int drawbarIndex = 0; drawbarIndex < OrganSubModel::NR_OF_DRAWBARS; drawbarIndex++)
   {
      widgetId = WidgetIds::GetOrganDrawbar(drawbarIndex);
      GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));
   }
}

void SlidersPane::Relayout() // override
{
   // TODO RELAYOUT



   WidgetIds::EWidgetId widgetId;

   // Add sliders, and names for channels and master volume.
   for (int sliderIndex = 0; sliderIndex < NR_OF_SLIDERS; sliderIndex++)
   {
      widgetId = WidgetIds::GetPrimaryKeyboardSliderBox(sliderIndex);
      GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, false));
      widgetId = WidgetIds::GetPrimaryKeyboardSliderBox(sliderIndex);
      GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));
      widgetId = WidgetIds::GetPrimaryKeyboardSlider(sliderIndex);
      GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, false));
      widgetId = WidgetIds::GetPrimaryKeyboardSliderLevelLeft(sliderIndex);
      GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, false));
      widgetId = WidgetIds::GetPrimaryKeyboardSliderLevelRight(sliderIndex);
      GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, false));
      widgetId = WidgetIds::GetPrimaryKeyboardSliderName(sliderIndex);
      GetWidgets().AddWidget(widgetId, new UpdateOrganRotatorSpeed(GetView().GetWidgetIds(), widgetId, false));
      widgetId = WidgetIds::GetPrimaryKeyboardSliderSourceName(sliderIndex);
      GetWidgets().AddWidget(widgetId, new UpdateOrganRotatorSpeed(GetView().GetWidgetIds(), widgetId, false));
   }

   // Add organ drawbars.
   for (int drawbarIndex = 0; drawbarIndex < OrganSubModel::NR_OF_DRAWBARS; drawbarIndex++)
   {
      widgetId = WidgetIds::GetOrganDrawbar(drawbarIndex);
      GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));
   }
}

void SlidersPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
   if (changedProperty == ChangedProperties::EChangedProperty::SlidersTabSelection)
   {
      UpdateTab();
   }
   else if (changedProperty == ChangedProperties::EChangedProperty::SecondElapsed)
   {
      CheckGatesFading();
   }

   int index = ChangedProperties::GetIndexOfOrganDrawbarProperty(changedProperty);
   if ((changedProperty >= ChangedProperties::EChangedProperty::OrganDrawbar1) &&
       (index < OrganSubModel::NR_OF_DRAWBARS))
   {
      UpdateDrawbar(index);
   }

   CheckUpdateMixerChannelVolume(index, changedProperty);
   CheckUpdateMixerChannelLevelLeft(index, changedProperty);
   CheckUpdateMixerChannelLevelRight(index, changedProperty);

   if (changedProperty == ChangedProperties::EChangedProperty::MasterLevelLeft)
   {
      UpdateMasterLevelLeft();
   }
   else if (changedProperty == ChangedProperties::EChangedProperty::MasterLevelRight)
   {
      UpdateMasterLevelRight();
   }

   CheckUpdateChannelLastTimeGateLeftActive(index, changedProperty);

   CheckUpdateChannelLastTimeGateRightActive(index, changedProperty);

   if ((changedProperty == ChangedProperties::EChangedProperty::MasterLastTimeGateLeftActive) ||
       (changedProperty == ChangedProperties::EChangedProperty::MasterLastTimeGateRightActive))
   {
      UpdatePropertyMasterLastTimeGate();
   }

   else if (changedProperty == ChangedProperties::EChangedProperty::MasterVolume)
   {
      UpdateMasterVolume();
   }

   CheckUpdateChannelName(index, changedProperty);
   CheckUpdateChannelSource(index, changedProperty);
}

void SlidersPane::UpdateTab()
{
   bool drawbarsSelected = _mixerSubModel.GetTabSelection() == MixerSubModel::ETabSelection::Drawbars;
   UpdateTabShowSliders(drawbarsSelected);
   UpdateTabShowOrganWidgets(drawbarsSelected);
   UpdateTabUpdateValues(drawbarsSelected);
}

void SlidersPane::UpdateTabShowOrganWidgets(bool organDrawbarsSelected)
{
   WidgetIds::EWidgetId widgetId;
   for (int organDrawbarIndex = 0; organDrawbarIndex < OrganSubModel::NR_OF_DRAWBARS; organDrawbarIndex++)
   {
      widgetId = WidgetIds::GetOrganDrawbar(organDrawbarIndex);
      GetWidgets().GetWidget(widgetId).Show(organDrawbarsSelected);
   }
}

void SlidersPane::UpdateTabShowSliders(bool drawbarsSelected)
{
   WidgetIds::EWidgetId widgetId;

   // TODO: CONSIDER FIRST/LAST_SLIDER_PANE_WIDGET ENUM VALUES EQUAL TO START/END WIDGETS TO USE A SIMPLE FOR LOOP
   for (int sliderIndex = 0; sliderIndex < NR_OF_SLIDERS; sliderIndex++)
   {
      widgetId = WidgetIds::GetPrimaryKeyboardSliderBox(sliderIndex);
      GetWidgets().GetWidget(widgetId).Show(!drawbarsSelected);
      widgetId = WidgetIds::GetPrimaryKeyboardSlider(sliderIndex);
      GetWidgets().GetWidget(widgetId).Show(!drawbarsSelected);
      widgetId = WidgetIds::GetOrganDrawbar(sliderIndex);
      GetWidgets().GetWidget(widgetId).Show(!drawbarsSelected);
      widgetId = WidgetIds::GetPrimaryKeyboardSliderLevelLeft(sliderIndex);
      GetWidgets().GetWidget(widgetId).Show(!drawbarsSelected);
      widgetId = WidgetIds::GetPrimaryKeyboardSliderLevelRight(sliderIndex);
      GetWidgets().GetWidget(widgetId).Show(!drawbarsSelected);
      widgetId = WidgetIds::GetPrimaryKeyboardSliderName(sliderIndex);
      GetWidgets().GetWidget(widgetId).Show(!drawbarsSelected);
      widgetId = WidgetIds::GetPrimaryKeyboardSliderSourceName(sliderIndex);
      GetWidgets().GetWidget(widgetId).Show(!drawbarsSelected);
   }
}

void SlidersPane::UpdateTabUpdateValues(bool drawbarsSelected)
{
   if (drawbarsSelected)
   {
      for (int drawbarIndex = 0; drawbarIndex < NR_OF_SLIDERS; drawbarIndex++)
      {
         UpdateDrawbar(drawbarIndex);
      }
   }
   else
   {
      int channelOffset = _mixerSubModel.GetChannelOffset();
      for (int sliderIndex = 0; sliderIndex < NR_OF_CHANNEL_SLIDERS; sliderIndex++)
      {
         int channelIndex = channelOffset + sliderIndex;
         UpdateChannelGate(channelIndex);
         UpdateMixerChannelLevelLeft(channelIndex);
         UpdateMixerChannelLevelRight(channelIndex);
         UpdateChannelName(channelIndex);
         UpdateChannelSource(channelIndex);
         UpdateMixerChannelVolume(channelIndex);
      }
      UpdatePropertyMasterLastTimeGate();
      UpdateMasterVolume();
      UpdateMasterLevelLeft();
      UpdateMasterLevelRight();
   }
}

void SlidersPane::UpdateDrawbar(int drawbarIndex)
{
   static_cast<ValueWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganDrawbar1, drawbarIndex))
    .SetValue(_organSubModel.GetDrawbars(drawbarIndex));
}

void SlidersPane::CheckUpdateChannelLastTimeGateRightActive(
 int &index, ChangedProperties::EChangedProperty changedProperty)
{
   index = ChangedProperties::GetIndexOfChannelLastTimeGateRightActiveProperty(changedProperty);
   if ((changedProperty >= ChangedProperties::EChangedProperty::MixerChannel1LastTimeGateRightActive) &&
       (index < MixerSubModel::NR_OF_MIXER_CHANNELS))
   {
      if (IsChannelIndexActive(index))
      {
         UpdateChannelGate(index);
      }
   }
}

void SlidersPane::CheckUpdateChannelLastTimeGateLeftActive(
 int &index, ChangedProperties::EChangedProperty changedProperty)
{
   index = ChangedProperties::GetIndexOfChannelLastTimeGateLeftActiveProperty(changedProperty);
   if ((changedProperty >= ChangedProperties::EChangedProperty::MixerChannel1LastTimeGateLeftActive) &&
       (index < MixerSubModel::NR_OF_MIXER_CHANNELS))
   {
      if (IsChannelIndexActive(index))
      {
         UpdateChannelGate(index);
      }
   }
}

void SlidersPane::UpdatePropertyMasterLastTimeGate()
{
   long long ms = std::max(_mixerSubModel.GetMasterLastTimeGateLeftActive().toMilliseconds(),
    _mixerSubModel.GetMasterLastTimeGateRightActive().toMilliseconds());
   UpdateWidgetForGateFading(
    ms, static_cast<ValueWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider9SourceName)));
}

bool SlidersPane::IsChannelIndexActive(int channelIndex)
{
   MixerSubModel::ETabSelection tabSelection = _mixerSubModel.GetTabSelection();
   return (((tabSelection == MixerSubModel::ETabSelection::Channels1To8) && (0 <= channelIndex) &&
            (channelIndex < NR_OF_CHANNEL_SLIDERS)) ||
           ((tabSelection == MixerSubModel::ETabSelection::Channels9To16) && (NR_OF_CHANNEL_SLIDERS <= channelIndex) &&
            (channelIndex < (2 * NR_OF_CHANNEL_SLIDERS))) ||
           ((tabSelection == MixerSubModel::ETabSelection::Channels17To24) &&
            ((2 * NR_OF_CHANNEL_SLIDERS) <= channelIndex) && (channelIndex < (3 * NR_OF_CHANNEL_SLIDERS))));
}

void SlidersPane::CheckUpdateMixerChannelVolume(int &index, ChangedProperties::EChangedProperty changedProperty)
{
   index = ChangedProperties::GetIndexOfMixerChannelVolumeProperty(changedProperty);
   if ((changedProperty >= ChangedProperties::EChangedProperty::MixerChannel1Volume) &&
       (index < MixerSubModel::NR_OF_MIXER_CHANNELS))
   {
      if (IsChannelIndexActive(index))
      {
         UpdateMixerChannelVolume(index);
      }
   }
}

void SlidersPane::UpdateMixerChannelVolume(int channelIndex)
{
   Widget &widget =
    GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider1, channelIndex % NR_OF_CHANNEL_SLIDERS);
   ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
   valueWidget.SetValue(_mixerSubModel.GetChannelVolume(channelIndex));
}

void SlidersPane::CheckUpdateMixerChannelLevelLeft(int &index, ChangedProperties::EChangedProperty changedProperty)
{
   index = ChangedProperties::GetIndexOfMixerChannelLevelLeftProperty(changedProperty);
   if ((changedProperty >= ChangedProperties::EChangedProperty::MixerChannel1LevelLeft) &&
       (index < MixerSubModel::NR_OF_MIXER_CHANNELS))
   {
      if (IsChannelIndexActive(index))
      {
         UpdateMixerChannelLevelLeft(index);
      }
   }
}

void SlidersPane::UpdateMixerChannelLevelLeft(int channelIndex)
{
   Widget &widget =
    GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider1LevelLeft, channelIndex % NR_OF_CHANNEL_SLIDERS);
   ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
   valueWidget.SetValue(_mixerSubModel.GetChannelLevelLeft(channelIndex));
}

void SlidersPane::CheckUpdateMixerChannelLevelRight(int &index, ChangedProperties::EChangedProperty changedProperty)
{
   index = ChangedProperties::GetIndexOfMixerChannelLevelRightProperty(changedProperty);
   if ((changedProperty >= ChangedProperties::EChangedProperty::MixerChannel1LevelRight) &&
       (index < MixerSubModel::NR_OF_MIXER_CHANNELS))
   {
      if (IsChannelIndexActive(index))
      {
         UpdateMixerChannelLevelRight(index);
      }
   }
}

void SlidersPane::UpdateMixerChannelLevelRight(int channelIndex)
{
   Widget &widget = GetWidgets().GetWidget(
    WidgetIds::EWidgetId::PrimaryKeyboardSlider1LevelRight, channelIndex % NR_OF_CHANNEL_SLIDERS);
   ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
   valueWidget.SetValue(_mixerSubModel.GetChannelLevelRight(channelIndex));
}

/// <summary>
/// Combined widget for right/left gate.
/// </summary>
/// <param name="channelIndex"></param>
void SlidersPane::UpdateChannelGate(int channelIndex)
{
   Widget &widget = GetWidgets().GetWidget(
    WidgetIds::EWidgetId::PrimaryKeyboardSlider1SourceName, channelIndex % NR_OF_CHANNEL_SLIDERS);
   ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
   long long ms = std::max(_mixerSubModel.GetChannelLastTimeGateLeftActive(channelIndex).toMilliseconds(),
    _mixerSubModel.GetChannelLastTimeGateRightActive(channelIndex).toMilliseconds());
   UpdateWidgetForGateFading(ms, valueWidget);
}

void SlidersPane::UpdateWidgetForGateFading(long long ms, ValueWidget &valueWidget)
{
   long long ago = std::max(0LL, juce::Time::getCurrentTime().toMilliseconds() - ms);
   double red = std::max(0.0, 1.0 - (1.0 / GATE_FADE_TIME) * (ago / 1000.0));
   int thickness = std::max(0, GATE_FADE_BOX_OUTLINE_THICKNESS -
                                static_cast<int>(GATE_FADE_BOX_OUTLINE_THICKNESS / GATE_FADE_TIME * (ago / 1000.0)));

   if (!DoubleUtilities::AreEqual(valueWidget.GetWidgetOutlineColorRed(), red))
   {
      valueWidget.SetWidgetOutlineColor(red, 0.0, 0.0,
       1.0); // TODO: Check values (green/blue values, going to black?)
   }
   if (valueWidget.GetWidgetOutlineThickness() != thickness)
   {
      valueWidget.SetWidgetOutlineThickness(thickness);
   }
}

void SlidersPane::UpdateChannelName(int channelIndex)
{
   Widget &widget =
    GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider1Name, channelIndex % NR_OF_CHANNEL_SLIDERS);
   UpdateOrganRotatorSpeed &textWidget = static_cast<UpdateOrganRotatorSpeed &>(widget);
   textWidget.SetText(_mixerSubModel.GetChannelName(channelIndex));
}

void SlidersPane::CheckUpdateChannelName(int &index, ChangedProperties::EChangedProperty changedProperty)
{
   index = ChangedProperties::GetIndexOfChannelNameProperty(changedProperty);
   if ((changedProperty >= ChangedProperties::EChangedProperty::Channel1Name) &&
       (index < MixerSubModel::NR_OF_MIXER_CHANNELS))
   {
      if (IsChannelIndexActive(index))
      {
         UpdateChannelName(index);
      }
   }
}

void SlidersPane::CheckUpdateChannelSource(int &index, ChangedProperties::EChangedProperty changedProperty)
{
   index = ChangedProperties::GetIndexOfChannelSourceProperty(changedProperty);
   if ((changedProperty >= ChangedProperties::EChangedProperty::Channel1Source) &&
       (index < MixerSubModel::NR_OF_MIXER_CHANNELS))
   {
      if (IsChannelIndexActive(index))
      {
         UpdateChannelSource(index);
      }
   }
}

void SlidersPane::UpdateChannelSource(int channelIndex)
{
   Widget &widget = GetWidgets().GetWidget(
    WidgetIds::EWidgetId::PrimaryKeyboardSlider1SourceName, channelIndex % NR_OF_CHANNEL_SLIDERS);
   UpdateOrganRotatorSpeed &textWidget = static_cast<UpdateOrganRotatorSpeed &>(widget);
   textWidget.SetText(_mixerSubModel.GetChannelSourceName(channelIndex));

   int channelOffset = _mixerSubModel.GetChannelOffset();
   if (channelOffset >= 0)
   {
      Widget &boxWidget =
       GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSliderBox1, channelIndex % NR_OF_CHANNEL_SLIDERS);
      ShapeWidget &shapeWidget = static_cast<ShapeWidget &>(boxWidget);

      switch (_mixerSubModel.GetChannelSource(channelIndex))
      {
      case MixerChannelSubModel::ESource::Off: shapeWidget.SetWidgetFillColor(0.1, 0.1, 0.1, 1.0); break;
      case MixerChannelSubModel::ESource::PrimaryKeyboard: shapeWidget.SetWidgetFillColor(1.0, 1.0, 0.0, 1.0); break;
      case MixerChannelSubModel::ESource::PrimaryKeyboardPads:
         shapeWidget.SetWidgetFillColor(1.0, 0.0, 1.0, 1.0);
         break;
      case MixerChannelSubModel::ESource::SecondaryKeyboard: shapeWidget.SetWidgetFillColor(0.0, 1.0, 1.0, 1.0); break;
      default: Debug::Error(__FUNCTION__, "Illelgal source");
      }
   }
}

void SlidersPane::UpdateMasterVolume()
{
   static_cast<ValueWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider9))
    .SetValue(_mixerSubModel.GetMasterVolume());
}

void SlidersPane::UpdateMasterLevelLeft()
{
   static_cast<ValueWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider9LevelLeft))
    .SetValue(_mixerSubModel.GetMasterLevelLeft());
}

void SlidersPane::UpdateMasterLevelRight()
{
   static_cast<ValueWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider9LevelRight))
    .SetValue(_mixerSubModel.GetMasterLevelRight());
}

void SlidersPane::CheckGatesFading()
{
   int channelOffset = _mixerSubModel.GetChannelOffset();
   if (channelOffset >= 0)
   {
      for (int channelIndex = channelOffset; channelIndex < channelOffset + NR_OF_CHANNEL_SLIDERS; channelIndex++)
      {
         Widget &widget = GetWidgets().GetWidget(
          WidgetIds::EWidgetId::PrimaryKeyboardSlider1SourceName, channelIndex % NR_OF_CHANNEL_SLIDERS);
         ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
         long long ms = std::max(_mixerSubModel.GetChannelLastTimeGateLeftActive(channelIndex).toMilliseconds(),
          _mixerSubModel.GetChannelLastTimeGateRightActive(channelIndex).toMilliseconds());
         UpdateWidgetForGateFading(ms, valueWidget);
      }
   }
   UpdatePropertyMasterLastTimeGate();
}
