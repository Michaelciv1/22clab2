/*
  CIS 22B

    Lab3: Simulates people entering and leaving lines outside of a grocery store
        using queues.

  Author: Michael Wallerius
  Date: 5/8/2020
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Queue.h"

using namespace std;

int random(int lower_bound, int upper_bound);

int main()
{
    Queue* adultQueue = new Queue();
	Queue* seniorQueue = new Queue();
    srand(time(0));

    for (int x = 0; x < 5; x++){
        adultQueue->enqueue(random(18,59));
        seniorQueue->enqueue(random(60,100));
    }

    cout << "Initial Adult Line: ";
    adultQueue->print();
    cout << "Initial Senior Line: ";
    seniorQueue->print();
    cout << "Press enter or 'e' to exit " << endl;

    while (cin.get() != 'e') {
        int adultTemp, seniorTemp;
        adultTemp = random(18,59);
        seniorTemp = random(60,100);

        cout << "press enter or 'e' to end " << endl;
        cout << "Entered Store: " << seniorQueue->dequeue() << " " << adultQueue->dequeue() << endl;

        cout << "New Arrivals: " << adultTemp << " " << seniorTemp << endl;
        adultQueue->enqueue(adultTemp);
        seniorQueue->enqueue(seniorTemp);

        cout << "Current Adult Line: ";
        adultQueue->print();
        cout << "Current Senior Line: ";
        seniorQueue->print();
    }
}

int random(int lower_bound, int upper_bound){
    int n = rand();
    n %= (upper_bound - lower_bound + 1);
    n += lower_bound;
    return n;
}

/*
OUTPUT
Initial Adult Line: 41 31 41 44 36
Initial Senior Line: 80 72 64 78 79
Press enter or 'e' to exit

press enter or 'e' to end
Entered Store: 80 41
New Arrivals: 51 95
Current Adult Line: 31 41 44 36 51
Current Senior Line: 72 64 78 79 95

press enter or 'e' to end
Entered Store: 72 31
New Arrivals: 32 61
Current Adult Line: 41 44 36 51 32
Current Senior Line: 64 78 79 95 61

press enter or 'e' to end
Entered Store: 64 41
New Arrivals: 54 87
Current Adult Line: 44 36 51 32 54
Current Senior Line: 78 79 95 61 87

press enter or 'e' to end
Entered Store: 78 44
New Arrivals: 54 61
Current Adult Line: 36 51 32 54 54
Current Senior Line: 79 95 61 87 61

press enter or 'e' to end
Entered Store: 79 36
New Arrivals: 39 75
Current Adult Line: 51 32 54 54 39
Current Senior Line: 95 61 87 61 75
*/
