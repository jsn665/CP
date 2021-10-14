# include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int DIRECTIONS[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    string s;
    vector<vector<char>> grid;
    bool backtrack(int x, int y, int i){
            if(i == s.length() - 1 && s[s.length() - 1] == grid[x][y]){
                return true;
            }
            else if(s[i] != grid[x][y]){
                return false;
            }
            char temp = grid[x][y];
            grid[x][y] = '#';
            for(auto dir : DIRECTIONS){
                int newX = dir[0] + x;
                int newY = dir[1] + y;
                if(newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[0].size() || grid[newX][newY] == '#') continue;
                if(backtrack(newX, newY, i + 1)){
                        return true;
                }
            }
            grid[x][y] = temp;
            return false;

    }

    bool exist(vector<vector<char>>& board, string word) {
              s = word;
              grid = board;
              int N = grid.size(), M = grid[0].size();
              for(int i = 0; i < N; i++){
                  for(int j = 0; j < M; j++){
                      if(grid[i][j] == s[0] && backtrack(i, j, 0)){
                          return true;
                      }
                      
                  }
              }
        return false;
    }
};

