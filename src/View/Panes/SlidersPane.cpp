#include "SlidersPane.h"
#include "../../Model/MixerSubModel.h"
#include "../../Utilities/Debug.h"
#include "../../Widgets/ValueWidget.h"
#include "../View.h"

SlidersPane::SlidersPane(View &view, MixerSubModel &mixerSubModel) : Pane(view), _mixerSubModel(mixerSubModel)
{
    for (int channelIndex = 0; channelIndex < MixerSubModel::NR_OF_MIXER_CHANNELS; channelIndex++)
    {
        MixerChannelSubModel &mixerChannelSubModel = *_mixerSubModel.GetMixerChannelSubModels()[channelIndex];
        _mixerChannelSubModels.push_back(&mixerChannelSubModel);
        mixerChannelSubModel.Subscribe(*this);
    }

    _mixerSubModel.Subscribe(*this);
}

void SlidersPane::Init() // override
{
}

void SlidersPane::Fill() // override
{
	 // Add sliders for channels and master volume.
    for (int sliderIndex = 0; sliderIndex < NR_OF_SLIDERS; sliderIndex++)
    {
        WidgetIds::EWidgetId widgetId =
            (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::PrimaryKeyboardSlider1 + sliderIndex);
        GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));
    }
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
}

void SlidersPane::SetChannelVolume(int channelIndex)
{
    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider1, channelIndex % 8);
    ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
    valueWidget.SetValue(_mixerSubModel.GetChannelVolume(channelIndex));
}