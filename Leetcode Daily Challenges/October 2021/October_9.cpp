# include <bits/stdc++.h>


using namespace std;


class Node{
	public:
	vector<Node *> children;
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


class Solution {
public:
    int DIRECTIONS[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void findWords(Node *root, int x, int y, vector<vector<char>> &board, vector<string> &res, string curr, set<string> &s){
	if(root->isComplete && s.count(curr)){
		res.push_back(curr);
		s.erase(curr);
	}
	char temp = board[x][y];
	board[x][y] = '#';    
    	for(auto dir: DIRECTIONS){
		int newX = x + dir[0], newY = y + dir[1];
		if(newX < 0 || newY < 0 || newX >= board.size() || newY >= board[0].size() || board[newX][newY] == '#' || !root->containsKey(board[newX][newY])){
			continue;
		}
		findWords(root->getNode(board[newX][newY]), newX, newY, board, res, curr + board[newX][newY], s);
	}
	board[x][y] = temp;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Node* root = new Node();
    set<string> s;
	for(string word: words){
		Node *dummy = root;
        s.emplace(word);
		for(int i = 0; i < word.length(); i++){
			char key = word[i];
			if(!dummy->containsKey(key)){
				dummy->addKey(key);
			}
			dummy = dummy->getNode(key);
		}
        dummy->isComplete = true;
	}
	int N = board.size(), M = board[0].size();
	vector<string> res;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			Node *dummy = root;
			string curr = "";
			if(dummy->containsKey(board[i][j])){
				curr += board[i][j];
				findWords(dummy->getNode(board[i][j]), i, j, board, res, curr, s);
			}
		}
	}
	return res;
    }
};

