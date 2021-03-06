#include "stdafx.h"
#include <iostream>
#include<cassert>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <sstream>
#include <hash_map>
#include<unordered_map>
#include<time.h>
#include <cstdio>
#include "..\Utilities\BinaryTree.h"
#include "..\Utilities\List.h"

using namespace std;
using namespace stdext;


//实现二叉树的先序、中序、后序遍历，包括递归方式和非递归方式
//先序遍历：先当前节点，再打印左子树，再打印右子树
//中序遍历：先打印左子树，再打印当前，再打印右子树
//后续遍历：先打印左子树，再打印右子树最后当前节点
//定义二叉树
class Node{
public:
	int value;
	Node *left;//前向声明的类或者结构体只能用来定义指针或者引用。 
	           //必须用指针。不用指针编译通不过，就算能通过不用指针会一直调用下去，造成堆栈溢出
	Node *right;
public:
	Node(int data){
		value = data;
		left = nullptr;
		right = nullptr;
	}

};

class PrintBT{
public:
	//递归版本

	//先序打印
	void printPreOrderRecur(Node *head){
		if (head == nullptr){
			return;
		}
		cout << head->value << " ";
		printPreOrderRecur(head->left);
		printPreOrderRecur(head->right);
	}
	//中序打印
	void printInOrderRecur(Node *head){
		if (head == nullptr){
			return;
		}
		printInOrderRecur(head->left);
		cout << head->value << " ";
		printInOrderRecur(head->right);

	}
	//后序打印
	void printPosOrderRecur(Node *head){
		if (head == nullptr){
			return;
		}
		printInOrderRecur(head->left);
		printInOrderRecur(head->right);
		cout << head->value << " ";
	}


	//非递归版***********************//

	//先序打印 非递归 使用栈 
	void printPreOrderUnRecur(Node *head){
		stack<Node*>s;
		s.push(head);
		while(!s.empty()){
			head = s.top();
			cout << head->value << " ";
			s.pop();
			if (head->right != nullptr){
				s.push(head->right);
			}
			if (head->left != nullptr){
				s.push(head->left);
			}
		}
		
	
	}


	//中序打印  非递归 使用栈 
	//当前节点为空，从栈拿出打印，否则当前节点向右，否则当前节点入栈，当前节点向左
	void printInOrderUnRecur(Node *head){
		stack<Node*>s;
		if (head != nullptr){
			while (!s.empty() || head != nullptr){
				if (head != nullptr){
					s.push(head);
					head = head->left;
				}
				else{
					head = s.top();
					s.pop();
					cout << head->value << " ";
					head = head->right;
				}
			}
		}
	}

	//后序打印  和前序类似，先排成 中右左，放入辅助栈中，再输出栈中元素 则变为 左 右 中
	void printPosOrderUnRecur(Node *head){
		stack<Node*>s1,s2;
		s1.push(head);
		while (!s1.empty()){
			head = s1.top();
			s2.push(head);
			s1.pop();
			if (head->left != nullptr){
				s1.push(head->left);
			}
			if (head->right != nullptr){
				s1.push(head->right);
			}

		}
		while (!s2.empty()){
			cout << s2.top()->value << " ";
			s2.pop();
		}
	}


};


//int main()
//{
//	PrintBT test;
//	Node *head = new Node(5);
//	head->left = new Node(3);
//	head->right = new Node(8);
//	head->left->left = new Node(2);
//	head->left->right = new Node(4);
//	head->left->left->left = new Node(1);
//	head->right->left = new Node(7);
//	head->right->left->left = new Node(6);
//	head->right->right = new Node(10);
//	head->right->right->left = new Node(9);
//	head->right->right->right = new Node(11);
//	cout << "先序打印1：" << endl;
//	test.printPreOrderRecur(head);
//	cout << endl;
//	cout << "先序打印2：" << endl;
//	test.printPreOrderUnRecur(head);
//	cout << endl;
//	cout << "中序打印1：" << endl;
//	test.printInOrderRecur(head);
//	cout << endl;
//	cout << "中序打印2：" << endl;
//	test.printInOrderRecur(head);
//	cout << endl;
//	cout << "后序打印1：" << endl;
//	test.printPosOrderUnRecur(head);
//	cout << endl;
//	cout << "后序打印2：" << endl;
//	test.printPosOrderUnRecur(head);
//
//
//}


//在二叉树中找到一个节点的后继节点
//后继节点：中序遍历的序列中一个节点的下一个节点

//中序遍历顺序为左中右   所以后继节点只需关注该节点是否有右子树   

//一个节点如果有右子树，其后继节点为整棵右子树最左节点
//如果没有右子树  （一路向上，找到父节点的左子树是该节点的点）

class specialNode{
public:
	int value;
	specialNode *left;//前向声明的类或者结构体只能用来定义指针或者引用。 
	//必须用指针。不用指针编译通不过，就算能通过不用指针会一直调用下去，造成堆栈溢出
	specialNode *right;
	specialNode *parent;
public:
	specialNode(int data){
		value = data;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
};

class SuccessorNode{
public:
	specialNode* getSuccessorNode(specialNode *Node){
		if (Node == nullptr){
			return Node;
		}
		else if (Node->right != nullptr){//如果节点有右子树，那么该节点的后继肯定是整棵右子树的最左节点
			return getLeftNode(Node->right);

		}
		else{//如果没有右子树，此节点的后继肯定在上面 一直向上找，直到节点与父节点的左节点相等
			specialNode *parent = Node->parent;
			while (parent != nullptr&&parent->left != Node){

				Node = parent;

				parent = Node->parent;
			}
			return parent;
		}
	}

