//--------------------------------------------------------------------
//
//  Laboratory 11                                         show11.cpp
//
//  Array implementation of the showStructure operation for the
//  Heap ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include "BaseHeap.h"
using namespace std;

//--------------------------------------------------------------------

// Outputs the priorities of the data items in a heap in both array
// and tree form.
template < typename TypeOfData, typename TypeOfKey, typename Comparator >
void BaseHeap<TypeOfData, TypeOfKey, Comparator>::showStructure() const
{
	//loop counter
	int loopCount;

	//if no user input of elements, then output empty heap
	if (sizeOfElements == 0)
		cout << "\nEmpty heap" << endl;
	//else, output heap tree
	else
	{
		//Output array type of heap
		cout << "size = " << sizeOfElements << endl;
		//for i less than max size, output while iterating items of heap
		for (loopCount = 0; loopCount < maxElements; loopCount++)
			cout << loopCount << "\t";
		cout << endl;
		//output priority members of heap then iterate
		for (loopCount = 0; loopCount < sizeOfElements; loopCount++)
			cout << itemData[loopCount].getPriority() << "\t";
		cout << endl << endl;
		//output tree
		showSubtree(0, 0);
	}
}

//--------------------------------------------------------------------

// Helper function for the showStructure() function.
template < typename TypeOfData, typename TypeOfKey, typename Comparator >
void BaseHeap<TypeOfData, TypeOfKey, Comparator>::showSubtree(int i, int level) const
{
	//loop count
	int loopCount;

	//if index is less than size of elements, go through following
	if (i < sizeOfElements)
	{
		//Output right sub
		showSubtree(2 * i + 2, level + 1);
		//Move over to mid-level
		for (loopCount = 0; loopCount < level; loopCount++)
			cout << "\t";
		//Output priority item
		cout << " " << itemData[i].getPriority();
		//Output sign to connect items "<"
		if (2 * i + 2 < sizeOfElements)
			cout << "<";
		//Output sign to connect items "\\"
		else if (2 * i + 1 < sizeOfElements)
			cout << "\\";
		cout << endl;
		//Output left sub
		showSubtree(2 * i + 1, level + 1);
	}
}

//--------------------------------------------------------------------
