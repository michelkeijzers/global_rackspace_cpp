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

OrganSetupPane::OrganSetupPane(View &view, OrganSubModel &organSubModel, double leftPercentage, double topPercentage,
 double widthPercentage, double heightPercentage)
    : Pane(view, leftPercentage, topPercentage, widthPercentage, heightPercentage), _organSubModel(organSubModel)
{
   organSubModel.Subscribe(*this);
}

void OrganSetupPane::Fill() // override
{
   GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganSetupPaneBox,
    new ShapeWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganSetupPaneBox, false));
   GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganSetupPaneTitleTextLabel,
    new TextWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganSetupPaneTitleTextLabel, false));
   GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganSetupPrimaryKeyboardActiveButton,
    new ButtonWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganSetupPrimaryKeyboardActiveButton, true));
   GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganSetupSecondaryKeyboardActiveButton,
    new ButtonWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganSetupSecondaryKeyboardActiveButton, true));
   GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganSetupLowestNoteSlider,
    new ValueWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganSetupLowestNoteSlider, true));
   GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganSetupHighestNoteSlider,
    new ValueWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganSetupHighestNoteSlider, true));
   GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganSetupLowestNoteTextLabel,
    new TextWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganSetupLowestNoteTextLabel, false));
   GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganSetupHighestNoteTextLabel,
    new TextWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganSetupHighestNoteTextLabel, false));
   GetWidgets().AddWidget(WidgetIds::EWidgetId::OrganSetupSustainPedalActiveButton,
    new ButtonWidget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganSetupSustainPedalActiveButton, true));
}

// 0%   15%   30%                                   70%     85%   100%
// +---------------------------------------------------------------+ 0%
// |                        ORGAN SETTINGS                         |    Pane Title
// +-----+-----+-------------------------------------+-------+-----+ PTH (0%)
// |Upper|Lower|    Low Note Slider                  |  C-2  | Sus-|  
// |key- |key- +-------------------------------------+-------+ tain| 50%
// |board|board|    High Note Slider                 |  G8   |     |
// +-----+-----+-------------------------------------+-------+-----+ 100%

void OrganSetupPane::Relayout() // override
{
   const double paneTitleHeightPercentage = GetPaneTitleHeightPercentage();
   const double fullHeightPercentage = (1.0 - paneTitleHeightPercentage) / 2;
   const double halfHeightPercentage = fullHeightPercentage / 2.0;
   SetWidgetBounds(WidgetIds::EWidgetId::ChannelsSetupPaneBox, 0.0, 0.0, 1.0, 1.0, 0);
   SetWidgetBounds(
    WidgetIds::EWidgetId::ChannelsSetupPaneTitleTextLabel, 0.0, 0.0, 1.0, paneTitleHeightPercentage, 0.0);
   SetWidgetBounds(WidgetIds::EWidgetId::OrganSetupPrimaryKeyboardActiveButton, 0.0, paneTitleHeightPercentage, 0.15,
    fullHeightPercentage, 0.0);
   SetWidgetBounds(WidgetIds::EWidgetId::OrganSetupSecondaryKeyboardActiveButton, 0.15, paneTitleHeightPercentage, 0.15,
    fullHeightPercentage, 0.0);
   SetWidgetBounds(
    WidgetIds::EWidgetId::OrganSetupLowestNoteSlider, 0.3, paneTitleHeightPercentage, 0.4, halfHeightPercentage, 0.0);
   SetWidgetBounds(WidgetIds::EWidgetId::OrganSetupHighestNoteSlider, 0.3,
    paneTitleHeightPercentage + halfHeightPercentage, 0.4, halfHeightPercentage, 0.0);
   SetWidgetBounds(WidgetIds::EWidgetId::OrganSetupLowestNoteTextLabel, 0.7, paneTitleHeightPercentage, 0.15,
    halfHeightPercentage, 0.0);
   SetWidgetBounds(WidgetIds::EWidgetId::OrganSetupHighestNoteTextLabel, 0.7,
    paneTitleHeightPercentage + halfHeightPercentage, 0.15, halfHeightPercentage, 0.0);
   SetWidgetBounds(WidgetIds::EWidgetId::OrganSetupSustainPedalActiveButton, 0.85, paneTitleHeightPercentage, 0.15,
    fullHeightPercentage, 0.0);
}

void OrganSetupPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
   if (changedProperty == ChangedProperties::EChangedProperty::OrganPrimaryKeyboardActive)
   {
      static_cast<ButtonWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganSetupPrimaryKeyboardActiveButton))
       .SetPressed(_organSubModel.IsPrimaryKeyboardActive());
   }
   else if (changedProperty == ChangedProperties::EChangedProperty::OrganSecondaryKeyboardActive)
   {
      static_cast<ButtonWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganSetupSecondaryKeyboardActiveButton))
       .SetPressed(_organSubModel.IsSecondaryKeyboardActive());
   }
   else if (changedProperty == ChangedProperties::EChangedProperty::OrganLowestNote)
   {
      uint8_t noteNumber = _organSubModel.GetLowestNote();
      static_cast<ValueWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganSetupLowestNoteSlider))
       .SetValue(MidiUtilities::MidiToParam(noteNumber));
      static_cast<TextWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganSetupLowestNoteTextLabel))
       .SetText(juce::MidiMessage::getMidiNoteName(noteNumber, true, true, 4).toStdString());
   }
   else if (changedProperty == ChangedProperties::EChangedProperty::OrganHighestNote)
   {
      uint8_t noteNumber = _organSubModel.GetHighestNote();
      static_cast<ValueWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganSetupHighestNoteSlider))
       .SetValue(MidiUtilities::MidiToParam(noteNumber));
      static_cast<TextWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganSetupHighestNoteTextLabel))
       .SetText(juce::MidiMessage::getMidiNoteName(noteNumber, true, true, 4).toStdString());
   }
   else if (changedProperty == ChangedProperties::EChangedProperty::OrganSustainPedalActive)
   {
      static_cast<ButtonWidget &>(GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganSetupSustainPedalActiveButton))
       .SetPressed(_organSubModel.IsSustainPedalActive());
   }
}
