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

template<typename T>
size_t RangeSize(IteratorRange<T> itr){
    return itr.end() - itr.begin();
}

int main(){
    std:: vector<int> vec = {1, 2, 3, 4, 5};
    for (int x : Head(vec, 3)){
        ++x;
        std:: cout << x << " ";
    }
    std:: cout << RangeSize(Head(vec, 3)) << '\n';
    return 0;
}