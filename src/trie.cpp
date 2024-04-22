#include <trie.h>

TrieNode::TrieNode()
{

    isEndOfWord = false;
    for (int i = 0; i < 26; i++)
    {
        characters[i] = nullptr;
    }
}

Trie::Trie()
{
    root = new TrieNode();
}

void Trie::Insert(std::string word)
{
    TrieNode *current = root;
    for (char c : word)
    {
        int index = c - 'a';
        if (!current->characters[index])
        {
            current->characters[index] = new TrieNode();
        }
        current = current->characters[index];
    }
}