#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {
    int n = 5;
    int position = 5; // position begins at 1.
    LinkedList simpleList;
    Node* testNode = new Node(99, nullptr); // to test insert
    Node* arrayNodes[n] = {nullptr};
    int target = 2; // for searching a node
    bool found = false;
    int size = simpleList.getSize();

    // Testing push method
    for (int i = 0; i < n; i++) {
        arrayNodes[i] = new Node(i, nullptr);
        simpleList.push(arrayNodes[i]);
    }
    size = simpleList.getSize();

    std::cout << "Printing the list after using push method: " << std::endl;
    simpleList.printList();
    std::cout << "List size is: " << size << "." << std::endl;

    // testing append method
    for (int i = 0; i < n; i++) {
        arrayNodes[i] = new Node(i, nullptr);
        simpleList.append(arrayNodes[i]);
    }
    size = simpleList.getSize();

    std::cout << "Printing the list after using append method: " << std::endl;
    simpleList.printList();
    std::cout << "List size is: " << size << "." << std::endl;

    // testing insert method
    simpleList.insert(testNode, position);
    size = simpleList.getSize();
    
    std::cout << "Printing the list after using insert method: " << std::endl;
    simpleList.printList();
    std::cout << "List size is: " << size << "." << std::endl;

    // testing removeFirst method
    std::cout << "Testing removeFirst method, removing first element." << std::endl;
    simpleList.removeFirst();
    size = simpleList.getSize();

    std::cout << "Printing the list after using removeFirst method: " << std::endl;
    simpleList.printList();
    std::cout << "List size is: " << size << "." << std::endl;

    // testing removeLast method
    std::cout << "Testing removeLast method, removing last element." << std::endl;
    simpleList.removeLast();
    size = simpleList.getSize();

    std::cout << "Printing the list after using removeLast method: " << std::endl;
    simpleList.printList();
    std::cout << "List size is: " << size << "." << std::endl;

    // testing remove method
    // Test removing from an empty list
    position = 2;
    std::cout << "Testing remove method. Removing node: " << position << std::endl;
    simpleList.remove(position);
    size = simpleList.getSize();

    std::cout << "Printing the list after using rememove method: " << std::endl;
    simpleList.printList();
    std::cout << "List size is: " << size << "." << std::endl;

    // testing bool search
    std::cout << "Testing boolean search method. Searching 2 on the list, does it exits?" << std::endl;
    found = simpleList.search(target);
    if (found == true) {
        std::cout << "Found target node: " << target << std::endl;
    } else {
        std::cout << "Target node is not on the list..." << std::endl;
    }

    // testing ascending order list method
    std::cout << "Testing ascending order list method." << std::endl;
    simpleList.sortAsc();
    simpleList.printList();

    // testing descending order list method
    std::cout << "Testing descending order list method." << std::endl;
    simpleList.sortDesc();
    simpleList.printList();

    return 0;

}