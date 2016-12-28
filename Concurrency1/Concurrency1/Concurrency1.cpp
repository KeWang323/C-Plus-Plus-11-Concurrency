// Concurrency1.cpp : 定义控制台应用程序的入口点。
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

