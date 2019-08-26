#include "stdafx.h"
#include <iostream>
#include<cassert>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include<map>
#include <sstream>
#include <hash_map>
#include<unordered_map>
#include<time.h>
#include <cstdio>
#include<iomanip>//输出格式控制
#include "..\Utilities\BinaryTree.h"
#include "..\Utilities\List.h"

using namespace std;
using namespace stdext;


//剑指8 二叉树的下一个节点

struct SpecialBinaryTreeNode
{
	int                    m_nValue;
	SpecialBinaryTreeNode*        m_pLeft;
	SpecialBinaryTreeNode*        m_pRight;
	SpecialBinaryTreeNode*        m_pParent;
};

//如果 此节点有右子树，找到此右子树最左边的节点
//如果 此节点没有右子树，找到一个节点的父节点的左子树为此节点的节点，则此节点的父节点就是要找到节点
SpecialBinaryTreeNode* GetNext(SpecialBinaryTreeNode* pNode)
{
	if (pNode == nullptr)
		return nullptr;

	SpecialBinaryTreeNode* pNext = nullptr;
	if (pNode->m_pRight != nullptr)
	{
		SpecialBinaryTreeNode* pRight = pNode->m_pRight;
		while (pRight->m_pLeft != nullptr)
			pRight = pRight->m_pLeft;

		pNext = pRight;//返回此节点
	}
	
	else if (pNode->m_pParent != nullptr)
	{
		SpecialBinaryTreeNode* pCurrent = pNode;
		SpecialBinaryTreeNode* pParent = pNode->m_pParent;
		while (pParent != nullptr && pCurrent == pParent->m_pRight)//当前节点是父节点的右节点，继续向上找
		{
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}

		pNext = pParent;
	}

	return pNext;
}

// ==================== 辅助代码用来构建二叉树 ====================
SpecialBinaryTreeNode* CreateSpecialBinaryTreeNode(int value)
{
	SpecialBinaryTreeNode* pNode = new SpecialBinaryTreeNode();
	pNode->m_nValue = value;
	pNode->m_pLeft = nullptr;
	pNode->m_pRight = nullptr;
	pNode->m_pParent = nullptr;

	return pNode;
}

void ConnectTreeNodes(SpecialBinaryTreeNode* pParent, SpecialBinaryTreeNode* pLeft, SpecialBinaryTreeNode* pRight)
{
	if (pParent != nullptr)
	{
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;

		if (pLeft != nullptr)
			pLeft->m_pParent = pParent;
		if (pRight != nullptr)
			pRight->m_pParent = pParent;
	}
}

void PrintTreeNode(SpecialBinaryTreeNode* pNode)
{
	if (pNode != nullptr)
	{
		printf("value of this node is: %d\n", pNode->m_nValue);

		if (pNode->m_pLeft != nullptr)
			printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
		else
			printf("left child is null.\n");

		if (pNode->m_pRight != nullptr)
			printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
		else
			printf("right child is null.\n");
	}
	else
	{
		printf("this node is null.\n");
	}

	printf("\n");
}

void PrintTree(SpecialBinaryTreeNode* pRoot)
{
	PrintTreeNode(pRoot);

	if (pRoot != nullptr)
	{
		if (pRoot->m_pLeft != nullptr)
			PrintTree(pRoot->m_pLeft);

		if (pRoot->m_pRight != nullptr)
			PrintTree(pRoot->m_pRight);
	}
}

void DestroyTree(SpecialBinaryTreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		SpecialBinaryTreeNode* pLeft = pRoot->m_pLeft;
		SpecialBinaryTreeNode* pRight = pRoot->m_pRight;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}

