
#if !defined(ARRAY_LIST_H)
#define ARRAY_LIST_H

#include <iostream>
#include <memory>
#include <array>
#include <stdexcept>

namespace morris_container {

    template<typename T>
    class Array {
    public:
        Array() : capacity_(10), size_(0) {
            InitInnerArray();
        }

        Array(size_t capacity) : capacity_(capacity), size_(0) {
            InitInnerArray();
        }

        ~Array() = default;

    public:
        size_t capacity() { return capacity_; }

        size_t size() { return size_; }

        bool IsEmpty() { return size_ == 0; }

        void Add(size_t index, T t) {
            if (index < 0 || index > size_)
                throw std::invalid_argument("Add failed. Require index >=0 and index <= size");

            if (size_ == capacity_)
                Resize(2 * size_);

            for (size_t i = size_; i > index; i--) {
                up_arr_[i] = up_arr_[i - 1];
            }

            up_arr_[index] = t;
            size_++;
        }

        void AddLast(T t) {
            Add(size_, t);
        }

        void AddFirst(T t) {
            Add(0, t);
        }

        T Get(size_t index) {
            if (index < 0 || index >= size_)
                throw std::invalid_argument("Get failed. Index is illegal");
            return up_arr_[index];
        }

        void Set(size_t index, T value) {
            if (index < 0 || index >= size_)
                throw std::invalid_argument("Set failed. Index is illegal");
            up_arr_[index] = value;
        }

        bool Contains(T t) {

            for (size_t i = 0; i < size_; i++) {
                if (up_arr_[i] == t)
                    return true;
            }
            return false;
        }

        T Remove(size_t index) {
            if (index < 0 || index >= size_)
                throw std::invalid_argument("Remove failed. Index is illegal");
            T ret = up_arr_[index];
            for (int i = index + 1; i < size_; ++i) {
                up_arr_[i - 1] = up_arr_[i];
            }
            size_--;
            up_arr_[size_] = nullptr;
            if (size_ == capacity_ / 2)
                Resize(capacity_ / 2);

            return ret;
        }

        T RemoveFirst() {
            return Remove(0);
        }

        T RemoveLast() {
            return Remove(size_ - 1);
        }

        void RemoveElement(T t){
            int index = Find(t);
            if (index != -1)
                Remove(index);
        }

        int Find(T t) {
            for (int i = 0; i < size_; ++i) {
                if (up_arr_[i] == t)
                    return i;
            }
            return -1;
        }

    private:
        size_t capacity_;
        size_t size_;
        std::unique_ptr<T[]> up_arr_;

        std::unique_ptr<T[]> CreateArray(int capacity) {
            std::unique_ptr<T[]> up{new T[capacity]};
            return up;
        }

        void InitInnerArray() {
            up_arr_ = CreateArray(capacity_);
        }

        void Resize(size_t capacity) {
            std::unique_ptr<T[]> new_up_arr{new T[capacity]};

            for (size_t i = 0; i < size_; i++) {
                new_up_arr[i] = up_arr_[i];
            }
            up_arr_.reset(new_up_arr);
        }

    };

} // namespace morris_container
#endif // ARRAY_LIST_H
