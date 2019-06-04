// codePractice.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<cassert>
#include <string>
#include <stack>
#include <queue>
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
void swap(int &a, int &b)
{
	int tem = a;
	a = b ;
	b = tem;
}
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
//
////插入排序II
void insertSortII(int arry[], int length)

{
	for (int i = 1; i < length; i++)
	{
		for (int j = i - 1; j >= 0 && (arry[j] > arry[j + 1]);j--)
		{
			swap(arry[j + 1], arry[j]);
		}
	}



}
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
void merge(int arry[], int L, int mid, int R)
{
	int length = R - L + 1;
	int p1 = L;
	int p2 = mid + 1;
	int i = 0;
	int *a=new int[R-L+1];
	while ((p1 <= mid)&&(p2 <= R))
	{
		a[i++] = arry[p1] < arry[p2] ? arry[p1++] : arry[p2++];
		
	}
	while (p1<=mid)
	{
		a[i++] = arry[p1++];
	}
	while (p2 <= R)
	{
		a[i++] = arry[p2++];
	}
	for (int i = 0; i < length; i++)
	{
		arry[L+i] = a[i];
	}


}
void sortProcess(int arry[], int L,int R)
{
	if (L == R)
	{
		return;
	}
	int mid = (L + R) / 2;
	sortProcess(arry, L, mid);
	sortProcess(arry, mid + 1, R);
	merge(arry, L, mid, R);

}
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
//int merge(int arr[], int L,int mid, int R)
//{
//	//int mid = L + (R - L) >> 1;
//	int length = R - L + 1;
//	int *help = new int[R - L + 1];
//	int i = 0;
//	int p1 = L;
//	int p2 = mid+1;
//	int result = 0;
//	while ((p1 <= mid) && (p2 <= R))
//	{
//		result += arr[p1] < arr[p2] ? arr[p1] * (R - p2 + 1) : 0;
//		help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
//		
//	}
//
//	while (p1 <= mid)
//	{
//		help[i++] = arr[p1++];
//	}
//	while (p2 <= R)
//	{
//		help[i++] = arr[p2++];
//	}
//	for (int j = 0; j < length; j++)
//		arr[L+j] = help[j];
//	return result;
//}
//
//int sortProcess(int arr[], int L, int R)
//{
//	if (L == R)
//	{
//		return 0;
//	}
//	int mid = L + ((R - L) >> 1);  //注意 >>的优先级低
//	return sortProcess(arr, L, mid)  //左侧产生的小和加右侧产生的小和加最后左右merge产生的小和
//	+sortProcess(arr, mid + 1, R)
//	+merge(arr, L, mid, R);
//}
//int main()
//{
//	int a[5] = { 1, 0, 3, 4, 5 };
//	int res;
//	res=sortProcess(a, 0, 4);
//	cout << res << endl;
//}


//给定数组arr,给定num,将小于num的数放左边，大于num的数放右边

void process(int arr[], int num,int length)
{
	int point = -1;
	int i = 0;
	while (i!=length)
	{
		if (arr[i] <= num)
		{
			swap(arr[i], arr[++point]);
			
		}
		i++;
	}

}



//荷兰国旗问题
//注意if-else匹配，防止出错。
void partition(int arr[], int l, int r,int num)
{
	int cur = l;
	int less = l - 1;
	int more = r + 1;

	while (cur < more)
	{
		if (arr[cur] < num)
		{
			swap(arr[++less], arr[cur++]);
		}
		else if (arr[cur] > num)
		{

			swap(arr[--more], arr[cur]);
		}
		else
		{
			cur++;
		}
	}
}




//快速排序 AND随机快速排序
int * partation(int arr[], int L, int R)
{
	int less = L - 1;
	int more = R ; //注意这一行，以最后一个数作为比较的数，大于此数放右边，小于此数放左边
	int cur = L;
	int *result = new int[2]; //分配动态数组****
	while (L < more)
	{
		if (arr[L] < arr[R])
		{
			swap(arr[++less], arr[L++]);
		}
		else if (arr[L]>arr[R])
		{
			swap(arr[--more], arr[L]);

		}
		else
			L++;
	}
	swap(arr[R], arr[more]); //最后需要交换一下最后一个数和右边第一个数。

	result[0] = less+1;    //返回中间数的左右边界
	result[1] = more;
	return  result;

}

