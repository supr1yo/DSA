# Simple stack
class Stack:
    def __init__(self):
        self.stack = []
    
    def push(self, item):
        """
        Push an item onto the stack.

        Parameters:
        item (any): The item to be pushed onto the stack.
        """
        print('Operation: Push\n')
        self.stack.append(item)
        print('Inserted element: ', self.stack[len(self.stack) - 1])
        
    def pop(self):
        '''Removes the last item/top item'''
        print('Operation: Pop\n')
        if(len(self.stack) < 1):
            print('Empty stack.Unable to perform pop')
        else:
            print(f'Deleted element: {self.stack.pop(len(self.stack) - 1)}')
            
    
    def display(self):
        '''Displaying the stack'''
        print(f'Stack contents: {self.stack}\n')
        print(f'[Top: {self.stack[len(self.stack) - 1]}]')


s = Stack()

print('===================\n')
print(
        ' 1: Push\n',
        '2: Pop\n',
        '3: Display\n'
        )
print('===================\n')

while 1:
    ch = int(input('Enter your Choice: '))
    if ch==1:
        item = input('Enter the item: ')
        s.push(item)
    elif ch==2:
        s.pop()
    elif ch==3:
        s.display()