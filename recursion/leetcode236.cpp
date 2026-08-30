#include <iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //递归模拟
        dfs(root,p,q);
        return ans;
    }
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return false;
        bool leftson = dfs(root->left,p,q);
        bool rightson = dfs(root->right,p,q);
        if((leftson&&rightson)||((root==p||root==q)&&(leftson||rightson))) ans = root;
        return root==p || root==q || leftson || rightson;
    }
};