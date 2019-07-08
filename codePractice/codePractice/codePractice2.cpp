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

	//ǰ�� ���л� �ݹ鷽ʽ
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
	//ǰ�����л� �ݹ鷽ʽ
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


	//�������л� 
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

	//���㷴���л�
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

		secPos = levelStr.find("!");//�ҵ��ָ���
		while (secPos != string::npos)
		{
			q->push(levelStr.substr(firPos, secPos - firPos));//��ȡ��ָ������ʼλ�ÿ�ʼ������ΪsecPos-firPos�����ַ���
			firPos = secPos + 1;
			secPos = levelStr.find("!", firPos);//�ҵ�����λ�ã��Ҳ�������npos
		}
		queue<Node*>*qNode = new queue<Node*>;//�洢�����ɵĽڵ�
		Node *root = generateNodeByString(q->front());
		q->pop();
		if (nullptr != root){
			qNode->push(root);
		}
		Node *node = nullptr;
		while (!qNode->empty()){  //������˳���ó��ڵ㣬���������ҽڵ㣬�������ҽڵ������
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


//ƽ������������������߶Ȳ����һ
//�ݹ�

class ReturnData{//����ֵ��
public:
	bool isBalance;//�Ƿ�ƽ��
	int h;//�������ĸ߶�
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
	if (!leftData->isBalance){//������ƽ�⣬ֱ�ӷ���false
		return new ReturnData(false, 0);
	}
	ReturnData *rightData = process(head->right);
	if (!rightData->isBalance){//���������ƽ�⣬ֱ�ӷ���false
		return new ReturnData(false, 0);
	}

	if (abs(leftData->h - rightData->h) > 1){//����������ֵ����1������false
		return new ReturnData(false, 0);
	}

	return new ReturnData(true, max(leftData->h, rightData->h) + 1);//�������������ֵ������1 �����������������߶ȼ����Լ��ĸ߶�1

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



//���������� ÿ���ڵ����������������ڵ�󣬶��ұ���������������ڵ�С
//������������������Ϊ������Ϊ����������

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
			return false;//�����ߵ���С��ǰ�ߵ���������false
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



//��ȫ������(Complete Binary Tree)�� ��������������Ϊh������ h ���⣬�������� (1��h-1) �Ľ�������ﵽ���������� h �����еĽ�㶼���������������
//�����ǰ�ڵ����Һ���û�����ӣ�ֱ�ӷ���false
//�����ǰ�ڵ�ֻ�����ӣ���ô֮�����еĽڵ㶼ΪҶ�ڵ㣨��Ϊ��Ľڵ㣩�����򷵻�false

bool isCBT(Node *head){
	queue<Node*>q;
	q.push(head);
	bool leaf = false;//�ڶ�������ı�־�����ֻ�����ӣ�û���Һ��ӣ�����������нڵ㶼�������κκ���
	while (!q.empty()){
		head = q.front();
		q.pop();
		if (head->left == nullptr&&head->right != nullptr){//���ֻ���ҽڵ�û����ڵ㣬����false
			return false;
		}
		if (leaf && (head->left != nullptr || head->right != nullptr)){//��������˵ڶ���������������Һ�����һ�����ǿ�
			return false;
		}
		if (head->left != nullptr){
			q.push(head->left);
		}
		if (head->right != nullptr){
			q.push(head->right);
		}
		else{//����Һ��ӵ��ڿգ����־��Ϊtrue
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



//��֪һ����ȫ������������ڵ�ĸ���
//Ҫ��ʱ�临�Ӷȵ���O(N)��NΪ������Ľڵ����
//���������ҪO��N��

//�ݹ����
//�����������ȫ������������������ڵ��ܵ������һ�㣬˵������������Ϊ�������ù�ʽ����������ڵ������ݹ����������ڵ���
//������ܵ������һ�㣬˵������������Ϊ�������ù�ʽ����������ڵ������ٵݹ����������ڵ���
//O((logN)^2)=O(h^2)������ƽ��  ÿһ��ֻ��ѡ��һ���ڵ����bs�ݹ飬���Ե���bs�����Ĵ���ΪO��h��,
//ÿ�ε���bs����������鿴node������������ڵ㣬���Ի��ٱ���O��h�����ڵ㡣

//�������ĸ߶�
int mostLeftLevel(Node *node, int level){
	while (node != nullptr){
		level++;
		node = node->left;
	}
	return level - 1;

}
int bs(Node *node, int level, int h){//level:ͷ�ڵ����ڲ���   h:��ǰ�����ܸ߶�  ���ֵ�ǹ̶��� ��Ϊ���е�level���㶼�Ǽ�����������ϵĲ�
	if (level == h){//����ܸ߶Ⱥ͵�ǰ�ڵ����ڲ�����ȣ��ܹ���һ���ڵ�
		return 1;
	}

	if (mostLeftLevel(node->right, level+1) == h){//��һ�������������������ڵ��������������һ��
		return(1 << (h - level)) + bs(node->right, level + 1, h);//�ݹ�

	}
	else{//�ڶ������
		return(1 << (h - level - 1)) + bs(node->left, level + 1, h);  //ע��()λ��  +�����ȼ���<<���������Ʋ�����()������

	}


}

int nodeNum(Node *head){//��ڵ����������
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



// ��ϣ������������������������ ������һ�������һ�������벻һ�����������һ������ϣ��ײ����������ֵ���ȷֲ�



//���RandomPool�ṹ
//���һ�ֽṹ���ڸýṹ���������������ܣ�
//insert(key)����ĳ��key���뵽�ýṹ���������ظ����롣
//delete(key)����ԭ���ڽṹ�е�ĳ��key�Ƴ���getRandom()��
//�ȸ���������ؽṹ�е��κ�һ��key��
//Ҫ��Insert��delete��getRandom������ʱ�临�Ӷȶ���O(1)

template<typename T>//ģ������б�
class RandomPool{
public:
	hash_map<T, int>keyIndexMap;
	hash_map<int, T>indexKeyMap;
	int size;
	RandomPool(){
		srand((unsigned int)time(NULL));//�������������ʼ���� ��ϵͳʱ��Ϊ����
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
		int index = keyIndexMap[key];//��¼����Ҫɾ����key��index
		int lastindex = --size;
		T lastkey = indexKeyMap[lastindex];//��¼���һ��key
		keyIndexMap[lastkey] = index;//�����һ��key��ֵ����ΪҪɾ����key��index
		indexKeyMap[index] = lastkey;//��Ҫɾ����index����ֵ����Ϊ���һ��index��ֵ
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
//	cout << "delete����:" << endl;
//	cout << rand.getRandom() << endl;
//	cout << rand.getRandom() << endl;
//	cout << rand.getRandom() << endl;
//	cout << rand.getRandom() << endl;
//	cout << rand.getRandom() << endl;
//	
//}


//��¡������ �����ж�ʧ����   ��ס��¡��������С���㹫ʽ ��ϣ�����������㹫ʽ ��ʵʧ���ʼ��㹫ʽ



// ���鼯

//�ȶ���ڵ�
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
////����!=�����  ���valueֵ����ȣ��򷵻�true 
////ע�⣬��������Լ����������Ҫ�Ƚϴ�С��Ҫ�������������
////���������������д�� �����ⶨ�壻  ������ֻ����һ����������Ϊ��Ա����ʱ��*this��Ϊ���������  ������Ϊ��Ԫ����
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
//	hash_map<UnionNode, UnionNode>fatherMap;//key--�ڵ�  value--father
//	hash_map<UnionNode, int>sizeMap;//ĳ�ڵ����ڼ��ϵ��ܽڵ���
//	UnionFind(list<UnionNode>nodes){
//		//��ʼ��
//		for (auto &node : nodes){
//			fatherMap[node] = node;//�׽ڵ�ָ���Լ�
//			sizeMap[node] = 1;//ÿ������ֻ��һ���ڵ㣬�ܽڵ�����1
//		}
//	}
//
//	//�ݹ�汾��father�ڵ�
//	UnionNode findHead(UnionNode node){//��father  ���ҵĹ����н�һ�������е�һ����ɶ�ָ��father�ڵ�
//		UnionNode father = fatherMap[node];
//		if (father != node){
//			father = findHead(father);//�ݹ�
//		}
//		fatherMap[node] = father;//���˼����е����нڵ�����Ϊһ��father
//		return father;
//
//	}
//	//�ǵݹ�汾��father�ڵ�
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
//	//�ж��ǲ���ͬһ����
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
//			if (aSetSize < bSetSize){//�������ٵĽڵ��ͷ�ҵ������������
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




//������

class Islands{
public:
	int contIslands(vector<vector<int>>m){
		if (m.empty() || m[0].empty()){//�����СΪ0
			return 0;
		}
		int N = m.size();//��
		int M = m[0].size();//��
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
	void infect(vector<vector<int>>&m, int i, int j, int N, int M){//ע�� ���Ҫ�ı�ԭ���ݣ�һ��������
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


//ǰ׺��  
class TrieNode{
public:
	int path; //������˽ڵ�Ĵ���
	int end;   //�Դ˽ڵ��β���ַ�������
	TrieNode *nexts[26];//·
	TrieNode(){
		path = 0; 
		end = 0;
		for (int i = 0; i < 26; i++){
			nexts[i] = nullptr;
		}
		//һ����26��·���������ͨ����nullptr���ͨ�˾��ǲ�Ϊ��
		//�����ֹ26��· ������Ƴ�hashmap����asic�������
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
			if (node->nexts[index] == nullptr){//�����û�нڵ㣬����һ���ڵ�
				node->nexts[index] = new TrieNode();
			}
			node = node->nexts[index];
			node->path++;//path����1
		}
		node->end++;//word������������һ��node��end��һ
	}


	//����һ��word�����˼���
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
		return node->end;//�������word�����˼���
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
				if (--node->nexts[index]->path == 0){//���path==0�����ֱ��ɾ������  ����path��һ
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