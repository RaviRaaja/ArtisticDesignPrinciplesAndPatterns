#include "prerequisite/DependencyInjection.h"

using namespace std;

bool A::processA() {
  cout << "Processing A" << endl;
  return true;
}

std::shared_ptr<B> B::create(const std::shared_ptr<A> &AInstance) {
  if (nullptr == AInstance.get()) {
    cout << "Unable to create B instance" << endl;
    return nullptr;
  }
  auto bInstance = new B(AInstance);
  if (nullptr == bInstance) {
    return nullptr;
  }
  return shared_ptr<B>(bInstance);
}

bool B::processB() {
  cout << "Processing B" << endl;
  m_AInstance->processA();
  return true;
}
