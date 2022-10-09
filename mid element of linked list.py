class Node:
	def __init__(self, data):
		self.data = data 
		self.next = None 

class LinkedList:
	def __init__(self):
		self.head = None
		
	def push(self, new_data):
		new_node = Node(new_data)
		new_node.next = self.head
		self.head = new_node

	def printList(self):
		node = self.head
		while node:
			print(str(node.data) + "->", end = "")
			node = node.next
		print("NULL")

	def printMiddle(self):
		count = 0
		mid = self.head
		ptr = self.head
		while(ptr != None):
		# Update mid, when 'count' is odd number
			if count&1:
				mid = mid.next
			count += 1
			ptr = ptr.next
			
		# If empty list is provided
		if mid!=None:
			print("The middle element is ", mid.data)

llist = LinkedList()
for i in range(5, 0, -1):
        llist.push(i)
        llist.printList()
        llist.printMiddle()
