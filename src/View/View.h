#pragma once

#include <vector>
#include "Panes/Pane.h"

class View
{
  public:
    View();

  private:
    std::vector<Pane*> _panes;
};
