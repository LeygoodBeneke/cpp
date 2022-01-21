#include<iostream>
#include<map>// Синонимы
#include<set>
#include<cassert>
#include<exception>
#include<sstream>

void AddSynonyms(std:: map<std:: string, std:: set<std:: string>>& synonyms,
		const std:: string& first_word, const std:: string& second_word){
	synonyms[second_word].insert(first_word);
	synonyms[first_word].insert(second_word);
}

size_t GetSynonymCount(std:: map<std:: string, std:: set<std:: string>>& synonyms,
		const std:: string& first_word){
	return synonyms[first_word].size() + 1;
}

bool AreSynonyms(std:: map<std:: string, std:: set<std:: string>>& synonyms,
		const std:: string& first_word, const std:: string& second_word){
	return synonyms[first_word].count(second_word) == 1;
}

template <class T, class U>
void AssertEqual(const T& t, const U& u, const std:: string hint){
	if (t != u){
		std:: ostringstream os;
		os << "Assertion failed: " << t << " != " << u << "\nHint: " << hint << '\n';
		throw std:: runtime_error(os.str());
	}
}

void TestAddSynonyms(){
	{
		std:: map<std:: string, std:: set<std:: string>> empty;
		AddSynonyms(empty, "a", "b");
		const std:: map<std:: string, std:: set<std:: string>> expected = {
			{"a", {"b"}},
			{"b", {"a"}},
		};
		assert(empty == expected);
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
		assert(nempty == expected);
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
		assert(AreSynonyms(notempty, "a", "b") == true);
		assert(AreSynonyms(notempty, "b", "c") == true);
		assert(AreSynonyms(notempty, "a", "d") == false);
		assert(AreSynonyms(notempty, "c", "z") == false);
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

void TestAll(){
	TestAddSynonyms();
	TestAreSynonyms();
	TestGetSynonymCount();
}

int main(){
	TestAll();
	return 0;
}
