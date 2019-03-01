// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。

#include <iostream>
#include <cmath>

bool g_InvalidInput = false;
bool equal(double num1, double num2)
{
	// 由于精度原因，不能用等号判断两个小数是否相等
	if((num1-num2>-0.0000001) && (num1-num2<0.0000001))
		return true;
	else
		return false;
}
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	/*
	double result = 1.0;
	for (int i = 1; i <= exponent; ++i)
	{
		result *= base;
	}
	*/

	if(exponent == 0)
		return 1;
	if(exponent == 1)
		return base;
	
	// 利用公示
	// 利用右移 >> 代替 /
	double result = PowerWithUnsignedExponent(base, exponent>>1);
	result *= result;

	// 用位与运算符代替求余运算符（%）
	if ((exponent & 0x1) == 1)
		result *= base;

	return result;
}

double Power(double base, int exponent)
{
	g_InvalidInput = false;

	// 函数在两种情况下会返回0：
	// 一种是base=0，指数是负数，对0求倒数是非法的，返回0且全局变量g_InvalidInput= true;
	// 一种是0的0次方没有意义，但需要考虑，返回值是0
	// 这种方法的缺点是：
	// 当直接调用Power函数时，返回值是0.0时无法判断属于上述那种情况。
	if(equal(base, 0.0) && exponent<0)
	{
		g_InvalidInput = true;
		return 0.0;
	}

	// 当指数是负数的时候，就需要求倒数
	unsigned int absExponent = (unsigned int) exponent;
	// 不能直接修改exponent的值
	if (exponent < 0)
		absExponent = (unsigned int) (-exponent);

	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
		result = 1.0 / result;

	return result;
}