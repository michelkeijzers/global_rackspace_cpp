#include "SlidersPane.h"
#include "../../Model/MixerSubModel.h"
#include "../../Model/OrganSubModel.h"
#include "../../Utilities/Debug.h"
#include "../../Widgets/ValueWidget.h"
#include "../View.h"

SlidersPane::SlidersPane(View &view, MixerSubModel &mixerSubModel, OrganSubModel &organSubModel)
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

void SlidersPane::Fill() // override
{
    WidgetIds::EWidgetId widgetId;

    // Add sliders, and names for channels and master volume.
    for (int sliderIndex = 0; sliderIndex < NR_OF_SLIDERS; sliderIndex++)
    {
        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::PrimaryKeyboardSlider1 + sliderIndex);
        GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));

        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::PrimaryKeyboardSlider1LevelLeft + 2 * sliderIndex);
        GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));

        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::PrimaryKeyboardSlider1LevelRight + 2 * sliderIndex);
        GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));

		  widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::PrimaryKeyboardSlider1Name + sliderIndex);
        GetWidgets().AddWidget(widgetId, new TextWidget(GetView().GetWidgetIds(), widgetId, true));

        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::PrimaryKeyboardSlider1SourceName + sliderIndex);
        GetWidgets().AddWidget(widgetId, new TextWidget(GetView().GetWidgetIds(), widgetId, true));
    }

    // Add organ drawbars.
    for (int drawbarIndex = 0; drawbarIndex < OrganSubModel::NR_OF_DRAWBARS; drawbarIndex++)
    {
        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::OrganDrawbar1 + drawbarIndex);
        GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));
    }

    // Add organ drive and reverbAmount.
    widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::OrganDrive);
    GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));

    widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::OrganReverbAmount);
    GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));
}

void SlidersPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
    if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::MixerChannel1Volume) &&
        ((int)changedProperty <
         (int)ChangedProperties::EChangedProperty::MixerChannel1Volume + MixerSubModel::NR_OF_MIXER_CHANNELS))
    {
        int channelIndex = (int)changedProperty - (int)ChangedProperties::EChangedProperty::MixerChannel1Volume;
        if (IsChannelIndexActive(channelIndex))
        {
            SetChannelVolume(channelIndex);
        }
    }

    else if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::MixerChannel1LevelLeft) &&
        ((int)changedProperty <
         (int)ChangedProperties::EChangedProperty::MixerChannel1LevelLeft + MixerSubModel::NR_OF_MIXER_CHANNELS))
    {
        int channelIndex = (int)changedProperty - (int)ChangedProperties::EChangedProperty::MixerChannel1LevelLeft;
        if (IsChannelIndexActive(channelIndex))
        {
            SetChannelLevelLeft(channelIndex);
        }
    }

    else if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::MixerChannel1LevelRight) &&
        ((int)changedProperty <
         (int)ChangedProperties::EChangedProperty::MixerChannel1LevelRight + MixerSubModel::NR_OF_MIXER_CHANNELS))
    {
        int channelIndex = (int)changedProperty - (int)ChangedProperties::EChangedProperty::MixerChannel1LevelRight;
        if (IsChannelIndexActive(channelIndex))
        {
            SetChannelLevelRight(channelIndex);
        }
    }

 	 else if (changedProperty == ChangedProperties::EChangedProperty::MasterLevelLeft)
    {
        Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider9LevelLeft);
        ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
        valueWidget.SetValue(_mixerSubModel.GetMasterLevelLeft());
    }

	 else if (changedProperty == ChangedProperties::EChangedProperty::MasterLevelRight)
    {
        Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider9LevelRight);
        ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
        valueWidget.SetValue(_mixerSubModel.GetMasterLevelRight());
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
    
	 else if (changedProperty == ChangedProperties::EChangedProperty::OrganDrive)
    {
        Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganDrive);
        ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
        valueWidget.SetValue(_organSubModel.GetDrive());
    }

	 else if (changedProperty == ChangedProperties::EChangedProperty::OrganReverbAmount)
    {
        Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganReverbAmount);
        ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
        valueWidget.SetValue(_organSubModel.GetReverbAmount());
    }

    if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::Channel1Name) &&
        ((int)changedProperty <
         (int)ChangedProperties::EChangedProperty::Channel1Name + MixerSubModel::NR_OF_MIXER_CHANNELS))
    {
        int channelIndex = (int)changedProperty - (int)ChangedProperties::EChangedProperty::Channel1Name;
        if (IsChannelIndexActive(channelIndex))
        {
            SetChannelName(channelIndex);
        }
    }
    if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::Channel1Source) &&
        ((int)changedProperty <
         (int)ChangedProperties::EChangedProperty::Channel1Source + MixerSubModel::NR_OF_MIXER_CHANNELS))
    {
        int channelIndex = (int)changedProperty - (int)ChangedProperties::EChangedProperty::Channel1Source;
        if (IsChannelIndexActive(channelIndex))
        {
            SetChannelSource(channelIndex);
        }
    }
}

bool SlidersPane::IsChannelIndexActive(int channelIndex)
{
    MixerSubModel::EPaneSelection paneSelection = _mixerSubModel.GetPaneSelection();
    return (
        ((paneSelection == MixerSubModel::EPaneSelection::Channels1To8) && (0 <= channelIndex) && (channelIndex < 8)) ||
        ((paneSelection == MixerSubModel::EPaneSelection::Channels9To16) && (8 <= channelIndex) &&
         (channelIndex < 16)) ||
        ((paneSelection == MixerSubModel::EPaneSelection::Channels17To23) && (16 <= channelIndex) &&
         (channelIndex < 24)));
}

void SlidersPane::SetChannelVolume(int channelIndex)
{
    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider1, channelIndex % 8);
    ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
    valueWidget.SetValue(_mixerSubModel.GetChannelVolume(channelIndex));
}

void SlidersPane::SetChannelLevelLeft(int channelIndex)
{
    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider1LevelLeft, channelIndex % 8);
    ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
    valueWidget.SetValue(_mixerSubModel.GetChannelLevelLeft(channelIndex));
}

void SlidersPane::SetChannelLevelRight(int channelIndex)
{
    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider1LevelRight, channelIndex % 8);
    ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
    valueWidget.SetValue(_mixerSubModel.GetChannelLevelRight(channelIndex));
}

void SlidersPane::SetChannelName(int channelIndex)
{
    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider1Name, channelIndex % 8);
    TextWidget &textWidget = static_cast<TextWidget &>(widget);
    textWidget.SetText(_mixerSubModel.GetChannelName(channelIndex));
}

void SlidersPane::SetChannelSource(int channelIndex)
{
    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider1SourceName, channelIndex % 8);
    TextWidget &textWidget = static_cast<TextWidget &>(widget);
    textWidget.SetText(_mixerSubModel.GetChannelSourceName(channelIndex));
}