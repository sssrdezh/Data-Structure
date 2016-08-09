#pragma once
#include<ctime>
#include<cstdlib>

typedef double ElemType;
typedef int Status;
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
void CreateListTail(LinkList *L, int n);
Status GetElem(LinkList L, int i, ElemType *e);
Status ListInsert(LinkList *L, int i, ElemType e);
Status ListDelete(LinkList *L, int i, ElemType *e);
Status ClearList(LinkList *L);