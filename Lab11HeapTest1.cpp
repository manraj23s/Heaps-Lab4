
//--------------------------------------------------------------------
//
//  Laboratory 11 (test plan 11-1)                          test11.cpp
//
//  Version: 1
//  Date Originally Written: 3/23/2021
//  Data Last Modified: 3/28/2021
//  Author Names: Manraj Singh (Programming & Documentation)
//                Corey Shimshock (Documentation & Programming)
//  Purpose: Test program for the operations in the Heap ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include <string>
#include <cctype>
#include "BaseHeap.cpp"
using namespace std;

//--------------------------------------------------------------------
//print help menu message
void printHelp();
//--------------------------------------------------------------------

// Declaration for the heap data item class
template < typename TypeOfKey >
class TestDataItem
{
public:
    TestDataItem()
    {
        priorityItem = -1;
    }

    //Set priority
    void setPriority(TypeOfKey  newPty)
    {
        priorityItem = newPty;
    }       

    //Return priority
    TypeOfKey getPriority() const
    {
        return priorityItem;
    }            

private:
    //Priority for data item
    TypeOfKey  priorityItem;                   
};

template < typename TypeOfKey = int >
//class to check if item is greater than another
class Greater {
public:
    bool operator()(const TypeOfKey& a, const TypeOfKey& b) const { return a > b; }
};

int main()
{
    //Greater > uses the default int type for KeyType
    //Test heap
    BaseHeap<TestDataItem<int>, int, Greater<> > testHeap(8);  
    //Heap data item
    TestDataItem<int> testDataItem;       
    //User input priority
    int  priorityInput;                        
    //Input command
    char userCommand;                             

    //output help message
    printHelp();

    do
    {
        //Output heap
        testHeap.showStructure();                     

        //Read command
        cout << endl << "Command: ";                  
        cin >> userCommand;
        //Change input to uppercase
        userCommand = toupper(userCommand);			      

        if (userCommand == '+')
            cin >> priorityInput;

        switch (userCommand)
        {
        case 'H':
            printHelp();
            break;

        //Insert value
        case '+':                                  
            testDataItem.setPriority(priorityInput);
            cout << "Insert: Priority = " << testDataItem.getPriority() << endl;
            testHeap.addItem(testDataItem);
            break;
        
        //Remove value
        case '-':                                  
            testDataItem = testHeap.deleteItem();
            cout << "Removed data item: priority= " 
                 << testDataItem.getPriority() << endl;
            break;

        //Clear heap
        case 'C':                                  
            cout << "Clear the heap!" << endl;
            testHeap.clearHeap();
            break;

        //isEmpty
        case 'E':                                  
            if (testHeap.isHeapEmpty())
                cout << "Heap is empty!" << endl;
            else
                cout << "Heap is NOT empty!" << endl;
            break;

        //isFull
        case 'F':                                  
            if (testHeap.isHeapFull())
                cout << "Heap is full!" << endl;
            else
                cout << "Heap is NOT full!" << endl;
            break;
        
        //Quit test program
        case 'Q':                              
            break;

        //Invalid command
        default:                               
            cout << "Inactive or invalid command!" << endl;
        }
        //while user does not quit, keep going
    } while (userCommand != 'Q');

    return 0;
}

//--------------------------------------------------------------------

void printHelp()
{
    cout << endl << "Commands:" << endl;
    cout << "  H    : Help (displays this message)" << endl;
    cout << "  +(x) : Insert data item with priority (x)" << endl;
    cout << "  -    : Remove highest priority data item" << endl;
    cout << "  C    : Clear the heap" << endl;
    cout << "  E    : Empty heap?" << endl;
    cout << "  F    : Full heap?" << endl;
    cout << "  Q    : Quit the test program" << endl;
    cout << endl;
}
