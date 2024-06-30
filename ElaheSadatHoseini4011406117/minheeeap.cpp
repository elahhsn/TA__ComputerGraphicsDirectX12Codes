#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class MinHeap {
private:
    Node* head;

    void swap(Node* a, Node* b) {
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

    void heapifyDown(Node* start) {
        Node* smallest = start;
        Node* left = start->next;
        Node* right = left ? left->next : nullptr;

        if (left && left->data < smallest->data)
            smallest = left;
        if (right && right->data < smallest->data)
            smallest = right;

        if (smallest != start) {
            swap(smallest, start);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;

        // Adjust the heap
        Node* current = head;
        while (current && current->next && current->data > current->next->data) {
            swap(current, current->next);
            current = current->next;
        }
    }

    int extractMin() {
        if (!head) {
            throw runtime_error("Heap is empty!");
        }

        int minValue = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;

        if (head) {
            heapifyDown(head);
        }

        return minValue;
    }

    int getMin() {
        if (!head) {
            throw runtime_error("Heap is empty!");
        }
        return head->data;
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~MinHeap() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    MinHeap heap;

    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(30);
    heap.insert(2);

    cout << "Min-Heap elements: ";
    heap.display();

    cout << "Extracted Min: " << heap.extractMin() << endl;

    cout << "Min-Heap after extraction: ";
    heap.display();

    cout << "Current Min: " << heap.getMin() << endl;

    return 0;
}