void quikSort(int arr[], int L, int R)
{
	if (L < R)
	{
		swap(arr[R], arr[L + (int)(rand() % (R - L + 1)) ]);//随机快排，随机选取一个数为中间位置的数
		int *P = partation(arr, L, R);
		quikSort(arr, L, P[0] - 1);
		quikSort(arr, P[1] + 1, R);
	}
}


//堆排序
 
//将一个数插入到数组index位置处并形成大根堆
void heapInsert(int arr[],int index)
{
	//当index=0时，(index-1)/2=0,此时也会停止
	while (arr[index]>arr[(index - 1) / 2])
	{
		swap(arr[index], arr[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}

//当index位置数值变小时，调整顺序重新变为大根堆
void heapify(int arr[], int index, int heapsize)
{
	int left = index * 2 + 1;
	while (left < heapsize)
	{
		int largest = left + 1 < heapsize && arr[left + 1] > arr[left] 
			? left + 1 
			: left;  //判断，左右孩子中较大数的位置。右边不越界并且右边的数大于左边，右边为最大数，否则为左边
		largest = arr[index]>arr[largest] ? index : largest;//判断index位置改变后是否比左右孩子中最大的数值大
		if (largest == index)
		{
			break;
		}
		swap(arr[largest], arr[index]);
		index = largest;//此时，孩子中最大值已经和父节点交换，此位置发生变化，重复以上过程，使此数组重新调整为大根堆
		left = index * 2 + 1;

	}
}

//堆排序，每次将最后一个数和第一个数交换，此时能得到一个最大值，heapsize-1，继续调整重新形成大根堆，重复第一步操作，至
//全部调整完
void heapSort(int arr[], int length)
{
	//数组建立大根堆
	for (int i = 0; i < length; i++)
	{
		heapInsert(arr, i);
	}

	//最后位置和头交换，得到一个最大值
	int heapsize = length;
	swap(arr[--heapsize], arr[0]);
	while (heapsize > 0)
	{
		heapify(arr, 0, heapsize);
		swap(arr[--heapsize], arr[0]);
		
	}

}


//不基于比较的排序
//给定一个数组，求如果排序之后，相邻两数的最大差值，要求时
//间复杂度O(N)，且要求不能用非基于比较的排序

int maxGap(int arr[])
{
	return 0;

}




//用数组结构实现大小固定的队列和栈
//1 栈的实现
class ArrayStack{
private:
	int size;
	int *arr;
	int sizeIndex;
public:
	ArrayStack(int initSize)
	{
		size = initSize;
		if (size < 0) 
		{
			throw "The init size is less than 0!";
		}
		arr = new int[initSize];
		sizeIndex = 0;
	}

	int StackPeek()//返回栈顶
	{
		if (sizeIndex == 0){
			return NULL;
		}
		return arr[sizeIndex - 1];

	}
	int pop()
	{
		if (sizeIndex == 0){
			throw "The stack is empty!";
		}
		return arr[--sizeIndex];

	}

	void push(int obj)
	{
		if (sizeIndex == size)
		{
			throw "The stack is full!";

		}
		arr[sizeIndex++] = obj;
	}

};

//队列的实现 队列先进先出
class ArrayQueue{
private:
	int size;
	int sizeIndex;
	int start;//指向队列头部
	int end;//指向队列的尾部，即新数据加入的位置
	int *arr;
public:
	ArrayQueue(int initSize)
	{
		size = initSize;
		if (size < 0)
		{
			throw "The init size is less than 0!";
		}
		sizeIndex = 0;
		arr = new int[initSize];
		start = 0;
		end = 0;
	}
	//返回队列第一个数
	int peek()
	{
		if (size == 0)
		{
			return NULL;
		}
		return arr[start];
	}

	void push(int obj)
	{
		if (sizeIndex==size)
		{
			throw "The queue is full!";

		}
		sizeIndex++;
		arr[end] = obj;
		end = end == size - 1 ? 0 : end + 1;

	}

	int poll() //弹出一个数
	{
		if (sizeIndex == 0)
		{
			throw "The queue is empty!";

		}
		sizeIndex--;
		int temp = start;
		start = start == size - 1 ? 0 : start + 1;
		return arr[temp];

	}

};

//void main()
//{
//	
//	//int a[6] = { 1, 3, 6, 2, 1, 3 };
//	////process(a, 3, 6);
//	//heapSort(a, 6);
//	//for (int i = 0; i < 6; i++)
//	//	cout << a[i];
//	ArrayStack myStack(5);
//	ArrayQueue myQueue(5);
//	myStack.push(1);
//	myStack.push(2);
//	myStack.push(3);
//	myStack.push(4);
//	myStack.push(5);
//	myQueue.push(1);
//	myQueue.push(2);
//	myQueue.push(3);
//	myQueue.push(4);
//	myQueue.push(5);
//	//myStack.push(5);
//	for (int i = 0; i < 5; i++)
//	{
//		cout << myStack.pop() << endl;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		cout << myQueue.poll() << endl;
//	}
//}



//实现一个特殊的栈，在实现栈的基本功能的基础上，再实现返
//回栈中最小元素的操作。
//要求：时间复杂度都是O（1）
//使用现有的stack结构

//解决方案：使用两个stack,一个存放正常数据，另一个存放当前栈中的
//最小值，出栈时，两个栈顶同时出栈，得到当前栈中的最小值

class MinStack
{
private:
	stack<int>sData;
	stack<int>sMin;
public:
	void push(int data)
	{
		if (sData.empty())
		{
			sData.push(data);
			sMin.push(data);
		}
		else if (data < sMin.top())
		{
			sData.push(data);
			sMin.push(data);

		}
		else
		{
			sData.push(data);
			sMin.push(sMin.top());//如果入栈数据不是最小值，smin栈顶仍为最小值，复制一份，保持两栈size相同
		}
	}
	void pop()
	{
		sData.pop();
		sMin.pop();
	}
	int min()
	{
		return sMin.top();
	}
};


//int main()
//{
//	MinStack mystack;
//	mystack.push(5);
//	mystack.push(3);
//	mystack.push(2);
//	mystack.push(1);
//	cout<<mystack.min()<<endl;
//	mystack.pop();
//	cout << mystack.min() << endl;
//
//}



//仅用队列实现栈结构

class queueStack{
private:
	queue<int>Data;
	queue<int>Help;
public:
	/*queueStack()
	{


	}*/
	//入栈
	void pushQueueStack(int data)
	{
		Data.push(data);
	}
	//出栈
	int popQueueStack()
	{
		while (Data.size() > 1)//Data栈中只剩下一个数的时候停止，返回剩下的最后一个数即为stack的弹出的第一个数
		{
			Help.push(Data.front());
			Data.pop();
		}
		int res = Data.front();
		Data.pop();
		swapQueue();//指针交换，DATA和Help交换
		return res;
	}
	//显示栈顶元素
	int peekQueueStack()
	{
		while (Data.size() > 1)//Data栈中只剩下一个数的时候停止，返回剩下的最后一个数即为stack的弹出的第一个数
		{
			Help.push(Data.front());
			Data.pop();
		}
		int res = Data.front();
		Help.push(res);
		Data.pop();
		swapQueue();//指针交换，DATA和Help交换
		return res;

	}

	//指针交换
	void swapQueue()
	{
		queue<int>tmp = Help;
		Help = Data;
		Data = tmp;

	}
};

//int main()
//{
//	queueStack myStack;
//	myStack.pushQueueStack(5);
//	myStack.pushQueueStack(4);
//	myStack.pushQueueStack(3);
//	myStack.pushQueueStack(2);
//	myStack.pushQueueStack(1);
//	cout << myStack.peekQueueStack() << endl;
//	myStack.popQueueStack();
//	cout << myStack.peekQueueStack() << endl;
//
//}


//仅用栈实现队列结构
//两个栈push栈和pop栈
//原则1：一次将push里的数转移到pop
//原则2：pop里如果有数，不能转移
class stackQueue
{
private:
	stack<int>stackPush;
	stack<int>stackPop;
public:
	void pushStackQueue(int data)
	{
		stackPush.push(data);
	}

	int popStackQueue()
	{
		if (stackPush.empty() && stackPop.empty())
		{
			throw "The queue is empty!";
		}
		else if (stackPop.empty())//只有pop为空时才可以一次性将push的数转移到pop
		{
			while (!stackPush.empty())
			{
				stackPop.push(stackPush.top());//全部转移
				stackPush.pop();//出栈
			}
		}
		int res = stackPop.top();
		stackPop.pop();
		return res;
	}
};

int main()
{
	stackQueue mystackQueue;
	mystackQueue.pushStackQueue(1);
	mystackQueue.pushStackQueue(2);
	mystackQueue.pushStackQueue(3);
	mystackQueue.pushStackQueue(4);
	cout << mystackQueue.popStackQueue() << endl;
	cout << mystackQueue.popStackQueue() << endl;
	mystackQueue.pushStackQueue(5);
	mystackQueue.pushStackQueue(6);
	cout << mystackQueue.popStackQueue() << endl;


}
