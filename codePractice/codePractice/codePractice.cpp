// codePractice.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<cassert>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

//T1 虚函数使用 链接：https://www.nowcoder.com/questionTerminal/3cea911c23a043ae96f0767d42bfa4f2


//class Base {
//public:
//	Base() { echo(); }
//	virtual void echo() { printf("Base"); }
//};
//
//class Derived :public Base {
//public:
//	Derived() { echo(); }
//	virtual void echo() { printf("Derived"); }
//};

//int main() {
//	Base* base = new Derived();
//	base->echo();
//	return 0;
//}

//T2链接：https://www.nowcoder.com/questionTerminal/7183f3428a444efe8a3f91247ddf6b7a
//判断运行多少次截止，注意溢出
//int main()
//{
//	unsigned char i = 7;
//	int j = 0;
//	for (; i>0; i -= 3)
//	{
//		++j;
//	}
//	printf("%d\n", j);
//	return 0;
//}

//T3 https://www.nowcoder.com/questionTerminal/17d4c9b1a03e4650be5e29af3f2e1f7c
//模板的定义
//template <class T>
//T fun(T x, T y){
//	return x*x + y*y;
//}
//int main()
//{
//	float result;
//	result=fun<float>(2, 1.0);
//	cout << result;
//}

//int main()
//{
//	int I = 1;
//	if (I <= 0)
//		printf("****\n");
//	else
//		printf("%%%%\n");
//}

//class parent
//{
//public:
//	virtual void output();
//};
//void parent::output()
//{
//	printf("parent!");
//}
//
//class son : public parent
//{
//public:
//	virtual void output();
//};
//void son::output()
//{
//	printf("son!");
//}
//
//int main()
//{
//	son s;
//	memset(&s, 0, sizeof(s));
//	parent& p = s;
//	p.output();
//}

//#define JH(a,b,t)t=a; a=b; b=t;
//int main()
//{
//
//	int a, b, t;
//	a = 1;
//	b = 2;
//	JH(a, b, t)
//		printf("%d %d\n", a, t);
//
//	return 0;
//}

//冒泡排序
//void swap(int &a, int &b)
//{
//	int tem = a;
//	a = b ;
//	b = tem;
//}
//void bubbleSort(int arry[],int length)
//{
//	
//	for (int i = length - 1; i > 0; i--)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (arry[j] > arry[j + 1])
//				swap(arry[j], arry[j + 1]);
//		}
//	}
//}
//
////选择排序
//
//void selectionSort(int arry[], int length)
//{
//	for (int i = 0; i < length - 1; i++)
//	{
//		int Index = i;
//		for (int j = i + 1; j < length; j++)
//		{
//			Index = arry[j] < arry[Index] ? j : Index;
//		}
//		swap(arry[Index], arry[i]);
//	}
//}
//
////插入排序
//void insertSort(int arry[], int length)
//{
//	for (int i = 0; i < length-1; i++)
//	{
//		if (arry[i + 1] < arry[i])
//		{
//			swap(arry[i + 1], arry[i]);
//			for (int j = i; j > 0; j--)
//			{
//				if (arry[j] < arry[j - 1])
//					swap(arry[j], arry[j - 1]);
//			}
//
//		}
//		
//
//	}
//}
//
////插入排序II
//void insertSortII(int arry[], int length)
//
//{
//	for (int i = 1; i < length; i++)
//	{
//		for (int j = i - 1; j >= 0 && (arry[j] > arry[j + 1]);j--)
//		{
//			swap(arry[j + 1], arry[j]);
//		}
//	}
//
//
//
//}
//
//
//int main()
//{
//
//	int a[9] = { 1, 3, 2,4,5,2,9,5,0 };
//	//bubbleSort(a,8);
//	//selectionSort(a, 8);
//	insertSortII(a, 9);
//	for (int i = 0; i < 9;i++)
//	cout << a[i];
//	return 0;
//
//}


//LEETCODE 171. Excel表列序号
//class Solution {
//public:
//	int titleToNumber(string s) {
//		int length = s.length();
//		int result = 0;
//		int j = 0;
//		for (int i = length - 1; i >= 0; i--)
//		{
//			result = result + (s[i] - 'A' + 1)*(pow(26, j));
//			j++;
//		}
//		return result;
//
//	}
//};
//
//string stringToString(string input) {
//	assert(input.length() >= 2);
//	string result;
//	for (int i = 1; i < input.length() - 1; i++) {
//		char currentChar = input[i];
//		if (input[i] == '\\') {
//			char nextChar = input[i + 1];
//			switch (nextChar) {
//			case '\"': result.push_back('\"'); break;
//			case '/': result.push_back('/'); break;
//			case '\\': result.push_back('\\'); break;
//			case 'b': result.push_back('\b'); break;
//			case 'f': result.push_back('\f'); break;
//			case 'r': result.push_back('\r'); break;
//			case 'n': result.push_back('\n'); break;
//			case 't': result.push_back('\t'); break;
//			default: break;
//			}
//			i++;
//		}
//		else {
//			result.push_back(currentChar);
//		}
//	}
//	return result;
//}
//
//int main() {
//	string line;
//	while (getline(cin, line)) {
//		string s = stringToString(line);
//
//		int ret = Solution().titleToNumber(line);
//
//		
//		cout << ret << endl;
//	}
//	return 0;
//} 


