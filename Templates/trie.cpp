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


