// 面试题25：合并两个排序的链表
// 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按
// 照递增排序的。例如输入图3.11中的链表1和链表2，则合并之后的升序链表如链
// 表3所示。

#include <cstdio>
#include "..\Utilities\List.h"

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	// 每当代码试图访问空指针指向的内存时程序就会崩溃。
	// 在本体中一旦输入空的链表就会引入空指针。
	// 要对空链表单独处理
	if(pHead1 == nullptr)
		return pHead2;
	if(pHead2 == nullptr)
		return pHead1;

	ListNode* pMergeHead = nullptr;

	if (pHead1->m_nValue < pHead2->m_nValue)
	{
		pMergeHead = pHead1;
		pMergeHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
	}
	else
	{
		pMergeHead = pHead2;
		pMergeHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
	}

	return pMergeHead;
}

ListNode* noMerge(ListNode* pHead1, ListNode* pHead2)
{
	if(pHead1 == nullptr)
	{
        return pHead2;
    }
    if(pHead2 == nullptr)
    {
        return pHead1;
    }
    
    ListNode* mergeHead = nullptr;
    ListNode* current = nullptr;     
    while(pHead1!=nullptr && pHead2!=nullptr)
    {
        if(pHead1->val <= pHead2->val)
        {
            if(mergeHead == nullptr)
            {
               mergeHead = current = pHead1;
            }
            else
            {
               current->next = pHead1;
               current = current->next;
            }
            
            pHead1 = pHead1->next;
        }
        else
        {
            if(mergeHead == nullptr)
            {
               mergeHead = current = pHead2;
            }
            else
            {
               current->next = pHead2;
               current = current->next;
            }
            pHead2 = pHead2->next;
        }
    }
    if(list1 == nullptr)
    {
        current->next = pHead2;
    }
    else
    {
        current->next = pHead1;
    }
    
    return mergeHead;
}

