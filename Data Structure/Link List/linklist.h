#pragma once
#include<ctime>
#include<cstdlib>
typedef int Status;
typedef double ElemType;

struct Node
{
	ElemType data;
	struct Node *next;
};
typedef struct Node Node;
typedef struct Node *LinkList;
#define ERROR -1;
#define OK 0;
void CreateListHead(LinkList *L, int n);
Status GetElem(LinkList L, int i, ElemType *e);