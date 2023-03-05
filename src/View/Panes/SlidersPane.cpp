#include "SlidersPane.h"
#include "../../Model/MixerSubModel.h"
#include "../../Model/OrganSubModel.h"
#include "../../Utilities/Debug.h"
#include "../../Widgets/ValueWidget.h"
#include "../View.h"

SlidersPane::SlidersPane(View &view, MixerSubModel &mixerSubModel, OrganSubModel& organSubModel)
    : Pane(view), _mixerSubModel(mixerSubModel), _organSubModel(organSubModel)
{
    for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
    {
        MixerChannelSubModel &mixerChannelSubModel = *_mixerSubModel.GetMixerChannelSubModels()[channelIndex];
        _mixerChannelSubModels.push_back(&mixerChannelSubModel);
        mixerChannelSubModel.Subscribe(*this);
    }

    _mixerSubModel.Subscribe(*this);
    _organSubModel.Subscribe(*this);
}

void SlidersPane::Init() // override
{
}

void SlidersPane::Fill() // override
{
    WidgetIds::EWidgetId widgetId;

	 // Add sliders for channels and master volume.
    for (int sliderIndex = 0; sliderIndex < NR_OF_SLIDERS; sliderIndex++)
    {
        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::PrimaryKeyboardSlider1 + sliderIndex);
        GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));
    }

	 // Add organ drawbars.
	 for (int drawbarIndex = 0; drawbarIndex < OrganSubModel::NR_OF_DRAWBARS; drawbarIndex++)
    {
        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::OrganDrawbar1 + drawbarIndex);
        GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));
    }

	 // Add organ overdrive and reverb.
    widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::OrganOverdrive);
    GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));

    widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::OrganReverb);
    GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));
}

void SlidersPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
    if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::MixerChannel1Volume) &&
        ((int)changedProperty < (int)ChangedProperties::EChangedProperty::MixerChannel1Volume +
            MixerSubModel::NR_OF_MIXER_CHANNELS))
    {
        int channelIndex = (int)changedProperty - (int)ChangedProperties::EChangedProperty::MixerChannel1Volume;

        switch (_mixerSubModel.GetPaneSelection())
        {
        case MixerSubModel::EPaneSelection::Drawbars:
            break;

        case MixerSubModel::EPaneSelection::Channels1To8:
            if (channelIndex < 8)
            {
                SetChannelVolume(channelIndex);
            }
            break;

        case MixerSubModel::EPaneSelection::Channels9To16:
            if ((channelIndex >= 8) && (channelIndex < 16))
            {
                SetChannelVolume(channelIndex);
            }
            break;

        case MixerSubModel::EPaneSelection::Channels17To23:
            if ((channelIndex >= 16) && (channelIndex < 24))
            {
                SetChannelVolume(channelIndex);
            }
            break;

        default:
            Debug::Error(__FUNCTION__, "Illegal pane selection");
            break;
        }
    }
    else if (changedProperty == ChangedProperties::EChangedProperty::MasterVolume)
    {
        Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider9);
        ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
        valueWidget.SetValue(_mixerSubModel.GetMasterVolume());
    }
 	 else if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::OrganDrawbar1) &&
        ((int)changedProperty <
         (int)ChangedProperties::EChangedProperty::OrganDrawbar1 + OrganSubModel::NR_OF_DRAWBARS))
    {
        int drawbarIndex = (int)changedProperty - (int)ChangedProperties::EChangedProperty::OrganDrawbar1;
        Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganDrawbar1, drawbarIndex);
        ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
        valueWidget.SetValue(_organSubModel.GetDrawbarValue(drawbarIndex));
    }
    else if (changedProperty == ChangedProperties::EChangedProperty::OrganOverdrive)
    {
        Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganOverdrive);
        ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
        valueWidget.SetValue(_organSubModel.GetOverdrive());
	 }
    else if (changedProperty == ChangedProperties::EChangedProperty::OrganReverb)
    {
        Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganReverb);
        ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
        valueWidget.SetValue(_organSubModel.GetReverb());
    }
}

void SlidersPane::SetChannelVolume(int channelIndex)
{
    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider1, channelIndex % 8);
    ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
    valueWidget.SetValue(_mixerSubModel.GetChannelVolume(channelIndex));
}