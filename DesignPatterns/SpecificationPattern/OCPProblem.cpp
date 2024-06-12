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

class FilterWithPreferences {
    public:
    vector<Person*> filterByEducation(vector<Person*> personList, Education educationPref) {
        vector<Person*> result;
        for (auto person : personList) {
            if (person->education() == educationPref) {
                result.push_back(person);
            }
        }
        return result;
    }

    vector<Person*> filterByOccupation(vector<Person*> personList, Occupation occupationPref) {
        vector<Person*> result;
        for (auto person : personList) {
            if (person->occupation() == occupationPref) {
                result.push_back(person);
            }
        }
        return result;
    }

    vector<Person*> filterByOccupationAndEducation(vector<Person*> personList, Occupation occupationPref, Education educationPref) {
        vector<Person*> result;
        for (auto person : personList) {
            if (person->occupation() == occupationPref && person->education() == educationPref) {
                result.push_back(person);
            }
        }
        return result;
    }
};

int main() {
    Person person1("Sam", Occupation::DOCTOR, Education::MASTER_DEGREE, "Vellore");
    Person person2("Jane", Occupation::ENGINEER, Education::BACHELOR_DEGREE, "Chennai");
    Person person3("Alice", Occupation::LAWYER, Education::DOCTORATE, "Trichy");
    Person person4("Bob", Occupation::ENGINEER, Education::MASTER_DEGREE, "Coimbatore");
    Person person5("Dan", Occupation::TEACHER, Education::BACHELOR_DEGREE, "Tanjore");

    vector<Person*> listOfPeople {&person1, &person2, &person3, &person4, &person5};

    FilterWithPreferences fp;

    for (auto person: fp.filterByEducation(listOfPeople, Education::MASTER_DEGREE)) {
        cout << *person << endl;
    }
    cout  << endl;
    for (auto person: fp.filterByOccupation(listOfPeople, Occupation::ENGINEER)) {
        cout << *person << endl;
    }
    cout  << endl;
    for (auto person: fp.filterByOccupationAndEducation(listOfPeople, Occupation::ENGINEER, Education::MASTER_DEGREE)) {
        cout << *person << endl;
    }

    return 0;
}













