// 面试题22：链表中倒数第k个结点
// 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
// 本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表有6个结点，
// 从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是
// 值为4的结点。

#include <cstdio>
#include "..\Utilities\List.h"

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	// 首先检查输入的pListNode为空指针。由于代码会试图访问空指针指向的内存，从而造成程序崩溃。
	// 其次检查输入的参数k为0.
	// 由于k是一个无符号整数，那么for循环中k-1得到的将不是-1，而是4294967295（0xffffffff）。
	// 因此，for循环执行的次数远远超过我们的预计，同样也会造成程序崩溃。
	if(pListHead == nullptr || k == 0)
		return nullptr;

	ListNode* pAhead = pListHead;
	ListNode* pBehind = nullptr;

	for (unsigned int i = 0; i < k - 1; ++i)
	{
		// 最后要注意输入的以pListHead为头节点的链表的节点总少于k。
		// 由于for循环执行的次数远远超出我们的预计，同样也会造成程序崩溃。
		if(pAhead->m_pNext != nullptr)
			pAhead = pAhead->m_pNext;
		else
		{
			return nullptr;
		}
	}

	pBehind = pListHead;
	while(pAhead->m_pNext != nullptr)
	{
		pAhead = pAhead->m_pNext;
		pBehind = pBehind->m_pNext;
	}


	return pBehind;
}