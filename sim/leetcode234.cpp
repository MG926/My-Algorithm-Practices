#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //链表模拟
        int n=0;
        ListNode* now_node = head;
        while(now_node){
            n++;
            now_node = now_node->next;
        }
        int k=n/2;
        ListNode* last_node;
        now_node = head;
        while(k){
            k--;
            ListNode* temp_node = now_node->next;
            if(now_node == head) now_node->next = nullptr;
            else now_node->next = last_node;
            last_node = now_node;
            now_node = temp_node;
        }
        if(n%2) now_node = now_node->next;
        while(now_node && last_node){
            if(now_node->val != last_node->val) return false;
            now_node = now_node->next;
            last_node = last_node->next;
        }
        return true;
    }
};