#pragma once

#include <vector>
#include <string>
#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif 
#include "Widget.h"


class Widgets
{
  public:
    Widgets(gigperformer::sdk::GigPerformerAPI* gig_performer_api);
    ~Widgets();

	 Widget *GetWidgetByName(std::string name);

  private:
    std::vector<Widget*> _widgets;
};