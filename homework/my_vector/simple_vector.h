#include <iostream>

template<typename T>
class SimpleVector {
public:
    explicit SimpleVector(size_t size = 0){
        data = new T[size];
        size_ = size;
        capacity_ = size;
    }

    ~SimpleVector(){ delete[] data; }

    T& operator[](size_t index){ return *(data + index); }
    
    T* begin(){ return data; }
    T* end(){ return data + size_; }

    const T* begin() const { return data; }
    const T* end() const { return data + size_; }

    const size_t Capacity() const { return capacity_; }
    const size_t Size() const { return end() - begin(); }


    void PushBack(T value){
        if (Size() == Capacity()){
            DataUpdate();
        }
        data[Size()] = value;
        size_++;
    }


private:
    T* data = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

    void DataUpdate(){
        capacity_ = (capacity_ == 0) ? 1 : capacity_ * 2;
        T* new_data = new T[capacity_];
        std:: copy(begin(), end(), new_data);
        delete[] data;
        data = new_data;
    }
};