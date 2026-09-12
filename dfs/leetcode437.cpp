#include <iostream>
#include <unordered_map>
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
private:
    unordered_map<long long,int> hash;
public:
    int pathSum(TreeNode* root, int targetSum) {
        hash[0]++;
        return dfs(root,0,targetSum);
    }
    int dfs(TreeNode* root, long long cursum, int targetSum){
        if(!root) return 0;
        cursum += root->val;
        int ret=0;
        if(hash.count(cursum-targetSum)) ret = hash[cursum-targetSum];
        hash[cursum]++;
        int left_ret = dfs(root->left,cursum,targetSum),right_ret = dfs(root->right,cursum,targetSum);
        hash[cursum]--;

        return ret+left_ret+right_ret;
    }
};