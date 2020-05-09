#ifndef QUEUE_H
#define QUEUE_H

class Queue {
      private:
          struct Person{
            int age;
            Person *next;
          };

         Person *front;  // points to the first person in the queue
         Person *rear;  // points to the last person in the queue
         int numPeople;
      public:
         Queue();  // constructor initializes head and tail pointers to null
         ~Queue(); // destructor destroys the list
         void enqueue(int);  // adds a person to the end of the queue
         int dequeue();   // removes a person from the beginning of the queue
         bool isEmpty();   // returns true if the queue is empty;
         void print(); // prints the queue on the screen in one line, each person (age) separated by a space
};

#endif // QUEUE_H
