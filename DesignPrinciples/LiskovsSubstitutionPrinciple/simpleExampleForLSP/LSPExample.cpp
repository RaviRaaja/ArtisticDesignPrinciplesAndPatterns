#include <iostream>

using namespace std;

class Vehicle {
public:
  virtual void startEngine() { cout << "Default Implementation" << endl; }
  virtual void checkAirInTyre() { cout << "Default Implementation" << endl; }
};

class Car : public Vehicle {
public:
  void startEngine() override { cout << "Starting Car engine" << endl; }
  void checkAirInTyre() override { cout << "Checking air in Car" << endl; }
};

class ElectricCar : public Vehicle {
public:
  void startEngine() override { cout << "Starting Electric Car engine" << endl; }
  void checkAirInTyre() override { cout << "Checking air in electric car" << endl; }
};

class Bicycle : public Vehicle {
public:
  void startEngine() override { std::logic_error("Cycle does not have engines"); }
  void checkAirInTyre() override { cout << "Checking air in cycle" << endl; }
};

bool changeEngineOil(Vehicle *v) {
  auto carInstance = dynamic_cast<Car*>(v);
  if (carInstance) {
    cout << "Changing oil for car" << endl;
    return true;
  }

  cout << "Invalid class / car , no engine" << endl;
  return false;
}

int main() {
  Vehicle *car = new Car();
  car->startEngine();

  Vehicle *elecCar = new ElectricCar();
  changeEngineOil(elecCar);

  Bicycle *cyc = new Bicycle();
  cyc->checkAirInTyre();

  delete car;
  delete cyc;
  delete elecCar;
  return 0;
}