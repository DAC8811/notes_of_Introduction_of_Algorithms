#include <iostream>
#include "heap_priority_queue.h"

int main()
{
    std::cout << "Hello World!\n";
    heap_priority_queue<double> test({16.1,14.2,10.3,8.1,7.9,9,3.5,2,4,1.7,2.3,8.2});
    double max = test.maxium();
    cout << max << endl;
    for (int i = 0; i < 3; i++)
    {
        max = test.extract();
        cout << max << endl;
    }
    test.insert(18.9);
    max = test.extract();
    cout << max << endl;
    test.increase_key(5,19.3);
    max = test.extract();
    cout << max << endl;
}

