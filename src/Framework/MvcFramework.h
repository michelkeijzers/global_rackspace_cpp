#pragma once

#include <memory>
#include "../Controller/Controller.h"
#include "../Model/Model.h"
#include "../View/View.h"
#ifdef _CONSOLE
    #include "../../../global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/global_rackspace_cpp2_tester/GigPerformerAPI.h"
#else
    #include <gigperformer/sdk/GigPerformerAPI.h>
#endif

class Model;
class View;
class Controller;
class OrganSubModel;
class WidgetsListener;
class gigPerformerApi;

class MvcFramework
{
  public:
    MvcFramework();

	 void Init(gigperformer::sdk::GigPerformerAPI *gigPerformerApi);

	 static gigperformer::sdk::GigPerformerAPI *GetGigPerformerApi();

	 //std::shared_ptr<Model> GetModel();
    //std::shared_ptr<View> GetView();
    std::shared_ptr<Controller> GetController();
    std::shared_ptr<WidgetsListener> GetWidgetsListener();

  private:
    std::shared_ptr<Model> _model;
    std::shared_ptr<View> _view;
    std::shared_ptr<Controller> _controller;

    std::shared_ptr<WidgetsListener> _widgetsListener;

	 static gigperformer::sdk::GigPerformerAPI *_gigPerformerApi;
};
