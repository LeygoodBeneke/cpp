#pragma once
#include <chrono>
#include <iostream>
#include <string>

using namespace std;
using namespace std:: chrono;

#define UNIQ_ID_IMPL(lineno) _a_lovac_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)
#define LOG_DURATION(message) \
    LogDuration UNIQ_ID(__LINE__) { message };

class LogDuration {
public:
    explicit LogDuration(const string& msg = "")
        : start(steady_clock:: now()),
          message(msg + ": ") {}

    ~LogDuration() {
        auto finish = steady_clock:: now();
        auto dur = finish - start;
        cerr << message << 
        duration_cast<milliseconds>(dur).count() << " ms." << '\n'; 
    }
private:
    string message;
    steady_clock:: time_point start;
};
