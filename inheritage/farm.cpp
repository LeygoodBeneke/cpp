#include<iostream>
#include<string>

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
	Animal(const std:: string& t = "animal")
		: type(t){}

	void Eat(Fruit& f){
		std:: cout << type << " eats " << f.getType() << ".\n";
	}

	std:: string getType(){
		return type;
	}

protected:
	const std:: string type;
};

class Cat : public Animal{
public:
	Cat() : Animal("cat") {}
};

class Dog : public Animal{
public:
	Dog() : Animal("dog") {}
};


int main(){
	Cat c;
	Apple a;
	c.Eat(a);
	return 0;
}
