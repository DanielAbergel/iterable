#pragma once
#include <iostream>

namespace itertools
{

template <typename T>
class range
{
private:
    T _begin;
    T _end;

    class iterator
    {
    private:
        T iterator_temp;

    public:
        iterator(T iterator_temp) : iterator_temp(iterator_temp) {}

        T operator*() const
        {
            return iterator_temp;
        }
        iterator &operator++()
        {
            ++iterator_temp;
            return *this;
        }
        bool operator==(const iterator &other) const
        {
            return this->iterator_temp == other.iterator_temp;
        }
        bool operator!=(const iterator &other)
        {
            return this->iterator_temp != other.iterator_temp;
        }
    };

public:
    range(T Begin, T End) : _begin(Begin), _end(End)
    {
    }

    range(range const &other)
    {
        this->_begin = other._begin;
        this->_end = other._end;
    }
    iterator begin() const
    {
        return iterator(_begin);
    }
    iterator end() const
    {
        return iterator(_end);
    }
};

} // namespace itertools
