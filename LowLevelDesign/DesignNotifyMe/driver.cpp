#ifdef PREREQUISITE
#include "prerequisite/BindFunctionality.h"
#include "prerequisite/CallbackFunctionsUsingFunctional.h"
#include "prerequisite/CallbackFunctionsUsingLambda.h"
#include "prerequisite/DependencyInjection.h"
#endif
#include "SimpleObserver.h"
#include <iostream>

int main() {

#ifdef PREREQUISITE
  auto AInstance = std::make_shared<A>();
  auto bInstance = B::create(AInstance);
  bInstance->processB();

  testBindFunctionality();

  callback::functional::testCBUsingFunctional();
  callback::lambda::testCallbackUsingLambda();
  simpleObserverTest();
#endif
  return 0;
}