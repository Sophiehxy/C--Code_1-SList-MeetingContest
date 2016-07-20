#pragma once
#include<malloc.h>
#include<cassert>

typedef int DataType;
typedef struct ListNode
{
	DataType _data;
	struct ListNode* _next;
}ListNode;

void InitList(ListNode** pHead)//��pHead�ĵ�ַ�������ö���ָ��
{
	*pHead = NULL;
}

ListNode* BuyNode(DataType x)
{
	ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
	tmp->_data = x;
	tmp->_next = NULL;
	return tmp;
}

//-------------------β��---------------------//
void PushBack(ListNode** pHead,DataType x)
{
	//1������Ϊ��
	if (*pHead == NULL)
	{
		*pHead = BuyNode(x);
	}
	//2������Ϊ��
	else
	{
		ListNode* cur = *pHead;
		while (cur->_next!=NULL)
		{
			cur = cur->_next;
		}
		cur->_next = BuyNode(x);
	}
}

//-------------------ͷ��---------------------//
void PushFront(ListNode** pHead, DataType x)
{
	if (*pHead == NULL)
	{
		*pHead = BuyNode(x);
		(*pHead)->_next = NULL;
	}
	else
	{
		ListNode* tmp = BuyNode(x);
		tmp->_next = *pHead;
		*pHead = tmp;
	}
}

//-------------------����λ��---------------------//
ListNode* Find(ListNode* pHead, DataType x)
{
	ListNode* cur = pHead;
	while (cur != NULL)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
//-------------------����---------------------//
void Insert(ListNode* pos, DataType x)
{
	assert(pos);
	//��һ��
	/*ListNode* tmp = BuyNode(x);
	tmp->_next = pos->_next;
	pos->_next = tmp;*/
	//����:(��ñ���pos->_next->_next�����)
	/*ListNode* next = pos->_next;
	pos->_next = BuyNode(x);
	pos->_next->_next = next;*/
	//������
	ListNode* next = pos->_next;
	ListNode* tmp = BuyNode(x);
	tmp->_next = next;
	pos->_next = tmp;
}

//-------------------βɾ---------------------//
void PopBack(ListNode*& pHead)
{
	//1������Ϊ��
	if (pHead == NULL)
	{
		return;
	}
	//2��ֻ��һ���ڵ�
	else if (pHead->_next == NULL)
	{
		free(pHead);
		pHead = NULL;
	}
	//3������ڵ�
	else
	{
		ListNode* prev = NULL;
		ListNode* tail = pHead;
		while (tail->_next!=NULL)
		{
			prev = tail;
			tail = tail->_next;
		}
		prev->_next = NULL;
		free(tail);
	}
}

//-------------------ͷɾ---------------------//
void PopFront(ListNode*& pHead)
{
	if (pHead == NULL)
	{
		return;
	}
	else if (pHead->_next == NULL)
	{
		free(pHead);
		pHead = NULL;
	}
	else
	{
		ListNode* del = pHead;
		pHead = pHead->_next;
		free(del);
	}
}

//-------------------ɾ��---------------------//
void Erase(ListNode*& pHead,ListNode* pos)
{
	assert(pos);
	if (pos == pHead)
	{
		pHead = pHead->_next;
		free(pos);
	}
	else
	{
		ListNode* del = pHead;
		while (del)
		{
			if (del->_next == pos)
			{
				del->_next = pos->_next;
				free(pos);
				break;
			}
			del = del->_next;
		}
	}
}


//-------------------��ӡ---------------------//
void PrintList(ListNode*& pHead)
{
	ListNode* cur = pHead;
	while (cur!=NULL)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}
void Test()
{
	ListNode* list;
	InitList(&list);
	PushBack(&list, 4);
	PushBack(&list, 5);
	PushFront(&list, 1);
	ListNode* pos = Find(list, 1);
	Insert(pos, 2);
	PopBack(list);
	PopBack(list);
	PopFront(list);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, 5);
	PushFront(&list, 1);
	PrintList(list);
	/*pos = Find(list, 1);
	Erase(list, pos);*/
	PrintList(list);
}

