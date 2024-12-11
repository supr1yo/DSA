class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    # Create linked list
    def create(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        
        current = self.head
        
        while current.next:
            current = current.next
        current.next = new_node
    
    # Insert at first
    def insert_at_first(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    # Insert at last
    def insertAtLast(self, data):
        newNode = Node(data)

        current = self.head

        while current.next:
            current = current.next
        current.next = newNode


    # Display the linked list
    def display(self):
        current = self.head

        while current:
            print(current.data, end=" -> ")
            current = current.next
        print('None')


if __name__ == "__main__":
    ll = LinkedList()
    ll.create(10)
    ll.create(20)

    ll.display()  # Output: 10 -> 20 -> None
