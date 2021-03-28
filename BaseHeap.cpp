//--------------------------------------------------------------------
//
//  Laboratory 11                                             Heap.cpp
//
//  Class declaration for the array implementation of the Heap ADataType
//
//--------------------------------------------------------------------

#include "BaseHeap.h"

//==================================================================================

///Preconditions: Valid and established heap from constructor
///Postconditions: data item is instantiated as an array of data type
///Inputs: None, initializes data item to store values from default constr
///Outputs: None
template <typename TypeOfData, typename TypeOfKey, typename Comparator>
BaseHeap < TypeOfData, TypeOfKey, Comparator> ::BaseHeap(int maxNumber)
{
	//default element size is 0
	sizeOfElements = 0;
	//combine derived member to base class's definition
	maxElements = maxNumber;
	//data item is a new array of type with a size equivalent to max elements
	itemData = new TypeOfData[maxElements];
}

//==================================================================================

///Preconditions: constructor must be valid and initialized
///Postconditions: constructor is copied and this is given memory of other
///Inputs: none
///Outputs: none, constructor is copied in memory
template <typename TypeOfData, typename TypeOfKey, typename Comparator>
BaseHeap< TypeOfData, TypeOfKey, Comparator>::BaseHeap(const BaseHeap& other)
{
	//this has memory equal to other
	*this = other;
}

//==================================================================================

///Preconditions: Heap is established and memory copy equal to other
///Postconditions: Heap is returned as memory address and equaled to other if not previously
///Inputs: None
///Outputs: None, data item array reinstantiated if not done from previous function
template <typename TypeOfData, typename TypeOfKey, typename Comparator>
BaseHeap<TypeOfData, TypeOfKey, Comparator>& BaseHeap<TypeOfData, TypeOfKey, Comparator>::operator=(const BaseHeap& other)
{
	if (this != &other)
	{
		clearHeap();

		sizeOfElements = other.sizeOfElements;
		maxElements = other.maxElements;

		itemData = new TypeOfData[maxElements];

		for (int i = 0; i < sizeOfElements; i++)
		{
			itemData[i] = other.itemData[i];
		}
	}
	return *this;
}

//==================================================================================

///Preconditions: Heap must be valid and with memory to clear
///Postconditions: Heap memory is cleared by destructor
///Inputs: User input to clear heap
///Outputs: Heap is shown to be cleared
template <typename TypeOfData, typename TypeOfKey, typename Comparator>
BaseHeap<TypeOfData, TypeOfKey, Comparator>::~BaseHeap()
{
	clearHeap();
}

//==================================================================================

///Preconditions: 
///Postconditions: 
///Inputs: 
///Outputs: 
/**
	@brief Remove, it will remove the data with the highest priority and returns it, logic error if empty
	@param nothing
	@return data that was deleted
*/
template <typename TypeOfData, typename TypeOfKey, typename Comparator>
TypeOfData BaseHeap< TypeOfData, TypeOfKey, Comparator>::deleteItem() throw (logic_error)
{
	//if heap is empty, throw logic error because cannot delete an item from a heap with no items
	if (isHeapEmpty() == true)
		throw logic_error("Heap is Empty! Cannot remove item from empty heap!");

	//object of data type that is a temporary value
	TypeOfData placeHolder;
	//object whose job is to return data
	TypeOfData ReturnData;
	//index
	int index = 0;
	//instantiate max value as each index is added
	int maxVal = index;

	//element size is decremented when an item is deleted
	sizeOfElements--;

	//return data is instantiated as an array of data type with a size of index
	ReturnData = itemData[index];
	//array's size is instantiated by size of elements
	itemData[index] = itemData[sizeOfElements];

	//while the index is less than the heap size, check max value of heap
	while (index < sizeOfElements)
	{
		//if the index consists of two children
		if ((index * 2 + 2) < sizeOfElements)
		{
			//if right is larger, max value is to the right by incrementing maxVal by 2
			if (comparator(itemData[(index * 2) + 2].getPriority(), itemData[maxVal].getPriority()))
				maxVal = index * 2 + 2;
			//if left is larger, max value is to the left by incrementing maxVal by 1
			if (comparator(itemData[index * 2 + 1].getPriority(), itemData[maxVal].getPriority()))
				maxVal = index * 2 + 1;
			//if child is greater than the parent
			if (maxVal != index)
			{
				//temp array of data item with size of index
				placeHolder = itemData[index];
				//index array is instantiated to maxVal array
				itemData[index] = itemData[maxVal];
				//maxVal array is instantiated to temp
				itemData[maxVal] = placeHolder;
				//index number is updated
				index = maxVal;
			}
			//else if parent is the largest, return
			else
				return ReturnData;
		}
		//else if only one child (since it is a heap then left)
		else if ((index * 2 + 1) < sizeOfElements)
		{
			//if the child is left, give priority
			if (comparator(itemData[index * 2 + 1].getPriority(), itemData[maxVal].getPriority()))
			{
				//maxVal is to the left by incrementing by 1
				maxVal = index * 2 + 1;

				//temp array of data item with size of index
				placeHolder = itemData[index];
				//index array is instantiated to maxVal array
				itemData[index] = itemData[maxVal];
				//maxVal array is instantiated to temp
				itemData[maxVal] = placeHolder;
				//index number is updated
				index = maxVal;
			}
			//else just return data index
			else
				return ReturnData;
		}
		//if there is no child  to check
		else 
			return ReturnData;
	}

	//return the data value of the index removed
	return ReturnData;
}

