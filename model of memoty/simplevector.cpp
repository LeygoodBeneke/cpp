#include <iostream>
#include <vector>

template<typename T>
class SimpleVector {
public:
    explicit SimpleVector(size_t size){
        data = new T[size];
    }

    ~SimpleVector(){
        delete[] data;
    }
    
private:
    T* data;
};

int main(){
    SimpleVector<int> sv(6);
}
