# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        """思路：利用leetcode21代码，采取归并排序思想，时间复杂度为O(KNLOGN)"""
        n = len(lists)
        if(n==0): return None
        if(n==1): return lists[0]
        while(n>1):
            stack = []
            k = 0
            while(k<n):
                if(k==n-1): stack.append(lists[k])
                else:
                    list1 = lists[k]
                    list2 = lists[k+1]
                    new_list = self.mergeLists(list1,list2)
                    stack.append(new_list)
                k += 2
            lists = stack.copy()
            n = len(lists)
        return lists[0] 
    def mergeLists(self, list1,list2):
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
