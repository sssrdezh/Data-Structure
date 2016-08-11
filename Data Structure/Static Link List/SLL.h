#pragma once
#define MAXSIZE 1000
#define ERROR -1
#define OK 0;
typedef int Status;
typedef double ElemType;
struct Component
{
	ElemType data;
	int cur;
};
typedef Component StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space);
int Malloc_SLL(StaticLinkList space);
void Free_SLL(StaticLinkList space, int i);
Status ListInsert(StaticLinkList L, int i, ElemType e);
int ListLength(StaticLinkList L);
