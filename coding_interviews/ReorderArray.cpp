// 面试题21：调整数组顺序使奇数位于偶数前面
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。

#include <cstdio>
#include <vector>

using namespace std;

// void Reorder(int *pData, unsigned int length, bool (*func)(int));
// bool isEven(int n);

// ====================方法一====================
// void ReorderOddEven_1(int *pData, unsigned int length length)
// {
// 	if(pData == nullptr || length == 0)
// 		return;

// 	int *pBegin = pData;
// 	int *pEnd = pData + length - 1;

// 	while(pBegin < pEnd)
// 	{
// 		// 向后移动pBegin
// 		while(pBegin < pEnd && (*pBegin & 0x1) != 0)
// 			pBegin++;

// 		// 向前移动pEnd
// 		while(pBegin < pEnd && (*pEnd & 0x1) == 0)
// 			pEnd--;

// 		if (pBegin < pEnd)
// 		{
// 			int temp = *pBegin;
// 			*pBegin = *pEnd;
// 			*pEnd = temp;
// 		}
// 	}
// }

int main()
{
	vector<int> array = {1, 2, 3, 4, 5, 6, 7};

    int length = array.size();
    // printf("length: %d\n", length);
        
    if(length <= 0)
        return 0;
    
    int odd = 0;
    int even = 0;
    for(int i = 0; i < length; ++i)
    {
        if((array[i] & 0x1) == 0)
            ++even;
        else
            ++odd;
    }

    // printf("even,odd: %d %d\n", even,odd);
    
    int* pBegin = array.data();
    int* pEnd = array.data() + length - 1;
    int count = 0;
    while(pBegin <= pEnd && count < even)
    {
    	//printf("%d\n", *pBegin);
        if((*pBegin & 0x1) == 0)
        {
        	count++;
        	
        	int tempNumber = *pBegin;
        	// printf("%d\n", tempNumber);
        	int* pTemp = pBegin;
        	int* pMove = pTemp + 1;
        	// printf("%d\n", *pMove);
        	while(pMove <= pEnd)
        	{
        		
        		*pTemp = *pMove;
        		// printf("%d %d\n", count, *pMove);
        		pMove++;
        		pTemp++;
        		//printf("%d\n", pEnd);
        	}
        	// printf("%d\n", tempNumber);
        	// array[length-1] = tempNumber;
        	*pTemp = tempNumber;
        	// printf("%d\n", array[length-1]);
        }
        else
        	pBegin++;

        // for(int i = 0; i < length; ++i)
        // 	printf("%d\t", array[i]);
        // printf("\n");
    }

    for(int i = 0; i < length; ++i)
        printf("%d\t", array[i]);    

    return 0;
}
