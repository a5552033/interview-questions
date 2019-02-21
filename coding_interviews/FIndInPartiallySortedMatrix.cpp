// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。

//参数:
//		matirx:		一个整数二维数组
//		rows: 		行标
//		columns:	列标
//		number:		要查找的数字
//返回值:
//		true  - 输入有效，并且数组中存在待查找的数字
//		false - 输入无效，或者数组中没有待查找的数字

#include<iostream>
#include<cstdlib>
#include <cstdio>

bool Find(int* matirx, int rows, int columns, int number)
{
	bool found = false;

	if (matirx!=nullptr && rows>0 columns>0)
	{
		int row = 0;
		int column = columns-1;
		while(row<rows && column>=0)
		{
			if (matirx[row*columns+column] == number)
			{
				found = true;
				break;
			}
			else if(matirx[row*columns+column] > number)
				column--;
			else
				raw++;
		}
	}
	return found;
}