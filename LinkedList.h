// Guards
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Node to represent a list item: could be class or struct
class Node {
    public:
        int data;
        Node* next;
        // Default Constructor
        Node() : data(0), next(nullptr) {}
        Node(int d) : data(d), next(nullptr) {}
        Node(int d, Node* nxt) : data(d), next(nxt) {}
        ~Node() {}
};

class LinkedList {
    public:
        LinkedList();

        ~LinkedList();

        void push(Node*& newHead);

        void append(Node*& newNode);

        void insert(Node*& newNode, int position);

        void removeFirst();

        void removeLast();

        void remove(int position);

        bool search(int target);

        void swap(Node*& current, Node*& nxt);

        void sortAsc();

        void sortDesc();

        void printList();

        int getSize() const;

        bool isEmpty();

    private:
        Node* head; // head pointer (points to the first element of the list)
        Node* tail; // tail pointer (points to the last element of the list)
        int size; // List size
};
#endif