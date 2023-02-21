#pragma once

#include <string>
#include "Pane.h"

class View;

class OrganPane : public Pane
{
  public:
	 OrganPane(View* view);

	 void Init() override;
};