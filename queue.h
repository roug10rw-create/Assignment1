#ifndef QUEUE_H
#define QUEUE_H

#include <string>

struct User {
    std::string username;
    int level;
    std::string faction;
};

struct Node {
    User data;
    Node* next;
};

struct Queue {
    Node* head;
    Node* tail;
};

void initQueue(Queue& q);
bool isEmpty(Queue& q);
int enqueue(Queue& q, User u);
int dequeue(Queue& q, User& u);

int enqueueRandomUsers(Queue& q, int count);

#endif