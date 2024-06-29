class Node():
    def __init__(self,key:int,val:int):
        self.key = key 
        self.val = val
        self.next = None
        self.prev = None

class LRUCache(object):

    def __init__(self,cap:int):
        self.head = Node(-1,-1)
        self.tail = Node(-1,-1)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.cap = cap
        self.m = dict()

    def append(self,node:Node):
        temp = self.head.next
        node.next = temp
        node.prev = self.head
        self.head.next = node
        temp.prev = node
    
    def remove(self,delnode:Node):
        delprev = delnode.prev
        delnext = delnode.next
        delprev.next = delnext 
        delnext.prev = delprev
        del delnode

    def get(self, key):
        if self.m.get(key) != None:
            resnode =  self.m.get(key)
            value = resnode.val
            del self.m[key]
            self.remove(resnode)
            self.append(resnode)
            self.m[key] = self.head.next
            return value
        return -1
        

    def put(self, key, value):
        if self.m.get(key) != None:
            temp = self.m.get(key)
            del self.m[key]
            self.remove(temp)
        if len(self.m) == self.cap:
            del self.m[self.tail.prev.key]
            self.remove(self.tail.prev)
        
        self.append(Node(key,value))
        self.m[key] = self.head.next 
        



# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)