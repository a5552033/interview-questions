// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。

#include<cstdio>
#include<cstring>

using namespace std;

void ReplaceBalnk(char str[], int length)
{
	if (str==nullptr && length<=0)
		return;

	/*originalLength 为字符串str的实际长度*/
	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while(str[i] != '\0')
	{
		originalLength++;

		if (str[i] == ' ')
		{
			numberOfBlank++;
		}

		i++;
	}

	/*newLength 为把空格替换成'%20'之后的长度*/
	int newLength = originalLength + 2 * numberOfBlank;
	// 题目中说明字符串后面有足够的空余内存
	if(newLength > length)
		return;

	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	while(indexOfOriginal>=0 && indexOfNew>indexOfOriginal)
	{
		if(str[indexOfOriginal] == ' ')
		{
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
		}
		else
		{
			str[indexOfNew--] = str[indexOfOriginal];
		}

		indexOfOriginal--;
	}
}