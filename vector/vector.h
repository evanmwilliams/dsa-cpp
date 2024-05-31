#pragma once

#include <string>
#include <utility>

template <typename T>
class Vector
{
private:
  T *data;
  int sz;
  int cp;

  void resize()
  {
    cp = cp == 0 ? 1 : cp * 2;
    T *new_data = new T[cp];
    for (int i = 0; i < sz; ++i)
    {
      new_data[i] = std::move(data[i]);
    }
    delete[] data;
    data = new_data;
  }

public:
  Vector() : data(nullptr), sz(0), cp(0) {}

  ~Vector() { delete[] data; }

  // Copy Constructor
  Vector(const Vector &other) : data(new T[other.cp]), sz(other.sz), cp(other.cp)
  {
    std::copy(other.data, other.data + sz, data);
  }

  // Move constructor
  Vector(Vector &&other) noexcept : data(other.data), sz(other.sz), cp(other.cp)
  {
    other.data = nullptr;
    other.sz = 0;
    other.cp = 0;
  }

  Vector &operator=(Vector &&other) noexcept
  {
    if (this != &other)
    {
      delete[] data;
      data = other.data;
      sz = other.sz;
      cp = other.cp;
      other.data = nullptr;
      other.sz = 0;
      other.cp = 0;
    }
    return *this;
  }

  Vector &operator=(const Vector &other)
  {
    if (this != &other)
    {
      T *new_data = new T[other.cp];
      std::copy(other.data, other.data + other.sz, new_data);
      delete[] data;
      data = new_data;
      sz = other.sz;
      cp = other.cp;
    }
    return *this;
  }

  T &operator[](size_t index)
  {
    return data[index];
  }

  const T &operator[](size_t index) const
  {
    return data[index];
  }

  T at(size_t index)
  {
    return data[index];
  }

  const T at(size_t index) const
  {
    return data[index];
  }

  T front()
  {
    if (sz == 0)
    {
      throw std::out_of_range("Vector is empty.");
    }
    return data[0];
  }

  const T front() const
  {
    if (sz == 0)
    {
      throw std::out_of_range("Vector is empty.");
    }
    return data[0];
  }

  T back()
  {
    if (sz == 0)
    {
      throw std::out_of_range("Vector is empty.");
    }
    return data[sz - 1];
  }

  const T back() const
  {
    if (sz == 0)
    {
      throw std::out_of_range("Vector is empty.");
    }
    return data[sz - 1];
  }

  void push_back(const T &value)
  {
    if (sz == cp)
      resize();
    data[sz] = value;
    sz++;
  }

  void push_back(T &&value)
  {
    if (sz == cp)
      resize();
    data[sz] = value;
    sz++;
  }

  void pop_back()
  {
    if (sz > 0)
    {
      --sz;
    }
  }

  void insert(size_t index, const T &value)
  {
    if (index > sz)
      throw std::out_of_range("Index out of range");
    if (sz == cp)
      resize();

    for (int i = sz; i > index; --i)
    {
      data[i] = std::move(data[i - 1]);
    }
    data[index] = value;
    sz++;
  }

  int size()
  {
    return sz;
  }

  bool empty()
  {
    return sz == 0;
  }

  // Iterators
  T *begin()
  {
    return data;
  }

  T *end()
  {
    return data + sz;
  }

  const T *begin() const
  {
    return data;
  }

  const T *end() const
  {
    return data + sz;
  }

  std::string to_string()
  {
    if (sz == 0)
      return "[]";
    std::string str = "[";
    for (int i = 0; i < sz - 1; ++i)
    {
      str += std::to_string(data[i]) + ", ";
    }
    str += std::to_string(data[sz - 1]) + "]";
    return str;
  }
};