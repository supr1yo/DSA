class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None



def inOrder(node):
    if node is None:
        return
    
    inOrder(node.left)
    print(node.data)
    inOrder(node.right)


def preOrder(node):
    if node is None:
        return
    
    print(node.data)
    preOrder(node.left)
    preOrder(node.right)

def postOrder(node):
    if node is None:
        return
    postOrder(node.left)
    postOrder(node.right)
    print(node.data)