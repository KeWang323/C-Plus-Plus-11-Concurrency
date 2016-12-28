// Concurrency3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<chrono>
#include<iostream>
#include<thread>

using namespace std;

void thread_task(int n) {
	this_thread::sleep_for(chrono::seconds(n));
	cout << "Hello Concurrency" 
		<< this_thread::get_id()
		<< " paused " << n << " seconds" << endl;
}

int main()
{
	thread threads[6];
	cout << "6 threads created..." << endl;
	for (int i = 0; i < 6; i++) {
		threads[i] = thread(thread_task, i + 1);
	}
	for (auto& t : threads) {
		t.join();
	}
	cout << "All threads joined." << endl;
    return 0;
}

