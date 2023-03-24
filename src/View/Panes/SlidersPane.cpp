#include "SlidersPane.h"
#include "../../Model/MixerSubModel.h"
#include "../../Model/Model.h"
#include "../../Model/OrganSubModel.h"
#include "../../Utilities/Debug.h"
#include "../../Utilities/DoubleUtilities.h"
#include "../../Widgets/ValueWidget.h"
#include "../View.h"
#include <juce_core/juce_core.h>
#include <juce_core/time/juce_Time.h>

#include "../../Framework/MvcFramework.h"

SlidersPane::SlidersPane(View &view, Model &model, MixerSubModel &mixerSubModel, OrganSubModel &organSubModel)
    : Pane(view), _model(model), _mixerSubModel(mixerSubModel), _organSubModel(organSubModel)
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
        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::PrimaryKeyboardSliderBox1 + sliderIndex);
        GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));
        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::PrimaryKeyboardSlider1 + sliderIndex);
        GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));
        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::PrimaryKeyboardSlider1LevelLeft + sliderIndex);
        GetWidgets().AddWidget(widgetId, new ValueWidget(GetView().GetWidgetIds(), widgetId, true));
        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::PrimaryKeyboardSlider1LevelRight + sliderIndex);
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
    if (changedProperty == ChangedProperties::EChangedProperty::SlidersTabSelection)
    {
        UpdateTab();
    }
    else if (changedProperty == ChangedProperties::EChangedProperty::SecondElapsed)
    {
        CheckGatesFading();
    }

    else if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::OrganDrawbar1) &&
             ((int)changedProperty <
              (int)ChangedProperties::EChangedProperty::OrganDrawbar1 + OrganSubModel::NR_OF_DRAWBARS))
    {
        int drawbarIndex = (int)changedProperty - (int)ChangedProperties::EChangedProperty::OrganDrawbar1;
        UpdateDrawbar(drawbarIndex);
    }

    else if (changedProperty == ChangedProperties::EChangedProperty::OrganDrive)
    {
        UpdateOrganDrive();
    }

    else if (changedProperty == ChangedProperties::EChangedProperty::OrganReverbAmount)
    {
        UpdateOrganReverbAmount();
    }

    else if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::MixerChannel1Volume) &&
             ((int)changedProperty <
              (int)ChangedProperties::EChangedProperty::MixerChannel1Volume + MixerSubModel::NR_OF_MIXER_CHANNELS))
    {
        int channelIndex = (int)changedProperty - (int)ChangedProperties::EChangedProperty::MixerChannel1Volume;
        if (IsChannelIndexActive(channelIndex))
        {
            UpdateChannelVolume(channelIndex);
        }
    }

    else if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::MixerChannel1LevelLeft) &&
             ((int)changedProperty <
              (int)ChangedProperties::EChangedProperty::MixerChannel1LevelLeft + MixerSubModel::NR_OF_MIXER_CHANNELS))
    {
        int channelIndex = (int)changedProperty - (int)ChangedProperties::EChangedProperty::MixerChannel1LevelLeft;
        if (IsChannelIndexActive(channelIndex))
        {
            UpdateChannelLevelLeft(channelIndex);
        }
    }

    else if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::MixerChannel1LevelRight) &&
             ((int)changedProperty <
              (int)ChangedProperties::EChangedProperty::MixerChannel1LevelRight + MixerSubModel::NR_OF_MIXER_CHANNELS))
    {
        int channelIndex = (int)changedProperty - (int)ChangedProperties::EChangedProperty::MixerChannel1LevelRight;
        if (IsChannelIndexActive(channelIndex))
        {
            UpdateChannelLevelRight(channelIndex);
        }
    }

    else if (changedProperty == ChangedProperties::EChangedProperty::MasterLevelLeft)
    {
        UpdateMasterLevelLeft();
    }

    else if (changedProperty == ChangedProperties::EChangedProperty::MasterLevelRight)
    {
        UpdateMasterLevelRight();
    }

    else if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::MixerChannel1LastTimeGateLeftActive) &&
             ((int)changedProperty < (int)ChangedProperties::EChangedProperty::MixerChannel1LastTimeGateLeftActive +
                                         MixerSubModel::NR_OF_MIXER_CHANNELS))
    {
        int channelIndex =
            (int)changedProperty - (int)ChangedProperties::EChangedProperty::MixerChannel1LastTimeGateLeftActive;
        if (IsChannelIndexActive(channelIndex))
        {
            UpdateChannelGate(channelIndex);
        }
    }

    else if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::MixerChannel1LastTimeGateRightActive) &&
             ((int)changedProperty < (int)ChangedProperties::EChangedProperty::MixerChannel1LastTimeGateRightActive +
                                         MixerSubModel::NR_OF_MIXER_CHANNELS))
    {
        int channelIndex =
            (int)changedProperty - (int)ChangedProperties::EChangedProperty::MixerChannel1LastTimeGateRightActive;
        if (IsChannelIndexActive(channelIndex))
        {
            UpdateChannelGate(channelIndex);
        }
    }

    else if ((changedProperty == ChangedProperties::EChangedProperty::MasterLastTimeGateLeftActive) ||
             (changedProperty == ChangedProperties::EChangedProperty::MasterLastTimeGateRightActive))
    {
        UpdatePropertyMasterLastTimeGate();
    }

    else if (changedProperty == ChangedProperties::EChangedProperty::MasterVolume)
    {
        UpdateMasterVolume();
    }

    if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::Channel1Name) &&
        ((int)changedProperty <
         (int)ChangedProperties::EChangedProperty::Channel1Name + MixerSubModel::NR_OF_MIXER_CHANNELS))
    {
        int channelIndex = (int)changedProperty - (int)ChangedProperties::EChangedProperty::Channel1Name;
        if (IsChannelIndexActive(channelIndex))
        {
            UpdateChannelName(channelIndex);
        }
    }
    if (((int)changedProperty >= (int)ChangedProperties::EChangedProperty::Channel1Source) &&
        ((int)changedProperty <
         (int)ChangedProperties::EChangedProperty::Channel1Source + MixerSubModel::NR_OF_MIXER_CHANNELS))
    {
        int channelIndex = (int)changedProperty - (int)ChangedProperties::EChangedProperty::Channel1Source;
        if (IsChannelIndexActive(channelIndex))
        {
            UpdateChannelSource(channelIndex);
        }
    }
}

