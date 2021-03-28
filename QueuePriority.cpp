//--------------------------------------------------------------------
//
//  Laboratory 11, Programming Exercise 1            PriorityQueue.cpp
//
//  ** SOLUTION: Heap implementation of the Priority Queue ADT **
//
//--------------------------------------------------------------------

using namespace std;
#include "QueuePriority.h"

//--------------------------------------------------------------------

///Preconditions: Queue heap must be valid.
///Postconditions: Empty priority queue created
///Inputs: User starts program
///Outputs: Empty priority queue created.
template < typename TypeOfData, typename TypeOfKey, typename Comparator >
QueuePriority<TypeOfData, TypeOfKey, Comparator>::QueuePriority(int maxNumber)
    : BaseHeap<TypeOfData, TypeOfKey, Comparator>(maxNumber)
{}

//--------------------------------------------------------------------

///Preconditions: Queue must have been created.
///Postconditions: New data item inserted into queue.
///Inputs: User input to add item to queue.
///Outputs: New item from queue outputted.
template < typename TypeOfData, typename TypeOfKey, typename Comparator >
void QueuePriority<TypeOfData, TypeOfKey, Comparator>::elementEnqueue(const TypeOfData& newDataItem)
{
    BaseHeap<TypeOfData, TypeOfKey, Comparator>::addItem(newDataItem);
}

//--------------------------------------------------------------------

///Preconditions: Items must have been added to queue to be able to dequeue
///Postconditions: First data item removed and returned.
///Inputs: User input to dequeue.
///Outputs: First added data item (least recent) outputted.
template < typename TypeOfData, typename TypeOfKey, typename Comparator >
TypeOfData QueuePriority<TypeOfData, TypeOfKey, Comparator>::elementDequeue()
{
    return BaseHeap<TypeOfData, TypeOfKey, Comparator>::deleteItem();
}

