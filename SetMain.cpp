#include "Set.cpp"

using namespace std;

void printSet(Set& s);
void printSet(Set* ps);	


void printSet(Set& s)
{
	s.print();
}


void printSet(Set* ps)
{
	ps->print();
}

int main(void)
{
	Set s1;	// a Set object is created

	// Insert is tested
	s1.insert(1);
	s1.insert(1);  // Inserting a duplicated element, the total number of elements should not change at this line
	s1.insert(2);
	s1.print();

	// Testing isElement method
	if(s1.isElement(1)&&s1.isElement(2)&&!s1.isElement(3))
	{
		printf("\nisElement seems OK.\n");
	}


	// Testing a copy constructor
	Set s2(s1);	// Explicit copy constructor call
	Set s3=s1;	// Copy constructor is called by initialization

	
	printSet(s1);	// The parameter is passed by value -> copy is created -> copy constructor is called
	printSet(s2);	// The parameter is passed by value -> copy is created -> copy constructor is called
	printSet(&s3);	// The address of set object is passed -> copy constructor is NOT called

	s2.remove(1);	// Testing remove method
	printSet(s2);	// Checking the result of remove operation
	//NO
	printSet(s1);	// Making sure that the other set object remained unchanged (if not -> problems in copy constructor)
	s2.remove(1);	// Further testing of remove method: make sure that false is returned. Use debugger.

// Empty Function
	s1.empty();
	s2.empty();
	s3.empty();
	return 0;
}

/* After having checked and executed the code, modify the following function
	void printSet(Set s);
   to have a reference type parameter:
	void printSet(Set &s);
   Remember to do it twice: in the implementation (.cpp) and in the prototype (header).
*/
