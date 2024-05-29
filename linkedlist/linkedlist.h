#pragma once

#include <string>
#include <memory>
#include <stdexcept>

template <typename T>
class LinkedList
{
public:
  virtual ~LinkedList() = default;
  virtual void push_back(T data) = 0;
  virtual void push_front(T data) = 0;
  virtual T pop_front() = 0;
  virtual T pop_back() = 0;
  virtual void remove(T data) = 0;
  virtual bool find(T data) const = 0;
  virtual void clear() = 0;
  virtual bool empty() const = 0;
  virtual size_t length() const = 0;
  virtual std::string to_string() const = 0;
};

