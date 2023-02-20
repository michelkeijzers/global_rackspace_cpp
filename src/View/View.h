#pragma once

#include <memory>
#include <vector>
#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif
#include "Panes/Pane.h"
#include "../Widgets/Widgets.h"

class View
{
  public:
    View(gigperformer::sdk::GigPerformerAPI *gig_performer_api);

	 void FillWidgets();
	 //Widgets *GetWidgets();

	 void ShowWidget(std::string widgetName, bool show);
	 void SetWidgetValue(std::string widgetName, double value);

  private:
    std::vector<std::shared_ptr<Pane>> _panes;

	 Widgets _widgets;
};
