# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """思路：简单的链表模拟题"""
        if(not head): return head
        if(not head.next): return head
        now_node = head
        pre_node = head
        while(now_node):
            next_node = now_node.next
            if(now_node == head):
                head = next_node
                now_node.next = head.next
                head.next = now_node
                pre_node = now_node
            else:
                if(not now_node.next): return head
                pre_node.next = now_node.next
                now_node.next = next_node.next
                next_node.next = now_node
                pre_node = now_node
            now_node = now_node.next
        return head