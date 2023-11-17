#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Note {

    Note(const string& title) {
        this->title = title;
    }

    void addNote(const string& note) {
        entries.push_back(note);
    }

    // save() method violates single responsibility principle
    void save(const string& fileName) {
        ofstream ofs(fileName);
        for (auto bulletins: entries) {
            ofs << bulletins << endl;
        }
    }

    string title;
    vector<string> entries;
};

int main() {
    Note note1("ThingstoBuy");
    note1.addNote("Milk");
    note1.addNote("banana");
    note1.save("thingstobuy.txt");

    return 0;
}



















































