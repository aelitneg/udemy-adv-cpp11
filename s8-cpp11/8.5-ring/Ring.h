#ifndef RING_H_
#define RING_H_

#include <iostream>
using namespace std;

template <class T>
class Ring
{
public:
    class iterator;

    Ring(int size) : _size(size), _pos(0), _data(NULL)
    {
        _data = new T[size];
    }

    ~Ring()
    {
        delete[] _data;
    }

    void add(T value)
    {
        _data[_pos++] = value;

        if (_pos == _size)
        {
            _pos = 0;
        }
    }

    T &get(int pos)
    {
        return _data[pos];
    }

    iterator begin()
    {
        return iterator(0, *this);
    }

    iterator end()
    {
        return iterator(_size, *this);
    }

private:
    int _size;
    int _pos;
    T *_data;
};

template <class T>
class Ring<T>::iterator
{
public:
    iterator(int pos, Ring &ring) : _pos(pos), _ring(ring) {}

    bool operator!=(const iterator &other) const
    {
        return _pos != other._pos;
    }

    iterator &operator++(int)
    {
        _pos++;
        return *this;
    }

    iterator &operator++()
    {
        _pos++;
        return *this;
    }

    T &operator*() const
    {
        return _ring.get(_pos);
    }

private:
    int _pos;
    Ring &_ring;
};

#endif // RING_H_