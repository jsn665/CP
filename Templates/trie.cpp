#include <bits/stdc++.h>

using namespace std;


class Node{
	public:
	vector<Node*> children;
	bool isComplete;
	Node(){
		children.resize(26);
		isComplete = false;
	}

	bool containsKey(char key){
		return children[key - 'a'] != NULL;
	}

	void addKey(char key){
		children[key - 'a'] = new Node();
	}

	Node *getNode(char key){
		return children[key - 'a'];
	}



};

class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();
    }

    void insert(string word) {
	int N = word.length();
	Node *dummy = root;
	for(int i = 0; i < N; i++){
		char key = word[i];
		if(!dummy->containsKey(key)){
			dummy->addKey(key);
		}
		dummy = dummy->getNode(key);
	}
	dummy->isComplete = true;
    }

    bool search(string word) {
	int N = word.length();
	Node *dummy = root;
	for(int i = 0; i < N; i++){
		char key = word[i];
		if(!dummy->containsKey(key)){
			return false;
		}
		dummy = dummy->getNode(key);
	}
	return dummy->isComplete;
    }

    bool startsWith(string prefix) {
	int N = prefix.length();
	Node *dummy = root;
	for(int i = 0; i < N; i++){
		char key = prefix[i];
		if(!dummy->containsKey(key)){
			return false;
		}
		dummy = dummy->getNode(key);
	}
	return true;
    }
};
