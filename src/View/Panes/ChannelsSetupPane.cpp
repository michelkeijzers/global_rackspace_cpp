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

ChannelsSetupPane::ChannelsSetupPane(View &view, MixerSubModel &mixerSubModel)
    : Pane(view), _mixerSubModel(mixerSubModel)
{
    mixerSubModel.Subscribe(*this);
}

void ChannelsSetupPane::Fill() // override
{

    GetWidgets().AddWidget(
        WidgetIds::EWidgetId::SyncLabelsToMixerButton,
        new ButtonWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::SyncLabelsToMixerButton, true));

    GetWidgets().AddWidget(WidgetIds::EWidgetId::ChannelIndexTextLabel,
                           new TextWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::ChannelIndexTextLabel, true));

    GetWidgets().AddWidget(WidgetIds::EWidgetId::NextSourceTextLabel,
                           new TextWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::NextSourceTextLabel, true));

    GetWidgets().AddWidget(
        WidgetIds::EWidgetId::VolumeOverrideTextLabel,
        new TextWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::VolumeOverrideTextLabel, true));

    for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
    {
        WidgetIds::EWidgetId widgetId =
            (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::SetupChannel1Name + channelIndex);
        GetWidgets().AddWidget(widgetId, new TextWidget(GetView().GetWidgetIds(), widgetId, false));

        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::SetupChannel1Number + channelIndex);
        GetWidgets().AddWidget(widgetId, new TextWidget(GetView().GetWidgetIds(), widgetId, false));

        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::SetupChannel1SourceName + channelIndex);
        GetWidgets().AddWidget(widgetId, new TextWidget(GetView().GetWidgetIds(), widgetId, false));

        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::SetupChannel1NextSourceButton + channelIndex);
        GetWidgets().AddWidget(widgetId, new ButtonWidget(GetView().GetWidgetIds(), widgetId, true));

        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::SetupChannel1VolumeOverrideButton + channelIndex);
        GetWidgets().AddWidget(widgetId, new ButtonWidget(GetView().GetWidgetIds(), widgetId, true));
    }
}

void ChannelsSetupPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
    if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::Channel1Name) &&
        ((int)changedProperty <
         (int)ChangedProperties::EChangedProperty::Channel1Name + MixerSubModel::NR_OF_MIXER_CHANNELS))
    {
        int channelIndex = (int)changedProperty - (int)ChangedProperties::EChangedProperty::Channel1Name;
        SetChannelName(channelIndex);
    }

    if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::Channel1Source) &&
        ((int)changedProperty <
         (int)ChangedProperties::EChangedProperty::Channel1Source + MixerSubModel::NR_OF_MIXER_CHANNELS))
    {
        int channelIndex = (int)changedProperty - (int)ChangedProperties::EChangedProperty::Channel1Source;
        SetChannelSource(channelIndex);
    }

    if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::Channel1VolumeOverride) &&
        ((int)changedProperty <
         (int)ChangedProperties::EChangedProperty::Channel1VolumeOverride + MixerSubModel::NR_OF_MIXER_CHANNELS))
    {
        int channelIndex = (int)changedProperty - (int)ChangedProperties::EChangedProperty::Channel1VolumeOverride;
        SetChannelVolumeOverride(channelIndex);
    }
}

void ChannelsSetupPane::SetChannelName(int channelIndex)
{
    const std::string &channelName = _mixerSubModel.GetMixerChannelSubModels()[channelIndex]->GetName();

    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::SetupChannel1Name, channelIndex);
    TextWidget &valueWidget = static_cast<TextWidget &>(widget);
    valueWidget.SetText(_mixerSubModel.GetMixerChannelSubModels()[channelIndex]->GetName());
}

void ChannelsSetupPane::SetChannelSource(int channelIndex)
{
    const std::string &channelName = _mixerSubModel.GetMixerChannelSubModels()[channelIndex]->GetName();

    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::SetupChannel1SourceName, channelIndex);
    TextWidget &valueWidget = static_cast<TextWidget &>(widget);
    valueWidget.SetText(_mixerSubModel.GetMixerChannelSubModels()[channelIndex]->GetName());
}

void ChannelsSetupPane::SetChannelVolumeOverride(int channelIndex)
{
    const std::string &channelName = _mixerSubModel.GetMixerChannelSubModels()[channelIndex]->GetName();

    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::SetupChannel1VolumeOverrideButton, channelIndex);
    ButtonWidget &valueWidget = static_cast<ButtonWidget &>(widget);
    valueWidget.SetPressed(_mixerSubModel.GetMixerChannelSubModels()[channelIndex]->IsVolumeOverridden());
}
