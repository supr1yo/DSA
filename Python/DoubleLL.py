class Node:
    def __init__(self, data: any = None, next: any = None, prev: any = None) -> None:
        self.data = data
        self.next = next
        self.prev = prev

class DoubleLL:
    def __init__(self) -> None:
        self.head = None
    
    def create_node(self, data: any):
        node = Node(data, self.head, None)
        self.head = node
        node.prev = None