		specialNode* getLeftNode(specialNode *Node){
			if (Node == nullptr){
				return Node;
			}
			while (Node->left != nullptr){
				Node = Node->left;
			}
			return Node;
		}


};

//int main()
//{
//	specialNode *head = new specialNode(6);
//	head->parent = nullptr;
//	head->left = new specialNode(3);
//	head->left->parent = head;
//	head->left->left = new specialNode(1);
//	head->left->left->parent = head->left;
//	head->left->left->right = new specialNode(2);
//	head->left->left->right->parent = head->left->left;
//	head->left->right = new specialNode(4);
//	head->left->right->parent = head->left;
//	head->left->right->right = new specialNode(5);
//	head->left->right->right->parent = head->left->right;
//	head->right = new specialNode(9);
//	head->right->parent = head;
//	head->right->left = new specialNode(8);
//	head->right->left->parent = head->right;
//	head->right->left->left = new specialNode(7);
//	head->right->left->left->parent = head->right->left;
//	head->right->right = new specialNode(10);
//	head->right->right->parent = head->right;
//
//	SuccessorNode test;
//	specialNode *result;
//	specialNode *test1 = head->left->left;
//	specialNode *test2 = head->left->left->right;
//	result=test.getSuccessorNode(test1);
//	cout << result->value << endl; 
//	result = test.getSuccessorNode(test2);
//	cout << result->value << endl;
//
//}



//二叉树的序列化和反序列化

//序列化：遍历该二叉树
//反序列化：恢复
class SerializeAndReconstructTree{
public:

	//前序 序列化 递归方式
	string serialByPre(Node *head){
		if (head == nullptr){
			return "#!";
		}
		string result;
		string svalue = to_string(head->value);
		result = svalue + "!";
		result+=serialByPre(head->left);
		result+=serialByPre(head->right);
		return result;
	}
	//前序反序列化 递归方式
	//将得到的字符串分割好后装入队列
	Node* reconByPreString(string prestr){
		queue<string>*q;
		size_t firPos = 0;
		size_t secPos = 0;

		secPos = prestr.find("!");//找到分隔符
		while (secPos!=string::npos)
		{
			q->push(prestr.substr(firPos, secPos - firPos));//获取从指定的起始位置开始，长度为secPos-firPos的子字符串
			firPos = secPos + 1;
			secPos = prestr.find("!", firPos);//找到返回位置，找不到返回npos
		}
		return reconPreOrder(q);//调用递归函数，得到二叉树的头

	}

	//递归函数，重新生成二叉树
	Node *reconPreOrder(queue<string>*queue){
		string value = queue->front();
		if (value == "#"){
			return nullptr;
		}
		int svalue = stoi(value);
		Node *head = new Node(svalue);
		head->left = reconPreOrder(queue);
		head->right = reconPreOrder(queue);
		return head;

	}


	//按层序列化 
	string serialByLevel(Node *head){
		if (head == nullptr){
			return"#!";
		}
		string result;
		string svalue = to_string(head->value);
		result = svalue + "!";
		queue<Node*>q;
		q.push(head);
		while (!q.empty())
		{
			head = q.front();
			q.pop();
			if (head->left != nullptr){
				svalue = to_string(head->left->value);
				result += svalue + "!";
				q.push(head->left);
			}
			else{
				result += "#!";
			}
			if (head->right != nullptr){
				svalue = to_string(head->right->value);
				result += svalue + "!";
				q.push(head->right);
			}
			else{
				result += "#!";
			}
		}
		return result;
	}

	//按层反序列化
	Node* generateNodeByString(string val)
	{
		if ("#" == val)
			return nullptr;

		return new Node(stoi(val));
	}


