#pragma once
#include <vector>

class Model;
class View;
class SubView;

class SubViews
{
  public:
    SubViews(Model &model, View &view);
    ~SubViews();

	 void Fill();
    void Init();

  private:
    std::vector<SubView *> _subViews;

	 Model &_model;
    View &_view;
};