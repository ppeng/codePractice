// codePractice.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//�麯��ʹ�� ���ӣ�https://www.nowcoder.com/questionTerminal/3cea911c23a043ae96f0767d42bfa4f2


class Base {
public:
	Base() { echo(); }
	virtual void echo() { printf("Base"); }
};

class Derived :public Base {
public:
	Derived() { echo(); }
	virtual void echo() { printf("Derived"); }
};

int main() {
	Base* base = new Derived();
	base->echo();
	return 0;
}


