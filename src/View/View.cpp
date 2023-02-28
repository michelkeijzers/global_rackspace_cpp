#include <memory>
#include "View.h"
#include "../Widgets/Widgets.h"
#include "Panes/OrganPane.h"
#include "Panes/PrimaryKeyboardButtonsPane.h"
#include "../Plugins/OrganPlugin.h"
#include "../Model/Model.h"


View::View(std::shared_ptr<Model> model, gigperformer::sdk::GigPerformerAPI *gig_performer_api)
    : _widgets(gig_performer_api)
{
    _panes.push_back(std::make_shared<OrganPane>(this, model->GetOrganSubModel()));
    _panes.push_back(std::make_shared<PrimaryKeyboardButtonsPane>(this, model->GetOrganSubModel()));

	 _plugins.push_back(std::make_shared<OrganPlugin>(this, model->GetOrganSubModel()));
}

void View::FillWidgets()
{
}

void View::Init()
{
    for (auto &pane : _panes)
    {
        pane->Init();
    }
}

Widgets *View::GetWidgets()
{
    return &_widgets;
}
