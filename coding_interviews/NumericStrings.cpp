// 面试题20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
// 字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
// “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是

#include <cstdio>

bool scanUnsignedInteger(const char** str);
bool scanInteger(const char** str);

// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，其中A和C都是
// 整数（可以有正负号，也可以没有），而B是一个无符号整数
bool isNumeric(const char* str)
{
	if(str == nullptr)
		return false;

	// A
	bool numeric = scanInteger(&str);

	// 如果出现'.'，接下来是数字的小数部分B
	if (*str == '.')
	{
		++str;

		// 下面一行代码用||的原因：
		// 1. 小数可以没有整数部分，例如.123 = 0.123；
		// 2. 小数点后面可以没有数字，例如：233. = 233.0
		// 3. 当然小数点前面和后面都可以有数字，例如233.666
		numeric = scanUnsignedInteger(&str) || numeric;
	}

	// 因为整个过程中传递的参数都是字符串的首地址，所以首地址一直在变
	// 模拟一个扫描的过程 C
	if (*str == 'e' || *str == 'E')
	{
		++str;

		// 下面一行代码用&&的原因：
		// 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如：.e、e1;
		// 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如：12e、12e+5.4

		numeric = numeric && scanInteger(&str);
	}

	return numeric && *str == '\0';
}

bool scanUnsignedInteger(const char** str)
{
	const char* before = *str;
	while(**str != '\0' && **str >= '0' && **str <= '9')
		++(*str);

	return *str > before;
}

bool scanInteger(const char** str)
{
	if(**str == '+' || **str == '-')
		++(*str);
	return scanUnsignedInteger(str);
}


bool scanUnsignedInteger(const char** string)
{
    const char* before = *string;
    
    if(**string != '\0' && **string >= '0' && **string <= '9')
        ++(*string);
    
    return *string > before;
}

// bool scanInteger(const char** string)
// {
//     while(**string == '+' || **string == '-')
//         ++(*string);
    
//     return scanUnsignedInteger(string);
// }

// bool isNumeric(const char* string)
// {
//     if(string == nullptr)
//         return false;
    
//     bool numeric = scanInteger(&string);
    
//     if(*string == '.')
//     {
//         ++string;
        
//         numeric = scanUnsignedInteger(&string) || numeric;
//     }
    
//     if(*string == 'E' || *string == 'e')
//     {
//         ++string;
        
//         numeric = scanInteger(&string) && numeric;
//     }
    
//     return numeric && (*string=='\0');
// }

void Test(const char* testName, const char* str, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(isNumeric(str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}


int main(int argc, char* argv[])
{
    Test("Test1", "100", true);
    Test("Test2", "123.45e+6", true);
    Test("Test3", "+500", true);
    Test("Test4", "5e2", true);
    Test("Test5", "3.1416", true);
    Test("Test6", "600.", true);
    Test("Test7", "-.123", true);
    Test("Test8", "-1E-16", true);
    Test("Test9", "1.79769313486232E+308", true);

    printf("\n\n");

    Test("Test10", "12e", false);
    Test("Test11", "1a3.14", false);
    Test("Test12", "1+23", false);
    Test("Test13", "1.2.3", false);
    Test("Test14", "+-5", false);
    Test("Test15", "12e+5.4", false);
    Test("Test16", ".", false);
    Test("Test17", ".e1", false);
    Test("Test18", "e1", false);
    Test("Test19", "+.", false);
    Test("Test20", "", false);
    Test("Test21", nullptr, false);

    return 0;
}