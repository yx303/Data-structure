#include<iostream>
#include "Parking.h"
using namespace std;

int main() {
	Stack Enter;//ͣ����ջ
	Queue W;//��ʱ����
	Car p;
	InitStack(Enter);//��ʼ��ͣ����
	InitQueue(W);//��ʼ����ʱ����
	InitCar(p);//��ʼ��������Ϣ
	int choice;
	cout << "**********��ӭʹ��ͣ����ϵͳ**********" << endl;
	do {
		cout << "***1.��������Ǽ�     ***" << endl;
		cout << "***2.�����뿪�Ǽ�     ***" << endl;
		cout << "***3.ͣ������Ϣ��ʾ   ***" << endl;
		cout << "***4.��ʱ�����Ϣ��ʾ ***" << endl;
		cout << "***101.�˳�ϵͳ       ***" << endl;
		cout << "Enter choice:";
		cin >> choice;
		switch (choice) {
		case 1://��������
			Arrive(Enter, W, p);
			cout << endl;
			break;
		case 2://�����뿪
			Leave(Enter, W, p);
			cout << endl;
			break;
		case 3://��ʾͣ������Ϣ
			ShowStack(Enter);
			cout << endl;
			break;
		case 4://��ʾ��ʱ�����Ϣ
			ShowQueue(W);
			cout << endl;
			break;
		}
	} while (choice != 101);
	return 0;
}