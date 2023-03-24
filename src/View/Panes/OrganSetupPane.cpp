#include <juce_core/juce_core.h>
#include <juce_audio_basics/midi/juce_MidiMessage.h>
#include "OrganSetupPane.h"
#include "../../Framework/MvcFramework.h"
#include "../../Model/OrganSubModel.h"
#include "../../Utilities/Debug.h"
#include "../../Utilities/MidiUtilities.h"
#include "../../Widgets/ButtonWidget.h"
#include "../../Widgets/ShapeWidget.h"
#include "../../Widgets/TextWidget.h"
#include "../../Widgets/ValueWidget.h"
#include "../../Widgets/Widget.h"
#include "../ChangedProperties.h"
#include "../IObserver.h"
#include "../View.h"

OrganSetupPane::OrganSetupPane(View &view, OrganSubModel &organSubModel) : Pane(view), _organSubModel(organSubModel)
{
    organSubModel.Subscribe(*this);
}

void OrganSetupPane::Fill() // override
{
    GetWidgets().AddWidget(WidgetIds::EWidgetId::SetupOrganPaneBox,
                           new ShapeWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::SetupOrganPaneBox, false));

    GetWidgets().AddWidget(
        WidgetIds::EWidgetId::SetupOrganTitleTextLabel,
        new TextWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::SetupOrganTitleTextLabel, false));

    GetWidgets().AddWidget(
        WidgetIds::EWidgetId::SetupOrganPrimaryKeyboardActiveButton,
        new ButtonWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::SetupOrganPrimaryKeyboardActiveButton, true));

    GetWidgets().AddWidget(WidgetIds::EWidgetId::SetupOrganSecondaryKeyboardActiveButton,
                           new ButtonWidget(GetView().GetWidgetIds(),
                                            WidgetIds::EWidgetId::SetupOrganSecondaryKeyboardActiveButton, true));

    GetWidgets().AddWidget(
        WidgetIds::EWidgetId::SetupOrganLowestNoteSlider,
        new ValueWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::SetupOrganLowestNoteSlider, true));

    GetWidgets().AddWidget(
        WidgetIds::EWidgetId::SetupOrganHighestNoteSlider,
        new ValueWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::SetupOrganHighestNoteSlider, true));

    GetWidgets().AddWidget(
        WidgetIds::EWidgetId::SetupOrganLowestNoteTextLabel,
        new TextWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::SetupOrganLowestNoteTextLabel, false));

    GetWidgets().AddWidget(
        WidgetIds::EWidgetId::SetupOrganHighestNoteTextLabel,
        new TextWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::SetupOrganHighestNoteTextLabel, false));

    GetWidgets().AddWidget(
        WidgetIds::EWidgetId::SetupOrganSustainPedalActiveButton,
        new ButtonWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::SetupOrganSustainPedalActiveButton, true));
}

void OrganSetupPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
    if (changedProperty == ChangedProperties::EChangedProperty::OrganPrimaryKeyboardActive)
    {
        Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::SetupOrganPrimaryKeyboardActiveButton);
        ButtonWidget &buttonWidget = static_cast<ButtonWidget &>(widget);
        bool isActive = _organSubModel.IsPrimaryKeyboardActive();
        buttonWidget.SetPressed(isActive);
    }
    else if (changedProperty == ChangedProperties::EChangedProperty::OrganSecondaryKeyboardActive)
    {
        Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::SetupOrganSecondaryKeyboardActiveButton);
        ButtonWidget &buttonWidget = static_cast<ButtonWidget &>(widget);
        bool isActive = _organSubModel.IsSecondaryKeyboardActive();
        buttonWidget.SetPressed(isActive);
    }
    else if (changedProperty == ChangedProperties::EChangedProperty::OrganLowestNote)
    {
        Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::SetupOrganLowestNoteSlider);
        ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
        int noteNumber = _organSubModel.GetLowestNote();
        valueWidget.SetValue(MidiUtilities::MidiToParam(noteNumber));

        Widget &nameWidget = GetWidgets().GetWidget(WidgetIds::EWidgetId::SetupOrganLowestNoteTextLabel);
        TextWidget &textWidget = static_cast<TextWidget &>(nameWidget);
        textWidget.SetText(juce::MidiMessage::getMidiNoteName(noteNumber, true, true, 4).toStdString());
    }
    else if (changedProperty == ChangedProperties::EChangedProperty::OrganHighestNote)
    {
        Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::SetupOrganHighestNoteSlider);
        ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
        int noteNumber = _organSubModel.GetHighestNote();
        valueWidget.SetValue(MidiUtilities::MidiToParam(noteNumber));

        Widget &nameWidget = GetWidgets().GetWidget(WidgetIds::EWidgetId::SetupOrganHighestNoteTextLabel);
        TextWidget &textWidget = static_cast<TextWidget &>(nameWidget);
        textWidget.SetText(juce::MidiMessage::getMidiNoteName(noteNumber, true, true, 4).toStdString());
    }
    else if (changedProperty == ChangedProperties::EChangedProperty::OrganSustainPedalActive)
    {
        Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::SetupOrganSustainPedalActiveButton);
        ButtonWidget &buttonWidget = static_cast<ButtonWidget &>(widget);
        bool isActive = _organSubModel.IsSustainPedalActive();
        buttonWidget.SetPressed(isActive);
    }
}
