﻿#include<iostream>
#include<vector>
#include<deque>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	vector<int>ticketnumber;
	int max = 0, min = 10000000;
	cout << "请输入购票者数量：";
	cin >> n;

	
	cout << "生成随机购票编号...\n";
	srand(static_cast<unsigned>(time(0))); // 随机种子
	for (int i = 0; i < n; ++i) {
		int current = rand() % 10000 + 1;
		ticketnumber.push_back(current); // 随机编号1到10000
	}
	cout << "购票者随机编号：";
	for (int num : ticketnumber) {
		cout << num << " ";
	}
	cout << endl;


	sort(ticketnumber.begin(), ticketnumber.end());//小到大排序
	deque<int> queue(ticketnumber.begin(), ticketnumber.end());
	// 模拟售票过程
	cout << "开始售票...\n";
	srand(static_cast<unsigned>(time(0))); // 随机种子

	while (!queue.empty()) {
		int command = rand() % 2; // 随机指令0或1
		if (command == 0) {
			// 最小编号购票
			cout << "编号 " << queue.front() << " 的购票者购票成功。\n";
			queue.pop_front();
		}
		else {
			// 最大编号购票
			cout << "编号 " << queue.back() << " 的购票者购票成功。\n";
			queue.pop_back();
		}
	}

	cout << "所有购票者已完成购票！\n";
}