class Node:

    """ Container """

    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next


if __name__ == "__main__":
    node1 = Node(1)
    node2 = Node(2)
    node3 = Node(3)
    head = node1
    head.next = node2
    node2.next = node3
