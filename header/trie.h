#include <string>
class TrieNode
{
public:
	TrieNode *characters[26];
	bool isEndOfWord;

	TrieNode();
};

class Trie{
	public:
	TrieNode* root;
	Trie();
	void Insert(std::string);

};