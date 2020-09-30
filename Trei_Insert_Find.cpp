#include <iostream>

using namespace std;

inline char toChar(int i) {
	return static_cast<char>('a' + i);
}

class trie {
public:
	char val;
	trie* child[26];
	bool we;

};

trie* node_create() {
	trie* temp = new trie();
	temp->we = false;

	for (int i = 0; i < 26; i++) {
		temp->child[i] = NULL;
	}

	return temp;
}

void insert_recursive(string word, trie* root, int index) {
	if (index == word.size())
	{
		root->val = word[index];
		// cout << "done\n";
		root->we = 1;
		return;
	}

	int in = word[index] - 'a';
	if (!root->child[in]) {
		root->child[in] = node_create();
		root->child[in]->val = word[index];
	}
	insert_recursive(word, root->child[in], index + 1);
	return;
}

bool search(string word, trie* root, int index) {
	int iter = word[index] - 'a';
	if (index == word.size() and root->we)
		return true;
	if (!root->child[iter])
		return false;

	bool found = search(word, root->child[iter], index + 1);

	return found;
}

void preorder_print(trie* root, string word) {
	if (root->we) {
		cout << word << endl;
	}

	for (int i = 0; i < 26; i++) {
		if (root->child[i])
		{
			preorder_print(root->child[i], word + toChar(i));
		}
	}
}

int main() {
	trie* root = node_create();
	string word[10] = {"wefvvb", "apple", "app", "note", "notarised"};
	for (int i = 0; i < 5; i++)
	{
		insert_recursive(word[i], root, 0);
	}

	string w;
	preorder_print(root, w);


	// string search_word;
	// while (1) {
	// 	cin >> search_word;
	// 	if(!search_word.compare("-1"))
	// 	{
	// 		cout<<"ended\n";
	// 		break;
	// 	}
	// 	cout << search(search_word, root, 0);
	// 	cout<<endl;
	// }

	cout << endl;
}