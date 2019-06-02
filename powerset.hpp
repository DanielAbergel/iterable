#pragma once

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

namespace itertools
{
template <typename type>

class powerset
{
private:
    type data;

public:
    powerset(type input) : data(input)
    {
    }

    template <typename _data>
    class iterator
    {
    private:
        _data _begin;
        _data _end;
        vector<vector<_data>> value;
        unsigned size;
        unsigned index;

    public:
        iterator(_data ptr1, _data ptr2) : _begin(ptr1), _end(ptr2), size(0), index(0)
        {
            updateLength(ptr1, ptr2);
            size = std::pow(2, size);
            vector<_data> tempVec = dataStructureBuilder(_begin, _end);
            value = combinationsBuilder(tempVec);
        }

        auto operator*()
        {

            vector<typename remove_const<typename remove_reference<decltype(*_end)>::type>::type> temp;

            for (auto i : value[index])
            {
                temp.push_back(*i);
            }

            return temp;
        }

        auto operator++()
        {
            ++index;
            return *this;
        }

        bool operator!=(iterator<_data> it)
        {
            return (index != size);
        }

    private:
        void updateLength(_data begin, _data end)
        {
            _data ptrBegin = begin;
            while (begin != end)
            {
                size++;
                ++begin;
            }
            begin = ptrBegin;
        }
        vector<_data> dataStructureBuilder(_data val1, _data val2)
        {
            vector<_data> temp;
            _data it = val1;

            while (it != val2)
            {
                temp.push_back(it);
                ++it;
            }

            return temp;
        }

        vector<vector<_data>> combinationsBuilder(vector<_data> &val)
        {
            vector<vector<_data>> combinations;
            vector<_data> tempVec;

            combinations.push_back(tempVec);

            for (int i = 0; i < val.size(); i++)
            {
                vector<vector<_data>> temp = combinations;
                for (int j = 0; j < temp.size(); j++)
                {
                    temp[j].push_back(val[i]);
                }

                for (int j = 0; j < temp.size(); j++)
                {
                    combinations.push_back(temp[j]);
                }
            }

            return combinations;
        }
    };

public:
    auto begin() const
    {
        return iterator<decltype(data.begin())>(data.begin(), data.end());
    }

    auto end() const
    {
        return iterator<decltype(data.begin())>(data.end(), data.end());
    }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, vector<T> &input)
{
    os << "{";
    auto start = input.begin();
    if (start != input.end()) 
    {
        os << *start;
        start++;
    }
    while (start != input.end())
    {
        os << "," << *start;
        start++;
    }

    os << "}";
    return os;
}
} // namespace itertools