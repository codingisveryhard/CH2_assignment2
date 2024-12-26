#include <iostream>
using namespace std;



class Animal
{
public:
	Animal() {
		cout << "Animal 생성자 호출" << endl;
	}
	virtual void makeSound() = 0;				// 동물의 울음소리를 출력하는 순수 가상 함수
	virtual void move() = 0;					// 동물의 움직임을 출력하는 순수 가상 함수
	virtual ~Animal() {							// 가상 소멸자(virtual을 붙여야 자식 클래스의 소멸자가 호출됨)
		cout << "Animal 소멸자 호출" << endl;
	}
};


class Zoo 
{
public:

	void addAnimal(Animal* animal) {			// 동물을 추가하는 함수
		this->animal[animalCount] = animal;		// 배열에 동물을 추가
		animalCount++;
	}
	void performAction() {						// 동물의 소리와 행동을 출력하는 함수		
		for (int i = 0; i < 10; i++) {
				animal[i]->makeSound();
				animal[i]->move();
		}
	}
	~Zoo() {
		for (int i = 0; i < 10; i++) {
			delete animal[i];				// 동적할당된 동물 객체를 삭제
			animal[i] = nullptr;			// 포인터를 nullptr로 초기화(오류방지)
		}
	}
private:
	Animal* animal[10] = {};				// 배열의 크기를 10으로 정하고 초기화시킴
	int animalCount = 0;					// 동물의 수를 카운트함	
};

class Dog : public Animal
{
public:
	Dog() {
		cout << "Dog 생성자 호출" << endl;
	}
	void makeSound() override {
		cout << "댕! 댕! " << endl;
	}
	void move() override {
		cout << "댕댕이가 달려갑니다." << endl;
	}
	~Dog() {
		cout << "Dog 소멸자 호출" << endl;
	}
};

class Cat : public Animal
{
public:
	Cat() {
		cout << "Cat 생성자 호출" << endl;
	}
	void makeSound() override {
		cout << "떼껄룩!" << endl;
	}
	void move() override {
		cout << "떼껄룩이 당신을 응시합니다." << endl;
	}
	~Cat() {
		cout << "Cat 소멸자 호출" << endl;
	}
};

class Cow : public Animal
{
public:
	Cow() {
		cout << "Cow 생성자 호출" << endl;
	}
	void makeSound() override {
		cout << "음메~!" << endl;
	}
	void move() override {
		cout << "소가 풀을 뜯습니다." << endl;
	}
	~Cow() {
		cout << "Cow 소멸자 호출" << endl;
	}
};

Animal* createRandomAnimal() {
	int random = rand() % 3;				// 랜덤 난수로 0, 1, 2 중 하나를 생성
	switch (random) {
	case 0:
		return new Dog();					// 생성된 값이 0이면 Dog 객체 생성
	case 1:
		return new Cat();					// 생성된 값이 1이면 Cat 객체 생성	
	case 2:
		return new Cow();					// 생성된 값이 2이면 Cow 객체 생성
	default:
		return nullptr;						// 그 외의 값이면 nullptr 반환 (오류방지)
	}
}



int main()
{
	Animal* animal[10] = {};				// 동물 객체를 담을 배열 생성하고 초기화
	Zoo zoo;								// Zoo 객체 생성
	for (int i = 0; i < 10; i++) {			
		animal[i] = createRandomAnimal();	// 동물 객체를 랜덤으로 생성하여 배열에 추가
	}
	for (int i = 0; i < 10; i++) {
		zoo.addAnimal(animal[i]);			// Zoo 객체에 동물 객체를 추가
	}
	zoo.performAction();					// Zoo 객체의 동물의 소리와 행동을 출력
	zoo.~Zoo();								// Zoo 객체 소멸자 호출


	return 0;
}



