#include "SubView.h"
#include "Panes/Panes.h"

SubView::SubView(Model &model, View &view) : _panes(model, view), _view(view), _model(model)
{
}

void SubView::Fill()
{
   _panes.Fill();
}

void SubView::Init()
{
   _panes.Init();
}

Panes &SubView::GetPanes()
{
   return _panes;
}

View &SubView::GetView()
{
   return _view;
}

Model &SubView::GetModel()
{
   return _model;
}
