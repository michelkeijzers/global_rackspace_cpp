#pragma once

#include "Pane.h"
#include <string>

class View;

class SlidersPane : public Pane
{
  public:
    static const int NR_OF_SLIDERS = 9;

    SlidersPane(View& view);

    void Init() override;
};
