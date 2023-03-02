#pragma once

#include "Pane.h"
#include <string>

class View;

class SlidersPane : public Pane
{
  public:
    SlidersPane(View& view);

    void Init() override;
};
