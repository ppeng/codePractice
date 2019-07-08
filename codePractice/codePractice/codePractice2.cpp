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
		char *a=new char[length];
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

int main(){
	
	Trie *test=new Trie();
	cout << test->search("peng") << endl;
	test->insert("peng");
	test->insert("peng");
	cout << test->search("peng") << endl;
	test->_delete("peng");
	cout << test->search("peng") << endl;


}