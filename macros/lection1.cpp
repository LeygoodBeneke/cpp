#include<iostream>
#include<iomanip>
#include<string>

#define AS_KV(x) #x << " = " << x << '\n'

int main(){
    int x = 4;
    std:: string s = "hello";
    bool b = false;

    std:: cerr << AS_KV(x) << AS_KV(s) << AS_KV(b);
}