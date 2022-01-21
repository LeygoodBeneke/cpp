#include<iostream>
#include<cassert>

int Sum(int x, int y){
	return x + y;
}

void TestSum(){
	assert(Sum(2, 3) == 5);
	assert(Sum(2, 2) == 4);
	assert(Sum(-2, 0) == -2);
	assert(Sum(-2, -3) == -5);
	assert(Sum(-3, 3) == 0);
	std:: cout << "TestSum: OK" << '\n';
}

int main(){
	TestSum();

	return 0;
}
