#include "profile.h"

int main() {
    { LOG_DURATION("func");
        for (long long i = 0; i < 1000000; i++) {
            int a;
        }
    }
    return 0;
}