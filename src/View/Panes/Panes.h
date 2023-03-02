#pragma once

#include <vector>

class Pane;

class Panes
{
  public:
    Panes();
    ~Panes();

	 void Init();

	 void AddPane(Pane& pane);

  private:
    std::vector<Pane*> _panes;
};
