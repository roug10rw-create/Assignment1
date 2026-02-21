#include "queue.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;   

void initQueue(Queue& q) {
    q.head = nullptr;
    q.tail = nullptr;
}

bool isEmpty(Queue& q) {
    return (q.head == nullptr);
}

int enqueue(Queue& q, User u) {

    Node* newNode = new Node;

    if (newNode == nullptr)
        return 1;

    newNode->data = u;
    newNode->next = nullptr;

    if (q.tail == nullptr) {
        q.head = newNode;
        q.tail = newNode;
    }
    else {
        q.tail->next = newNode;
        q.tail = newNode;
    }

    return 0;
}

int dequeue(Queue& q, User& u) {

    if (isEmpty(q))
        return 1;

    Node* temp = q.head;

    u = temp->data;
    q.head = temp->next;

    if (q.head == nullptr)
        q.tail = nullptr;

    delete temp;

    return 0;
}

string randomUsername() {

    string letters = "abcdefghijklmnopqrstuvwxyz0123456789";
    string name = "";

    for (int i = 0; i < 10; i++) {
        int index = rand() % letters.length();
        name += letters[index];
    }

    return name;
}

int enqueueRandomUsers(Queue& q, int count) {

    for (int i = 0; i < count; i++) {

        User u;

        u.username = randomUsername();
        u.level = (rand() % 60) + 1;

        int factionNumber = rand() % 3;

        if (factionNumber == 0)
            u.faction = "red";
        else if (factionNumber == 1)
            u.faction = "blue";
        else
            u.faction = "green";

        if (enqueue(q, u) != 0)
            return 1;
    }

    return 0;
}