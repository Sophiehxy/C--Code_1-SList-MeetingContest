#pragma once
#include<malloc.h>
#include<cassert>

typedef int DataType;
typedef struct ListNode
{
	DataType _data;
	struct ListNode* _next;
}ListNode;

void InitList(ListNode** pHead)//传pHead的地址，所以用二级指针
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

//-------------------尾插---------------------//
void PushBack(ListNode** pHead,DataType x)
{
	//1、链表为空
	if (*pHead == NULL)
	{
		*pHead = BuyNode(x);
	}
	//2、链表不为空
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

//-------------------头插---------------------//
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

//-------------------查找位置---------------------//
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
//-------------------插入---------------------//
void Insert(ListNode* pos, DataType x)
{
	assert(pos);
	//法一：
	/*ListNode* tmp = BuyNode(x);
	tmp->_next = pos->_next;
	pos->_next = tmp;*/
	//法二:(最好避免pos->_next->_next的情况)
	/*ListNode* next = pos->_next;
	pos->_next = BuyNode(x);
	pos->_next->_next = next;*/
	//法三：
	ListNode* next = pos->_next;
	ListNode* tmp = BuyNode(x);
	tmp->_next = next;
	pos->_next = tmp;
}

//-------------------尾删---------------------//
void PopBack(ListNode*& pHead)
{
	//1、链表为空
	if (pHead == NULL)
	{
		return;
	}
	//2、只有一个节点
	else if (pHead->_next == NULL)
	{
		free(pHead);
		pHead = NULL;
	}
	//3、多个节点
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

//-------------------头删---------------------//
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

//-------------------删除---------------------//
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


//-------------------打印---------------------//
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

