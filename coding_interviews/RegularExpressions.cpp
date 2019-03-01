// 面试题19：正则表达式匹配
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
// 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
// 中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
// 和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。

#include <cstdio>

bool matchCore(const char* str, const char* pattern);

bool match(const char* str, const char* pattern)
{
	if(str==nullptr || pattern==nullptr)
		return false;

	return matchCore(str, pattern);
}

bool matchCore(const char* str, const char* pattern)
{
	if(*str=='\0' && *pattern=='\0')
		return true;
	if(*str!='\0' && *pattern=='\0')
		return false;

	// 模式的第二个字符是*
	if (*(pattern+1) == '*')
	{
		if (*pattern == *str || (*pattern == '.' && *str != '\0'))
			// 进入有限状态机的下一个状态
			return matchCore(str+1, pattern+2)
			// 继续留在有限状态机的当前状态
			|| matchCore(str+1, pattern)
			// 略过一个“*”
			|| matchCore(str, pattern+2);
		else
			return matchCore(str, pattern+2);
	}

	if (*pattern == *str || (*pattern == '.' && *str != '\0'))
	{
		return matchCore(str+1, pattern+1);
	}

	return false;
}