	Node* reconByLevelString(string levelStr){
		queue<string>*q;
		size_t firPos = 0;
		size_t secPos = 0;

		secPos = levelStr.find("!");//找到分隔符
		while (secPos != string::npos)
		{
			q->push(levelStr.substr(firPos, secPos - firPos));//获取从指定的起始位置开始，长度为secPos-firPos的子字符串
			firPos = secPos + 1;
			secPos = levelStr.find("!", firPos);//找到返回位置，找不到返回npos
		}
		queue<Node*>*qNode = new queue<Node*>;//存储新生成的节点
		Node *root = generateNodeByString(q->front());
		q->pop();
		if (nullptr != root){
			qNode->push(root);
		}
		Node *node = nullptr;
		while (!qNode->empty()){  //按队列顺序拿出节点，并分配左右节点，并把左右节点入队列
			node = qNode->front();
			qNode->pop();
			if (node != nullptr){
				cout << node->value << endl;
			}
			else{
				cout << "#" << endl;
			}
			node->left = generateNodeByString(q->front());
			q->pop();
			node->right = generateNodeByString(q->front());
			q->pop();
			if (node->left != nullptr){
				qNode->push(node->left);
			}
			if (node->right != nullptr){
				qNode->push(node->right);
			}

		}
		return root;

	}









};

//int main()
//{
//	SerializeAndReconstructTree test;
//	Node *head = new Node(5);
//	head->left = new Node(3);
//	head->right = new Node(8);
//	head->left->left = new Node(2);
//	head->left->right = new Node(4);
//	head->left->left->left = new Node(1);
//	head->right->left = new Node(7);
//	head->right->left->left = new Node(6);
//	head->right->right = new Node(10);
//	head->right->right->left = new Node(9);
//	head->right->right->right = new Node(11);
//	string result = test.serialByPre(head);
//	cout << result << endl;
//	string result2 = test.serialByLevel(head);
//	cout << result2 << endl;
//	
//}


//平衡二叉树：左右子树高度差不超过一
//递归

class ReturnData{//返回值类
public:
	bool isBalance;//是否平衡
	int h;//子树树的高度
	ReturnData(bool isB, int h){
		isBalance = isB;
		h = h;
	}
};

ReturnData* process(Node *head){
	if (head == nullptr){
		return new ReturnData(true, 0);
	}
	ReturnData *leftData = process(head->left);
	if (!leftData->isBalance){//左树不平衡，直接返回false
		return new ReturnData(false, 0);
	}
	ReturnData *rightData = process(head->right);
	if (!rightData->isBalance){//如果右树不平衡，直接返回false
		return new ReturnData(false, 0);
	}

	if (abs(leftData->h - rightData->h) > 1){//左右两树差值大于1，返回false
		return new ReturnData(false, 0);
	}

	return new ReturnData(true, max(leftData->h, rightData->h) + 1);//如果左右子树差值不大于1 返回左右两子树最大高度加上自己的高度1

}

bool isB(Node *head){
	return process(head)->isBalance;
}

//int main()
//{
//	SerializeAndReconstructTree test;
//	Node *head = new Node(5);
//	head->left = new Node(3);
//	head->right = new Node(8);
//	head->left->left = new Node(2);
//	head->left->right = new Node(4);
//	head->left->left->left = new Node(1);
//	head->right->left = new Node(7);
//	head->right->left->left = new Node(6);
//	head->right->right = new Node(10);
//	head->right->right->left = new Node(9);
//	head->right->right->right = new Node(11);
//	cout << isB(head) << endl;
//	
//}



//搜索二叉树 每个节点比它左子树的任意节点大，而且比它右子树的任意节点小
//二叉树中序遍历结果若为升序，则为搜索二叉树

void findLeft(Node *head, stack<Node*>*s){
	s->push(head);
	while (head->left != nullptr){
		s->push(head->left);
		head = head->left;
	}

}
bool isBst(Node *head){
	if (head == nullptr){
		return false ;
	}
	int min = INT_MIN;
	stack<Node*>s;
	Node *cur=head;
	s.push(head);
	while (cur->left != nullptr){
		s.push(cur->left);
		cur = cur->left;
	}
	while (!s.empty()){
		cur = s.top();
		s.pop();
		if (cur->value > min)
		{
			min = cur->value;
		}
		else
		{
			return false;//如果后边的数小于前边的数，返回false
		}
		if (cur->right != nullptr){
			findLeft(cur->right,&s);
			
		}
	}
	return true;

}


//int main()
//{
//	PrintBT test;
//	Node *head = new Node(5);
//	head->left = new Node(3);
//	head->right = new Node(8);
//	head->left->left = new Node(2);
//	head->left->right = new Node(4);
//	head->left->left->left = new Node(1);
//	head->right->left = new Node(7);
//	head->right->left->left = new Node(6);
//	head->right->right = new Node(10);
//	head->right->right->left = new Node(9);
//	head->right->right->right = new Node(11);
//	cout<<isBst(head);
//}



//完全二叉树(Complete Binary Tree)： 若设二叉树的深度为h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数，第 h 层所有的结点都连续集中在最左边
//如果当前节点有右孩子没有左孩子，直接返回false
//如果当前节点只有左孩子，那么之后所有的节点都为叶节点（度为零的节点），否则返回false

bool isCBT(Node *head){
	queue<Node*>q;
	q.push(head);
	bool leaf = false;//第二种情况的标志。如果只有左孩子，没有右孩子，则下面的所有节点都不能有任何孩子
	while (!q.empty()){
		head = q.front();
		q.pop();
		if (head->left == nullptr&&head->right != nullptr){//如果只有右节点没有左节点，返回false
			return false;
		}
		if (leaf && (head->left != nullptr || head->right != nullptr)){//如果发生了第二种情况，但是左右孩子有一个不是空
			return false;
		}
		if (head->left != nullptr){
			q.push(head->left);
		}
		if (head->right != nullptr){
			q.push(head->right);
		}
		else{//如果右孩子等于空，则标志置为true
			leaf = true;
		}
	}
	return true;
}

//int main()
//{
//	PrintBT test;
//	Node *head = new Node(5);
//	head->left = new Node(3);
//	head->right = new Node(8);
//	head->left->left = new Node(2);
//	head->left->right = new Node(4);
//	head->left->left->left = new Node(1);
//	head->right->left = new Node(7);
//	head->right->left->left = new Node(6);
//	head->right->right = new Node(10);
//	//head->right->right->left = new Node(9);
//	//head->right->right->right = new Node(11);
//	cout << isCBT(head)<<endl;
//}



//已知一棵完全二叉树，求其节点的个数
//要求：时间复杂度低于O(N)，N为这棵树的节点个数
//遍历求解需要O（N）

//递归求解
//分析：如果完全二叉树右子树的最左节点能到达最后一层，说明整棵左子树为满树，用公式算出左子树节点数，递归求右子树节点数
//如果不能到达最后一层，说明整棵右子树为满树，用公式求出右子树节点数，再递归求左子树节点数
//O((logN)^2)=O(h^2)层数的平方  每一层只会选择一个节点进行bs递归，所以调用bs函数的次数为O（h）,
//每次调用bs函数，都会查看node右子树的最左节点，所以会再遍历O（h）个节点。

//整棵树的高度
int mostLeftLevel(Node *node, int level){
	while (node != nullptr){
		level++;
		node = node->left;
	}
	return level - 1;

}
int bs(Node *node, int level, int h){//level:头节点所在层数   h:当前树的总高度  这个值是固定的 因为所有的level计算都是计算的整棵树上的层
	if (level == h){//如果总高度和当前节点所在层数相等，总共右一个节点
		return 1;
	}

	if (mostLeftLevel(node->right, level+1) == h){//第一种情况，右子树的最左节点在整棵树的最后一层
		return(1 << (h - level)) + bs(node->right, level + 1, h);//递归

	}
	else{//第二种情况
		return(1 << (h - level - 1)) + bs(node->left, level + 1, h);  //注意()位置  +的优先级比<<大，所以左移操作用()括起来

	}


}

int nodeNum(Node *head){//求节点个数主函数
	if (head == nullptr){
		return 0;
	}
	return bs(head, 1, mostLeftLevel(head, 1));
}

//int main()
//{
//	PrintBT test;
//	Node *head = new Node(5);
//	head->left = new Node(3);
//	head->right = new Node(8);
//	head->left->left = new Node(2);
//	head->left->right = new Node(4);
//	head->right->left = new Node(7);
//	head->right->right = new Node(10);
//	head->left->left->left = new Node(1);
//	head->left->left->right = new Node(2);
//	cout << nodeNum(head) << endl;
//}



// 哈希函数：输入域无穷；输出域有限 ；输入一样，输出一样；输入不一样，输出可能一样（哈希碰撞）；输出域的值均匀分布



//设计RandomPool结构
//设计一种结构，在该结构中有如下三个功能：
//insert(key)：将某个key加入到该结构，做到不重复加入。
//delete(key)：将原本在结构中的某个key移除。getRandom()：
//等概率随机返回结构中的任何一个key。
//要求：Insert、delete和getRandom方法的时间复杂度都是O(1)

template<typename T>//模板参数列表
class RandomPool{
public:
	hash_map<T, int>keyIndexMap;
	hash_map<int, T>indexKeyMap;
	int size;
	RandomPool(){
		srand((unsigned int)time(NULL));//随机数发生器初始函数 以系统时间为种子
		size = 0;
	}
	~RandomPool(){}

