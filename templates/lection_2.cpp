#include<iostream>
#include<vector>
#include<sstream>
#include<map>

template<typename First, typename Second>
std:: ostream& operator<< (std:: ostream& out, const std:: pair<First, Second>& p){
	out << p.first << ", " << p.second;
	return out;
}

template<typename T>
std:: ostream& operator<< (std:: ostream& out, const std:: vector<T>& vi){
	for (const auto& val : vi){
		out << val << " ";
	}
	return out;
}

template<typename Key, typename Value>
std:: ostream& operator<< (std:: ostream& out, const std:: map<Key, Value>& m){
	for (const auto& val : m){
		out << val << " ";
	}
	return out;
}

int main(){
	std:: cout << "Vectors:\n";
	std:: vector<double> vi = {1.2, 2.3, 3.4};
	std:: cout << vi << '\n';

	std:: cout << "Maps:\n";
	std:: map<int, double> m = {{1, 2.233}, {3, 4}};
	std:: cout << m << '\n';
	return 0;
}
