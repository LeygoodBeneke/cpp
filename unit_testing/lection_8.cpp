#include<iostream>
#include<map>// Синонимы
#include<set>
#include<exception>
#include<sstream>

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

void AddSynonyms(std:: map<std:: string, std:: set<std:: string>>& synonyms,
		const std:: string& first_word, const std:: string& second_word){
	synonyms[second_word].insert(first_word);
	synonyms[first_word].insert(second_word);
}

size_t GetSynonymCount(std:: map<std:: string, std:: set<std:: string>>& synonyms,
		const std:: string& first_word){
	return synonyms[first_word].size();
}

bool AreSynonyms(std:: map<std:: string, std:: set<std:: string>>& synonyms,
		const std:: string& first_word, const std:: string& second_word){
	return synonyms[first_word].count(second_word) != 0;
}

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

void TestAddSynonyms(){
	{
		std:: map<std:: string, std:: set<std:: string>> empty;
		AddSynonyms(empty, "a", "b");
		const std:: map<std:: string, std:: set<std:: string>> expected = {
			{"a", {"b"}},
			{"b", {"a"}},
		};
		AssertEqual(empty, expected, "Add to empty");
	}
	{
		std:: map<std:: string, std:: set<std:: string>> nempty = {
			{"a", {"b"}},
			{"b", {"a", "c"}},
			{"c", {"b"}},
		};
		AddSynonyms(nempty, "a", "c");
		const std:: map<std:: string, std:: set<std:: string>> expected = {
			{"a", {"b", "c"}},
			{"b", {"a", "c"}},
			{"c", {"b", "a"}},
		};
		AssertEqual(nempty, expected, "Add to not empty");
	}
}

void TestAreSynonyms(){
	{
		std:: map<std:: string, std:: set<std:: string>> notempty = {
			{"a", {"b", "c"}},
			{"b", {"a", "c"}},
			{"c", {"b", "a"}},
		};
		Assert(AreSynonyms(notempty, "a", "b"), "notempty a b");
		Assert(AreSynonyms(notempty, "b", "c"), "notempty b c");
		Assert(!AreSynonyms(notempty, "a", "d"), "notempty a d");
		Assert(!AreSynonyms(notempty, "c", "z"), "notempty c z");

	}
}

void TestGetSynonymCount(){
	{
		std:: map<std:: string, std:: set<std:: string>> notempty = {
			{"a", {"b", "c"}},
			{"b", {"a", "c"}},
			{"c", {"b", "a", "z"}},
			{"z", {"c"}},
		};
		AssertEqual(GetSynonymCount(notempty, "d"), 0u, "count for empty");
		AssertEqual(GetSynonymCount(notempty, "b"), 2u, "count for b");
		AssertEqual(GetSynonymCount(notempty, "c"), 3u, "count for c");
		AssertEqual(GetSynonymCount(notempty, "z"), 1u, "count for z");
	}
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

void TestAll(){
	TestRunner tr;
	tr.RunTest(TestAreSynonyms, "AreSynonyms");
	tr.RunTest(TestAddSynonyms, "AddSynonyms");
	tr.RunTest(TestGetSynonymCount, "GetSynonymCount");
}

int main(){
	TestAll();
	
	int tt;
	std:: cin >> tt;
	std:: map<std:: string, std:: set<std:: string>> synonyms;

	for (int i = 0; i < tt; i++){
		std:: string operation_code;
		std:: cin >> operation_code;
		
		if (operation_code == "ADD"){
			std:: string first_word, second_word;
			std:: cin >> first_word >> second_word;
			AddSynonyms(synonyms, first_word, second_word);
		}else if (operation_code == "COUNT"){
			std:: string word; std:: cin >> word;
			std:: cout << GetSynonymCount(synonyms, word) << '\n';
		}else if (operation_code == "CHECK"){
			std:: string first_word, second_word;
			std:: cin >> first_word >> second_word;
			if (AreSynonyms(synonyms, first_word, second_word))std:: cout << "YES";
			else std:: cout << "NO";
		}
	}
	return 0;
}
