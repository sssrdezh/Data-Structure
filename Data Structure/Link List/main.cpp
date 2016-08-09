#include "linklist.h"

int main()
{
	int i;
	ElemType e;
	LinkList listHead,listTail;
	CreateListHead(&listHead, 10);
	CreateListTail(&listTail, 10);
	ListInsert(&listHead, 5, 3.14);
	ListDelete(&listHead, 5, &e);
	ClearList(&listTail);
	return 0;
}

