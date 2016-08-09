#include "linklist.h" 



/*
 * 创建链表--头插法
 * 1.声明一个结点p和计数器变量i；
 * 2.初始化一个空链表L；
 * 3.让L的头结点的指针指向NULL，即建立了一个带头结点的单链表；
 * 4.循环
 *		*生成一个新结点，赋值给p；
 *		*随机生成一个数字赋值给p的数据域p->data;
 *		*将p插入到头结点与前一新结点之间。
*/
void CreateListHead(LinkList *L, int n)
{
	LinkList p,r;
	srand(unsigned(time(0)));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->data = NULL;
	(*L)->next = nullptr;
	r = *L;
	for (int i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = r->next;
		r->next = p;

	}
}
/*
 * 创建链表--尾插法
*/
void CreateListTail(LinkList *L, int n)
{
	LinkList p,r;
	srand(unsigned(time(0)));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->data = NULL;
	(*L)->next = nullptr;
	r = *L;
	for (int i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = nullptr;
		r->next = p;
		r = r->next;
	}
}
/*
 * 单链表的读取
 * 1.声明一个结点p指向链表的第一个结点，初始化j从1开始；
 * 2.当j<i时，就遍历链表，让p的指针向后移动，不断指向下一结点，j累加1；
 * 3.若到链表末尾p为空，则说明第i个元素不存在；
 * 4.否则查找成功，返回节点p的数据。
*/
Status GetElem(LinkList L, int i, ElemType *e)
{
	int j;
	LinkList p; /*声明一个结点p*/
	p = L->next; /*让p指向链表L的第一个结点*/
	j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;
	*e = p->data;
	return OK;
}
/*单链表插入结点*/
Status ListInsert(LinkList *L, int i, ElemType e)
{
	int j;
	LinkList p,s;
	p = (*L)->next;
	j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
Status ListDelete(LinkList *L, int i, ElemType *e)
{
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	while (p->next && j < i)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i)
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}
Status ClearList(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next;
	while (p->next)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(p);
	(*L)->next = nullptr;
	return OK;
}