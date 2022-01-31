#include<iostream>
#include<memory>
#include<string>
#include<vector>

struct Fruit{
public:
	Fruit(const std:: string& t = "fruit", const int& hp = 5)
		: type(t), health(hp){}

	std:: string getType(){
		return type;
	}

protected:
	const std:: string type;
	const int health;
};

struct Apple : public Fruit{
	Apple() : Fruit("apple", 20) {}
};

struct Orange : public Fruit{
	Orange() : Fruit("orange", 15) {}
};

struct Animal{
public:
	Animal(const std:: string& t = "animal") : type(t){}

	void Eat(Fruit& f){
		std:: cout << type << " eats " << f.getType() << ".\n";
	}

	virtual void Sound() const = 0;

	std:: string getType(){
		return type;
	}

protected:
	const std:: string type;
};

class Cat : public Animal{
public:
	Cat() : Animal("cat") {}

	void Sound() const override{
		std:: cout << "Meow\n";
	}
};

class Dog : public Animal{
public:
	Dog() : Animal("dog") {}

	void Sound() const override{
		std:: cout << "Wow!\n";
	}
};

class Parrot : public Animal{
private:
	std:: string name;
public:
	Parrot(const std:: string& n) : Animal("Parrot"), name(n) {}

	void Sound() const override{
		std:: cout << name << " is nice!\n";
	}
};

void MakeSound(const Animal& a){
	a.Sound();
}

int main(){
	std:: vector<std:: shared_ptr<Animal>> animals = {
		std:: make_shared<Cat>(),
		std:: make_shared<Dog>(),
		std:: make_shared<Parrot>("Kesha"),
	};
	for (auto a : animals){
		MakeSound(*a);
	}
	system("pause");
	return 0;
}
