// 面试题1:赋值运算符函数
// 题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数
// 总结：
//     1、写完一个代码后，要有测试样例；
//     2、

#include<cstring>
#include<cstdio>

class CMyString
{
public:
	CMyString(char* pData = nullptr); //复制构造函数
	CMyString(const CMyString& str);
	~CMyString(void); // 析构函数

	CMyString& operator = (const CMyString& str); //赋值运算符函数

	void Print();

private:
	char* m_pData;
};

CMyString::CMyString(char *pData) //双冒号表示该函数是类CMyString的一个成员函数
{
	if(pData == nullptr)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString& str)
{
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
	delete[] m_pData; // 负载机系统资源的释放需要依靠实例的析构函数
}

CMyString& CMyString::operator = (const CMyString& str)
{
	// 判断传入的参数和当前的实例是不是同一个实例。
	if (this != &str)
	{
		CMyString strTemp(str);

		char* pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}

	return *this;
}

// ====================测试代码====================
void CMyString::Print()
{
	printf("%s", m_pData);
}

void Test1()
{
	printf("%s\n", "Test1 begins:");

	char* text = "Hello World!";

	CMyString str1(text);
	CMyString str2;
	str2 = str1;

	printf("The expected result is:%s.\n", text);

	printf("The actual result is:");
	str2.Print();
	printf(".\n");
}

// 赋值给自己
void Test2()
{
	printf("Test2 begins:\n");

	char* text = "Hello World!";

	CMyString str1(text);
	str1 = str1;

	printf("The expected result is:%s.\n", text);

	printf("The actual result is:.");
	str1.Print();
	printf(".\n");
}

// 连续赋值
void Test3()
{
	printf("Test2 begins:\n");

	char* text = "Hello World!";

	CMyString str1(text);
	CMyString str2;
	CMyString str2;
	str3 = str2 = str1;

	printf("The expected result is:%s.\n", text);

	printf("The actual str2 result is:");
	str2.Print();
	printf(".\n");

	printf("The actual str3 result is:");
	str3.Print();
	printf(".\n");
}

int main()
{
	Test1();
	Test2();
	Test3();

	return 0;
}