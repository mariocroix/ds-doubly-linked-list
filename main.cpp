#include "list.hpp"

int main() {
    List<int> myList;

    std::cout << "Inserting elements...\n";
    myList.push_back(3);
    myList.push_front(1);
    myList.push_back(5);
    myList.push_front(2);

    std::cout << "Original list: ";
    myList.print();

    std::cout << "\nReversed list: ";
    myList.reverse();
    myList.print();

    std::cout << "\nRemoving elements...\n";
    myList.pop_back();
    myList.pop_front();

    std::cout << "List after removal: ";
    myList.print();

    std::cout << "\nInserting at position 1...\n";
    myList.insert(1, 4);

    std::cout << "List after insertion: ";
    myList.print();

    std::cout << "\nRemoving at position 1...\n";
    myList.remove(1);

    std::cout << "List after removal: ";
    myList.print();

    std::cout << "\nPrinting in reverse...\n";
    myList.rprint();

    std::cout << "\nChecking for cycle...\n";
    if (myList.hasCycle()) {
        std::cout << "The list has a cycle.\n";
        std::cout << "Start point of the cycle: " << myList.getStartPoint() << "\n";
    } else {
        std::cout << "The list does not have a cycle.\n";
    }

    return 0;
}

