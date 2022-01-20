#include<iostream>

template<typename First, typename Second>
std:: pair<First, Second> operator* (const std:: pair<First, Second>& p1, const std:: pair<First, Second>& p2){
	First f = p1.first * p2.first;
	Second s = p1.second * p2.second;
	return std:: make_pair(f, s);
}

template<typename T>
T Pow(T x){
	return x * x;
}

int main(){
	std:: cout << "Numbers:\n";
	std:: cout << Pow(2) << '\n';
	std:: cout << Pow(2.5) << '\n';
	
	std:: cout << "Pairs:\n";
	auto p = std:: make_pair(2, 3);
	auto res = Pow(p);
	std:: cout << res.first << '\n' << res.second << '\n';
	return 0;
}
