// codePractice.cpp : �������̨Ӧ�ó������ڵ㡣
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

//T1 �麯��ʹ�� ���ӣ�https://www.nowcoder.com/questionTerminal/3cea911c23a043ae96f0767d42bfa4f2


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

//T2���ӣ�https://www.nowcoder.com/questionTerminal/7183f3428a444efe8a3f91247ddf6b7a
//�ж����ж��ٴν�ֹ��ע�����
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
//ģ��Ķ���
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

//ð������
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
////ѡ������
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
////��������
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
////��������II
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


//LEETCODE 171. Excel�������
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


//�鲢����
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


//LEETCODE 168. Excel��������
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


//С������
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
//	int mid = L + ((R - L) >> 1);  //ע�� >>�����ȼ���
//	return sortProcess(arr, L, mid)  //��������С�ͼ��Ҳ������С�ͼ��������merge������С��
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


//��������arr,����num,��С��num��������ߣ�����num�������ұ�

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



//������������
//ע��if-elseƥ�䣬��ֹ����
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




//�������� AND�����������
int * partation(int arr[], int L, int R)
{
	int less = L - 1;
	int more = R ; //ע����һ�У������һ������Ϊ�Ƚϵ��������ڴ������ұߣ�С�ڴ��������
	int cur = L;
	int *result = new int[2]; //���䶯̬����****
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
	swap(arr[R], arr[more]); //�����Ҫ����һ�����һ�������ұߵ�һ������

	result[0] = less+1;    //�����м��������ұ߽�
	result[1] = more;
	return  result;

}

void quikSort(int arr[], int L, int R)
{
	if (L < R)
	{
		swap(arr[R], arr[L + (int)(rand() % (R - L + 1)) ]);//������ţ����ѡȡһ����Ϊ�м�λ�õ���
		int *P = partation(arr, L, R);
		quikSort(arr, L, P[0] - 1);
		quikSort(arr, P[1] + 1, R);
	}
}


//������
 
