#include <iostream>
using namespace std;

// Interface Segregation Principle - no code should be forced
// to depend on methods it does not use.

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

class HPprinter_101: public IPrint, IScan, IFax {
    public:
    void print() { cout << "print" << endl; }
    void scan() { cout << "scan" << endl; }
    void fax() { cout << "fax" << endl; }
};

class HPprinter_100: public IPrint {
    public:
    void print() { cout << "print" << endl; }
};

int main() {
    // print button pressed
    HPprinter_101* printerObj = new HPprinter_101();
    printerObj->print();
    delete printerObj; 

    // scan functionality is mistakenly used
    HPprinter_100* lowConfigprinterObj = new HPprinter_100();
    lowConfigprinterObj->print();
    delete lowConfigprinterObj;
    return 0;
}