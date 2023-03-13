#include "OrganSetupPane.h"
#include "../../Framework/MvcFramework.h"
#include "../../Model/OrganSubModel.h"
#include "../../Widgets/ButtonWidget.h"
#include "../../Widgets/ShapeWidget.h"
#include "../../Widgets/TextWidget.h"
#include "../../Widgets/ValueWidget.h"
#include "../../Widgets/Widget.h"
#include "../ChangedProperties.h"
#include "../IObserver.h"
#include "../View.h"
#include "../../Utilities/Debug.h"


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


	/*
	* 
	* 
	* TODO

	ChangedPr5operties OrganPrimaryKeyboardActive, OrganSecondaryKeyboardActive, OrganLowestNote, OrganHighestNote,
        OrganSustainPedalActive,


   Widgets 
                  SetupOrganPrimaryKeyboardActiveButton,
                  SetupOrganSecondaryKeyboardActiveButton,
                  SetupOrganLowestNoteSlider,
                  SetupOrganHighestNoteSlider,
                  SetupOrganLowestNoteTextLabel,
                  SetupOrganHighestNoteTextLabel,
                  SetupOrganSustainPedalActiveButton,
						*/
		 
    if (changedProperty == ChangedProperties::EChangedProperty::OrganRotatorSpeed)
    {
        Widget &widget = GetWidgets().GetWidget(WidgetIds::EWidgetId::OrganRotatorSpeedTextLabel);
        TextWidget &textWidget = static_cast<TextWidget &>(widget);
        bool isRotatorSpeedFast = _organSubModel.IsRotatorSpeedFast();
        // textWidget.SetText(isRotatorSpeedFast ? ROTATOR_SPEED_FAST_TEXT : ROTATOR_SPEED_SLOW_TEXT);
        textWidget.SetWidgetFillColor(isRotatorSpeedFast ? 1.0 : 0.0, isRotatorSpeedFast ? 0.0 : 1.0, 0.0, 1.0);
    }
}
