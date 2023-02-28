#pragma once

#include <memory>
#include <string>
#include <vector>
#include "../../Utilities/IObserver.h"
#include "../../Widgets/Widgets.h"

class View;

class Pane : public IObserver
{
  public:
    Pane(View *view);

    virtual void Init() = 0;

  private:
    Widgets _widgets;

    View *_view;
};
