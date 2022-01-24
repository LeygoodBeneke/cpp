#include<iostream>
#include<map>
#include<set>
#include<exception>
#include<sstream>

#include "test_runner.h"
#include "synonyms.h"
#include "tests.h"

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