//==================================================================================

///Preconditions: Heap should be valid and have items inside it of memory.
///Postconditions: Heap is cleared if it is not empty.
///Inputs: User inputs to clear heap.
///Outputs: Heap is cleared.
template <typename TypeOfData, typename TypeOfKey, typename Comparator>
void BaseHeap < TypeOfData, TypeOfKey, Comparator> ::clearHeap()
{
	while (isHeapEmpty() == false)
	{
		deleteItem();
	}
}

//==================================================================================

///Preconditions: Heap should be valid and instantiated.
///Postconditions: Heap returns whether empty or not.
///Inputs: User input to check if empty.
///Outputs: Either empty or not empty returned.
/**
	@brief isEmpty, just return the size if not 0 then it is not empty
	@param nothing
	@return true/ false if empty then true
*/
template <typename TypeOfData, typename TypeOfKey, typename Comparator>
bool BaseHeap<TypeOfData, TypeOfKey, Comparator>::isHeapEmpty() const
{
	//heap returned if empty or not.
	return sizeOfElements == 0;
}

//==================================================================================

///Preconditions: Heap should be valid and instantiated.
///Postconditions: Heap returns whether full or not.
///Inputs: User input to check if full.
///Outputs: Either full or not full returned.
template <typename TypeOfData, typename TypeOfKey, typename Comparator>
bool BaseHeap<TypeOfData, TypeOfKey, Comparator>::isHeapFull() const
{
	//if size of elements is equal to max num elements, then full
	return sizeOfElements == maxElements;
}

//==================================================================================

///Preconditions: //Heap must be valid.
///Postconditions: Heap's structure is shown
///Inputs: User starts program with input to allow for structure to be shown
///Outputs: Structure of heap is outputted.
template <typename TypeOfData, typename TypeOfKey, typename Comparator>
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

//==================================================================================

///Preconditions: Heap must be valid and deployed.
///Postconditions: Heap's left and right subtrees are displayed.
///Inputs: User input to add values to heap.
///Outputs: Heap output with branch structure.
template < typename TypeOfData, typename TypeOfKey, typename Comparator >
void BaseHeap<TypeOfData, TypeOfKey, Comparator>::showSubtree(int i, int treeLevel) const
{
	//loop count
	int loopCount;   

	//if index is less than size of elements, go through following
	if (i < sizeOfElements)
	{
		//Output right sub
		showSubtree(2 * i + 2, treeLevel + 1);       
		//Move over to mid-level
		for (loopCount = 0; loopCount < treeLevel; loopCount++)        
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
		showSubtree(2 * i + 1, treeLevel + 1);        
	}
}

//==================================================================================

///Preconditions: Heap must be valid and instantiated.
///Postconditions: Items are added to heap
///Inputs: User input "+" and item to add.
///Outputs: Item added and displayed in heap.
template <typename TypeOfData, typename TypeOfKey, typename Comparator>
void BaseHeap<TypeOfData, TypeOfKey, Comparator>::addItem(const TypeOfData& newDataItem) throw (logic_error)
{
	//add temp value and present index variable equal to size of items
	TypeOfData temp;
	int indexPresent = sizeOfElements;

	//if heap is full, throw exception that heap is full and no more can be added.
	if (isHeapFull() == true)
		throw logic_error("Heap is full! Cannot add more items.");

	//add array of type item to new data items
	itemData[indexPresent] = newDataItem;
	//increment size of items
	sizeOfElements++;
	//Compare item to parent root node
	while (comparator(itemData[indexPresent].getPriority(), itemData[(indexPresent - 1) / 2].getPriority()))
	{
		//Start of heap swap comparison
		temp = itemData[(indexPresent - 1) / 2];
		itemData[(indexPresent - 1) / 2] = itemData[indexPresent];
		//next item is equal to temp, so swapped
		itemData[indexPresent] = temp;
		//Swap completed

		//Index is updated in heap
		indexPresent = (indexPresent - 1) / 2;
	}
}
//==================================================================================