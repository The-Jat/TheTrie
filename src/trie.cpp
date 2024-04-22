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
    current->isEndOfWord = true;
}

void Trie::collectWords(TrieNode *node, std::string prefix, std::vector<std::string> &words)
{
    if (node->isEndOfWord)
    {
        words.push_back(prefix);
    }
    for (int i = 0; i < 26; ++i)
    {
        if (node->characters[i])
        {
            collectWords(node->characters[i], prefix + char('a' + i), words);
        }
    }
}

std::vector<std::string> Trie::getWords()
{
    std::vector<std::string> words;
    collectWords(root, "", words);
    return words;
}