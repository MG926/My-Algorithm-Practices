#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct nodeval{
    int selected;
    int unselected;
};
class Solution {
public:
    int rob(TreeNode* root) {
        nodeval ans=treerob(root);
        return max(ans.selected,ans.unselected);
    }
    nodeval treerob(TreeNode* root){
        if(!root) return {0,0};
        nodeval left = treerob(root->left),right = treerob(root->right);
        int selected = root->val+left.unselected+right.unselected;
        int unselected = max(left.unselected,left.selected)+max(right.selected,right.unselected);
        return {selected,unselected};
    }
};