#include <iostream>
using namespace std;

class IPrint {
    public:
    virtual void print() = 0;
};

class IScan {
    public:
    virtual void scan() = 0;
};

class IFax {
    public:
    virtual void fax() = 0;
};

class HPprinter101: public IPrint, IFax, IScan {
    public:
    void print() override {
        cout << "printing" << endl;
    }

    void scan() override {
        cout << "scan" << endl;
    }

    void fax() override {
        cout << "Send Fax" << endl;
    }
};

class HPprinter100: public IPrint {
    public:
    void print() override {
        cout << "printing" << endl;
    }
};

int main() {
    HPprinter101* advPrinter = new HPprinter101();
    advPrinter->scan();
    advPrinter->print();
    cout << "----" << endl;
    HPprinter100* minimumVersionPrinter = new HPprinter100();
    minimumVersionPrinter->print();
    return 0;
}