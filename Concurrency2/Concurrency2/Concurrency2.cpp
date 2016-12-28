// Concurrency2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<thread>
#include<chrono>
#include<functional>
#include<atomic>
#include<utility>
#include<iostream>


using namespace std;

void function1(int n) {
	for (int i = 0; i < 5; i++) {
		cout << "Thread 1 executing"<< endl;
		this_thread::sleep_for(chrono::milliseconds(10));
	}
}

void function2(int& n) {
	for (int i = 0; i < 5; i++) {
		cout << "Thread 2 executing" << endl;
		n++;
		this_thread::sleep_for(chrono::milliseconds(10));
	}
}

int main()
{
	int n = 0;
	thread t1;
	thread t2(function1, n + 1);
	thread t3(function2, ref(n));
	thread t4(move(t3));
	t2.join();
	t4.join();
	cout << "Final value of n is " << n << endl;
    return 0;
}