void SlidersPane::UpdateTab()
{
    bool drawbarsSelected = _mixerSubModel.GetTabSelection() == MixerSubModel::ETabSelection::Drawbars;

    UpdateTabShowSliders(drawbarsSelected);
    UpdateTabShowOrganWidgets(drawbarsSelected);
    UpdateTabUpdateValues(drawbarsSelected);
}

void SlidersPane::UpdateTabShowOrganWidgets(bool drawbarsSelected)
{
    WidgetIds::EWidgetId widgetId;

    for (int drawbarIndex = 0; drawbarIndex < OrganSubModel::NR_OF_DRAWBARS; drawbarIndex++)
    {
        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::OrganDrawbar1 + drawbarIndex);
        GetWidgets().GetWidget(widgetId).Show(drawbarsSelected);
    }

    // Add organ drive and reverbAmount.
    widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::OrganDrive);
    GetWidgets().GetWidget(widgetId).Show(drawbarsSelected);

    widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::OrganReverbAmount);
    GetWidgets().GetWidget(widgetId).Show(drawbarsSelected);
}

void SlidersPane::UpdateTabShowSliders(bool drawbarsSelected)
{
    WidgetIds::EWidgetId widgetId;

    for (int sliderIndex = 0; sliderIndex < NR_OF_SLIDERS; sliderIndex++)
    {
        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::PrimaryKeyboardSliderBox1 + sliderIndex);
        GetWidgets().GetWidget(widgetId).Show(!drawbarsSelected);

        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::PrimaryKeyboardSlider1 + sliderIndex);
        GetWidgets().GetWidget(widgetId).Show(!drawbarsSelected);

        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::PrimaryKeyboardSlider1LevelLeft + sliderIndex);
        GetWidgets().GetWidget(widgetId).Show(!drawbarsSelected);

        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::PrimaryKeyboardSlider1LevelRight + sliderIndex);
        GetWidgets().GetWidget(widgetId).Show(!drawbarsSelected);

        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::PrimaryKeyboardSlider1Name + sliderIndex);
        GetWidgets().GetWidget(widgetId).Show(!drawbarsSelected);

        widgetId = (WidgetIds::EWidgetId)((int)WidgetIds::EWidgetId::PrimaryKeyboardSlider1SourceName + sliderIndex);
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
        UpdateOrganDrive();
        UpdateOrganReverbAmount();
    }
    else
    {
        int channelOffset = _mixerSubModel.GetChannelOffset();
        for (int sliderIndex = 0; sliderIndex < NR_OF_CHANNEL_SLIDERS; sliderIndex++)
        {
            int channelIndex = channelOffset + sliderIndex;
            UpdateChannelGate(channelIndex);
            UpdateChannelLevelLeft(channelIndex);
            UpdateChannelLevelRight(channelIndex);
            UpdateChannelName(channelIndex);
            UpdateChannelSource(channelIndex);
            UpdateChannelVolume(channelIndex);
        }
        UpdatePropertyMasterLastTimeGate();
        UpdateMasterVolume();
        UpdateMasterLevelLeft();
        UpdateMasterLevelRight();
    }
}