// ====================测试代码====================
void Test(char* testName, SpecialBinaryTreeNode* pNode, SpecialBinaryTreeNode* expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	SpecialBinaryTreeNode* pNext = GetNext(pNode);
	if (pNext == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

//            8
//        6      10
//       5 7    9  11
void Test1_7()
{
	SpecialBinaryTreeNode* pNode8 = CreateSpecialBinaryTreeNode(8);
	SpecialBinaryTreeNode* pNode6 = CreateSpecialBinaryTreeNode(6);
	SpecialBinaryTreeNode* pNode10 = CreateSpecialBinaryTreeNode(10);
	SpecialBinaryTreeNode* pNode5 = CreateSpecialBinaryTreeNode(5);
	SpecialBinaryTreeNode* pNode7 = CreateSpecialBinaryTreeNode(7);
	SpecialBinaryTreeNode* pNode9 = CreateSpecialBinaryTreeNode(9);
	SpecialBinaryTreeNode* pNode11 = CreateSpecialBinaryTreeNode(11);

	ConnectTreeNodes(pNode8, pNode6, pNode10);
	ConnectTreeNodes(pNode6, pNode5, pNode7);
	ConnectTreeNodes(pNode10, pNode9, pNode11);

	Test("Test1", pNode8, pNode9);
	Test("Test2", pNode6, pNode7);
	Test("Test3", pNode10, pNode11);
	Test("Test4", pNode5, pNode6);
	Test("Test5", pNode7, pNode8);
	Test("Test6", pNode9, pNode10);
	Test("Test7", pNode11, nullptr);

	DestroyTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test8_11()
{
	SpecialBinaryTreeNode* pNode5 = CreateSpecialBinaryTreeNode(5);
	SpecialBinaryTreeNode* pNode4 = CreateSpecialBinaryTreeNode(4);
	SpecialBinaryTreeNode* pNode3 = CreateSpecialBinaryTreeNode(3);
	SpecialBinaryTreeNode* pNode2 = CreateSpecialBinaryTreeNode(2);

	ConnectTreeNodes(pNode5, pNode4, nullptr);
	ConnectTreeNodes(pNode4, pNode3, nullptr);
	ConnectTreeNodes(pNode3, pNode2, nullptr);

	Test("Test8", pNode5, nullptr);
	Test("Test9", pNode4, pNode5);
	Test("Test10", pNode3, pNode4);
	Test("Test11", pNode2, pNode3);

	DestroyTree(pNode5);
}

//        2
//         3
//          4
//           5
void Test12_15()
{
	SpecialBinaryTreeNode* pNode2 = CreateSpecialBinaryTreeNode(2);
	SpecialBinaryTreeNode* pNode3 = CreateSpecialBinaryTreeNode(3);
	SpecialBinaryTreeNode* pNode4 = CreateSpecialBinaryTreeNode(4);
	SpecialBinaryTreeNode* pNode5 = CreateSpecialBinaryTreeNode(5);

	ConnectTreeNodes(pNode2, nullptr, pNode3);
	ConnectTreeNodes(pNode3, nullptr, pNode4);
	ConnectTreeNodes(pNode4, nullptr, pNode5);

	Test("Test12", pNode5, nullptr);
	Test("Test13", pNode4, pNode5);
	Test("Test14", pNode3, pNode4);
	Test("Test15", pNode2, pNode3);

	DestroyTree(pNode2);
}

void Test16()
{
	SpecialBinaryTreeNode* pNode5 = CreateSpecialBinaryTreeNode(5);

	Test("Test16", pNode5, nullptr);

	DestroyTree(pNode5);
}

//int main(int argc, char* argv[])
//{
//	Test1_7();
//	Test8_11();
//	Test12_15();
//	Test16();
//}


//剑指14 剪绳子

//动态规划

int maxProsuct1(int length){
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int* products = new int[length+1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;
	int max = 0;
	

	for (int i = 4; i <= length; ++i)
	{
		for (int j = 1; j <= i/2; ++j){
			int product=products[j] * products[i - j];
			if (product > max)
			{
				max = product;
			}
			products[i] = max;

		}
	}
	max = products[length];
	delete[] products;
	return max;

}

//贪婪算法
int maxProsuct2(int length)
{
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	//尽可能多的剪去长度为3的绳子段
	int timesOf3 = length / 3;
	//当绳子最后剩下的长度为4时，不能再减去长度为3的绳子段。
	//此时，剪成长度为2的绳子段 因为2x2>3x1
	if (length - timesOf3*3 == 1)
		timesOf3 -= 1;
	int timesOf2 = (length - timesOf3 * 3) / 2;

	return (int)(pow(3, timesOf3)*pow(2, timesOf2));

}



//int main(){
//	
//	for (int num = 0; num < 100; num++){
//		cout << maxProsuct1(num) << endl;
//		cout << maxProsuct1(num) << endl;
//	}
//}



//赛码网在线编程 --基础题
//int main(){
//	int n;
//	int sum = 1;
//	int flagplus = 1;
//	cin >> n;
//	int j = 0;
//	for (int i = 0; i<n-1; i++){
//
//		if (j<flagplus){
//			sum = sum + 1;
//			j++;
//		}
//		else if (j == flagplus)
//		{
//			j = 0;
//			sum = sum - 1;
//			flagplus++;
//
//		}
//
//	}
//	cout << sum << endl;
//	return 0;
//}

//int main(){
//	int length;//长度
//	cin >> length;
//	//int a[length];
//	vector<int>arr;
//	vector<int>flags;
//	bool flag = false;
//	int num;
//	int j = 0;
//	for (int i = 0; i<length; i++){//将输入读入数组
//		cin >> num;
//		arr.push_back(num);
//	}
//
//	for (int i = 0; i<length - 1; i++){
//		if (arr[i + 1]<arr[i]){ flag = true; flags.push_back(i); }
//		if (flag&&arr[i + 1]>arr[i] ){
//			if (arr[i + 1]<arr[flags[0]])flag = false;
//			else{
//				cout << "yes" << endl;
//				return 0;
//			}
//		}
//		if (arr[i + 1]<arr[i] && i + 1 == length - 1){
//			cout << "yes" << endl;
//			return 0;
//		}
//
//	}
//	cout << "no" << endl;
//	return 0;
//
//
//}



//int main(){
//	string str;
//	string trans;
//	string dest;
//	int num = 0;//记录相同字符串的个数
//	getline(cin, str);
//	getline(cin, dest);
//	trans = str;//必须加上这一句话  因为此时trans没有空间，如果没有此句，后面访问trans时会报错
//	double length = str.length();
//	double lengthdes = dest.length();
//	for (int i = 0; i<length; i++){
//		if ((str[i] - '0' >= 0 && str[i] - '0' <= 9) || (str[i] >= 'a'&&str[i] <= 'z') || (str[i] >= 'A'&&str[i] <= 'Z')){
//			trans[i] = '1';
//		}
//		else trans[i] = '0';
//	}
//	for (int i = 0; i<length; i++){
//		if (trans[i] == dest[i]) num++;
//	}
//
//	double result = num / lengthdes * 100;
//
//	cout << setprecision(2) << fixed << result << "%" << endl;
//}

//路灯
//int main(){
//	int num = 0;//灯的个数
//	double j = 0;
//	int length = 0;//路的长度
//	vector<double>led;//灯的位置
//	cin >> num;
//	cin >> length;
//	for (int i = 0; i<num; i++){
//		cin >> j;
//		led.push_back(j);
//	}
//
//	sort(led.begin(), led.end());
//	double maxLength = 0;
//	for (int i = 0; i<num - 1; i++){
//		double sub = led[i + 1] - led[i];
//		if (sub>maxLength)
//			maxLength = sub;
//	}
//	maxLength = maxLength / 2;
//	if (led[0] - 0>maxLength && led[0] - 0>length-led[num - 1] )
//		maxLength = led[0];
//	else if (length-led[num - 1] >maxLength && length-led[num - 1] >led[0] - 0)
//		maxLength = length-led[num - 1];
//
//	cout << setprecision(2) << fixed << maxLength << endl;
//}


//计算器的新功能
//char arr[5][1000];
//int pos = 0;
//
//void printMultiSign() {
//	if (pos != 0) {
//		arr[0][pos] = ' ';
//		arr[1][pos] = ' ';
//		arr[2][pos] = '*';
//		arr[3][pos] = ' ';
//		arr[4][pos++] = ' ';
//	}
//}
//
//void printNumToArray(int num) {
//	int tmp = 1;
//	while (num / tmp / 10 != 0) {
//		tmp *= 10;//得到最高位数
//	};
//	printMultiSign();
//
//	while (tmp != 0) {
//		int t = num / tmp % 10; //从前向后依次输出
//		tmp = tmp / 10;
//		switch (t) {
//		case 0:
//			arr[0][pos] = ' ';
//			arr[1][pos] = '|';
//			arr[2][pos] = ' ';
//			arr[3][pos] = '|';
//			arr[4][pos++] = ' ';
//
//			arr[0][pos] = '-';
//			arr[1][pos] = ' ';
//			arr[2][pos] = ' ';
//			arr[3][pos] = ' ';
//			arr[4][pos++] = '-';
//
//			arr[0][pos] = ' ';
//			arr[1][pos] = '|';
//			arr[2][pos] = ' ';
//			arr[3][pos] = '|';
//			arr[4][pos++] = ' ';
//			break;
//		case 1:
//			arr[0][pos] = ' ';
//			arr[1][pos] = ' ';
//			arr[2][pos] = ' ';
//			arr[3][pos] = ' ';
//			arr[4][pos++] = ' ';
//
//			arr[0][pos] = ' ';
//			arr[1][pos] = ' ';
//			arr[2][pos] = ' ';
//			arr[3][pos] = ' ';
//			arr[4][pos++] = ' ';
//
//			arr[0][pos] = ' ';
//			arr[1][pos] = '|';
//			arr[2][pos] = ' ';
//			arr[3][pos] = '|';
//			arr[4][pos++] = ' ';
//			break;
//		case 2:
//			arr[0][pos] = ' ';
//			arr[1][pos] = ' ';
//			arr[2][pos] = ' ';
//			arr[3][pos] = '|';
//			arr[4][pos++] = ' ';
//
//			arr[0][pos] = '-';
//			arr[1][pos] = ' ';
//			arr[2][pos] = '-';
//			arr[3][pos] = ' ';
//			arr[4][pos++] = '-';
//
//			arr[0][pos] = ' ';
//			arr[1][pos] = '|';
//			arr[2][pos] = ' ';
//			arr[3][pos] = ' ';
//			arr[4][pos++] = ' ';
//			break;
//		case 3:
//			arr[0][pos] = ' ';
//			arr[1][pos] = ' ';
//			arr[2][pos] = ' ';
//			arr[3][pos] = ' ';
//			arr[4][pos++] = ' ';
//
//			arr[0][pos] = '-';
//			arr[1][pos] = ' ';
//			arr[2][pos] = '-';
//			arr[3][pos] = ' ';
//			arr[4][pos++] = '-';
//
//			arr[0][pos] = ' ';
//			arr[1][pos] = '|';
//			arr[2][pos] = ' ';
//			arr[3][pos] = '|';
//			arr[4][pos++] = ' ';
//			break;
//		case 4:
//			arr[0][pos] = ' ';
//			arr[1][pos] = '|';
//			arr[2][pos] = ' ';
//			arr[3][pos] = ' ';
//			arr[4][pos++] = ' ';
//
//			arr[0][pos] = ' ';
//			arr[1][pos] = ' ';
//			arr[2][pos] = '-';
//			arr[3][pos] = ' ';
//			arr[4][pos++] = ' ';
//
//			arr[0][pos] = ' ';
//			arr[1][pos] = '|';
//			arr[2][pos] = ' ';
//			arr[3][pos] = '|';
//			arr[4][pos++] = ' ';
//			break;
//		case 5:
//			arr[0][pos] = ' ';
//			arr[1][pos] = '|';
//			arr[2][pos] = ' ';
//			arr[3][pos] = ' ';
//			arr[4][pos++] = ' ';
//
//			arr[0][pos] = '-';
//			arr[1][pos] = ' ';
//			arr[2][pos] = '-';
//			arr[3][pos] = ' ';
//			arr[4][pos++] = '-';
//
//			arr[0][pos] = ' ';
//			arr[1][pos] = ' ';
//			arr[2][pos] = ' ';
//			arr[3][pos] = '|';
//			arr[4][pos++] = ' ';
//			break;
//		case 6:
//			arr[0][pos] = ' ';
//			arr[1][pos] = '|';
//			arr[2][pos] = ' ';
//			arr[3][pos] = '|';
//			arr[4][pos++] = ' ';
//
//			arr[0][pos] = '-';
//			arr[1][pos] = ' ';
//			arr[2][pos] = '-';
//			arr[3][pos] = ' ';
//			arr[4][pos++] = '-';
//
//			arr[0][pos] = ' ';
//			arr[1][pos] = ' ';
//			arr[2][pos] = ' ';
//			arr[3][pos] = '|';
//			arr[4][pos++] = ' ';
//			break;
//		case 7:
//			arr[0][pos] = ' ';
//			arr[1][pos] = ' ';
//			arr[2][pos] = ' ';
//			arr[3][pos] = ' ';
//			arr[4][pos++] = ' ';
//
//			arr[0][pos] = '-';
//			arr[1][pos] = ' ';
//			arr[2][pos] = ' ';
//			arr[3][pos] = ' ';
//			arr[4][pos++] = ' ';
//
//			arr[0][pos] = ' ';
//			arr[1][pos] = '|';
//			arr[2][pos] = ' ';
//			arr[3][pos] = '|';
//			arr[4][pos++] = ' ';
//			break;
//		case 8:
//			arr[0][pos] = ' ';
//			arr[1][pos] = '|';
//			arr[2][pos] = ' ';
//			arr[3][pos] = '|';
//			arr[4][pos++] = ' ';
//
//			arr[0][pos] = '-';
//			arr[1][pos] = ' ';
//			arr[2][pos] = '-';
//			arr[3][pos] = ' ';
//			arr[4][pos++] = '-';
//
//			arr[0][pos] = ' ';
//			arr[1][pos] = '|';
//			arr[2][pos] = ' ';
//			arr[3][pos] = '|';
//			arr[4][pos++] = ' ';
//			break;
//		case 9:
//			arr[0][pos] = ' ';
//			arr[1][pos] = '|';
//			arr[2][pos] = ' ';
//			arr[3][pos] = ' ';
//			arr[4][pos++] = ' ';
//
//			arr[0][pos] = '-';
//			arr[1][pos] = ' ';
//			arr[2][pos] = '-';
//			arr[3][pos] = ' ';
//			arr[4][pos++] = '-';
//
//			arr[0][pos] = ' ';
//			arr[1][pos] = '|';
//			arr[2][pos] = ' ';
//			arr[3][pos] = '|';
//			arr[4][pos++] = ' ';
//			break;
//		}
//	}
//}
//
//void printArray() {
//	arr[0][pos] = '\0';
//	arr[1][pos] = '\0';
//	arr[2][pos] = '\0';
//	arr[3][pos] = '\0';
//	arr[4][pos] = '\0';
//	pos = 0;
//	cout << arr[0] << endl;
//	cout << arr[1] << endl;
//	cout << arr[2] << endl;
//	cout << arr[3] << endl;
//	cout << arr[4] << endl;
//}
//
//
//void generate(int num) {
//	for (int i = 2; i < num;) {
//		if (num % i == 0) {
//			printNumToArray(i);
//			num = num / i;
//			i = 2;
//		}
//		else {
//			++i;
//		}
//	}
//	printNumToArray(num);
//}
//
//int main()
//{
//	int num = 0;
//	while (scanf("%d", &num) != EOF) {
//		generate(num);
//		printArray();
//	}
//	return 0;
//}


//typedef long long LL;//一定要用long long类型 
//int main()
//
//{
//	int num = 0;
//	vector<int>arry;
//	cin >> num;
//	int a;
//	for (int i = 0; i < num; i++){
//		cin >> a;
//		arry.push_back(a);
//	}
//	int min = abs(arry[1]-arry[0]);
//	int weizhi = 0;
//	for (int i = 0; i < num - 1; i++){
//		if (abs(arry[i + 1] - arry[i]) < min){
//			min = abs(arry[i + 1] - arry[i]);
//			weizhi= i;
//		}
//	}
//	cout << arry[weizhi] << ' ' << arry[weizhi + 1] << endl;
//	return 0;
//}


//int main(){
//	vector<int>arry;
//	int num = 0;
//	int a;
//	cin >> num;
//	for (int i = 0; i < num; i++){
//		cin >> a;
//		arry.push_back(a);
//	}
	/*int max1 = 0;
	int max = 0;
	int jishu = 0;
	for (int i = 0; i < num-1 ; i++){
		
		
		for (int k = 0; k < num - i; k++){
			int base = arry[i];
			jishu = 0;
			for (int j = i + k; j < num; j++){

				if (arry[j] > base){
					jishu++;
					base = arry[j];
				}
			}
			if (jishu+1 > max1)
				max1 = jishu+1;
		}
		if (max1 > max)
			max = max1;
		
	}
	cout << max << endl;
	return 0;*/


	/*vector<int> dp;
	for (int i = 0; i < arry.size(); ++i) {
		int left = 0, right = dp.size();
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (dp[mid] < arry[i]) left = mid + 1;
			else right = mid;
		}
		if (right >= dp.size()) dp.push_back(arry[i]);
		else dp[right] = arry[i];
	}
	cout << dp.size();
	return 0;

}*/

//int main()
//{
//	int num;
//	vector<int>arry;
//	cin >> num;
//	int a;
//	int res = 0;
//	for (int i = 0; i<num; i++){
//		cin >> a;
//		arry.push_back(a);
//	}
//	vector<int>dp(num, 1);
//	for (int i = 0; i<num; i++){
//		for (int j = 0; j<i; j++){
//			if (arry[j]<arry[i]){
//				dp[i] = max(dp[i], dp[j] + 1);
//			}
//
//		}
//		res = max(res, dp[i]);
//	}
//	cout << res << endl;
//	return 0;
//
//}



//int main(){
//	int num = 0;
//	vector<int>arry;
//	int a;
//	cin >> num;
//	for (int i = 0; i < num; i++){
//		cin >> a;
//		arry.push_back(a);
//	}
//	int total = 0;
//	for (int i = 0; i < num-1; i++){
//		for (int j = i + 1; j < num; j++){
//			if ((arry[j]<arry[i] && arry[j] >= arry[i] * 0.9) || (arry[j]>arry[i]&&arry[i] >= arry[j]*0.9))
//			{
//				total++;
//			}
//		}
//	}
//	cout << total << endl;
//
//}

//int main(){
//	int length = 0;
//	vector<int>num;
//	int a;
//	cin >> length;
//	for (int i = 0; i < length; i++){
//		cin >> a;
//		num.push_back(a);
//	}
//
//
//}


class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr){
			return pHead1;
		}
		ListNode* index1 = pHead1;
		ListNode* index2 = pHead2;
		ListNode* newHead = nullptr;
		ListNode* index3 = nullptr;
		if (index1->m_nValue >= index2->m_nValue){
			index3 = index2;
			index2 = index2->m_pNext;
		}
		else{
			index3 = index1;
			index1 = index1->m_pNext;
		}
		
		newHead=index3;
		while (index1 != nullptr&&index2 != nullptr){
			if (index1->m_nValue >= index2->m_nValue){
				index3->m_pNext = index2;
				index2 = index2->m_pNext;
				index3 = index3->m_pNext;

			}
			else{
				index3->m_pNext = index1;
				index1 = index1->m_pNext;
				index3 = index3->m_pNext;
			}

		}
		if (index1 == nullptr){
			while (index2 != nullptr){
				index3->m_pNext = index2;
				index2 = index2->m_pNext;
				index3 = index3->m_pNext;
			}

		}
		if (index2 == nullptr){
			while (index1 != nullptr){
				index3->m_pNext = index1;
				index1 = index1->m_pNext;
				index3 = index3->m_pNext;
			}

		}
		return newHead;
	}
};


//int main(){
//	Solution test;
//	ListNode* newHead = nullptr;
//	ListNode* pNode1 = CreateListNode(1);
//	ListNode* pNode2 = CreateListNode(2);
//	ListNode* pNode3 = CreateListNode(3);
//	ListNode* pNode4 = CreateListNode(4);
//	ListNode* pNode5 = CreateListNode(5);
//
//	ConnectListNodes(pNode1, pNode2);
//	ConnectListNodes(pNode2, pNode3);
//	ConnectListNodes(pNode3, pNode4);
//	ConnectListNodes(pNode4, pNode5);
//	PrintList(pNode1);
//
//	ListNode* pNode6 = CreateListNode(6);
//	ListNode* pNode7 = CreateListNode(7);
//	ListNode* pNode8 = CreateListNode(8);
//	ListNode* pNode9 = CreateListNode(9);
//	ListNode* pNode10 = CreateListNode(10);
//
//	ConnectListNodes(pNode6, pNode7);
//	ConnectListNodes(pNode7, pNode8);
//	ConnectListNodes(pNode8, pNode9);
//	ConnectListNodes(pNode9, pNode10);
//
//	newHead=test.Merge(pNode1, pNode6);
//	PrintList(newHead);
//	
//	
//}











bool VerifySquenceOfBST(vector<int> sequence) {
	int length = sequence.size();
	int root = sequence[length - 1];
	vector<int>sequenceleft;
	
	vector<int>sequenceright;
	int i = 0;
	for (; i<length - 1; i++){
		if (sequence[i]>root)
			break;
		else
			sequenceleft.push_back(sequence[i]);
	}
	int j = i;
	for (; j<length - 1; j++){
		if (sequence[j]<root)
			return false;
		else
			sequenceright.push_back(sequence[j]);
	}

	bool left = true;
	if (i>0){
		left = VerifySquenceOfBST(sequenceleft);
	}
	bool right = true;
	if (j<length - 1){
		right = VerifySquenceOfBST(sequenceright);
	}
	return(left&&right);

}



////int main(){
//	vector<int>q = { 5,4,3,2,1 };
//	cout << VerifySquenceOfBST(q) << endl;
//
//}


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
}; 
class Solution3 {
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {

		vector<vector<int>>paths;
		FindPath(root, expectNumber, paths, 0);
		return paths;



	}
	vector<int>path;
	void FindPath(TreeNode* root, int expectNumber, vector<vector<int>>paths, int sum){

		if (root == nullptr)
			return;
		path.push_back(root->val);
		sum = root->val + sum;
		if (root->left == nullptr&&root->right == nullptr&&sum == expectNumber)
			paths.push_back(path);
		else{
			if (root->left != nullptr)
				FindPath(root->left, expectNumber, paths, sum);
			if (root->right != nullptr)
				FindPath(root->right, expectNumber, paths, sum);
		}
		path.pop_back();
	}

};

