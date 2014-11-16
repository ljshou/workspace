# Definition for singly-linked list.
class ListNode:
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution:
	def mergeList(self, lhs, rhs):
		new_list = ListNode(-1)
		rear = new_list

		while lhs != None and rhs != None:
			if lhs.val < rhs.val:
				rear.next = lhs
				lhs = lhs.next
			else:
				rear.next = rhs
				rhs = rhs.next
			rear = rear.next

		if lhs != None:
			rear.next = lhs

		if rhs != None:
			rear.next = rhs

		return new_list.next

# @param head, a ListNode
# @return a ListNode
	def sortList(self, head):
		if head == None or head.next == None:
			return head
	  # fast-slow scheme to divide list into two parts
		fast = head.next
		slow = head
		while fast != None and fast.next != None:
			fast = fast.next.next
			slow = slow.next

		list2 = slow.next
		slow.next = None
		return self.mergeList(self.sortList(head), self.sortList(list2))

if __name__ == '__main__':
	head = ListNode(3)
	head.next = ListNode(0)
	head.next.next = ListNode(1)
	head.next.next.next = ListNode(2)

	head = Solution().sortList(head)
	while head != None:
		print head.val
		head = head.next
