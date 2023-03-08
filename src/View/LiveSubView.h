#pragma once

#include "SubView.h"

class Model;
class View;

class LiveSubView : public SubView
{
  public:
    LiveSubView(Model &model, View &view);

  protected:
	 void Fill() override;
};