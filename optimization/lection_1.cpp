#include <iostream>
#include <string>
#include <vector>
#include <chrono>
using namespace std:: chrono;

std:: vector<std:: string> GenerateBigVector1() {
    std:: vector<std:: string> result;
    auto start = steady_clock:: now();
    for (int i = 0; i < 2800; ++i){
        result.insert(result.begin(), std:: to_string(i));
    }
    auto finish = steady_clock:: now();
    auto duration = finish - start;
    std:: cerr << duration_cast<milliseconds>(duration).count() << '\n';
    return result;
}
std:: vector<std:: string> GenerateBigVector2() {
    std:: vector<std:: string> result;
    auto start = steady_clock:: now();
    for (int i = 0; i < 2800; ++i){
        result.push_back(std:: to_string(i));
    }
    auto finish = steady_clock:: now();
    auto duration = finish - start;
    std:: cerr << duration_cast<milliseconds>(duration).count() << '\n';
    return result;
}
int main(){
    GenerateBigVector1();
    GenerateBigVector2();
}
