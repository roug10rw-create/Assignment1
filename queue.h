#ifndef QUEUE_H
#define QUEUE_H
#include <string>

struct User {
	std::string username;
	int level;
	std:: string faction
};

struct Node{
	User data;
	Node* next;
};

void initQueue(Queue& q);
bool isEmpty(Queue& q);
int enqueue(Queue& q, User u);
int dequeue(Queue& q, User& u);

int endqueueRandonUsers(Queue& q, int count);

#endif
