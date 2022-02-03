#include<iostream>
#include<vector>

template<typename Iterator>
struct IteratorRange {
    Iterator first, last;

    Iterator begin() const {
        return first;
    }

    Iterator end() const{
        return last;
    }
};


template<typename T>
IteratorRange<typename std:: vector<T> :: iterator> Head(std:: vector<T>& v, size_t top){
    return {
        v.begin(), std:: next(v.begin(), std:: min(top, v.size()))
    };
}

int main(){
    std:: vector<int> vec = {1, 2, 3, 4, 5};
    for (int x : Head(vec, 3)){
        ++x;
        std:: cout << x << " ";
    }
    return 0;
}