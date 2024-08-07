# Queue

class Queue:
    def __init__(self):
        self.queue = []
    
    
    def enqueue(self, item):
        '''Inserts element to the queue'''
        print('Operation: Enqueue')
        self.queue.append(item)
        print(f'Inserted element: {self.queue[len(self.queue) - 1]}')
        
        
    def dequeue(self):
        '''Removes the first element from queue'''
        print('Operation: Dequeue')
        if len(self.queue) < 1:
            print('Empty queue. Unable to perform dequeue.')
        else:
            print(f'Deleted element: {self.queue.pop(0)}')
    
    def display(self):
        '''Displaying the queue contents'''
        print(f'Queue contents: {self.queue}')
        print(f'[Front: {self.queue[0]}]')
        

q = Queue()

print('==================')
print('1: Enqueue')
print('2: Dequeue')
print('3: Display')
print('==================')

while 1:
    ch = int(input('Choose the option: '))
    if ch==1:
        item = input('Enter the item: ')
        q.enqueue(item)
    elif ch==2:
        q.dequeue()
    elif ch==3:
        q.display()
    