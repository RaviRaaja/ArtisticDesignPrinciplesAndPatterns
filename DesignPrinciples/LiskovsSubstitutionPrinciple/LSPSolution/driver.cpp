#include <iostream>
#include <Manager.h>
#include <Ceo.h>
#include <Employee.h>

int main()
{
    // note: BaseEmployee* emp = new Manager(); // does not work base of cpp double dispatch unavailability in cpp. But same works in java & c# etc.
    // In cpp if we are creating child class instance and assigning to parent class variable type, we can use all method which are in parent class
    // child class methods cannot be accessed. in this case emp->createPerformanceReport() method will not be able to access.

    Manager* frontEndTeamManager = new Manager();
    
    frontEndTeamManager->setFirstName("Rahul");
    frontEndTeamManager->setLastName("K");
    frontEndTeamManager->computeSalary(5);

    Employee* emp = new Employee();
    // note: BaseEmployee* emp = new Employee(); // does not work base of cpp double dispatch unavailability in cpp. But same works in java & c# etc.
    // In cpp if we are creating child class instance and assigning to parent class variable type, we can use all method which are in parent class
    // child class methods cannot be accessed. in this case emp->manager() method will not be able to access.


    
    emp->setFirstName("Ram");
    emp->setLastName("L");
    emp->computeSalary(2);
    emp->assignManager(frontEndTeamManager);
    

    cout << "emp name: " << emp->firstName()
         << " " << emp->lastName()
         << " salary per hour is " << emp->salary() << " rupees"
         << " His manager Name is " << emp->manager()->firstName() << endl;

    frontEndTeamManager->createPerformanceReport();
    delete emp;
    delete frontEndTeamManager;
    return 0;
}
