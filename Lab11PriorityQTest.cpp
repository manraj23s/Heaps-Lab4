
//--------------------------------------------------------------------
//
//  Laboratory 11, Programming Exercise 1                test11pq.cpp
//
//  Version: 1
//  Date Originally Written: 3/23/2021
//  Data Last Modified: 3/28/2021
//  Author Names: Manraj Singh (Programming & Documentation)
//                Corey Shimshock (Documentation & Programming)
//  Purpose: Test program for operations in the Priority Queue ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include <cctype>
#include "QueuePriority.cpp"
using namespace std;

//--------------------------------------------------------------------
//help message menu
void printHelp();

//--------------------------------------------------------------------
//
// Declaration for the priority queue data item class
//

class TestData
{
public:

    //Set priority
    void setPriority(int newPriority)
    {
        itemPriority = newPriority;
    }  

    //Return priority
    int getPriority() const
    {
        return itemPriority;
    }         

private:
    // Priority for the data item
    int itemPriority;                    
};

//--------------------------------------------------------------------

int main()
{
    //Test priority queue
    QueuePriority<TestData> testQueue(8);
    //Queue data item
    TestData testData;                 
    //User input priority
    int priorityInput;                      
    //Input command
    char userCommand;                          

    printHelp();

    //while the program is not quit from, keep continuing program
    do
    {
        //Output queue
        testQueue.showStructure();                    

        //Read command
        cout << endl << "Command (H for help): ";     
        cin >> userCommand;
        //Turn user command to uppercase
        userCommand = toupper(userCommand);			   
        //if user commands + or >, then ask for more input
        if ((userCommand == '+') || (userCommand == '>'))
            cin >> priorityInput;

        switch (userCommand)
        {
        //Enqueue
        case '+':                                  
            testData.setPriority(priorityInput);
            cout << "Enqueue: pty= " << testData.getPriority()
                << endl;
            testQueue.elementEnqueue(testData);
            break;

        //Dequeue
        case '-':                                  
            testData = testQueue.elementDequeue();
            cout << "Dequeued: pty= " << testData.getPriority()
                << endl;
            break;

        //Clear queue
        case 'C':
            cout << "Clear the queue!" << endl;
            testQueue.clearHeap();
            break;

        //isEmpty
        case 'E':                                  
            if (testQueue.isHeapEmpty())
                cout << "Queue is empty!" << endl;
            else
                cout << "Queue is NOT empty!" << endl;
            break;

        //isFull
        case 'F':                                  
            if (testQueue.isHeapFull())
                cout << "Queue is full!" << endl;
            else
                cout << "Queue is NOT full!" << endl;
            break;

        //Print out help menu
        case 'H':                                  
            printHelp();
            break;

        // Quit test program
        case 'Q':                                  
            break;

        //Invalid command
        default:                                   
            cout << "Invalid or inactive command!" << endl;
        }
    } while (userCommand != 'Q');

    return 0;
}

void printHelp() {
    cout << endl << "Commands:" << endl;
    cout << "  +x : Enqueue data item with priority (x)" << endl;
    cout << "  -  : Dequeue data item" << endl;
    cout << "  C  : Clear the queue" << endl;
    cout << "  E  : Empty queue?" << endl;
    cout << "  F  : Full queue?" << endl;
    cout << "  H  : Print this help message" << endl;
    cout << "  Q  : Quit the test program" << endl;
    cout << endl;
}