#include "MvcFramework.h"

#include "../Widgets/WidgetsListener.h"

/* static */ gigperformer::sdk::GigPerformerAPI *MvcFramework::_gigPerformerApi = nullptr;

const int GIG_PERFORMER_LIVE_PANEL_WIDTH = 1200;
const int GIG_PERFORMER_LIVE_PANEL_HEIGHT = 600;

class OrganSubModel;

MvcFramework::MvcFramework(gigperformer::sdk::GigPerformerAPI &gigPerformerApi)
    : _model(nullptr), _view(nullptr), _controller(nullptr), _widgetsListener(nullptr)
{
   _gigPerformerApi = &gigPerformerApi;
}

MvcFramework::~MvcFramework()
{
   if (_model != nullptr)
   {
      delete _model;
      _model = nullptr;
   }

   if (_view != nullptr)
   {
      delete _view;
      _view = nullptr;
   }

   if (_controller != nullptr)
   {
      delete _controller;
      _controller = nullptr;
   }

   if (_widgetsListener != nullptr)
   {
      delete _widgetsListener;
      _widgetsListener = nullptr;
   }
}

void MvcFramework::Init()
{
   _model = new Model();
   _model->Fill();
   _model->Init();

   _view = new View(*_model, GIG_PERFORMER_LIVE_PANEL_WIDTH, GIG_PERFORMER_LIVE_PANEL_HEIGHT);
   _view->Fill();
   _view->Init();
   _controller = new Controller(*_model, *_view);
   _widgetsListener = new WidgetsListener(*_controller, _view->GetWidgetIds());

   _controller->Fill();
   _controller->Init();
}

/* static */ gigperformer::sdk::GigPerformerAPI &MvcFramework::GetGigPerformerApi()
{
   return *_gigPerformerApi;
}

Controller &MvcFramework::GetController()
{
   return *_controller;
}

WidgetsListener &MvcFramework::GetWidgetsListener()
{
   return *_widgetsListener;
}
