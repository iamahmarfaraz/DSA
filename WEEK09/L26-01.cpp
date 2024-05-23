#include <iostream>
using namespace std;

// without virtual early binding, static binding
// with virtual late binding, dynamic binding

class Animal
{
public:
    // virtual
    virtual void makeSound()
    {
        cout << "Animal makes a sound" << std::endl;
    }
};

class Dog : public Animal
{
public:
    void makeSound() override
    {
        cout << "Dog barks" << std::endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound() override
    {
        cout << "Cat meows" << std::endl;
    }
};

void sound(Animal *animal){
    animal->makeSound();
}

int main()
{
    Animal *animal = new Dog();
    sound(animal);


    Animal *animalPtr;
    Dog dogObj;
    Cat catObj;

    animalPtr = &dogObj;
    animalPtr->makeSound(); // Output: "Dog barks"

    // animalPtr = &catObj;
    // animalPtr->makeSound(); // Output: "Cat meows"

    return 0;
}
