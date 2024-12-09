#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

// ���ࣺFan
class Fan {
protected:
    int number; // ��Ʊ���
public:
    Fan(int num) : number(num) {}
    virtual ~Fan() {}

    int getNumber() const { return number; }
    virtual string getType() const = 0; // ���麯�������ڻ�ȡ��Ʊ������
};

// ��ͨ��Ʊ����
class TicketFan : public Fan {
public:
    TicketFan(int num) : Fan(num) {}
    string getType() const override { return "��ͨ��Ʊ��"; }
};

// VIP��Ʊ����
class VIPFan : public Fan {
public:
    VIPFan(int num) : Fan(num) {}
    string getType() const override { return "VIP��Ʊ��"; }
};

// ���������
bool comp(const Fan* a, const Fan* b) {
    return a->getNumber() < b->getNumber();
}

// ��ӹ�Ʊ��
void addFan(deque<Fan*>& ticketQueue, deque<Fan*>& vipQueue) {
    int randomNumber = rand() % 10000 + 1;
    int randomType = (rand() % 5 == 0) ? 1 : 0; // ���֮һ����Ϊ VIP

    if (randomType == 0) {
        ticketQueue.push_back(new TicketFan(randomNumber));
        cout << "���빺Ʊ�߱��: " << randomNumber << ", ����: ��ͨ��Ʊ��\n";
    }
    else {
        vipQueue.push_back(new VIPFan(randomNumber));
        cout << "���빺Ʊ�߱��: " << randomNumber << ", ����: VIP��Ʊ��\n";
    }
}

// ��Ʊ����
void buyTicket(int command, deque<Fan*>& queue) {
    if (queue.empty()) return;

    if (command == 0) {
        cout << queue.front()->getType() << "��� " << queue.front()->getNumber() << " ��Ʊ�ɹ���\n";
        delete queue.front(); // ɾ�������ͷ��ڴ�
        queue.pop_front();
    }
    else {
        cout << queue.back()->getType() << "��� " << queue.back()->getNumber() << " ��Ʊ�ɹ���\n";
        delete queue.back(); // ɾ�������ͷ��ڴ�
        queue.pop_back();
    }
}

// VIP���ڹ�Ʊ
void buyVIP(int command, deque<Fan*>& ticketQueue, deque<Fan*>& vipQueue) {
    if (vipQueue.empty()) {
        buyTicket(command, ticketQueue);
    }
    else {
        buyTicket(command, vipQueue);
    }
}

// ����ѡ��
void function(int choice, deque<Fan*>& ticketQueue, deque<Fan*>& vipQueue) {
    switch (choice) {
    case 1: {
        int m;
        cout << "�����������Ĺ�Ʊ��������\n";
        cin >> m;
        for (int i = 0; i < m; ++i) {
            addFan(ticketQueue, vipQueue);
        }
        sort(ticketQueue.begin(), ticketQueue.end(), comp);
        sort(vipQueue.begin(), vipQueue.end(), comp);
        break;
    }
    case 2: {
        int command = rand() % 2; // ���ָ�� 0 �� 1
        cout << "���ָ��Ϊ: " << command << endl;
        buyTicket(command, ticketQueue);
        buyVIP(command, ticketQueue, vipQueue);
        break;
    }
    }
}

// ������
int main() {
    int n = -1;
    deque<Fan*> ticketQueue;
    deque<Fan*> vipQueue;

    cout << "�����빺Ʊ��������";
    while (n <= 0) {
        cin >> n;
        if (n > 0) break;
    }

    cout << "���������Ʊ����Լ�Ʊ������...\n";
    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < n; ++i) {
        addFan(ticketQueue, vipQueue);
    }
    cout << endl;

    sort(ticketQueue.begin(), ticketQueue.end(), comp);
    sort(vipQueue.begin(), vipQueue.end(), comp);

    cout << "��ʼ��Ʊ...\n";

    while (!ticketQueue.empty() || !vipQueue.empty()) {
        cout << "1�����빺Ʊ�� 2��������Ʊ\n";
        int choice;
        cin >> choice;

        function(choice, ticketQueue, vipQueue);

        if (ticketQueue.empty() && vipQueue.empty()) {
            cout << "1�����빺Ʊ�� 2���˳�\n";
            cin >> choice;
            if (choice == 2) break;
            function(1, ticketQueue, vipQueue);
        }
    }

    cout << "���й�Ʊ������ɹ�Ʊ��\n";

    // ����ʣ������еĶ���
    for (Fan* fan : ticketQueue) delete fan;
    for (Fan* fan : vipQueue) delete fan;

    return 0;
}
