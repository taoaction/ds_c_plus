
#if !defined(ARRAY_LIST_H)
#define ARRAY_LIST_H

#include <iostream>
#include <memory>
#include <array>

using namespace std;

template <typename T>
class ArrayList
{
public:
  ArrayList() = default;
  ArrayList(size_t capacity);
  ~ArrayList() = default;

public:
  size_t capacity() { return capacity_; }
  size_t size() { return size_; }
  T Get(size_t index);
  void Set(size_t index, T value);

private:
  size_t capacity_;
  size_t size_;
  unique_ptr<T> arr_;
  void CreateArray();
};

template <typename T>
ArrayList<T>::ArrayList(size_t capacity) : capacity_(capacity), size_(0) {}

#endif // ARRAY_LIST_H
