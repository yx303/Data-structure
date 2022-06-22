#include<iostream>
#include "Parking.h"
using namespace std;

void InitStack(Stack& P) {
	//��ʼ��ջ������һ����ջ
	P.top = -1;
}

void Push(Stack& P,Car& e) {
	//��ջ����Ԫ��e����Pջ��ջ��
		P.C[++P.top] = e;
}

void Pop(Stack& P, Car& e) {
	//��ջ����ջ��Ԫ����e����
		e = P.C[P.top--];
}

void InitQueue(Queue& Q) {
	//��ʼ�����У�����һ���ն���
	Q.front = Q.rear = 0;
}

void EnterQueue(Queue& Q, Car& e) {
	//��Ԫ��e���
		Q.S[Q.rear] = e;
		Q.rear = (Q.rear + 1) % maxqueuesize;
}

void DeleteQueue(Queue& Q, Car& e) {
	//���ӣ���e����
		e = Q.S[Q.front];
		Q.front = (Q.front + 1) % maxqueuesize;
}

void Arrive(Stack& Enter, Queue& W,Car& p) {
	//��������ͣ����
	if (Enter.top == maxstacksize - 1) {
		cout << "ͣ��������,������ʱ���!" << endl;
		if ((W.rear + 1) % maxqueuesize == W.front) {
			cout << "��ʱ�������������ȥ������ͣ������" << endl;
		}
		else {
			cout << "�����복�ƺ�<��:��A-88888>:";
			cin >> p.num;
			EnterQueue(W, p);
		}
	}
	else {
	cout << "�����복�ƺ�<��:��A-88888>:";
	cin >> p.num;
	cout << "�����복�ƺ�Ϊ" << p.num << "�ĳ�����ͣ������ʱ�䣬hour:";
	cin >> p.reach.hour;
	cout << "min:";
	cin>>p.reach.min;
	p.pos = Enter.top + 2;
	Push(Enter, p);
	cout << "���ƺ�Ϊ��" << p.num << "���ĳ���ͣ�����е�λ��Ϊ:" << p.pos << endl;
	}
}

void Leave(Stack& Enter, Queue& W, Car& p) {
	//������ͣ��������p����,����ʱ�����Ϊ�գ�����ʱ�����һ��������ͣ����
	string num;
	int flag = 0, pos = 0, time;
	double pay=0;
	Stack S;
	InitStack(S);
	Car e;
	if (Enter.top == -1) cout << "ͣ����Ϊ�գ�" << endl;
	else {
		cout << "�������뿪�����ĳ��ƺ�<��:��A-88888>��";
		cin >> num;
		for (int i = 0; i <= Enter.top; i++) {
			if (Enter.C[i].num == num) {
				flag++;
				pos = Enter.C[i].pos;
			}
		}
		if (!flag) cout << "���ƺ�Ϊ��" << num << "���ĳ�����ͣ������!" << endl;
		else {
			for (int i = Enter.top; i >= pos; i--) {
				Pop(Enter, e);
				Push(S, e);
			}
			Pop(Enter, p);
			cout << "�����복�ƺ�Ϊ��" << p.num << "���ĳ��뿪ͣ������ʱ�䣬hour:";
			cin >> p.leave.hour;
			cout << "min:";
			cin >> p.leave.min;
			cout << "���ƺ�Ϊ��" << p.num << "���ĳ�����ͣ������ʱ��Ϊ��" << p.reach.hour << ':' << p.reach.min << endl;
			cout << "���ƺ�Ϊ��" << p.num << "���ĳ�ʻ��ͣ������ʱ��Ϊ��" << p.leave.hour << ':' << p.leave.min << endl;
			time = (p.leave.hour - p.reach.hour) * 60 + (p.leave.min - p.reach.min);
			pay = time * fee;
			cout << "���ƺ�Ϊ��" << p.num << "���ĳ��踶ͣ����" << pay << "Ԫ" << endl;
			cout << endl;
			while (S.top >= 0) {
				Pop(S, e);
				e.pos--;
				Push(Enter, e);
			}
			if (W.front != W.rear) {
				DeleteQueue(W, e);
				cout << "�����복�ƺ�Ϊ��" << e.num << "���ĳ�����ͣ������ʱ�䣬hour:";
				cin >> e.reach.hour;
				cout << "min:";
				cin >> e.reach.min;
				e.pos = Enter.top + 2;
				Push(Enter, e);
				cout << "���ƺ�Ϊ��" << e.num << "���ĳ���ͣ�����е�λ��Ϊ:" << e.pos << endl;
			}
		}
	}
}

void ShowStack(Stack& S) {
	//���ͣ������Ϣ
	if (S.top == -1) cout << "ͣ����Ϊ��!" << endl;
	else {
		//Car e;
		cout << "ͣ�����еĳ�����ϢΪ��" << endl;
		for (int i = 0; i <= S.top; i++) {
			//e = S.C[i];
			cout << "����λ��Ϊ:" << S.C[i].pos << " ";
			cout << "���ƺ�Ϊ��" << S.C[i].num << " ";
			cout << "���������ʱ��Ϊ��" << S.C[i].reach.hour << ':' << S.C[i].reach.min << endl;
		}
	}
	cout << endl;
}

void ShowQueue(Queue& Q) {
	//�����ʱ�����Ϣ
	int i=0;
	if (Q.front == Q.rear) cout << "��ʱ���Ϊ��!" << endl;
	else {
		cout << "��ʱ����еĳ�����ϢΪ:" << endl;
		int t = Q.front % maxqueuesize;
		Car e;
		while (t != Q.rear) {
			e = Q.S[t];
			i++;
			cout << "����λ��:" << i << " ";
			cout << "���ƺ�Ϊ��" << e.num << endl;
			t = (t + 1) % maxqueuesize;
		}
	}
	cout << endl;
}

void InitCar(Car& p) {
	//��ʼ��������Ϣ
	p = { "",{0,0},{0,0},0 };
}