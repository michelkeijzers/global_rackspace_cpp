#pragma once

#include <memory>
#include <string>
#include <vector>
#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif

class Widgets
{
  public:
    Widgets(gigperformer::sdk::GigPerformerAPI *gigPerformerApi);

    void SetValue(std::string widgetName, double value);
    void ShowWidget(std::string widgetName, bool show);

  private:
    void AssertIfWidgetDoesNotExist(std::string widgetName);

    std::vector<std::string> _widgetNames;

    gigperformer::sdk::GigPerformerAPI *_gigPerformerApi;
};