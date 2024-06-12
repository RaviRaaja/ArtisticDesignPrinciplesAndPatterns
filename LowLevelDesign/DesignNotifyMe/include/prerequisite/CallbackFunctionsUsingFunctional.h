#include <functional>
#include <iostream>

namespace callback {
namespace functional {
// Class A with a callback
class A {
public:
  std::function<void(int, double, std::string)> callback;

  void doSomething(int value1, double value2, const std::string &value3) {
    if (callback) {
      callback(value1, value2,
               value3); // Call the callback with provided values
    }
  }
};

// Class B that defines the callback
class B {
public:
  void myCallbackFunction(int value1, double value2,
                          const std::string &value3) {
    std::cout << "Callback called with values: " << value1 << ", " << value2
              << ", " << value3 << std::endl;
  }
};

int testCBUsingFunctional() {
  A a;
  B b;

  // Set the callback using std::bind with placeholders
  a.callback = std::bind(&B::myCallbackFunction, &b, std::placeholders::_1,
                         std::placeholders::_2, std::placeholders::_3);

  // Provide parameters from main
  int userValue1 = 42;
  double userValue2 = 3.14;
  std::string userValue3 = "Hello";

  // Trigger the action that calls the callback with user-provided values
  a.doSomething(userValue1, userValue2, userValue3);

  return 0;
}
} // namespace functional
} // namespace callback