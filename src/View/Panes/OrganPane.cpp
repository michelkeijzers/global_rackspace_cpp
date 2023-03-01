#include "OrganPane.h"
#include "../../Framework/MvcFramework.h"
#include "../../Model/OrganSubModel.h"
#include "../../Widgets/ValueWidget.h"
#include "../../Widgets/Widget.h"
#include "../View.h"
#include "../../View/IObserver.h"
#include <memory>

OrganPane::OrganPane(View *view, std::shared_ptr<OrganSubModel> organSubModel) : Pane(view)
{
    organSubModel->Subscribe(*this);
}

void OrganPane::Init() // override
{
    GetWidgets()->AddWidget(
        WidgetIds::EWidgetId::OrganDrawbar1,
        std::make_shared<Widget>(GetView()->GetWidgetIds(), WidgetIds::EWidgetId::OrganDrawbar1, true));
}

void OrganPane::Update(View::EChangedProperty changedProperty) /* override */
{
    if (changedProperty == View::EChangedProperty::Drawbar1)
    {
        Widget &widget = GetWidgets()->GetWidgetById(WidgetIds::EWidgetId::OrganDrawbar1);
        ValueWidget &valueWidget = static_cast<ValueWidget &>(widget);
        valueWidget.SetValue(GetView()->GetModel()->GetOrganSubModel()->GetDrawbarValue(1));
    }
}