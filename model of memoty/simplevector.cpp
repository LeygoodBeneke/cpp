#include <iostream>
#include <vector>

template<typename T>
class SimpleVector {
public:
    explicit SimpleVector(size_t size){
        data = new T[size];
        end_ = data + size;
    }

    ~SimpleVector(){
        delete[] data;
    }

    T& operator[](size_t index){
        return *(data + index);
    }
    
    T* begin(){ return data; }

    T* end(){ return end_; }

private:
    T* data;
    T* end_;
};

int main(){
    SimpleVector<int> sv(6);
}
