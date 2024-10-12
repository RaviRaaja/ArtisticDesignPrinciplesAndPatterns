#include <iostream>

using namespace std;

// Problem of double dispatch.
// Classes with same interface will not be able communicate if interface type is provided.

class Dog;
class Cat;
class SoundVisitor;
class IVisitor;

class IAnimal {
    public:
    // assuming there are other apis which is common to cat and dog
    virtual void accept(IVisitor* v) = 0;
};

class IVisitor {
    public:
    virtual void makeSoundWithDog(Dog* animal) = 0;
    virtual void makeSoundWithCat(Cat* animal) = 0;
};

class SoundVisitor : public IVisitor {
    public:
        void makeSoundWithDog(Dog* dog) {
            cout << "Dog making sound" << endl;
        }
        void makeSoundWithCat(Cat* cat) {
            cout << "Cat making sound" << endl;
        }
};

class Dog : public IAnimal {
    public:
    void accept(IVisitor* visitor) {
        visitor->makeSoundWithDog(this);
    }
};

class Cat : public IAnimal {
    public:
    void accept(IVisitor* visitor) {
        visitor->makeSoundWithCat(this);
    }
};

int main() {
    IVisitor* soundVisitor = new SoundVisitor();
    IAnimal* dogInstance = new Dog();
    IAnimal* catInstance = new Cat();

    dogInstance->accept(soundVisitor);

    delete dogInstance;
    delete catInstance;
    return 0;
}