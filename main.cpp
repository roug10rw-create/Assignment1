#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"

using namespace std;   // ✅ namespace used here

int main(int argc, char* argv[]) {

    if (argc != 2) {
        cout << "Usage: program <number_of_users>\n";
        return 1;
    }

    int count = atoi(argv[1]);

    if (count <= 0) {
        cout << "Invalid number of users.\n";
        return 1;
    }

    srand(time(NULL));

    Queue q;
    initQueue(q);

    if (enqueueRandomUsers(q, count) != 0) {
        cout << "Error creating users.\n";
        return 1;
    }

    cout << "\nDequeuing Users:\n\n";

    User u;

    while (!isEmpty(q)) {

        dequeue(q, u);

        cout << "Username: " << u.username << "\n";
        cout << "Level: " << u.level << "\n";
        cout << "Faction: " << u.faction << "\n\n";
    }

    return 0;
}