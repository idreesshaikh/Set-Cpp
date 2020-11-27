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
	
    Set(const Set &theOther);
.
    ~Set();
    bool insert(int element);
	
    bool remove(int element);

    bool isElement(int element);

    void print();

    void empty();
};
#endif /* SET_H */
	