	void insert( T key );
	void _delete(T key);
	T getRandom();
};

template<typename T>
void RandomPool<T>::insert(T key){
	if (keyIndexMap.find(key) == keyIndexMap.end()){
		keyIndexMap[key] = size;
		indexKeyMap[size++] = key;
	}
}
template<typename T>
T RandomPool<T>::getRandom(){
	int index = rand() % size;
	return indexKeyMap[index];
}

template<typename T>
void RandomPool<T>::_delete(T key){
	if (keyIndexMap.find(key) != keyIndexMap.end()){
		int index = keyIndexMap[key];//记录下来要删除的key的index
		int lastindex = --size;
		T lastkey = indexKeyMap[lastindex];//记录最后一个key
		keyIndexMap[lastkey] = index;//把最后一个key的值设置为要删除的key的index
		indexKeyMap[index] = lastkey;//把要删除的index处的值设置为最后一个index的值
		keyIndexMap.erase(key);
		indexKeyMap.erase(lastindex);
	}
}

//int main(){
//	RandomPool<std::string> rand;
//	rand.insert("p");
//	rand.insert("peng");
//	rand.insert("da");
//	rand.insert("shen");
//	
//	cout << rand.getRandom() << endl;
//	cout << rand.getRandom() << endl;
//	cout << rand.getRandom() << endl;
//	cout << rand.getRandom() << endl;
//	cout << rand.getRandom() << endl;
//	
//	
//	
//	rand._delete("da");
//	rand._delete("shen");
//	cout << "delete操作:" << endl;
//	cout << rand.getRandom() << endl;
//	cout << rand.getRandom() << endl;
//	cout << rand.getRandom() << endl;
//	cout << rand.getRandom() << endl;
//	cout << rand.getRandom() << endl;
//	
//}


//布隆过滤器 存在判断失误率   记住布隆过滤器大小计算公式 哈希函数个数计算公式 真实失误率计算公式



// 并查集

//先定义节点
//class UnionNode{
//public:
//	int value;
//	UnionNode(int v){
//		value = v;
//	}
//	~UnionNode(){}
//	/*bool operator != (const UnionNode &node1){
//		return!(this->value == node1.value);
//	}*/
//
//};
//
////重载!=运算符  如果value值不相等，则返回true 
////注意，如果两个自己定义的类需要比较大小，要进行运算符重载
////运算符重载有三种写法 可类外定义；  在类内只能有一个参数，作为成员函数时，*this即为左操作数；  类内作为友元函数
//
//bool operator == (const UnionNode &node1, const UnionNode &node2)
//{
//	return (node1.value == node2.value);
//}
//bool operator != (const UnionNode &node1, const UnionNode &node2)
//{
//	return !(node1.value == node2.value);
//}
//
//
//
//class UnionFind{
//public:
//	hash_map<UnionNode, UnionNode>fatherMap;//key--节点  value--father
//	hash_map<UnionNode, int>sizeMap;//某节点所在集合的总节点数
//	UnionFind(list<UnionNode>nodes){
//		//初始化
//		for (auto &node : nodes){
//			fatherMap[node] = node;//首节点指向自己
//			sizeMap[node] = 1;//每个集合只有一个节点，总节点数是1
//		}
//	}
//
//	//递归版本找father节点
//	UnionNode findHead(UnionNode node){//找father  在找的过程中将一个集合中的一串变成都指向father节点
//		UnionNode father = fatherMap[node];
//		if (father != node){
//			father = findHead(father);//递归
//		}
//		fatherMap[node] = father;//将此集合中的所有节点设置为一个father
//		return father;
//
//	}
//	//非递归版本找father节点
//	UnionNode findHeadUnr(UnionNode node){
//		stack<UnionNode>s;
//		UnionNode cur=node;
//		UnionNode father = fatherMap[node];
//		while (father != node){
//			s.push(cur);
//			cur = father;
//			father = fatherMap[cur];
//
//		}
//		while (!s.empty()){
//			cur = s.top();
//			s.pop();
//			fatherMap[cur] = father;
//		}
//	}
//
//	//判断是不是同一集合
//	bool isSameSet(UnionNode a, UnionNode b){
//		return findHead(a) == findHead(b);
//	}
//
//	void _union(UnionNode a, UnionNode b){
//		UnionNode aHead = findHead(a);
//		UnionNode bHead = findHead(b);
//		if (aHead != bHead){
//			int aSetSize = sizeMap[aHead];
//			int bSetSize = sizeMap[bHead];
//			if (aSetSize < bSetSize){//将数量少的节点的头挂到数量多的上面
//				fatherMap[aHead] = bHead;
//				sizeMap[bHead] = aSetSize + bSetSize;
//
//			}
//			else
//			{
//				fatherMap[bHead] = aHead;
//				sizeMap[aHead] = aSetSize + bSetSize;
//			}
//		}
//	}
//};




//岛问题

class Islands{
public:
	int contIslands(vector<vector<int>>m){
		if (m.empty() || m[0].empty()){//数组大小为0
			return 0;
		}
		int N = m.size();//行
		int M = m[0].size();//列
		int res = 0;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				if (m[i][j] == 1){
					res++;
					infect(m, i, j, N, M);
				}
			}
		}
		return res;

	}
	void infect(vector<vector<int>>&m, int i, int j, int N, int M){//注意 如果要改变原数据，一定用引用
		if (i < 0 || i >= N || j < 0 || j >= M || m[i][j] != 1){
			return;
		}
		m[i][j] = 2;
		infect(m, i + 1, j, N, M);
		infect(m, i - 1, j, N, M);
		infect(m, i, j + 1, N, M);
		infect(m, i, j - 1, N, M);
	}
};

//int main()
//{
//	vector<vector<int>>m1 = { { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 1, 1, 1, 0, 1, 1, 1, 0 },
//	{ 0, 1, 1, 1, 0, 0, 0, 1, 0 },
//	{ 0, 1, 1, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 1, 1, 0, 0 },
//	{ 0, 0, 0, 0, 1, 1, 1, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }, };
//	Islands test;
//	cout<<test.contIslands(m1)<<endl;
//}


//前缀树   
//字母放到边上，不要放到节点里边
class TrieNode{
public:
	int path; //到达过此节点的次数
	int end;   //以此节点结尾的字符串个数
	TrieNode *nexts[26];//路
	TrieNode(){
		path = 0; 
		end = 0;
		for (int i = 0; i < 26; i++){
			nexts[i] = nullptr;
		}
		//一共有26条路。，如果不通就是nullptr如果通了就是不为空
		//如果不止26条路 可以设计成hashmap或者asic码等类型
	}
};

