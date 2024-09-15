class TreeNode:
    def __init__(self, value: int) -> None:
        self.value = value
        self.children = []
    
    def add_child(self, child: any):
        self.children.append(child)