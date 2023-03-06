#include "SubViews.h"
#include "LiveSubView.h"
#include "ChannelsSetupSubView.h"
#include "PluginsSetupSubView.h"
#include "SubView.h"

SubViews::SubViews(Model &model, View &view) : _model(model), _view(view)
{
}

SubViews::~SubViews()
{
    _subViews.clear();
}

void SubViews::Fill()
{
    _subViews.push_back(new LiveSubView(_model, _view));
    _subViews.push_back(new ChannelsSetupSubView(_model, _view));
    _subViews.push_back(new PluginsSetupSubView(_model, _view));

    for (auto subView : _subViews)
    {
        subView->Fill();
    }
}

void SubViews::Init()
{
    for (auto subView : _subViews)
    {
        subView->Init();
    }
}
