#pragma once

// See: http://www.vishalchovatiya.com/observer-design-pattern-in-modern-cpp/

#include <vector>
#include "IObserver.h"

//template <typename T> struct Observable
class Observable
{
  public:
    //void notify(T &source, const std::string &fieldName)
    void Notify(const std::string &changedProperty)
    {
        for (auto observer : mObservers)
        {
            observer->Update(changedProperty);
        }
    }

     //void subscribe(IObserver<T> &observer)
    void Subscribe(IObserver &observer)
    {
        mObservers.push_back(&observer);
    }

    //void unsubscribe(IObserver<T> &observer)
    void Unsubscribe(IObserver &observer)
    {
        mObservers.erase(remove(mObservers.begin(), mObservers.end(), &observer), mObservers.end());
    }   

  private:
    //std::vector<IObserver<T> *> mObservers;
    std::vector<IObserver *> mObservers;
};
