#include <iostream>
//#include <ctime>
//#include <cstdlib>
const int num = 10;

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

void randomAnimals(Animal *animals[]){

    for(int i =0; i < num; i++){
        animals[i] = randomAnimal();
    }
}


void callCats(Animal *animals[]){
    for(int i =0; i < num; i++){
        if(typeid(Cat) == typeid(*(animals[i]))){
            animals[i] -> speak();
        }
    }
}

void callCatsAndDerrived(Animal *animals[]){
    for(int i =0; i < num; i++){
        Animal *animal = dynamic_cast<Cat *>(animals[i]);
        if(animal != nullptr){
            animal->speak();
        }
    }
}


int main() {
    srand(time(NULL));
    Animal *animals[num];
    randomAnimals(animals);
    callCats(animals);
    std::cout << std::endl;
    callCatsAndDerrived(animals);


    return 0;
}