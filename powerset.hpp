#pragma once
#include <iostream>

namespace itertools
{

template <typename Templte_0>
class powerset
{
private:
    Templte_0 argument;

    template <typename it>
    class iterator
    {

    private:
        it it0;
        it it1;
        bool Switch = true;

    public:
        iterator(it first, it second) : it0(first), it1(second)
        {
        }

        std::pair<decltype(*it0), decltype(*it1)> operator*() const
        {
            return std::pair<decltype(*it0), decltype(*it1)>(*it0, *it1);
        }
        iterator<it> &operator++()
        {
            return *this;
        }
        bool operator==(const iterator<it> &other) const
        {
            return false;
        }
        bool operator!=(const iterator<it> &other)
        {
            return false;
        }
    };

public:
    powerset(Templte_0 arg) : argument(arg)
    {
    }
    auto begin()
    {
        return iterator<decltype(argument.begin())>(argument.begin(), argument.begin());
    }
    auto end()
    {
        return iterator<decltype(argument.end())>(argument.end(), argument.end());
    }
};
} // namespace itertools
