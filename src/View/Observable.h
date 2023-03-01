#pragma once

// See: http://www.vishalchovatiya.com/observer-design-pattern-in-modern-cpp/

#include "IObserver.h"
#include <vector>

class Observable
{
  public:
    void Notify(View::EChangedProperty changedProperty)
    {
        for (auto observer : mObservers)
        {
            observer->Update(changedProperty);
        }
    }

    void Subscribe(IObserver &observer)
    {
        mObservers.push_back(&observer);
    }

    void Unsubscribe(IObserver &observer)
    {
        mObservers.erase(remove(mObservers.begin(), mObservers.end(), &observer), mObservers.end());
    }

  private:
    std::vector<IObserver *> mObservers;
};
