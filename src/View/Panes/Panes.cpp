#include "Panes.h"
#include "Pane.h"

Panes::Panes() : _panes()
{
}

Panes::~Panes()
{
    _panes.clear();
}

void Panes::Init()
{
    for (auto pane : _panes)
    {
        pane->Init();
    }
}

void Panes::AddPane(Pane& pane)
{
    _panes.push_back(&pane);
}
