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


//ʵ�ֶ��������������򡢺�������������ݹ鷽ʽ�ͷǵݹ鷽ʽ
//����������ȵ�ǰ�ڵ㣬�ٴ�ӡ���������ٴ�ӡ������
//����������ȴ�ӡ���������ٴ�ӡ��ǰ���ٴ�ӡ������
//�����������ȴ�ӡ���������ٴ�ӡ���������ǰ�ڵ�
//���������
class Node{
public:
	int value;
	Node *left;//ǰ������������߽ṹ��ֻ����������ָ��������á� 
	           //������ָ�롣����ָ�����ͨ������������ͨ������ָ���һֱ������ȥ����ɶ�ջ���
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
	//�ݹ�汾

	//�����ӡ
	void printPreOrderRecur(Node *head){
		if (head == nullptr){
			return;
		}
		cout << head->value << " ";
		printPreOrderRecur(head->left);
		printPreOrderRecur(head->right);
	}
	//�����ӡ
	void printInOrderRecur(Node *head){
		if (head == nullptr){
			return;
		}
		printInOrderRecur(head->left);
		cout << head->value << " ";
		printInOrderRecur(head->right);

	}
	//�����ӡ
	void printPosOrderRecur(Node *head){
		if (head == nullptr){
			return;
		}
		printInOrderRecur(head->left);
		printInOrderRecur(head->right);
		cout << head->value << " ";
	}


	//�ǵݹ��***********************//

	//�����ӡ �ǵݹ� ʹ��ջ 
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


	//�����ӡ  �ǵݹ� ʹ��ջ 
	//��ǰ�ڵ�Ϊ�գ���ջ�ó���ӡ������ǰ�ڵ����ң�����ǰ�ڵ���ջ����ǰ�ڵ�����
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

	//�����ӡ  ��ǰ�����ƣ����ų� �����󣬷��븨��ջ�У������ջ��Ԫ�� ���Ϊ �� �� ��
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
//	cout << "�����ӡ1��" << endl;
//	test.printPreOrderRecur(head);
//	cout << endl;
//	cout << "�����ӡ2��" << endl;
//	test.printPreOrderUnRecur(head);
//	cout << endl;
//	cout << "�����ӡ1��" << endl;
//	test.printInOrderRecur(head);
//	cout << endl;
//	cout << "�����ӡ2��" << endl;
//	test.printInOrderRecur(head);
//	cout << endl;
//	cout << "�����ӡ1��" << endl;
//	test.printPosOrderUnRecur(head);
//	cout << endl;
//	cout << "�����ӡ2��" << endl;
//	test.printPosOrderUnRecur(head);
//
//
//}


//�ڶ��������ҵ�һ���ڵ�ĺ�̽ڵ�
//��̽ڵ㣺���������������һ���ڵ����һ���ڵ�

//�������˳��Ϊ������   ���Ժ�̽ڵ�ֻ���ע�ýڵ��Ƿ���������   

//һ���ڵ�����������������̽ڵ�Ϊ��������������ڵ�
//���û��������  ��һ·���ϣ��ҵ����ڵ���������Ǹýڵ�ĵ㣩

class specialNode{
public:
	int value;
	specialNode *left;//ǰ������������߽ṹ��ֻ����������ָ��������á� 
	//������ָ�롣����ָ�����ͨ������������ͨ������ָ���һֱ������ȥ����ɶ�ջ���
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
		else if (Node->right != nullptr){//����ڵ�������������ô�ýڵ�ĺ�̿϶�������������������ڵ�
			return getLeftNode(Node->right);

		}
		else{//���û�����������˽ڵ�ĺ�̿϶������� һֱ�����ң�ֱ���ڵ��븸�ڵ����ڵ����
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



//�����������л��ͷ����л�

//���л��������ö�����
//�����л����ָ�
class SerializeAndReconstructTree{
public:

	//ǰ�� ���л��ͷ����л� �ݹ鷽ʽ
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

	//�����л� �ݹ鷽ʽ
	//���õ����ַ����ָ�ú�װ�����
	Node* reconByPreString(string prestr){
		queue<string>*q;
		size_t firPos = 0;
		size_t secPos = 0;

		secPos = prestr.find("!");//�ҵ��ָ���
		while (secPos!=string::npos)
		{
			q->push(prestr.substr(firPos, secPos - firPos));//��ȡ��ָ������ʼλ�ÿ�ʼ������ΪsecPos-firPos�����ַ���
			firPos = secPos + 1;
			secPos = prestr.find("!", firPos);//�ҵ�����λ�ã��Ҳ�������npos
		}
		return reconPreOrder(q);//���õݹ麯�����õ���������ͷ

	}

	//�ݹ麯�����������ɶ�����
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




