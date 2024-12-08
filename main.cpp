#include<iostream>
#include<vector>
#include<deque>
#include <algorithm>

using namespace std;

int main()
{
	int n=-1;
	vector<int>ticketnumber;
	int max = 0, min = 10000000;
	while (n <= 0)
	{
		cout << "�����빺Ʊ��������";//��ֹ��������
		cin >> n;
		if (n > 0)break;
	}
	
	cout << "���������Ʊ���...\n";
	srand(static_cast<unsigned>(time(0))); // �������

	for (int i = 0; i < n; ++i) {
		cout << "��Ʊ�������ţ�";
		int current = rand() % 10000 + 1;
		ticketnumber.push_back(current); // ������1��10000
		cout << current << endl;
	}
	cout << endl;

	sort(ticketnumber.begin(), ticketnumber.end());//С��������
	deque<int> queue(ticketnumber.begin(), ticketnumber.end());
	// ģ����Ʊ����
	cout << "��ʼ��Ʊ...\n";
	srand(static_cast<unsigned>(time(0))); // �������

	while (!queue.empty()) {
		//�Ƿ��������Ĺ�Ʊ��
		cout << "1�����빺Ʊ�� 2��������Ʊ" << endl;//�˴�������botton
		int choice, current = 0;
		cin >> choice;
		switch (choice)
		{
		case 1://���빺Ʊ��
			int m;
			cout << "�����������Ĺ�Ʊ��������\n";
			cin >> m;
			for (int i = 0; i < m; i++)
			{
				cout << "�µĹ�Ʊ�������ţ�";
				current = rand() % 10000 + 1;
				queue.push_back(current);
				cout << current << endl;
			}
			sort(queue.begin(), queue.end());
			//Ȼ�������Ʊ
		case 2://������Ʊ
			int command = rand() % 2; // ���ָ��0��1
			cout << "���ָ��Ϊ" << command << endl;
			if (command == 0) {
				// ��С��Ź�Ʊ
				cout << "��� " << queue.front() << " �Ĺ�Ʊ�߹�Ʊ�ɹ���\n";
				queue.pop_front();
			}
			else {
				// ����Ź�Ʊ
				cout << "��� " << queue.back() << " �Ĺ�Ʊ�߹�Ʊ�ɹ���\n";
				queue.pop_back();
			}
			break;
		}
	}

	cout << "���й�Ʊ������ɹ�Ʊ��\n";
}