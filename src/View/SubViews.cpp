#include "SubViews.h"
#include "LiveSubView.h"
#include "SetupSubView.h"
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
