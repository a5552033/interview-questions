// 面试题10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。


#include <stdio>

using namespace std;

// ====================方法1：递归====================
long long Fibonacci_Solution1(unsigned int n)
{
	if(n <= 0)
		return 0;

	if(n == 1)
		return 1;

	return Fibonacci_Solution1(n-1) + Fibonacci_Solution1(n-2);
}

// ====================方法2：循环====================
long long Fibonacci_Solution2(unsigned n)
{
	int result[2] = {0, 1};
	if (n < 2)
	{
		return result[n];
	}

	long long fibNMinusOne = 1;
	long long fibNMinustwo = 0;
	long long fibN = 0;
	for (int i = 2; i <= n; ++i)
	{
		fibN = fibNMinusOne + fibNMinustwo;

		fibNMinustwo = fibNMinusOne;
		fibNMinusOne = fibN;
	}

	return fibN;
}