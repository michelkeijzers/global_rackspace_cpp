#include <memory>
#include "View.h"
#include "Panes/OrganPane.h"
#include "Panes/PrimaryKeyboardButtonsPane.h"
#include "../Widgets/Widgets.h"

View::View(gigperformer::sdk::GigPerformerAPI *gig_performer_api) : _widgets(gig_performer_api)
{
    _panes.push_back(std::make_shared<OrganPane>(this));
    _panes.push_back(std::make_shared<PrimaryKeyboardButtonsPane>(this));
}

void View::FillWidgets()
{

}


void View::Init()
{
    for (auto& pane : _panes)
    {
        pane->Init();
	 }
}



void View::SetWidgetValue(std::string widgetName, double value)
{
    _widgets.SetValue(widgetName, value);
}


void View::ShowWidget(std::string widgetName, bool show)
{
    _widgets.ShowWidget(widgetName, show);
}


void View::SetWidgetLabelText(std::string widgetName, std::string labelText)
{
    _widgets.SetWidgetLabelText(widgetName, labelText);
}


void View::SetWidgetFillColor(std::string widgetName, double red, double green, double blue, double alpha)
{
    _widgets.SetWidgetFillColor(widgetName, red, green, blue, alpha);
}
