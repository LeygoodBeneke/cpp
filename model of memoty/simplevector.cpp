#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class SimpleVector {
public:
    explicit SimpleVector(size_t size){
        data = new T[size];
        end_ = data + size;
    }

    ~SimpleVector(){ delete[] data; }

    T& operator[](size_t index){
        return *(data + index);
    }
    
    T* begin(){ return data; }
    T* end(){ return end_; }

    const T* begin() const { return data; }
    const T* end() const { return end_; }

private:
    T* data;
    T* end_;
};

template<typename T>
void Print(const SimpleVector<T>& vec) {
    for (auto val : vec) { std:: cout << val << ' '; }
}

int main(){
    SimpleVector<int> sv(6);
}
