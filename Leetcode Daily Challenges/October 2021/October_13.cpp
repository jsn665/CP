/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int i = 0;
    TreeNode* construct(vector<int> &preorder, int lowerBound, int upperBound){
        if(i == (int)preorder.size()){
            return NULL;
        }
        int value = preorder[i];
        if(!(value >= lowerBound && value <= upperBound)){
            return NULL;
        }
        i++;
        TreeNode *root = new TreeNode(value);
        root->left = construct(preorder, lowerBound, value);
        root->right = construct(preorder, value, upperBound);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(preorder, INT_MIN, INT_MAX);
    }
};
