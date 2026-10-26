
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int i, left, right;
    int chopsticks[5] = {0, 0, 0, 0, 0};

    srand(time(0));

    for (i = 0; i < 5; i++)
    {
        cout << "Philosopher " << i
             << " is thinking..." << endl;

        left = i;
        right = (i + 1) % 5;

        if (chopsticks[left] == 0 &&
            chopsticks[right] == 0)
        {
            chopsticks[left] = 1;
            chopsticks[right] = 1;

            cout << "Philosopher " << i
                 << " is eating..." << endl;

            chopsticks[left] = 0;
            chopsticks[right] = 0;

            cout << "Philosopher " << i
                 << " put down chopsticks." << endl;
        }
        else
        {
            cout << "Philosopher " << i
                 << " is waiting..." << endl;
        }

        cout << endl;
    }

    return 0;
}
