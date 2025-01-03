#pragma once
#include <cassert>  //Make sure the index is valid
#include <algorithm> // Để sử dụng std::fill, std::sort
#include <utility>   // Để sử dụng std::move
//Make vector class to store CSV files' data
#include "Properties.h"

using ll = long long;

namespace custom {
template <class T>
class vector {
private:
    T* _data;
    ll s;          // Current size of the vector (Number of elements)
    ll capacity;   // Maximum size of the vector's array (If reached double it)

public:
    vector() : _data(nullptr), s(0), capacity(0) {}

    vector(ll cellNum, const T& val) : s(cellNum), capacity(cellNum) {
        _data = new T[cellNum];
        std::fill(_data, _data + cellNum, std::move(val));
    }
    vector(const ll cellNum) : s(cellNum), capacity(cellNum) {
        _data = new T[cellNum];
    }

    ~vector() {
        clear();
        _data = NULL;
    }

    void clear() {
        if (_data) {
            delete[] _data;
            this->_data = nullptr;
        }
        this->capacity = 0;
        this->s = 0;
    }

    // Constructor hỗ trợ initializer_list
   vector(std::initializer_list<T> init) : s(init.size()), capacity(init.size()) {
    _data = new T[s];
    int index = 0;
    for (const auto& element : init) {
        _data[index++] = element;
    }
    }

    void push_back(const T& val) {
        if (s == capacity) {
            upsize();
        }
        _data[s++] = val;
    }
    
    void push_back(T&& val) {
        if (s == capacity) {
            upsize();
        }
        _data[s++] = val;
    }

    void insert(const T& val, long long index) 
    {
        assert(index >= 0); 
        assert(index <= s); 
        if (s == capacity) {
            upsize();
        }
        ++s;
        for (long long i = s - 1; i > index; --i)
        {
            _data[i] = _data[i - 1]; 
        }
        _data[index] = val; 
    }
    void insert(T&& val, long long index)
    {
        assert(index >= 0);
        assert(index <= s);
        if (s == capacity) {
            upsize();
        }
        ++s;
        for (int i = s - 1; i > index; --i)
        {
            _data[i] = _data[i - 1];
        }
        _data[index] = val;
    }
    void erase(long long index)
    {
        for (int i = index; i < s-1; ++i)
        {
            _data[i] = _data[i + 1]; 
        }
        --s; 
    }
    T& operator[] (ll __offset) {
        assert(__offset < s);
        return _data[__offset];
    }

    const T& operator[] (ll __offset) const {
        assert(__offset < s);
        return _data[__offset];
    }

    vector& operator= (const vector& rhs) {
        if (this == &rhs) {
            return *this;
        }
        if (s < rhs.s) {
            delete[] _data;
            _data = new T[rhs.s];
            capacity = rhs.s;
        }
        s = rhs.s;
        for (int i = 0; i < s; ++i)
        {
            _data[i] = rhs[i]; 
        }
        return *this;
    }

    void pop_back() {
        assert(s > 0);
        --s;
    }

    ll size() const {
        return s;
    }
    // Hàm kiểm tra xem vector có rỗng hay không
    bool empty() const {
        return s == 0;
    }
    
    T* begin()
    {
        return _data; 
    }
    T* end()
    {
        return _data + s; 
    }
private:
    void upsize() {
        capacity = (capacity == 0) ? 1 : 2 * capacity;
        T* ne = new T[capacity];
        //std::move(_data, _data + s, ne);
        for (int i = 0; i < s; ++i)
        {
            ne[i] = _data[i];
        }
        delete[] _data;
        _data = ne;
    }

public:
    void setDefault(int n, T def[]) {
        for (int i = 0; i < n; i++)
            this->push_back(def[i]);
    }
};
} // namespace custom 