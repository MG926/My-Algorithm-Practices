#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        //递归翻转
        bfs(root);
        return root;
    }
    void bfs(TreeNode* root){
        if(!root) return;
        bfs(root->left);
        bfs(root->right);
        TreeNode* temp=root->left;
        root->left = root->right;
        root->right = temp;
        return;
    }
};