#include "test_runner.h"

#include <ostream>
using namespace std;

#define RUN_TEST(obj, func) obj.RunTest(func, #func);
#define ASSERT_EQUAL(a, b) AssertEqual(a, b, "");
#define ASSERT(a) Assert(a, "")

#define PRINT_VALUES(out, x, y) out << (x) << '\n' << (y) << '\n'

int main() {
  TestRunner tr;
  tr.RunTest([] {
    ostringstream output;
    PRINT_VALUES(output, 5, "red belt");
    ASSERT_EQUAL(output.str(), "5\nred belt\n");
  }, "PRINT_VALUES usage example");
  return 0;
}