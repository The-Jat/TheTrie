#include <vector>
#include <string>

class TrieNode
{
public:
	TrieNode *characters[26];
	bool isEndOfWord;

	TrieNode();
};

class Trie
{
public:
	TrieNode *root;

	Trie();
	void Insert(std::string);
	void collectWords(TrieNode *, std::string, std::vector<std::string> &);

	std::vector<std::string> getWords();
};