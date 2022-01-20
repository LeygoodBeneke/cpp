#include<iostream>
#include<algorithm>

template<typename T> // template<class T>
T Max(T a, T b){
	if (a > b) return a;
	return b;
}

int main(){
	std:: cout << Max<double>(2, 3.123) << '\n'; //strict cast
	return 0;
}

