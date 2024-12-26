#include <iostream>
using namespace std;

class Animal
{
public:
	Animal() {
		cout << "Animal »ý¼ºÀÚ È£Ãâ" << endl;
	}
	virtual void makeSound() = 0;
	virtual void move() = 0;
	virtual ~Animal() {
		cout << "Animal ¼Ò¸êÀÚ È£Ãâ" << endl;
	}
};


class Zoo 
{
public:

	void addAnimal(Animal* animal) {
		this->animal[animalCount] = animal;
		animalCount++;
	}
	void performAction() {
		for (int i = 0; i < 10; i++) {
				animal[i]->makeSound();
				animal[i]->move();
		}
	}
	virtual ~Zoo() {
		for (int i = 0; i < 10; i++) {
				delete animal[i];
				animal[i] = nullptr;
		}
	}
private:
	Animal* animal[10] = {};
	int animalCount = 0;
};

class Dog : public Animal
{
public:
	Dog() {
		cout << "Dog »ý¼ºÀÚ È£Ãâ" << endl;
	}
	void makeSound() override {
		cout << "´ó! ´ó! " << endl;
	}
	void move() override {
		cout << "´ó´óÀÌ°¡ ´Þ·Á°©´Ï´Ù." << endl;
	}
	~Dog() {
		cout << "Dog ¼Ò¸êÀÚ È£Ãâ" << endl;
	}
};

class Cat : public Animal
{
public:
	Cat() {
		cout << "Cat »ý¼ºÀÚ È£Ãâ" << endl;
	}
	void makeSound() override {
		cout << "¶¼²¬·è!" << endl;
	}
	void move() override {
		cout << "¶¼²¬·èÀÌ ´ç½ÅÀ» ÀÀ½ÃÇÕ´Ï´Ù." << endl;
	}
	~Cat() {
		cout << "Cat ¼Ò¸êÀÚ È£Ãâ" << endl;
	}
};

class Cow : public Animal
{
public:
	Cow() {
		cout << "Cow »ý¼ºÀÚ È£Ãâ" << endl;
	}
	void makeSound() override {
		cout << "À½¸Þ~!" << endl;
	}
	void move() override {
		cout << "¼Ò°¡ Ç®À» ¶â½À´Ï´Ù." << endl;
	}
	~Cow() {
		cout << "Cow ¼Ò¸êÀÚ È£Ãâ" << endl;
	}
};

int main()
{
	Animal* animal[10] = {};
	Zoo zoo;
	for (int i = 0; i < 10; i++) {
		int random = rand() % 3;
		switch (random) {
		case 0:
			animal[i] = new Dog();
			break;
		case 1:
			animal[i] = new Cat();
			break;
		case 2:
			animal[i] = new Cow();
			break;
		}
	}
	for (int i = 0; i < 10; i++) {
		zoo.addAnimal(animal[i]);
	}
	zoo.performAction();
	zoo.~Zoo();


	return 0;
}
