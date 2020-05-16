#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue(){
    front = nullptr;
    rear = nullptr;
    numPeople = 0;
}

Queue::~Queue(){
    while (!isEmpty())
    dequeue();
}

// This function takes no input and returns no value. It prints the current specified queue.
void Queue::print(){
    Person *nodePtr;
    nodePtr = front;

    while (nodePtr){
        cout << nodePtr->age << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}

// This function takes an integer as an input and returns no value. It enqueues the input to the specified queue.
void Queue::enqueue(int num){
    Person *newNode = nullptr;

    newNode = new Person;
    newNode->age = num;
    newNode->next = nullptr;

   if (isEmpty()){
      front = rear = newNode;
   }
   else{
      rear->next = newNode;
      rear = rear->next;
   }
   numPeople++;
}

//This function takes no input and returns an int as a value. It dequeues the first person in line in the specified queue.
int Queue::dequeue(){
    Person *temp = nullptr;
    int age = -1;

    if (!isEmpty()){
        age = front->age;
        temp = front;
        front = front->next;
        delete temp;
    }
    numPeople--;
    return age;
}

/*This function takes no input and returns a bool. It checks if the queue is empty.
Return value: true means the queue is empty
              false means the queue is not empty
*/
bool Queue::isEmpty(){
    return (numPeople == 0);
}
