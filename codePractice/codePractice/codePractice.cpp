// codePractice.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include<cassert>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

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
////��������II
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



void main()
{
	int a[6] = { 1, 3, 6, 2, 1, 3 };
	//process(a, 3, 6);
	heapSort(a, 6);
	for (int i = 0; i < 6; i++)
		cout << a[i];
}