#pragma once

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
    MvcFramework(gigperformer::sdk::GigPerformerAPI& gigPerformerApi);
    ~MvcFramework();

	 void Init();

	 static gigperformer::sdk::GigPerformerAPI& GetGigPerformerApi();

    Controller& GetController();
    WidgetsListener& GetWidgetsListener();

  private:
    Model* _model;
    View* _view;
    Controller* _controller;
    WidgetsListener* _widgetsListener;

	 static gigperformer::sdk::GigPerformerAPI* _gigPerformerApi;
};