void SlidersPane::UpdateDrawbar(int drawbarIndex)
{
    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganDrawbar1, drawbarIndex);
    ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
    valueWidget.SetValue(_organSubModel.GetDrawbars(drawbarIndex));
}

void SlidersPane::UpdateOrganDrive()
{
    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganDrive);
    ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
    valueWidget.SetValue(_organSubModel.GetDrive());
}

void SlidersPane::UpdateOrganReverbAmount()
{
    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganReverbAmount);
    ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
    valueWidget.SetValue(_organSubModel.GetReverbAmount());
}

void SlidersPane::UpdatePropertyMasterLastTimeGate()
{
    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider9SourceName);
    ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
    long long ms = std::max(_mixerSubModel.GetMasterLastTimeGateLeftActive().toMilliseconds(),
                            _mixerSubModel.GetMasterLastTimeGateRightActive().toMilliseconds());
    UpdateWidgetForGateFading(ms, valueWidget);
}

bool SlidersPane::IsChannelIndexActive(int channelIndex)
{
    MixerSubModel::ETabSelection tabSelection = _mixerSubModel.GetTabSelection();
    return (
        ((tabSelection == MixerSubModel::ETabSelection::Channels1To8) && (0 <= channelIndex) && (channelIndex < 8)) ||
        ((tabSelection == MixerSubModel::ETabSelection::Channels9To16) && (8 <= channelIndex) && (channelIndex < 16)) ||
        ((tabSelection == MixerSubModel::ETabSelection::Channels17To24) && (16 <= channelIndex) &&
         (channelIndex < 24)));
}

void SlidersPane::UpdateChannelVolume(int channelIndex)
{
    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider1, channelIndex % 8);
    ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
    valueWidget.SetValue(_mixerSubModel.GetChannelVolume(channelIndex));
}

void SlidersPane::UpdateChannelLevelLeft(int channelIndex)
{
    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider1LevelLeft, channelIndex % 8);
    ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
    valueWidget.SetValue(_mixerSubModel.GetChannelLevelLeft(channelIndex));
}

void SlidersPane::UpdateChannelLevelRight(int channelIndex)
{
    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider1LevelRight, channelIndex % 8);
    ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
    valueWidget.SetValue(_mixerSubModel.GetChannelLevelRight(channelIndex));
}

