#include "OrganPane.h"
#include "../../Framework/MvcFramework.h"
#include "../../Model/OrganSubModel.h"
#include "../../Widgets/ValueWidget.h"
#include "../../Widgets/Widget.h"
#include "../View.h"
#include "../ChangedProperties.h"
#include "../IObserver.h"

OrganPane::OrganPane(View& view, OrganSubModel& organSubModel) : Pane(view)
{
    organSubModel.Subscribe(*this);
}

void OrganPane::Init() // override
{
    GetWidgets().AddWidget(
        WidgetIds::EWidgetId::OrganDrawbar1,
        new Widget(GetView().GetWidgetIds(), WidgetIds::EWidgetId::OrganDrawbar1, true));
}

void OrganPane::Update(ChangedProperties::EChangedProperty changedProperty) /* override */
{
    if (changedProperty == ChangedProperties::EChangedProperty::Drawbar1)
    {
        Widget &widget = GetWidgets().GetWidgetById(WidgetIds::EWidgetId::OrganDrawbar1);
        ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
        valueWidget.SetValue(GetView().GetModel().GetOrganSubModel().GetDrawbarValue(0));
    }
}