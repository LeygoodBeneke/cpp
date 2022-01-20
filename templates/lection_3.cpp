#include<iostream>
#include<vector>
#include<sstream>
#include<map>

template<typename Collection>
std:: string Join(const Collection& c, char d){
	std:: stringstream ss;
	bool first = true;
	for (const auto& value : c){
		if (!first){
			ss << d;
		}
		first = false;
		ss << value;
	}
	return ss.str();
}

template<typename First, typename Second>
std:: ostream& operator<< (std:: ostream& out, const std:: pair<First, Second>& p){
	return out << '(' << p.first << ", " << p.second << ')';
}

template<typename T>
std:: ostream& operator<< (std:: ostream& out, const std:: vector<T>& vi){
	return out << '[' << Join(vi, ',') << ']';
}

template<typename Key, typename Value>
std:: ostream& operator<< (std:: ostream& out, const std:: map<Key, Value>& m){
	return out << '{' << Join(m, ',') << '}';
}

int main(){
	std:: cout << "Vectors:\n";
	std:: vector<double> vi = {1.2, 2.3, 3.4};
	std:: cout << vi << '\n';

	std:: vector<std:: vector<double>> vi2 = {{1, 2}, {3.343, 5.343}};
	std:: cout << vi2 << '\n';

	std:: cout << "Maps:\n";
	std:: map<int, double> m = {{1, 2.233}, {3, 4}};
	std:: cout << m << '\n';
	return 0;
}
