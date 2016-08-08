#include "linklist.h" 
/*
 * ��������--ͷ�巨
 * 1.����һ�����p�ͼ���������i��
 * 2.��ʼ��һ��������L��
 * 3.��L��ͷ����ָ��ָ��NULL����������һ����ͷ���ĵ�������
 * 4.ѭ��
 *		*����һ���½�㣬��ֵ��p��
 *		*�������һ�����ָ�ֵ��p��������p->data;
 *		*��p���뵽ͷ�����ǰһ�½��֮�䡣
*/
void CreateListHead(LinkList *L, int n)
{
	LinkList p;
	srand(unsigned(time(0)));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->data = NULL;
	(*L)->next = nullptr;
	for (int i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;

	}
}
/*
 * �������Ķ�ȡ
 * 1.����һ�����pָ�������ĵ�һ����㣬��ʼ��j��1��ʼ��
 * 2.��j<iʱ���ͱ�����������p��ָ������ƶ�������ָ����һ��㣬j�ۼ�1��
 * 3.��������ĩβpΪ�գ���˵����i��Ԫ�ز����ڣ�
 * 4.������ҳɹ������ؽڵ�p�����ݡ�
*/
Status GetElem(LinkList L, int i, ElemType *e)
{
	int j;
	LinkList p; /*����һ�����p*/
	p = L->next; /*��pָ������L�ĵ�һ�����*/
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