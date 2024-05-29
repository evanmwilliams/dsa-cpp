#pragma once

#include "linkedlist.h"

// Doubly Linked List
template <typename T>
class DoublyLinkedList : public LinkedList<T>
{
private:
  struct Node
  {
    T data;
    std::shared_ptr<Node> next;
    std::shared_ptr<Node> prev;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
  };

  std::shared_ptr<Node> head;
  std::shared_ptr<Node> tail;
  size_t size;

public:
  DoublyLinkedList();
  ~DoublyLinkedList();
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
DoublyLinkedList<T>::DoublyLinkedList()
{
  head = std::make_shared<Node>(-1);
  tail = std::make_shared<Node>(-1);
  head->next = tail;
  tail->prev = head;
  size = 0;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
  clear();
}

template <typename T>
void DoublyLinkedList<T>::push_back(T data)
{
  auto new_node = std::make_shared<Node>(data);
  if (head->next == tail) // List is empty
  {
    head->next = new_node;
    tail->prev = new_node;
    new_node->prev = head;
    new_node->next = tail;
  }
  else
  {
    new_node->prev = tail->prev;
    new_node->next = tail;
    tail->prev->next = new_node;
    tail->prev = new_node;
  }
  size++;
}

template <typename T>
void DoublyLinkedList<T>::push_front(T data)
{
  auto new_node = std::make_shared<Node>(data);
  if (head->next == tail) // List is empty
  {
    head->next = new_node;
    tail->prev = new_node;
    new_node->prev = head;
    new_node->next = tail;
  }
  else
  {
    new_node->next = head->next;
    new_node->prev = head;
    head->next->prev = new_node;
    head->next = new_node;
  }
  size++;
}

template <typename T>
T DoublyLinkedList<T>::pop_back()
{
  if (head->next == tail)
  {
    throw std::out_of_range("List is empty");
  }
  T data = tail->prev->data;
  tail->prev = tail->prev->prev;
  tail->prev->next = tail;
  size--;
  return data;
}

template <typename T>
T DoublyLinkedList<T>::pop_front()
{
  if (head->next == tail)
  {
    throw std::out_of_range("List is empty");
  }
  T data = head->next->data;
  head->next = head->next->next;
  head->next->prev = head;
  size--;
  return data;
}

template <typename T>
void DoublyLinkedList<T>::remove(T data)
{
  if (head->next == tail)
  {
    throw std::out_of_range("List is empty");
  }
  auto current = head->next;
  while (current != tail)
  {
    if (current->data == data)
    {
      current->prev->next = current->next;
      current->next->prev = current->prev;
      current->next = nullptr;
      current->prev = nullptr;
      size--;
      return;
    }
    current = current->next;
  }
  throw std::out_of_range("Data not found");
}

template <typename T>
bool DoublyLinkedList<T>::find(T data) const
{
  if (head->next == tail)
  {
    throw std::out_of_range("List is empty");
  }
  auto current = head->next;
  while (current != tail)
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
void DoublyLinkedList<T>::clear()
{
  while (head->next != tail)
  {
    this->pop_front();
  }
}

template <typename T>
bool DoublyLinkedList<T>::empty() const
{
  return size == 0;
}

template <typename T>
size_t DoublyLinkedList<T>::length() const
{
  return size;
}

template <typename T>
std::string DoublyLinkedList<T>::to_string() const
{
  std::string str;
  std::shared_ptr<Node> current = head;
  if (head->next == tail)
  {
    return "[]";
  }
  current = current->next;
  while (current != nullptr && current->next != tail)
  {
    str += "[" + std::to_string(current->data) + "]->";
    current = current->next;
  }
  str += "[" + std::to_string(current->data) + "]";
  return str;
}