#include "ChannelsSetupPane.h"
#include "../../Framework/MvcFramework.h"
#include "../../Model/OrganSubModel.h"
#include "../../Utilities/Debug.h"
#include "../../Widgets/ButtonWidget.h"
#include "../../Widgets/TextWidget.h"
#include "../../Widgets/ValueWidget.h"
#include "../../Widgets/Widget.h"
#include "../ChangedProperties.h"
#include "../IObserver.h"
#include "../View.h"
#include "SlidersPane.h"

ChannelsSetupPane::ChannelsSetupPane(View &view, MixerSubModel &mixerSubModel, double leftPercentage, double topPercentage,
 double widthPercentage, double heightPercentage)
    : Pane(view, leftPercentage, topPercentage, widthPercentage, heightPercentage), _mixerSubModel(mixerSubModel)
{
   mixerSubModel.Subscribe(*this);
}

void ChannelsSetupPane::Fill() // override
{
   WidgetIds::EWidgetId widgetId = WidgetIds::EWidgetId::ChannelsSetupPaneBox;
   GetWidgets().AddWidget(widgetId, new ShapeWidget(GetView().GetWidgetIds(), widgetId, false));
   widgetId = WidgetIds::EWidgetId::ChannelsSetupPaneTitleTextLabel;
   GetWidgets().AddWidget(widgetId, new TextWidget(GetView().GetWidgetIds(), widgetId, false));
   widgetId = WidgetIds::EWidgetId::SyncLabelsToMixerButton;
   GetWidgets().AddWidget(widgetId, new ButtonWidget(GetView().GetWidgetIds(), widgetId, true));
   widgetId = WidgetIds::EWidgetId::ChannelIndexTextLabel;
   GetWidgets().AddWidget(widgetId, new TextWidget(GetView().GetWidgetIds(), widgetId, true));
   widgetId = WidgetIds::EWidgetId::NextSourceTextLabel;
   GetWidgets().AddWidget(widgetId, new TextWidget(GetView().GetWidgetIds(), widgetId, true));
   widgetId = WidgetIds::EWidgetId::VolumeOverrideTextLabel;
   GetWidgets().AddWidget(widgetId, new TextWidget(GetView().GetWidgetIds(), widgetId, true));
   for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
   {
      widgetId = WidgetIds::GetChannelsSetupName(channelIndex);
      GetWidgets().AddWidget(widgetId, new TextWidget(GetView().GetWidgetIds(), widgetId, false));
      widgetId = WidgetIds::GetChannelsSetupNumber(channelIndex);
      GetWidgets().AddWidget(widgetId, new TextWidget(GetView().GetWidgetIds(), widgetId, false));
		widgetId = WidgetIds::GetChannelsSetupNextSourceButton(channelIndex);
      GetWidgets().AddWidget(widgetId, new ButtonWidget(GetView().GetWidgetIds(), widgetId, true));
      widgetId = WidgetIds::GetChannelsSetupVolumeOverrideButton(channelIndex);
      GetWidgets().AddWidget(widgetId, new ButtonWidget(GetView().GetWidgetIds(), widgetId, true));
   }
}

void ChannelsSetupPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
   int index = ChangedProperties::GetIndexOfChannelNameProperty(changedProperty);
   if ((changedProperty >= ChangedProperties::EChangedProperty::Channel1Name) &&
       (index < MixerSubModel::NR_OF_MIXER_CHANNELS))
   {
      SetChannelName(index);
   }

   index = ChangedProperties::GetIndexOfChannelSourceProperty(changedProperty);
   if ((changedProperty >= ChangedProperties::EChangedProperty::Channel1Source) &&
       (index < MixerSubModel::NR_OF_MIXER_CHANNELS))
   {
      SetChannelSource(index);
   }

   index = ChangedProperties::GetIndexOfMixerChannelVolumeProperty(changedProperty);
   if ((changedProperty >= ChangedProperties::EChangedProperty::Channel1VolumeOverride) &&
       (index < MixerSubModel::NR_OF_MIXER_CHANNELS))
   {
      SetChannelVolumeOverride(index);
   }
}

//   10% 
//   v    v 20%
//         30%                                                100%
// +--------+----------------------------------------------+----+ 0%
// | CHA    |                                              |    |     CHA : CHANNELS SETUP (Pane Title)
// +--------+                                              |    | *   *   : Over from remainder space (height)
// | [Sync] | ................ 24 ........................ |    |    [Sync]: [Sync Labels to Mixer button], Margin 10%
// |        |                                              |    |
// +---+----+----------------------------------------------+----+ 60%
// |Cha|    | ................ 24 ........................ |    |     Cha : Channel # (Text Label)
// +---+----+----------------------------------------------+----+ 70%
// |Nxt|    | ................ 24 ........................ |    |     Nxt: Next Source (Upper/Pad/Lower Text Label)
// +---+----+----------------------------------------------+----+ 85%
// |Vol|    | ................ 24 ........................ |    |     Vol: Volume Override
// +---+----+----------------------------------------------+----+ 100%

