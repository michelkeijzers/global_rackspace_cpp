#include "MvcFramework.h"

#include "../Widgets/WidgetsListener.h"

MvcFramework::MvcFramework() : _model(nullptr), _view(nullptr), _controller(nullptr), _widgetsListener(nullptr)
{
}

void MvcFramework::Init(gigperformer::sdk::GigPerformerAPI *gigPerformerApi)
{
    _model = std::make_shared<Model>();
    _view = std::make_shared<View>(gigPerformerApi);
    _controller = std::make_shared<Controller>(_model, _view, gigPerformerApi);
    _widgetsListener = std::make_shared<WidgetsListener>(_controller, gigPerformerApi);

    _controller->FillControllers();
    _controller->FillMidiInBlocks();
    _controller->Init();
}

std::shared_ptr<Controller> MvcFramework::GetController()
{
    return _controller;
}

std::shared_ptr<WidgetsListener> MvcFramework::GetWidgetsListener()
    {
    return _widgetsListener;
}
