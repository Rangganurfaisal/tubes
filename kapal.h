#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include<iostream>
#include<cstdlib>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define Head(Q) ((Q).Head)
#define Tail(Q) ((Q).Tail)
#define Top(S) ((S).Top)

typedef struct elm_kapal *adr_kapal;

struct kapal{
	string nama;
	int kapasitas;
};

struct elm_kapal{
	kapal info;
	adr_kapal next;
};

struct Queue{
	adr_kapal Head, Tail;
};

struct Stack{
	adr_kapal Top;
};

adr_kapal create_element(kapal k);
bool isQueueEmpty(Queue Q);
void createQueue(Queue &Q);
void enqueue(Queue &Q, kapal k);
kapal dequeue(Queue &Q);
void showQueue(Queue Q);
bool isStackEmpty(Stack S);
void createStack(Stack &S);
void push(Stack &S, kapal k);
kapal pop(Stack &S);

#endif
