/*
 *      PK4 RTTI
 *
 *      Zadania dotyczą wykorzystania mechanizmów RTTI w języku C++
 *      Zalecanie jest wykonywanie ich po kolei od zadania 1 do 3
 *
 * */



#include <iostream>
#include <typeinfo>
const int NUMBER_OF_ANIMALS = 10;

class Animal {
public:
    virtual ~Animal() {}
    virtual void speak() const = 0;

    /* ZADANIE 1 */

    // dodaj metodę className zwracającą nazwę klasy
    // odkomentuj wywołanie funkcji getAnimalsClassNames znajdujące się w funkcji main aby sprawdzić działanie metody
    //
    // PS: mozliwe ze przed nazwą klasy będzie się wyświetlać tajemnicza cyfra, zależy to od implementacji klasy type_info w różnych środowiskach

    /* ROZWIAZANIE */

    const char * className() const { return typeid(*this).name(); }
};

class Cat : public Animal {
public:
    void speak() const { std::cout << "Miau!" << std::endl; }
    void tryToRuleTheWorld() const {

        /* ZADANIE 2 */

        // ponieważ tylko prawdziwe koty mogą opanować świat, a inne zwierzęta dziedziczące po nich nie są w stanie tego zrobić...
        // użyj odpowiedniego operatora mechanizmu RTTI aby tylko dla obiektów klasy Cat (wykluczając klasy pochodne) na standardowe wyjście było wypisywane:
        // "humans are my servants because I am a " + nazwa klasy przy użyciu metody className zaimplementowanej wcześniej
        // natomiast na obiektach klas pochodnych od klasy Cat powinna być używana medota speak
        //
        // aby przetestować działanie metody odkomentuj wywołanie funkcji oneCatExample w funkcji main

        /* ROZWIAZANIE */

        if(typeid(Cat) == typeid(*this))
            std::cout << "humans are my servants because I am a " << this -> className() << std::endl;
        else
            this -> speak();
    };
};

class Dog : public Animal {
public:
    void speak() const { std::cout << "Hau!" << std::endl; }
};

class Tiger : public Cat {
public:
    void speak() const { std::cout << "mraU!" << std::endl; }
};

class Nyan : public Cat {
public:
    void speak() const { std::cout << "nyan!" << std::endl; }
};

Animal* randomAnimal(){
    switch (rand() % 5){
        case 0:
            return new Cat();
        case 1:
            return new Dog();
        case 2:
            return new Tiger();
        case 3:
            return new Nyan();
    }
    return nullptr;
}

void randomAnimals(Animal *animals[]){

    for(int i =0; i < NUMBER_OF_ANIMALS; i++){
        animals[i] = randomAnimal();
    }
}

void getAnimalsClassNames(Animal *animals[]){
    std::cout << "\nAnimals class names:" << std::endl;
    for(int i =0; i < NUMBER_OF_ANIMALS; i++)
        std::cout << animals[i]->className() << std::endl;
    std::cout << std::endl;
}

void oneCatExample() {
    std::cout << "One cat trying to rule the world says: " << std::endl;
    Cat *cat = new Cat();
    cat->tryToRuleTheWorld();
    std::cout << std::endl;
}

void letTheCatsOut(Animal *animals[]){

    /* ZADANIE 3 */
    // używając operatora dynamic_cast uzupełnij warunek, tak aby metoda speak wykonywała się dla klasy Cat oraz każdej jej klasy pochodnej
    //
    // aby przetestować działanie funkcji odkomentuj jej wywołanie w funkcji main

    /*
    for(int i =0; i < NUMBER_OF_ANIMALS; i++){
        Cat *cat = dynamic_cast<Cat *>(animals[i]);
        if(*//* tutaj umieść warunek *//*){
            cat->tryToRuleTheWorld();
        }
    }
    */

    /* ROZWIAZANIE */

    for(int i =0; i < NUMBER_OF_ANIMALS; i++){
        Cat *cat = dynamic_cast<Cat *>(animals[i]);
        if(cat != nullptr){
            cat->tryToRuleTheWorld();
        }
    }
}


int main() {
    srand(time(NULL));
    Animal *animals[NUMBER_OF_ANIMALS];
    randomAnimals(animals);

    // getAnimalsClassNames(animals);
    //
    // powinno wypisac w konsoli 10 nazw klas zwierząt


    // oneCatExample();
    //
    // powinno wypisać w konsoli "One cat trying to rule the world says: humans are my servants because I am a Cat"
    // ostatnie słowo Cat może zawierać w sobie jakąś cyfrę lub różnić się w inny sposób


    // letTheCatsOut(animals);
    //
    // dla wszystkich obiektów klasy Cat powinno wypisać zdanie "humans are my servants because I am a Cat"
    // dla obiektów klas jej pochodnych (Tiger, Nyan) powinno wypisać słowo zdefiniowane w wirtualnej metodzie speak
    // (liczbę obiektów klasy cat i pochodnych można prosto zweryfikować z wynikiem wywołania getAnimalsClassNames z zadania 1)

    return 0;
}