// Concurrency5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<chrono>
#include<thread>
#include<mutex>

using namespace std;

timed_mutex mtx;

void fireworks() {
	while (!mtx.try_lock_for(chrono::milliseconds(200))) {
		cout << "-";
	}

	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << "*" << endl;
	mtx.unlock();
}

int main()
{
	thread threads[10];
	for (int i = 0; i < 10; i++) {
		threads[i] = thread(fireworks);
	}
	for (auto& t : threads) {
		t.join();
	}
    return 0;
}

