#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

int main()
{
    Solution s;
    int val;
    cin>>val;
    ListNode* snode = new ListNode(val);
    ListNode* head= snode;
    ListNode* tnode;
    for(int i=0;i<3;i++){
        cin>>val;
        ListNode* node= new ListNode(val);
        if(i==1) tnode = node;
        head->next = node;
        head = node;
    }
    head->next = tnode;
    s.detectCycle(snode);
    return 0;
}