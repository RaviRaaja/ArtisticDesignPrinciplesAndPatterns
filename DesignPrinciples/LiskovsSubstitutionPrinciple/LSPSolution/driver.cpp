#include <Ceo.h>
#include <Employee.h>
#include <Manager.h>
#include <iostream>

int main() {
  Manager *frontEndTeamManager = new Manager();

  frontEndTeamManager->setFirstName("Rahul");
  frontEndTeamManager->setLastName("K");
  frontEndTeamManager->computeSalary(5);

  Employee *emp = new Employee();

  // Below all works
  // BaseEmployee* emp1 = new Employee();
  // BaseEmployee* ceo1 = new Ceo(); Here we cannot use assign manager
  // functionality as this is seperated to different interface. BaseEmployee*
  // manager1 = new Manager();

  emp->setFirstName("Ram");
  emp->setLastName("L");
  emp->computeSalary(2);
  emp->assignManager(frontEndTeamManager);

  cout << "emp name: " << emp->firstName() << " " << emp->lastName()
       << " salary per hour is " << emp->salary() << " rupees"
       << " His manager Name is " << emp->manager()->firstName() << endl;

  frontEndTeamManager->createPerformanceReport();
  delete emp;
  delete frontEndTeamManager;
  return 0;
}
