//常见面试题

//1、逆序打印（从尾到头打印）单链表---------递归思想
void PrintTailToHead(ListNode* pHead)
{
	if (pHead != NULL)
	{
		PrintTailToHead(pHead->_next);
		printf("%d->", pHead->_data);

	}
}

void MeetingTest1()
{
	ListNode* list;
	InitList(&list);
	PushFront(&list, 4);
	PushFront(&list, 3);
	PushFront(&list, 2);
	PushFront(&list, 1);
	PrintList(list);
	PrintTailToHead(list);
}

//2、删除一个无头结点单链表的非尾节点
void DelNotTailNode(ListNode* pos)
{
	assert(pos);
	assert(pos->_next);
	ListNode* del = pos->_next;
	pos->_data = del->_data;
	pos->_next = del->_next;
	free(del);
}

void MeetingTest2()
{
	ListNode* list;
	InitList(&list);
	PushFront(&list, 4);
	PushFront(&list, 3);
	PushFront(&list, 2);
	PushFront(&list, 1);
	PrintList(list);
	ListNode* pos = Find(list,2);
	DelNotTailNode(pos);
	PrintList(list);

}

//3、无头单链表的非头结点处插入一节点
void InsertNotFront(ListNode* pos,DataType x)
{
	assert(pos && pos->_next);
	ListNode* tmp = BuyNode(x);
	tmp->_next = pos->_next;
	pos->_next = tmp;
	DataType mid = pos->_data;
	pos->_data = tmp->_data;
	tmp->_data = mid;
}

void MeetingTest3()
{
	ListNode* list;
	InitList(&list);
	PushFront(&list, 4);
	PushFront(&list, 3);
	PushFront(&list, 2);
	PushFront(&list, 1);
	PrintList(list);
	ListNode* pos = Find(list, 2);
	InsertNotFront(pos, 5);
	PrintList(list);
}

//4、反转单链表
ListNode* Reverse(ListNode*& pHead)
{
	ListNode* cur = pHead;
	ListNode* newHead = NULL;
	while (cur)
	{
		ListNode* tmp = cur;
		cur = cur->_next;
		tmp->_next = newHead;
		newHead = tmp;
	}
	pHead = newHead;
	return pHead;
}
void MeetingTest4()
{
	ListNode* list;
	InitList(&list);
	PushFront(&list, 4);
	PushFront(&list, 3);
	PushFront(&list, 2);
	PushFront(&list, 1);
	PrintList(list);
	Reverse(list);
	PrintList(list);

}
//5、查找单链表的中间节点，要求只能遍历一遍链表
ListNode* FindMidOfList(ListNode* pHead)
{
	ListNode* fast = pHead;
	ListNode* slow = pHead;
	while (fast && fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
	}
	printf("%d\n", slow->_data);
	return slow;
}
void MeetingTest5()
{
	ListNode* list;
	InitList(&list);
	PushFront(&list, 5);
	PushFront(&list, 4);
	PushFront(&list, 3);
	PushFront(&list, 2);
	PushFront(&list, 1);
	PrintList(list);
	FindMidOfList(list);
}
//6、单链表实现约瑟夫环
ListNode* JosephCycle(ListNode*pHead, int m)
{
	ListNode* cur = pHead;
	if (cur == NULL)
		return NULL;
	while (1)
	{
		if (cur == cur->_next)//只剩一个节点,即为最终节点
		{
			return cur;
		}
		int x = m;
		while (--x)
		{
			cur = cur->_next;
		}
		ListNode* del = cur->_next;
		cur->_data = del->_data;
		cur->_next = del->_next;
		free(del);
	}
}
void MeetingTest6()
{
	ListNode* list;
	InitList(&list);
	PushFront(&list, 5);
	PushFront(&list, 4);
	PushFront(&list, 3);
	PushFront(&list, 2);
	PushFront(&list, 1);
	PrintList(list);
	//建环
	ListNode* ret = Find(list, 5);
	ret->_next = list;
	ret = JosephCycle(list, 5);
	printf("最后剩余节点为：%d\n", ret->_data);
	//解环
	ret->_next = NULL;
	free(ret);
	
}

//7、单链表的排序（冒泡法）升序
void SortList(ListNode*& pHead)
{
	if (pHead==NULL || pHead->_next == NULL)
	{
		return;
	}
	ListNode* cur = pHead->_next;
	ListNode* prev = pHead;
	ListNode* tail = NULL;
	while (pHead != tail)
	{
		cur = pHead->_next;
		prev = pHead;
		int exchange = 0;
		while (cur != NULL)
		{
			if (prev->_data > cur->_data)
			{
				DataType tmp = prev->_data;
				prev->_data = cur->_data;
				cur->_data = tmp;
				exchange = 1;
			}
			cur = cur->_next;
			prev = prev->_next;
		}
		if (exchange == 0)
			return;
		tail = prev;
	}
}

