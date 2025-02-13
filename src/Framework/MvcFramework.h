#pragma once

#include "../Controller/Controller.h"
#include "../Model/Model.h"
#include "../Utilities/Debug.h"
#include "../View/View.h"
#ifdef TESTER
#include "../../../JuceTester2/NewProject/Builds/VisualStudio2022/Source/GP_API/GigPerformerAPI.h"
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
   MvcFramework(gigperformer::sdk::GigPerformerAPI &gigPerformerApi);
   ~MvcFramework();

   void Init();

   static gigperformer::sdk::GigPerformerAPI &GetGigPerformerApi();

   Controller &GetController();
   WidgetsListener &GetWidgetsListener();

 private:
   Model *_model;
   View *_view;
   Controller *_controller;
   WidgetsListener *_widgetsListener;

   static gigperformer::sdk::GigPerformerAPI *_gigPerformerApi;
};
