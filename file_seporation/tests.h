#include "test_runner.h"

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

void TestAll(){
	TestRunner tr;
	tr.RunTest(TestAreSynonyms, "AreSynonyms");
	tr.RunTest(TestAddSynonyms, "AddSynonyms");
	tr.RunTest(TestGetSynonymCount, "GetSynonymCount");
}
