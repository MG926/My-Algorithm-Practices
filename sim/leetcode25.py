# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        """思路：找到完整的长度为k的子链表的head前的pre节点以及tail节点：花费O(k)时间，空间O(1)。
            然后对这个子链表进行逆序：花费O(k)时间，空间O(1)。
            因此全部的时间复杂度为O(N)，空间O(1)"""
        if(k==1): return head
        pre = ListNode(-1)
        last_tail = pre
        last_tail.next = head
        now_node = head
        cnt = 1
        while(now_node and now_node.next):
            cnt += 1
            now_node = now_node.next
            if(cnt%k==0):
                last_tail = self.reverseGroup(last_tail,now_node)
                now_node = last_tail.next
                cnt = 1
        return pre.next
    def reverseGroup(self, pre, tail):
        tail_next = tail.next
        now_node = pre.next
        next_pre = now_node
        while(now_node!=tail):
            next_node = now_node.next
            now_node.next = tail_next
            tail_next = now_node
            now_node = next_node
        now_node.next = tail_next
        pre.next = now_node
        return next_pre