class Trie{
private:
	TrieNode *root;
public:
	Trie(){
		root = new TrieNode();
	}
	void insert(string word){
		if (word.empty()){
			return;
		}
		int length = word.length();
		char *a=new char[length];//因为不知道word的长度，所以用动态方式开辟char类型的数组，将string转为char[]
		strcpy(a, word.c_str());
		TrieNode *node = root;
		int index = 0;
		for (int i = 0; i < length; i++){
			index = a[i] - 'a';
			if (node->nexts[index] == nullptr){//如果还没有节点，创建一个节点
				node->nexts[index] = new TrieNode();
			}
			node = node->nexts[index];
			node->path++;//path增加1
		}
		node->end++;//word插入结束后最后一个node的end加一
	}


	//返回一个word出现了几次
	int search(string word){
		if (word.empty()){
			return 0;
		}
		int length = word.length();
		char *a = new char[length];
		strcpy(a, word.c_str());
		TrieNode *node = root;
		int index = 0;
		for (int i = 0; i < length; i++){
			index = a[i] - 'a';
			if (node->nexts[index] == nullptr){
				return 0;
			}
			node = node->nexts[index];
		}
		return node->end;//返回这个word出现了几次
	}


	void _delete(string word){
		if (search(word) != 0){
			int length = word.length();
			char *a = new char[length];
			strcpy(a, word.c_str());
			TrieNode *node = root;
			int index = 0;
			for (int i = 0; i < length; i++){
				index = a[i] - 'a';
				if (--node->nexts[index]->path == 0){//如果path==0，后边直接删除就行  否则，path减一
					node->nexts[index] = nullptr;
					return;
				}
				node = node->nexts[index];
			}
			node->end--;

		}
	}

};

//int main(){
//	
//	Trie *test=new Trie();
//	cout << test->search("peng") << endl;
//	test->insert("peng");
//	test->insert("peng");
//	cout << test->search("peng") << endl;
//	test->_delete("peng");
//	cout << test->search("peng") << endl;
//}

 

//拼接字符串，使新字符串有最低的字典序
 


//切金条——贪心策略
//算法思想：
/*基于哈夫曼编码的思想，
(1) 首先构造小根堆
(2) 每次取最小的两个数（小根堆），使其代价最小。并将其和加入到小根堆中
(3) 重复(2)过程，直到最后堆中只剩下一个节点
注意：代价不是最后一个值，而是所有非叶结点之和，即上面求得两两个结点之和
*/



//函数对象（function object）又叫做仿函数
//其实就是重载了operator（）操作符的struct或class
struct cmp{
	bool operator()(int &a, int &b){
		return a > b; //第一个元素大于第二个元素，返回真时； 对应的是小根堆，升序！
	}
};

int lessMoney(int arr[], int length){
 	priority_queue<int, vector<int>, cmp> pQ;   //priority_queue<Type, Container, Functional>
	                                            //Type为数据类型， Container为保存数据的容器，Functional为元素比较方式
	for (int i = 0; i < length; i++){
		pQ.push(arr[i]);//建立小根堆
	}
	int sum = 0;
	int cur = 0;
	while (pQ.size()>1){
		int top1 = pQ.top();
		pQ.pop();
		int top2 = pQ.top();
		pQ.pop();
		cur = top1 + top2;
		sum += cur;
		pQ.push(cur);
	}
	return sum;
}

//int main()
//{
//	int arr[5] = { 10, 5, 7,11,9 };
//	int length = 5;
//	cout << lessMoney(arr, length) << endl;
//	
//}




//做项目，不同项目启动资金和收益不同，求最后获得的最大钱数
//两个堆，成本组成小根堆，收益组成大根堆
//每次从成本堆里拿出成本最小的项目放入收益堆里，再从收益堆里取收益最大的项目，直到达到项目最大值或当前成本不足以启动项目



class IPONode{
public:
	int p;//收益
	int c;//启动资金
	IPONode();
	IPONode(int p,int c){
		p = p;
		c = c;

	}
};

class  cmpMinCost{  //花费按小根堆排列
public:
	bool operator()(IPONode &a, IPONode &b){
		return a.c > b.c; //第一个元素大于第二个元素，返回真时； 对应的是小根堆，升序！
	}
};
class cmpMaxProfit{ //收益按大根堆排列
public:
	bool operator()(IPONode &a, IPONode &b){
		return a.p < b.p; //第一个元素大于第二个元素，返回真时； 对应的是小根堆，升序！
	}
};
class IPO{
public:
	int findMaxCapital(int k, int w, int profits[], int captial[],int length){ //w为现有总钱数 k为项目数量
		IPONode *nodes = new IPONode[length];//注意此处写法
		for (int i = 0; i < length; i++){
			nodes[i] = IPONode(profits[i], captial[i]);


		}
		priority_queue<IPONode, vector<IPONode>, cmpMinCost> minCostQ;
		priority_queue<IPONode, vector<IPONode>, cmpMaxProfit> maxProfitQ;
		for (int i = 0; i < length; i++){
			minCostQ.push(nodes[i]);
		}
		for (int i = 0; i < k; i++){
			while (!minCostQ.empty() && minCostQ.top().c <= w){//每个项目的成本不能超过要求的成本
				maxProfitQ.push(minCostQ.top());
				minCostQ.pop();
			}
			if (maxProfitQ.empty()){
				return w;
			}
			w += maxProfitQ.top().p;//完成项目后的资本变为原始资本加上利润
			maxProfitQ.pop();
		}
		return w;

	}

};



//安排会议室，返回能举办的最多的场次数
//按结束时间最早的安排
class Program{
public:
	int start;
	int end;
	Program();
	Program(int start, int end){
		start = start;
		end = end;
	}
	
};

class  cmpMinEnd{  //花费按小根堆排列
public:
	bool operator()(Program &a, Program &b){
		return a.end > b.end; //第一个元素大于第二个元素，返回真时； 对应的是小根堆，升序！
	}
};


class BestArrange{
public:
	int bestArrange(Program programs[], int start,int length){
		//先对数组按结束时间从小到大排序
		priority_queue<Program, vector<Program>, cmpMinEnd> minEnd;
		Program cur;
		for (int i = 0; i < length; i++){
			minEnd.push(programs[i]);//将所有项目按结束时间组成小根堆
		}

		

		int result = 0;//计数
		for (int i = 0; i < length; i++){
			cur = minEnd.top();
			if (start <= cur.start){ //如果开始时间<=当前项目的开始时间，则可以开始
				result++;
				start = cur.end;
				minEnd.pop();
			}
			else{
				minEnd.pop();

			}
		}
		return result;
		
		
	}

};



