#include<iostream>
#include<vector>
#include<deque>
#include <algorithm>

using namespace std;
typedef struct Fan {
	int number;//��Ʊ���
	int level;//Ʊ�ĵȼ� 0����ͨ  1��VIP
}Fan;
bool comp(const Fan& a, const Fan& b)
{
	return a.number < b.number;
}
void addfan(deque<Fan>&ticket,deque<Fan>&vip)
{
	Fan newfan;
	cout << "��Ʊ�������ţ�";
	newfan.number = rand() % 10000 + 1;
	cout << newfan.number << endl;

	cout << "��Ʊ���ͣ�";
	newfan.level = (0 < (rand() % 5)) ? 0 : 1;//���֮һ����Ϊvip
	cout << newfan.level << endl;

	if (newfan.level == 0)//��ͨƱ
	{
		ticket.push_back(newfan);
	}
	else
	{
		vip.push_back(newfan);
	}
}
void buyticket(int command, deque<Fan>& ticket)
{
	if (ticket.empty())
	{
		return;
	}
	if (command == 0) {
		// ��С��Ź�Ʊ
		cout << "��� " << ticket.front().number << " �Ĺ�Ʊ�߹�Ʊ�ɹ���\n";
		ticket.pop_front();
	}
	else {
		// ����Ź�Ʊ
		cout << "��� " << ticket.back().number << " �Ĺ�Ʊ�߹�Ʊ�ɹ���\n";
		ticket.pop_back();
	}
}
void buyvip(int command, deque<Fan>& ticket, deque<Fan>& vip)
{
	if (vip.empty())//��vip����Ϊ��ʱ��vip���ڿ�����ͨƱ
	{
		buyticket(command, ticket);
	}
	else
	{
		buyticket(command, vip);
	}
}
void function(int choice, deque<Fan>& ticket, deque<Fan>& vip)
{
	switch (choice)
	{
	case 1://���빺Ʊ��
		int m;
		cout << "�����������Ĺ�Ʊ��������\n";
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			addfan(ticket, vip);
		}
		sort(ticket.begin(), ticket.end(), comp);//С��������
		sort(vip.begin(), vip.end(), comp);

		//Ȼ�������Ʊ
	case 2://������Ʊ
		int command = rand() % 2; // ���ָ��0��1
		cout << "���ָ��Ϊ" << command << endl;
		buyticket(command, ticket);
		buyvip(command, ticket, vip);
		break;
	}
}
int main()
{
	int n = -1;
	deque<Fan> ticketqueue;
	deque<Fan> vipqueue;

	while (n <= 0)
	{
		cout << "�����빺Ʊ��������";//��ֹ��������
		cin >> n;
		if (n > 0)break;
	}

	cout << "���������Ʊ����Լ�Ʊ������...\n";
	srand(static_cast<unsigned>(time(0))); // �������

	for (int i = 0; i < n; ++i) {
		
		addfan(ticketqueue, vipqueue);
	}
	cout << endl;

	sort(ticketqueue.begin(), ticketqueue.end(),comp);//С��������
	sort(vipqueue.begin(), vipqueue.end(), comp);

	
	// ģ����Ʊ����
	cout << "��ʼ��Ʊ...\n";
	srand(static_cast<unsigned>(time(0))); // �������

	while (!ticketqueue.empty()||!vipqueue.empty()) {
		//�Ƿ��������Ĺ�Ʊ��
		cout << "1�����빺Ʊ�� 2��������Ʊ" << endl;//�˴�������botton
		int choice, current = 0;
		cin >> choice;
		function(choice, ticketqueue, vipqueue);
		if (ticketqueue.empty() && vipqueue.empty())
		{
			cout << "1�����빺Ʊ�� 2���˳�" << endl;//�˴�������botton
			cin >> choice;
			if (choice == 2)break;
			function(1, ticketqueue, vipqueue);
		}
	}

	cout << "���й�Ʊ������ɹ�Ʊ��\n";
}