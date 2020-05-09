#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Queue.h"

using namespace std;

int random(int lower_bound, int upper_bound);

int main()
{
    Queue queue;
    srand(time(0));
    cout << "Press enter or 'e' to exit " << endl;

    for (int x = 0; x < 5; x++){
        int f = random(30,70);
        cout << f << " ";
        queue.enqueue(f);
    }

    //queue.print();

    //queue.dequeue();
    //queue.print();

    while (cin.get() != 'e') {
           cout << "press enter or 'e' to end ";
           // remove one person from the senior line
           // remove one person from the adult line
           // generate two random people and place them in the correct line
       }
}

int random(int lower_bound, int upper_bound){
    int n = rand();
    n %= (upper_bound - lower_bound + 1);
    n += lower_bound;
    return n;
}