//递归
//求n!
class Factorial
{
public:
	//非递归版本
	int function1(int n){
		int result = 1;
		for (int i = 1; i <= n; i++){
			result *= i;

		}
		return result;
	}

	//递归版本
	int function2(int n){
		if (n == 1){
			return 1;
		}
		return n*function2(n - 1);
	}
};

//int main()
//{
//	int n = 10;
//	Factorial test;
//	cout<<test.function1(n)<<endl;
//	cout << test.function2(n) << endl;
//}


 //汉诺塔问题
//从上到下为1：N

void process(int N, string from, string to, string help){
	if (N == 1){
		cout << "move 1 from " << from << " to " << to << endl; //第三步，如果只剩下最后一个，从左移动到右
	}
	else{
		process(N - 1, from, help, to);//第一步：1：N-1 从左到中 此时借助的是右杆
		cout << "move "<<N<<" from " << from << " to " << to << endl;
		process(N - 1, help, to, from);//第三步：1：N-1从中杆到右杆，此时，借助的是左杆
	}
}

//int main()
//{
//	process(3, "左", "右", "中");
//}




//打印一个字符串的全部子序列，包括空字符串
//对于字符串，每个位置有两种情况：包含此位置；不包含此位置
//

void printAllSub(char str[], int i, string res){//i:当前数组的位置
	//int length = sizeof(str) ;//得到数组的长度 两种方式  此种方式得不到正确长度，永远为4  因为传递过来的只是数组的首位置指针
	int length = strlen(str);//此方法正确，但是数组只能使用字符串初始化 因为只有字符串才以'\0'结尾
	if (i == length){
		cout << res << endl;
		return;
	}
	printAllSub(str, i + 1, res);  //不包含此位置，此时res的值不变，走到下一个位置，同样分为两种情况
	printAllSub(str, i + 1, res + str[i]);//包含此位置，此时res的值加上此位置的值，走到下一个位置，同样分为两种情况


}

//int main(){
//	//char a[] = { 'a', 'b', 'c','d','e' };
//	char a[] = "abcdefghi";
//	int length1 = sizeof(a);
//	//int length2 = strlen(a);//strlem必须对用字符串数组形式，以‘\0结尾’
//	printAllSub(a, 0, "");
//}



//最小路径问题
//暴力递归 
int walk1(vector<vector<int>>matrix, int i, int j){//i:当前行数 j:当前列数
	if (i == matrix.size()-1 && j == matrix[0].size()-1){//已经到达最右下角位置
		return matrix[i][j];
	}
	if (i == matrix.size()-1){//到达了最后一行，只能往右走
		return matrix[i][j] + walk1(matrix, i, j + 1);
	}
	if (j == matrix[0].size()-1){//到达了最后一列，只能往下走
		return matrix[i][j] + walk1(matrix, i + 1, j);
	}

	int right = walk1(matrix, i, j + 1);//往右走，到右下角的最短路径和  枚举
	int down = walk1(matrix, i + 1, j);//往下走 到右下角的最短路径和
	return matrix[i][j] + min(right, down);//选择长度最短的路径
}


//动态规划
//递归时有重复状态  无后效性问题 （之前选择的不会影响后续）
//先根据basecase   再找普通位置










//int main()
//{
//	vector<vector<int>>a = { { 1, 3, 2, 9 }, { 8, 1, 3, 0 }, { 5, 0, 6, 1 }, { 8, 8, 4, 0 } };
//	cout << walk1(a, 0, 0) << endl;
//}



//给你一个数组arr，和一个整数aim。如果可以任意选择arr中的
//数字，能不能累加得到aim

bool sumIsaim(int a[], int length,int i,int sum,int aim){//数组 长度 当前位置 和 目标
	if (sum == aim ){//如果相等，返回true
		return true;
	}
	if (i == length){
		return false;
	}
	return sumIsaim(a, length, i + 1, sum , aim) || sumIsaim(a, length, i+1, sum+a[i],aim);
	
	
}

//int main()
//{
//	int a[3] = { 1, 2, 3 };
//	int length = 3;
//	int aim = 5;
//	cout << sumIsaim(a, 3, 0, 0, 5)<<endl; 
//}



//剑指1 赋值运算符
//注意：构造函数只在对一个未存在的对象初始化的时候使用，
//而拷贝赋值针对的是已经存在的对象进行初始化

class CMyString{
public:
	CMyString(char* pData = nullptr);
	
	CMyString(const CMyString& str);//如果构造函数的第一个参数是自身类型的引用，且任何额外的参数都有默认值，
	                                //此构造函数为拷贝构造函数
	~CMyString(void);
	CMyString& operator = (const CMyString& str);//拷贝赋值运算符

	void Print();
private:
	char* m_pData;
};


//构造函数
CMyString::CMyString(char* pData){
	if (pData == nullptr){
		m_pData = new char[1];
		m_pData[0] = '\0';
	}

	else{
		int length = strlen(pData);//strlen() 计算字符串的长度，以\0'为字符串结束标记。
		m_pData = new char[length + 1];
		strcpy(m_pData, pData);
	}
}

//拷贝构造函数
CMyString::CMyString(const CMyString &str)
{
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
	//m_pData = str.m_pData;
}

//析构函数
CMyString::~CMyString()
{
	delete[] m_pData;
}



//运算符重载有三种写法 可类外定义；  在类内只能有一个参数，作为成员函数时，*this即为左操作数；  类内作为友元函数

//拷贝赋值运算符
CMyString& CMyString::operator=(const CMyString &str){

	if (this == &str){  //如果是同一个实例，不用赋值，不能释放内存，因为传入的内存和释放的内存是同一个
		return *this;
	}
	delete[]m_pData;  //分配新内存前释放自身已有的内存
	m_pData = nullptr;

	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
	return *this;
}

void CMyString::Print()
{
	cout<<m_pData<<endl;
}