void MeetingTest7()
{
	ListNode* list;
	InitList(&list);
	PushFront(&list, 5);
	PushFront(&list, 3);
	PushFront(&list, 1);
	PushFront(&list, 7);
	PushFront(&list, 4);
	PushFront(&list, 15);
	PushFront(&list, 0);
	PushFront(&list, 9);
	PushFront(&list, 2);
	PushFront(&list, 14);
	PrintList(list);
	SortList(list);
	PrintList(list);
}

//8、合并两个有序的单链表，合并后的链表依然有序(升序)
ListNode* MergeList(ListNode* pHead1, ListNode* pHead2)
{
	//1、其中一个链表为空
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;

	ListNode* newHead = NULL;
	ListNode* tail = NULL;
	ListNode* cur1 = pHead1;
	ListNode* cur2 = pHead2;
	//2、确定头结点
	if (cur1->_data < cur2->_data)
	{
		newHead = cur1;
		cur1 = cur1->_next;
	}
	else
	{
		newHead = cur2;
		cur2 = cur2->_next;
	}
	tail = newHead;

	//3、两链表均不为空
	while (cur1 && cur2)
	{
		if (cur1->_data < cur2->_data)
		{
			tail->_next = cur1;
			tail = tail->_next;
			cur1 = cur1->_next;
		}
		else
		{
			tail->_next = cur2;
			tail = tail->_next;
			cur2 = cur2->_next;
		}
	}
	//4、其中一个链表为空了
	if (cur1 != NULL)
	{
		tail->_next = cur1;
	}
	if (cur2 != NULL)
	{
		tail->_next = cur2;
	}
	return newHead;
}
void MeetingTest8()
{
	ListNode* list1;
	InitList(&list1);
	ListNode* list2;
	InitList(&list2);
	PushBack(&list1, 1);
	PushBack(&list1, 3);
	PushBack(&list1, 5);
	PushBack(&list1, 7);
	PushBack(&list1, 9);
	PushBack(&list2, 2);
	PushBack(&list2, 4);
	PushBack(&list2, 6);
	PushBack(&list2, 8);
	PushBack(&list2, 10);
	PrintList(list1);
	PrintList(list2);
	ListNode* list = MergeList(list1, list2);
	PrintList(list);
}

//9、查找单链表的倒数第k个结点，要求只遍历一遍链表
//思路：快慢指针，快指针始终与慢指针差k步，当快指针到结尾，则慢指针指向倒数第k个结点
ListNode* FindKTailNode(ListNode* pHead,int k)
{
	ListNode* fast = pHead;
	ListNode* slow = pHead;
	while (k--)//使快指针与慢指针相差k步
	{
		if (fast == NULL)//链表长度 < k
		{
			return NULL;
		}
		fast = fast->_next;
	}
	while (fast)
	{
		slow = slow->_next;
		fast = fast->_next;
	}
	printf("倒数第k个结点为：%d\n", slow->_data);
	return slow;
}

void MeetingTest9()
{
	ListNode* list;
	InitList(&list);
	PushFront(&list, 5);
	PushFront(&list, 3);
	PushFront(&list, 1);
	PushFront(&list, 7);
	PushFront(&list, 4);
	PushFront(&list, 15);
	PushFront(&list, 0);
	PushFront(&list, 9);
	PushFront(&list, 2);
	PushFront(&list, 14);
	PrintList(list);
	FindKTailNode(list, 5);
}

//10、判断链表是否带环，若带环，求环的长度及环的入口点
ListNode* HasCycle(ListNode* pHead)//判断是否带环
{
	ListNode* fast = pHead;
	ListNode* slow = pHead;
	while (fast&&fast->_next)
	{
		fast = fast->_next->_next;//快指针走两步
		slow = slow->_next;//慢指针走一步
		if (slow == fast)
		{
			printf("该链表带环。\n");
			return slow;
		}
	}
	printf("该链表不带环。\n");
	return NULL;
}

int GetCycleLength(ListNode* meetNode)//求环的长度
{
	ListNode* slow = meetNode->_next;
	ListNode* fast = meetNode->_next->_next;
	int count = 1;
	while (fast != slow)
	{
		fast = fast->_next->_next;
		slow = slow->_next;
		count++;
	}
	printf("该链表环的长度为：%d。\n",count);
	return count;
}

ListNode* GetEntryNode(ListNode* pHead, ListNode* meetNode)//获取入口点
{
	while (pHead && meetNode)
	{
		if (pHead == meetNode)
		{
			printf("链表环的入口点为：%d.\n", pHead->_data);
			return pHead;
		}
		pHead = pHead->_next;
		meetNode = meetNode->_next;
	}
	return NULL;
}

