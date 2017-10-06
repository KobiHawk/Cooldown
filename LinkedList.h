#pragma once
#include "Projectile.h"

class Node
{
public:
	Node() {}
	~Node() {}
	Node* getNext() { return next; }
	void setNext(Node* node) { next = node; }
private:
	Projectile projectile;
	Node* next;
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	bool add(Projectile newProjectile);
	bool remove(Projectile* newProjectile);
private:
	Node* head;
};