//int main()
//{
//	char *testChar = "abc";
//	CMyString test1(testChar), test2(testChar);//直接初始化
//	CMyString test4 = test2;//拷贝初始化，使用拷贝构造函数
//	CMyString test3 = "aaa";//拷贝初始化，使用的是拷贝构造函数,此时会进行隐式的类型转换，虽然拷贝构造函数接受CMyString,
//	                        //但仍可以使用string类型进行拷贝初始化。C++ primer p263
//	
//	test4 = test3;//已经存在的对象,使用拷贝赋值运算符
//
//	test1.Print();
//	test2.Print();
//	test3.Print();
//	test4.Print();
//
//	//连续赋值
//	CMyString test5, test6;
//	test5 = test6 = test2;
//	test5.Print();
//	test6.Print();
//}




//class TestClass{
//public:
//	TestClass(int data) :a(data){}
//private:
//	int a;
//};
//
//int main()
//{
//	TestClass a(5);
//	int data = 5;
//	
//}



////指针和引用测试
//int main()
//{
//	int a = 5;
//	int &f = a;//f时对a的引用，引用即别名
//	int *g = &f;//此时&是取地址符
//	int *b = &a;//*紧随类型名出现，表示指针，存放的是a的地址，指向a
//	int c = *b;  //*出现在表达式，表示解引用。得到指针指向对象的值
//	int *d = nullptr;
//	d = b;//赋值，改变了d指针的值，d指针指向了和b一样的位置。
//	*d = 7;//使用*解引用，改变了d指针指向的对象的值
//	cout << &a << endl;//a的地址
//	cout << a << endl;//a的值
//	cout << &b << endl;//b指针本身的地址
//	cout << *b << endl;//解引用b得到的b里存放的地址对应的对象的值
//	cout << b << endl;//b中存放的a的地址
//	cout << c << endl;
//	cout << d << endl;
//	cout << f << endl;
//	cout << g << endl;
//	cout << *g << endl;
//	
//}
//sizeof()测试

//int GetSize(char data[])
//{
//	return sizeof(data);
//}
//int main()
//{
//	char data1[] = { 1, 2, 3, 4,5 };
//	int size1 = sizeof(data1);
//	char *data2 = data1;
//	int size2 = sizeof(data2);
//	int size3 = GetSize(data1);
//	cout << size1 << endl;
//	cout << size2 << endl;
//	cout << size3 << endl;
//}





//剑指3 找出数组中的重复数字
bool duplicate(int numbers[], int length, int* duplication) {
	//方法三 先排序，再找重复数字
	//冒泡排序O（n）=n2
	if (numbers == nullptr || length <= 0)
		return false;
	for (int i = 0; i < length; ++i){
		if (numbers[i]<0 || numbers[i]>length - 1)
			return false;
	}

	for (int i = length-1; i >0 ; i--)
	{
		for (int j = 0; j < i; j++){
			if (numbers[j ] > numbers[j+1]){
				int temp = numbers[j +1];
				numbers[j +1] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
	for (int i = 0; i < length; i++)
	{
		cout << numbers[i] << ' ';
	}
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] == numbers[i + 1]){
			*duplication = numbers[i];
			return true;
		}
		
	}
	return false;
}

	//方法一
	/*if (numbers == nullptr || length <= 0)
		return false;
	for (int i = 0; i < length; ++i){
		if (numbers[i]<0 || numbers[i]>length - 1)
			return false;
	}
	for (int i = 0; i < length; i++){
		while (numbers[i] != i){
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}

			int temp = numbers[i];
			numbers[i] = numbers[temp];
			numbers[temp] = temp;
		}
	}
	return false;*/

	//方法二：
	/*if (numbers == nullptr || length <= 0)
		return false;
	for (int i = 0; i < length; ++i){
		if (numbers[i]<0 || numbers[i]>length - 1)
			return false;
	}
	int *hashmap = new int[length - 1];
	for (int i = 0; i < length; i++)
	{
		if (hashmap[numbers[i]] == 1){
			*duplication = numbers[i];
			return true;

		}
		hashmap[numbers[i]] = 1;
		

	}
	return false;
}*/


// ====================测试代码====================
bool contains(int array[], int length, int number)
{
	for (int i = 0; i < length; ++i)
	{
		if (array[i] == number)
			return true;
	}

	return false;
}
void test(char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
	printf("%s begins: ", testName);

	int duplication;
	bool validInput = duplicate(numbers, lengthNumbers, &duplication);

	if (validArgument == validInput)
	{
		if (validArgument)
		{
			if (contains(expected, expectedExpected, duplication))
				printf("Passed.\n");
			else
				printf("FAILED.\n");
		}
		else
			printf("Passed.\n");
	}
	else
		printf("FAILED.\n");
}

