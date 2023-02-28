#include "MvcFramework.h"

#include "../Widgets/WidgetsListener.h"

/* static */ gigperformer::sdk::GigPerformerAPI *MvcFramework::_gigPerformerApi;

class OrganSubModel;

MvcFramework::MvcFramework() : _model(nullptr), _view(nullptr), _controller(nullptr), _widgetsListener(nullptr)
{
}

void MvcFramework::Init(gigperformer::sdk::GigPerformerAPI *gigPerformerApi)
{
    _model = std::make_shared<Model>();
    _model->Init();

    _view = std::make_shared<View>(_model);
    _controller = std::make_shared<Controller>(_model, _view);
    _widgetsListener = std::make_shared<WidgetsListener>(_controller, _view->GetWidgetIds());

    _controller->FillControllers();
    _controller->FillMidiInBlocks();
    _controller->Init();

	 MvcFramework::_gigPerformerApi = gigPerformerApi;
}


/* static */ gigperformer::sdk::GigPerformerAPI *MvcFramework::GetGigPerformerApi()
{
    return _gigPerformerApi;
}

std::shared_ptr<Controller> MvcFramework::GetController()
{
    return _controller;
}

std::shared_ptr<WidgetsListener> MvcFramework::GetWidgetsListener()
    {
    return _widgetsListener;
}
