#include "Set.h"
#include <limits.h>
#include <iostream>

using namespace std;

Set::Set()
{
    elementNum = 0;
    pData = NULL;
}

// Write a copy constructor. Do not forget the dynamically allocated attributes!
Set::Set(const Set &theOther)
{
    elementNum = theOther.elementNum;
    int *temp = new int[elementNum];
    for (int i = 0; i < elementNum; i++)
    {
        temp[i] = theOther.pData[i];
    }
    pData = temp;
}

// Write a destructor: release dynamically allocated resources.
Set::~Set()
{
    delete pData;
    pData = NULL;
}
// If the set contains some element, then the same element cannot be inserted again;
// in this case the method should return true indicating that the element is already there in the set.
bool Set::insert(int element)
{
    if (elementNum == INT_MAX)
    {
        //Queue is full
        return false;
    }
    int i;
    /*for (i = 0; i < elementNum; i++)
    {
        if (pData[i] == element)
            return true;
    }*/
    if (isElement(element))
    {
        return true;
    }
    int *ptr = new int[elementNum + 1];
    for (i = 0; i < elementNum; i++)
    {
        ptr[i] = pData[i];
    }
    ptr[elementNum] = element;
    if (pData != NULL)
    {
        delete[] pData;
    }
    pData = ptr;
    elementNum += 1;
    return true;
}

// Remove an element from the set.
// If there is no such element in the set, then the method should return flase.
bool Set::remove(int element) //Slight Problem fix it
{
    /*int RemainElem = elementNum-element;
    if(RemainElem < 0)
    {
        return false;
    }
    int* ptrR = new int[RemainElem];
    for(int i=0;i<RemainElem;i++)
    {
        ptrR[i] = pData[i+element];
    }
    elementNum =-element;
    return true;*/
    int i;
    int j = 0;
    if (!isElement(element)|| elementNum<=0)
    {
        return false;
    }
    int *temp = new int[elementNum - 1];

    for (i = 0; i < elementNum - 1; i++)
    {
        if (pData[i] != element)
        {
            temp[j] = pData[i];
            j++;
        }
    }
    if (pData != NULL)
    {
        delete[] pData;
    }
    pData = temp;
    delete[] temp;
    elementNum--;
    return true;
}

// Check if the given element is contained by the set.
bool Set::isElement(int element)
{
    for (int i = 0; i < elementNum; i++)
    {
        if (pData[i] == element)
            return true;
    }
    return false;
}
// Print the set elements separated by spaces. Puts a new line before the first an after the last elements.
void Set::print()
{
    int i;
    for (i = 0; i < elementNum; i++)
    {
        cout << "Queue" << i + 1 << ":  " << pData[i] << endl;
    }
    cout << endl;
}

//Clear the set (delete all elements)
void Set::empty()
{
    delete[] pData;
    pData = NULL;
    elementNum = 0;
}