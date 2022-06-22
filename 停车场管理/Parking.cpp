#include<iostream>
#include "Parking.h"
using namespace std;

void InitStack(Stack& P) {
	//初始化栈，构造一个空栈
	P.top = -1;
}

void Push(Stack& P,Car& e) {
	//入栈，将元素e置入P栈的栈顶
		P.C[++P.top] = e;
}

void Pop(Stack& P, Car& e) {
	//出栈，将栈顶元素用e返回
		e = P.C[P.top--];
}

void InitQueue(Queue& Q) {
	//初始化队列，构造一个空队列
	Q.front = Q.rear = 0;
}

void EnterQueue(Queue& Q, Car& e) {
	//将元素e入队
		Q.S[Q.rear] = e;
		Q.rear = (Q.rear + 1) % maxqueuesize;
}

void DeleteQueue(Queue& Q, Car& e) {
	//出队，用e返回
		e = Q.S[Q.front];
		Q.front = (Q.front + 1) % maxqueuesize;
}

void Arrive(Stack& Enter, Queue& W,Car& p) {
	//车辆进入停车场
	if (Enter.top == maxstacksize - 1) {
		cout << "停车场已满,进入临时便道!" << endl;
		if ((W.rear + 1) % maxqueuesize == W.front) {
			cout << "临时便道已满，请您去其他的停车场！" << endl;
		}
		else {
			cout << "请输入车牌号<例:京A-88888>:";
			cin >> p.num;
			EnterQueue(W, p);
		}
	}
	else {
	cout << "请输入车牌号<例:京A-88888>:";
	cin >> p.num;
	cout << "请输入车牌号为" << p.num << "的车进入停车场的时间，hour:";
	cin >> p.reach.hour;
	cout << "min:";
	cin>>p.reach.min;
	p.pos = Enter.top + 2;
	Push(Enter, p);
	cout << "车牌号为“" << p.num << "”的车在停车场中的位置为:" << p.pos << endl;
	}
}

void Leave(Stack& Enter, Queue& W, Car& p) {
	//车辆出停车场，用p返回,若临时便道不为空，则临时便道第一辆车进入停车场
	string num;
	int flag = 0, pos = 0, time;
	double pay=0;
	Stack S;
	InitStack(S);
	Car e;
	if (Enter.top == -1) cout << "停车场为空！" << endl;
	else {
		cout << "请输入离开车辆的车牌号<例:京A-88888>：";
		cin >> num;
		for (int i = 0; i <= Enter.top; i++) {
			if (Enter.C[i].num == num) {
				flag++;
				pos = Enter.C[i].pos;
			}
		}
		if (!flag) cout << "车牌号为“" << num << "”的车不在停车场中!" << endl;
		else {
			for (int i = Enter.top; i >= pos; i--) {
				Pop(Enter, e);
				Push(S, e);
			}
			Pop(Enter, p);
			cout << "请输入车牌号为“" << p.num << "”的车离开停车场的时间，hour:";
			cin >> p.leave.hour;
			cout << "min:";
			cin >> p.leave.min;
			cout << "车牌号为“" << p.num << "”的车进入停车场的时间为，" << p.reach.hour << ':' << p.reach.min << endl;
			cout << "车牌号为“" << p.num << "”的车驶出停车场的时间为，" << p.leave.hour << ':' << p.leave.min << endl;
			time = (p.leave.hour - p.reach.hour) * 60 + (p.leave.min - p.reach.min);
			pay = time * fee;
			cout << "车牌号为“" << p.num << "”的车需付停车费" << pay << "元" << endl;
			cout << endl;
			while (S.top >= 0) {
				Pop(S, e);
				e.pos--;
				Push(Enter, e);
			}
			if (W.front != W.rear) {
				DeleteQueue(W, e);
				cout << "请输入车牌号为“" << e.num << "”的车进入停车场的时间，hour:";
				cin >> e.reach.hour;
				cout << "min:";
				cin >> e.reach.min;
				e.pos = Enter.top + 2;
				Push(Enter, e);
				cout << "车牌号为“" << e.num << "”的车在停车场中的位置为:" << e.pos << endl;
			}
		}
	}
}

void ShowStack(Stack& S) {
	//输出停车场信息
	if (S.top == -1) cout << "停车场为空!" << endl;
	else {
		//Car e;
		cout << "停车场中的车辆信息为：" << endl;
		for (int i = 0; i <= S.top; i++) {
			//e = S.C[i];
			cout << "车辆位置为:" << S.C[i].pos << " ";
			cout << "车牌号为：" << S.C[i].num << " ";
			cout << "车辆进入的时间为：" << S.C[i].reach.hour << ':' << S.C[i].reach.min << endl;
		}
	}
	cout << endl;
}

void ShowQueue(Queue& Q) {
	//输出临时便道信息
	int i=0;
	if (Q.front == Q.rear) cout << "临时便道为空!" << endl;
	else {
		cout << "临时便道中的车辆信息为:" << endl;
		int t = Q.front % maxqueuesize;
		Car e;
		while (t != Q.rear) {
			e = Q.S[t];
			i++;
			cout << "车辆位置:" << i << " ";
			cout << "车牌号为：" << e.num << endl;
			t = (t + 1) % maxqueuesize;
		}
	}
	cout << endl;
}

void InitCar(Car& p) {
	//初始化车辆信息
	p = { "",{0,0},{0,0},0 };
}