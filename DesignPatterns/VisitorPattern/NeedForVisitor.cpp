#include <iostream>

using namespace std;

// Problem of double dispatch.
// Classes with same interface will not be able communicate if interface type is provided.

class Dog;
class Cat;

class IAnimal {
    public:
    virtual void makeSound(Dog* d) const = 0;
    virtual void makeSound(Cat* d) const = 0;
    virtual void makeSound(IAnimal* a) const = 0; // this method is added to convey that double dispatch will not happend automatically.

};

class Dog : public IAnimal {
    public:
    void makeSound(Dog* d) const {
        cout << "Dog interacting with Dog" << endl;
    }

    void makeSound(Cat* c) const {
        cout << "Dog interacting with Cat" << endl;
    }

    void makeSound(IAnimal* a) const {
        cout << "Dog interacting with Animal" << endl;
    }
};

class Cat : public IAnimal {
    public:
    void makeSound(Dog* d) const {
        cout << "Cat interacting with Dog" << endl;
    }

    void makeSound(Cat* c) const {
        cout << "Dog interacting with Cat" << endl;
    }

    void makeSound(IAnimal* a) const {
        cout << "Cat interacting with Animal" << endl;
    }
};

int main() {
    IAnimal* dog1 = new Dog();
    IAnimal* cat1 = new Cat();
    dog1->makeSound(cat1); // Dog interacting with Animal - though cat object is passed complier could not able to infer it is cat, treats as animal
    cat1->makeSound(dog1); // Cat interacting with Animal - though dog object is passed complier could not able to infer it is dog, treats as animal
    delete dog1;
    delete cat1;
    return 0;
}