#pragma once

#include <vector>

class Model;
class View;
class Pane;

class Panes
{
  public:
    Panes(Model& model, View &view);
    ~Panes();

	 void AddPane(Pane &pane);

	 void Fill();
	 void Init();

  private:
    std::vector<Pane*> _panes;

	 Model &_model;
    View &_view;
};
