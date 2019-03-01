// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？例如，在图3.8的链表中，
// 环的入口结点是结点3。

#include <cstdio>
#include "..\Utilities\list.h"

ListNode* MeetingNode(ListNode* pListHead)
{
	if(pListHead == nullptr)
		return nullptr;

	// 链表中如果存在环，链表中至少有两个节点
	ListNode* pSlow = pListHead->m_pNext;
	if(pSlow == nullptr)
		return nullptr;

	ListNode* pFast = pListHead->m_pNext;
	while(pSlow != nullptr && pFast != nullptr)
	{
		if (pFast == pSlow)
		{
			return pFast;
		}

		pSlow = pSlow->m_pNext;

		pFast = pFast->m_pNext;
		if(pFast != nullptr)
			pFast = pFast->m_pNext;
	}

	return nullptr;
}

ListNode* EntryNodeOfLoop(*ListNode pListHead)
{
	ListNode* meetingNode = MeetingNode(pListHead);
	if(meetingNode == nullptr)
		return nullptr;

	// 得到链表中环的节点数
	int nodesNumberInloop = 1;
	ListNode* pNode1 = meetingNode;
	while(pNode1->m_pNext != meetingNode)
	{
		nodesNumberInloop++;
		pNode1 = pNode1->m_pNext;
	}

	// 先移动pNode1，次数为环中节点数
	pNode1 = pListHead;
	for (int i = 0; i < nodesNumberInloop; ++i)
	{
		pNode1 = pNode1->m_pNext;
	}

	// 再移动节点pNode1和pNode2
	ListNode* pNode2 = pListHead;
	while(pNode1 != pNode2)
	{
		pNode1 = pNode1->m_pNext;
		pNode2 = pNode2->m_pNext;
	}

	return pNode2;
}