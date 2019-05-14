#pragma once
#include <iostream>

namespace itertools
{

template <typename Templte_0, typename Templte_1>
class zip
{
private:
    Templte_0 argument_0;
    Templte_1 argument_1;

    template <typename it_0, typename it_1>
    class iterator
    {

    private:
        it_0 it0;
        it_1 it1;
        bool Switch = true;

    public:
        iterator(it_0 first, it_1 second) : it0(first), it1(second)
        {
        }

        std::pair<decltype(*it0), decltype(*it1)> operator*() const
        {
            return std::pair<decltype(*it0), decltype(*it1)>(*it0, *it1);
        }
        iterator<it_0, it_1> &operator++()
        {
            return *this;
        }
        bool operator==(const iterator<it_0, it_1> &other) const
        {
            return false;
        }
        bool operator!=(const iterator<it_0, it_1> &other)
        {
            return false;
        }
    };

public:
    zip(Templte_0 arg1, Templte_1 arg2) : argument_0(arg1), argument_1(arg2)
    {
    }
    auto begin()
    {
        return iterator<decltype(argument_0.begin()), decltype(argument_1.begin())>(argument_0.begin(), argument_1.begin());
    }
    auto end()
    {
        return iterator<decltype(argument_0.end()), decltype(argument_1.end())>(argument_0.end(), argument_1.end());
    }
};

template <typename Template_0, typename Template_1>
ostream &operator<<(ostream &os, std::pair<Template_0, Template_1> &Pair)
{
    os << Pair.first << " , " << Pair.second ; 
    return os ; 
}
} // namespace itertools