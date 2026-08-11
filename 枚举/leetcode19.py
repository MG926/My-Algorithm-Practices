# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        """思路：先遍历一遍链表得到链表长度和信息，然后定位到删除节点的前一个位置进行删除操作，时间复杂度为O(N)"""
        _len = 1
        now_node = head
        lists = [head]
        while(1):
            if(now_node.next == None): break
            _len += 1
            lists.append(now_node.next)
            now_node = now_node.next
        if(_len == 1): return None
        front = _len-n-1
        if(front == -1):
            return head.next
        front_node = lists[front]
        front_node.next = front_node.next.next
        return head