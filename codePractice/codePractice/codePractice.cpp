// codePractice.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include<cassert>
#include <string>
#include <stack>
#include <queue>
#include <sstream>
#include <hash_map>
#include<unordered_map>

using namespace std;
using namespace stdext;

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

//int main()
//{
//	stackQueue mystackQueue;
//	mystackQueue.pushStackQueue(1);
//	mystackQueue.pushStackQueue(2);
//	mystackQueue.pushStackQueue(3);
//	mystackQueue.pushStackQueue(4);
//	cout << mystackQueue.popStackQueue() << endl;
//	cout << mystackQueue.popStackQueue() << endl;
//	mystackQueue.pushStackQueue(5);
//	mystackQueue.pushStackQueue(6);
//	cout << mystackQueue.popStackQueue() << endl;
//
//
//}

//给定一个整型矩阵matrix，请按照转圈的方式打印它
//分析：可按圈打印，给出左上和右下角位置信息，每次打印一圈的数。

class printMatrixSpiralOrder{
public:
	void SpiralOrderPrint(vector<vector<int>> my_matrix)
	{
		int TR = 0;//左上角行
		int TC = 0;//左上角列
		int DR = my_matrix.size() - 1;//右下角行
		int DC = my_matrix[0].size() - 1;//右下角列
		while ((TR <= DR)&&(TC <= DC))
		{
			printEdge(my_matrix, TR, DR, TC, DC);
			TR++;
			TC++;
			DR--;
			DC--;

		}
	}
	void printEdge(vector<vector<int>> matrix, int TR, int DR, int TC, int DC)
	{
		if (TR == DR)
		{
			for (int i = TC; i <= DC; i++)
				cout << matrix[TR][i] << " ";
		}
		else if (TC == DC)
		{
			for (int i = TR; i < DR; i++)
				cout << matrix[i][TC] << " ";
		}
		else
		{
			int currC = TC;
			int currR = TR;
			while (currC != DC)
			{
				cout << matrix[TR][currC] << " ";
				currC++;
			}
			while (currR != DR)
			{
				cout << matrix[currR][DC] << " ";
				currR++;
			}
			while (currC != TC)
			{
				cout << matrix[DR][currC] << " ";
				currC--;
			}
			while (currR != TR)
			{
				cout << matrix[currR][TC] << " ";
				currR--;
			}
		}
	}
};

//给定一个整型正方形矩阵matrix，请把该矩阵调整成
//顺时针旋转90度的样子。额外空间复杂度O(1)
//分析：和上题类似，由外向内，分圈调整，先调整外圈，再调整内圈。
//每圈的调整方法相同，使用rotateEdge()函数可以计算出对应位置，直接调整。

class rotateMatrix{
public:
	void rotate(vector<vector<int>> &matrix)  //按圈调整，先调整外圈，再调整内圈
	{
		int TR = 0;
		int TC = 0;
		int DR = matrix.size() - 1;//得到行数
		int DC = matrix[0].size() - 1;//得到列数
		while (TR < DR)
		{
			rotateEdge(matrix, TR++, TC++, DR--, DC--);//注意TR TC加，DR,DC减
		}
	}

