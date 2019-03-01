// 面试题26：树的子结构
// 题目：输入两棵二叉树A和B，判断B是不是A的子结构。

#include <cstdio>

struct BinaryTreeNode{
	double m_dbValue;
	BinaryTreeNode* mpLeft;
	BinaryTreeNode* mpRight;
};

bool DoseTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);
bool Equal(double num1, double num2);

bool HasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	bool isHave = false;

	if (pRoot1 != nullptr && pRoot2 != nullptr)
	 {
	 	if(Equal(pRoot1->m_dbValue, pRoot2->m_dbValue))
	 		isHave = DoseTree1HaveTree2(pRoot1, pRoot2);
	 
		if(!isHave)
		{
			isHave = HasSubtree(pRoot1->mpLeft, pRoot2);
		}
		if(!isHave)
			isHave = HasSubtree(pRoot1->mpRight, pRoot2);
	}

	return isHave;
}

bool DoseTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	if(pRoot2 == nullptr)
		return true;
	if(pRoot1 == nullptr)
		return false;

	if(!Equal(pRoot1->m_dbValue, pRoot2->m_dbValue))
		return false;

	return DoseTree1HaveTree2(pRoot1->mpLeft, pRoot2->mpLeft) &&
		DoseTree1HaveTree2(pRoot1->mpRight, pRoot2->mpRight);
}

bool Equal(double num1, double num2)
{
	if(abs(num1-numb2)<0.0000001)
		return true;
	else
		return false;
}
