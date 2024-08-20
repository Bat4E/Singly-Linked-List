// This to practice building Data Structures
// Linked List

#include "LinkedList.h"
#include <iostream>

// Default Constructor
LinkedList::LinkedList() {
    head = nullptr; 
    tail = nullptr;
    size = 0;
}

// Destructor
LinkedList::~LinkedList() {
    Node* current = head; // temp helper pointer
    // iterates through the list and deletes all nodes
    while (current) { // nullptr == 0, in C/C++ 0 == false
        Node* next = current->next; // helper pointer
        delete current; // free memory
        current = next; // step over the list
    }
}

// adds Node to the head of the list (first position)
void LinkedList::push(Node*& newHead) {
    if (isEmpty()) {
        head = newHead;
        tail = newHead;
        size++;
    } else {
        newHead->next = head;
        head = newHead;
        size++;
    }
}

// adds Node to the tail of the list (last position)
// another day...
void LinkedList::append(Node*& newNode) {
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
        size++;
    } else {
        Node* current = head;
        while (current->next != nullptr) { // checking to stop right at the last node
            current = current->next;
        }
        current->next = newNode;
        tail = newNode;
        size++;
    }
}

// inserts a node on the given position if its possible
void LinkedList::insert(Node*& newNode, int position) {
    int currentPosition = 0; // counter to keep track of the current position
    
    if (position < 0) {
        std::cout << "Position is a negative number, out of bound." << std::endl;
    } else if ((size == 0) && (position > 0)) {
            std::cout << "The List is empty, position is out of bound." << std::endl;
    } else {
        if (position == 0) {
            push(newNode);
            std::cout << "Inserted node to head of the list at position: " << currentPosition << std::endl;
        } else if (position == size) {
            append(newNode);
            std::cout << "Inserted node to end of the list at position: " << size << std::endl;
        } else {
            Node* current = head;
            Node* previous = nullptr;
            while (currentPosition < position) {
                previous = current; // keeps track of previous node of desired inserting position
                current = current->next;
                currentPosition++;
            }
            newNode->next = current;
            previous->next = newNode;
            size++;
            std::cout << "Inserted node at position: " << currentPosition << std::endl;
        }
    }
}

// removes the first node of the list
void LinkedList::removeFirst() {
    if (isEmpty()) {
        std::cout << "The List is empty already, can't remove node..." << std::endl;
    } else {
        Node* current = head;

        head = head->next;
        current->next = nullptr;
        delete current;
        size--;
    }
}

// removes the last node of the list
void LinkedList::removeLast() {
    if (isEmpty()) {
        std::cout << "The List is empty already, can't remove node..." << std::endl;
    } else if (size == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;
    } else {
        Node* current = head;
        Node* previous = nullptr;
        int position = 1;
        // traversing the list
        while (current && position < size) {
            previous = current;
            current = current->next;
            position++;
        }
        delete tail;
        tail = previous;
        tail->next = nullptr;
        size--;
    }
}

// removes node from the list, any position
void LinkedList::remove(int position) {
    if (position <= 0) {
        std::cout << "The List is empty already, can't remove node..." << std::endl;
    } else if (position > size) {
        std::cout << "Out of bound..." << std::endl;
    } else if (position == 1) { // removing first element
        removeFirst();
    } else if (position == size) { // removing last element
        removeLast();
    } else {
        Node* current = head;
        Node* previous = nullptr;
        int currentPosition = 1;
        // traversing the list
        while (current && currentPosition < position) {
            previous = current;
            current = current->next;
            currentPosition++;
        }
        previous->next = current->next; // skips one
        delete current; // delete desired node
        size--;
    }
}

// searches for a node, return true or false if it exists.
bool LinkedList::search(int target) {
    Node* current = head;
    bool found = false;
    while (current) {
        if (current->data == target) {
            found = true;
        }
        current = current->next;
    }
    return found;
}

// swaps data from two nodes
void LinkedList::swap(Node*& current, Node*& nxt) {
    int data = 0; // helper
    data = current->data;
    current->data = nxt->data;
    nxt->data = data;
}

// sorts the list in ascending order
void LinkedList::sortAsc() {
    Node* current = nullptr;
    bool swaps = true;
    
    if (isEmpty()) {
        std::cout << "The list is empty..." << std::endl;
    } else if (size == 1) {
        std::cout << "List is sorted." << std::endl;
    } else {
        // swap is we're not done
        while (swaps) {
            // resetting values
            swaps = false;
            current = head;

            // traverse the list
            while (current && current->next) {
                if (current->data > current->next->data) {
                    swap(current, current->next);
                    swaps = true;
                }
                current = current->next;
            }
        }
    }
}

// sorts the list in descending order
void LinkedList::sortDesc() {
        Node* current = nullptr;
    bool swaps = true;
    
    if (isEmpty()) {
        std::cout << "The list is empty..." << std::endl;
    } else if (size == 1) {
        std::cout << "List is sorted." << std::endl;
    } else {
        // swap is we're not done
        while (swaps) {
            // resetting values
            swaps = false;
            current = head;

            // traverse the list
            while (current && current->next) {
                if (current->data < current->next->data) {
                    swap(current, current->next);
                    swaps = true;
                }
                current = current->next;
            }
        }
    }
}

// displays the List Nodes
void LinkedList::printList(){
    if (head == nullptr) {
        std::cout << "List is empty." << std::endl;
    } else {
        Node* current = head;
        std::cout << "List data:";
        while (current) {
            std::cout << " " << current->data;
            current = current->next;
        }
        std::cout << std::endl;
    }
}

// Gets Lists' size
int LinkedList::getSize() const {
    return size;
}

// Checks if list is Empty or not
bool LinkedList::isEmpty() {
    if (size == 0)
        return true;
    else
        return false;
}