//����������

//1�������ӡ����β��ͷ��ӡ��������---------�ݹ�˼��
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

//2��ɾ��һ����ͷ��㵥����ķ�β�ڵ�
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

//3����ͷ������ķ�ͷ��㴦����һ�ڵ�
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

//4����ת������
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
//5�����ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������
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
//6��������ʵ��Լɪ��
ListNode* JosephCycle(ListNode*pHead, int m)
{
	ListNode* cur = pHead;
	if (cur == NULL)
		return NULL;
	while (1)
	{
		if (cur == cur->_next)//ֻʣһ���ڵ�,��Ϊ���սڵ�
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
	//����
	ListNode* ret = Find(list, 5);
	ret->_next = list;
	ret = JosephCycle(list, 5);
	printf("���ʣ��ڵ�Ϊ��%d\n", ret->_data);
	//�⻷
	ret->_next = NULL;
	free(ret);
	
}

//7�������������ð�ݷ�������
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

//8���ϲ���������ĵ������ϲ����������Ȼ����(����)
ListNode* MergeList(ListNode* pHead1, ListNode* pHead2)
{
	//1������һ������Ϊ��
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;

	ListNode* newHead = NULL;
	ListNode* tail = NULL;
	ListNode* cur1 = pHead1;
	ListNode* cur2 = pHead2;
	//2��ȷ��ͷ���
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

	//3�����������Ϊ��
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
	//4������һ������Ϊ����
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

//9�����ҵ�����ĵ�����k����㣬Ҫ��ֻ����һ������
//˼·������ָ�룬��ָ��ʼ������ָ���k��������ָ�뵽��β������ָ��ָ������k�����
ListNode* FindKTailNode(ListNode* pHead,int k)
{
	ListNode* fast = pHead;
	ListNode* slow = pHead;
	while (k--)//ʹ��ָ������ָ�����k��
	{
		if (fast == NULL)//������ < k
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
	printf("������k�����Ϊ��%d\n", slow->_data);
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

//10���ж������Ƿ���������������󻷵ĳ��ȼ�������ڵ�
ListNode* HasCycle(ListNode* pHead)//�ж��Ƿ����
{
	ListNode* fast = pHead;
	ListNode* slow = pHead;
	while (fast&&fast->_next)
	{
		fast = fast->_next->_next;//��ָ��������
		slow = slow->_next;//��ָ����һ��
		if (slow == fast)
		{
			printf("�����������\n");
			return slow;
		}
	}
	printf("������������\n");
	return NULL;
}

int GetCycleLength(ListNode* meetNode)//�󻷵ĳ���
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
	printf("�������ĳ���Ϊ��%d��\n",count);
	return count;
}

ListNode* GetEntryNode(ListNode* pHead, ListNode* meetNode)//��ȡ��ڵ�
{
	while (pHead && meetNode)
	{
		if (pHead == meetNode)
		{
			printf("��������ڵ�Ϊ��%d.\n", pHead->_data);
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
	//����
	ListNode* tail = Find(list, 10);
	ListNode* entry = Find(list, 6);//������ڵ�
	tail->_next = entry;

	ListNode* meetNode = HasCycle(list);//�Ƿ������������
	int length = GetCycleLength(list);
	ListNode* retEntry = GetEntryNode(list, meetNode);//�󻷵���ڵ�
	//assert(retEntry == entry);//�ж���ڵ��Ƿ���ȷ

}

//11���ж��������Ƿ��ཻ(������)�����ཻ���󽻵�
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
		printf("�������ཻ��\n");
		return true;
	}
	printf("�������ཻ��\n");
	return false;
}

//�󽻵㣬˼·�����������Ȳ�sub���ó�����������sub����Ȼ��������һ���ߣ���������Ϊ����
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
		printf("����Ϊ��%d\n", crossNode->_data);
	}
}

//12���ж��������Ƿ��ཻ(���ܴ���)�����ཻ���󽻵�
bool CheckCross_Cycle(ListNode* pHead1, ListNode* pHead2)
{
	ListNode* meetNode1 = HasCycle(pHead1);
	ListNode* meetNode2 = HasCycle(pHead2);
	//���������
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
			printf("�������ཻ��\n");
			return true;
		}
		else
		{
			printf("�������ཻ��\n");
			return false;
		}
		
	}
	//����������������������������������
	if (meetNode1 && meetNode2)
	{
		if (meetNode1 == meetNode2)
		{
			printf("�������ཻ��\n");
			return true;
		}
		ListNode* cur = meetNode1->_next;
		while (cur != meetNode1)
		{
			if (cur == meetNode2)
			{
				printf("�������ཻ��\n");
				return true;
			}
			cur = cur->_next;
		}
		printf("�������ཻ��\n");
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
	//����
	ListNode* tail1 = Find(list1, 9);
	ListNode* entry = Find(list1, 5);//������ڵ�
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