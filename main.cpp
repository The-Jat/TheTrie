#include <trie.h>
#include <iostream>

int main()
{
    Trie *root = new Trie();

    root->Insert("manish");
    root->Insert("man");
    root->Insert("thejat");

    std::vector<std::string> allWords = root->getWords();
    for (std::string word : allWords)
    {
        std::cout << word << std::endl;
    }
}