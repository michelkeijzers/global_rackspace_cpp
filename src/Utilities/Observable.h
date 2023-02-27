#pragma once

// See: http://www.vishalchovatiya.com/observer-design-pattern-in-modern-cpp/

#include <vector>
#include "IObserver.h"

template <typename T> struct Observable
{
    void notify(T &source, const std::string &fieldName)
    {
        for (auto observer : mObservers)
        {
            observer->fieldChanged(source, fieldName);
        }
    }

    void subscribe(IObserver<T> &observer)
    {
        mObservers.push_back(&observer);
    }

    void unsubscribe(IObserver<T> &observer)
    {
        mObservers.erase(remove(mObservers.begin(), mObservers.end(), &observer), mObservers.end());
    }

  private:
    std::vector<IObserver<T> *> mObservers;
};