//int main()
//{
//	Solution3 test;
//	TreeNode* pRoot=new TreeNode(10);
//	pRoot->left=new TreeNode(5);
//	pRoot->right= new TreeNode(12);
//	pRoot->left->left = new TreeNode(4);
//	pRoot->left->right = new TreeNode(7);
//	vector <vector<int>>result;
//	result = test.FindPath(pRoot, 22);
//	cout << " ";
//
//	
//
//}

int FindGreatestSumOfSubArray(vector<int> array) {

	int length = array.size();
	vector<int>dp(length, 0);
	dp[0] = array[0];
	for (int i = 1; i<length; i++){
		if (dp[i - 1] + array[i]<array[i])
			dp[i] = array[i];

		else if (dp[i - 1] + array[i]>dp[i - 1])
			dp[i] = dp[i - 1] + array[i];
		else if (dp[i - 1] + array[i]>array[i])
			dp[i] = dp[i - 1] + array[i];

		
			
	}
	int max = dp[0];
	for (int i = 0; i<length; i++){
		if (dp[i]>max)
			max = dp[i];
	}
	return max;



}

//int main()
//{
//	vector<int>test = { -2, -8, -1, -5, -9 };
//	cout << FindGreatestSumOfSubArray(test) << endl;
//}

//int main(){
//	int num;
//	int result = 0;
//	vector<int>stone;
//	vector<int>help;
//	map<int, int>mapa;
//	cin >> num;
//	int a;
//	for (int i = 0; i < num; i++){
//		cin >> a;
//		stone.push_back(a);
//		help.push_back(a);
//		
//	}
//	
//	sort(help.begin(), help.end());
//	for (int i = 0, j = 0; i<num - 1, j<num - 1;){
//		if (help[j] != stone[i]){
//			result++;
//			i++;
//		}
//		else{
//			i++;
//			j++;
//		}
//		if (i == num || j == num)
//			break;
//
//	}
//
//	cout << result << endl;
//
//}

