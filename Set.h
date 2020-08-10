#ifndef SET_H
#define SET_H
#include <stdio.h>

class Set
{
    int elementNum;
    int* pData;
public:
    // Initialize an empty set.
    Set();

    // Write a copy constructor. Do not forget the dynamically allocated attributes!
    Set(const Set &theOther);

    // Write a destructor: release dynamically allocated resources.
    ~Set();

    // Insert a new element into the set. If no memory can be allocated, false is to be returned.
    // If the set contains some element, then the same element cannot be inserted again;
    // in this case the method should return true indicating that the element is already there in the set.
    bool insert(int element);

    // Remove an element from the set.
    // If there is no such element in the set, then the method should return flase.
    bool remove(int element);

    // Check if the given element is contained by the set.
    bool isElement(int element);

    // Print the set elements separated by spaces. Puts a new line before the first an after the last elements.
    void print();

    //Clear the set (delete all elements)
    void empty();
};
#endif /* SET_H */
	