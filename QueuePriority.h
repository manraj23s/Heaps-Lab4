#pragma once
//--------------------------------------------------------------------
//
//  Laboratory 11, Programming Exercise 1              PriorityQueue.h
//
// Inherits the array implementation of the Heap ADT
// Class declared for heap impl. of the Priority Queue ADT 
//
//--------------------------------------------------------------------

#include <stdexcept>
#include <iostream>
#include "BaseHeap.cpp"
using namespace std;

//--------------------------------------------------------------------

// Default maximum queue size
const int defaultMaxQueueSize = 10;   

//comparator template of priority queue which is derived from BaseHeap
template < typename TypeOfData, typename TypeOfKey = int, typename Comparator = Less<TypeOfKey> >
class QueuePriority : public BaseHeap<TypeOfData>
{
public:
    //Constructor
    QueuePriority(int maxNumber = defaultMaxQueueSize);

    //Queue operations
    //Enqueue element
    void elementEnqueue(const TypeOfData& newDataItem);   
    //Dequeue element
    TypeOfData elementDequeue();                            
};

