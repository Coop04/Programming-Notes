class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    Node head;

    public void add(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node temp = head;// for traversal
        while (temp.next != null) { //insert at end
            temp = temp.next;
        }
        temp.next = newNode;
    }

    public void delete(int data) {
        Node currentNode = head;
        Node prevNode = null;
        if (currentNode != null && currentNode.data == data) { // element at first position
            head = currentNode.next;
            return;
        }
        while (currentNode != null && currentNode.data != data) {
            prevNode = currentNode;
            currentNode = currentNode.next;
        }
        if (currentNode == null)
            return;
        prevNode.next = currentNode.next;
    }

    public boolean search(int data) {
        Node currentNode = head;
        while (currentNode != null) {
            if (currentNode.data == data) {
                return true;
            }
            currentNode = currentNode.next;
        }
        return false;
    }
}

public class LinkedListOps {
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        System.out.println("Original List:");
        printList(list);
        list.delete(3);
        System.out.println("List after deleting node with value 3:");
        printList(list);
        int searchValue = 2;
        if (list.search(searchValue)) {
            System.out.println(searchValue + " found in the list.");
        } else {
            System.out.println(searchValue + " not found in the list.");
        }
    }

    public static void printList(LinkedList list) {
        Node currentNode = list.head;
        while (currentNode != null) {
            System.out.print(currentNode.data + " ");
            currentNode = currentNode.next;
        }
        System.out.println();
    }
}
