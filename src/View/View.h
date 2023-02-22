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
    void Init();  //TODO: Change to relayout

	 Widgets* GetWidgets();
	
  private:
    std::vector<std::shared_ptr<Pane>> _panes;

    Widgets _widgets;
};
