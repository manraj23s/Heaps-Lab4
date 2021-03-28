
//--------------------------------------------------------------------
//
//  Laboratory 11, Programming Exercise 1 (test plan 11-2)    ossim.cs
//
//  Version: 1
//  Date Originally Written: 3/23/2021
//  Data Last Modified: 3/28/2021
//  Author Names: Manraj Singh (Programming & Documentation)
//                Corey Shimshock (Documentation & Programming)
//  Purpose: (Shell) Operating system task scheduling simulation
//
//--------------------------------------------------------------------

// Simulates an operating system's use of a priority queue to regulate
// access to a system resource (printer, disk, etc.).

#include <iostream>
#include <cstdlib>
#include "QueuePriority.cpp"
#include <time.h>
using namespace std;

//--------------------------------------------------------------------

// Declaration for the task data struct
struct DataTask
{
    //Returns priority needed by heap.
    int getPriority() const
    {
        return prioritizedTask;
    }     
    
    //Task priority
    int prioritizedTask;
    //Time when task enqueued
    int timeOfEnqueue;                 
};

//--------------------------------------------------------------------

int main()
{
    //Priority queue of tasks
    QueuePriority<DataTask, int, Less<int> > taskPQ;   
    //Task
    DataTask taskFromData;               
    //Length of simulation (minutes)
    int lengthSimulation;
    //Current minute
    int minute;                  
    //Number of priority levels
    int numberPriorityLevels;            
    //Number of new tasks arriving
    int numberOfArrivals;             
    //Loop counter
    int loopCount;                       

    //Seed the random number generator with 7 random numbers
    srand(7);

    cout << "Enter # of priority levels: ";
    cin >> numberPriorityLevels;

    cout << "Enter the length of time to run the simulator: ";
    cin >> lengthSimulation;

    //while minute is less than simulator time, dequeue elements 
    for (minute = 0; minute < lengthSimulation; minute++)
    {
        // Dequeue the first task in the queue (if any).
        if (taskPQ.isHeapEmpty() == false)
        {
            taskFromData = taskPQ.elementDequeue();
            cout << "At " << minute <<" minutes: dequeued: " << "task priority: " << taskFromData.prioritizedTask << " at time of enque: " 
                 << taskFromData.timeOfEnqueue << " with " << (minute - taskFromData.timeOfEnqueue) << " priority." << endl;
        }

        //Determine the number of new tasks and add them to the queue in range 0 to 4
       numberOfArrivals = rand() % 4;
		
       //if number of new tasks arriving is 1, perform
		if( numberOfArrivals == 1 )
		{
            //display random number of priority level, enqueue time, and the enqueued element
			taskFromData.prioritizedTask = rand() % numberPriorityLevels;
			taskFromData.timeOfEnqueue = minute;
			taskPQ.elementEnqueue(taskFromData);
		}
		
        //if number of new tasks arriving is 2, perform
		if( numberOfArrivals == 2 )
		{
            //display random number of priority level, enqueue time, and the enqueued element
			taskFromData.prioritizedTask = rand() % numberPriorityLevels;
			taskFromData.timeOfEnqueue = minute;
			taskPQ.elementEnqueue(taskFromData);
			
            //display random number of priority level, enqueue time, and the enqueued element
			taskFromData.prioritizedTask = rand() % numberPriorityLevels;
			taskFromData.timeOfEnqueue = minute;
			taskPQ.elementEnqueue(taskFromData);
		}
    }
    return 0;
}

