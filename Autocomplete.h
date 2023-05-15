#ifndef AUTOCOMPLETE
#define AUTOCOMPLETE

#include <string>
#include <vector>

struct TrieNode {
    bool isEndOfWord;
    std::vector<TrieNode*> children;

    TrieNode(){
        isEndOfWord = false;
        children = std::vector<TrieNode*> (26,nullptr);
    }
};

class Autocomplete {
    private:
        TrieNode* root;
    
    public:
        Autocomplete();
        void insert(std::string word);
        void search(TrieNode* curr, std::string partialWord, std::vector<std::string>& suggestions);
        std::vector<std::string> getSuggestions(std::string partialWord);

};












#endif