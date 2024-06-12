#include <iostream>
#include "Manager.h"
#include <Ceo.h>

int main() {

    Manager* frontEndTeamManager = new Manager();
    frontEndTeamManager->setFirstName("Rahul");
    frontEndTeamManager->setLastName("K");
    frontEndTeamManager->computeSalary(5);

    // It is possible to assign ceo to employee but fails with runtime error
    Employee* emp = new Ceo(); 

    // Employee* emp = new Employee();
    emp->setFirstName("Ram");
    emp->setLastName("L");
    emp->computeSalary(2);
    try {
        emp->assignManager(frontEndTeamManager);
    } catch (const runtime_error& e) {
        cerr << "Exception: " << e.what() << endl;
        return 0;
    }
   

    cout << "emp name: " << emp->firstName() 
         << " " << emp->lastName() 
         << " salary per hour is " << emp->salary() << "rupees"
         << " His manager Name is " << emp->manager()->firstName() << endl; 
    
    delete emp;
    delete frontEndTeamManager;
    return 0;
}