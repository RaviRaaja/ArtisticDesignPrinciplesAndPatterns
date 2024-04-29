#include <iostream>
#include <Manager.h>
#include <Ceo.h>

int main() {
    // creating manager
    Manager* frontEndTeamManager = new Manager();
    frontEndTeamManager->setFirstName("Rahul");
    frontEndTeamManager->setLastName("K");
    frontEndTeamManager->computeSalary(3);
    delete frontEndTeamManager;

    // creating Manager using emp type
    Employee* emp = new Ceo();
    emp->setFirstName("Sam");
    emp->setLastName("L");
    emp->computeSalary(6);
    emp->assignManager(frontEndTeamManager);
    delete emp;

    return 0;
}