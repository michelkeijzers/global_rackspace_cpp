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

ChannelsSetupPane::ChannelsSetupPane(View &view, MixerSubModel &mixerSubModel, double leftPercentage, double topPercentage,
 double widthPercentage, double heightPercentage)
    : Pane(view, leftPercentage, topPercentage, widthPercentage, heightPercentage), _mixerSubModel(mixerSubModel)
{
   mixerSubModel.Subscribe(*this);
}

void ChannelsSetupPane::Fill() // override
{
   GetWidgets().AddWidget(WidgetIds::EWidgetId::SyncLabelsToMixerButton,
    new ButtonWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::SyncLabelsToMixerButton, true));
   GetWidgets().AddWidget(WidgetIds::EWidgetId::ChannelIndexTextLabel,
    new UpdateOrganRotatorSpeed(GetView().GetWidgetIds(), WidgetIds::EWidgetId::ChannelIndexTextLabel, false));
   GetWidgets().AddWidget(WidgetIds::EWidgetId::NextSourceTextLabel,
    new UpdateOrganRotatorSpeed(GetView().GetWidgetIds(), WidgetIds::EWidgetId::NextSourceTextLabel, false));
   GetWidgets().AddWidget(WidgetIds::EWidgetId::VolumeOverrideTextLabel,
    new UpdateOrganRotatorSpeed(GetView().GetWidgetIds(), WidgetIds::EWidgetId::VolumeOverrideTextLabel, false));
   for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
   {
      WidgetIds::EWidgetId widgetId = WidgetIds::GetSetupChannelName(channelIndex);
      GetWidgets().AddWidget(widgetId, new UpdateOrganRotatorSpeed(GetView().GetWidgetIds(), widgetId, false));
      widgetId = WidgetIds::GetSetupChannelNumber(channelIndex);
      GetWidgets().AddWidget(widgetId, new UpdateOrganRotatorSpeed(GetView().GetWidgetIds(), widgetId, false));
      widgetId = WidgetIds::GetSetupChannelSourceName(channelIndex);
      GetWidgets().AddWidget(widgetId, new UpdateOrganRotatorSpeed(GetView().GetWidgetIds(), widgetId, false));
      widgetId = WidgetIds::GetSetupChannelNextSourceButton(channelIndex);
      GetWidgets().AddWidget(widgetId, new ButtonWidget(GetView().GetWidgetIds(), widgetId, true));
      widgetId = WidgetIds::GetSetupChannelVolumeOverrideButton(channelIndex);
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
void ChannelsSetupPane::Relayout() // override
{

   // TODO RELAYOUT
}

void ChannelsSetupPane::SetChannelName(int channelIndex)
{
   static_cast<UpdateOrganRotatorSpeed &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::SetupChannel1Name, channelIndex))
    .SetText(_mixerSubModel.GetMixerChannelSubModels()[channelIndex]->GetName());
}

void ChannelsSetupPane::SetChannelSource(int channelIndex)
{
   static_cast<UpdateOrganRotatorSpeed &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::SetupChannel1SourceName, channelIndex))
    .SetText(_mixerSubModel.GetMixerChannelSubModels()[channelIndex]->GetName());
}

void ChannelsSetupPane::SetChannelVolumeOverride(int channelIndex)
{
   static_cast<ButtonWidget &>(
    GetWidgets().GetWidget(WidgetIds::EWidgetId::SetupChannel1VolumeOverrideButton, channelIndex))
    .SetPressed(_mixerSubModel.GetMixerChannelSubModels()[channelIndex]->IsVolumeOverridden());
}