//int main()
//{
//	int length;
//	cin >> length;
//	string s;
//	cin >> s;
//
//	int res=0;
//	for (int i = 0; i < length - 1; i++){
//		if (s[i] == s[i + 1])
//			res++;
//	}
//
//	int res2 = 1;
//	char cur = s[0];
//	for (int i = 1; i < length; i++){
//		if (s[i] != cur){
//			res2++;
//			cur = s[i];
//		}
//	}
//	if (res >= 2)
//		cout << res2 + 2 << endl;
//	else if (res == 1)
//		cout << res2 + 1
//		<< endl;
//	else
//		cout << res2 << endl;
//}



class Solution821 {
public:
	vector<string> Permutation(string str) {

		vector<string>result;
		if (str.empty())
			return result;
		Permutation(str, result, 0);
		return result;


	}

	void Permutation(string str, vector<string>&res, int begin){
		if (begin == (str.size() - 1))
		{
			res.push_back(str);
		}

		for (int i = begin; i<=str.size() - 1; i++){
			swap(str[begin], str[i]);
			Permutation(str, res, begin + 1);
			swap(str[begin], str[i]);//再交换回来
		}

	}


	void swap(char &fir, char &sec)
	{
		char temp = fir;
		fir = sec;
		sec = temp;
	}
};
//int main(){
//	string str = "abcd";
//	cout << str.size();
//	cout << str.length();
//	Solution821 test;
//	test.Permutation(str);
//	cout << str << endl;
//}



