#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //归并排序
        return mergesort(head,nullptr);
    }
    ListNode* mergesort(ListNode* head, ListNode* tail){
        if(head==nullptr) return head;
        if(head->next==tail){
            head->next = nullptr;
            return head;
        }
        ListNode* point1=head,*point2=head;
        while(point2!=tail){
            point1 = point1->next;
            point2 = point2->next;
            if(point2!=tail) point2 = point2->next;
        }
        ListNode* left_head=mergesort(head,point1),*right_head=mergesort(point1,tail);
        return merge(left_head,right_head);
    }
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* head_node = new ListNode(0);
        ListNode* head = head_node;
        while(head1 && head2){
            if(head1->val>head2->val){
                head->next = head2;
                head2 = head2->next;
            }else{
                head->next = head1;
                head1 = head1->next;
            }
            head = head->next;
        }
        if(head1) head->next = head1;
        if(head2) head->next = head2;
        return head_node->next;
    }
};

int main()
{
    Solution s;
    ListNode* head;
    ListNode* node=head;
    for(int i=0;i<4;i++){
        int num;
        cin >> num;
        ListNode tmp(num);
        head->next = &tmp;

    }
    head = s.sortList(node);
    return 0;
}