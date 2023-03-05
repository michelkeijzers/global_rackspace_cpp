#pragma once

#include "../../Widgets/Widgets.h"
#include "../IObserver.h"
#include <string>

class View;

class Pane : public IObserver
{
  public:
    Pane(View &view);

    virtual void Init() = 0;
    virtual void Fill() = 0;

  protected:
    Widgets &GetWidgets();
    View &GetView();

  private:
    Widgets _widgets;
    View &_view;
};
