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
#include <juce_audio_basics/midi/juce_MidiMessage.h>
#include <juce_core/juce_core.h>

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
        static_cast<ButtonWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::SetupOrganPrimaryKeyboardActiveButton))
            .SetPressed(_organSubModel.IsPrimaryKeyboardActive());
    }
    else if (changedProperty == ChangedProperties::EChangedProperty::OrganSecondaryKeyboardActive)
    {
        static_cast<ButtonWidget &>(
            GetWidgets().GetWidget(WidgetIds::EWidgetId::SetupOrganSecondaryKeyboardActiveButton))
            .SetPressed(_organSubModel.IsSecondaryKeyboardActive());
    }
    else if (changedProperty == ChangedProperties::EChangedProperty::OrganLowestNote)
    {
        uint8_t noteNumber = _organSubModel.GetLowestNote();
        static_cast<ValueWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::SetupOrganLowestNoteSlider))
            .SetValue(MidiUtilities::MidiToParam(noteNumber));
        static_cast<TextWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::SetupOrganLowestNoteTextLabel))
            .SetText(juce::MidiMessage::getMidiNoteName(noteNumber, true, true, 4).toStdString());
    }
    else if (changedProperty == ChangedProperties::EChangedProperty::OrganHighestNote)
    {
        uint8_t noteNumber = _organSubModel.GetHighestNote();
        static_cast<ValueWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::SetupOrganHighestNoteSlider))
            .SetValue(MidiUtilities::MidiToParam(noteNumber));
        static_cast<TextWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::SetupOrganHighestNoteTextLabel))
            .SetText(juce::MidiMessage::getMidiNoteName(noteNumber, true, true, 4).toStdString());
    }
    else if (changedProperty == ChangedProperties::EChangedProperty::OrganSustainPedalActive)
    {
        static_cast<ButtonWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::SetupOrganSustainPedalActiveButton))
            .SetPressed(_organSubModel.IsSustainPedalActive());
    }
}
