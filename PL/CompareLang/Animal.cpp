#include <iostream>
using namespace std;

// Abstract Class
class Animal {
public:
    Animal() { // constructor
        cout << "Animal constructor called." << endl;
    }
    virtual ~Animal() { // destructor
        cout << "Animal destructor called." << endl;
    }
    virtual void makeSound() = 0; // pure virtual function (override ได้)
    virtual void eat() {// virtual function (override ได้)
        cout << "This animal eats food." << endl;
    }
    void breathe() {// non-virtual function (ห้าม override)
        cout << "(Breathing...)" << endl;
    }
};

class Dog : public Animal {
public:
    Dog() {
        cout << ">> Dog constructor called." << endl;
    }

    ~Dog() override {
        cout << "<< Dog destructor called." << endl;
    }

    void makeSound() override {
        cout << "Woof!" << endl;
    }

    void eat() override {
        cout << "The dog eats dog food." << endl;
    }
};

class Cat : public Animal {
public:
    Cat() {
        cout << ">> Cat constructor called." << endl;
    }

    ~Cat() override {
        cout << "<< Cat destructor called." << endl;
    }

    void makeSound() override {
        cout << "Meow!" << endl;
    }
};

class Labrador : public Dog {
public:
    Labrador() {
        cout << ">>> Labrador constructor called." << endl;
    }

    ~Labrador() override {
        cout << "<<< Labrador destructor called." << endl;
    }

    void makeSound() override {
        cout << "Labrador Woof!" << endl;
    }
};

int main() {
    // Static allocation
    static Dog dog;
    cout << "dog(object) is created." << endl;

    // Stack allocation,Destructor จะถูกเรียกอัตโนมัติเมื่อออกจากฟังก์ชัน
    Labrador labrador;
    cout << "labrador(object) is created." << endl;

    // Heap allocation 
    Animal* cat = new Cat();
    cout << "cat(object) is created." << endl;

    // Polymorphism ผ่าน base class p
    Animal* a[3];
    a[0] = &dog;   // static
    a[1] = &labrador; // stack
    a[2] = cat;  //heap
    for (int i = 0; i < 3; ++i) {
        cout << "--- Animal number [" << i << "] ---" << endl;
        a[i]->makeSound();
        a[i]->eat();
        a[i]->breathe();
        cout << endl;
    }

    cout << "\n=== Memory Cleanup ===" << endl;
    delete cat;
    cout << "Heap memory deleted successfully." << endl;
    return 0;
}