//归并排序
//void merge(int arry[], int L, int mid, int R)
//{
//	int length = R - L + 1;
//	int p1 = L;
//	int p2 = mid + 1;
//	int i = 0;
//	int *a=new int[R-L+1];
//	while ((p1 <= mid)&&(p2 <= R))
//	{
//		a[i++] = arry[p1] < arry[p2] ? arry[p1++] : arry[p2++];
//		
//	}
//	while (p1<=mid)
//	{
//		a[i++] = arry[p1++];
//	}
//	while (p2 <= R)
//	{
//		a[i++] = arry[p2++];
//	}
//	for (int i = 0; i < length; i++)
//	{
//		arry[L+i] = a[i];
//	}
//
//
//}
//void sortProcess(int arry[], int L,int R)
//{
//	if (L == R)
//	{
//		return;
//	}
//	int mid = (L + R) / 2;
//	sortProcess(arry, L, mid);
//	sortProcess(arry, mid + 1, R);
//	merge(arry, L, mid, R);
//
//}
//int main()
//{
//	int a[5] = { 1, 5, 3, 4, 7 };
//	sortProcess(a, 0, 4);
//	for (int i = 0; i < 5; i++)
//		cout << a[i];
//
//}


//LEETCODE 168. Excel表列名称
//class Solution {
//public:
//	string convertToTitle(int n) {
//		stack<char> s;
//		string result;
//		stringstream stream;
//		int i = 0;
//		int m = 0;
//		char r;
//		while (n != 0)
//		{
//			m = n % 26;
//			if (m == 0)
//			{
//				r = 'Z';
//				n = n - 26;
//			}
//			else
//			{
//				r = 'A' + m - 1;
//				
//			}
//			n = n / 26;
//			s.push(r);
//			
//		}
//		while (!s.empty())
//		{
//			
//			
//			stream << s.top();
//			s.pop();
//
//		}
//		result = stream.str();
//		return result;
//
//	}
//};

//class Solution {
//public:
//	string convertToTitle(int n) {
//		string res;
//		while (n) {
//			res += --n % 26 + 'A';
//			n /= 26;
//		}
//		return string(res.rbegin(), res.rend());
//	}
//};






//class Solution {
//public:
//	string convertToTitle(int n) {
//		string res = "";
//		while (n) {
//			if (n % 26 == 0) {
//				res += 'Z';
//				n -= 26;
//			}
//			else {
//				res += n % 26 - 1 + 'A';
//				n -= n % 26;
//			}
//			n /= 26;
//		}
//		reverse(res.begin(), res.end());
//		return res;
//	}
//};

//int stringToInteger(string input) {
//	return stoi(input);
//}
//
//int main() {
//	string line;
//	while (getline(cin, line)) {
//		int n = stringToInteger(line);
//
//		string ret = Solution().convertToTitle(n);
//
//		string out = (ret);
//		cout << out << endl;
//	}
//	return 0;
//}


//小和问题
int merge(int arr[], int L,int mid, int R)
{
	//int mid = L + (R - L) >> 1;
	int length = R - L + 1;
	int *help = new int[R - L + 1];
	int i = 0;
	int p1 = L;
	int p2 = mid+1;
	int result = 0;
	while ((p1 <= mid) && (p2 <= R))
	{
		result += arr[p1] < arr[p2] ? arr[p1] * (R - p2 + 1) : 0;
		help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
		
	}

	while (p1 <= mid)
	{
		help[i++] = arr[p1++];
	}
	while (p2 <= R)
	{
		help[i++] = arr[p2++];
	}
	for (int j = 0; j < length; j++)
		arr[L+j] = help[j];
	return result;
}

int sortProcess(int arr[], int L, int R)
{
	if (L == R)
	{
		return 0;
	}
	int mid = L + ((R - L) >> 1);  //注意 >>的优先级低
	return sortProcess(arr, L, mid)  //左侧产生的小和加右侧产生的小和加最后左右merge产生的小和
	+sortProcess(arr, mid + 1, R)
	+merge(arr, L, mid, R);
}
int main()
{
	int a[5] = { 1, 0, 3, 4, 5 };
	int res;
	res=sortProcess(a, 0, 4);
	cout << res << endl;
}