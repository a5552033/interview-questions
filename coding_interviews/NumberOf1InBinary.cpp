// 面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。

#include <cstdio>

int numberOf1_Solution1(int number)
{
	int count = 0;
	unsigned int flag = 1;

	//当flag的值大于无符号整数最大的值，则变成负数，此时退出循环。
	while(flag)
	{
		if(number & flag)
			count++;

		flag = flag << 1;
	}

	return count;
}