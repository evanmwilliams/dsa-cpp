#pragma once

#include "linkedlist.h"
#include <iostream>

// Singly Linked List
template <typename T>
class SinglyLinkedList : public LinkedList<T>
{
private:
  struct Node
  {
    T data;
    std::shared_ptr<Node> next;

    Node(T value) : data(value), next(nullptr) {}
  };

  std::shared_ptr<Node> head;
  std::shared_ptr<Node> tail;
  size_t size;

public:
  SinglyLinkedList();
  ~SinglyLinkedList();
  void push_back(T data) override;
  void push_front(T data) override;
  T pop_front() override;
  T pop_back() override;
  void remove(T data) override;
  bool find(T data) const override;
  void clear() override;
  bool empty() const override;
  size_t length() const override;
  std::string to_string() const override;
};

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
  head = nullptr;
  tail = nullptr;
  size = 0;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
  clear();
}

template <typename T>
void SinglyLinkedList<T>::push_back(T data)
{
  std::shared_ptr<Node> new_node = std::make_shared<Node>(data);
  if (size == 0)
  {
    head = std::move(new_node);
    tail = head;
  }
  else
  {
    tail->next = std::move(new_node);
    tail = tail->next;
  }
  size++;
}

template <typename T>
void SinglyLinkedList<T>::push_front(T data)
{
  std::shared_ptr<Node> new_node = std::make_shared<Node>(data);
  if (size == 0)
  {
    head = std::move(new_node);
    tail = head;
  }
  else
  {
    new_node->next = head;
    head = std::move(new_node);
  }
  size++;
}

template <typename T>
T SinglyLinkedList<T>::pop_front()
{
  if (size == 0)
  {
    throw std::out_of_range("List is empty");
  }
  T data = head->data;
  head = head->next;
  size--;
  return data;
}

template <typename T>
T SinglyLinkedList<T>::pop_back()
{
  if (size == 0)
  {
    throw std::out_of_range("List is empty");
  }
  if (size == 1)
  {
    T data = head->data;
    head = nullptr;
    tail = nullptr;
    size--;
    return data;
  }
  T data = tail->data;
  std::shared_ptr<Node> current = head;
  while (current->next != tail)
  {
    current = current->next;
  }
  tail = current;
  tail->next = nullptr;
  size--;
  return data;
}

template <typename T>
void SinglyLinkedList<T>::remove(T data)
{
  if (size == 0)
  {
    throw std::out_of_range("List is empty");
  }
  std::shared_ptr<Node> current = head;
  std::shared_ptr<Node> previous = nullptr;
  while (current != nullptr)
  {
    if (current->data == data)
    {
      if (previous == nullptr)
      {
        head = current->next;
      }
      else
      {
        previous->next = current->next;
      }
      size--;
      return;
    }
    previous = current;
    current = current->next;
  }
  throw std::out_of_range("Data not found");
}

template <typename T>
bool SinglyLinkedList<T>::find(T data) const
{
  std::shared_ptr<Node> current = head;
  while (current != nullptr)
  {
    if (current->data == data)
    {
      return true;
    }
    current = current->next;
  }
  return false;
}

template <typename T>
void SinglyLinkedList<T>::clear()
{
  while (head != nullptr)
  {
    this->pop_front();
  }
  head = nullptr;
  tail = nullptr;
  size = 0;
}

template <typename T>
bool SinglyLinkedList<T>::empty() const
{
  return size == 0;
}

template <typename T>
size_t SinglyLinkedList<T>::length() const
{
  return size;
}

template <typename T>
std::string SinglyLinkedList<T>::to_string() const
{
  std::string str;
  std::shared_ptr<Node> current = head;
  if (head == nullptr)
  {
    return "[]";
  }
  while (current != nullptr && current->next != nullptr)
  {
    str += "[" + std::to_string(current->data) + "]->";
    current = current->next;
  }
  str += "[" + std::to_string(current->data) + "]";
  return str;
}