#pragma once

#include <memory>
#include <vector>
#include "../Widgets/Widgets.h"

class gigperformer::sdk::GigPerformerAPI;

class Pane;

class View
{
  public:
    View(gigperformer::sdk::GigPerformerAPI *gig_performer_api);

    void FillWidgets();
    void Init();

	 void ShowWidget(std::string widgetName, bool show);
    void SetWidgetValue(std::string widgetName, double value);
    void SetWidgetLabelText(std::string widgetName, std::string labelText);
    void SetWidgetFillColor(std::string widgetName, double red, double green, double blue, double alpha);

  private:
    std::vector<std::shared_ptr<Pane>> _panes;

    Widgets _widgets;
};