//int MoreThanHalfNum_Solution(vector<int> numbers) {
//	int length = numbers.size();
//	map<int, int>help;
//	for (int i = 0; i<length; i++){
//		
//		help[numbers[i]]++;
//
//	}
//	for (int i = 0; i<length; i++)
//	{
//		if (help[numbers[i]] >= length / 2)
//			return numbers[i];
//	}
//	return 0;
//
//}


vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	vector<int>res;
	int length = input.size();
	if (k>length)
		return res;
	for (int i = 0; i<k; i++){
		res.push_back(input[i]);
	}
	make_heap(res.begin(), res.end());
	for (int i = k; i<length; i++){
		if (input[i]<res[0]){
			pop_heap(res.begin(), res.end());
			res.pop_back();

			res.push_back(input[i]);
			push_heap(res.begin(), res.end());
		}

	}
	return res;
}
//int main(){
//	vector<int>test = { 1, 2, 4, 0, 6 };
//	vector<int>res;
//	res = GetLeastNumbers_Solution(test, 3);
//	cout << " " << endl;
//	
//}


//int main(){
//	string str;
//	cin >> str;
//
//	vector<string>help;
//	int first = 0;
//	int sec = 0;
//	
//	while (sec != -1){
//		sec = str.find(",");
//		help.push_back(str.substr(first, sec));
//		str = str.substr(sec + 1, str.size());
//		
//	}
//	sort(help.begin(), help.end());
//	int length = help.size();
//	for (int i = 0; i < length; i++)
//		cout << help[i] << ",";
//
//}


