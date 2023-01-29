  
class Node():
    def __init__(self,name):
        self.children = []
        self.name = name
        
    def add_child(self, name):
        self.children.append(Node(name))
    def display(self):
        return self.children.name
        
    def bfs(self, array):
        qeue = [self]
        while len(qeue) > 0:
            current = qeue.pop(0)
            array.append(current.name)
            for child in current.children:
                qeue.append(child)
        return array
        
print("hi im shahin sha \m came here after hatched")
