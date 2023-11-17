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

    string title;
    vector<string> entries;
};

struct PersistentManager {
    void save(const string& fileName, Note note) {
        ofstream ofs(fileName);
        for (auto bulletins: note.entries) {
            ofs << bulletins << endl;
        }
    }
};

int main() {
    Note note1("ThingstoBuy");
    note1.addNote("Milk");
    note1.addNote("banana");

    PersistentManager pm;
    pm.save("thingstobuy.txt", note1);

    return 0;
}



















































