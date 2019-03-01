// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。

#include <cstdio>
#include "..\Utilities\list.h"

ListNode* ReverseList(ListNode* pHead)
{
	if(pHead == nullptr)
		return nullptr;

	ListNode* pNode = pHead;
	ListNode* pReverseHead = nullptr;
	ListNode* pPrev = nullptr;
	while(pNode != nullptr)
	{
		ListNode* pNext = pNode->m_pNext;

		if(pNext == nullptr)
			pReverseHead = pNode;

		pNode->m_pNext = pPrev;

		pPrev = pNode;
		pNode = pNext;
	}

	return pReverseHead;
}