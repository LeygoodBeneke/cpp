#include<iostream>

template<typename T, typename U>
struct Pair{
    T first;
    U second;
};

int main(){
    Pair<int, bool> p;
    p.first = 5;
    p.second = true;
    return 0;
}