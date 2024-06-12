#include <iostream>
#include <memory>

// Class B is dependent on class A

class A {
public:
  bool processA();
  virtual ~A() {}
};

class B {
public:
  static std::shared_ptr<B> create(const std::shared_ptr<A> &AInstance);
  B(std::shared_ptr<A> AInstance) : m_AInstance(std::move(AInstance)) {};
  bool processB();

private:
  std::shared_ptr<A> m_AInstance;
};