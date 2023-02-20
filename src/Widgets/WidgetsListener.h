#pragma once

#include <memory>
#include <string>

#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif

class Controller;

class WidgetsListener
{
  public:
    WidgetsListener(std::shared_ptr<Controller> controller, gigperformer::sdk::GigPerformerAPI *gigPerformerApi);

    void OnWidgetValueChanged(const std::string &widgetName, double newValue);

  private:
    std::shared_ptr<Controller> _controller;
    gigperformer::sdk::GigPerformerAPI *_gigPerformerApi;
};