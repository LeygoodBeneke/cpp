#include<iostream>
#include<map>// Синонимы
#include<set>

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
	return synonyms[first_word].count(second_word) == 1;
}

int main(){
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
