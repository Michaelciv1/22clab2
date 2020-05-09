    #include "Queue.h"
    #include <iostream>

    using namespace std;

Queue::Queue()
    {
        front = nullptr;
        rear = nullptr;
        numPeople = 0;
    }

Queue::~Queue()
    {
        while (!isEmpty())
        dequeue();
    }

void Queue::print(){
        Person *nodePtr;
        nodePtr = front;

        while (nodePtr){
            cout << nodePtr->age << " ";
            nodePtr = nodePtr->next;
        }
        cout << endl;
    }

void Queue::enqueue(int num)
    {

       Person *seniorNode = nullptr;
       Person *adultNode = nullptr;

    if (num >= 60){
         seniorNode = new Person;
         seniorNode->age = num;
         seniorNode->next = nullptr;

         if (isEmpty()){
            front = rear = seniorNode;
            }
         else{
            rear->next = seniorNode;
            rear = rear->next;
        }
       numPeople++;
    }
    else{
       adultNode = new Person;
       adultNode->age = num;
       adultNode->next = nullptr;
       }

       if (isEmpty())
       {
          front = rear = adultNode;
       }
       else
       {
          rear->next = adultNode;
          rear = rear->next;
       }
       numPeople++;
    }

int Queue::dequeue()
    {
       Person *temp = nullptr;
       int age = -1;

       if (!isEmpty())
       {
          age = front->age;
          temp = front;
          front = front->next;
          delete temp;
       }
       numPeople--;
       return age;
    }

bool Queue::isEmpty()
    {
       return (numPeople == 0);
    }
