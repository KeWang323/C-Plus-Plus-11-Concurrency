// Concurrency1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<thread>
using namespace std;

void hello() {
	cout << "Hello, Concurrency" << endl;
}
int main()
{
	thread t(hello);
	t.join();
	return 0;
}

