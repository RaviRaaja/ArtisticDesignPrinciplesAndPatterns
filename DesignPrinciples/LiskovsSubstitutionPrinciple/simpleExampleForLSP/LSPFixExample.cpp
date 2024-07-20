#include <iostream>

using namespace std;

class IPressureCheck {
public:
    virtual ~IPressureCheck() = default;
    virtual void checkAirInTyre() = 0;
};

class IVehicle {
public:
  virtual ~IVehicle() = default;
  virtual bool hasEngine() = 0; 
  virtual void startEngine() = 0;
};

class Car : public IVehicle, IPressureCheck {
public:
  void startEngine() override { cout << "Starting Car engine" << endl; }
  void checkAirInTyre() override { cout << "Air check funtionality" << endl; }
  bool hasEngine() override {
    return true;
  }
};

class ElectricCar :  public IVehicle, IPressureCheck {
public:
  void startEngine() override {
    cout << "Starting Electric Car engine" << endl;
  }
  void checkAirInTyre() override { cout << "Air check funtionality" << endl; }
  bool hasEngine() override {
    return false;
  }
};

class Bicycle : public IPressureCheck {
public:
  void checkAirInTyre() override { cout << "Bicycle Air check funtionality" << endl; }
};

bool changeEngineOil(IVehicle *v) {
  if (v->hasEngine()) {
    cout << "Change oil " << endl;
    return true;
  }

  cout << "Invalid class / car , no engine" << endl;
  return false;
}

int main() {
  IVehicle *car = new Car();
  car->startEngine();

  IVehicle *elecCar = new ElectricCar();
  changeEngineOil(elecCar);

  Bicycle *cyc = new Bicycle();
  cyc->checkAirInTyre();

  delete car;
  delete cyc;
  delete elecCar;
  return 0;
}