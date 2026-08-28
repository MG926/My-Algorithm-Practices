# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        """思路：模拟就行"""
        pre = ListNode(-1)
        ans =pre
        if(not list1): return list2
        if(not list2): return list1
        while(list1 and list2):
            if(list1.val<list2.val):
                ans.next = list1
                list1 = list1.next
            else:
                ans.next = list2
                list2 = list2.next
            ans = ans.next
        ans.next = list1 if list1 else list2
        return pre.next