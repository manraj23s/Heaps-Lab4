#pragma once
//--------------------------------------------------------------------
//
//  Laboratory 11                                             Heap.h
//
//  Class declaration for the array implementation of the Heap ADataType
//
//--------------------------------------------------------------------

#include <stdexcept>
#include <iostream>

using namespace std;

//template for Heap that checks if one value is less than another
template < typename TypeOfKey = int >
class Less {
public:
    bool operator()(const TypeOfKey& a, const TypeOfKey& b) const { return a < b; }
};

//template for Heap that uses comparator for checking less than
template < typename TypeOfData, typename TypeOfKey = int, typename Comparator = Less<TypeOfKey> >
class BaseHeap
{
public:
    //Default max heap size
    static const int maxHeapDefault = 10;   

    //Constructor
    //Default and basic constructor
    BaseHeap(int numMax = maxHeapDefault);
    //Constructor copy
    BaseHeap(const BaseHeap& other);		    
    //Assignment operator overloaded
    BaseHeap& operator= (const BaseHeap& other);  

    //Destructor
    ~BaseHeap();

    //Manipulation operations of heap
    //Data item insert
    void addItem(const TypeOfData& newDataItem)    
        throw (logic_error);
    //Max priority element removed
    TypeOfData deleteItem() throw (logic_error); 
    //Heap cleared
    void clearHeap();                          

    //Heap status operations
    //Empty heap
    bool isHeapEmpty() const;                  
    //Full heap
    bool isHeapFull() const;                   

    //Output heap, testing and debugging purpose
    void showStructure() const;

private:
    //showStructure() recursive helper
    void showSubtree(int index, int level) const;

    //Data members
    //Max num elements in heap
    int maxElements;
    //Actual num elements in heap
    int sizeOfElements;     
    TypeOfData* itemData; // Array containing the heap elements

    Comparator comparator;
};
