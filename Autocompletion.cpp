#include <iostream>
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
        Autocomplete(){
            root = new TrieNode();
        }


        void insert(std::string word){
            TrieNode* curr = root;

            for (char o: word){
                int index = o - 'a';
                if(curr->children[index] == nullptr){
                    curr->children[index] = new TrieNode();
                }

                curr = curr->children[index];

            }

            curr->isEndOfWord = true;
        }

        void search(TrieNode* curr, std::string partialWord, std::vector<std::string>& suggestions){
            if (curr == nullptr){
                return;
            }

            if (curr->isEndOfWord){
                suggestions.push_back(partialWord);
            }

            for (int i = 0; i < 26; i++){
                char o = i + 'a';
                search(curr->children[i], partialWord + o, suggestions);
            }
        }

        std::vector<std::string> getSuggestions(std::string partialWord){
            TrieNode* curr = root;
            std::vector<std::string> suggesstions;

            for (char o: partialWord){
                int index = o - 'a';
                if (curr->children[index] == nullptr){
                    return suggesstions;
                }

                curr = curr->children[index];
            }

            search(curr, partialWord, suggesstions);

            return suggesstions;


        }
};