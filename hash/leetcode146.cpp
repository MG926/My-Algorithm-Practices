#include <iostream>
#include <unordered_map>
using namespace std;

struct LinkedNode{
    int key,value;
    LinkedNode* prevNode;
    LinkedNode* nextNode;
    LinkedNode():key(0),value(0),prevNode(nullptr),nextNode(nullptr){}
    LinkedNode(int _key, int _value):key(_key),value(_value),prevNode(nullptr),nextNode(nullptr){}
};

class LRUCache {
private:
    unordered_map<int,LinkedNode*> cache;
    LinkedNode* head;
    LinkedNode* tail;
    int _capacity,size;
public:
    LRUCache(int capacity) {
        head = new LinkedNode();
        tail = new LinkedNode();
        head->nextNode = tail;
        tail->prevNode = head;
        _capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        LinkedNode* node = cache[key];
        To_Head(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            LinkedNode* node = cache[key];
            node->value = value;
            To_Head(node);
        }else{
            if(_capacity==size){
                LinkedNode* tail_node = tail->prevNode;
                cache.erase(tail_node->key);
                remove_node(tail_node);
                delete tail_node;
            }else{
                size++;
            }
            LinkedNode* new_node = new LinkedNode(key,value);
            cache[key] = new_node;
            new_node->nextNode = head->nextNode;
            head->nextNode = new_node;
            new_node->prevNode = head;
            new_node->nextNode->prevNode = new_node;
        }
    }
    void To_Head(LinkedNode* node){
        remove_node(node);
        node->nextNode = head->nextNode;
        head->nextNode = node;
        node->prevNode = head;
        node->nextNode->prevNode = node;
    }
    void remove_node(LinkedNode* node){
        node->prevNode->nextNode = node->nextNode;
        node->nextNode->prevNode = node->prevNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */