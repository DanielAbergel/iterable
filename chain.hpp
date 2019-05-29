#pragma once
#include <iostream>



namespace itertools
{

template <typename Templte_0, typename Templte_1>
class chain
{
private:
    Templte_0 _begin;
    Templte_1 _end;

public:
    chain(Templte_0 arg1, Templte_1 arg2) : _begin(arg1), _end(arg2)
    {
    }

    template <typename it_0, typename it_1>
    class iterator
    {

    private:
        it_0 iterator_0;
        it_1 iterator_1;
        bool Switch ;

    public:
        iterator(it_0 first, it_1 second) : iterator_0(first), iterator_1(second), Switch(true)
        {
        }

        decltype(*iterator_0) operator*() const
        {
            if (Switch)
                return *iterator_0;

            return *iterator_1;
        }
        iterator<it_0, it_1> &operator++()
        {
            if (Switch)
                ++iterator_0;
            else
                ++iterator_1;
            return *this;
        }

        bool operator!=(iterator<it_0, it_1> &other)
        {
            if (Switch && (iterator_0 != other.iterator_0) == false )
                Switch = false;
            if (Switch)
                return (iterator_0 != other.iterator_0);
            return (iterator_1 != other.iterator_1);
        }
    };
    auto begin() const
    {
        return iterator<decltype(_begin.begin()), decltype(_end.begin())>(_begin.begin(), _end.begin());
    }
    auto end() const
    {
        return iterator<decltype(_begin.end()), decltype(_end.end())>(_begin.end(), _end.end());
    }
};

} // namespace itertools
