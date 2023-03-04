#pragma once

#include <string>
#include "../View/IObserver.h"

class View;

class Plugin : public IObserver
{
  public:
    Plugin(const std::string& name, View& view);

	 virtual void Init() = 0;

    const std::string& GetName();

  protected:
    View& GetView();

  private:
    const std::string _name;

    View& _view;
};