	void rotateEdge(vector<vector<int>>&matrix,int TR, int TC, int DR, int DC) //仔细算一下位置。。。。。。
	{
		int times = DC - TC;
		int tmp = 0;
		for (int i = 0; i != times; i++)
		{
			tmp = matrix[TR][TC + i];
			matrix[TR][TC + i] = matrix[DR - i][TC];
			matrix[DR - i][TC] = matrix[DR][DC - i];
			matrix[DR][DC - i] = matrix[TR + i][DC];
			matrix[TR + i][DC] = tmp;
		}
	}
	void printMatrix(vector<vector<int>>&matrix)
	{
		int row = matrix.size();
		int column = matrix[0].size();
		for (int i = 0; i != row; i++)
		{
			for (int j = 0; j != column; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};

//给定一个矩阵matrix，按照“之”字形的方式打印这 个矩阵
//分析 A B两点从头出发，A向右，到头后向下，B向下，到头后向右，每走一步将两点连接经过的数就是需要打印的数
//需要一个flag标记向下打印还是向上打印

class ZigZigPrintMatrix{
public:
	void printMatrixZigZig(vector<vector<int>>matrix)
	{
		int ar = 0;//A B两点都从（0，0）出发
		int ac = 0;
		int br = 0;
		int bc = 0;
		int endR = matrix.size()-1;
		int endC = matrix[0].size()-1;
		bool fromUp = false;//记录方向,是否从上到下打印
		while (ar != endR+1)
		{
			printLevel(matrix, ar, ac, br, bc, fromUp);
			ar = (ac == endC ? ar+1 : ar);//A点向右走，如果到了最右边，则保持列不变，向下走
			ac = (ac == endC ? ac : ac+1);
			//注意 BC BR的先后顺序，不能颠倒
			bc = (br == endR ? bc + 1 : bc);
			br = (br == endR ? br : br+1);
			fromUp = !fromUp;
		}

	}

	void printLevel(vector<vector<int>>matrix, int ar, int ac, int br, int bc, bool flag)
	{
		if (flag)
		{
			while (ar != br + 1)
			{
				cout << matrix[ar++][ac--] << " ";
			}

		}
		else
		{
			while (br != ar -1)
			{
				cout << matrix[br--][bc++] << " ";
			}
		}

	}



};






//int main()
//{
//	vector<vector<int>>matrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };
//	printMatrixSpiralOrder print;
//	//print.SpiralOrderPrint(matrix);
//	rotateMatrix test;
//	/*test.printMatrix(matrix);
//	test.rotate(matrix);
//	test.printMatrix(matrix);*/
//	ZigZigPrintMatrix zigMatrix;
//	zigMatrix.printMatrixZigZig(matrix);
//
//}

//在行列都排好序的矩阵中找数k 
// 时间复杂度为O(N+M)，额外空间复杂度为O(1)。
//分析：从右上角出发，如果比K大,向左移动，否则向下移动

class findMaxSortedMatrix{
public:
	bool findMax(vector<vector<int>>matrix,int k)
	{
		int lengthR = matrix.size();
		int lengthC = matrix[0].size();
		int currR = 0;
		int currC = lengthC - 1;
		while ((currR != lengthR) || (currC != -1))
		{
			if (matrix[currR][currC] == k)
			{
				return true;
			}
			else if (matrix[currR][currC] > k)
			{
				currC--;
			}
			else
			{
				currR++;
			}
		}
		return false;

	}
};

//int main()
//{
//	findMaxSortedMatrix findMax;
//	vector<vector<int>>matrix = { { 0, 1, 2, 3, 4, 5, 6 },// 0
//	{ 10, 12, 13, 15, 16, 17, 18 },// 1
//	{ 23, 24, 25, 26, 27, 28, 29 },// 2
//	{ 44, 45, 46, 47, 48, 49, 50 },// 3
//	{ 65, 66, 67, 68, 69, 70, 71 },// 4
//	{ 96, 97, 98, 99, 100, 111, 122 },// 5
//	{ 166, 176, 186, 187, 190, 195, 200 },// 6
//	{ 233, 243, 321, 341, 356, 370, 380 } // 7
//	};
//	int K = 233;
//	cout<<findMax.findMax(matrix, K)<<endl;
//}




//给定一个链表的头节点head，请判断该链表是否为回文结构

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode()=default;//默认构造函数要加上default
	//一旦我们定义了其他类型的构造函数，我们必须定义一个默认的构造函数，否则类将没有默认构造函数。
	ListNode(int x) {//其他形式构造函数
		val = x;
		next = nullptr;
	}
};

class IsPalindromeList{
public:
	//方法一：将所有节点的value装入栈中，依次出栈，原数据即变为反方向，对比是否相等
	//需要n的额外空间
	bool isPalindromel1(ListNode* head)
	{
		stack <int> stack;
		ListNode* cur = head;
		while (cur != nullptr)
		{
			stack.push(cur->val);
			cur = cur->next;
		}
		while (head != nullptr)
		{
			if (head->val != stack.top())
				return false;
			else
			{
				head = head->next;
				stack.pop();
			}
		}
		return true;
	}


	//方法二：两个指针，一个快指针一次走两步一个慢指针一次走一步，快指针走到终点的时候慢指针走到中点
	//从中点位置开始入栈，再出栈，依次和从头开始的节点比较是否相等
	//需要额外空间：n/2
	bool isPalindromel2(ListNode* head)
	{
		if (head == nullptr || head->next == nullptr)
		{
			return true;
		}

		stack<int>my_node_value;
		ListNode *slowNode = head->next;
		ListNode *fastNode = head;
		while (fastNode->next != nullptr&&fastNode->next->next != nullptr){
			slowNode = slowNode->next;
			fastNode = fastNode->next->next;
		}
		while (slowNode != nullptr){
			my_node_value.push(slowNode->val);
			slowNode = slowNode->next;
		}
		while (!my_node_value.empty()){
			if (head->val != my_node_value.top()){
				return false;
				break;
			}
			else{
				head = head->next;
				my_node_value.pop();
			}
		}
		return true;
	}


	//方法三：两个指针，一个快指针一次走两步一个慢指针一次走一步，快指针走到终点的时候慢指针走到中点
	//从中间开始分为两段，将后一段指针改变方向，改为由后指向前
	//两段都是从前向后开始比较
	//额外空间复杂度：O（1）
	bool isPalindromel3(ListNode* head){
		if (head == nullptr || head->next == nullptr){
			return true;
		}

		ListNode *n1 = head;//慢指针
		ListNode *n2 = head;//快指针
		while (n2->next != nullptr&&n2->next->next != nullptr){
			n1 = n1->next;
			n2 = n2->next->next;
		}//n1此时指向中点，n2指向末尾
		n2 = n1->next;  //n2为后半段的第一个节点
		n1->next = nullptr;  //n1的next为空
		ListNode *n3 = nullptr;
		while (n2 != nullptr){//改变后半段的指针方向
			n3 = n2->next;
			n2->next = n1;
			n1 = n2;
			n2 = n3;
		}
		n3 = n1;//此时，n1为整个链表中最后一个位置，赋给n3
		n2 = head;//n2为头
		while (n1 != nullptr&&n2 != nullptr){
			if (n1->val != n2->val){//比较是否相等
				return false;
				break;
			}
			else{
				n1 = n1->next;
				n2 = n2->next;
			}
		}
		//复位 将后半段方向复原
		n1 = n3->next;
		n3->next = nullptr;//最后一个位置，next为null
		while (n1 != nullptr){
			n2 = n1->next;
			n1->next = n3;
			n3 = n1;
			n1 = n2;
		}
		return true;


	}

};

void printList(ListNode* pHead) {
	while (pHead != nullptr) {
		std::cout << pHead->val << ",";
		pHead = pHead->next;
	}
	std::cout << "\n";
}


//int main()
//{
//	ListNode* pHead = new ListNode(1);
//	pHead->next = new ListNode(2);
//	pHead->next->next = new ListNode(4);
//	std::cout << "origin list is:" << std::endl;
//	printList(pHead);
//	IsPalindromeList List;
//	bool is_palindrome = List.isPalindromel3(pHead);
//	if (is_palindrome) {
//		std::cout << "is palindrome" << std::endl;
//	}
//	else {
//		std::cout << "not palindrome" << std::endl;
//	}
//	return 0;
//}


//将单向链表按某值划分成左边小、中间相等、右边大的形式
class SmallerEqualBigger{
public:
	void swapList(ListNode *a, ListNode *b){
		int tmp = a->val;
		a->val = b->val;
		b->val = tmp;

	}

	//方法一：将链表装入数组，分为三部分后再重新连接形成新链表
	//缺点：打破数据的稳定性
	ListNode* listPartition1(ListNode* head, int pivot){
		if (head == nullptr){
			return NULL;
		}
		ListNode *cur = head;
		int length = 0;
		while (cur != nullptr){//统计链表的长度
			length++;
			cur = cur->next;
		}
		cur = head;
		ListNode *nodeArr = new ListNode[length];
		for (int j = 0; j < length; j++){//将所有链表数据存入数组
			nodeArr[j] = *cur;
			cur = cur->next;
		}
		arrPartition(nodeArr, length,pivot); //将数组中的数据按val的大小分为三部分
		//将分好的数据重新连接
		for (int i = 1; i != length; i++){
			nodeArr[i - 1].next = &nodeArr[i];
		}
		nodeArr[length - 1].next = nullptr;
		return nodeArr;
	}

	void arrPartition(ListNode *arr,int length, int pivot)
	{
		int small = -1;
		int big = length;
		int index = 0;
		while (index != big){
			if (arr[index].val < pivot){
				swapList(&arr[index++], &arr[++small]);
			}
			else if (arr[index].val == pivot){
				index++;
			}
			else{
				swapList(&arr[index], &arr[--big]);
			}
		}

	}

	ListNode* listPartition2(ListNode* head, int pivot){
		ListNode *sH = nullptr;//小于区域的头small head
		ListNode *sT = nullptr;//小于区域的尾部small tail
		ListNode *eH = nullptr;//等于区域
		ListNode *eT = nullptr;
		ListNode *bH = nullptr;//大于区域
		ListNode *bT = nullptr;
		while (head != nullptr){
			ListNode *next = head->next;
			head->next = nullptr;
			if (head->val < pivot){
				if (sH == nullptr){
					sH = head;
					sT = head;
				}
				else{
					sT->next = head;
					sT = head;
				}
				
			}
			else if (head->val == pivot){
				if (eH == nullptr){
					eH = head;
					eT = head;
				}
				else{
					eT->next = head;
					eT = head;
				}
			}
			else
			{
				if (bH == nullptr){
					bH = head;
					bT = head;
				}
				else{
					bT->next = head;
					bT = head;
				}
			}
			head = next;
		}
		if (sT != nullptr){//小段连接相等段
			sT->next = eH;//eh可以为空
			eT = (nullptr == eT ? sT : eT);//保证et不能为空，因为它要连接下一段
		}
		if (eT != nullptr){//相等段连接大段
			eT->next = bH;//bh可以为空
		}
		return sH != nullptr ? sH : eH != nullptr ? eH : bH;//返回不为空的部分的头节点 sh eh或bh
	}






};

//int main()
//{
//	ListNode* pHead = new ListNode(1);
//	ListNode* result;
//	pHead->next = new ListNode(2);
//	pHead->next->next = new ListNode(4);
//	pHead->next->next->next= new ListNode(3);
//	pHead->next->next->next->next = new ListNode(0);
//	pHead->next->next->next->next->next = new ListNode(5);
//	std::cout << "origin list is:" << std::endl;
//	printList(pHead);
//	SmallerEqualBigger test;
//	pHead=test.listPartition2(pHead, 6);
//	std::cout << "new list is:" << std::endl;
//	printList(pHead);
//
//}


//复制含有随机指针节点的链表
struct specialListNode{
//public:
	int value;
	specialListNode *next;
	specialListNode *rand;
	specialListNode() = default; //默认构造函数
	specialListNode(int x):
		value(x),next(nullptr),rand(nullptr) {}    //构造函数初始值列表
};

////使用hash_map所需要的hash函数
//struct hash_Node{
//	 size_t operator() (const specialListNode &node) const{
//		return node.value;
//	}
// };
//
////使用hash_map所需要的比较函数
//struct compare_Node{
//	    bool operator() (const specialListNode &n1, const specialListNode &n2) const{
//		         return n1.value == n2.value && n1.next == n2.next && n1.rand == n2.rand;
//		}
//};


class CopyListWithRandom{
public:
	void printRandLinkedList(specialListNode* head){
		specialListNode *cur = head;
		cout << "order:" << endl;
		while (cur != nullptr){
			cout << cur->value << " ";
			cur = cur->next;
		
		}
		cout << endl;
		cur = head;
		cout << "rand:" << endl;
		while (cur != nullptr){
			if (cur->rand == nullptr){
				cout << "-" << " ";
			}
			else
				cout << cur->rand->value<<" ";
			
			cur = cur->next;
		
		}
		cout << endl;

	}


	specialListNode* copyListWithRand1(specialListNode* head){
		unordered_map<specialListNode*, specialListNode*> map;
		specialListNode *cur = head;
		while (cur != nullptr){
			specialListNode *ptr=new specialListNode;
			ptr->value = cur->value;
			ptr->next = nullptr;
			ptr->rand = nullptr;
			map[cur] = ptr;//对应关系
			//map.insert(make_pair(cur, ptr));
			cur = cur->next;
		}
		cur = head;
		while (cur != nullptr){
			map[cur]->next = map[cur->next]; //map[cur]指的是cur' .cur'的next就是cur->next对应的（cur->next）'即map[cur->next]  画个图即明白
			map[cur]->rand = map[cur->rand];
			cur = cur->next;
		}
		return map[head];
	}

	//注意画图理解
	specialListNode* copyListWithRand2(specialListNode* head){
		specialListNode *cur = head;
		specialListNode *next = nullptr;
		while (cur != nullptr){//将所有节点拷贝，并按1-1‘-2-2’3-3‘的顺序连接
			next = cur->next;
			specialListNode *newNode = new specialListNode;
			cur->next = newNode;
			newNode->value = cur->value;
			newNode->next = next;
			newNode->rand = nullptr;
			cur = next;
		}

		cur = head;
		specialListNode *curCopy = new specialListNode;
		while (cur != nullptr){//设置拷贝节点的rand      rand关系：1-3-3’从而找到1‘->rand 为3’
			next = cur->next->next;
			curCopy = cur->next;
			curCopy->rand = cur->rand!=nullptr?cur->rand->next:nullptr;
			cur = next;
			
		}
		specialListNode *res = head->next;
		cur = head;
		while (cur != nullptr){//设置拷贝节点的naxt,分离两条链表
			next = cur->next->next;
			curCopy = cur->next;
			cur->next = next;
			curCopy->next = curCopy->next == nullptr ? nullptr : next->next;
			cur = next;
		}
		return res;

	}


};

//int main()
//{
//	specialListNode *head = NULL;
//
//	head = new specialListNode(1);
//	head->next = new specialListNode(2);
//	head->next->next = new specialListNode(3);
//	head->next->next->next = new specialListNode(4);
//	head->next->next->next->next = new specialListNode(5);
//	head->next->next->next->next->next = new specialListNode(6);
//
//	head->rand = head->next->next->next->next->next; // 1 -> 6
//	head->next->rand = head->next->next->next->next->next; // 2 -> 6
//	head->next->next->rand = head->next->next->next->next; // 3 -> 5
//	head->next->next->next->rand = head->next->next; // 4 -> 3
//	head->next->next->next->next->rand = nullptr; // 5 -> null
//	head->next->next->next->next->next->rand = head->next->next->next; // 6 -> 4
//	CopyListWithRandom test;
//	test.printRandLinkedList(head);
//	head=test.copyListWithRand2(head);
//	test.printRandLinkedList(head);
//}


//单链表可能有环也可能无环。给定两个单链表的头节点 head1 和 head2，
//这两个单链表可能相交也可能不相交。请实现一个函数，如果两个链表相交，请返回相交的第一个节点；如果不相交，返回 NULL。


 //分析 此问题拆分为三步  
//1 判断一个链表有无环  方法一：将节点放入map，每次有新的节点查询map中以前是否出现此节点。
//方法二 快慢指针，每次分别走两步和一步，最后相遇则为有环


//2 判断两个无环链表相交 方法一：链表1所有节点放入map 查询map中有没有链表2的节点 
//方法二：统计链表1和2 的长度和最后一个节点， 如果最后一个节点相等一定相交。因为单链表，相交的位置是同一个节点，指向的next也是相同，所以相交节点以后的位置都是相等的
//长的减短的：n=length1-length2，长的先走n步，短的再走，找到第一个相交的节点。或者使用map

//有环和无环单链表不可能相交



//3 判断两个有环链表相交：loop1 2为第一二个链表的入环节点  各自成环--不相交(loop1!=loop2)   先相交，共享一个环（loop1==loop2）--相当于无环链表找相交节点问题    
//两个链表共同组成一个环 （loop1!=loop2） 解决办法：loop1一直往下走，循环完一遍没有碰到loop2 此时为情况1：各自成环 不相交
//

class FindFirstIntersectNode{
public:
	ListNode* getIntersectNode(ListNode *head1, ListNode *head2){
		if (head1 == nullptr || head2 == nullptr){
			return NULL;
		}
		ListNode *loop1=getLoopNode(head1);
		ListNode *loop2=getLoopNode(head2);

		if (loop1 ==NULL&&loop2==NULL){//没有入环节点判断相交点
			return noLoop(head1, head2);
		}

		if (loop1 != NULL&&loop2 != NULL){//两个链表都有入环节点
			return bothLoop(head1, loop1, head2, loop2);
		}
		return NULL;//如果一个有环，一个无环，不可能相交
	}



	//得到入环节点  方法原理不知道 结果正确 归纳总结出来的 记住
	ListNode*  getLoopNode(ListNode *head){//快慢指针，分别一次走一步和两步，最后相遇说明有环
		if (head == nullptr || head->next == nullptr||head->next->next==nullptr){
			return nullptr;
		}
		ListNode *slow = head->next;
		ListNode *fast = head->next->next;
		while (fast != slow){//直到快慢指针相遇
			if (fast->next != nullptr && fast->next->next != nullptr){//这个条件很重要，一定别写错了
				fast = fast->next->next;//快指针一次走两步
				slow = slow->next;
			}
			else
				return nullptr;

		}
		fast = head;//快指针从头开始，慢指针从相遇位置开始，都一次走一步
		while (fast != slow){  //再次相遇的位置就是入环点
			fast = fast->next;
			slow = slow->next;
		}
		return slow;

	}

	//都没有入环节点，判断相交
	ListNode* noLoop(ListNode *head1, ListNode *head2){
		int length1 = 0;//记录两个链表的长度
		int length2 = 0;
		
		ListNode *cur1 = head1;
		ListNode *cur2 = head2;
		while (cur1->next != nullptr){//得到length1和end1
			length1++;
			
			cur1= cur1->next;
		}
		
		while (cur2->next != nullptr){//得到length2和end2
			length2++;
		
			cur2 = cur2->next;

		}
		if (cur1 != cur2){//如果两链表尾不相等，说明不相交
			return nullptr;

		}
		else{//如果两个链表结尾内存地址相等说明两链表有相交点，查找相交点 
			int n = length1 >= length2 ? length1 - length2 : length2 - length1;//得到两链表长度的差值
			cur1 = length1 > length2 ? head1 : head2;//cur1指向长度长的链表
			cur2 = cur1 == head1 ? head2 : head1;
			while (n != 0){//长的链表先走n步
				n--;
				cur1 = cur1->next;
			}
			while (cur1 != cur2){//然后同时走 找到两链表相等的节点

				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			return cur1;

		}
	}


	//都有入环节点，判断相交函数
	//都有入环节点有三种可能
	ListNode* bothLoop(ListNode *head1, ListNode *loop1, ListNode *head2, ListNode *loop2){
		ListNode *cur1 = head1;
		ListNode *cur2 = head2;
		if (loop1 == loop2){//如果两个入环节点相等，说明两链表为同一个环，和上边没有环的判断方法相同,此时两链表end相等
			int n = 0;
			while (cur1 != loop1){//注意条件
				n++;
				cur1=cur1->next ;
			}
			while (cur2 != loop2){
				n--;
				cur2=cur2->next;
			}
			cur1 = n > 0 ? head1 : head2;
			cur2 = cur1 == head1 ? head2 : head1;
			n = abs(n);
			while (n != 0){
				n--;
				cur1 = cur1->next;
			}
			while (cur1 != cur2){
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			return cur1;
		}
		
		else{//loop1和loop2不相等，有两种可能：完全没交点；两链表共同组成环。loop1在环内遍历，看能否找到loop2
			cur1 = loop1->next;
			while (cur1 != loop1){
				if (cur1 == loop2){
					return cur1;//返回交点
				}
				cur1 = cur1->next;
			}
			return nullptr;//没有交点
		}

	}

};

int main()
{
	FindFirstIntersectNode test;
	ListNode *result;

	// 1->2->3->4->5->6->7->null
	ListNode *head1 = new ListNode(1);
	head1->next = new ListNode(2);
	head1->next->next = new ListNode(3);
	head1->next->next->next = new ListNode(4);
	head1->next->next->next->next = new ListNode(5);
	head1->next->next->next->next->next = new ListNode(6);
	head1->next->next->next->next->next->next = new ListNode(7);

	// 0->9->8->6->7->null
	ListNode *head2 = new ListNode(0);
	head2->next = new ListNode(9);
	head2->next->next = new ListNode(8);
	head2->next->next->next = head1->next->next->next->next->next; // 8->6
	result = test.getIntersectNode(head1, head2);//无环链表交点
	cout << result->val<<endl;
	

	// 1->2->3->4->5->6->7->4->->->
	head1 = new ListNode(1);
	head1->next = new ListNode(2);
	head1->next->next = new ListNode(3);
	head1->next->next->next = new ListNode(4);
	head1->next->next->next->next = new ListNode(5);
	head1->next->next->next->next->next = new ListNode(6);
	head1->next->next->next->next->next->next = new ListNode(7);
	head1->next->next->next->next->next->next = head1->next->next->next; // 7->4

	// 0->9->8->2->->->
	head2 = new ListNode(0);
	head2->next = new ListNode(9);
	head2->next->next = new ListNode(8);
	head2->next->next->next = head1->next; // 8->2
	result = test.getIntersectNode(head1, head2); //有相同环链表交点
	cout << result->val<<endl;

	// 0->9->8->6->4->5->6->->
	head2 = new ListNode(0);
	head2->next = new ListNode(9);
	head2->next->next = new ListNode(8);
	head2->next->next->next = head1->next->next->next->next->next; // 8->6
	result = test.getIntersectNode(head1, head2);//共同组成环
	cout << result->val<<endl;

}
