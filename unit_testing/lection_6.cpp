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
	std:: cout << "Test AddSynonyms: OK" << '\n';
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
	std:: cout << "Test AreSynonyms: OK" << '\n';
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
	std:: cout << "Test GetSynonymCount: OK" << '\n';
}

template<class TestFunc>
void RunTest(TestFunc func, const std:: string& test_name){
	try{
		func();
	}catch(std:: runtime_error& e){
		std:: cout << test_name << " fail: " << e.what() << '\n';
	}
}

void TestAll(){
	RunTest(TestAreSynonyms, "AreSynonyms");
	RunTest(TestAddSynonyms, "AddSynonyms");
	RunTest(TestGetSynonymCount, "GetSynonymCount");
}

int main(){
	TestAll();
	return 0;
} 