void ChannelsSetupPane::Relayout() // override
{
   const double paneTitleHeightPercentage = GetPaneTitleHeightPercentage();
   const double leftWidgetsWidthPercentage = 0.3;
   const double channelWidthPercentage = (1.0 - leftWidgetsWidthPercentage) / SlidersPane::NR_OF_SLIDERS;
   const double channelIndexHeightPercentage = 0.1;
   const double nextSourceHeightPercentage = 0.15;
   const double volumeOverrideHeightPercentage = nextSourceHeightPercentage;
   const double channelNameHeightPercentage =
    1.0 - channelIndexHeightPercentage - nextSourceHeightPercentage - volumeOverrideHeightPercentage;
   SetWidgetBounds(WidgetIds::EWidgetId::ChannelsSetupPaneBox, 0.0, 0.0, 1.0, 1.0, 0);
   SetWidgetBounds(WidgetIds::EWidgetId::ChannelsSetupPaneTitleTextLabel, 0.0, 0.0, leftWidgetsWidthPercentage,
    paneTitleHeightPercentage, 0.0);
   SetWidgetBounds(WidgetIds::EWidgetId::SyncLabelsToMixerButton, 0.0, 0.0, leftWidgetsWidthPercentage, 0.6, 0.1);
   1.0 - channelIndexHeightPercentage - nextSourceHeightPercentage - volumeOverrideHeightPercentage;
   SetWidgetBounds(WidgetIds::EWidgetId::ChannelIndexTextLabel, 0.0, channelNameHeightPercentage,
    leftWidgetsWidthPercentage, channelIndexHeightPercentage, 0.0);
   SetWidgetBounds(WidgetIds::EWidgetId::NextSourceTextLabel, 0.0,
    channelNameHeightPercentage + channelIndexHeightPercentage, leftWidgetsWidthPercentage, nextSourceHeightPercentage,
    0.0);
   SetWidgetBounds(WidgetIds::EWidgetId::VolumeOverrideTextLabel, 0.0,
    channelNameHeightPercentage + channelIndexHeightPercentage + nextSourceHeightPercentage, leftWidgetsWidthPercentage,
    volumeOverrideHeightPercentage, 0.0);
   for (int channelIndex = 0; channelIndex < SlidersPane::NR_OF_SLIDERS; channelIndex++)
   {
      SetWidgetBounds(WidgetIds::GetChannelsSetupName(channelIndex),
       leftWidgetsWidthPercentage + channelIndex * channelWidthPercentage, 0, channelWidthPercentage,
       channelNameHeightPercentage, 0.0);
      SetWidgetBounds(WidgetIds::GetChannelsSetupNumber(channelIndex),
       leftWidgetsWidthPercentage + channelIndex * channelWidthPercentage, channelNameHeightPercentage,
       channelWidthPercentage, channelIndexHeightPercentage, 0.0);
      SetWidgetBounds(WidgetIds::GetChannelsSetupNextSourceButton(channelIndex),
       leftWidgetsWidthPercentage + channelIndex * channelWidthPercentage,
       channelNameHeightPercentage + channelIndexHeightPercentage, channelWidthPercentage, nextSourceHeightPercentage,
       0.0);
      SetWidgetBounds(WidgetIds::GetChannelsSetupVolumeOverrideButton(channelIndex),
       leftWidgetsWidthPercentage + channelIndex * channelWidthPercentage,
       channelNameHeightPercentage + channelIndexHeightPercentage + nextSourceHeightPercentage, channelWidthPercentage,
       volumeOverrideHeightPercentage, 0.0);
   }
}

void ChannelsSetupPane::SetChannelName(int channelIndex)
{
   static_cast<TextWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::ChannelsSetup1Name, channelIndex))
    .SetText(_mixerSubModel.GetMixerChannelSubModels()[channelIndex]->GetName());
}

void ChannelsSetupPane::SetChannelSource(int channelIndex)
{
   static_cast<TextWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::ChannelsSetup1SourceName, channelIndex))
    .SetText(_mixerSubModel.GetMixerChannelSubModels()[channelIndex]->GetName());
}

void ChannelsSetupPane::SetChannelVolumeOverride(int channelIndex)
{
   static_cast<ButtonWidget &>(
    GetWidgets().GetWidget(WidgetIds::EWidgetId::ChannelsSetup1VolumeOverrideButton, channelIndex))
    .SetPressed(_mixerSubModel.GetMixerChannelSubModels()[channelIndex]->IsVolumeOverridden());
}