//��һ�������뵽����indexλ�ô����γɴ����
void heapInsert(int arr[],int index)
{
	//��index=0ʱ��(index-1)/2=0,��ʱҲ��ֹͣ
	while (arr[index]>arr[(index - 1) / 2])
	{
		swap(arr[index], arr[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}

//��indexλ����ֵ��Сʱ������˳�����±�Ϊ�����
void heapify(int arr[], int index, int heapsize)
{
	int left = index * 2 + 1;
	while (left < heapsize)
	{
		int largest = left + 1 < heapsize && arr[left + 1] > arr[left] 
			? left + 1 
			: left;  //�жϣ����Һ����нϴ�����λ�á��ұ߲�Խ�粢���ұߵ���������ߣ��ұ�Ϊ�����������Ϊ���
		largest = arr[index]>arr[largest] ? index : largest;//�ж�indexλ�øı���Ƿ�����Һ�����������ֵ��
		if (largest == index)
		{
			break;
		}
		swap(arr[largest], arr[index]);
		index = largest;//��ʱ�����������ֵ�Ѿ��͸��ڵ㽻������λ�÷����仯���ظ����Ϲ��̣�ʹ���������µ���Ϊ�����
		left = index * 2 + 1;

	}
}

//������ÿ�ν����һ�����͵�һ������������ʱ�ܵõ�һ�����ֵ��heapsize-1���������������γɴ���ѣ��ظ���һ����������
//ȫ��������
void heapSort(int arr[], int length)
{
	//���齨�������
	for (int i = 0; i < length; i++)
	{
		heapInsert(arr, i);
	}

	//���λ�ú�ͷ�������õ�һ�����ֵ
	int heapsize = length;
	swap(arr[--heapsize], arr[0]);
	while (heapsize > 0)
	{
		heapify(arr, 0, heapsize);
		swap(arr[--heapsize], arr[0]);
		
	}

}


//�����ڱȽϵ�����
//����һ�����飬���������֮����������������ֵ��Ҫ��ʱ
//�临�Ӷ�O(N)����Ҫ�����÷ǻ��ڱȽϵ�����

int maxGap(int arr[])
{
	return 0;

}




//������ṹʵ�ִ�С�̶��Ķ��к�ջ
//1 ջ��ʵ��
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

	int StackPeek()//����ջ��
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

//���е�ʵ�� �����Ƚ��ȳ�
class ArrayQueue{
private:
	int size;
	int sizeIndex;
	int start;//ָ�����ͷ��
	int end;//ָ����е�β�����������ݼ����λ��
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
	//���ض��е�һ����
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

	int poll() //����һ����
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



//ʵ��һ�������ջ����ʵ��ջ�Ļ������ܵĻ����ϣ���ʵ�ַ�
//��ջ����СԪ�صĲ�����
//Ҫ��ʱ�临�Ӷȶ���O��1��
//ʹ�����е�stack�ṹ

//���������ʹ������stack,һ������������ݣ���һ����ŵ�ǰջ�е�
//��Сֵ����ջʱ������ջ��ͬʱ��ջ���õ���ǰջ�е���Сֵ

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
			sMin.push(sMin.top());//�����ջ���ݲ�����Сֵ��sminջ����Ϊ��Сֵ������һ�ݣ�������ջsize��ͬ
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



//���ö���ʵ��ջ�ṹ

class queueStack{
private:
	queue<int>Data;
	queue<int>Help;
public:
	/*queueStack()
	{


	}*/
	//��ջ
	void pushQueueStack(int data)
	{
		Data.push(data);
	}
	//��ջ
	int popQueueStack()
	{
		while (Data.size() > 1)//Dataջ��ֻʣ��һ������ʱ��ֹͣ������ʣ�µ����һ������Ϊstack�ĵ����ĵ�һ����
		{
			Help.push(Data.front());
			Data.pop();
		}
		int res = Data.front();
		Data.pop();
		swapQueue();//ָ�뽻����DATA��Help����
		return res;
	}
	//��ʾջ��Ԫ��
	int peekQueueStack()
	{
		while (Data.size() > 1)//Dataջ��ֻʣ��һ������ʱ��ֹͣ������ʣ�µ����һ������Ϊstack�ĵ����ĵ�һ����
		{
			Help.push(Data.front());
			Data.pop();
		}
		int res = Data.front();
		Help.push(res);
		Data.pop();
		swapQueue();//ָ�뽻����DATA��Help����
		return res;

	}

	//ָ�뽻��
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


//����ջʵ�ֶ��нṹ
//����ջpushջ��popջ
//ԭ��1��һ�ν�push�����ת�Ƶ�pop
//ԭ��2��pop���������������ת��
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
		else if (stackPop.empty())//ֻ��popΪ��ʱ�ſ���һ���Խ�push����ת�Ƶ�pop
		{
			while (!stackPush.empty())
			{
				stackPop.push(stackPush.top());//ȫ��ת��
				stackPush.pop();//��ջ
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

//����һ�����;���matrix���밴��תȦ�ķ�ʽ��ӡ��
//�������ɰ�Ȧ��ӡ���������Ϻ����½�λ����Ϣ��ÿ�δ�ӡһȦ������

class printMatrixSpiralOrder{
public:
	void SpiralOrderPrint(vector<vector<int>> my_matrix)
	{
		int TR = 0;//���Ͻ���
		int TC = 0;//���Ͻ���
		int DR = my_matrix.size() - 1;//���½���
		int DC = my_matrix[0].size() - 1;//���½���
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

//����һ�����������ξ���matrix����Ѹþ��������
//˳ʱ����ת90�ȵ����ӡ�����ռ临�Ӷ�O(1)
//���������������ƣ��������ڣ���Ȧ�������ȵ�����Ȧ���ٵ�����Ȧ��
//ÿȦ�ĵ���������ͬ��ʹ��rotateEdge()�������Լ������Ӧλ�ã�ֱ�ӵ�����

class rotateMatrix{
public:
	void rotate(vector<vector<int>> &matrix)  //��Ȧ�������ȵ�����Ȧ���ٵ�����Ȧ
	{
		int TR = 0;
		int TC = 0;
		int DR = matrix.size() - 1;//�õ�����
		int DC = matrix[0].size() - 1;//�õ�����
		while (TR < DR)
		{
			rotateEdge(matrix, TR++, TC++, DR--, DC--);//ע��TR TC�ӣ�DR,DC��
		}
	}

	void rotateEdge(vector<vector<int>>&matrix,int TR, int TC, int DR, int DC) //��ϸ��һ��λ�á�����������
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

//����һ������matrix�����ա�֮�����εķ�ʽ��ӡ�� ������
//���� A B�����ͷ������A���ң���ͷ�����£�B���£���ͷ�����ң�ÿ��һ�����������Ӿ�������������Ҫ��ӡ����
//��Ҫһ��flag������´�ӡ�������ϴ�ӡ

class ZigZigPrintMatrix{
public:
	void printMatrixZigZig(vector<vector<int>>matrix)
	{
		int ar = 0;//A B���㶼�ӣ�0��0������
		int ac = 0;
		int br = 0;
		int bc = 0;
		int endR = matrix.size()-1;
		int endC = matrix[0].size()-1;
		bool fromUp = false;//��¼����,�Ƿ���ϵ��´�ӡ
		while (ar != endR+1)
		{
			printLevel(matrix, ar, ac, br, bc, fromUp);
			ar = (ac == endC ? ar+1 : ar);//A�������ߣ�����������ұߣ��򱣳��в��䣬������
			ac = (ac == endC ? ac : ac+1);
			//ע�� BC BR���Ⱥ�˳�򣬲��ܵߵ�
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

//�����ж��ź���ľ���������k 
// ʱ�临�Ӷ�ΪO(N+M)������ռ临�Ӷ�ΪO(1)��
//�����������Ͻǳ����������K��,�����ƶ������������ƶ�

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




//����һ�������ͷ�ڵ�head�����жϸ������Ƿ�Ϊ���Ľṹ

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode()=default;//Ĭ�Ϲ��캯��Ҫ����default
	//һ�����Ƕ������������͵Ĺ��캯�������Ǳ��붨��һ��Ĭ�ϵĹ��캯���������ཫû��Ĭ�Ϲ��캯����
	ListNode(int x) {//������ʽ���캯��
		val = x;
		next = nullptr;
	}
};

class IsPalindromeList{
public:
	//����һ�������нڵ��valueװ��ջ�У����γ�ջ��ԭ���ݼ���Ϊ�����򣬶Ա��Ƿ����
	//��Ҫn�Ķ���ռ�
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


	//������������ָ�룬һ����ָ��һ��������һ����ָ��һ����һ������ָ���ߵ��յ��ʱ����ָ���ߵ��е�
	//���е�λ�ÿ�ʼ��ջ���ٳ�ջ�����κʹ�ͷ��ʼ�Ľڵ�Ƚ��Ƿ����
	//��Ҫ����ռ䣺n/2
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


	//������������ָ�룬һ����ָ��һ��������һ����ָ��һ����һ������ָ���ߵ��յ��ʱ����ָ���ߵ��е�
	//���м俪ʼ��Ϊ���Σ�����һ��ָ��ı䷽�򣬸�Ϊ�ɺ�ָ��ǰ
	//���ζ��Ǵ�ǰ���ʼ�Ƚ�
	//����ռ临�Ӷȣ�O��1��
	bool isPalindromel3(ListNode* head){
		if (head == nullptr || head->next == nullptr){
			return true;
		}

		ListNode *n1 = head;//��ָ��
		ListNode *n2 = head;//��ָ��
		while (n2->next != nullptr&&n2->next->next != nullptr){
			n1 = n1->next;
			n2 = n2->next->next;
		}//n1��ʱָ���е㣬n2ָ��ĩβ
		n2 = n1->next;  //n2Ϊ���εĵ�һ���ڵ�
		n1->next = nullptr;  //n1��nextΪ��
		ListNode *n3 = nullptr;
		while (n2 != nullptr){//�ı���ε�ָ�뷽��
			n3 = n2->next;
			n2->next = n1;
			n1 = n2;
			n2 = n3;
		}
		n3 = n1;//��ʱ��n1Ϊ�������������һ��λ�ã�����n3
		n2 = head;//n2Ϊͷ
		while (n1 != nullptr&&n2 != nullptr){
			if (n1->val != n2->val){//�Ƚ��Ƿ����
				return false;
				break;
			}
			else{
				n1 = n1->next;
				n2 = n2->next;
			}
		}
		//��λ �����η���ԭ
		n1 = n3->next;
		n3->next = nullptr;//���һ��λ�ã�nextΪnull
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


//����������ĳֵ���ֳ����С���м���ȡ��ұߴ����ʽ
class SmallerEqualBigger{
public:
	void swapList(ListNode *a, ListNode *b){
		int tmp = a->val;
		a->val = b->val;
		b->val = tmp;

	}

	//����һ��������װ�����飬��Ϊ�����ֺ������������γ�������
	//ȱ�㣺�������ݵ��ȶ���
	ListNode* listPartition1(ListNode* head, int pivot){
		if (head == nullptr){
			return NULL;
		}
		ListNode *cur = head;
		int length = 0;
		while (cur != nullptr){//ͳ������ĳ���
			length++;
			cur = cur->next;
		}
		cur = head;
		ListNode *nodeArr = new ListNode[length];
		for (int j = 0; j < length; j++){//�������������ݴ�������
			nodeArr[j] = *cur;
			cur = cur->next;
		}
		arrPartition(nodeArr, length,pivot); //�������е����ݰ�val�Ĵ�С��Ϊ������
		//���ֺõ�������������
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
		ListNode *sH = nullptr;//С�������ͷsmall head
		ListNode *sT = nullptr;//С�������β��small tail
		ListNode *eH = nullptr;//��������
		ListNode *eT = nullptr;
		ListNode *bH = nullptr;//��������
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
		if (sT != nullptr){//С��������ȶ�
			sT->next = eH;//eh����Ϊ��
			eT = (nullptr == eT ? sT : eT);//��֤et����Ϊ�գ���Ϊ��Ҫ������һ��
		}
		if (eT != nullptr){//��ȶ����Ӵ��
			eT->next = bH;//bh����Ϊ��
		}
		return sH != nullptr ? sH : eH != nullptr ? eH : bH;//���ز�Ϊ�յĲ��ֵ�ͷ�ڵ� sh eh��bh
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


//���ƺ������ָ��ڵ������
struct specialListNode{
//public:
	int value;
	specialListNode *next;
	specialListNode *rand;
	specialListNode() = default; //Ĭ�Ϲ��캯��
	specialListNode(int x):
		value(x),next(nullptr),rand(nullptr) {}    //���캯����ʼֵ�б�
};

////ʹ��hash_map����Ҫ��hash����
//struct hash_Node{
//	 size_t operator() (const specialListNode &node) const{
//		return node.value;
//	}
// };
//
////ʹ��hash_map����Ҫ�ıȽϺ���
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
			map[cur] = ptr;//��Ӧ��ϵ
			//map.insert(make_pair(cur, ptr));
			cur = cur->next;
		}
		cur = head;
		while (cur != nullptr){
			map[cur]->next = map[cur->next]; //map[cur]ָ����cur' .cur'��next����cur->next��Ӧ�ģ�cur->next��'��map[cur->next]  ����ͼ������
			map[cur]->rand = map[cur->rand];
			cur = cur->next;
		}
		return map[head];
	}

	//ע�⻭ͼ���
	specialListNode* copyListWithRand2(specialListNode* head){
		specialListNode *cur = head;
		specialListNode *next = nullptr;
		while (cur != nullptr){//�����нڵ㿽��������1-1��-2-2��3-3����˳������
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
		while (cur != nullptr){//���ÿ����ڵ��rand      rand��ϵ��1-3-3���Ӷ��ҵ�1��->rand Ϊ3��
			next = cur->next->next;
			curCopy = cur->next;
			curCopy->rand = cur->rand!=nullptr?cur->rand->next:nullptr;
			cur = next;
			
		}
		specialListNode *res = head->next;
		cur = head;
		while (cur != nullptr){//���ÿ����ڵ��naxt,������������
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


//����������л�Ҳ�����޻������������������ͷ�ڵ� head1 �� head2��
//����������������ཻҲ���ܲ��ཻ����ʵ��һ��������������������ཻ���뷵���ཻ�ĵ�һ���ڵ㣻������ཻ������ NULL��


 //���� ��������Ϊ����  
//1 �ж�һ���������޻�  ����һ�����ڵ����map��ÿ�����µĽڵ��ѯmap����ǰ�Ƿ���ִ˽ڵ㡣
//������ ����ָ�룬ÿ�ηֱ���������һ�������������Ϊ�л�


//2 �ж������޻������ཻ ����һ������1���нڵ����map ��ѯmap����û������2�Ľڵ� 
//��������ͳ������1��2 �ĳ��Ⱥ����һ���ڵ㣬 ������һ���ڵ����һ���ཻ����Ϊ�������ཻ��λ����ͬһ���ڵ㣬ָ���nextҲ����ͬ�������ཻ�ڵ��Ժ��λ�ö�����ȵ�
//���ļ��̵ģ�n=length1-length2����������n�����̵����ߣ��ҵ���һ���ཻ�Ľڵ㡣����ʹ��map

//�л����޻������������ཻ



//3 �ж������л������ཻ��loop1 2Ϊ��һ����������뻷�ڵ�  ���Գɻ�--���ཻ(loop1!=loop2)   ���ཻ������һ������loop1==loop2��--�൱���޻��������ཻ�ڵ�����    
//��������ͬ���һ���� ��loop1!=loop2�� ����취��loop1һֱ�����ߣ�ѭ����һ��û������loop2 ��ʱΪ���1�����Գɻ� ���ཻ
//

class FindFirstIntersectNode{
public:
	ListNode* getIntersectNode(ListNode *head1, ListNode *head2){
		if (head1 == nullptr || head2 == nullptr){
			return NULL;
		}
		ListNode *loop1=getLoopNode(head1);
		ListNode *loop2=getLoopNode(head2);

		if (loop1 ==NULL&&loop2==NULL){//û���뻷�ڵ��ж��ཻ��
			return noLoop(head1, head2);
		}

		if (loop1 != NULL&&loop2 != NULL){//�����������뻷�ڵ�
			return bothLoop(head1, loop1, head2, loop2);
		}
		return NULL;//���һ���л���һ���޻����������ཻ
	}



	//�õ��뻷�ڵ�  ����ԭ��֪�� �����ȷ �����ܽ������ ��ס
	ListNode*  getLoopNode(ListNode *head){//����ָ�룬�ֱ�һ����һ�����������������˵���л�
		if (head == nullptr || head->next == nullptr||head->next->next==nullptr){
			return nullptr;
		}
		ListNode *slow = head->next;
		ListNode *fast = head->next->next;
		while (fast != slow){//ֱ������ָ������
			if (fast->next != nullptr && fast->next->next != nullptr){//�����������Ҫ��һ����д����
				fast = fast->next->next;//��ָ��һ��������
				slow = slow->next;
			}
			else
				return nullptr;

		}
		fast = head;//��ָ���ͷ��ʼ����ָ�������λ�ÿ�ʼ����һ����һ��
		while (fast != slow){  //�ٴ�������λ�þ����뻷��
			fast = fast->next;
			slow = slow->next;
		}
		return slow;

	}

	//��û���뻷�ڵ㣬�ж��ཻ
	ListNode* noLoop(ListNode *head1, ListNode *head2){
		int length1 = 0;//��¼��������ĳ���
		int length2 = 0;
		
		ListNode *cur1 = head1;
		ListNode *cur2 = head2;
		while (cur1->next != nullptr){//�õ�length1��end1
			length1++;
			
			cur1= cur1->next;
		}
		
		while (cur2->next != nullptr){//�õ�length2��end2
			length2++;
		
			cur2 = cur2->next;

		}
		if (cur1 != cur2){//���������β����ȣ�˵�����ཻ
			return nullptr;

		}
		else{//������������β�ڴ��ַ���˵�����������ཻ�㣬�����ཻ�� 
			int n = length1 >= length2 ? length1 - length2 : length2 - length1;//�õ��������ȵĲ�ֵ
			cur1 = length1 > length2 ? head1 : head2;//cur1ָ�򳤶ȳ�������
			cur2 = cur1 == head1 ? head2 : head1;
			while (n != 0){//������������n��
				n--;
				cur1 = cur1->next;
			}
			while (cur1 != cur2){//Ȼ��ͬʱ�� �ҵ���������ȵĽڵ�

				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			return cur1;

		}
	}


	//�����뻷�ڵ㣬�ж��ཻ����
	//�����뻷�ڵ������ֿ���
	ListNode* bothLoop(ListNode *head1, ListNode *loop1, ListNode *head2, ListNode *loop2){
		ListNode *cur1 = head1;
		ListNode *cur2 = head2;
		if (loop1 == loop2){//��������뻷�ڵ���ȣ�˵��������Ϊͬһ���������ϱ�û�л����жϷ�����ͬ,��ʱ������end���
			int n = 0;
			while (cur1 != loop1){//ע������
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
		
		else{//loop1��loop2����ȣ������ֿ��ܣ���ȫû���㣻������ͬ��ɻ���loop1�ڻ��ڱ��������ܷ��ҵ�loop2
			cur1 = loop1->next;
			while (cur1 != loop1){
				if (cur1 == loop2){
					return cur1;//���ؽ���
				}
				cur1 = cur1->next;
			}
			return nullptr;//û�н���
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
	result = test.getIntersectNode(head1, head2);//�޻�������
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
	result = test.getIntersectNode(head1, head2); //����ͬ��������
	cout << result->val<<endl;

	// 0->9->8->6->4->5->6->->
	head2 = new ListNode(0);
	head2->next = new ListNode(9);
	head2->next->next = new ListNode(8);
	head2->next->next->next = head1->next->next->next->next->next; // 8->6
	result = test.getIntersectNode(head1, head2);//��ͬ��ɻ�
	cout << result->val<<endl;

}
