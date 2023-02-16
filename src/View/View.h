#pragma once

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

  private:
    std::vector<Pane*> _panes;

	 Widgets _widgets;
};
