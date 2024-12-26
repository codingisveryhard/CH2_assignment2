#include <iostream>
using namespace std;

class Animal
{
public:
	Animal() {
		cout << "Animal ������ ȣ��" << endl;
	}
	virtual void makeSound() = 0;
	virtual void move() = 0;
	virtual ~Animal() {
		cout << "Animal �Ҹ��� ȣ��" << endl;
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
		cout << "Dog ������ ȣ��" << endl;
	}
	void makeSound() override {
		cout << "��! ��! " << endl;
	}
	void move() override {
		cout << "����̰� �޷����ϴ�." << endl;
	}
	~Dog() {
		cout << "Dog �Ҹ��� ȣ��" << endl;
	}
};

class Cat : public Animal
{
public:
	Cat() {
		cout << "Cat ������ ȣ��" << endl;
	}
	void makeSound() override {
		cout << "������!" << endl;
	}
	void move() override {
		cout << "�������� ����� �����մϴ�." << endl;
	}
	~Cat() {
		cout << "Cat �Ҹ��� ȣ��" << endl;
	}
};

class Cow : public Animal
{
public:
	Cow() {
		cout << "Cow ������ ȣ��" << endl;
	}
	void makeSound() override {
		cout << "����~!" << endl;
	}
	void move() override {
		cout << "�Ұ� Ǯ�� ����ϴ�." << endl;
	}
	~Cow() {
		cout << "Cow �Ҹ��� ȣ��" << endl;
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
