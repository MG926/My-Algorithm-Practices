#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Trie {
//26叉树查找前缀字符串
private:
    vector<Trie*> children;
    bool isEnd;

    Trie* SearchPrefix(string prefix){
        Trie* node = this;
        for(auto ch:prefix){
            ch -= 'a';
            if(!node->children[ch]) return nullptr;
            node = node->children[ch];
        }
        return node;
    }
public:
    vector<string> word_list;
    Trie(): children(26),isEnd(false){}
    
    void insert(string word) {
        Trie* node=this;
        for(auto ch:word){
            ch -= 'a';
            if(!node->children[ch]) node->children[ch] = new Trie();
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node=SearchPrefix(word);
        return node!=nullptr && node->isEnd;
    }
    
    bool startsWith(string prefix) {
        return this->SearchPrefix(prefix)!=nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */