class Node:
    '''
    Node of linked list
    '''
    def __init__(self, data: any = None, next: any = None):
        self.data = data
        self.next = next
    

class LinkedList:
    def __init__(self):
        self.head = None
    
    def create(self, data: any = None, next: any = None):
        '''
        Creates a node
        '''
        node = Node(data, self.head)
        self.head = node
    
    def create_list(self, size: int = 1):
        '''
        Creates linked list
        '''
        for i in range(size):
            data = input('Enter the data: ')
            self.create(data)
    
    def insert_at_first(self, data: any = None):
        node = Node(data)
        node.next = self.head
        self.head = node
    
    def insert_at_last(self, data: any = None):
        node = Node(data)
        if self.head is None:
            self.head = node
        else:
            temp = self.head

            while temp.next:
                temp = temp.next
            temp.next = node
    
    def delete_from_first(self):
        self.head = self.head.next
    

    def delete_from_last(self):
        '''
        Deletes the last node of linked list.
        '''
        print()
        temp = self.head
        while temp.next:
            temp_prev = temp
            temp = temp.next
        temp_prev.next = None 
    
    def display(self):
        '''
        Displays the linked list.
        '''
        if self.head is None:
            print('Linked list is empty.')
        
        link_list = ''
        temp = self.head
        while temp: # Run the loop as long as temp is not None.
            link_list += str(temp.data) + '-->'
            temp = temp.next
        print(link_list)




List = LinkedList()


while True:
    print('Please enter the option\n')
    print('1: Create list.')
    print('2: Insert a node at first.')
    print('3: Insert a node at last.')
    print('4: Delete the first node.')
    print('5: Delete the last node.')
    print('6: Display the linked list.')
    print('7: Exit the program.')
    choice = int(input('Choice: '))
    if choice == 1:
        size = int(input('Enter the size of linked list: '))
        List.create_list(size)
    elif choice == 2:
        data = int(input('Enter the value: '))
        List.insert_at_first(data)
    elif choice == 3:
        data = int(input('Enter the value: '))
        List.insert_at_last(data)
    elif choice == 4:
        List.delete_from_first()
    elif choice == 5:
        List.delete_from_last()
    elif choice == 6:
        List.display()
    elif choice == 7:
        break