void MeetingTest10()
{
	ListNode* list;
	InitList(&list);
	PushFront(&list, 10);
	PushFront(&list, 9);
	PushFront(&list, 8);
	PushFront(&list, 7);
	PushFront(&list, 6);
	PushFront(&list, 5);
	PushFront(&list, 4);
	PushFront(&list, 3);
	PushFront(&list, 2);
	PushFront(&list, 1);
	PrintList(list);
	//建环
	ListNode* tail = Find(list, 10);
	ListNode* entry = Find(list, 6);//环的入口点
	tail->_next = entry;

	ListNode* meetNode = HasCycle(list);//是否带环，相遇点
	int length = GetCycleLength(list);
	ListNode* retEntry = GetEntryNode(list, meetNode);//求环的入口点
	//assert(retEntry == entry);//判断入口点是否正确

}

//11、判断两链表是否相交(不带环)，若相交，求交点
bool CheckCross(ListNode* pHead1, ListNode* pHead2)
{
	ListNode* cur1 = pHead1;
	ListNode* cur2 = pHead2;
	
	while (cur1->_next)
		cur1 = cur1->_next;
	while (cur2->_next)
		cur2 = cur2->_next;
	if (cur1 == cur2)
	{
		printf("两链表相交。\n");
		return true;
	}
	printf("两链表不相交。\n");
	return false;
}

//求交点，思路：求两链表长度差sub，让长的链表先走sub步，然后两链表一起走，当相遇则为交点
ListNode* GetCrossNode(ListNode* pHead1, ListNode* pHead2)
{
	ListNode* cur1 = pHead1;
	ListNode* cur2 = pHead2;
	ListNode* tail1 = pHead1;
	ListNode* tail2 = pHead2;
	int length1 = 0;
	int length2 = 0;
	while (tail1)
	{
		tail1 = tail1->_next;
		length1++;
	}
	while (tail2)
	{
		tail2 = tail2->_next;
		length2++;
	}
	if (length1 > length2)
	{
		int sub = length1 - length2;	
		while (cur1&&cur2)
		{
			while (sub-->0)
				cur1 = cur1->_next;

			cur1 = cur1->_next;
			cur2 = cur2->_next;

			if (cur1 == cur2)
				return cur1;
		}
		return NULL;
	}
	else //length1 < length2
	{
		int sub = length2 - length1;
		while (cur1&&cur2)
		{
			while (sub-->0)
				cur2 = cur2->_next;

			cur1 = cur1->_next;
			cur2 = cur2->_next;

			if (cur1 == cur2)
				return cur1;
		}	
	}
}
void MeetingTest11()
{
	ListNode* list1;
	InitList(&list1);
	ListNode* list2;
	InitList(&list2);
	PushBack(&list1, 1);
	PushBack(&list1, 3);
	PushBack(&list1, 5);
	PushBack(&list1, 7);
	PushBack(&list1, 9);
	PushBack(&list2, 2);
	PushBack(&list2, 4);

	/*ListNode* cross = Find(list1, 9);
	ListNode* tail = Find(list2, 4);
	tail->_next = cross;*/

	PrintList(list1);
	PrintList(list2);

	bool test=CheckCross(list1, list2);
	if (test == true)
	{
		ListNode* crossNode = GetCrossNode(list1, list2);
		printf("交点为：%d\n", crossNode->_data);
	}
}

//12、判断两链表是否相交(可能带环)，若相交，求交点
bool CheckCross_Cycle(ListNode* pHead1, ListNode* pHead2)
{
	ListNode* meetNode1 = HasCycle(pHead1);
	ListNode* meetNode2 = HasCycle(pHead2);
	//不带环情况
	if (meetNode1 == NULL && meetNode2 == NULL)
	{
		ListNode* cur1 = pHead1;
		ListNode* cur2 = pHead2;

		while (cur1->_next)
			cur1 = cur1->_next;
		while (cur2->_next)
			cur2 = cur2->_next;

		if (cur1 == cur2)
		{
			printf("两链表相交。\n");
			return true;
		}
		else
		{
			printf("两链表不相交。\n");
			return false;
		}
		
	}
	//带环的情况（若带环，则两链表均带环）
	if (meetNode1 && meetNode2)
	{
		if (meetNode1 == meetNode2)
		{
			printf("两链表相交。\n");
			return true;
		}
		ListNode* cur = meetNode1->_next;
		while (cur != meetNode1)
		{
			if (cur == meetNode2)
			{
				printf("两链表相交。\n");
				return true;
			}
			cur = cur->_next;
		}
		printf("两链表不相交。\n");
		return false;
	}
	
}
void MeetingTest12()
{
	ListNode* list1;
	InitList(&list1);
	ListNode* list2;
	InitList(&list2);
	PushBack(&list1, 1);
	PushBack(&list1, 3);
	PushBack(&list1, 5);
	PushBack(&list1, 7);
	PushBack(&list1, 9);
	//建环
	ListNode* tail1 = Find(list1, 9);
	ListNode* entry = Find(list1, 5);//环的入口点
	tail1->_next = entry;

	PushBack(&list2, 2);
	PushBack(&list2, 4);
	ListNode* cross = Find(list1, 3);
	ListNode* tail2 = Find(list2, 4);
	tail2->_next = cross;	

	/*PrintList(list1);
	PrintList(list2);*/

	CheckCross_Cycle(list1, list2);

}