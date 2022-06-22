#include<iostream>
#include "Parking.h"
using namespace std;

int main() {
	Stack Enter;//停车场栈
	Queue W;//临时队列
	Car p;
	InitStack(Enter);//初始化停车场
	InitQueue(W);//初始化临时队列
	InitCar(p);//初始化车辆信息
	int choice;
	cout << "**********欢迎使用停车场系统**********" << endl;
	do {
		cout << "***1.车辆到达登记     ***" << endl;
		cout << "***2.车辆离开登记     ***" << endl;
		cout << "***3.停车场信息显示   ***" << endl;
		cout << "***4.临时便道信息显示 ***" << endl;
		cout << "***101.退出系统       ***" << endl;
		cout << "Enter choice:";
		cin >> choice;
		switch (choice) {
		case 1://车辆到达
			Arrive(Enter, W, p);
			cout << endl;
			break;
		case 2://车辆离开
			Leave(Enter, W, p);
			cout << endl;
			break;
		case 3://显示停车场信息
			ShowStack(Enter);
			cout << endl;
			break;
		case 4://显示临时便道信息
			ShowQueue(W);
			cout << endl;
			break;
		}
	} while (choice != 101);
	return 0;
}