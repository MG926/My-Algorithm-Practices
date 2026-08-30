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
        //利用数学a+m+b=b+m+a和双指针的操作方式来查找交点，时间复杂度O(m+n)
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