#include <functional>
#include <iostream>

// Regular function
void myFunction(int x, double y) {
  std::cout << "Function called with: " << x << " and " << y << std::endl;
}

int testBindFunctionality() {
  // Bind arguments to the function and create a function object
  auto boundFunc = std::bind(myFunction, std::placeholders::_1, 3.14);

  // Call the function through the bound function object
  boundFunc(42);

  auto boundFunc2 = std::bind(myFunction, 42, std::placeholders::_1);
  boundFunc2(3.14);

  // -------------------------------------------

  // Define a lambda function and assign it to a std::function object
  std::function<void(int)> func = [](int x) {
    std::cout << "Lambda called with: " << x << std::endl;
  };

  // Call the lambda function through the std::function object
  func(42);

  return 0;
}