// 重复的数字是数组中最小的数字
void test1()
{
	int numbers[] = { 2, 1, 3, 1, 4 };
	int duplications[] = { 1 };
	test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 重复的数字是数组中最大的数字
void test2()
{
	int numbers[] = { 2, 4, 3, 1, 4 };
	int duplications[] = { 4 };
	test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 数组中存在多个重复的数字
void test3()
{
	int numbers[] = { 2, 4, 2, 1, 4 };
	int duplications[] = { 2, 4 };
	test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 没有重复的数字
void test4()
{
	int numbers[] = { 2, 1, 3, 0, 4 };
	int duplications[] = { -1 }; // not in use in the test function
	test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 没有重复的数字
void test5()
{
	int numbers[] = { 2, 1, 3, 5, 4 };
	int duplications[] = { -1 }; // not in use in the test function
	test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test6()
{
	int* numbers = nullptr;
	int duplications[] = { -1 }; // not in use in the test function
	test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}

//void main()
//{
//	test1();
//	test2();
//	test3();
//	test4();
//	test5();
//	test6();
//}


//剑指 3.2 不修改数组找出重复的数字
//int countRange(const int* numbers, int length, int start, int end){
//	if (numbers == nullptr)
//		return 0;
//	int count = 0;
//	for (int i = 0; i < length; i++)
//	{
//		if (numbers[i] >= start&&numbers[i] <= end)
//			count++;
//	}
//	return count;
//
//}
//
//
//
//
//
//
//int getDuplication(const int* numbers, int length){
//	if (numbers == nullptr || length <= 0)
//		return -1;
//	int start = 1;
//	int end = length -1;
//	while (end >= start){
//		int middle = ((start + end) / 2)+start;
//		int count = countRange(numbers, length,start, end);
//		if (end == start){
//			if (count > 1)
//				return start;
//			else
//				break;
//		}
//		if (count > (middle - start + 1))
//			end = middle;
//		else
//			start = middle + 1;
//	}
//	return -1;
//
//}


//int main()
//{
//	char str1[] = "hello";
//	char str2[] = "hello";
//	char *str3 = "hello";
//	char *str4 = "hello";
//	if (str1 == str2)
//		cout << "str1 and str2 are same" << endl;
//	else
//		cout << "not same" << endl;
//}


//剑指5 替换空格


/*length 为字符数组str的总容量，大于或等于字符串str的实际长度*/
void ReplaceBlank(char str[], int length)
{ 
	if (str == nullptr || length <= 0){
		return;
	}
	int i = 0;
	int size = 0;//统计字符串长度
	int num = 0;//统计空格数量
	while (str[i] != '\0'){
		size++;
		if (str[i] == ' '){
			num++;
		}
		i++;
		
	}

	int newStrIndex = size + num * 2;
	int oldStrIndex = size;
	while (oldStrIndex >= 0 && newStrIndex > oldStrIndex){
		if (str[oldStrIndex] == ' '){
			str[newStrIndex--] = '0';
			str[newStrIndex--] = '2';
			str[newStrIndex--] = '%';
		}
		else
			str[newStrIndex--] = str[oldStrIndex];
		oldStrIndex--;
	}
}

// ====================测试代码====================
void Test(char* testName, char str[], int length, char expected[])
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	ReplaceBlank(str, length);

	if (expected == nullptr && str == nullptr)
		printf("passed.\n");
	else if (expected == nullptr && str != nullptr)
		printf("failed.\n");
	else if (strcmp(str, expected) == 0)
		printf("passed.\n");
	else
		printf("failed.\n");
}

// 空格在句子中间
void Test1()
{
	const int length = 100;

	char str[length] = "hello world";
	Test("Test1", str, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
	const int length = 100;

	char str[length] = " helloworld";
	Test("Test2", str, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
	const int length = 100;

	char str[length] = "helloworld ";
	Test("Test3", str, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
	const int length = 100;

	char str[length] = "hello  world";
	Test("Test4", str, length, "hello%20%20world");
}

// 传入nullptr
void Test5()
{
	Test("Test5", nullptr, 0, nullptr);
}

// 传入内容为空的字符串
void Test6()
{
	const int length = 100;

	char str[length] = "";
	Test("Test6", str, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
	const int length = 100;

	char str[length] = " ";
	Test("Test7", str, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
	const int length = 100;

	char str[length] = "helloworld";
	Test("Test8", str, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
	const int length = 100;

	char str[length] = "   ";
	Test("Test9", str, length, "%20%20%20");
}

//int main(int argc, char* argv[])
//{
//	Test1();
//	Test2();
//	Test3();
//	Test4();
//	Test5();
//	Test6();
//	Test7();
//	Test8();
//	Test9();
//
//	return 0;
//}


// 剑指5-2 两个有序数组合并

void merge(int arr1[], int arr2[], int length1, int length2){
	int length = length1 + length2 - 1;
	length1--;
	length2--;

	while (length1 >= 0 && length2 >= 0){
		if (arr1[length1] > arr2[length2]){
			arr1[length--] = arr1[length1--];
		}
		else
			arr1[length--] = arr2[length2--];
		
	}
	
	while (length2 >= 0)//array2还有剩余值，此时array1已经比较完，直接将array2搬过去
	{
		arr1[length--] = arr2[length2--];
	}


}

//int main()
//{
//	int arry2[] = { 1, 2, 3, 4 };
//	int arry1[8] = { 5, 6, 7, 8 };
//	int length1 = 4;
//	int length2 = 4;
//	merge(arry1, arry2, 4, 4);
//	for (int i = 0; i <8; i++)
//	{
//		cout << arry1[i] << ',' << endl;
//	}
//}


//剑指6 从尾到头打印链表



//核心代码 
//方法一 栈
void PrintListReversingly_Iteratively(ListNode* pHead)
{
	std::stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d\t", pNode->m_nValue);
		nodes.pop();
	}
}

//方法二：递归
void PrintListReversingly_Recursively(ListNode* pHead)
{
	if (pHead != nullptr)
	{
		if (pHead->m_pNext != nullptr)
		{
			PrintListReversingly_Recursively(pHead->m_pNext);
		}

		printf("%d\t", pHead->m_nValue);
	}
}

// ====================测试代码====================
void Test(ListNode* pHead)
{
	PrintList(pHead);
	PrintListReversingly_Iteratively(pHead);
	printf("\n");
	PrintListReversingly_Recursively(pHead);
}

// 1->2->3->4->5
void Test61()
{
	printf("\nTest1 begins.\n");

	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1);

	DestroyList(pNode1);
}

// 只有一个结点的链表: 1
void Test62()
{
	printf("\nTest2 begins.\n");

	ListNode* pNode1 = CreateListNode(1);

	Test(pNode1);

	DestroyList(pNode1);
}

// 空链表
void Test63()
{
	printf("\nTest3 begins.\n");

	Test(nullptr);
}

//int main(int argc, char* argv[])
//{
//	Test61();
//	Test62();
//	Test63();
//
//	return 0;
//}



 
//剑指7 重建二叉树
BinaryTreeNode* constructCore(vector<int> pre, int startPre, int endPre, vector<int>vin, int startVin, int endVin){
	 if (startPre>endPre || startVin>endVin)
		 return nullptr;
	 BinaryTreeNode *root = new BinaryTreeNode();//前序序列第一个数字是根节点的值
	 root->m_nValue = pre[startPre];
	 root->m_pRight = root->m_pLeft = nullptr;
	 for (int i = startVin; i <= endVin; i++)
	 {
		 if (vin[i] == pre[startPre]){
			 root->m_pLeft = constructCore(pre, startPre + 1, startPre + i - startVin, vin, startVin, i - 1);
			 root->m_pRight = constructCore(pre, i - startVin + startPre + 1, endPre, vin, i + 1, endVin);
			 break;

		 }
		 
	 }
	 return root;
 }
BinaryTreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {

	return constructCore(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);

}



//int main()
//{
//	vector<int>a = { 1, 2, 4, 7, 3, 5, 6,8 };
//	vector<int>b = { 4, 7, 2, 1, 5, 3, 8,6 };
//	BinaryTreeNode* result = reConstructBinaryTree(a, b);
//	PrintTree(result);
//}