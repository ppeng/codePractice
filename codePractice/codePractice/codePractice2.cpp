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

	//前序 序列化和反序列化 递归方式
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

	//反序列化 递归方式
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
};

int main()
{
	SerializeAndReconstructTree test;
	Node *head = new Node(5);
	head->left = new Node(3);
	head->right = new Node(8);
	head->left->left = new Node(2);
	head->left->right = new Node(4);
	head->left->left->left = new Node(1);
	head->right->left = new Node(7);
	head->right->left->left = new Node(6);
	head->right->right = new Node(10);
	head->right->right->left = new Node(9);
	head->right->right->right = new Node(11);
	string result = test.serialByPre(head);
	cout << result << endl;
	
}




