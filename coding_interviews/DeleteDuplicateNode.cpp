// 面试题18（二）：删除链表中重复的结点
// 题目：在一个排序的链表中，如何删除重复的结点？例如，在图3.4（a）中重复
// 结点被删除之后，链表如图3.4（b）所示。

#include <cstdio>
#include "..\utilities\list.h"

void DeleteDuplication(ListNode** pHead)
{
	if(pHead==nullptr || *pHead==nullptr)
		return;

	ListNode* pPreNode = nullptr;
	ListNode* pNode = *pHead;
	while(pNode != nullptr)
	{
		ListNode* pNext = pNode->m_pNext;
		bool needDelete = false;
		if(pNext!=nullptr && pNext->m_nValue==pNode->m_nValue)
			needDelete = true;

		// 如果不需要删除，即不是重复节点
		if (!needDelete)
		{
			pPreNode = pNode;
			pNode = pNode->m_pNext;
		}
		else
		{
			int value = pNode->m_nValue;
			ListNode* pToBeDel = pNode;
			while(pToBeDel!=nullptr && pToBeDel->m_nValue==value)
			{
				pNext = pToBeDel->m_pNext;

				delete pToBeDel;
				pToBeDel = nullptr;

				pToBeDel = pNext;
			}

			if(pPreNode == nullptr)
				*pHead = pNext;
			else
				pPreNode->m_pNext = pNext;
		}
	}
}