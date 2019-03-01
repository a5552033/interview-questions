// 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。

#include <math>
#include <iostream>

// ====================动态规划====================
// 从下至上求解问题

int maxProductAfterCutting_solution1(int length)
{
	if(length<2)
		return 0;
	if(length == 2)
		return 1;
	if(length == 3)
		return 2;

	int* products = new int[length+1];
	// 此处赋值没有错误。因为f(5)=2*3而不是等于2*1，仔细想一下。
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max = 0;
	for (int i = 4; i <=length; ++i)
	{
		max = 0;
		for (int j = 1; j <= i/2; ++j)
		{
			int product = products[j] * products[i-j];
			if(max < product)
				max = product;

			product[i] = max;
		}
	}

	max = products[length];
	delete[] products;

	return max;
}

// ====================贪婪算法====================
int maxProductAfterCutting_solution2(int length)
{
	if(length<2)
		return 0;
	if(length == 2)
		return 1;
	if(length == 3)
		return 2;

	// 尽可能多地剪去长度为3的绳子段
	int timeOf3 = length / 3;

	//当绳子最后剩下的长度为4的时候，不能再剪去长度为3的绳子段。
	//此时更好的方法是把绳子剪成长度为2的两段，因为2*2 > 1*3。
	if (length - timeOf3*3 == 1)
	{
		timeOf3 -= 1;
	}

	int timeOf2 = (length-timeOf3*3) / 2;

	return (int)(pow(3, timeOf3) * (int) pow(2, timeOf2));
}
