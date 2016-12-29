// Concurrency4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

volatile int counter(0);
mutex mtx;

void attemp_10k_increase() {
	for (int i = 0; i < 10000; i++) {
		if (mtx.try_lock()) {
			counter++;
			mtx.unlock();
		}
	}
}

int main()
{
	thread threads[10];
	for (int i = 0; i < 10; i++) {
		threads[i] = thread(attemp_10k_increase);
	}
	for (auto& t : threads) {
		t.join();
	}
	cout << counter << " successful increases of the counter." << endl;

	return 0;
}