//int main(){
//	int n = 0;
//	cin >> n;
//	vector<string>strs;
//	int i = 0;
//	while (i < n){
//		string str;
//		cin >> str;
//		strs.push_back(str);
//		i++;
//	}
//
//	int str1;
//	int str2;
//	cin >> str1 >> str2;
//
//	string string1 = strs[str1 - 1];
//	string string2 = strs[str2 - 1];
//	
//	int length1 = string1.size();
//	int length2 = string2.size();
//
//	int length = min(length1, length2);
//	int count = 0;
//
//	for (int i = 0; i < length;i++){
//		if (string1[i] == string2[i])
//			count++;
//		else
//			break;
//	}
//	cout<< count<<endl;
//	return 0;
//}

//int main()
//{
//	// 原始数组
//	int ary[4] = { 1, 2, 3, 4 };
//
//	// 打印数据
//	for (int i = 0; i < 4; i++)
//		std::cout << ary[i] << "\t";
//	std::cout << std::endl;
//
//	// 常量化数组指针
//	const int*c_ptr = ary;
//	//c_ptr[1] = 233;   //error
//
//	// 通过const_cast<Ty> 去常量
//	int *ptr = const_cast<int*>(c_ptr);
//
//	// 修改数据
//	for (int i = 0; i < 4; i++)
//		ptr[i] += 1;    //pass
//
//	// 打印修改后的数据
//	for (int i = 0; i < 4; i++)
//		std::cout << ary[i] << "\t";
//	std::cout << std::endl;
//
//	return 0;
//	
//}



