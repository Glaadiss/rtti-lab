#include <iostream>
#include <ctime>
#include <cstdlib>

class Animal {
public:
    virtual ~Animal() {}
    virtual void speak() const = 0;
};

class Cat : public Animal {
public:
    virtual void speak() const { std::cout << "Miau!" << std::endl; }
};

class Dog : public Animal {
public:
    virtual void speak() const { std::cout << "Hau!" << std::endl; }
};

class Tiger : public Cat {
public:
    virtual void speak() const { std::cout << "mraU!" << std::endl; }
};

Animal* randomAnimal(){
    switch (rand() % 3){
        case 0:
            return new Cat();
        case 1:
            return new Dog();
        case 2:
            return new Tiger();
    }
    return nullptr;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}