#include <iostream>
#include <cstdlib>

using namespace std;

// Initialize a mutex to 1
int mutex = 1;

// Number of full slots as 0
int full = 0;

// Number of empty slots as size of buffer
int empty_slots, bufferSize, x = 0;

// Function to produce an item and add it to the buffer
void producer()
{
    // Decrease mutex value by 1
    --mutex;

    // Increase the number of full slots by 1
    ++full;

    // Decrease the number of empty slots by 1
    --empty_slots;

    // Item produced
    x++;
    cout << "\nProducer produces item " << x << endl;

    // Increase mutex value by 1
    ++mutex;
}

// Function to consume an item and remove it from buffer
void consumer()
{
    // Decrease mutex value by 1
    --mutex;

    // Decrease the number of full slots by 1
    --full;

    // Increase the number of empty slots by 1
    ++empty_slots;
    cout << "\nConsumer consumes item " << x << endl;
    x--;

    // Increase mutex value by 1
    ++mutex;
}

// Driver Code
int main()
{
    int n, i;
    cout << "\nEnter the buffer size: ";
    cin >> bufferSize;

    empty_slots = bufferSize;

    cout << "\n1. Press 1 for Producer"
        "\n2. Press 2 for Consumer"
        "\n3. Press 3 for Exit\n";

    for (i = 1; i > 0; i++) {

        cout << "\nEnter your choice: ";
        cin >> n;

        // Switch Cases
        switch (n) {
        case 1:

            // If mutex is 1 and empty is non-zero, then it is possible to produce
            if ((mutex == 1)
                && (empty_slots != 0)) {
                producer();
            }

            // Otherwise, print buffer is full
            else {
                cout << "Buffer is full!" << endl;
            }
            break;

        case 2:

            // If mutex is 1 and full is non-zero, then it is possible to consume
            if ((mutex == 1)
                && (full != 0)) {
                consumer();
            }

            // Otherwise, print Buffer is empty
            else {
                cout << "Buffer is empty!" << endl;
            }
            break;

        // Exit Condition
        case 3:
            exit(0);
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }

    return 0;
}
