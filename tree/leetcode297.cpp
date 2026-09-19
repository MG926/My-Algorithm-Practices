#include <iostream>
#include <list>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        dfsSerialize(root,s);
        return s;
    }
    void dfsSerialize(TreeNode* root, string& s){
        if(!root) s += "null,";
        else{
            s += to_string(root->val)+",";
            dfsSerialize(root->left,s);
            dfsSerialize(root->right,s);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> datalist;
        string str="";
        for(auto ch:data){
            if(ch==','){
                datalist.push_back(str);
                str.clear();
            }else str += ch;
        }
        if(str.length()){
            datalist.push_back(str);
            str.clear();
        }
        return dfsDeserialize(datalist);
        
    }

    TreeNode* dfsDeserialize(list<string>& datalist){
        if(datalist.front()=="null"){
            datalist.erase(datalist.begin());
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(datalist.front()));
        datalist.erase(datalist.begin());
        root->left = dfsDeserialize(datalist);
        root->right = dfsDeserialize(datalist);
        return root;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));