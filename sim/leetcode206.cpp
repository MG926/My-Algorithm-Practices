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
private:
    ListNode* _head;
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        recursion(head);
        head->next = nullptr;
        return _head;
    }
    void recursion(ListNode* head){
        if(!head->next){
            _head = head;
            return;
        }
        recursion(head->next);
        head->next->next = head;
    }
};