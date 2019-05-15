// codePractice.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

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
void swap(int &a, int &b)
{
	int tem = a;
	a = b ;
	b = tem;
}
void bubbleSort(int arry[],int length)
{
	
	for (int i = length - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arry[j] > arry[j + 1])
				swap(arry[j], arry[j + 1]);
		}
	}
}

//选择排序

void selectionSort(int arry[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		int Index = i;
		for (int j = i + 1; j < length; j++)
		{
			Index = arry[j] < arry[Index] ? j : Index;
		}
		swap(arry[Index], arry[i]);
	}
}

//插入排序
void insertSort(int arry[], int length)
{
	for (int i = 0; i < length-1; i++)
	{
		if (arry[i + 1] < arry[i])
		{
			swap(arry[i + 1], arry[i]);
			for (int j = i; j > 0; j--)
			{
				if (arry[j] < arry[j - 1])
					swap(arry[j], arry[j - 1]);
			}

		}
		

	}
}


int main()
{

	int a[9] = { 1, 3, 2,4,5,2,9,5,0 };
	//bubbleSort(a,8);
	//selectionSort(a, 8);
	insertSort(a, 9);
	for (int i = 0; i < 9;i++)
	cout << a[i];
	return 0;

}

