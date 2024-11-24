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
    
    # Display
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
