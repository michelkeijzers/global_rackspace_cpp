#pragma once

#include <string>
#include "../IObserver.h"
#include "../../Widgets/Widgets.h"

class View;

class Pane : public IObserver
{
  public:
    Pane(View& view);

    virtual void Init() = 0;

	protected:
    Widgets& GetWidgets();
      View& GetView();

  private:
    Widgets _widgets;

    View& _view;
};
