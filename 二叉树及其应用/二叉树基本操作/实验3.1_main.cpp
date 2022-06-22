#include<iostream>
#include<conio.h>
#include "windows.h"
#include "Tree.h"
using namespace std;

int main() {
	BiList root = new BiTree;
	int choice, len, LR;
	DataType p, c;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
	//��ʾ���˵�
	cout << "1-��ʼ��������" << endl;
	cout << "2-������չ����������д�����������" << endl;
	cout << "3-������������" << endl;
	cout << "4-������" << endl;
	cout << "5-���������������" << endl;
	cout << "6-���Ҷ���" << endl;
	cout << "7-�����Ϊ1�Ľ��" << endl;
	cout << "8-�����Ϊ2�Ľ��" << endl;
	cout << "9-�������н������Һ��ӽ��" << endl;
	cout << "10-����״��ӡ������" << endl;
	cout << "11-���ٶ�����" << endl;
	cout << "101-�˳�" << endl;
	cout << "Enter choice:";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cin >> choice;
	while (choice != 101) {
		switch (choice) {
		case 1://��ʼ��������
			InitBiTree(root);
			cout << "��ʼ����ɣ�" << endl;
			system("pause");
			break;
		case 2://������չ����������д�����������
			cout << "�������������չ�����������(��'.'��ʾ������)<��:AB..CD...>:" << endl;
			CreateBiTree(root);
			system("pause");
			break;
		case 3://����������
			len = BiTreeLength(root);
			cout << "�ö����������Ϊ��" << len << endl;
			system("pause");
			break;
		case 4://������
			cout << "������Ŀ����Ԫ��:";
			cin >> p;
			cout << "�����������Ԫ��:";
			cin >> c;
			cout << "��������Ҫ���ý���������Һ��ӽ��(ż��Ϊ���ӡ�����Ϊ�Һ���):";
			cin >> LR;
			InsertChild(root, p, LR, c);
			system("pause");
			break;
		case 5://���������������
			cout << "���������Ķ�����Ϊ:";
			DisplayBiTree(root);
			cout << endl;
			system("pause");
			break;
		case 6://���Ҷ���
			cout << "Ҷ���Ϊ:";
			DisplayLeaf(root);
			cout << endl;
			system("pause");
			break;
		case 7://�����Ϊ1�Ľ��
			cout << "��Ϊ1�Ľ�㣺";
			DisplayDegree1(root);
			cout << endl;
			system("pause");
			break;
		case 8://�����Ϊ2�Ľ��
			cout << "��Ϊ2�Ľ��Ϊ:";
			DisplayDegree2(root);
			cout << endl;
			system("pause");
			break;
		case 9://�������н������Һ��ӽ��
			SwopChild(root);
			cout << "������ɣ�" << endl;
			system("pause");
			break;
		case 10://����״��ӡ������
			PrintTree(root, 0);
			cout << "��ӡ��ɣ�" << endl;
			system("pause");
			break;
		case 11://���ٶ�����
			DestroyBiTree(root);
			cout << "�����٣�" << endl;
			system("pause");
			break;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		cout << "Enter choice:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> choice;
	}
	return 0;
}