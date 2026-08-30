#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA) return NULL;
        if(!headB) return NULL;
        ListNode* nodeA=headA, *nodeB=headB;
        while(nodeA!=nodeB){
            nodeA = nodeA?nodeA->next:headB;
            nodeB = nodeB?nodeB->next:headA;
        }
        return nodeA;
    }
};