/// <summary>
/// Combined widget for right/left gate.
/// </summary>
/// <param name="channelIndex"></param>
void SlidersPane::UpdateChannelGate(int channelIndex)
{
    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider1SourceName, channelIndex % 8);
    ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
    long long ms = std::max(_mixerSubModel.GetChannelLastTimeGateLeftActive(channelIndex).toMilliseconds(),
                            _mixerSubModel.GetChannelLastTimeGateRightActive(channelIndex).toMilliseconds());
    UpdateWidgetForGateFading(ms, valueWidget);
}

void SlidersPane::UpdateWidgetForGateFading(long long ms, ValueWidget &valueWidget)
{
    long long ago = std::max(0LL, juce::Time::getCurrentTime().toMilliseconds() - ms);
    double red = std::max(0.0, 1.0 - (1.0 / 30) * (ago / 1000.0));
    int thickness = std::max(0, 5 - (int)(5 / 30.0 * (ago / 1000.0)));

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
    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider1Name, channelIndex % 8);
    TextWidget &textWidget = static_cast<TextWidget &>(widget);
    textWidget.SetText(_mixerSubModel.GetChannelName(channelIndex));
}

void SlidersPane::UpdateChannelSource(int channelIndex)
{
    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider1SourceName, channelIndex % 8);
    TextWidget &textWidget = static_cast<TextWidget &>(widget);
    textWidget.SetText(_mixerSubModel.GetChannelSourceName(channelIndex));

    int channelOffset = _mixerSubModel.GetChannelOffset();
    if (channelOffset >= 0)
    {
        Widget &boxWidget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSliderBox1, channelIndex % 8);
        ShapeWidget &shapeWidget = static_cast<ShapeWidget &>(boxWidget);

        switch (_mixerSubModel.GetChannelSource(channelIndex))
        {
        case MixerChannelSubModel::ESource::Off:
            shapeWidget.SetWidgetFillColor(0.1, 0.1, 0.1, 1.0);
            break;

        case MixerChannelSubModel::ESource::PrimaryKeyboard:
            shapeWidget.SetWidgetFillColor(1.0, 1.0, 0.0, 1.0);
            break;

        case MixerChannelSubModel::ESource::PrimaryKeyboardPads:
            shapeWidget.SetWidgetFillColor(1.0, 0.0, 1.0, 1.0);
            break;

        case MixerChannelSubModel::ESource::SecondaryKeyboard:
            shapeWidget.SetWidgetFillColor(0.0, 1.0, 1.0, 1.0);
            break;

        default:
            Debug::Error(__FUNCTION__, "Illelgal source");
        }
    }
}

void SlidersPane::UpdateMasterVolume()
{
    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider9);
    ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
    valueWidget.SetValue(_mixerSubModel.GetMasterVolume());
}

void SlidersPane::UpdateMasterLevelLeft()
{
    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider9LevelLeft);
    ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
    valueWidget.SetValue(_mixerSubModel.GetMasterLevelLeft());
}

void SlidersPane::UpdateMasterLevelRight()
{
    Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider9LevelRight);
    ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
    valueWidget.SetValue(_mixerSubModel.GetMasterLevelRight());
}

void SlidersPane::CheckGatesFading()
{
    int channelOffset = _mixerSubModel.GetChannelOffset();
    if (channelOffset >= 0)
    {
        for (int channelIndex = channelOffset; channelIndex < channelOffset + NR_OF_CHANNEL_SLIDERS; channelIndex++)
        {
            Widget &widget =
                GetWidgets().GetWidget(WidgetIds::EWidgetId::PrimaryKeyboardSlider1SourceName, channelIndex % 8);
            ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
            long long ms = std::max(_mixerSubModel.GetChannelLastTimeGateLeftActive(channelIndex).toMilliseconds(),
                                    _mixerSubModel.GetChannelLastTimeGateRightActive(channelIndex).toMilliseconds());

            UpdateWidgetForGateFading(ms, valueWidget);
        }
    }
    UpdatePropertyMasterLastTimeGate();
}