//int main()
//{
//	const int a = 10;
//	//int *b = const_cast<int*>(a);//不通过
//	const int *b = &a;
//	int *c = const_cast<int*>(&a);
//
//	*c = 5;
//	//cout << a << endl;
//
//	static int f = 5;
//	cout << f << endl;
//}


//剑指41 数据流中的中位数

//class DynamicArray
//{
//public:
//	void Insert(double num)
//	{
//		
//	}
//
//	 int GetMedian()
//	{
//		int size = min.size() + max.size();
//		if (size == 0)
//			throw exception("No numbers are available");
//
//		 int median = 0;
//		if ((size & 1) == 1)
//			median = min[0];
//		else
//			median = (min[0] + max[0]) / 2;
//
//		return median;
//	}
//
//private:
//	vector<int> min;
//	vector<int> max;
//};
//
//// ====================测试代码====================
//void Test(char* testName, DynamicArray<double>& numbers, double expected)
//{
//	if (testName != nullptr)
//		printf("%s begins: ", testName);
//
//	if (abs(numbers.GetMedian() - expected) < 0.0000001)
//		printf("Passed.\n");
//	else
//		printf("FAILED.\n");
//}
//
//int main(int argc, char* argv[])
//{
//	DynamicArray<double> numbers;
//
//	printf("Test1 begins: ");
//	try
//	{
//		numbers.GetMedian();
//		printf("FAILED.\n");
//	}
//	catch (const exception&)
//	{
//		printf("Passed.\n");
//	}
//
//	numbers.Insert(5);
//	Test("Test2", numbers, 5);
//
//	numbers.Insert(2);
//	Test("Test3", numbers, 3.5);
//
//	numbers.Insert(3);
//	Test("Test4", numbers, 3);
//
//	numbers.Insert(4);
//	Test("Test6", numbers, 3.5);
//
//	numbers.Insert(1);
//	Test("Test5", numbers, 3);
//
//	numbers.Insert(6);
//	Test("Test7", numbers, 3.5);
//
//	numbers.Insert(7);
//	Test("Test8", numbers, 4);
//
//	numbers.Insert(0);
//	Test("Test9", numbers, 3.5);
//
//	numbers.Insert(8);
//	Test("Test10", numbers, 4);
//
//	return 0;
//}


//剑指45 把数组排成最小的数
static bool cmp(int a, int b)
{
	string A = "";
	string B = "";
	A += to_string(a);
	A += to_string(b);
	B += to_string(b);
	B += to_string(a);
	return A<B;
}
string PrintMinNumber(vector<int> numbers) {
	string answer = "";
	sort(numbers.begin(), numbers.end(), cmp);
	for (int i = 0; i<numbers.size(); i++)
	{
		answer += to_string(numbers[i]);
	}
	return answer;

}



int main(){


}