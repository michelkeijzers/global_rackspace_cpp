#include <memory>
#include "View.h"
#include "Panes/PrimaryKeyboardButtonsPane.h"
#include "../Widgets/Widgets.h"

View::View(gigperformer::sdk::GigPerformerAPI *gig_performer_api) : _widgets(gig_performer_api)
{
    _panes.push_back(std::make_shared<PrimaryKeyboardButtonsPane>());
}

void View::FillWidgets()
{

}

//Widgets *View::GetWidgets()
//{
//   return &_widgets;
//}


void View::SetWidgetValue(std::string widgetName, double value)
{
    _widgets.SetValue(widgetName, value);
}


void View::ShowWidget(std::string widgetName, bool show)
{
    _widgets.ShowWidget(widgetName, show);
}