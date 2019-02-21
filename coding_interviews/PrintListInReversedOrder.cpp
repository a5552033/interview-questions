// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。

#include<stdio>
#include<stdlib>
#include<stack>
#include"..\Utilities\List.h"

using namesapce std;

void PrintListReversingly_Iteratively(ListNode* pHead)
{
	std::stack<ListNode*> nodes;
	ListNode* pNode = pHead;
	while(pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while(!node.empty)
	{
		pNode = nodes.top();
		printf("%d\t", pNode->m_nValue);
		nodes.pop();
	}
}

void PrintListReversingly_Recursively(ListNode* pHead)
{
	if(pHead != nullptr)
	{
		if (pHead->m_pNext != nullptr)
		{
			PrintListReversingly_Recursively(pHead->m_pNext);
		}
		printf("%d\t", pHead->m_nValue);
	}
}