#include <iostream>
#include <vector>

using namespace std;

enum Occupation {
    ENGINEER = 1,
    DOCTOR,
    LAWYER,
    TEACHER,
    NONE
};

enum Education {
    DOCTORATE = 1,
    MASTER_DEGREE,
    BACHELOR_DEGREE,
    HIGH_SCHOOL,
    SECONDARY_EDUCATION
};


string occupationToString(Occupation occ) {
    switch (occ) {
        case ENGINEER:
            return "Engineer";
        case DOCTOR:
            return "Doctor";
        case LAWYER:
            return "Lawyer";
        case TEACHER:
            return "teacher";
    }
    return "None";
}

string educationToString(Education occ) {
    switch (occ) {
        case MASTER_DEGREE:
            return "Master Degree";
        case BACHELOR_DEGREE:
            return "Bachelor Degree";
        case HIGH_SCHOOL:
            return "High School";
        case SECONDARY_EDUCATION:
            return "Secondary Education";
    }
    return string();
}


class Person {
    public:
        Person(string name, Occupation occupation, Education education, string location):
        m_name(name),
        m_occupation(occupation),
        m_education(education),
        m_location(location) {}

        string name() const { return m_name; }

        Occupation occupation() const { return m_occupation; }

        Education education() const { return m_education; }

        string location() const { return m_location; }

        friend ostream& operator<<(ostream& os, const Person& person) {
            os << " Name: " <<  person.name() << "|"
               << " Occupation: " << occupationToString(person.occupation()) << "|"
               << " Location: " << person.location() << "|"
               << " Education: " << educationToString(person.education()); 
            return os;
        }

    private:
        string m_name;
        Occupation m_occupation;
        Education m_education;
        string m_location;
};

/// @brief Specification related functionality

class ISpecification {
public:
    virtual bool isValid(Person* person) = 0;
    virtual ~ISpecification() {}
};

class EducationSpecification: public ISpecification {
public:
    EducationSpecification(Education education): m_education(education) {}

    bool isValid(Person* person) {
        return person->education() == m_education;
    }
private: 
    Education m_education;
};

class OccupationSpecification: public ISpecification {
public:
    OccupationSpecification(Occupation occupation): m_occupation(occupation) {}

    bool isValid(Person* person) {
        return person->occupation() == m_occupation;
    }
private: 
    Occupation m_occupation;
};

class AndSpecification: public ISpecification {
public:
    AndSpecification(ISpecification* spec1, ISpecification* spec2): m_spec1(spec1), m_spec2(spec2) {}

    bool isValid(Person* person) {
        return m_spec1->isValid(person) && m_spec2->isValid(person);
    }
private: 
    ISpecification* m_spec1;
    ISpecification* m_spec2;
};

class OrSpecification: public ISpecification {
public:
    OrSpecification(ISpecification* spec1, ISpecification* spec2): m_spec1(spec1), m_spec2(spec2) {}

    bool isValid(Person* person) {
        return m_spec1->isValid(person) || m_spec2->isValid(person);
    }
private: 
    ISpecification* m_spec1;
    ISpecification* m_spec2;
};

/// @brief  Filter related functionality

class Filter {
    public:
        vector<Person*> execute(vector<Person*> personList, ISpecification* spec) {
            vector<Person*> res;
            for (auto person: personList) {
                if (spec->isValid(person)) {
                    res.push_back(person);
                }
            }
            return res;
        }    
};

int main() {
    Person person1("Sam", Occupation::DOCTOR, Education::MASTER_DEGREE, "Vellore");
    Person person2("Jane", Occupation::ENGINEER, Education::BACHELOR_DEGREE, "Chennai");
    Person person3("Alice", Occupation::LAWYER, Education::DOCTORATE, "Trichy");
    Person person4("Bob", Occupation::ENGINEER, Education::MASTER_DEGREE, "Coimbatore");
    Person person5("Dan", Occupation::TEACHER, Education::BACHELOR_DEGREE, "Tanjore");

    vector<Person*> listOfPeople {&person1, &person2, &person3, &person4, &person5};

    EducationSpecification eduSpec(Education::MASTER_DEGREE);
    Filter filter;
    for (auto person: filter.execute(listOfPeople, &eduSpec)) {
        cout << *person << endl;
    }   
    cout << endl;
    OccupationSpecification occSpec(Occupation::ENGINEER);
    for (auto person: filter.execute(listOfPeople, &occSpec)) {
        cout << *person << endl;
    }
    cout << endl;
    AndSpecification educationAndOccupationSpec(&eduSpec, &occSpec);
    for (auto person: filter.execute(listOfPeople, &educationAndOccupationSpec)) {
        cout << *person << endl;
    }
    cout << endl;
    OrSpecification educationOrOccupationSpec(&eduSpec, &occSpec);
    for (auto person: filter.execute(listOfPeople, &educationOrOccupationSpec)) {
        cout << *person << endl;
    }

    return 0;
}













