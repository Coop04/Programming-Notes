class Node {
    int data;
    Node prev;
    Node next;

    Node(int data) {
        this.data = data;
        this.prev = null;
        this.next = null;
    }
}

class DoublyLinkedList {
    Node head;

    public void insert(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
        newNode.prev = temp;
    }

    public void delete(int data) {
        Node currentNode = head;
        while (currentNode != null && currentNode.data != data) {
            currentNode = currentNode.next;
        }
        if (currentNode == null)
            return;
        if (currentNode.prev != null)
            currentNode.prev.next = currentNode.next;
        if (currentNode.next != null)
            currentNode.next.prev = currentNode.prev;
        if (currentNode == head)
            head = currentNode.next;
    }

    public void display() {
        Node currentNode = head;
        while (currentNode != null) {
            System.out.print(currentNode.data + " ");
            currentNode = currentNode.next;
        }
        System.out.println();
    }
}

public class DLinkedListOps {
    public static void main(String[] args) {
        DoublyLinkedList list = new DoublyLinkedList();
        list.insert(1);
        list.insert(2);
        list.insert(3);
        list.insert(4);
        System.out.println("Original List:");
        list.display();
        list.delete(3);
        System.out.println("List after deleting node with value 3:");
        list.display();
    }
}
