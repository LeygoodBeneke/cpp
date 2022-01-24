
template <class T, class U>
void AssertEqual(const T& t, const U& u, const std:: string hint){
	if (t != u){
		std:: ostringstream os;
		os << "Assertion failed: " << t << " != " << u << "\nHint: " << hint << '\n';
		throw std:: runtime_error(os.str());
	}
}

void Assert(bool b, const std:: string& hint){
	AssertEqual(b, true, hint);
}

template<typename T>
std:: ostream& operator<< (std:: ostream& os, const std:: set<T>& s){
	os << "(";
	bool first = true;
	for (const auto& val: s){
		if (!first) os << ", ";
		first = false;
		os << val;
	}
	return os << ")";
}

template<typename K, typename V>
std:: ostream& operator<< (std:: ostream& os, const std:: map<K, V>& m){
	os << "{";
	bool first = true;
	for (const auto& kv: m){
		if (!first) os << ", ";
		first = false;
		os << kv.first << ": " << kv.second; 
	}
	return os << "}";
}

class TestRunner{
public:
	template<class TestFunc>
	void RunTest(TestFunc func, const std:: string& test_name){
		try{
			func();
			std:: cerr << test_name << ": OK" << '\n';
		}catch(std:: runtime_error& e){
			++fail_count;
			std:: cerr << test_name << " fail: " << e.what() << '\n';
		}
	}

	~TestRunner(){
		if (fail_count){
			std:: cerr << fail_count << " tests failed. Terminate";
			exit(1);
		}
	}
private:
	int fail_count = 0;
};

